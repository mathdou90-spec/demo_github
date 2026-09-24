 #include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* str;  // 存储字符串
    int len;    // 存储字符串长度
    
public:
    // 构造函数，用传入的C风格字符串初始化
    MyString(const char* s = "") {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        //strcpy相当于一个字符一个字符的copy
    }
    
    // 析构函数，释放动态分配的内存
    ~MyString() {
        delete[] str;
    }
    
    // 返回字符串长度
    int length() const {
        return len;
    }
    
    // 查找子串，找到返回首次出现的位置，否则返回-1
    int find(const char* find_str) const {
        // 如果查找的字符串为空或比原字符串长，直接返回-1
        if (find_str == nullptr || strlen(find_str) > static_cast<size_t>(len)) {
            return -1;
        }
        
        // 暴力匹配算法
        int find_len = strlen(find_str);
        for (int i = 0; i <= len - find_len; i++) {
            bool found = true;
            for (int j = 0; j < find_len; j++) {
                if (str[i + j] != find_str[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;  // 找到，返回位置
            }
        }
        return -1;  // 没找到
    }
    
    // 为了方便查找，可以添加一个重载版本，但题目没有要求
    // int find(const MyString& find_str) const {
    //     return find(find_str.c_str());
    // }
    
    // 返回内部字符串的C风格指针（辅助函数）
    const char* c_str() const {
        return str;
    }
};

int main() {
    // 读取初始字符串
    char init_str[1000];  // 假设最大长度
    cin >> init_str;
    
    // 创建MyString实例
    MyString myStr(init_str);
    
    // 读取询问次数
    int N;
    cin >> N;
    
    // 处理每个询问
    for (int i = 0; i < N; i++) {
        int op;
        cin >> op;
        
        if (op == 1) {
            // 操作1：输出字符串长度
            cout << myStr.length() << endl;
        } else if (op == 2) {
            // 操作2：查找子串
            char find_str[1000];
            cin >> find_str;
            cout << myStr.find(find_str) << endl;
        }
    }
    
    return 0;
}