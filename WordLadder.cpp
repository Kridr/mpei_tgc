//https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int HDE1(string word1, string word2) {
        int hd = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i])
                hd++;
        }
        return hd == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wl) {

        unordered_map <string, int> track;
        track[beginWord] = 1;

        unordered_set <string> unvis(wl.begin(), wl.end());
        if (unvis.empty() || unvis.find(endWord) == unvis.end())
            return 0;


        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            auto itr = unvis.begin();
            while (itr != unvis.end()) {
                string t = *itr;
                if (HDE1(word, t)) {
                    track[t] = track[word] + 1;

                    if (t == endWord)
                        return track[t];

                    itr = unvis.erase(itr);
                    q.push(t);

                } else ++itr;
            }
        }


    return 0;
    }
};
