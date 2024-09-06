#include <iostream>

using namespace std;

string removeBackspaces(string& s){
    int n = s.size();
    int idx = 0;

    for (int i = 0; i < n; i++){
        if (s[i] != '#'){
            s[idx] = s[i];
            idx++;
        }
        else if(s[i] == '#' && idx > 0){
            idx--;
        }

        if (idx < 0){
            idx = 0;
        }
    }

    return s.substr(0, idx);



}

int main(){
    string s, t;

    cin >> s >> t;

    if (removeBackspaces(s) == removeBackspaces(t))
        cout << "Yes";
    else
        cout << "No";
    
    return 0;
}