#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;

int n, m;
VVI dist;
VVC tauler;
queue<pair<int, int>> Q;
const VI dx = {0,1,0,-1}, dy = {1,0,-1,0};

bool ok(int x, int y){
    return (x >= 0) and (x < n) and (y >= 0) and (y < m) and tauler[x][y] != 'X';
}

void joc(){
    while(not Q.empty()){
        int x = Q.front().first, y = Q.front().second; Q.pop();
        for(int k = 0; k < 4; ++k){
            int a = x + dx[k], b = y + dy[k];
            if(ok(a, b) and dist[a][b] == -1){
                dist[a][b] = dist[x][y] + 1;
                Q.push({a, b});
            }
        }
    }
    return;
}

int main(){
    while(cin >> n >> m){
        tauler = VVC(n, VC(m));
        dist = VVI(n, VI(m, -1));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                char c;
                cin >> c;
                if(c == 'T'){
                    Q.push({i,j});
                    dist[i][j] = 0;
                }
                if(c == 'X') dist[i][j] = -2;
                tauler[i][j] = c;
                
            }
       
        joc();
        for(int i = 0; i < n; ++i){
            bool primer = true;
            for(int& j : dist[i]){
                if(primer) primer = false;
                else cout << ' ';
                cout << j;
            }
            cout << endl;
        }
        cout << string(10, '-') << endl;
    }
}
