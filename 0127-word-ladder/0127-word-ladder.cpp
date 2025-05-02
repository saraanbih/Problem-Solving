class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> st(wordList.begin(),wordList.end());
       if(st.find(endWord) == st.end())return 0;
       queue<pair<string,int>> q;
       q.push({beginWord,1});
       while(!q.empty()){
          auto[word,deg] = q.front(); q.pop();
          if(word == endWord) return deg;
          st.erase(word);
          for(int j = 0;j<word.size();j++){
             char ch = word[j];
             for(int i=0;i<26;i++){
                word[j] = 'a' + i;
                if(st.find(word) != st.end()){
                    q.push({word,deg+1});
                    st.erase(word);
                }
             }
             word[j] = ch;
          }
       }
       return 0;
    }
};
