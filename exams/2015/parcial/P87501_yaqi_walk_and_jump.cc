//walk and jump P87501
#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;
VVI R;
VVC T;
const int MOD = 1e8+7;
int n, m;

//maneres d'arribar a (n-1, m-1) desde la posicio (i, j)
int f(int i, int j){
    if(i >= n or j >= m) return 0;
    else if(T[i][j] == 'X') return R[i][j] = 0;
    else if(i == n - 1 and j == m - 1) return 1;
    else if(R[i][j] != -1) return R[i][j];
    else{
        long long ways = 0;
        ways = (ways + f(i+1, j) + f(i, j+1))%MOD;
        if(i+1 < n and T[i+1][j] == 'X') ways = (ways + f(i+2, j))%MOD;
        if(j+1 < m and T[i][j+1] == 'X') ways = (ways + f(i, j+2))%MOD;
        R[i][j] = (int)ways;
    }
    return R[i][j];
}

int main(){
    while(cin >> n >> m){
        T = VVC(n, VC(m));
        R = VVI(n, VI(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cin >> T[i][j];
        }
        cout << f(0, 0) << endl;
    }
}
