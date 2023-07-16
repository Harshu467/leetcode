class Solution(object):
    def smallestSufficientTeam(self, req_skills, people):
        """
        :type req_skills: List[str]
        :type people: List[List[str]]
        :rtype: List[int]
        """
        mainTeam = []
        map = {}
        i = 0
        for skill in req_skills:
            map[skill] = i
            i += 1

        reqSkills = (1 << i) - 1
        skills = self.getPeopleSkillsMask(people, map)
        localTeam = []
        self.findTeam(reqSkills, skills, 0, 0, localTeam, mainTeam)
        return mainTeam

    def getPeopleSkillsMask(self, people, map):
        skills = []
        for person in people:
            skillMask = 0
            for skill in person:
                skillMask |= 1 << map[skill]
            skills.append(skillMask)
        return skills

    def findTeam(self, reqSkills, skills, teamSkills, person, localTeam, mainTeam):
        if len(mainTeam) > 0 and len(localTeam) >= len(mainTeam) - 1 or person == len(skills):
            return

        localTeam.append(person)

        if (teamSkills | skills[person]) == reqSkills:
            if len(mainTeam) == 0 or len(localTeam) < len(mainTeam):
                mainTeam[:] = localTeam[:]
            localTeam.pop()
            return
        elif (teamSkills | skills[person]) > teamSkills:
            self.findTeam(reqSkills, skills, teamSkills | skills[person], person + 1, localTeam, mainTeam)

        localTeam.pop()
        self.findTeam(reqSkills, skills, teamSkills, person + 1, localTeam, mainTeam)