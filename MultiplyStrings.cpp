//https://leetcode.com/problems/multiply-strings/
class Solution {
public:
    int pf(char ch) {
        return (int)ch - (int)48;
    }

    string multiply(string num1, string num2) {

        //except zero case
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        //finding length for convenience and speed
        int na = num1.length();
        int nb = num2.length();

        //primal vector
        vector <int> mlp(na + nb);

        //filling vector with primal values
        for (int i = 0; i < na; i++) {
            for (int j = 0; j < nb; j++) {
                mlp[i + j] += pf(num1[na - i - 1]) * pf(num2[nb - j - 1]);
            }
        }

        //calculating numeral in every digit
        for (int i = 0; i < na + nb - 1; i++) {
            //transfer number
            int carry;
            carry = mlp[i] / 10;
            mlp[i] %= 10;
            //transferring
            mlp[i + 1] += carry;
        }

        //deleting all leading zeroes
        int k = na + nb - 1;
        while (mlp[k] == 0) {
            mlp.erase(mlp.begin() + k);
            k--;
        }

        //same as na and nb
        int sz = mlp.size();

        //vector of chars to convert to string further
        vector <char> res(sz);

        //fillin vector res
        for (int i = 0; i < sz; i++) {
            res[sz - i - 1] = mlp[i] + '0';
        }

        string m = string(res.begin(), res.end());

        //make memory free
        mlp.clear();
        res.clear();

        return m;


    }
};
