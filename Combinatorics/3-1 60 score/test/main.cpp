#include <iostream>
#include <vector>


using namespace std;

class num {
public:
    int n;
    int ar; // 0 = left; 1 = right
    num(int k) {
        n = k;
        ar = 0;
    }
    num() {
        ar = 0;
    }
};

void next_perm(int n, int k, num perm[]) {
    int larg_ind = 0;
    int larg_n = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && perm[i].ar == 0) {
            if (perm[i - 1].n < perm[i].n) {
                if (perm[i].n > larg_n) {
                    larg_n = perm[i].n;
                    larg_ind = i;
                }
            }
        } else if (i != n - 1 && perm[i].ar) {
            if (perm[i + 1].n < perm[i].n) {
                if (perm[i].n > larg_n) {
                    larg_n = perm[i].n;
                    larg_ind = i;
                }
            }
        }
    }
    if (perm[larg_ind].ar == 0) {
        perm[larg_ind].ar = perm[larg_ind - 1].ar;
        perm[larg_ind - 1].ar = 0;
        perm[larg_ind].n = perm[larg_ind - 1].n;
        perm[larg_ind - 1].n = larg_n;
    } else {
        perm[larg_ind].ar = perm[larg_ind + 1].ar;
        perm[larg_ind + 1].ar = 1;
        perm[larg_ind].n = perm[larg_ind + 1].n;
        perm[larg_ind + 1].n = larg_n;
    }
    for (int i = 0; i < n; i++) {
        if (perm[i].n > larg_n) {
            perm[i].ar = (perm[i].ar ? 0 : 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    num perm[n];
    for (int i = 0; i < n; i++) perm[i].n = i + 1;
    for (int i = 1; i < k; i++) {
        next_perm(n, k, perm);
        cout << i << ": ";
        for (int i = 0; i < n; i++) cout << perm[i].n << " ";
        cout << endl;
    }
    return 0;
}
