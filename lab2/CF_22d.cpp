#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
vector<pii> intervals;

inline bool cmp(pii a, pii b) {return a.second < b.second;}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        pii x;
        cin >> x.first >> x.second;
        if (x.first > x.second)
            swap(x.first, x.second);
        intervals.push_back(x);
    }

    sort(intervals.begin(), intervals.end(), cmp);

    int dr = intervals[0].second;
    vector<int> ans;
    ans.push_back(dr);
    
    for (int i = 1; i < (int)intervals.size(); i ++) {
        if (intervals[i].first > dr) {
            dr = intervals[i].second;
            ans.push_back(dr);
        }
    }

    cout << ans.size() << '\n';
    for (int it: ans)
        cout << it << ' ';
    cout << '\n';
    return 0;
}

        
