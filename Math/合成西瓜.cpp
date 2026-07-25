#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 998244353;

ll Num(ll n, ll base){
    ll r = 1;
    base %= MOD;
    while(n)
    {
        if(n & 1) r = (r * base) % MOD;
        base = (base * base) % MOD;  
        n >>= 1;                      
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        if(x <= y+1)
        {
            if(x <= y)
            {
                cout << 1 % MOD << endl;
                continue;
            }
            cout << x % MOD << endl;
        }
        else
        {
            ll exp = x - y - 1;                    
            ll num = Num(exp % (MOD - 1), 2);      
            ll res = ((y + 1) % MOD) * num % MOD;
            cout << res << endl;
        }
    }
    return 0;
}