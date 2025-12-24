// Mediana dinàmica
// https://jutge.org/problems/P37064_ca
// P37064_ca:std:none:G++17
// Created on 12/24/2025, 5:35:46 PM by YaQi Liu

#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    string word;
    map<string, int> mapa;
    auto it_med = mapa.end();
    while(cin >> word && word != "END"){
        int n = (int)mapa.size();
        mapa.insert({word, 1});
        if(n == 0) it_med = mapa.begin();
        else if(n%2 != 0){
            if (word < it_med->first) --it_med;
        }
        else{
            if (word > it_med->first) ++it_med;
        } 
        cout << it_med->first << "\n";
    }
}
