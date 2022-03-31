
#include <fstream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;

int main() {
    ifstream in("pariuri.in");
    ofstream out("pariuri.out");

    int N, M, x, y, pairs = 0;
    for(in >> N; N; -- N) {
        for (in >> M; M; -- M) {
            in >> x >> y;
            if(m.find(x) == m.end()) {
                m[x] = 0;
                pairs ++;
            }
            m[x] += y;
        }
    }

    out << pairs << '\n';
    for(const auto& it: m) {
        out << it.first << " " << it.second << " ";
    }
    out << '\n';
    return 0;
}