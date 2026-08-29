class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int ans=start^goal; // will contain same no.of bit that needs to be converted
        for(int i=0;i<32;i++){
            if(ans&(1<<i)){ // CHECK IF ith BIT IS SET OR NOT
                cnt++;
            }
        }
        return cnt;
        
    }
};