// Xafardeig
// https://jutge.org/problems/P47386_ca
// P47386_ca:std:none:G++17
// Created on 12/24/2025, 7:50:59 PM by YaQi Liu

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

set <string> people;
map <string, string> parelles;

int main() {
    string action;
    while(cin >> action){
        if(action == "info"){
            cout << "PARELLES:\n";
            auto it = parelles.begin();
            while (it != parelles.end()){
                if(it -> first < it ->second) cout << it ->first << " " << it -> second << endl;
                it++;
            }
            cout << "SOLS:\n";
            auto name = people.begin();
            while(name != people.end()){
                if(parelles.find(*name) == parelles.end())cout << *name << endl;
                name++;
            }
            cout << string(10, '-') << endl;
        }
        else if (action == "liats"){
            string x, y;
            cin >> x >> y;
            if(parelles.count(x)){
                string ex = parelles[x];
                parelles.erase(ex);
                parelles.erase(x);
            }
            if(parelles.count(y)){
                string ex = parelles[y];
                parelles.erase(ex);
                parelles.erase(y);
            }
            people.insert(x);
            people.insert(y);
            parelles[x] = y;
            parelles[y] = x;
        }
    }
}


