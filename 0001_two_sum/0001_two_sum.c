// Problem: 1. Two Sum
// Difficulty: Easy
// Link: https://leetcode.com/problems/two-sum/

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* answer = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                answer[0] = i;
                answer[1] = j;
                *returnSize = 2;
                return answer;
            }
        }
    }
    return NULL;
}
