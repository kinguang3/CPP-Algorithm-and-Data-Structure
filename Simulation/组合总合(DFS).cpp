#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        vector<vector<int>> ans;
        int pos = 0;
        dfs(res, candidates, target, ans, pos);
        return ans;
    }

    void dfs(vector<int>& res, vector<int>& candidates, int target, vector<vector<int>>& ans, int& pos){
        if(target == 0){
            ans.push_back(res);
            return;
        }
        for(int i = pos; i < candidates.size(); ++i){
            if(candidates[i] > target){
                return;
            }
            res.push_back(candidates[i]);
            dfs(res, candidates, target - candidates[i], ans, i);
            res.pop_back();
        }
    }
};