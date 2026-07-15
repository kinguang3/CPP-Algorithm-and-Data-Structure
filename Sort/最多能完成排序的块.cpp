#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int num = 0, ma = 0;
        for(int i = 0; i < arr.size(); ++i){
            ma = max(ma, arr[i]);
            if(ma == i)num++;
        } 
        return num;
    }
};