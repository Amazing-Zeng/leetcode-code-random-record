class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        char* son = new char[n / 2 ];  // 方括号！分配数组

        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0) continue;     // 长度必须能整除

            memcpy(son, s.data(), i);     // data() 带括号

            bool match = true;
            for (int k = 0; k < n; k++) {
                if (son[k % i] != s[k]) { // 直接取模，无需 j 复位
                    match = false;
                    break;
                }
            }
            if (match) {
                delete[] son;             // 配 delete[]
                return true;
            }
        }

        delete[] son;
        return false;
    }
};