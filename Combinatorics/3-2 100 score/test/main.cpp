#include <iostream>
#include <vector>


using namespace std;


int main(int argc, const char * argv[]) {
    long long int n, k;
    cin >> n >> k;
    k--;
    long long perm[n];
    for (long long int i = 0; i < n; i++) perm[i] = 0;
    long long int pos;
    long long int place;
    for (long long int i = n; i > 0; i--) {
        pos = k % i;
        k = k / i;
        if (k % 2 == 0) {
            place = 0;
            while (place <= pos) {
                if (perm[n - place - 1] != 0) pos++;
                place++;
            }
            perm[n - place] = i;
        } else {
            place = 0;
            while (place <= pos) {
                if (perm[place] != 0) pos++;
                place++;
            }
            perm[place - 1] = i;
        }
    }
    for (long long int i = 0; i < n; i++) cout << perm[i] << " ";
    return 0;
}
