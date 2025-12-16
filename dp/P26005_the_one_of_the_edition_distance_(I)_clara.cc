#include <iostream>
#include <vector>
#include <string>
using namespace std;


using VI = vector<int>;
using MI = vector<VI>;
using VC = vector<char>;
using MC = vector<VC>;
int n;
string w1, w2;
VI cost;
MI cas;


int f(int s1, int s2){
    int res = 0;
    if (s1 == 0) {
        for (int i = 0; i < s2; ++i) {
            res += cost[w2[i] - 'a'];
        }
        return res;
    }
    
    if (s2 == 0) {
        for (int i = 0; i < s1; ++i) {
            res += cost[w1[i] - 'a'];
        }
        return res;
    }
    
    if (cas[s1][s2] != -1) return res = cas[s1][s2];
    
    
    if (w1[s1 - 1] == w2[s2 - 1]) {
        return cas[s1][s2] = f(s1 - 1, s2 - 1);
    }
    
    else {
        return cas[s1][s2] = min(cost[w2[s2 - 1] - 'a'] + f(s1, s2 - 1), cost[w1[s1 - 1] - 'a'] + f(s1 - 1, s2));
    }
}


int main() {
    while (cin >> n) {
        cost = VI(n);
        for (int i = 0; i < n; ++i) cin >> cost[i];
        cin >> w1 >> w2;
        int s1 = w1.size();
		int s2 = w2.size();
        cas = MI(s1 + 1, VI(s2 + 1, -1));
        cout << f(s1, s2) << endl;
    }
}
