#include <string.h>
#include <stdlib.h>

// Macro for finding the maximum of two integers
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Helper function to check if the substring s[left...right] is a palindrome
int isPalindrome(char *s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return 0; // false
        }
        left++;
        right--;
    }
    return 1; // true
}

int maxPalindromes(char * s, int k) {
    int n = strlen(s);
    
    // Dynamically allocate the DP array and initialize to 0
    int* dp = (int*)calloc(n + 1, sizeof(int));
    if (!dp) return 0; // safety check for memory allocation
    
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        
        // Check for length k
        if (i >= k && isPalindrome(s, i - k, i - 1)) {
            dp[i] = MAX(dp[i], dp[i - k] + 1);
        }
        // Check for length k + 1
        if (i >= k + 1 && isPalindrome(s, i - k - 1, i - 1)) {
            dp[i] = MAX(dp[i], dp[i - k - 1] + 1);
        }
    }
    
    int result = dp[n];
    
    // Free the allocated memory to prevent memory leaks
    free(dp);
    
    return result;
}