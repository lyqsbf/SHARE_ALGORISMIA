#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;
int n, m, f, c, posf, posc;
VC camins;
VVC mapa;
VVB usat;


void escriu(){
    for(int i = 0; i < n*m; ++i){
        if (camins[i] == 0) {
            cout << endl;
            return;
        }
        cout << camins[i];
    }
    cout << endl;
}


void g(int f, int c, int i){
    if (f == posf and c == posc) {
        escriu();
        return;
    }
    
    if (f != n - 1 and usat[f + 1][c] == false) {
        camins[i] = mapa[f + 1][c];
        usat[f + 1][c] = true;
        g(f + 1, c, i + 1);
        camins[i] = 0;
        usat[f + 1][c] = false;
    }
    if (f != 0 and usat[f - 1][c] == false) {
        camins[i] = mapa[f - 1][c];
        usat[f - 1][c] = true;
        g(f - 1, c, i + 1);
        camins[i] = 0;
        usat[f - 1][c] = false;
    }
    if (c != 0 and usat[f][c - 1] == false) {
        camins[i] = mapa[f][c - 1];
        usat[f][c - 1] = true;
        g(f, c - 1, i + 1);
        camins[i] = 0;
        usat[f][c - 1] = false;
    }
    if (c != m - 1 and usat[f][c + 1] == false) {
        camins[i] = mapa[f][c + 1];
        usat[f][c + 1] = true;
        g(f, c + 1, i + 1);
        camins[i] = 0;
        usat[f][c + 1] = false;
    }
    return;
}


int main(){
    cin >> n >> m;
    mapa = VVC(n, VC(m));
    usat = VVB(n, VB(m, false));
    camins = VC(n*m, 0);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            mapa[i][j] = c;
        }
    }
    cin >> f >> c >> posf >> posc;
    usat[f][c] = true;
    camins[0] = mapa[f][c];
    g(f, c, 1);
}
