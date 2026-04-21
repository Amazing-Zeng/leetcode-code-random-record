class Solution {
public:

    void removeExtraSpaces(string& s)
    {
        int fastIndex=0,slowIndex=0;
        for(;fastIndex<s.size();fastIndex++)
        {
            //遇到非空格才进行处理
            if(s[fastIndex]!=' ')
            {
                if(slowIndex!=0)
                    {
                        s[slowIndex]=' ';
                        slowIndex++;
                    }
                while(fastIndex<s.size()&& s[fastIndex]!=' ')
                    {
                        s[slowIndex]=s[fastIndex];
                        slowIndex++;
                        fastIndex++;
                    }
                
            }

        }
        s.resize(slowIndex);
    }
    string reverseWords(string s) {
        removeExtraSpaces(s); // 移除多余空格
        reverse(s.begin(),s.end()); //翻转
        // 翻转单词
        int start=0; // 更新单词的位置
        for(int i=0;i<=s.size();i++)
        {
            //遇到最后或空格时，翻转前面的单词
            if(i==s.size() || s[i]==' ')
            {
                reverse(s.begin()+start,s.begin()+i); //reverse 是左闭右开：[begin, end)
                start=i+1;
            }
            
        }
        return s;

        
    }
};