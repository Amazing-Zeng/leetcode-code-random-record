class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=nums.size()-1;
            while(right>left)
            {
                if(nums[i]+nums[left]+nums[right]>0) right--;
                else if (nums[i]+nums[left]+nums[right]<0) left++;
                else
                {
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(right>left&&nums[right]==nums[right-1]) right--;
                    while(right>left&&nums[left]==nums[left+1]) left++;

                    // 找到答案，同时减1
                    left++;
                    right--;


                }
            }
        }   
        return result;     
    }
};
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end()); // 从小到大排序
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) break;   // 正数相加不可能为0
            if(i>0&&nums[i]==nums[i-1]) continue; //去掉重复

            unordered_set<int> set; // // 哈希集合，存已经遍历过的数
            // 使用集合来遍历过的nums[k]
            for(int k=i+1;k<nums.size();k++)
            {
                if(k>i+2&&nums[k]==nums[k-1]&&nums[k-1]==nums[k-2]) continue;
                int target=0-(nums[i]+nums[k]);
                if(set.find(target)!=set.end())
                {
                    result.push_back({nums[i],target,nums[k]});
                    set.erase(target);
                }
                else
                {
                    set.insert(nums[k]);
                }
            }
        }
        return result;
        
    }
};
*/