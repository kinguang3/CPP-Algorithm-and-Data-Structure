#include <bits/stdc++.h>
using namespace std;
int main(){
    string n,m;
    cin>>n>>m;
    int a[2005]={0},b[2005]={0},c[4000000]={0};
    for(int i=0;i<n.size();++i)
    {
        a[i]=n[n.size()-1-i]-'0';
    }
    for(int i=0;i<m.size();++i)
    {
        b[i]=m[m.size()-1-i]-'0';
    }
    for(int i=0;i<n.size();++i)
    {
        for(int j=0;j<m.size();++j)
        {
            c[j+i]=c[j+i]+a[i]*b[j];
            if(c[j+i]>=10)
            {
                c[j+i+1]+=c[j+i]/10;
                c[j+i]%=10;
            }
        }
    }
    int index;
    int len=n.size()+m.size();
    for(int i=len-1;i>=0;--i)
    {
        if(c[i]!=0)
        {
            index=i;
            break;
        }
    }
    for(int i=index;i>=0;--i)cout<<c[i];
}