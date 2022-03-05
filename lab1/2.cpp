
#include <iostream>

using namespace std;

int caut(int v[], int st, int dr, int e, int op) {
    if (st > dr)
        return -1;
    int mid = st + (dr - st) / 2;
    if (v[mid] == e)
        return mid;

    if (op * v[mid] < op * e)
        return caut(v, mid + 1, dr, e, op);
    return caut(v, st, mid - 1, e, op);
}

int lastAlmost(int v[], int n, int k, int e) {
    int Max = -1;
    for (int i = 0; i < n; i += k) {
        int capat_st = v[i], capat_dr = v[i + k - 1], op = 1;
        if (capat_dr < capat_st)
            swap(capat_st, capat_dr), op = -1;
        if (capat_st <= e && e <= capat_dr)
            Max = max(Max, caut(v, i, i + k - 1, e, op));
    }

    return Max;
}

int main() {
    int n = 12, k = 2;
    int v[] = {2, 0, 3, 1, 6, 7, 4, 5, 10, 8, 9, 11};

    int t[] = {6, 1, 11};
    for (int i = 0; i < 3; i ++)
        cout << lastAlmost(v, n, k, t[i]) << endl;
    return 0;
}

