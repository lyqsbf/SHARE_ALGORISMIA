// Rol classificatori
// https://jutge.org/problems/P60296_ca
// P60296_ca:std:none:G++17
// Created on 12/24/2025, 6:06:54 PM by YaQi Liu

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

set <string> jugadors;
set <string> jugadors_actius;
map <string, int> ranking;
int main() {
    string action;
    string player1;
    string player2;
    while(cin >> action){
        if(action == "LOGIN"){
            cin >> player1;
            jugadors_actius.insert(player1);
            if(jugadors.find(player1) == jugadors.end()){
                jugadors.insert(player1);
                ranking.insert({player1, 1200});
            }
        }
        else if(action == "PLAY"){
            cin >> player1 >> player2;
            if(jugadors_actius.find(player1) == jugadors_actius.end() or
                jugadors_actius.find(player2) == jugadors_actius.end())
                cout << "jugador(s) no connectat(s)" << endl;
            else{
                ranking[player1] += 10;
                ranking[player2] = max(1200, ranking[player2]-10);
            }
        }
        else if(action == "GET_ELO"){
            cin >> player1;
            cout << player1 << " " << ranking[player1] << endl;
        }
        else if(action == "LOGOUT"){
            cin >> player1;
            if(jugadors_actius.find(player1) != jugadors_actius.end()) jugadors_actius.erase(player1);
        }
    }
    cout << "\nRANKING\n";
    vector<pair<string, int>> vec(ranking.begin(), ranking.end());
    sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) {            
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    for (const auto& p : vec) {        
        cout << p.first << " " << p.second << endl;
    }
}
