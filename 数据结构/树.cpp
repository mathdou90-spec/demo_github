#include <iostream>
#include <queue> // 层序遍历需要用到队列

using namespace std;

// 1. 二叉树结构体定义
typedef char ElemType; // 假设数据域为字符

typedef struct BinTNode {
    ElemType data;
    struct BinTNode *lchild;
    struct BinTNode *rchild;

    // 构造函数（方便创建节点）
    BinTNode(ElemType val) : data(val), lchild(nullptr), rchild(nullptr) {}
} BinTNode, *BinTree;


// ==================== 遍历算法实现 ====================

// 2. 前序遍历 (Preorder Traversal): 根 -> 左 -> 右
void PreOrder(BinTree T) {
    if (T == nullptr) return;
    cout << T->data << " ";   // 访问根节点
    PreOrder(T->lchild);      // 递归遍历左子树
    PreOrder(T->rchild);      // 递归遍历右子树
}

// 3. 中序遍历 (Inorder Traversal): 左 -> 根 -> 右
void InOrder(BinTree T) {
    if (T == nullptr) return;
    InOrder(T->lchild);       // 递归遍历左子树
    cout << T->data << " ";   // 访问根节点
    InOrder(T->rchild);       // 递归遍历右子树
}

// 4. 后序遍历 (Postorder Traversal): 左 -> 右 -> 根
void PostOrder(BinTree T) {
    if (T == nullptr) return;
    PostOrder(T->lchild);     // 递归遍历左子树
    PostOrder(T->rchild);     // 递归遍历右子树
    cout << T->data << " ";   // 访问根节点
}

// 5. 层序遍历 (Level Order Traversal): 逐层从左到右
void LevelOrder(BinTree T) {
    if (T == nullptr) return;
    
    queue<BinTree> q; // 定义一个队列，存放结点指针
    q.push(T);        // 根节点入队
    
    while (!q.empty()) {
        BinTree current = q.front(); // 取出队头元素
        q.pop();                     // 队头出队
        cout << current->data << " ";// 访问当前节点
        
        // 如果有左孩子，左孩子入队
        if (current->lchild != nullptr) {
            q.push(current->lchild);
        }
        // 如果有右孩子，右孩子入队
        if (current->rchild != nullptr) {
            q.push(current->rchild);
        }
    }
}


// ==================== 测试代码 ====================
int main() {
    /*
              A
            /   \
           B     C
          / \   / \
         D   E F   G
    */
    
    // 手动构建一棵二叉树
    BinTree root = new BinTNode('A');
    root->lchild = new BinTNode('B');
    root->rchild = new BinTNode('C');
    
    root->lchild->lchild = new BinTNode('D');
    root->lchild->rchild = new BinTNode('E');
    
    root->rchild->lchild = new BinTNode('F');
    root->rchild->rchild = new BinTNode('G');

    // 打印各种遍历结果
    cout << "前序遍历 (根左右): ";
    PreOrder(root);
    cout << endl;

    cout << "中序遍历 (左根右): ";
    InOrder(root);
    cout << endl;

    cout << "后序遍历 (左右根): ";
    PostOrder(root);
    cout << endl;

    cout << "层序遍历 (逐层打印): ";
    LevelOrder(root);
    cout << endl;

    // 实际项目中需要释放内存，这里为了代码简洁省略了
    // 需注意：手动 new 的节点需要手动 delete 释放内存
    
    return 0;
}