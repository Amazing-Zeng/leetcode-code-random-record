class Solution {
public:
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
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int n=needle.size();
        int *next=nullptr;
        next=getNext(needle);
        int j=0;
        for(int i=0;i<haystack.size();i++)
        {
            
            while(j>0&&haystack[i]!=needle[j])
            {
                j=next[j-1];
            }
            if(haystack[i]==needle[j])
            {
                j++;
            }
            if(j==needle.size())
            {
                delete[] next;
                return (i-needle.size()+1);
            }
            
        }
        delete[] next;
        return -1;
    }
};