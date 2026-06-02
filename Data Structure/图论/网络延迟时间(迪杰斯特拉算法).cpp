#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int MAX = INT_MAX / 2;
        vector<vector<int>> g(n,vector<int> (n, MAX));
        for(auto i = 0; i < times.size(); ++i)
        {
            int v1 = times[i][0],v2 = times[i][1];//构造邻接矩阵
            g[v1-1][v2-1] = times[i][2];
        }
        vector<int> dist(n, MAX);
        dist[k-1] = 0;//初始化源节点的距离
        vector<int> used(n, 0);
        int ans = 0;
        for(auto i = 0; i < n; ++i)
        {
            int x = -1;
            for(auto j = 0; j < n; ++j)
            {
                if(!used[j] && (x == -1||dist[j] < dist[x]))
                {
                    x = j;//找到未访问的点中距离最小的点
                    
                }
            }
            used[x] = 1;
            ans = max(ans, dist[x]);
            for(auto j = 0; j < n; ++j)
            {
                dist[j] = min(dist[j], dist[x]+g[x][j]);
            }
            
        }
        return ans == MAX ? -1 : ans; 
    }
};