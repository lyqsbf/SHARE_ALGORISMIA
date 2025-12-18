#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;

int n, m;
VVC G;

bool dfs(int i, int j){
    if(i < 0 or i >= n or j < 0 or j >= m) return false;
    if(G[i][j] == 't') return true;
    if(G[i][j] == 'X') return false;
    G[i][j] = 'X';
    return dfs(i-1, j) or dfs(i, j-1) or dfs(i, j+1) or dfs(i+1, j);
}

int main(){
    cin >> n >> m;
    G = VVC(n, VC(m));
    for(int i = 0; i < n; ++i)
        for(char& j : G[i]) cin >> j;
    int i, j;
    cin >> i >> j;
    
    cout << (dfs(i-1, j-1) ? "yes" : "no") << endl;
}
