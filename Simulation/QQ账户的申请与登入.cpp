#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<string, string> users;

    for(int i = 0; i < n; ++i){
        string state, username, password;
        cin >> state >> username >> password;

        auto it = users.find(username);
        bool exists = (it != users.end());

        if(state == "N"){
            if(!exists){
                users[username] = password;
                cout << "New: OK\n";
            }
            else{
                cout << "ERROR: Exist\n";
            }
        }
        else{ 
            if(!exists){
                cout << "ERROR: Not Exist\n";
            }
            else if(it->second != password){
                cout << "ERROR: Wrong PW\n";
            }
            else{
                cout << "Login: OK\n";
            }
        }
    }
    return 0;
}