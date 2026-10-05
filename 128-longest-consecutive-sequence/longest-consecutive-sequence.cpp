class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        
        int longest=1;
        unordered_set<int>s;
        
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
        }
        
        for(auto it:s){
            if(s.find(it-1)==s.end()){ // it is the starting element
                int x=it;
                int cnt=1;
                
                while(s.find(x+1)!=s.end()){ // jab tak aage ke elements mil re h 
                    cnt++;
                    x=x+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
        
    }
};