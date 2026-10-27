class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.size();
        int left=0;
        int right=0;
        int result=0;
        std::unordered_map<char,int> unamp;
        for (; right < size; right++) 
        {
            if(unamp.find(s[right])!=unamp.end())
            {
                left=max(left,unamp[s[right]]+1);
            }
            unamp[s[right]]=right;
            result=max(result,right-left+1);
        }
        return result;
        
    }
};