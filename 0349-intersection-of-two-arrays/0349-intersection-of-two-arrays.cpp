class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 无序的不可重复集合
        std::unordered_set<int> unset;
        std::vector<int> result;
        for(int i=0;i<nums1.size();i++)
        {
            unset.insert(nums1[i]);
        }
        for(int j=0;j<nums2.size();j++)
        {
            if(unset.count(nums2[j]))
            {
                result.push_back(nums2[j]);
                unset.erase(nums2[j]);
            }
        }
        return result;
    }
};