class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*双遍历*/
        // std::unordered_set<int> result;
        // std::unordered_map<int,int> unmap;
        // int i=0;
        // for(const int& num:nums)
        // {
        //     unmap.insert({num,i});
        //     i++;
        // }
        // for(int j=0;j<nums.size();j++)
        // {
        //     auto itetor=unmap.find(target-nums[j]);
        //     if(itetor!=unmap.end()&& itetor->second!=j)
        //     {
        //         result.insert(j);
        //         result.insert(itetor->second);
        //     }
        // }
        // return vector<int>(result.begin(),result.end());
        /*单遍历*/
        unordered_map<int,int> unmap;
        for(int i=0;i<nums.size();i++)
        {
            auto iter=unmap.find(target-nums[i]);
            if(iter!=unmap.end())
            {
                return {iter->second,i};
            }
            unmap.insert({nums[i],i});
        }
        return {};
    }
};