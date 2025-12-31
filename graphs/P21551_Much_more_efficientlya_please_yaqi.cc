// Much more efficiently, please!
// https://jutge.org/problems/P21551_en
// P21551_en:std:none:G++17
// Created on 1/1/2026, 12:23:29 AM by YaQi Liu

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
VVI G;
VI color;

int n;

void solve(){
    queue<int> Q;
    Q.push(0);
    color[0] = 1;

    bool bipartit = true;
    int visited_count = 0;

    while(!Q.empty()){
        int x = Q.front(); Q.pop();
        visited_count++;
        for(int&y : G[x]){
            if(color[y] == 0){
                color[y] = 3 - color[x];
                Q.push(y);
            }
            else if (color[x] == color[y]) bipartit = false;
        }
    }
    if(visited_count < n) cout << "NC\n";
    else cout << (bipartit? "yes\n" : "no\n");
}

int main() {
    int m;
    while(cin >> n >> m){
        G = VVI(n);
        color = VI(n);
        for(int i = 0; i < m; i++){
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        solve();
    }
}
