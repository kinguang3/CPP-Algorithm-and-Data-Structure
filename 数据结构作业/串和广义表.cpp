#include <bits/stdc++.h>
using namespace std;


void Charge_Ele(string s, int *a[]) {
    for(auto i = 0; i < s.length(); i++) {
            a[s[i] - 'A'] += 1;
        }
}



void Reverse_Ele(string s) {
    for(auto i = 0; i < s.length(); i++) {
        swap(s[i], s[s.length() - 1 - i]);
    }
}


void insert(char *s, char *t, int pos) {
    int len = strlen(s);// 原字符串长度
    for(int i = len; i >= pos; i--) {
        s[i + strlen(t)] = s[i];
    }
    for(int i = 0; i < strlen(t); i++) {// 插入字符串
        s[pos + i] = t[i];
    }
}


void format(string &s, string &s1, string &s2, int n) {
    for(auto i = 0; i < n; i++) {
        s1[i] = s[i];
        }
    for(auto i = n; i < s.length(); i++) {
        s2[i - n] = s[i];
    }
}



bool Is_Same(int **a, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != a[j][i]) {
                return false;
            }
        }
    }
    return true;
}


void Sort(vector<int> &v) {
    sort(v.begin(), v.end(), greater<int>());
}