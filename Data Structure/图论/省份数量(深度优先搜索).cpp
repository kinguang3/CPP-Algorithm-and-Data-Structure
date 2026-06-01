#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    void dfs(vector<vector<int>> isConnected, vector<int> &visit, int n, int i)
    {
        for(auto j = 0; j < n; ++j)
        {
            if(!visit[j] && isConnected[i][j] == 1)
            {
                visit[j] = 1;
                dfs(isConnected, visit, n, j);//如果j没有被访问过，并且i和j之间有连接，那么就继续访问j的邻接点，直到访问完所有与i直接或间接连接的点为止
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int pr = 0;
        int n = isConnected.size();
        vector<int> visit(n, 0);
        for(auto i = 0; i < n; ++i)
        {
            if(!visit[i])//如果i没有被访问过，说明i所在的省份还没有被统计过，那么就以i为起点进行深度优先搜索，访问所有与i直接或间接连接的点，并将它们标记为已访问。每次进行一次深度优先搜索，就说明找到了一个新的省份，因此将省份数量加1。
            {
                dfs(isConnected, visit, n, i);
                pr++;
            }
        }
        return pr;
    }
};