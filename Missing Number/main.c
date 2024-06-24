int missingNumber(int* nums, int numsSize) {
    int num = numsSize;
    int prog = 0;
    int sum = 0;
    for(int i = 1; i <= num; i++) {
        prog += i;
    }
    for(int i = 0; i < num; i++) {
        sum += nums[i];
    }

    return prog - sum;
}
