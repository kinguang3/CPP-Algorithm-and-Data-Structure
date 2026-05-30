#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isNumber(string c)
    {
        return (c[0]>='0'&&c[0]<='9')||(c[0]=='-'&&c.size()>1);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto i=0;i<tokens.size();++i)
        {
            string token = tokens[i];
            if(isNumber(token))
            {
                st.push(stoi(token));
            }
            else
            {
                int m = st.top();
                st.pop();
                int n = st.top();
                st.pop();
                switch(token[0])//根据运算符进行计算
                {
                    case '+':st.push(n+m);break;
                    case '-':st.push(n-m);break;
                    case '*':st.push(n*m);break;
                    case '/':
                    {
                        if(m==0)
                        {
                            return 0;
                        }
                        st.push(n/m);
                    }
                    break;
                }
            }
        }
        return st.top();
    }
};