#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;

int posicio(string&s, VS& WORD){
    int n = WORD.size();
    for(int i = 0; i <n; ++i){
        if(s == WORD[i]) return i;
    }
    return -1;
}

int main(){
    int n;
    while(cin >> n){
        VS WORD(n);
        for(string&s : WORD) cin >> s;
        
        sort(WORD.begin(), WORD.end());
        
        int m;
        cin >> m;
        
        VVI G(n);
        VI grau(n, 0);
        for(int i = 0; i < m; ++i){
            string x, y;
            cin >> x >> y;
            int a = posicio(x, WORD);
            int b = posicio(y, WORD);
            G[a].push_back(b);
            ++grau[b];
        }
        priority_queue<int> cua;
        for(int i = 0; i < n; ++i){
            if(grau[i] == 0) cua.push(-i);
        }
        VS R;
        while(not cua.empty()){
            int k = -cua.top();
            R.push_back(WORD[k]);
            cua.pop();
            for(int a : G[k]){
                if(--grau[a]== 0) cua.push(-a);
            }
        }
        if(int(R.size()) < n) cout << "NO VALID ORDERING";
        else for(string&s : R) cout << s;
        cout << endl;
    }
}
