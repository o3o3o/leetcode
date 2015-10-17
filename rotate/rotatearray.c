/*
 *
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 */
void rotate(int* nums, int numsSize, int k) {

    int i, n = k % numsSize;
    int t;
    int *tn;
    if(!n || k < 0)
        return;
    tn = malloc(numsSize*sizeof(int));
    memset(tn, 0 , numsSize*sizeof(int));

    //1. move step by step
    //2. new array and set
    for(i=numsSize-1; i>=0; i--){
        tn[(i+n)%numsSize] = nums[i];
    }

    for(i=0;i<numsSize;i++){
        nums[i] = tn[i];
    }
    free(tn);
}
