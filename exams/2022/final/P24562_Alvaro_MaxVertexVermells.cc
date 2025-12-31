#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

int n, m;
VI pintat;
VVI G;

int primerNoPintat(){
	for(int i = 0; i < n; ++i){
		if(pintat[i] == 0) return i;
	}
	return -1;
}

int bfs(){
	queue<int> q;
	int vermell = 0;
	
	int p = 0;
	while(p != -1){
		q.push(p);
		pintat[p] = 1;
		int a, b;
		b = 0;
		a = 1;
		while(not q.empty()){
			int x = q.front(); q.pop();
			for(int y : G[x]){
				if(pintat[y] == 0){
					q.push(y);
					pintat[y] = -pintat[x];
					if(pintat[y] == 1) ++a;
					else ++b;
				}
				else if(pintat[y] == pintat[x]) return -1;
			}
		}
		vermell += max(a, b);
		p = primerNoPintat();
	}
	return vermell;
}

int main(){
	while(cin >> n >> m){
		G = VVI(n);
		pintat = VI(n, 0);
		for(int i = 0; i < m; ++i){
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		int vermell = bfs();
		if(vermell == -1) cout << "no" << endl;
		else cout << "yes" << ' ' << vermell << endl;
	}
}
