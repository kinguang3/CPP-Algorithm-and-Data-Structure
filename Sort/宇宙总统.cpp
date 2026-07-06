#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n == 0)return 0;
    vector<string> a(n+1);
    for(auto i = 1; i <= n; ++i)
    {
        cin>>a[i];
    }
    int f = 1;
    string M = a[1];
    for(auto i = 2; i <= n; ++i)
    {
        if(a[i].size() > M.size())
        {
            M = a[i];
            f = i;
        }
        else if(a[i].size() == M.size())
        {
            for(auto j = 0; j < M.size(); ++j)
            {
                if(a[i][j] == M[j])continue;
                else if(a[i][j] < M[j])break;
                else
                {
                    M = a[i];
                    f = i;
                    break;
                }
            }
        }
    }
    cout<<f<<endl;
    cout<<M;
}