#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_map<int, int> last_occurrence;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            if (last_occurrence.find(a[i]) != last_occurrence.end()) {
                start = max(start, last_occurrence[a[i]] + 1);
            }
            last_occurrence[a[i]] = i;
        }

        cout << start << '\n';
    }

    return 0;
}
