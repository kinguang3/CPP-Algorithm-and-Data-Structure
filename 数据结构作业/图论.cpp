#include <bits/stdc++.h>
using namespace std;

// ============================================
// 题1：图的基本操作（邻接矩阵）
// ============================================
const int MAXVEX = 100;
const int INF = INT_MAX;

typedef struct {
    char vex[MAXVEX];       // 顶点表
    int arc[MAXVEX][MAXVEX]; // 邻接矩阵
    int vexnum, arcnum;      // 顶点数和边数
} MGraph;

// 创建邻接矩阵图
void CreateMGraph(MGraph &G) {
    cout << "请输入顶点数和边数：";
    cin >> G.vexnum >> G.arcnum;
    
    // 初始化顶点
    cout << "请输入顶点：";
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.vex[i];
    }
    
    // 初始化邻接矩阵为0
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.arc[i][j] = 0;
        }
    }
    
    // 输入边
    cout << "请输入边（vi vj）：" << endl;
    for (int k = 0; k < G.arcnum; k++) {
        char vi, vj;
        cin >> vi >> vj;
        int i = -1, j = -1;
        for (int m = 0; m < G.vexnum; m++) {
            if (G.vex[m] == vi) i = m;
            if (G.vex[m] == vj) j = m;
        }
        if (i != -1 && j != -1) {
            G.arc[i][j] = 1;
            // 无向图需要双向
        }
    }
}

// 查找顶点位置
int LocateVex(MGraph &G, char v) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vex[i] == v) return i;
    }
    return -1;
}

// 添加顶点
void InsertVertex(MGraph &G, char v) {
    if (G.vexnum >= MAXVEX) {
        cout << "图已满！" << endl;
        return;
    }
    if (LocateVex(G, v) != -1) {
        cout << "顶点已存在！" << endl;
        return;
    }
    G.vex[G.vexnum++] = v;
    // 初始化新顶点的边
    for (int i = 0; i < G.vexnum; i++) {
        G.arc[G.vexnum-1][i] = 0;
        G.arc[i][G.vexnum-1] = 0;
    }
    cout << "顶点 " << v << " 添加成功！" << endl;
}

// 删除顶点
void DeleteVertex(MGraph &G, char v) {
    int pos = LocateVex(G, v);
    if (pos == -1) {
        cout << "顶点不存在！" << endl;
        return;
    }
    // 删除顶点
    for (int i = pos; i < G.vexnum - 1; i++) {
        G.vex[i] = G.vex[i + 1];
    }
    // 删除该行和该列的边
    for (int i = pos; i < G.vexnum - 1; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.arc[i][j] = G.arc[i + 1][j];
        }
    }
    for (int j = pos; j < G.vexnum - 1; j++) {
        for (int i = 0; i < G.vexnum; i++) {
            G.arc[i][j] = G.arc[i][j + 1];
        }
    }
    G.vexnum--;
    cout << "顶点 " << v << " 删除成功！" << endl;
}

// 添加边
void InsertArc(MGraph &G, char v, char w) {
    int i = LocateVex(G, v);
    int j = LocateVex(G, w);
    if (i == -1 || j == -1) {
        cout << "顶点不存在！" << endl;
        return;
    }
    if (G.arc[i][j] == 1) {
        cout << "边已存在！" << endl;
        return;
    }
    G.arc[i][j] = 1;
    cout << "边 <" << v << "," << w << "> 添加成功！" << endl;
}

// 删除边
void DeleteArc(MGraph &G, char v, char w) {
    int i = LocateVex(G, v);
    int j = LocateVex(G, w);
    if (i == -1 || j == -1) {
        cout << "顶点不存在！" << endl;
        return;
    }
    if (G.arc[i][j] == 0) {
        cout << "边不存在！" << endl;
        return;
    }
    G.arc[i][j] = 0;
    cout << "边 <" << v << "," << w << "> 删除成功！" << endl;
}

