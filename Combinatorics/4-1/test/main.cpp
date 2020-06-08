#include <iostream>
#include <vector>

#define MAX_N 2000
#define MAX_K 2000
#define MOD 1000000007

using namespace std;

int num[MAX_N][MAX_K];

int dec(int n, int k) {
    if (num[n][k] > 0) return num[n][k];
    num[n][k] = (n <= 1 || k == 1) ? 1 : (dec(n, k - 1) + (n - k >= 0 ? dec(n-k, k) : 0)) % MOD;
    return num[n][k];
}


int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            num[i][j] = 0;
        }
    }
    cout << dec(n, k) << endl;
    
    
    
    return 0;
}
