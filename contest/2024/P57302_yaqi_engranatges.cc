#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
VVI G;
VI gir;

bool gira_be(int n){
    queue<int> Q;
    for(int i = 0; i < n; i++){
        if(gir[i] == -1){
            Q.push(i);
            gir[i] = 0;
        }
        while(!Q.empty()){
            int a = Q.front(); Q.pop(); 
            for(int&x : G[a]){
                if(gir[x] != -1){
                    if(gir[x] == gir[a]) return false;
                }
                else{
                    gir[x] = 1 - gir[a];
                    Q.push(x);
                }
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        // -1 no esta determinat
        // 0 gira en sentit horari
        // 1 gira en sentit antihorari
        gir = VI(n, -1);
        G = VVI(n);
        while(m--){
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        cout << (gira_be(n)? "SI":"NO") << endl;
        G.clear();
        gir.clear();
    }
}