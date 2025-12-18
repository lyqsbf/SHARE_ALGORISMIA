#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, string> couples;
set<string> alone;


void liats(string a, string b){
    auto it1 = couples.find(a);
    auto it2 = couples.find(b);

    if(alone.find(a) != alone.end()) alone.erase(a);
    if(alone.find(b) != alone.end()) alone.erase(b);
    
    if(it1 == couples.end()){
        if(it2 != couples.end()){
            string x = it2 -> first, y = it2 -> second;
            if(x == b) alone.insert(y);
            else alone.insert(x);
            couples.erase(x);
            couples.erase(y);
        }
    }else{
        if(it2 == couples.end()){
            string x = it1 -> first, y = it1 -> second;
            if(x == a) alone.insert(y);
            else alone.insert(x);
            couples.erase(x);
            couples.erase(y);
        }else{
            string x = it1 -> first, y = it1 -> second;
            if(x == a) alone.insert(y);
            else alone.insert(x);
            couples.erase(x);
            couples.erase(y);
            
            x = it2 -> first, y = it2 -> second;
            if(x == b) alone.insert(y);
            else alone.insert(x);
            couples.erase(x);
            couples.erase(y);
        }
    }
    couples[a] = b;
    couples[b] = a;
}

int main(){
    string act;
    while(cin >> act){
        if(act == "info"){
            cout << "COUPLES:" << endl;
            for(auto p : couples)
                if(p.first < p.second) cout << p.first << ' ' << p.second << endl;
            cout << "ALONE:" << endl;
            for(auto p : alone) cout << p << endl;
            cout << string(10, '-') << endl;
        }else{
            string a, b;
            cin >> a >> b;
            /*if(a > b){
                string aux = a;
                a = b;
                b = aux;
            }*/
            liats(a, b);

        }
    }
}
