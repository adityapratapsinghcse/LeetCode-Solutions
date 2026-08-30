class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_index = 0;
        int max_index = 0;

        for(int i=0 ; i < nums.size() ;i++){
            if(nums[i] > nums[max_index]){
                max_index = i;
            }
            if(nums[i] < nums[min_index]){
                min_index = i;
            }

        } 
        int left = min(min_index, max_index);
        int right = max(min_index, max_index);
        
        int fromFront = right+1;

        int fromBack = nums.size() - left;

        int fromBoth = (left+1) + (nums.size() - right);


        return min({fromFront, fromBack , fromBoth});
    }
};