#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> qu;
        int tmp,res = 1,cnt;
        for(int i=1;i<=n;i++)qu.push(i);
        while(!qu.empty()){
            tmp=qu.front();
            if(res==k){
                if(qu.size() == 1)
                {
                    cnt = qu.front();
                    break;
                }
                qu.pop();
                res=1;

                continue;
            }
            qu.pop();
            qu.push(tmp);
            res+=1;
            if(qu.size() == 1)
            {
                cnt = qu.front();
                break;
            }
        }
        return cnt;
    }
};