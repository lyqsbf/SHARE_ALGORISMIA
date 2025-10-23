#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<bool,bool> bb;
typedef vector<bb> vbb;

void print(const vvc& tauler, const int& f, const int& c){
    for(int i = 0; i < f; ++i){
        for(int j = 0; j < c; ++j){
            cout << tauler[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void rec(int i, const int& f, const int& c, vvc& tauler, vbb& usat){
	if(i == f) return print(tauler, f, c);
	
	for(int j = 0; j < c; ++j ){
        if(not usat[i].first and not usat[j].second){
            tauler[i][j] = 'R';
            usat[i].first = true;
            usat[j].second = true;
            
            rec(i + 1, f, c, tauler, usat);
            
            tauler[i][j] = '.';
            usat[i].first = false;
            usat[j].second = false;
        }
	}
}

int main(){
	int f, c;
    cin >> f >> c;
    vvc tauler(f, vc(c, '.'));
    vbb usat(c, {false, false}); //primer files; segon columnes
    rec(0, f, c, tauler, usat);
}
