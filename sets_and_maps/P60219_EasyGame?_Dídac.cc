#include <iostream>
#include <map>
#include <set>
using namespace std;

struct comparacio{
    bool operator()(string a, string b) const {
        if (a.length() != b.length()) {
            return a.length() < b.length(); // Ordena de curta a llarga
        }
        return a < b; // Si mesuren el mateix, ordena alfabÃ¨ticament
    }
};

void escriu(map<string, int> M, int ronda){
    set<string> has;
    set<string, comparacio> had;
    for(auto x : M){
        if(x.second % 2 == 0) had.insert(x.first);
        else has.insert(x.first);
    }

    cout << "GAME #" << ronda << endl;
    cout << "HAS:" << endl;
    for(auto x : has) cout << x << endl;
    cout << endl;
    cout << "HAD:" << endl;
    for(auto x : had) cout << x << endl;
}

int main(){
    string s;
    int ronda = 0;
    map<string, int> M;
    while(cin >> s){
        if(s == "END" or s == "QUIT"){
            ++ronda;
            escriu(M, ronda);
            M.clear();
            if(s == "QUIT") break;
            else cout << endl;
        }
        else{
            if(M.find(s) == M.end()) M.insert({s, 1});
            else ++M[s];
        }
    }
}
