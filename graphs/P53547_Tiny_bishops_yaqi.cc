// Tiny bishops
// https://jutge.org/problems/P53547_en
// P53547_en:std:none:G++17
// Created on 12/29/2025, 10:39:41 PM by YaQi Liu

#include <iostream>
#include <vector>
#include <string>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
VVI T;
VVI vist;

const VI dx = {1, 1, -1, -1};
const VI dy = {1, -1, 1, -1};

int n, m;

void dfs(int r, int c, int& suma, int& count){
    vist[r][c] = 1;
    suma += T[r][c];
    count++;

    for(int i = 0; i < 4; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m){
            if(T[nr][nc] != -1 && !vist[nr][nc]){
                dfs(nr, nc, suma, count);
            }
        }
    }
}

void solve(int k){
    bool possible = true;
    int average = -1;
    vist = VVI(n, VI(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(T[i][j] != -1 && !vist[i][j]){
                int suma = 0;
                int count = 0;
                dfs(i, j, suma, count);

                if(suma % count != 0) possible = false;
                else{
                    int av = suma/count;
                    if(average == -1) average = av;
                    else if (average != av) possible = false;
                }
            }
        }
    }
    cout << "Case " << k+1 << ": " << (possible? "yes\n" : "no\n");
}

int main() {
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> n >> m;
        T = VVI(n, VI(m, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                string s;
                cin >> s;
                if(s == "X") T[i][j] = -1;
                else T[i][j] = stoi(s);
            }
        }
        solve(k);
    }
}
