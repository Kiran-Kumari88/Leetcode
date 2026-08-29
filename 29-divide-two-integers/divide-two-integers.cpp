class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == divisor)return 1;
        
        bool sign = true;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = false;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;
        while (n >= d) {
            int power = 0;
            while (n >= (d << (power + 1))) {
                power++;
            }
            ans += (1LL << power);
           n = n - (d << power);
        }

        if (ans == (1LL << 31)) {
            if (sign)
                return INT_MAX;
            else{
                return INT_MIN;
            }
        }

        return sign ? ans : -ans;
    }
};