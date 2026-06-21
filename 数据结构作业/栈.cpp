#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>
using namespace std;

// ============================================
// 题1：双栈结构（共享数组）
// ============================================
#define M 100  // 数组最大容量

typedef struct {
    int top[2], bot[2];  // 栈顶指针和栈底指针
    int *V;              // 共享数组
    int m;               // 数组最大容量
} DblStack;

// 双栈初始化
void InitDblStack(DblStack &S) {
    S.V = new int[M];
    S.m = M;
    S.bot[0] = S.top[0] = -1;   // 栈0：从左端开始，空时top[0]=-1
    S.bot[1] = S.top[1] = M;    // 栈1：从右端开始，空时top[1]=M
}

// 判断栈空
bool DblStackEmpty(DblStack &S, int i) {
    if (i == 0) return S.top[0] == -1;
    else return S.top[1] == M;
}

// 判断栈满
bool DblStackFull(DblStack &S) {
    return S.top[0] + 1 == S.top[1];
}

// 进栈
bool Push(DblStack &S, int i, int x) {
    if (DblStackFull(S)) {
        cout << "栈满！" << endl;
        return false;
    }
    if (i == 0) {
        S.V[++S.top[0]] = x;  // 栈0向右增长
    } else {
        S.V[--S.top[1]] = x;  // 栈1向左增长
    }
    return true;
}

// 出栈
bool Pop(DblStack &S, int i, int &x) {
    if (DblStackEmpty(S, i)) {
        cout << "栈空！" << endl;
        return false;
    }
    if (i == 0) {
        x = S.V[S.top[0]--];
    } else {
        x = S.V[S.top[1]++];
    }
    return true;
}

// ============================================
// 题2：回文判断
// ============================================
bool IsPalindrome(const char *str) {
    int len = strlen(str);
    stack<char> s;

    // 将前半部分字符入栈
    for (int i = 0; i < len / 2; i++) {
        s.push(str[i]);
    }

    // 从中间开始比较（奇数长度跳过中间字符）
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;
    for (int i = start; i < len; i++) {
        if (s.top() != str[i]) {
            return false;
        }
        s.pop();
    }
    return true;
}

// ============================================
// 题3：整数序列的栈处理（遇-1时输出栈顶并出栈）
// ============================================
void ProcessSequence() {
    stack<int> s;
    int a;
    cout << "请输入整数序列（以-2结束）：" << endl;

    while (cin >> a && a != -2) {
        if (a == -1) {
            if (s.empty()) {
                cout << "栈空，无法出栈！" << endl;
            } else {
                cout << s.top() << " ";
                s.pop();
            }
        } else {
            s.push(a);
        }
    }
    cout << endl;

    // 输出栈中剩余元素
    cout << "栈中剩余元素（从栈顶到栈底）：";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// ============================================
// 题4：后缀表达式求值
// ============================================
bool IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void PostfixEval() {
    stack<double> s;
    string token;
    cout << "请输入后缀表达式（操作数之间用空格分隔，以#结束）：" << endl;

    while (cin >> token && token != "#") {
        if (token.length() == 1 && IsOperator(token[0])) {
            // 运算符：弹出两个操作数进行计算
            if (s.size() < 2) {
                cout << "表达式错误！" << endl;
                return;
            }
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            double result;
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        cout << "除零错误！" << endl;
                        return;
                    }
                    result = a / b;
                    break;
            }
            s.push(result);
        } else {
            // 操作数：入栈
            s.push(atof(token.c_str()));
        }
    }

    if (s.size() == 1) {
        cout << "结果：" << s.top() << endl;
    } else {
        cout << "表达式错误！" << endl;
    }
}

// ============================================
// 题5：栈操作序列合法性判断
// ============================================

// 判断操作序列是否合法（I=入栈，O=出栈）
bool IsValidSequence(const char *seq) {
    int stackSize = 0;  // 模拟栈的大小
    for (int i = 0; seq[i] != '\0'; i++) {
        if (seq[i] == 'I') {
            stackSize++;
        } else if (seq[i] == 'O') {
            stackSize--;
            if (stackSize < 0) {
                return false;  // 栈空时出栈，不合法
            }
        }
    }
    return stackSize == 0;  // 最终栈必须为空
}

// 测试题5的选项
void TestSequences() {
    const char *options[] = {
        "IOIIOIOO",   // A
        "IOOIOIIO",   // B
        "IIIOIOIO",   // C
        "IIIOOIOO"    // D
    };
    char labels[] = {'A', 'B', 'C', 'D'};

    cout << "各序列合法性判断：" << endl;
    for (int i = 0; i < 4; i++) {
        cout << labels[i] << ". " << options[i]
             << " -> " << (IsValidSequence(options[i]) ? "合法" : "非法") << endl;
    }
}

