// Omplint la bossa
// https://jutge.org/problems/P98123_ca
// P98123_ca:std:none:G++17
// Created on 12/23/2025, 8:48:26 PM by YaQi Liu

#include <iostream>
#include <set>
#include <string>
using namespace std;

using ll = long long;

set<ll> bossa;
set<ll> resta;
ll suma_bossa = 0;

void f(int n){
    while((int)bossa.size() > n){
        ll minim = *bossa.begin();
        suma_bossa -= minim;
        resta.insert(minim);
        bossa.erase(minim);
    }
    while((int)bossa.size() < n && !resta.empty()){
        auto it = prev(resta.end());
        ll value = *it;
        suma_bossa += value;
        bossa.insert(value);
        resta.erase(value);
    }
    if(!bossa.empty() && !resta.empty()){
        ll minim_bossa = *bossa.begin();
        auto it_maxim_reserva = prev(resta.end());
        ll maxim_reserva = *it_maxim_reserva;

        if (maxim_reserva > minim_bossa) {
            suma_bossa -= minim_bossa;
            suma_bossa += maxim_reserva;
            
            bossa.erase(bossa.begin());
            resta.erase(it_maxim_reserva);
            
            bossa.insert(maxim_reserva);
            resta.insert(minim_bossa);
        }
    }
}

int main() {
    int n;
    cin >> n; 
    string action;
    ll value;

    while (cin >> action >> value){
        if(action == "deixar"){
            bossa.insert(value);
            suma_bossa += value;
        }
        else if(action == "endur"){
            auto it = bossa.find(value);
            if(it != bossa.end()){
                suma_bossa -= value;
                bossa.erase(value);
            }
            else{
                resta.erase(value);
            }
        }
        f(n);
        cout << suma_bossa << "\n";
    }
}
