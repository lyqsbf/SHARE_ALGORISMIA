// Weighted shortest path (1)
// https://jutge.org/problems/P43859_en
// P43859_en:std:none:G++17
// Created on 12/28/2025, 7:57:07 AM by YaQi Liu

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using P = pair<int, int>;
const int INF = 1e8;
vector<vector<P>> G;
int n;

int dijkstra(int x, int y){
    vector<int> dist(n, INF);
    dist[x] = 0;
    priority_queue <P> Q;
    Q.push({0, x});
    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        int d = -p.first; //-cost
        int u = p.second; //vertex
        if(d == dist[u]){
            if(u == y) return d;
            for(P arc : G[u]){
                int cost = arc.second;
                int v = arc.first;
                int d2 = d + cost;
                if(d2 < dist[v]){
                    dist[v] = d2;
                    Q.push({-d2, v});
                }
            }
        }
    }
    return -1;
}

int main() {
    int m;
    while(cin >> n >> m){
        G = vector<vector<P>>(n);
        for(int i = 0; i < m; i++){
            int u, v, c;
            cin >> u >> v >> c;
            G[u].push_back({v, c});
        }
        int x, y;
        cin >> x >> y;
        int d = dijkstra(x, y);
        if (d != -1) cout << d << endl;
        else cout << "no path from " << x << " to " << y << endl; 
    }
}
