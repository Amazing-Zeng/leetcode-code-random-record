class Solution {
public:

    void removeExtraSpaces(string& s){
        int fastIndex=0,slowIndex=0;
        for(;fastIndex<s.size();fastIndex++){
            if(s[fastIndex] != ' '){
                if(slowIndex!=0){
                    s[slowIndex++]=' ';
                }
                while(fastIndex<s.size()&&s[fastIndex]!=' '){
                    s[slowIndex]=s[fastIndex];
                    slowIndex++;
                    fastIndex++;
                }
            }
        }
        s.resize(slowIndex);
    }
    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for(int i=start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s,0,s.size()-1);
        int start=0;
        for(int i=0;i<=s.size();i++){
            if(i==s.size()||s[i]==' '){
                reverse(s,start,i-1);
                start=i+1;
            }
        }
        return s;
    }
};