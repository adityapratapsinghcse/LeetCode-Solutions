class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        vector<int> res;
        int max = INT_MIN;
        int min = INT_MAX;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] > max){
                max = arr[i];
            }    
            if(arr[i] < min){
                min = arr[i];
            }
        }
        res.push_back(min);
        res.push_back(max);
        return res;
    }
};