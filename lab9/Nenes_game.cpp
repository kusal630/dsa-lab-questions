#include <iostream>
#include <vector>
using namespace std;

class GameSimulator {
private:
    vector<int> a;
public:
    GameSimulator(const vector<int>& a) : a(a) {}
    
    int simulate(int n) {
        int m = n;
        while (true) {
            int cnt = 0;
            for (int x : a) {
                if (x > m) break;
                cnt++;
            }
            if (cnt == 0) break;
            m -= cnt;
        }
        return m;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, q;
        cin >> k >> q;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        vector<int> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i];
        }
        GameSimulator gs(a);
        vector<int> results;
        for (int n : queries) {
            results.push_back(gs.simulate(n));
        }
        for (size_t i = 0; i < results.size(); ++i) {
            if (i > 0) cout << " ";
            cout << results[i];
        }
        cout << endl;
    }
    return 0;
}