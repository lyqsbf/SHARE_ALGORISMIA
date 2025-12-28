// Las Zamburguesas
// https://jutge.org/problems/P88760_ca
// P88760_ca:std:none:G++17
// Created on 12/25/2025, 6:53:34 PM by YaQi Liu

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct Roca{
    double x, y, r;
};

using VR = vector<Roca>;
using VI = vector<int>;

double dist_rocks(Roca a, Roca b){
    double x1 = a.x;
    double x2 = b.x;
    double y1 = a.y;
    double y2 = b.y;
    double d_centre = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return (d_centre - a.r - b.r);
}

//idea: fer un bfs
int main() {
    int n;
    double d_max;
    while(cin >> n >> d_max){
        VR rocks(n);
        for(int i = 0; i < n; i++)
            cin >> rocks[i].x >> rocks[i].y >> rocks[i].r;
        queue<int> Q;
        VI dist(n, -1);
        Q.push(0);
        dist[0] = 0;
        bool posible = false;
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            if(u == n - 1){
                cout << dist[u] << endl;
                posible = true;
                break;
            }
            for(int v = 0; v < n; v++){
                if(dist[v] == -1 && dist_rocks(rocks[u], rocks[v]) <= d_max){
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }
        if(!posible) cout << "Xof!\n";
    }
}
