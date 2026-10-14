char* maxSumOfSquares(int num, int sum) {
    if (sum == 0 || sum > 9 * num)
        return "";

    char* ans = (char*)malloc((num + 1) * sizeof(char));
    if (ans == NULL) return "";

    int i = 0;

    while (sum >= 9) {
        ans[i++] = '9';
        sum -= 9;
        num--;
    }

    if (sum > 0) {
        ans[i++] = '0' + sum;
        num--;
    }

    while (num-- > 0) {
        ans[i++] = '0';
    }

    ans[i] = '\0';
    return ans;
}