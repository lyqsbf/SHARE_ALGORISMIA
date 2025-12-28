// Minimum spanning trees
// https://jutge.org/problems/P12887_en
// P12887_en:std:none:G++17
// Created on 12/28/2025, 3:46:47 PM by YaQi Liu

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Aresta{
    int x, y, c;
};

using VA = vector<Aresta>;
using VI = vector<int>;

int n, m;
VA V;
VI pare;

//si no te representant retorna x, si en te retorna el representant
int repre(int x){
    return (pare[x] == -1 ? x : pare[x] = repre(pare[x]));
}

//criteri d'ordre
bool ordre(Aresta a, Aresta b){
    return a.c < b.c; //en cas d'empat volem que retorni false
}

void kruskal(){
    sort(V.begin(), V.end(), ordre);
    int q = n;
    int cost = 0;
    pare = VI(n, -1);
    for(auto[x, y, c] : V){
        int rx = repre(x-1); //restem 1 perque els indexos estiguin de 0 a n-1
        int ry = repre(y-1);
        if(rx != ry){
            pare[ry] = rx;
            cost += c;
            if(--q == 1) break;
        }
    }
    cout << cost << endl;
}

int main() {
    while(cin >> n >> m){
        V = VA(m);
        for(auto&[x, y, c] : V) cin >> x >> y >> c;
        kruskal();
    }
}
