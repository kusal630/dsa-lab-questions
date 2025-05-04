#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class StrengthSolver {
private:
    int max_val;
    int count_max;
    int second_max;

public:
    StrengthSolver(const vector<int>& s) {
        max_val = *max_element(s.begin(), s.end());
        count_max = count(s.begin(), s.end(), max_val);
        
        second_max = -1;
        for (int num : s) {
            if (num != max_val && num > second_max) {
                second_max = num;
            }
        }
        if (second_max == -1) {
            second_max = max_val;
        }
    }

    int computeDifference(int s_i) {
        if (s_i == max_val) {
            if (count_max > 1) {
                return s_i - max_val;
            } else {
                return s_i - second_max;
            }
        } else {
            return s_i - max_val;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        StrengthSolver solver(s);
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                cout << " ";
            }
            cout << solver.computeDifference(s[i]);
        }
        cout << "\n";
    }
    return 0;
}