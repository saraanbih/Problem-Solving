class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // (currentWord, depth)

        while (!q.empty()) {
            auto [word, steps] = q.front(); q.pop();

            if (word == endWord) return steps;

            st.erase(word);  // Mark as visited

            for (int j = 0; j < word.size(); j++) {
                char original = word[j];
                for (int k = 0; k < 26; k++) {
                    word[j] = 'a' + k;
                    if (st.find(word) != st.end()) {
                        q.push({word, steps + 1});
                        st.erase(word); // Avoid revisiting
                    }
                }
                word[j] = original;  // Restore
            }
        }

        return 0;  // No path found
    }
};
