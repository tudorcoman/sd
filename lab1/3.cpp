
#include <iostream>

using namespace std;

int cautare_pare(int v[], int st, int dr, int e) {
//    cerr << st << " " << dr << endl;
    if (st > dr) return -1;
    if (st == dr) return (dr % 2 == 1) ? -1 : ((v[st] == e ? st : -1));

    if (dr - st == 1) {
        if (st % 2 == 0 && v[st] == e) return st;
        if (dr % 2 == 0 && v[dr] == e) return dr;
        return -1;
    }

    int mid = st + (dr - st) / 2;

    if (mid % 2 == 1) {
        int a = mid - 1, b = mid + 1;
        if (a < 0 && b > dr)
            return -1;
        if (a < 0)
            mid = b;
        else
            mid = a;
    }

    if (v[mid] == e)
        return mid;

    if (v[mid] < e)
        return cautare_pare(v, mid + 1, dr, e);

    return cautare_pare(v, st, mid - 1, e);
}

int cautare_impare(int v[], int st, int dr, int e) {
//    cerr << st << " " << dr << endl;
    if (st > dr) return -1;
    if (st == dr) return (dr % 2 == 0) ? -1 : ((v[st] == e ? st : -1));

    if (dr - st == 1) {
        if (st % 2 == 1 && v[st] == e) return st;
        if (dr % 2 == 1 && v[dr] == e) return dr;
        return -1;
    }

    int mid = st + (dr - st) / 2;

    if (mid % 2 == 0) {
        int a = mid - 1, b = mid + 1;
        if (a < 0 && b > dr)
            return -1;
        if (a < 0)
            mid = b;
        else
            mid = a;
    }

    if (v[mid] == e)
        return mid;

    if (v[mid] > e)
        return cautare_impare(v, mid + 1, dr, e);

    return cautare_impare(v, st, mid - 1, e);
}


int existsAlternate(int v[], int n, int e) {
    int dri = n - 1, drp = n - 1;

    if (dri % 2 == 0) dri --;
    if (drp % 2 == 1) drp --;

    int x = cautare_pare(v, 0, drp, e), y = cautare_impare(v, 0, dri, e);
    return max(x, y);
}

    
int main() {
    int v[] = {0, 5, 2, 3, 4, 1};

    for (int i = 0; i < 6; i ++)
        cout << i << " " << existsAlternate(v, 6, i) << endl;    
    return 0;
}
