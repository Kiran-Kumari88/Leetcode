class Solution {
public:
void merge(int start,int mid,int end,vector<int>& arr){
    int i=start;
    int j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
            i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=start;i<=end;i++){
        arr[i]=temp[i-start];
    }
}

int countPairs(int low, int mid, int high, vector<int>& arr){
    int cnt = 0;
    int right = mid + 1;

    for(int i = low; i <= mid; i++){
        while(right <= high && (long long)arr[i] > 2LL * arr[right]){
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(int start,int end,vector<int>& arr){
    int cnt=0;
    if(start>=end) return 0;

    int mid=start+(end-start)/2;

    cnt+=mergeSort(start,mid,arr);
    cnt+=mergeSort(mid+1,end,arr);
    cnt+=countPairs(start,mid,end,arr);
    merge(start,mid,end,arr);
    return cnt;

}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(0,n-1,nums);   
    }
};