#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        int fast = 1,slow = 1;
        while(fast<nums.size())
        {
            if(nums[fast] != nums[fast-1])//如果当前元素与前一个元素不同，说明是一个新的元素
            {
                nums[slow] = nums[fast];//将不重复的元素移动到前面
                slow++;
            }
            fast++;
        }
        return slow;
    }
};