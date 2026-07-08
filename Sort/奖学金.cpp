#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;         // 学号
    int scores[3];  // 语数英三科成绩
    int total;      // 总分
};

int main() {
    int n;
    cin >> n;
    
    vector<Student> students(n);
    
    for (int i = 0; i < n; ++i) {
        students[i].id = i + 1;      // 学号从1开始
        students[i].total = 0;
        for (int j = 0; j < 3; ++j) {
            cin >> students[i].scores[j];
            students[i].total += students[i].scores[j];  // 累加总分
        }
    }
    
    // 按总分降序排序，总分相同则按语文成绩降序
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.total != b.total) 
            return a.total > b.total;
        return a.scores[0] > b.scores[0];
    });
    
    int top = min(5, n);   // 取前5名
    for (int i = 0; i < top; ++i) {
        cout << students[i].id << " " << students[i].total << endl;  // 输出学号和总分
    }
    
    return 0;
}