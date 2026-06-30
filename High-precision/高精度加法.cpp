#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[501]={0},b[501]={0},c[501]={0};
    string n,m;
    cin>>n>>m;
    for(int i=0;i<n.size();++i)a[i]=n[n.size()-1-i]-'0';
    for(int i=0;i<m.size();++i)b[i]=m[m.size()-1-i]-'0';
    for(int i=0;i<502;++i)
    {
        c[i]+=(a[i]+b[i]);
        if(c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
    int index;
    for(int i=501;i>=0;--i)
    {
        if(c[i]!=0)
        {
            index=i;
            break;
        }
    }
    for(int i=index;i>=0;--i)cout<<c[i];
}

