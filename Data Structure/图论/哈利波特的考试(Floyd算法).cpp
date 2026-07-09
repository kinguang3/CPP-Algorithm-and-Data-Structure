#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size() - 1;
    vector<vector<int>> dist = graph;
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}
int main(){
    int n, m;
    bool is_pass = true;
    cin>>n>>m;
    int ans = INT_MAX;
    vector<int> d(n+1, 0);
    vector<vector<int>> a(n+1, vector<int> (n+1, INT_MAX));
    for(int i = 0; i < m; ++i){
        int x, y, dist;
        cin>>x>>y>>dist;
        a[x][y] = dist;
        a[y][x] = dist;
    }
    a = floydWarshall(a);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)a[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)continue;
            if(a[i][j] == INT_MAX)is_pass = false;
        }
        if(is_pass)break;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            d[i] =  max(d[i], a[i][j]);
        }
    }
    int f = 0;
    for(int i = 1; i <= n; ++i){
        if(d[i] < ans){
            ans = d[i];
            f = i;
        }
    }
    if(!is_pass)cout<<0;
    else  cout<<f<<" "<<ans;
    
}