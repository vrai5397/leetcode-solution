class Solution {
public:
    string frequencySort(string s) {

        vector<pair<char, int>> freq(128);

        // initialize characters
        for (int i = 0; i < 128; i++) {
            freq[i] = {char(i), 0};
        }

        // count frequency
        for (char ch : s) {
            int prev = freq[ch].second;
            freq[ch] = {ch, prev + 1};
        }

        // comparator
        auto lambda = [](pair<char, int>& p1, pair<char, int>& p2) {
            return p1.second > p2.second;
        };

        sort(freq.begin(), freq.end(), lambda);

        string result = "";

        for (auto x : freq) {
            if (x.second > 0) {
                result += string(x.second, x.first);
            }
        }

        return result;
    }
};