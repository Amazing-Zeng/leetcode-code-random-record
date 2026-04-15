class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 1 初始化栈
        stack<long long> st;
        // 2.长度作为循环 
        int tokenSize=tokens.size();
        // 3. 计算
        for(int i=0;i<tokenSize;i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long num1=st.top();
                st.pop();
                long long num2=st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            }
            else
                st.push(stoll(tokens[i])); // stoll字符串为十进制用法
        }
        return st.top();
    }
};