#include <iostream>
#include <vector>
using namespace std;

using VE = vector <int>; 
using VVE = vector <VE>; 

VVE M;
int n, sumax, sumay;

//maneres de tornar a (0,0) havent passat pel punt (sumax, sumay)
int f (int m, int i, int j, bool visitat) {
	if (i == sumax and j == sumay) visitat = true; 
	if (m == n and visitat and i == 0 and j == 0) return 1;
	if (m == n) return 0;  
	int res = 0; 
	res += f(m + 1, i + M[m][0], j + M[m][1], visitat); 
	res += f(m + 1, i, j + M[m][1], visitat);
	res += f(m + 1, i + M[m][0], j, visitat);
	res += f(m + 1, i, j, visitat);
	return res;
}

int main () {
	while (cin >> sumax >> sumay) { 
		cin >> n; 
		M = VVE (n, VE(2));
		for (int i = 0; i < n; ++i) {
			cin >> M[i][0] >> M[i][1]; 
		}
		cout << f(0, 0, 0, false) << endl; 
    }	
}
