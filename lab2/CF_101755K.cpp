
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 200001;
int f[MAX_N], v[MAX_N];

bool valid_sol(int M, int N, int x) {
    // trebuie gasite de la pozitia x + 1 la pozitia N toate elementele de la x+1 la M in ordinea asta
    
    int convinsi = 0, i;
    for (i = 1; i <= N && convinsi < x; i ++)
        if (v[i] > convinsi)
            convinsi ++, x --;

    convinsi = i - 1;
    while (i <= N && convinsi < M) {
        if (v[i] <= convinsi)
            convinsi ++;
        i ++;
    }

    return convinsi == M;
}

int caut(int st, int dr, int M, int N) {
    if (st > dr)
        return 0x7fffffff;
    if (st == dr) return st;

    int mid = (st + dr) / 2;
    if (valid_sol(M, N, mid))
        return min(mid, caut(st, mid, M, N));

    return caut(mid + 1, dr, M, N);
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i ++)
        cin >> v[i];
    cout << caut(0, M, M, N) << '\n';
    return 0;
}
