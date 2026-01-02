// Escape del laberinto
// https://jutge.org/problems/P88921_es
// P88921_es:std:none:G++17
// Created on 1/2/2026, 4:45:00 PM by YaQi Liu

#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VI = vector<int>;
using VVC= vector<VC>;
using VVI = vector<VI>;
VVC T;
VVI DP;

const int LIMIT = 1e6;

int solve(int x, int y){
    if(x < 0 || y < 0) return 0;
    if(DP[x][y] != -1) return DP[x][y];
    if(x == 0 && y == 0) return DP[x][y] = 1;
    int paths = solve(x-1, y) + solve(x, y-1);
    if(paths > LIMIT) paths = LIMIT;
    return DP[x][y] = paths;
}

int main() {
    int n, m;
    while(cin >> n>> m && !(n == 0 && m == 0)){
        T = VVC(n, VC(m));
        DP = VVI(n, VI(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> T[i][j];
                if(T[i][j] == 'X') DP[i][j] = 0;
            }
        }
        int res = solve(n-1, m-1);
        if(res >= LIMIT) cout << "!!!\n";
        else cout << res << endl;
    }
}
