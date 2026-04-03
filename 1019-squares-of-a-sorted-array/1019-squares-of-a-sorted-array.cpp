class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) { 
       
       //判断是否为空
        if (nums.empty()) return {};
      
        // 从大位置开始排序，到最后就是从小到大
        int k=nums.size()-1;
        // 注意：第一次参数是大小，第二个是初始值，（n,0）表示最大值的下标为n-1
        vector<int> result(nums.size(),0);
        for(int i=0,j=k;i<=j;)
         {
            if(nums[i]*nums[i]>nums[j]*nums[j])
            {
                result[k]=nums[i]*nums[i];
                i++;
            }
            else
            {
                result[k]=nums[j]*nums[j];  
                j--;
            }
            k--;
         }
         return result;
        
         }
};