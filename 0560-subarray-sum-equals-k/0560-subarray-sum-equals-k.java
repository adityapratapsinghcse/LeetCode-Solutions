class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();

        map.put(0,1);

        int prefix_sum = 0;
        int count = 0;

        for(int i=0 ; i< nums.length ; i++){
            prefix_sum += nums[i];

            int target = prefix_sum - k;

            if( map.containsKey(target)){
                count+=map.get(target);
            }

            map.put(prefix_sum , map.getOrDefault(prefix_sum,0) + 1);
        }
        return count;
    }
}