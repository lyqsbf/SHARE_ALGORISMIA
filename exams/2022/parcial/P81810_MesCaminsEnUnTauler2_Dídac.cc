#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using VC = vector<char>;
using VVC = vector<VC>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;

ll const MOD = 1e9 + 7;
VVC M;
VVVL A;

ll f(int i, int j, int k){ // #camins des de (i, j) passant per k obstacles
    if(i < 0 or j < 0 or k < 0) return 0;
    ll& res = A[i][j][k];
    if(res != -1) return res;
    k -= (M[i][j] == 'X');
    if(i+j == 0) return res = (k == 0);
    return res = (f(i-1, j, k) + f(i, j-1, k)) % MOD;
}

int main(){
    int n, m, k;
    while(cin >> n >> m >> k){
        M = VVC(n, VC(m));
        for(int i = 0; i < n; ++i) for(char& c : M[i]) cin >> c;
        A = VVVL(n, VVL(m, VL(k+1, -1)));
        cout << f(n-1, m-1, k) << endl;
    }
}
