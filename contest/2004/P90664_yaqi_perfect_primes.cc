#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 4000005; // Maximum value + buffer
vector<bool> is_prime(MAX_N, true);

// Function to precompute primes using Sieve of Eratosthenes
void sieve() {
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes
    for (int i = 2; i * i < MAX_N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Function to calculate sum of digits
int sum_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check if n is a perfect prime
bool is_perfect_prime(int n) {
    // If the number itself is not prime, it fails immediately
    if (!is_prime[n]) return false;
    
    while (n >= 10) {
        n = sum_digits(n);
        if (!is_prime[n]) return false;
    }
    
    return true;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute primes
    sieve();

    int n;
    while (cin >> n && n != 0) {
        if (is_perfect_prime(n)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}