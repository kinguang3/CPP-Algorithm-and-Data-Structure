#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    
    long long squares = 0;
    long long min_dim = min(n, m);
    for(long long k = 1; k <= min_dim; k++) {
        squares += (n - k + 1) * (m - k + 1);
    }
    
    long long total_rectangles = (n * (n + 1) / 2) * (m * (m + 1) / 2);
    
    long long rectangles = total_rectangles - squares;
    
    cout << squares << " " << rectangles;
    return 0;
}