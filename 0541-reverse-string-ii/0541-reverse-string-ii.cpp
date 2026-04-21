class Solution {
public:
    string reverseStr(string s, int k) {
        int size=s.size(); // s的长度
        for(int i=0;i<size;i=i+2*k)
        {
            if(i+k<size)
            {
                reverse(s.begin() + i, s.begin() + i + k );
            }
            else
            {
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
        
    }
};