#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    int scores[3];
    int total;
};

int main() {
    int n;
    cin >> n;
    
    vector<Student> students(n);
    
    for (int i = 0; i < n; ++i) {
        students[i].id = i + 1;
        students[i].total = 0;
        for (int j = 0; j < 3; ++j) {
            cin >> students[i].scores[j];
            students[i].total += students[i].scores[j];
        }
    }
    
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.total != b.total) 
            return a.total > b.total;
        return a.scores[0] > b.scores[0];
    });
    
    int top = min(5, n);
    for (int i = 0; i < top; ++i) {
        cout << students[i].id << " " << students[i].total << endl;
    }
    
    return 0;
}