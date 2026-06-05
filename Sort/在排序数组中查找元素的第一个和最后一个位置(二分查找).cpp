#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> res(2);
        if(nums.empty())
        {
            res[0] = -1;
            res[1] = -1;
            return res;
        }
        int first = lower_bound(nums.begin(), nums.end(),target) - nums.begin();//找到第一个大于等于target的元素位置
        int second = upper_bound(nums.begin(), nums.end(),target) - nums.begin() - 1;//找到第一个大于target的元素位置，减1即为最后一个等于target的元素位置
        if(first >= nums.size() || nums[first] != target)
        {
            res[0] = -1;
            res[1] = -1;
        }
        else
        {
            res[0] = first;
            res[1] = second;
        }
        return res;
    }
};