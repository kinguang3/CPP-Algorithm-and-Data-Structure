#include <bits/stdc++.h>
using namespace std;
int pro[6];
vector<bool> is_pass(1e4+5, false);
bool cmp(vector<int>& a,vector<int>& b){
    if(a[0] != b[0]){
        return a[0] > b[0] ;
    }
    int cnta = 0, cntb = 0;
    for(int j = 1; j <= 5; ++j){
        if(a[j] == pro[j])cnta++;
        if(b[j] == pro[j])cntb++;
    }
    if(cnta != cntb)return cnta > cntb;
    return a[6] < b[6];
}

void Print(vector<vector<int>> a, int n, int m, int k){
    for(auto i = 1; i <= n; ++i){
        if(a[i][0] < 0)continue;
        cout<<a[i][7]<<" ";
        printf("%05d", a[i][6]);
        cout<<" "<<a[i][0];
        for(auto j = 1; j <= k; ++j){
            cout<<" ";
            if(a[i][j] == -2){
                cout<<"-";
            }
            else cout<<a[i][j];
        }
        cout<<endl;
    }
}

int main(){
    int n, k, m;
    cin>>n>>k>>m;
    for(auto i = 1; i <= k; ++i){
        cin>>pro[i];
    }
    vector<vector<int>> a(1e4+5, vector<int> (8, -2));
    for(auto i = 0; i < m; ++i){
        int pos, tas, scor;
        cin>>pos>>tas>>scor;
        a[pos][tas] = max(a[pos][tas], scor);
        if(a[pos][tas] == -1)a[pos][tas] = 0;
        a[pos][6] = pos;
        if(scor != -1)is_pass[pos] = true;
    }
    for(auto i = 1; i <= n; ++i){
        a[i][0] = 0;
        for(auto j = 1; j <= k; ++j){
            if(a[i][j] != -2){
                a[i][0] += a[i][j];
            }
        }
        if(!is_pass[i]) a[i][0] = -1;
    }
    sort(a.begin()+1, a.begin()+n+1, cmp);
    a[1][7] = 1;
    for(auto i = 2; i <= n; ++i){
        if(a[i][0] == a[i-1][0]){
            a[i][7] = a[i-1][7];
        }
        else a[i][7] = i;
    }
    Print(a, n, m, k);
    return 0;
    }