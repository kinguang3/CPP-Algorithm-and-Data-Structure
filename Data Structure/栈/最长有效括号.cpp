#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ma = 0;
        for(auto i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    ma = max(ma,i-st.top());
                }
            }
        }
        return ma;
    }
};