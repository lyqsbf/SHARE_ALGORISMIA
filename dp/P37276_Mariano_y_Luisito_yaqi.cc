// Mariano y Luisito
// https://jutge.org/problems/P37276_es
// P37276_es:std:none:G++17
// Created on 1/2/2026, 7:00:09 PM by YaQi Liu

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VC = vector<char>;
using VI = vector<int>;
using VVC = vector<VC>;
using VVI = vector<VI>;
VVC T;
VVI DP;
VVI C;
const int INF = 1e9;

int A, L;

int solve(int i, int j){
    if(i >= L || i < 0 || j >= A || j < 0) return INF;
    if(DP[i][j] != -1) return DP[i][j];

    if(i == 0){
        if(T[i][j] == 'M') return DP[i][j] = 0;
        else return DP[i][j] = INF;
    }
    return DP[i][j] = C[i][j] + min({solve(i-1, j), solve(i-1, j-1) + 1, solve(i-1, j+1) + 1});
}

int main() {
    cin >> A >> L;
    T = VVC(L, VC(A));
    DP = VVI(L, VI(A, -1));
    C = VVI(L, VI(A, 0));
    for(int i = 0; i < L; i++){
        for(int j = 0; j < A; j++){
            cin >> T[i][j];
            if(T[i][j] == 'T') C[i][j] = 3;
            else if(T[i][j] == '*') DP[i][j] = C[i][j] = INF;
        }
    }
    int res = INF;

    for(int k = 0; k < A; k++){
        res = min(res, solve(L-1, k));
    }
    if(res == INF) cout << "IMPOSIBLE\n";
    else cout << res << endl;
}
