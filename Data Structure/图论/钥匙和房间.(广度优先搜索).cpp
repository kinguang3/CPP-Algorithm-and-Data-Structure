#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> qu;
        int n = rooms.size();
        vector<int> visit(n, 0);
        int num = 0;
        qu.push(0);//从0号房间开始访问
        visit[0] = 1;
        while(!qu.empty())
        {
            int x = qu.front();               
            num++;
            qu.pop();
            for(auto i = 0; i < rooms[x].size(); ++i)
            {
                if(!visit[rooms[x][i]])//如果这个房间没有被访问过
                {
                    visit[rooms[x][i]] = 1;
                    qu.push(rooms[x][i]);//将这个房间加入队列中
                }
            }
        }
        return num == rooms.size();
    }
};