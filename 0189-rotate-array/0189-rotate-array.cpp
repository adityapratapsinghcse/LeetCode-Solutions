class Solution {
public:
    void reverse_num(vector<int>& arr , int start, int end){
        while(start<end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % (nums.size());
        reverse_num(nums,0,nums.size()-1);
        reverse_num(nums,0,k-1);
        reverse_num(nums,k,nums.size()-1);
    }
};