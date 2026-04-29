class Solution {
public:
    // 取数值各个位上的单数之和
    int getSum(int n){
        int result=0;
        while(n!=0)
        {
            int temp=0;
            temp=(n%10)*(n%10);
            result+=temp;
            n=n/10;
        }
        return result;
    }
    bool isHappy(int n) {
        unordered_set<int> set; 
        while(1)
        {
            int happyNum=getSum(n);
            if(happyNum==1)
            {
                return true;
            }
            if(set.find(happyNum)!=set.end())
            {
                return false;
            }else{
                set.insert(happyNum);
            }
            // 更新值
            n=happyNum;
        }     
    }
};