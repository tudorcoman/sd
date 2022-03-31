
#include <cstdio>
#include <vector>

using namespace std;

vector<unsigned int> v;

class Hash {
private:
  const static int mod = 123457;
  vector<vector<unsigned int> > table;
  int dim; 
public:
  Hash() {table.resize(mod);}
  unsigned int search(unsigned int value) const {
    unsigned int rem = value % mod;
    for(unsigned int i = 0; i < table[rem].size(); ++ i)
      if(table[rem][i] == value)
        return i;
    return -1;
  }
 
  inline void insert(unsigned int value) {
    if(search(value) == -1) dim ++;
    table[value % mod].push_back(value);
  }
 
  inline void erase(unsigned int value) {
    unsigned int rem = value % mod;
    unsigned int s = table[rem].size() - 1;
    unsigned int pos = this->search(value);
    if(pos != -1) {
      table[rem][pos] = table[rem][s];
      table[rem].pop_back();
    }
    if(search(value) == -1) dim --;
  }

  inline int size() {
      return dim;
  }
} hashuri[2];

int main() {
    freopen("secv5.in", "r", stdin);
    freopen("secv5.out", "w", stdout);

    int N, l, u;
    scanf("%d %d %d", &N, &l, &u);
    v.resize(N);

    long long a, b; a = b = 0;
    int st = 0;

    for (int i = 0; i < N; i ++) {
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < N; i ++) {
        hashuri[0].insert(v[i]);
        while(hashuri[0].size() > u)
            hashuri[0].erase(v[st ++]);
        a += (i - st + 1);
    }

    st = 0;
    for (int i = 0; i < N; i ++) {
        hashuri[1].insert(v[i]);
        while (hashuri[1].size() >= l)
            hashuri[1].erase(v[st ++]);
        b += (i - st + 1);
    }


    printf("%lld\n", a-b);
    return 0;
}