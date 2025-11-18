#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print(const int& n, const vector<int>& num){
    cout << '(';
    bool primer = true;
    for(int i = 0; i < n; ++i){
        if(primer){
            cout << num[i] + 1;
            primer = false;
        }
        else cout << ',' << num[i] + 1;
    }
    cout << ')' << endl;
}

void f(int i,const int& n, vector<int>& num, vector<bool>& triat){
	if(i == n) return print(n, num);
	
	for(int j = 0; j < n; ++j ){
		if(not triat[j]){
            triat[j] = true;
            num[i] = j;
            f(i + 1, n, num, triat);
            triat[j] = false;
        }
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> num(n);
    vector<bool> triat(n, false);
	f(0, n, num, triat);
}
