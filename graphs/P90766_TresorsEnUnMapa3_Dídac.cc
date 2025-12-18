#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;

int n, m;
VVC map;

bool ok(int a, int b){
    return (a >= 0) and (a < n) and (b >= 0) and (b < m) and (map[a][b] != 'X');
}

int dfs(int i, int j){
    if(not ok(i, j)) return 0;
    int cont = 0;
    if(map[i][j] == 't') ++cont;
    map[i][j] = 'X';
    return cont + dfs(i-1, j) + dfs(i, j-1) + dfs(i+1, j) + dfs(i, j+1);
}

int main(){
    while(cin >> n >> m){
        map = VVC(n, VC(m));
        for(int i = 0; i < n; ++i)
            for(char& j : map[i]) cin >> j;
        int i, j;
        cin >> i >> j;

        cout << dfs(i-1, j-1) << endl;
    }
}
