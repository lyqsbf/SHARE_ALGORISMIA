#include <iostream>
#include <vector>
using namespace std;


using VI = vector<long long>;
using VVI = vector<VI>;
VVI memo = VVI(16, VI(16, -1));;
int n, v;


int f(int i, int voc, bool ant){
    for (int j = 0; j < 16; ++j){
        for (int k = 0; k < 16; ++k){
            cout << ' ' << memo[j][k];
        }
        cout << endl;
    }
    cout << endl;
	if (voc < 0) return 0;
	if (i == 0) return (voc == 0) ? 1 : 0;
	if (i%2 == 0 and i/2 > voc) return 0;
    if (i%2 == 1 and i/2 > voc) return 0;
	
	if (memo[i][voc] != -1) return memo[i][voc];
	
	long long result = 0;
	
	if (voc > 0) result += 5*f(i - 1, voc - 1, false);
	
	if (!ant) result += 21*f(i - 1, voc, true);
    
    memo[i][voc] = result;
    return result;
}


int main(){
    while (cin >> n >> v){
		cout << f(n, v, false) << endl;
	}
}
