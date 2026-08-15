#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=35;
vector<string> a(N);
int n;
bool cmp(string x,string y){
    return x+y>y+x;
}

int main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a.begin(),a.begin()+n,cmp);
    for(int i=0;i<n;++i)cout<<a[i];
}