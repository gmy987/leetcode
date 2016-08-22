class Solution {
  public:
    double myPow(double x, int n) {
        long long q = n;
        q = q < 0 ? -q : q;
        double acc = 1;
        while (q) {
            if (q & 1)
                acc = x * acc;
            x *= x;
            q >>= 1;
        }
        return n < 0 ? 1 / acc : acc;
    }
};
