int findNumberOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int dp[numsSize];
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }

    int maxLength = 1;
    int result = 0;

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (dp[i] == maxLength) {
            result++;
        }
    }

    return result;
}