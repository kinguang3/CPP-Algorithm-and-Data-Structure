#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, num = 0;
    cin>>n;
    vector<int> a(n+1);
    for(int i =1; i <= n; ++i){
        cin>>a[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n-i; ++j){
            if(a[j] > a[j+1]){
                swap(a[j+1], a[j]);
                num++;
            }
        }
    }
    cout<<num;
}