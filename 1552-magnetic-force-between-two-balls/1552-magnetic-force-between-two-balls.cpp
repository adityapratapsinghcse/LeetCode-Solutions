class Solution {
     bool is_possible(vector<int> &arr , int k , int mid){
        int ball = 1;
        int pos = arr[0];
        
        for(int i=1 ; i< arr.size() ; i++){
            if(arr[i] - pos >= mid){
                ball++;
                pos = arr[i];
            }
            if(ball == k){
                return true;
            }
        }
        return false;
            
    }
public:
    int maxDistance(vector<int>& arr, int k) {
        sort(arr.begin() , arr.end());
        int start = 1;
        int end = arr[arr.size()-1] - arr[0];
        int ans=-1;
        
        while(start <= end){
            int mid = (start+end) /2;
            
            if(is_possible(arr,k,mid)){
                ans = mid;
                start = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        return ans;
    }
};