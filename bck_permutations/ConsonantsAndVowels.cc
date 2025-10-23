#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n;

void print(const vector<char>& word){
  for(int i = 0; i < 2*n; ++i) cout << word[i];
  cout << endl;
}

void rec(int i, vector<char>& cons, vector<char>& vowels, vector<char>& word){
	if(i == 2*n) return print(word);
	
  if(i%2 == 0){ //consonant
		for(int j = 0; j < n; ++j){
			if(not (cons[j] == '.')){
				word[i] = cons[j];
				cons[j] = '.';
				rec(i + 1, cons, vowels, word);
				cons[j] = word[i];
			}
		}
  }
  else{ //vocal
		for(int j = 0; j < n; ++j){
			if(not (vowels[j] == '.')){
				word[i] = vowels[j];
				vowels[j] = '.';
				rec(i + 1, cons, vowels, word);
				vowels[j] = word[i];
			}
		}
  }
}

int main(){
    cin >> n;
    vector<char> cons(n);
    vector<char> vowels(n);
    vector<char> word(2*n);
    
    for(int i = 0; i < n; ++i){
      cin >> cons[i];
    }
    for(int i = 0; i < n; ++i){
			cin >> vowels[i];
    }
    rec(0, cons, vowels, word);
}
