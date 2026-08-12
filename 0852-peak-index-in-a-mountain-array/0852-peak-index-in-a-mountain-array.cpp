class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() -1;

        while(start <= end){
            int mid = (start + end) /2;

            if(arr[mid] < arr[mid+1]){
                start = mid+1;
            }
            else if(arr[mid-1] > arr[mid]){
                end = mid-1;
            }
            else if(arr[mid] > arr[mid+1]){
                return mid;
            }
        }
        return -1;
    }
};