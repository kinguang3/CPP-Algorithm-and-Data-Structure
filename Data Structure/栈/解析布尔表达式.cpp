#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int t_n = 0;
        int f_n = 0;
        stack<char> st;
        for(auto i = 0; i < expression.size(); ++i)
        {
            if(expression[i] == ',')continue;
            if(expression[i] != ')')
            {
                st.push(expression[i]);
                continue;
            }
            t_n = 0;
            f_n = 0;
            while(st.top() != '(')
            {
                if(st.top() == 't')t_n++;
                else if (st.top() == 'f')f_n++;
                st.pop();
                
            }
            st.pop();
            switch(st.top())//根据栈顶的运算符进行计算
            {
                case '!':
                    st.push((f_n == 1)?'t':'f');
                    break;
                
                case '|':
                    st.push((t_n > 0)?'t':'f');
                    break;
                
                case '&':
                    st.push((f_n == 0)?'t':'f');
                    break;
            }
        }
        return (st.top() == 't');
    }
};