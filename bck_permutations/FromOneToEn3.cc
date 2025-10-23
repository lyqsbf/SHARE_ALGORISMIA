#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int n, k;
VB triat;
VI num;

void print(){
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


void f(int i, int inv){
    if(k < inv or k > inv + (n - i)*(n - i - 1)/2) return;
    if(i == n) return print();
    
    int c = 0;
    for(int j = 0; j < n; ++j){
      if(not triat[j]){
        triat[j] = true;
        num[i] = j;
        f(i + 1, inv + c);
        triat[j] = false;
        ++c;
      }
    }

}

int main(){
	cin >> n >> k;
	num = VI(n);
  triat = VB(n, false);
	f(0, 0);
}
