class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> record(26,0);
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for(int i=0;i<t.size();i++){
            record[t[i]-'a']--;
        }
        for(int i=0;i<record.size();i++)
        {
            if(record[i]!=0)
            return false;
        }
        return true;
    }
};