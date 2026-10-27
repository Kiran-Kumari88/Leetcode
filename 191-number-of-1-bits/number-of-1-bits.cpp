class Solution {
public:
    int hammingWeight(int n) {
        int N = n;
        int cnt = 0;

        while (N > 0) {
            if (N & 1) cnt++;
            N = N >> 1;
        }

        return cnt;
    }
};