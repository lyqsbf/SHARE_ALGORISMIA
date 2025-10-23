//Paraules antipalindromiques
#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
VI v;

int n, x;

void f(int i){
	if(i == n){
		for(int k = 0; k < n; ++k) cout << char('a'+v[k]);
		cout << endl;
		return;	
	}
	for(int j = 0; j < x; ++j) {
        	if(i == 0 or (i == 1 and j != v[0]) or (i > 1 and j != v[i-1] and j != v[i-2])){
            		v[i] = j;
            		f(i+1);
        	}
    	}
}


int main(){
	cin >> n >> x;
	v = VI(n);
	f(0);
}
