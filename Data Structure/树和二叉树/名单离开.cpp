#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, root = 0;
    bool is_first = true;
    cin>>n;
    queue<int> q;
    vector<vector<char>> a(n, vector<char> (2));
    vector<int> num(25, 0);
    vector<int> b(25, -1);
    stack<int> res;
    for(int i = 0; i < n; ++i){
        cin>>a[i][0]>>a[i][1];
    }
    int f = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2; ++j){
            if(a[i][j] == '-')continue;
            num[f] = a[i][j] - '0';
            f++;
        }
    }
    sort(num.begin(), num.end());
    for(int i = 24; i > 0; --i){
        if((num[i] - num[i-1]) == 2){
            root = (num[i] + num[i-1]) / 2;
            break;
        }
    }
    q.push(root);
    while(!q.empty()){
        int tem = q.front();
        if(a[tem][0] == '-' && a[tem][1] == '-')res.push(tem);
        q.pop();
        for(int i = 0; i < 2; ++i){
            if(a[tem][i] == '-')continue;
            q.push(a[tem][i]-'0');
        }
    }
    int root_num = res.size();
    for(int i = res.size(); i > 0; --i){
        b[i] = res.top();
        res.pop();
    }
    for(int i = 1; i <= root_num; ++i){
        if(!is_first)cout<<" ";
        cout<<b[i];
        is_first = false;
    }
}