// ============================================
// 题6：循环队列（设置标志tag判断空/满）
// ============================================
#define MAXQSIZE 10

typedef struct {
    int data[MAXQSIZE];
    int front;
    int rear;
    int tag;  // tag==0表示因删除导致front==rear（空），tag==1表示因插入导致front==rear（满）
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
    Q.tag = 0;
}

bool QueueEmpty(SqQueue &Q) {
    return Q.front == Q.rear && Q.tag == 0;
}

bool QueueFull(SqQueue &Q) {
    return Q.front == Q.rear && Q.tag == 1;
}

bool EnQueue(SqQueue &Q, int x) {
    if (QueueFull(Q)) {
        cout << "队列满！" << endl;
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    if (Q.rear == Q.front) Q.tag = 1;  // 插入导致front==rear，标记为满
    return true;
}

bool DeQueue(SqQueue &Q, int &x) {
    if (QueueEmpty(Q)) {
        cout << "队列空！" << endl;
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    if (Q.rear == Q.front) Q.tag = 0;  // 删除导致front==rear，标记为空
    return true;
}

// ============================================
// 题7：双端循环队列（两端均可插入和删除）
// ============================================
typedef struct {
    int data[MAXQSIZE];
    int front;
    int rear;
    int tag;
} Deque;

void InitDeque(Deque &D) {
    D.front = D.rear = 0;
    D.tag = 0;
}

bool DequeEmpty(Deque &D) {
    return D.front == D.rear && D.tag == 0;
}

bool DequeFull(Deque &D) {
    return D.front == D.rear && D.tag == 1;
}

// 从队尾插入
bool EnQueueRear(Deque &D, int x) {
    if (DequeFull(D)) { cout << "队列满！" << endl; return false; }
    D.data[D.rear] = x;
    D.rear = (D.rear + 1) % MAXQSIZE;
    if (D.rear == D.front) D.tag = 1;
    return true;
}

// 从队尾删除
bool DeQueueRear(Deque &D, int &x) {
    if (DequeEmpty(D)) { cout << "队列空！" << endl; return false; }
    D.rear = (D.rear - 1 + MAXQSIZE) % MAXQSIZE;
    x = D.data[D.rear];
    if (D.rear == D.front) D.tag = 0;
    return true;
}

// 从队头插入
bool EnQueueFront(Deque &D, int x) {
    if (DequeFull(D)) { cout << "队列满！" << endl; return false; }
    D.front = (D.front - 1 + MAXQSIZE) % MAXQSIZE;
    D.data[D.front] = x;
    if (D.rear == D.front) D.tag = 1;
    return true;
}

// 从队头删除
bool DeQueueFront(Deque &D, int &x) {
    if (DequeEmpty(D)) { cout << "队列空！" << endl; return false; }
    x = D.data[D.front];
    D.front = (D.front + 1) % MAXQSIZE;
    if (D.rear == D.front) D.tag = 0;
    return true;
}

// ============================================
// 题8：Ackermann函数
// ============================================

// 递归算法
int Ack(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return Ack(m - 1, 1);
    return Ack(m - 1, Ack(m, n - 1));
}

// 非递归算法（用栈模拟）
int AckNonRecursive(int m, int n) {
    stack<int> s;
    s.push(m);
    while (!s.empty()) {
        m = s.top(); s.pop();
        if (m == 0) {
            n = n + 1;
        } else if (n == 0) {
            s.push(m - 1);
            n = 1;
        } else {
            s.push(m - 1);
            s.push(m);
            n = n - 1;
        }
    }
    return n;
}



// ============================================
// 题9：链表递归算法
// ============================================
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 求链表中的最大整数
int MaxInList(LinkList L) {
    if (L->next == NULL) return L->data;  // 只有一个结点
    int maxRest = MaxInList(L->next);
    return L->data > maxRest ? L->data : maxRest;
}

// 求链表的结点个数
int CountNodes(LinkList L) {
    if (L == NULL) return 0;
    return 1 + CountNodes(L->next);
}

// 求所有整数的平均值（先求和再除）
double SumList(LinkList L) {
    if (L == NULL) return 0;
    return L->data + SumList(L->next);
}

double AvgList(LinkList L) {
    int count = CountNodes(L);
    if (count == 0) return 0;
    return SumList(L) / count;
}


