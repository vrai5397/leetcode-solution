class Solution {
public:
unordered_map<string,int> mpp;
    vector<vector<string>> ans;

    void dfs(string word, vector<string>& seq, string& beginWord) {
        if (word == beginWord) {
            auto temp = seq;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        int steps = mpp[word];

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq, beginWord);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);

        mpp[beginWord] = 1;
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int steps = mpp[word];

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.count(word)) {
                        q.push(word);
                        mpp[word] = steps + 1;
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq, beginWord);
        }

        return ans;
    }
};