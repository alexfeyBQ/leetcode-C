**2169. Count Operations to Obtain Zero – Using Iterative Subtraction Method in C**

## Intuition
The problem asks how many operations are required to make **either of two integers zero**, where in each operation you subtract the **smaller** number from the **larger** one.  

This is conceptually similar to the **Euclidean algorithm** for computing the greatest common divisor (GCD), except that instead of using division, we count every subtraction step individually.

**Example:**
- Input: `num1 = 5`, `num2 = 2`
- Steps:
  - 5 ≥ 2 → 5 - 2 = 3 → count = 1  
  - 3 ≥ 2 → 3 - 2 = 1 → count = 2  
  - 2 ≥ 1 → 2 - 1 = 1 → count = 3  
  - 1 ≥ 1 → 1 - 1 = 0 → count = 4  
- Output: `4`

So the number of operations is **4**.

---

## Approach
- Initialize a counter `counter = 0`.  
- While both `num1` and `num2` are **non-zero**:
  - Subtract the smaller value from the larger value.  
  - Increment `counter` each time.  
- Once one of them becomes zero, return the counter.  

This simple loop ensures each subtraction step is tracked correctly.

# Code
```c []
int countOperations(int num1, int num2)
{
    int counter = 0; // Number of operations
  
    // Repeat until one of the two int is 0
    // Subtract smallest value from biggest value
    while (num1 != 0 && num2 != 0)
    {
        if (num1 >= num2)
        {
            num1 -= num2;
        }
        else
        {
            num2 -= num1;
        }   
        counter++; // Add 1 to count the number of operations
    }
    return counter; // Return the number of operations
}
```
