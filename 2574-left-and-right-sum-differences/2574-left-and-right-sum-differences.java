class Solution {
    public int[] leftRightDifference(int[] nums) {
        int n = nums.length;

        int total_sum = 0;
        for(int num: nums){
            total_sum += num;
        }
        
        int[] answer = new int[n];
        
        int leftsum=0;
        
        for(int i =0 ;i <n ; i++){
            int rightsum = total_sum - leftsum - nums[i];
            answer[i] = Math.abs(leftsum - rightsum);
            leftsum += nums[i];
        }
        return answer;
    }
}