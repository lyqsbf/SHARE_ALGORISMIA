#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

constexpr int UNDEF = INT_MAX;

int n;
vector<string> w;
vector<int> s, u, v;

void write()
{
    string prefix = "";
    for (int i = 0; i < n; ++i) {
        cout << prefix;
        for (int j = 0; j < w[i].size(); ++j)
            cout << s[w[i][j] - 'A'];
        prefix = (i < n - 2 ? " + " : " = ");
    }
    cout << endl;
}

void gen(char c, int diff)
{
    if (c > 'Z') {
        if (diff == 0)
            write();
        return;
    }
    if (v[c - 'A'] == UNDEF)
        return gen(c + 1, diff);
    for (int k = 0; k <= 9; ++k) {
        if (not u[k]) {
            u[k] = true;
            s[c - 'A'] = k;
            gen(c + 1, diff + k * v[c - 'A']);
            u[k] = false;
        }
    }
}

int main()
{
    v = vector<int>('Z' - 'A' + 1, UNDEF);
    cin >> n;
    w = vector<string>(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        for (int j = w[i].size() - 1, p = 1; j >= 0; --j, p *= 10) {
            char c = w[i][j];
            if (v[c - 'A'] == UNDEF)
                v[c - 'A'] = 0;
            v[c - 'A'] += (i < n - 1 ? p : -p);
        }
    }
    s = vector<int>('Z' - 'A' + 1, UNDEF);
    u = vector<int>(10, false);
    gen('A', 0);
}
