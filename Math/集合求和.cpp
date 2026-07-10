#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<int> a;
    ll i = 0, x, cnt;
    ll ans = 0, tmp = 0;
    while(cin>>x){
        a.push_back(x);
        tmp += x;
        i++;
    }
    cnt = pow(2, i-1);
    ans = tmp * cnt;
    cout<<ans;
}