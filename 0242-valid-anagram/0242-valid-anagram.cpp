class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size=s.size();
        int t_size=t.size();
        if(s_size!=t_size) return false;
        vector<int> nums(26,0);
        for(int i=0;i<s_size;i++)
        {
            int tmep=s[i]-'a';
            nums[tmep]++;
        }
        for(int j=0;j<t_size;j++)
        {
            int tmep=t[j]-'a';
            nums[tmep]--;
        }
        for(const int &x:nums)
        {
            if(x!=0)
            return false;
        }
        return true;
        
        
    }
};