#include <iostream>
#include <vector>

#define v_num 9

using namespace std;

class vis {
public:
    int v_list[v_num];
    vis() {
        for(int i = 0; i < v_num; i++) {
            v_list[i] = 0;
        }
    }
};

int mark[v_num];
int prior[v_num];
int a,b,l;
int ans = 0;

int gr_cur[v_num][v_num];


int graph[v_num][v_num] = {
    {0,1,0,1,1,1,0,1,0},
    {1,0,1,1,1,1,1,0,1},
    {0,1,0,1,1,1,0,1,0},
    {1,1,1,0,1,0,1,1,1},
    {1,1,1,1,0,1,1,1,1},
    {1,1,1,0,1,0,1,1,1},
    {0,1,0,1,1,1,0,1,0},
    {1,0,1,1,1,1,1,0,1},
    {0,1,0,1,1,1,0,1,0}};

void constr_gr_cur(vis v, int cur)
{
    for (int i = 0; i < v_num; i++) {
        gr_cur[cur][i] = graph[cur][i];
    }
    if (v.v_list[1]) {
        gr_cur[0][2] = 1;
        gr_cur[2][0] = 1;
    }
    if (v.v_list[3]) {
        gr_cur[0][6] = 1;
        gr_cur[6][0] = 1;
    }
    if (v.v_list[4]) {
        gr_cur[0][8] = 1;
        gr_cur[8][0] = 1;
        gr_cur[1][7] = 1;
        gr_cur[7][1] = 1;
        gr_cur[2][6] = 1;
        gr_cur[6][2] = 1;
        gr_cur[3][5] = 1;
        gr_cur[5][3] = 1;
    }
    if (v.v_list[5]) {
        gr_cur[2][8] = 1;
        gr_cur[8][2] = 1;
    }
    if (v.v_list[7]) {
        gr_cur[6][8] = 1;
        gr_cur[8][6] = 1;
    }
    for (int i = 0; i < v_num; i++) {
        if (v.v_list[i]) {
            gr_cur[cur][i] = 0;
        }
    }
}

void pass_search(int cur, int cur_l, vis v)
{
    v.v_list[cur] = 1;
    if (cur_l == l) {
        if(cur == b - 1) ans++;
    } else {
        for (int i = 0; i < v_num; i++) {
            constr_gr_cur(v, cur);
            if (gr_cur[cur][i]) {
                pass_search(i, cur_l + 1, v);
            }
        }
    }
    
}


int main(int argc, const char * argv[]) {
    
    cin >> a >> b >> l;
    vis v;
    pass_search(a - 1, 1, v);
    cout << ans << endl;
    return 0;
}
