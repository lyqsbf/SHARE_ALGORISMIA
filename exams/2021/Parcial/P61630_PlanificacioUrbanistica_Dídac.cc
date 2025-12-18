#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;
int n, m;
VVC M;

void escriu(){
	for(int i = 1; i < n+1; ++i){
		for(int j = 1; j < m+1; ++j) cout << M[i][j];
		cout << endl;
	} cout << endl;
}

void f(int i, int j){
	if(i == n+1) return escriu();
	if(j == m+1) return f(i+1, 1);
	if(M[i][j] != '?') return f(i, j+1);
	
	M[i][j] = '.'; 
	f(i, j+1);
	if(M[i-1][j-1] != 'C' and M[i-1][j] != 'C' and M[i-1][j+1] != 'C' and M[i][j-1] != 'C' and M[i][j+1] != 'C' and M[i+1][j-1] != 'C' and M[i+1][j] != 'C' and M[i+1][j+1] != 'C'){
		M[i][j] = 'C'; 
		f(i, j+1);
	}
	
	M[i][j] = '?';
}


int main(){
	while(cin >> n >> m){
		M = VVC(n+2, VC(m+2, '.'));
		for(int i = 1; i < n+1; ++i) for(int j = 1; j < m+1; ++j) cin >> M[i][j];
		f(1, 1);
		cout << string(10, '-') << endl;
	}
}
