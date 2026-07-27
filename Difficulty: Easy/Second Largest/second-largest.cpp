class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int first = INT_MIN;
        int second = -1;
        
        for(int i=0 ; i< arr.size() ; i++){
            if(arr[i] > first){
                first = arr[i]; 
            }
        }
        
        for(int i=0 ; i<arr.size();i++){
            if(arr[i] > second && arr[i] != first){
                second = arr[i];
            } 
        }
        return second;
    }
};