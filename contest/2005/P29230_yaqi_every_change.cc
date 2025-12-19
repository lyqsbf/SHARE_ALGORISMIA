//tots els canvis
#include <iostream>
#include <vector>
using namespace std;

using VI = vector <int>;
VI V;
VI monedes = {50, 20, 10, 5, 2, 1};
int n;

void escriu(){
	for (int i = 0; i < V.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << V[i];
	}
    cout << endl;
}


void f(int num, int imax) {
    if(num < 0) return;
    if(num == 0) return escriu();
    for (int i = imax; i < 6; ++i) {
        V.push_back(monedes[i]);
        f(num - monedes[i], i);
        V.pop_back();
    }
}

int main (){
	while (cin >> n){
		f(n, 0);
		cout << endl;
	}
}
