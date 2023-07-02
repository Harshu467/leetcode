

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return res;
        }
        
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] > b[0] + b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        unordered_set<string> visited;
        
        heap.push({nums1[0], nums2[0], 0, 0});
        visited.insert("0,0");
        
        while (k > 0 && !heap.empty()) {
            auto curr = heap.top();
            heap.pop();
            
            int i = curr[2];
            int j = curr[3];
            res.push_back({curr[0], curr[1]});
            k--;
            
            if (i + 1 < nums1.size() && visited.find(to_string(i + 1) + "," + to_string(j)) == visited.end()) {
                heap.push({nums1[i + 1], nums2[j], i + 1, j});
                visited.insert(to_string(i + 1) + "," + to_string(j));
            }
            
            if (j + 1 < nums2.size() && visited.find(to_string(i) + "," + to_string(j + 1)) == visited.end()) {
                heap.push({nums1[i], nums2[j + 1], i, j + 1});
                visited.insert(to_string(i) + "," + to_string(j + 1));
            }
        }
        
        return res;
    }
};