// 打印邻接矩阵
void PrintMGraph(MGraph &G) {
    cout << "邻接矩阵：" << endl;
    cout << "  ";
    for (int i = 0; i < G.vexnum; i++) {
        cout << G.vex[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << G.vex[i] << " ";
        for (int j = 0; j < G.vexnum; j++) {
            cout << G.arc[i][j] << " ";
        }
        cout << endl;
    }
}

// ============================================
// 题2：图的基本操作（邻接表）
// ============================================
typedef struct ArcNode {
    int adjvex;       // 邻接点下标
    struct ArcNode *nextarc; // 下一条边
} ArcNode;

typedef struct VNode {
    char data;        // 顶点数据
    ArcNode *firstarc; // 第一条边
} VNode, AdjList[MAXVEX];

typedef struct {
    AdjList vertices; // 顶点数组
    int vexnum, arcnum; // 顶点数和边数
} ALGraph;

// 创建邻接表图
void CreateALGraph(ALGraph &G) {
    cout << "请输入顶点数和边数：";
    cin >> G.vexnum >> G.arcnum;
    
    // 初始化顶点
    cout << "请输入顶点：";
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    
    // 输入边
    cout << "请输入边（vi vj）：" << endl;
    for (int k = 0; k < G.arcnum; k++) {
        char vi, vj;
        cin >> vi >> vj;
        int i = -1, j = -1;
        for (int m = 0; m < G.vexnum; m++) {
            if (G.vertices[m].data == vi) i = m;
            if (G.vertices[m].data == vj) j = m;
        }
        if (i != -1 && j != -1) {
            ArcNode *p = new ArcNode;
            p->adjvex = j;
            p->nextarc = G.vertices[i].firstarc;
            G.vertices[i].firstarc = p;
        }
    }
}

// 查找顶点位置（邻接表）
int LocateVexAL(ALGraph &G, char v) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == v) return i;
    }
    return -1;
}

// 添加顶点（邻接表）
void InsertVertexAL(ALGraph &G, char v) {
    if (G.vexnum >= MAXVEX) { cout << "图已满！" << endl; return; }
    if (LocateVexAL(G, v) != -1) { cout << "顶点已存在！" << endl; return; }
    G.vertices[G.vexnum].data = v;
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum++;
    cout << "顶点 " << v << " 添加成功！" << endl;
}

// 删除顶点（邻接表）
void DeleteVertexAL(ALGraph &G, char v) {
    int pos = LocateVexAL(G, v);
    if (pos == -1) { cout << "顶点不存在！" << endl; return; }
    
    // 删除该顶点的所有边
    ArcNode *p = G.vertices[pos].firstarc;
    while (p) {
        ArcNode *q = p;
        p = p->nextarc;
        delete q;
    }
    
    // 删除其他顶点指向该顶点的边
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *pre = NULL, *cur = G.vertices[i].firstarc;
        while (cur) {
            if (cur->adjvex == pos) {
                if (pre == NULL) G.vertices[i].firstarc = cur->nextarc;
                else pre->nextarc = cur->nextarc;
                delete cur;
                break;
            }
            pre = cur;
            cur = cur->nextarc;
        }
    }
    
    // 更新邻接点下标
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *cur = G.vertices[i].firstarc;
        while (cur) {
            if (cur->adjvex > pos) cur->adjvex--;
            cur = cur->nextarc;
        }
    }
    
    // 删除顶点
    for (int i = pos; i < G.vexnum - 1; i++) {
        G.vertices[i] = G.vertices[i + 1];
    }
    G.vexnum--;
    cout << "顶点 " << v << " 删除成功！" << endl;
}

// 添加边（邻接表）
void InsertArcAL(ALGraph &G, char v, char w) {
    int i = LocateVexAL(G, v);
    int j = LocateVexAL(G, w);
    if (i == -1 || j == -1) { cout << "顶点不存在！" << endl; return; }
    
    // 检查边是否已存在
    ArcNode *p = G.vertices[i].firstarc;
    while (p) {
        if (p->adjvex == j) { cout << "边已存在！" << endl; return; }
        p = p->nextarc;
    }
    
    ArcNode *newArc = new ArcNode;
    newArc->adjvex = j;
    newArc->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = newArc;
    cout << "边 <" << v << "," << w << "> 添加成功！" << endl;
}

// 删除边（邻接表）
void DeleteArcAL(ALGraph &G, char v, char w) {
    int i = LocateVexAL(G, v);
    int j = LocateVexAL(G, w);
    if (i == -1 || j == -1) { cout << "顶点不存在！" << endl; return; }
    
    ArcNode *pre = NULL, *cur = G.vertices[i].firstarc;
    while (cur) {
        if (cur->adjvex == j) {
            if (pre == NULL) G.vertices[i].firstarc = cur->nextarc;
            else pre->nextarc = cur->nextarc;
            delete cur;
            cout << "边 <" << v << "," << w << "> 删除成功！" << endl;
            return;
        }
        pre = cur;
        cur = cur->nextarc;
    }
    cout << "边不存在！" << endl;
}

// 打印邻接表
void PrintALGraph(ALGraph &G) {
    cout << "邻接表：" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << G.vertices[i].data << " -> ";
        ArcNode *p = G.vertices[i].firstarc;
        while (p) {
            cout << G.vertices[p->adjvex].data << " ";
            p = p->nextarc;
        }
        cout << endl;
    }
}

