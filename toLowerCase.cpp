//https://leetcode.com/problems/to-lower-case/
class Solution {
public:
    string toLowerCase(string str) {
       vector <char> resStr;


       //doing this according to the utf-8 (https://unicode-table.com/ru/)
       for (int i = 0; i < str.length(); i++) {
           (str[i] >= 64 && str[i] < 91) ? resStr.push_back(str[i] + 32) : resStr.push_back(str[i]);
       }

       string s = string(resStr.begin(), resStr.end());

       resStr.clear();

       return s;

    }
};
