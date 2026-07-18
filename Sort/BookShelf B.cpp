#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, b, ans = 0, num = 0;
    cin>>n>>b;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i)cin>>a[i];
    sort(a.begin() + 1, a.end(), greater<int>());
    for(int i = 1; i <= n; ++i){
        if(ans >= b)break;
        ans += a[i];
        num++;
    }
    cout<<num;
}