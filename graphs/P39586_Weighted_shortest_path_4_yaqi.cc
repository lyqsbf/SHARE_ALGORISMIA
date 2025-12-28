// Weighted shortest path (4)
// https://jutge.org/problems/P39586_en
// P39586_en:std:none:G++17
// Created on 12/28/2025, 1:31:01 PM by YaQi Liu

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;
VI ways;
VI dist;
VVP G;
int n;

int dijkstra(int x, int y){
    dist = VI(n, 1e9);
    dist[x] = 0;
    ways = VI(n, 0);
    ways[x] = 1;
    priority_queue<P> Q;
    Q.push({0, x});
    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        int d = -p.first;
        int u = p.second;
        if(d == dist[u]){
            if (u == y) return d;
            for(P arc : G[u]){
                int cost = arc.second;
                int v = arc.first;
                int d2 = d+cost;
                if(d2 < dist[v]){
                    dist[v] = d2;
                    ways[v] = ways[u];
                    Q.push({-d2, v});
                }
                else if(d2 == dist[v]){
                    ways[v] += ways[u];
                }
             }
        }
    }
    return -1;
}

int main() {
    int m;
    while(cin >> n >> m){
        G = VVP(n);
        for(int i = 0; i < m; i++){
            int u, v, c;
            cin >> u >> v >> c;
            G[u].push_back({v, c});
        }
        int x, y;
        cin >> x >> y;
        int d = dijkstra(x, y);
        if(d != -1) cout << "cost " << d << ", " << ways[y] << " way(s)\n";
        else cout << "no path from " << x << " to " << y << endl;
    }
}
