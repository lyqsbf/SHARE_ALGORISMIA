#include <iostream>
#include <string>
#include <queue>
using namespace std;


int main(){
    string c;
    queue<string> cua;
    while (cin >> c){
        cua.push(c);
    }
    
    int n = c.size();
    
    vector<queue<string>> llistes(26);
    
    for (int i = n - 1; i >= 0; --i) {
        while(!cua.empty()){
            string par = cua.front();
            cua.pop();
            int on = par[i] - 'a';
            llistes[on].push(par);
        }
        
        for (int j = 0; j < 26; ++j){
            while (!llistes[j].empty()){
                string nou = llistes[j].front();
                llistes[j].pop();
                cua.push(nou);
            }
        }
    }

    while(!cua.empty()){
        cout << cua.front();
        cua.pop();
        if (!cua.empty()) {
            cout << " "; 
        }
    }
    cout << endl;
}
