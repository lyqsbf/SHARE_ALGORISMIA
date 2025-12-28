// Weighted shortest path (2)
// https://jutge.org/problems/P13994_en
// P13994_en:std:none:G++17
// Created on 12/28/2025, 11:19:18 AM by YaQi Liu

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int INF = 1e8;

using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;
VVP G;
VI dist;
VI pares;
int n;

//retorna el cost minim per anar de x a y
int dijkstra(int x, int y){
    dist = VI(n, INF);
    dist[x] = 0;
    pares = VI(n, -1);
    priority_queue<P> Q;
    Q.push({0, x});
    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        int c = -p.first;
        int v = p.second;
        if(c == dist[v]){ //mirem la versio mes nova, c == dist[v] vol dir q es el cami mes curt
            if (v == y) return c;
            for(P arc : G[v]){
                int cost = arc.second;
                int u = arc.first;
                int d2 = c + cost;
                if(d2 < dist[u]){
                    dist[u] = d2;
                    pares[u] = v;
                    Q.push({-d2, u});
                }
            }
        }
    }
    return -1;
}

void minimum_path(int y){
    stack<int> path;
    while(y != -1){
        path.push(y);
        y = pares[y];
    }
    int i = 0;
    while(!path.empty()){
        int a = path.top(); path.pop();
        cout << (i ? " ":"") << a;
        i++;
    }
    cout << endl;
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
        if(dijkstra(x, y) != -1) minimum_path(y);
        else cout << "no path from " << x << " to " << y << endl;
        pares.clear();
    }
}
