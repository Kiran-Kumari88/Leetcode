class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;

        // sort by end time
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

    // n meetings in one room
        int cnt=1;
        int lastEndTime=intervals[0][1];
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=lastEndTime){
                cnt++;
                lastEndTime=intervals[i][1];
            }
        }
        //total minus that can be accomodated in one room. = that needs to be removed
        return n-cnt;
    }
};