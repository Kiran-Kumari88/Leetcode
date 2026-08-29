class Solution {
public:
    int hammingWeight(int n) {
        int N=n;
        int cnt=0;
        while(N!=0){
            N = N & (N-1);
            cnt++;
        }
        return cnt;
        
    }
};