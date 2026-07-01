#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,res,r,l,mid,f;
    cin>>n>>m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)
    {
        cin>>b[i];
        f=0;
        l=1;
        r=n;
        while(l<r)
        {
            mid=(l+r)/2;
            if(a[mid]>=b[i])r=mid;
            else l=mid+1;
        }
        if(a[l]!=b[i])f=-1;
        else f=l;
        cout<<f<<' ';
    }
}

