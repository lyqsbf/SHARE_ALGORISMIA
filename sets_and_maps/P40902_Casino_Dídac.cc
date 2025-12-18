#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> persones;

    string nom, act;
    while(cin >> nom >> act){
        auto it = persones.find(nom);
        if(act == "enters"){
            if(it == persones.end()) persones[nom];
            else cout << nom << " is already in the casino" << endl;
        }else if(act == "wins"){
            int x;
            cin >> x;
            if(it != persones.end()) it -> second += x;
            else cout << nom << " is not in the casino" << endl;
        }else if(act == "leaves"){
            if(it != persones.end()){
                cout << nom << " has won " << it -> second << endl;
                persones.erase(nom);
            }else cout << nom << " is not in the casino" << endl;
        }
    }

    cout << string(10, '-') << endl;
    for(auto p : persones) cout << p.first << " is winning " << p.second << endl;
}
