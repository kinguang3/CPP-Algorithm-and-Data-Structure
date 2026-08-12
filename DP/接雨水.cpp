#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> L_MAX(1e5, 0);
        vector<int> R_MAX(1e5, 0);
        vector<int> ans(1e5);
        int high = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            high = max(high, height[i]);
            L_MAX[i] = max(high, L_MAX[i]);
        }
        high = 0;
        for(int i = height.size() - 1; i >= 0; --i)
        {
            high = max(high, height[i]);
            R_MAX[i] = max(high, R_MAX[i]);
        }
        for(int i = 0; i < height.size(); ++i)
        {
            ans[i] = min(L_MAX[i], R_MAX[i]);
        }
        int res = 0;
        for(int i = 0; i < height.size(); ++i)res += ans[i] - height[i];
        return res;
    }
};