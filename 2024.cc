#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
VB usat;
VI dones, sol;
VVI roma;
int n, m, benefici, ant, numsol;


void f(int i) {
    if (i == n) {
        if (ant == benefici) ++numsol;
        if (benefici > ant) {
            numsol = 0;
            sol = dones;
            ant = benefici;
        }
    }
    
    for (int k = 0; k < m; ++k) {
        if (usat[k] == false) {
            dones[i] = k + 1;
            benefici += roma[i][k];
            usat[k] = true;
            f(i + 1);
            benefici -= roma[i][k];
            usat[k] = false;
        }
    }
}


int main() {
    while (cin >> n >> m) {
        benefici = 0;
        numsol = ant = 0;
        roma = VVI(n, VI(m));
        dones = VI(n);
        usat = VB(m, false);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> roma[i][j];
        f(0);
        cout << ant << endl;
    }
}
