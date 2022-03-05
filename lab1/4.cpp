
#include <iostream>

using namespace std;

int peak(int v[], int st, int dr) {
    if (st > dr) return -1;
    cerr << st << " " << dr << endl;
    int mid = st + (dr - st) / 2; 
    if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
        return mid;
 
    if (v[mid] >= v[mid - 1] && v[mid - 1] >= v[mid - 2])
        return peak(v, mid + 1, dr);

    return peak(v, st, mid - 1);
}


int caut(int v[], int st, int dr, int e, int op) {
    if (st > dr) return -1;
    int mid = st + (dr - st) / 2;
    if (v[mid] == e) return mid;
    if (v[mid] * op > e * op) return caut(v, st, mid - 1, e, op);
    return caut(v, mid + 1, dr, e, op);
}

int existsBitonic(int v[], int n, int e) {
    int vf = peak(v, 0, n - 1);
    return max(caut(v, 0, vf, e, 1), caut(v, vf, n - 1, e, -1));
}

int main() {
    int v[] = {1, 2, 3, 3, 4, 4, 5, 4, 4, 3, 3, 1};
    cout << peak(v, 0, 11) << endl;
    
    for (int i = 1; i <= 5; i ++)
        cout << i << " " << existsBitonic(v, 12, i) << endl;    
    return 0;
}
