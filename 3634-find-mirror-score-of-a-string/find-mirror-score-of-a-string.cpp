class Solution {
public:
    long long calculateScore(string s) {
        long long score = 0;

        unordered_map<char, char> mirror;
        for(int i = 0; i < 26; i++) {
            mirror['a' + i] = 'z' - i;
        }

        unordered_map<char, vector<int>> mp;

        for(int i = 0; i < s.size(); i++) {
            char ch = mirror[s[i]];

            if(!mp[ch].empty()) {
                score += (i - mp[ch].back());
                mp[ch].pop_back();
            }
            else {
                mp[s[i]].push_back(i);
            }
        }

        return score;
    }
};