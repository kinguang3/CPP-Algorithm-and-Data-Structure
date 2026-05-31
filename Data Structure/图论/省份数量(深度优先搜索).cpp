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
                dfs(isConnected, visit, n, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int pr = 0;
        int n = isConnected.size();
        vector<int> visit(n, 0);
        for(auto i = 0; i < n; ++i)
        {
            if(!visit[i])
            {
                dfs(isConnected, visit, n, i);
                pr++;
            }
        }
        return pr;
    }
};