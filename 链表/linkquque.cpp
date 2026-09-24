#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef int elemtype;
typedef struct LNode {   //第一个为结构体标签,拱结构体内部使用
    elemtype date;
    struct LNode *next;
}LNode;                  //第二个为该类型结构体别名
typedef struct {
    LNode *front,*rear;
}LinkQuque,*PLinkQuque;  //该类型结构体别名为LinkQuque,结构体指针别名为PLinkQuque
