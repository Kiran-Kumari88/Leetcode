class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        unsigned int xr = 0;

        // Step 1: XOR of all elements
        for(int num : nums) {
            xr = xr ^ num;
        }

        // Step 2: Find rightmost set bit
        unsigned int bit = xr & -xr;

        int a = 0, b = 0;

        // Step 3: Divide into two groups
        for(int num : nums) {
            if(num & bit) {
                a = a ^ num;
            }
            else {
                b = b ^ num;
            }
        }

        return {a, b};
    }
};