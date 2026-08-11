class Solution {
    public int thirdMax(int[] nums) {
        long max1 = Long.MIN_VALUE;
        Long max2 = Long.MIN_VALUE;
        long max3 = Long.MIN_VALUE;

        for(long x : nums){

            if(x == max1 || x == max2 || x == max3){
                continue;
            }

            if(x > max1){
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if(x > max2){
                max3 = max2;
                max2 = x;
            }
            else if(x > max3){
                max3 = x;
            }
        }
        if(max3 == Long.MIN_VALUE){
            return (int) max1;
        }
        return (int)max3;
    }
}