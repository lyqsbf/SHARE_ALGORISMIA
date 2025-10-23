#include <iostream>
#include <vector>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;


int n, res;
VB usat;
VVI G;


void cic(int x, int y, int pas){
    if (pas != 0 and x == y){
        if (pas > 2) res++;
        return;
    }
    for (int z : G[y]){
        if (z >= x  and not usat[z]){
            usat[z] = true;
            cic(x, z, pas + 1);
            usat[z] = false;
        }
    }
    return;
}


int main(){
    int m;
    while (cin >> n >> m){
        G =  VVI(n);
        while (m--){
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        res = 0;
        for (int i = 0; i < n; i++){
            usat = VB(n, false);
            cic(i, i, 0);
        }
        cout << res/2 << endl;
    }
}
