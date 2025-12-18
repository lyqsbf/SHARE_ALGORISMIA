#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

VVI G;


bool bfs(int n, int i, VI& colors){
    queue<int> cua;
    cua.push(i);
    colors[i] = 0;
    
    while(!cua.empty()){
        int x = cua.front(); cua.pop();
        for(int y : G[x])
            if(colors[y] == -1){
                cua.push(y);
                if(colors[x]) colors[y] = false;
                else colors[y] = true;
            }else if(colors[y] == colors[x]) return true;
    }
    return false;
}

bool connexes(int n){
    VI colors(n, -1);
    for(int i = 0; i < n; ++i)
        if(colors[i] == -1 and bfs(n, i, colors)) return false;
    return true;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        G = VVI(n);
        //vist = VI(n, false);
        while(m--){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
            //vist[a] = vist[b] = true;
        }
        if(connexes(n)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
