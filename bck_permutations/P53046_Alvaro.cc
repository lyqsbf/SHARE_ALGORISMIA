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

void s(vector<int>& num, int i, int j){
  int temp = num[i];
  num[i] = num[j];
  num[j] = temp;
}

void f(int i, int act, const int& n, vector<int>& num, vector<bool>& triat){
    if(i == n - 1) return print(n, num);
    
    for(int j = 0; j < n; ++j){
      if(not triat[j] and j != act){
        triat[j] = true;
        s(num, act, j);
        f(i + 1, j, n, num, triat);
        triat[j] = false;
        s(num, act, j);
      }
    }
}

int main(){
	int n;
	cin >> n;
	vector<int> num(n);
    for(int i = 0; i < n; ++i) num[i] = i;
	vector<bool> triat(n, false);
    triat[0] = true;
	f(0, 0, n, num, triat);
}
