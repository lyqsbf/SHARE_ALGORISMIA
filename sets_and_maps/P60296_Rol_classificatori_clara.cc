#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;


int main(){
    string c;
    string a, b;
    set<string> log;
    map<string, int> puntuacio;
    while (cin >> c){
        if (c == "LOGIN"){
            cin >> a;
            log.insert(a);
            auto it = puntuacio.find(a);
            if (it == puntuacio.end()) puntuacio[a] = 1200;
        }

        else if (c == "LOGOUT"){
            cin >> a;
            log.erase(a);
        }

        else if (c == "PLAY"){
            cin >> a >> b;
            auto it1 = log.find(a);
            auto it2 = log.find(b);
            if (it1 == log.end() or it2 == log.end()) cout << "jugador(s) no connectat(s)" << endl;
            else {
                auto it1 = puntuacio.find(a);
                auto it2 = puntuacio.find(b);
                int x = it1 -> second;
                int y = it2 -> second;
                puntuacio[a] = x + 10;
                if (y < 1210) {
                    puntuacio[b] = 1200;
                }
                else puntuacio[b] = y - 10;
            }
        }
        
        else{
            cin >> a;
            auto it = puntuacio.find(a);
            cout << a << ' ' << it -> second << endl;
        }
    }

    cout << endl;
    cout << "RANKING" << endl;
    set<pair<int, string>> ranking;
    for (auto it : puntuacio) {
        string x = it.first;
        int y = it.second;
        ranking.insert({-y, x});
    }

    for (auto it : ranking){
        cout << it.second << ' ' << -it.first << endl;
    }
}
