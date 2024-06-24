int searchInsert(int* nums, int numsSize, int target) {
    int index;
    if(target < nums[0]) {
        return 0;
    }
    
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == target) {
            index = i;
            return index;
        }
    }

    for(int j = 0; j < numsSize; j++) {
        if(j < numsSize-1) {
            if(target > nums[j] && target < nums[j+1]) {
                return index = j + 1;
            }
        }

        if(j == numsSize - 1) {
            index = numsSize;
        }
    }

    return index;
}
