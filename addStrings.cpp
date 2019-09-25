//https://leetcode.com/problems/add-strings/
class Solution {
public:
    int pf(char ch) {
        return (int)ch - (int)48;
    }

    string addStrings(string num1, string num2) {
        int na = num1.length();
        int nb = num2.length();

        int sz = na > nb ? na : nb;

        vector <int> sum(++sz);

        //first number
        for (int i = 0; i < na; i++) {
            sum[sz - i - 1] = pf(num1[na - i - 1]);
        }

        //first + second number
        for (int i = 0; i < nb; i++) {
            sum[sz - i - 1] += pf(num2[nb - i - 1]);
        }

        //final calculating
        for (int i = 0; i < sz - 1; i++) {
            int carry = sum[sz - i - 1]/10;
            sum[sz - i - 1] %= 10;
            sum[sz - i - 2] += carry;
        }

        //deleting first zero elem
        if (sum[0] == 0) {
            sum.erase(sum.begin() + 0);
        }

        sz = sum.size();

        vector <char> res(sz);

        for (int i = 0; i < sz; i++) {
            res[i] = sum[i] + '0';
        }

        string s = string(res.begin(), res.end());

        sum.clear();
        res.clear();

        return s;
    }
};
