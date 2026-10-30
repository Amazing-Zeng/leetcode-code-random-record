class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        std::unordered_map<string,vector<string>> unmap;
        int size=strs.size();
        for(int i=0;i<size;i++)
        {
            string tmp=strs[i];
            sort(tmp.begin(), tmp.end());
            unmap[tmp].push_back(strs[i]);
        }
        for(auto &s:unmap)
        {
            res.push_back(s.second);
        }
        return res;
    }
};