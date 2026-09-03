typedef struct {
    int* prefix;
    int size;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->prefix = (int*)malloc((numsSize+1) * sizeof(int));
    obj->size = numsSize-1;

    obj ->prefix[0]= 0;
    for(int i=0 ; i< numsSize ; i++){
        obj->prefix[i+1] = obj->prefix[i] + nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->prefix[right+1] - obj->prefix[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->prefix);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/