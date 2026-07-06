#include <bits/stdc++.h>
using namespace std;
int a[200010];
int dp[200010];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    dp[1]=a[1];
    int gd_max=dp[1];
    for(int i=2;i<=n;++i)
    {
        dp[i]=max(dp[i-1]+a[i],a[i]);
        gd_max=max(dp[i],gd_max);
    }
    cout<<gd_max;
}