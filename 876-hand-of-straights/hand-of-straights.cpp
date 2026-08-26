class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();

        if(n % groupSize){ // groups cannot be made
            return false;
        }

        map<int,int>mp;
        for(int freq : hand){ // put elements in map-> {num,freq}
            mp[freq]++;
        }

        while(!mp.empty()){
            int curr=mp.begin()->first;

            for(int i=0;i<groupSize;i++){
                if(mp[curr+i]==0){ // next element not present in the map
                    return false;
                }
                mp[curr+i]--; //reduce freq in map of that element
                if(mp[curr+i]<1){
                    mp.erase(curr+i);
                }
            }
        }
        return true;
        
    }
};