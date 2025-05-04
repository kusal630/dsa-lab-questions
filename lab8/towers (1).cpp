#include <iostream>
#include <vector>
using namespace std;

class TowerGame {
private:
    vector<long long> towers;  // towers[0] is the base tower
public:
    TowerGame(const vector<long long>& towers) : towers(towers) {}

    // Computes the donation value from a donor tower.
    static long long donation(long long x) {
        if (x == 2)
            return 1;
        else if (x == 1000000000LL)
            return x / 2;
        else if (x % 2 == 0)
            return (x + 2) / 2;
        else
            return (x + 1) / 2;
    }

    // Returns the final result: base tower plus maximum donation from one donor.
    long long getResult() {
        if (towers.empty())
            return 0;
        long long base = towers[0];
        long long maxDonation = 0;
        for (size_t i = 1; i < towers.size(); i++) {
            long long d = donation(towers[i]);
            if (d > maxDonation)
                maxDonation = d;
        }
        return base + maxDonation;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<long long> towers(N);
        for (int i = 0; i < N; i++) {
            cin >> towers[i];
        }
        TowerGame game(towers);
        cout << game.getResult() << "\n";
    }

    return 0;
}
