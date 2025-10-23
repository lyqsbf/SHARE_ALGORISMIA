#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print(const int& n, const vector<int>& num, const vector<string>& words){
    cout << '(';
    bool primer = true;
    for(int i = 0; i < n; ++i){
        if(primer){
            cout << words[num[i]];
            primer = false;
        }
        else cout << ',' << words[num[i]];
    }
    cout << ')' << endl;
}

void f(int i,const int& n, vector<int>& num, vector<bool>& triat, const vector<string>& words){
	if(i == n) return print(n, num, words);
	
	for(int j = 0; j < n; ++j ){
		if(not triat[j]){
            triat[j] = true;
            num[i] = j;
            f(i + 1, n, num, triat, words);
            triat[j] = false;
        }
	}
}

int main(){
	int n;
	cin >> n;
    vector<string> words(n);
    for(string& s : words) cin >> s;
	vector<int> num(n);
    vector<bool> triat(n, false);
	f(0, n, num, triat, words);
}
