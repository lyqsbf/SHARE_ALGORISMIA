#include <iostream>
#include <vector>
#include <string>
using namespace std;

using VS = vector<string>;
using VB = vector<bool>;
int n;
VS V;
VB usat;

void escriu(){
    int x = 0;
    cout << "{";
    for(int i = 0; i < n; i++){
        if(usat[i]){
            cout << (x ? "," : "") << V[i];
            x++;
        }
    }
    cout << "}" << endl;
}

void comb(int i){
    if (i == n) return escriu();
    usat[i] = false;
    comb(i + 1);
    usat[i] = true;
    comb(i + 1);
}

int main(){
    string s;
    cin >> n;
    V = VS(n);
    usat = VB(n);
    for(int i = 0; i < n; i++){
        cin >> s;
        V[i] = s;
    }
    comb(0);
}
