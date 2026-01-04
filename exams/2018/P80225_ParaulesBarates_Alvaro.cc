#include <iostream>
#include <vector>


using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;

int n, m, xi, yi, xf, yf, cmax, s;
VC res;
VVI V;
VVC L;
VVB triat;

void print(){
	for(int i = 0; i < n*m and res[i] != '.'; ++i){
		cout << res[i];
	}
	cout << endl;
}

void path(int i, int j, int k){
	if(i < 0 or i >= n or j < 0 or j >= m) return;
	if(triat[i][j]) return;
	
	s += V[i][j];
	if(s > cmax){
		s -= V[i][j];
		return;
	}
	
	res[k] = L[i][j];
	if(i == xf and j == yf){
		s -= V[i][j];
		return print();
	}
	
	triat[i][j] = true;
	path(i + 1, j, k + 1);
	path(i - 1, j, k + 1);
	path(i, j + 1, k + 1);
	path(i, j - 1, k + 1);
	triat[i][j] = false;
	res[k] = '.';
	s -= V[i][j];
}

int main(){
	cin >> n >> m;
	V = VVI(n, VI(m));
	L = VVC(n, VC(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j) cin >> L[i][j];
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j) cin >> V[i][j];
	}
	cin >> xi >> yi >> xf >> yf >> cmax;
	triat = VVB(n, VB(m, false));
	res = VC(n*m, '.');
	s = 0;
	path(xi, yi, 0);
}
