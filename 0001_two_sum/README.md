**1. Two Sum – Brute Force Search in C**

## Intuition

The **Two Sum** problem asks us to find two numbers in an array that add up to a given `target`.
A simple and intuitive way to solve it is by checking **all pairs of elements** until we find the correct sum.

This is known as the **brute force approach**, and although not the most efficient, it is clear and easy to understand.

**Example:**
Input: `nums = [2, 7, 11, 15]`, `target = 9`
→ `2 + 7 = 9` → return indices `[0, 1]`

## Approach

* Allocate memory for an integer array of size 2 to store the answer indices.
* Use a **nested loop**:

  * The outer loop iterates over each element `nums[i]`.
  * The inner loop checks each following element `nums[j]`.
  * If `nums[i] + nums[j] == target`, store indices `[i, j]` in `answer` and return it.
* If no pair is found, return `NULL`.

This guarantees finding the first valid pair that satisfies the equation.

## Code

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* answer = malloc(2 * sizeof(int)); // Allocate memory for result

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                answer[0] = i;
                answer[1] = j;
                *returnSize = 2;
                return answer; // Return indices as soon as match found
            }
        }
    }
    return NULL; // No valid pair found
}
```
