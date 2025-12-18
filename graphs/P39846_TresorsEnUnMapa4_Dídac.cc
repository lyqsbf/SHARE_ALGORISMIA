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
const VI dx = {0,1,0,-1}, dy = {1,0,-1,0};

bool ok(int a, int b){
    return (a >= 0) and (a < n) and (b >= 0) and (b < m) and (map[a][b] != 'X');
}

int bfs(int i, int j){
    VVI dist(n, VI(m, -1));
    dist[i][j] = 0;
    queue<pair<int, int>> Q;
    Q.push({i, j});
    int d = -1;

    while(not Q.empty()){
        int x = Q.front().first, y = Q.front().second; Q.pop();
        if(map[x][y] == 't') d = dist[x][y];
        for(int k = 0; k < 4; ++k){
            int a = x + dx[k] , b = y + dy[k];
            if(ok(a, b) and dist[a][b] == -1){
                Q.push({a, b});
                dist[a][b] = dist[x][y] + 1;
            }
        }
    }
    return d;
}

int main(){
    while(cin >> n >> m){
        map = VVC(n, VC(m));
        for(int i = 0; i < n; ++i)
            for(char& j : map[i]) cin >> j;
        int i , j;
        cin >> i >> j;

        int d = bfs(i-1, j-1);
        if(d != -1) cout << "distancia maxima: " << d << endl;
        else cout << "no es pot arribar a cap tresor" << endl;
    }
}
