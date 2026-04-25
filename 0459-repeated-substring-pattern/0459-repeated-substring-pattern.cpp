class Solution {
public:
    // 获取next表
    int* getNext(const string& needle)
    {  
        int n=needle.size();
        int* next=new int[n];  //堆上分配
        int i;      // 后缀
        int j = 0;  //前缀
        next[0] = 0;
        for(i=1;i<needle.size();i++)
        {
            while(j>0&&needle[i]!=needle[j])
            {
                j=next[j-1];
            }
            if(needle[i]==needle[j])
            {
                j++;
            }
            next[i]=j; //更新next表    
        }
        return next;

    } 
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        if(n==0)
            return false;
        int* next=new int[n];  //堆上分配
        next=getNext(s);
        int len = s.size();
        if(next[len - 1] != 0&&len%( len-next[len-1])==0)
            return true;
        return false;
    }
};
/*
// 2. 移动匹配
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t=s+s;
        t.erase(t.begin());//移除第一个字母
        t.erase(t.end()-1);//移除最后一个字母
        //std::string::npos C++ 字符串里的 “没找到 / 不存在 / 结束位置”
        if (t.find(s) != std::string::npos) 
            return true; // r
        return false;
    }
};
*/
/*
// 1.暴力解法：
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.size();
        for(int i=1;i<=len/2;i++)
        {
            // 总长度不能被子串长度整除，直接跳过
            if (len % i != 0) {
                continue;
            }
            bool match = true; //标志位
            for(int j=0;j<len;j++)
            {
                // s[i]表示的是原字符串，s[j%i]表示的是子串
                if(s[j]!=s[j%i]) 
                {
                    match=false;
                    break;
                }
            }
            if(match) return true;
        }
        return false;
    }
    
};
*/