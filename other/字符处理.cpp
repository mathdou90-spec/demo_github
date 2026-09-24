#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        // 跳过前导空格（增加越界保护，避免空字符串）
        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;

        // 第一个非空字符为 '.' 或字母则直接返回 0（使用安全的类型转换）
        if (isalpha(static_cast<unsigned char>(s[i])) || s[i] == '.') return 0;

        // 判断正负并跳过符号
        bool negative = false;   // 修正拼写：negivate → negative
        if (s[i] == '-') {
            negative = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        int ans = 0;
        // 循环转换数字，同时提前判断溢出
        while (i < s.size() && isdigit(static_cast<unsigned char>(s[i]))) {
            int digit = s[i] - '0';

            // ★ 核心修改：溢出判断放在累加之前 ★
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return negative ? INT_MIN : INT_MAX;
            }

            ans = ans * 10 + digit;
            i++;
        }

        // 循环结束后的溢出判断已不需要（循环内已处理），直接返回
        return negative ? -ans : ans;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "请输入一个字符串: ";
    getline(cin, input);
    int result = solution.myAtoi(input);
    cout << "转换结果: " << result << endl;
    return 0;
}