class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        if (x == 0)
            return 0;

        if (n < 0) {
            return 1 / x * myPow(1 / x, -(n + 1));
        } else {
            return (n % 2 != 0) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
        }
    }
};
