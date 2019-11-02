//https://leetcode.com/problems/broken-calculator/
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ops = 0;

        while (X != Y) {
            //trivial
            if (X > Y)
                return (X - Y + ops);

            /*
            Y is odd:
                it is clear
                that the last op to reach it is DECREMENT

            Y is even:
                Y = 2m

                last op is decrement:
                    2m -> 2m + 2k -> m + k ->(somehow) x
                    starting from m + k (it doesnt matter how we reach it)
                    m + k -> 2m + 2k = 1 op
                    2m + 2k -> 2m = 2k ops
                    so (2k + 1) ops need

                last op is double:
                    2m -> m -> m + k -> (somehow) x
                    starting from m + k (it doesnt matter how we reach it)
                    m + k -> m = k ops
                    m -> 2m = 1 op
                    so (k + 1) ops need

                 2k + 1 > k + 1
                 Hence, if Y is even the last op to reach it is DOUBLE

            */

            (Y % 2 == 0) ? (Y /= 2) : Y++;


            //we do only 1 op
            ops++;
        }

        return ops;
    }
};
