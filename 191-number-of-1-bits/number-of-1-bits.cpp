class Solution {
public:
    int hammingWeight(int n) {
        int N=n;
        int cnt=0;
        while(N>0){
            if(N%2==1) cnt++;
            N=N/2;
        }
        if(N==1) cnt+=1;
        return cnt;
        
    }
};