#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > p;

int caut(int st, int dr, int elem) {
    if (st > dr)
        return p.size();
    int mid = (st + dr) / 2;
    if (p[mid].back() <= elem) {
        return min(caut(st, mid - 1, elem), mid);
    }
    return caut(mid + 1, dr, elem);
}

int main() {
    int N, k;
    for (cin >> N; N; N --) {
        cin >> k;
        int pos = caut(0, p.size() - 1, k);
        if (pos == p.size()) {
            vector<int> x;
            x.push_back(k);
            p.push_back(x);
        } else
            p[pos].push_back(k);
    }

    for(auto part: p) {
        for (int x: part)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
