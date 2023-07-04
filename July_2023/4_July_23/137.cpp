class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        map<int,int>mp;
        for(int i=0;i<size;i++)
        {
            mp[nums[i]]++;
        }
        int ans;
        for(auto element:mp)
        {
            if(element.second==1)
            {
                ans=element.first;
            }
        }
        return ans;

    }
};