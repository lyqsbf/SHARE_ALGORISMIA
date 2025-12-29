// Minimizing the cost of a graph
// https://jutge.org/problems/P36054_en
// P36054_en:std:none:G++17
// Created on 12/28/2025, 8:43:56 PM by YaQi Liu

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u, v, w;
};

using VE = vector<Edge>;
using VI = vector<int>;
using ll = long long;

//Distjoint Set Union (DSU) structure
struct DSU{
    VI pares;
    DSU(int n){
        pares.resize(n);
        for(int i = 0; i < n; i++) pares[i] = i;
    }
    int find(int i){
        if (pares[i] == i) return i;
        return pares[i] = find(pares[i]);
    }
    //returns true if they were different sets
    bool unite(int i, int j){
        int root_i = find(i);
        int root_j = find(j);
        if(root_i != root_j){
            pares[root_i] = root_j;
            return true;
        }
        return false;
    }
};

bool compareEdge(const Edge&a, const Edge&b){
    return a.w < b.w;
}

int main() {
    int N, n;
    while(cin >> N >> n){
        VE negative;
        VE zero;
        VE positive;

        for(int i = 0; i < n; i++){
            int x, y, c;
            cin >> x >> y >> c;
            if (c < 0) negative.push_back({x, y, c});
            else if (c == 0) zero.push_back({x, y, c});
            else positive.push_back({x, y, c});
        }

        sort(positive.begin(), positive.end(), compareEdge);

        ll cost = 0;
        int m = 0;
        int M = 0;

        DSU dsu(N);
        for(const auto& edge : negative){
            cost += edge.w;
            m++;
            M++;
            dsu.unite(edge.u, edge.v);
        }
        M += (int)zero.size();
        for(const auto& edge : zero){
            if(dsu.unite(edge.u, edge.v)) m++;
        }
        for(const auto& edge : positive){
            if(dsu.unite(edge.u, edge.v)){
                cost += edge.w;
                m++;
                M++;
            }
        }

        cout << cost << " " << m << " " << M << endl;
    }
}
