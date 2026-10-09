class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(int j=0;j<magazine.size();j++)
        {
            for(int i=0;i<ransomNote.size();i++)
            {
                if(ransomNote[i]==magazine[j])
                {
                    ransomNote.erase(ransomNote.begin()+i);
                    break;
                }
            }
        }
        if(ransomNote.length()==0)
        {
            return true;
        }
        
        return false;
        
    }
};