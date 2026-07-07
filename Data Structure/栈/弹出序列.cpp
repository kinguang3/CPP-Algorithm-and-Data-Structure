#include <bits/stdc++.h>
using namespace std;
int main(){
    int m, n, k;
    cin>>m>>n>>k;
    for(int i = 0; i < k; ++i){
        bool is_pass = true;
        stack<int> st;
        vector<int> sqe(n+1);
        int pos = 1;
        for(int j = 1; j <= n; ++j){
            cin>>sqe[j];
        }
        for(int j = 1; j <= n; ++j){
            int tar = sqe[j];
            while(st.empty() || st.top() != tar){
                if(pos > n){
                    is_pass = false;
                    break;
                }
                st.push(pos++);
                if((int)st.size() > m){
                    is_pass = false;
                    break;
                }
            }
            if(!is_pass)break;
            st.pop();
        }
        if(is_pass){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}