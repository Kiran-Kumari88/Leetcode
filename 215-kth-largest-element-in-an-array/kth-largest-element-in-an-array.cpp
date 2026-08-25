class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());

        while (k>1) {
            maxHeap.pop();
            k--;
        }
        return maxHeap.top();
    }
};