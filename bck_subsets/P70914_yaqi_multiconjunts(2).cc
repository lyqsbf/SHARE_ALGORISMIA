#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
VI V;
int n;
int x;
int y;

void write(){
	cout << "{";
	int k = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < V[i]; j++){
			cout << (k ? "," : "") << i + 1;
			k++;
		}
	}
	cout << "}" << endl;
}

void f(int i){
	if(i == n) return write();
	
	for(int j = x; j <= y; j++){
		V[i] = j;
		f(i + 1);
	}
}

int main(){
	cin >> n >> x >> y;
	V = VI(n);
	f(0);
}
