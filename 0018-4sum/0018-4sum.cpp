class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i] > target && nums[i] > 0) {
                    return result; 
            }
            // 对nums[i]去重
            if (i> 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j=i+1;j<nums.size();j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left=j+1;
                int right=nums.size()-1;
                while(left<right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum>target) right--;
                    else if(sum<target) left++;
                    else{
                        result.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        // 去重逻辑应该放在找到一个四元组之后
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;
                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};