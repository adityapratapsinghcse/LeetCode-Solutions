class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> suffix_max(arr.size());

        int n = arr.size();
        suffix_max[n-1] = -1;
        for(int i=n-2 ; i >= 0 ; i--){
            suffix_max[i] = max(suffix_max[i+1],arr[i+1]);
        }
        return suffix_max;
    }
};