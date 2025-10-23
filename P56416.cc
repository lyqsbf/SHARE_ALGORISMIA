//Parcial 2012 Hamiltonian paths
#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;

using ll = long long;

VVI costs;
VI sol;
VB vist;
int n;
const ll INF = 15*1e6;
ll min_cost = INF;

void write(){
	for(int i = 0; i < n; i++)
		cout << (i ? " ": "") << sol[i] + 1;
	cout << endl;
}

void f(int i, ll act_cost){
	if((int)sol.size() == n){
		write();
		if (act_cost < min_cost) min_cost = act_cost;
		return;
	}
	for (int x = 0; x < n; x++){
		if(costs[i][x] and not vist[x]){
			vist[x] = true;
			sol.push_back(x);
			f(x, act_cost + costs[i][x]);
			sol.pop_back();
			vist[x] = false;
		}
	}
}

int main(){
	cin >> n;
	costs = VVI(n, VI(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> costs[i][j];
		}
	}
	vist = VB(n, false);
	vist[0] = true;
	sol.push_back(0);

	f(0, 0);
	cout << "min: " << min_cost << endl;
}
