class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // std::multiset<int> set; //可重复
        // int count=0;
        // for(const int&x:nums1)
        // {
        //     for(const int&y:nums2)
        //     {
        //         set.insert(x+y);
        //     }
        // }
        // for(const int&x:nums3)
        // {
        //     for(const int&y:nums4)
        //     {
        //         if(set.find(-(x+y))!=set.end())
        //         {
        //             count+=set.count(-(x+y));
        //         }
        //     }
        // }
        // return count;

        std::unordered_map <int,int> unmap; //不可重复
        int count=0;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                // auto iter = unmap.find(nums1[i] + nums2[j]);
                // if (iter != unmap.end()) {
                //     iter->second++;
                // } else {
                //     unmap.insert({nums1[i] + nums2[j], 1});
                // }
                unmap[nums1[i] + nums2[j]]++;
            }
        }
        for(const int&x:nums3)
        {
            for(const int&y:nums4)
            {
                auto iter=unmap.find(-(x+y));
                if(iter!=unmap.end())
                {
                    count+=iter->second;
                }
            }
        }
        return count;
    }
};