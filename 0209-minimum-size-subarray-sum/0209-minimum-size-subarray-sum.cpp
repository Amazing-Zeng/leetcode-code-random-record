class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int result = INT32_MAX; // 最终的结果
        int sum = 0; // 子序列的数值之和
        int subLength = 0; // 子序列的长度
        for(j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                subLength= j - i + 1;// 取子序列的长度
               result = result < subLength ? result : subLength;
               sum -= nums[i];
               i++;
            
            }
            //问题：放在外面的话如果都不满足的话，sub=0永远都是
            //result = result < subLength ? result : subLength;
        }
        //O（n)
        return result == INT32_MAX ? 0 : result;
    }
};