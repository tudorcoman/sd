
#include <iostream>

using namespace std;

int a[] = {4, 5, 6, 0, 1, 2, 3};

int minCirc(int v[], int st, int dr) {
    if (st > dr)
        return -1;
    int mid = st + (dr - st) / 2;
    if (v[mid] > v[mid + 1])
        return mid + 1; 

    if (v[mid] > v[0])
        return minCirc(v, mid + 1, dr);
    return minCirc(v, st, mid - 1);
}

int caut(int v[], int st, int dr, int e) {
    if (st > dr)
        return -1;
    int mid = st + (dr - st) / 2;
    if (v[mid] == e)
        return mid;

    if (v[mid] < e)
        return caut(v, mid + 1, dr, e);

    return caut(v, st, mid - 1, e);
}

int firstCirc(int v[], int n, int e) {
    int minPos = minCirc(v, 0, n - 1);
    int first_left = v[0], first_right = v[minPos - 1], second_left = v[minPos], second_right = v[n - 1];

    if (first_left <= e && e <= first_right)
        return caut(v, 0, minPos - 1, e);

    if (v[minPos] == e)
        return minPos;

    return caut(v, minPos, n - 1, e);
}

int b[] = {8, 9, 10, 12, 19, 3, 4, 5};

int main() {
    cout << minCirc(a, 0, 6) << endl;

    cout << firstCirc(b, 8, 12) << endl;
    cout << firstCirc(b, 8, 5) << endl;
    cout << firstCirc(b, 8, 1) << endl;
    return 0;
}
