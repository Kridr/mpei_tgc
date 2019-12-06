//https://leetcode.com/problems/word-ladder-ii/
class Solution {
public:
  unordered_set<string> dict; // word dictionary

  // mapNextWords[w]: set of all w's possible next words in dictionary
  // The "next" is always in start->end direction
  unordered_map<string, unordered_set<string>> mapNextWords;

  // all shortest ladders
  vector<vector<string>> ladders;

  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
  {
    dict = unordered_set<string>(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return ladders; // quit if endWord is not in dict

    // initialize two layers for two-end BFS
    unordered_set<string> forwardLayer({beginWord}), backwardLayer({endWord});

    // Sub-problem 1: build next word map
    buildMapNextWords(forwardLayer, backwardLayer, true);

    // Sub-problem 2: build ladders
    vector<string> ladder({beginWord});
    buildLadders(beginWord, endWord, ladder);

    return ladders;
  }

  ////////////////////
  // Build mapNextWords recursively using two-end BFS
  // Note: each recursion does exactly 1 transform distance from either start or end direction
  ////////////////////
  void buildMapNextWords(unordered_set<string>& layer1, unordered_set<string>& layer2, bool isForward)
  {
    if (layer1.empty()) return;

    // always BFS from the smaller layer side
    if (layer1.size() > layer2.size()) {
      swap(layer1, layer2);
      isForward = !isForward;
    }

    // remove used words from dict
    for (auto& w : layer1) dict.erase(w);
    for (auto& w : layer2) dict.erase(w);

    // next layer of layer1 by word transform
    unordered_set<string> nextLayer;

    bool shortest_ladder_found = false;

    // transform each word in layer1
    for (auto w : layer1) {
      string origW = w;
      for (int i = 0; i < w.size(); ++i) {
        char origCh = w[i];
        for (char c = 'a'; c <= 'z'; ++c) {
          w[i] = c; // transform word w

          // keep current->next always in start->end direction
          string curWrod = origW, nxtWord = w;
          if (!isForward) swap(curWrod, nxtWord);

          // next layer of layer1 meets layer2: shortest path found!
          if (layer2.count(w)) {
            shortest_ladder_found = true;
            mapNextWords[curWrod].insert(nxtWord);
          }
          //  next layer of layer1 didn't meet layer2, but still in dict, so keep going
          else if (dict.count(w)) {
            nextLayer.insert(w);
            mapNextWords[curWrod].insert(nxtWord);
          }
        }
        w[i] = origCh;
      }
    }

    // recursively build map if not done
    if (!shortest_ladder_found)
      buildMapNextWords(nextLayer, layer2, isForward);
  }

  ////////////////////
  // Build all shortest ladders using back tracking
  // curWord: current word in ladder
  // endWord: end word in ladder
  // ladder: current ladder in building process
  ////////////////////
  void buildLadders(string curWord, string endWord, vector<string>& ladder)
  {
    // if current word reaches end, current ladder is done
    if (curWord == endWord) {
      ladders.push_back(ladder);
      return;
    }

    // try all next word options and append to current ladder
    for (auto& w : mapNextWords[curWord]) {
      ladder.push_back(w);
      buildLadders(w, endWord, ladder);
      ladder.pop_back();
    }
  }
};
