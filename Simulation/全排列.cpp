#include <bits/stdc++.h>
using namespace std;
int n,f=0;
bool a[12];
int b[12];
void dfs(int x){
    if(x>n)
    {
        for(int i=1;i<=n;++i)
        {
            cout<<"    "<<b[i];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!a[i])
        {
            a[i]=true;
            b[x]=i;
            dfs(x+1);
            a[i]=false;
            b[x]=0;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
}