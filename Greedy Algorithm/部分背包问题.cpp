#include <bits/stdc++.h>
using namespace std;
int n,t;
float ans1;
#define ll long long
const ll N=1000;
vector<vector<float>> a(N,vector<float> (4));
bool cmp(vector<float> &x,vector<float> &y){
    return x[3]>y[3];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>t;
    
    for(int i=0;i<n;++i)
    {
        double m,v;
        cin>>m>>v;
        a[i][1]=m;
        a[i][2]=v;
        a[i][3]=v/m;
    }
    
    sort(a.begin(),a.begin()+n,cmp);
    for(int i=0;i<n;++i)
    {
        if(t<=0)break;
        if(t>0&&(t-a[i][1])<=0)
        {
            ans1+=t*a[i][3];
            break;
        }
        t-=a[i][1];
        ans1+=a[i][2];
    }
    printf("%.2f",ans1);
}