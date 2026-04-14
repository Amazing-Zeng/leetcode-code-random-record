class Solution {
public:
    bool isValid(string s) {
        // 定义栈
        stack<char> st;
        char* cur=&s[0];
        // 快速判断
        if(s.size()%2!=0) return false;
        // 数据的大小
        int size=s.size();
        while(size--)
        {
            // 判断左边
            if(*cur=='(')  
                st.push(')');
            else if (*cur=='{') 
                st.push('}');
            else if (*cur=='[') 
                st.push(']');
            //判断右边
            else if(st.empty()||st.top()!=*cur)
            {
                return false;
            }
            else
            // st.top() 与 s[i]相等，栈弹出元素
               st.pop();
            cur++;
        }
        if(!st.empty()) 
        {
            return false;
        }
        
        return true;
    }
};