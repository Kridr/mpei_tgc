class Solution {
public:
    int fib(int N) {
      long int result = 0;
      //counted with memorising two previous number
      long int firstPrev = 1;
      long int secondPrev = 1;
      if (N == 1 || N == 2) {
        return firstPrev;
      } else {
          for (int i = 2; i < N; i++) {
              result = firstPrev + secondPrev;
              firstPrev = secondPrev;
              secondPrev = result;
          }
          return result;
      }
    }
};
