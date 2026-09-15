class Solution {
    public int maxPalindromes(String s, int k) {
        int n = s.length();
        int[] dp = new int[n + 1];
        char[] chars = s.toCharArray(); // Convert to array for faster lookups
        
        for (int i = 1; i <= n; i++) {
            // Base case: carry over the previous optimal state
            dp[i] = dp[i - 1];
            
            // Check for length k
            if (i >= k && isPalindrome(chars, i - k, i - 1)) {
                dp[i] = Math.max(dp[i], dp[i - k] + 1);
            }
            // Check for length k + 1
            if (i >= k + 1 && isPalindrome(chars, i - k - 1, i - 1)) {
                dp[i] = Math.max(dp[i], dp[i - k - 1] + 1);
            }
        }
        
        return dp[n];
    }
    
    // Helper method to check if a specific range in the char array is a palindrome
    private boolean isPalindrome(char[] chars, int left, int right) {
        while (left < right) {
            if (chars[left] != chars[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}