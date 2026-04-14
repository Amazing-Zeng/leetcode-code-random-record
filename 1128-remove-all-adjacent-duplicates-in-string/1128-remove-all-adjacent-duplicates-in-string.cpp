class Solution {
public:
    string removeDuplicates(string s) {
        /*方法一：使用栈*/
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty()||st.top()!=s[i])
             st.push(s[i]); // 不同则加入到栈
            else 
            st.pop();//相同则去掉
        }
        string result = "";
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;
    }
};