// ============================================
// 题3：深度优先搜索（邻接表）
// ============================================
bool visited[MAXVEX];

// 递归DFS
void DFS(ALGraph &G, int v) {
    cout << G.vertices[v].data << " ";
    visited[v] = true;
    ArcNode *p = G.vertices[v].firstarc;
    while (p) {
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

// 非递归DFS
void DFS_NonRecursive(ALGraph &G, int v) {
    stack<int> s;
    s.push(v);
    visited[v] = true;
    bool first = true;
    
    while (!s.empty()) {
        int cur = s.top();
        if (first) {
            cout << G.vertices[cur].data << " ";
            first = false;
        }
        
        ArcNode *p = G.vertices[cur].firstarc;
        bool hasUnvisited = false;
        while (p) {
            if (!visited[p->adjvex]) {
                visited[p->adjvex] = true;
                s.push(p->adjvex);
                first = true;
                hasUnvisited = true;
                break;
            }
            p = p->nextarc;
        }
        
        if (!hasUnvisited) {
            s.pop();
            first = false;
        }
    }
}

// ============================================
// 题4：最长路径（距离v最短路径最长的顶点）
// ============================================
void LongestShortestPath(ALGraph &G, int v) {
    int dist[MAXVEX];
    bool visited[MAXVEX];
    queue<int> q;
    
    // 初始化距离
    for (int i = 0; i < G.vexnum; i++) {
        dist[i] = -1;
        visited[i] = false;
    }
    
    dist[v] = 0;
    visited[v] = true;
    q.push(v);
    
    // BFS求最短路径
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        ArcNode *p = G.vertices[cur].firstarc;
        while (p) {
            if (!visited[p->adjvex]) {
                dist[p->adjvex] = dist[cur] + 1;
                visited[p->adjvex] = true;
                q.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
    
    // 找最长距离
    int maxDist = -1, maxVex = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
            maxVex = i;
        }
    }
    
    cout << "距离顶点 " << G.vertices[v].data 
         << " 最短路径最长的顶点是 " << G.vertices[maxVex].data
         << "，距离为 " << maxDist << endl;
}

// ============================================
// 题5：有向图中v到u的路径判断（邻接表）
// ============================================
bool HasPath(ALGraph &G, int v, int u) {
    if (v == u) return true;
    
    bool visited[MAXVEX];
    memset(visited, false, sizeof(visited));
    
    stack<int> s;
    s.push(v);
    visited[v] = true;
    
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        
        ArcNode *p = G.vertices[cur].firstarc;
        while (p) {
            if (p->adjvex == u) return true;
            if (!visited[p->adjvex]) {
                visited[p->adjvex] = true;
                s.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
    
    return false;
}

// ============================================
// 题6：无向图中长度为k的简单路径判断（邻接表）
// ============================================
bool HasPathLengthK(ALGraph &G, int v, int u, int k) {
    if (k == 0) return v == u;
    if (k == 1) {
        ArcNode *p = G.vertices[v].firstarc;
        while (p) {
            if (p->adjvex == u) return true;
            p = p->nextarc;
        }
        return false;
    }
    
    bool visited[MAXVEX];
    memset(visited, false, sizeof(visited));
    visited[v] = true;
    
    stack<pair<int, int>> s; // (顶点, 路径长度)
    s.push({v, 0});
    
    while (!s.empty()) {
        auto [cur, len] = s.top();
        s.pop();
        
        ArcNode *p = G.vertices[cur].firstarc;
        while (p) {
            if (p->adjvex == u && len + 1 == k) {
                return true;
            }
            if (!visited[p->adjvex] && len + 1 < k) {
                visited[p->adjvex] = true;
                s.push({p->adjvex, len + 1});
            }
            p = p->nextarc;
        }
    }
    
    return false;
}

// ============================================
// 辅助函数：构建示例图
// ============================================
void BuildSampleGraph(ALGraph &G) {
    G.vexnum = 6;
    G.arcnum = 8;
    
    char vertices[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    for (int i = 0; i < G.vexnum; i++) {
        G.vertices[i].data = vertices[i];
        G.vertices[i].firstarc = NULL;
    }
    
    // 添加边（有向图）
    int edges[][2] = {{0,1},{0,2},{1,3},{2,4},{3,5},{4,5},{5,1},{2,3}};
    for (auto &e : edges) {
        ArcNode *p = new ArcNode;
        p->adjvex = e[1];
        p->nextarc = G.vertices[e[0]].firstarc;
        G.vertices[e[0]].firstarc = p;
    }
}

