import java.util.*;

class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int smaller = 0, equal = 0;

        for (int x : nums) {
            if (x < target)
                smaller++;
            else if (x == target)
                equal++;
        }

        List<Integer> ans = new ArrayList<>();

        for (int i = smaller; i < smaller + equal; i++) {
            ans.add(i);
        }

        return ans;
    }
}