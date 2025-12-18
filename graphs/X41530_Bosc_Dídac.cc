#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& G, int ini, vector<bool>& vist){
    queue<int> Q;
    Q.push(ini);
    vist[ini] = true;
    while(not Q.empty()){
        int x = Q.front(); Q.pop();
        for(int y : G[x]){
            if(not vist[y]){
                vist[y] = true;
                Q.push(y);
            }
        }
    }
}

int comp_connex(vector<vector<int>>& G, int n){
    vector<bool> vist(n, false);
    int k = 0;
    for(int i = 0; i < n; ++i){
        //cout << "i: " << i << endl;
        if(not vist[i]){
            
            bfs(G, i, vist);
            ++k;
        }
    }
    return k;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<vector<int>> G(n);
        for(int i = 0; i < m; ++i){
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        int k = comp_connex(G, n);
        if(n - k == m) cout << k << endl;
        else cout << "no" << endl;
    }
}
