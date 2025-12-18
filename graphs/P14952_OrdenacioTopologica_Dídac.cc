#include <vector>
#include <iostream>
#include <queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

VI grau;
VVI G;

void bfs(int n){
    priority_queue<int> P;
    for(int i = 0; i < n; ++i) 
        if(grau[i] == 0) P.push(-i);
    
    bool primer = true;
    while(not P.empty()){
        if(primer) primer = false;
        else cout << ' ';
        int x = -P.top(); P.pop();
        cout << x;
        for(int y : G[x])
            if(--grau[y] == 0) P.push(-y);
        
    }
    cout << endl;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        G = VVI(n);
        grau = VI(n, 0);
        while(m--){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            ++grau[b];
        }
        bfs(n);
    }
}
