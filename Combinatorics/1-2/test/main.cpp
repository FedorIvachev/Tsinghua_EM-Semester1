#include <iostream>
#include <vector>

#define MOD 1000000007
#define NUM 2000

using namespace std;

int main(int argc, const char * argv[]) {
    long long n, m;
    cin >> n >> m;
    long long cur[NUM];
    long long prev[NUM];
    prev[0] = 1;
    prev[1] = 1;
    
    long long *cur_comb = cur, *prev_comb = prev, *temp;
    
    for (int i = 2; i < n + 1; i++) {
        cur_comb[0] = 1;
        for (int j = 1; j < i; j++) {
            cur_comb[j] = (prev_comb[j] + prev_comb[j-1]) % MOD;
        }
        cur_comb[i] = 1;
        temp = cur_comb;
        cur_comb = prev_comb;
        prev_comb = temp;
    }
    cout << prev_comb[m] << endl;
    
    
    return 0;
}
