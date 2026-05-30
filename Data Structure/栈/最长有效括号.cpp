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
                    ma = max(ma,i-st.top());//如果当前字符是右括号，就弹出栈顶元素，如果栈为空，就将当前索引入栈，否则就计算当前有效括号的长度，并更新最大长度。
                }
            }
        }
        return ma;
    }
};