#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        cin.ignore(); // Ignore the newline after n
        
        vector<vector<string>> players(3);
        for (int i = 0; i < 3; ++i) {
            string line;
            getline(cin, line);
            istringstream iss(line);
            string word;
            vector<string> words;
            while (iss >> word) {
                words.push_back(word);
            }
            players[i] = words;
        }
        
        unordered_map<string, unordered_set<int>> word_map;
        for (int i = 0; i < 3; ++i) {
            for (const string& word : players[i]) {
                word_map[word].insert(i);
            }
        }
        
        vector<int> scores(3, 0);
        for (int i = 0; i < 3; ++i) {
            for (const string& word : players[i]) {
                int cnt = word_map[word].size();
                if (cnt == 1) {
                    scores[i] += 3;
                } else if (cnt == 2) {
                    scores[i] += 1;
                }
                // cnt ==3 contributes 0, so do nothing
            }
        }
        
        cout << scores[0] << " " << scores[1] << " " << scores[2] << "\n";
    }
    
    return 0;
}