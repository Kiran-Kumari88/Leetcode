class Solution {
public:
    bool isPowerOfTwo(int n) {
        int N=n;
        if (n <= 0) return false;
        if((N & (N-1))==0) return true;
        return false;
    }
};