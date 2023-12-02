#include<stdlib.h>
#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *temp;
    int *final;
    int i = 0;
    int count = 0;
    int sum = 0;
  for (int i = 0; i< numsSize;i++){
    sum = nums[i];
    count = 0;
    temp = malloc(sizeof(int) *numsSize);
    temp[count++] = i;
    for (int j = i+1; i< numsSize;i++)
    {
        if( nums[j]<target && sum+nums[j]<=target)
        {
            sum+=nums[j];
            temp[count++] = j;
            if(sum==target)
            {
                final = malloc(sizeof(int) *count);
                for(int l =0; l<count;l++)
                 {
                    final[l] = temp[l];
                    // printf("%d\n",temp[l]);
                 }
                    *returnSize = count;
                free(temp);
                  return (final);
            }

        }
    }
    free(temp);
  }
  return (0);
}
int main()
{
    int temp;
    int *temp2;
    temp2 = twoSum((int []){1,2,3},3,3,&temp);
    for (size_t i = 0; i < 2; i++)
    {
        printf("%d\n",temp2[i]);
    }
    

}