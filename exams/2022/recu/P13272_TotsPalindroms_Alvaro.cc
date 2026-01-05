#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> VC;

const VC lletra = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int k, n, nn;
string s;

void pal(int i){
	if(i > nn){
		cout << s << endl;
		return;
	}
	
	if(i == nn and n%2 == 0){
		if(s[i] == '.'){
			for(int j = 0; j < k; ++j){
				s[i] = lletra[j];
				pal(i + 1);
				s[i] = '.';
			}
			return;
		}
	}
	else{
		if(s[i] == '.' and s[n - i] == '.'){
			for(int j = 0; j < k; ++j){
				s[i] = s[n - i] = lletra[j];
				pal(i + 1);
				s[i] = s[n - i] = '.';
			}
			return;
		}
		if(s[i] == '.'){
			s[i] = s[n - i];
			pal(i + 1);
			s[i] = '.';
			return;
		}
		if(s[n - i] == '.'){
			s[n - i] = s[i];
			pal(i + 1);
			s[n - i] = '.';
			return;
		}
	}
	pal(i + 1);
}

int main(){
	while(cin >> k){
		cin >> s;
		n = s.size();
		--n;
		nn = n/2;
		pal(0);
		cout << "----------" << endl;
	}
}
