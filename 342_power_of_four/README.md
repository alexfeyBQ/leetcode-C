**342. Power of Four - Using Iterative Division Method in C**

# Intuition
To check whether a number `n` is a power of four, we can repeatedly divide it by 4:  

- Powers of four are numbers that can be expressed as `4^k` where `k ≥ 0`.  
- If `n` is a power of four, dividing it by 4 repeatedly should eventually reduce it to 1.  
- If at any step `n` is not divisible by 4, it cannot be a power of four.  

Example:  
- `16 → 16/4=4 → 4/4=1 → true`  
- `64 → 64/4=16 → 16/4=4 → 4/4=1 → true`  
- `8 → 8/4=2 → 2 is not divisible by 4 → false`

# Approach
- Check if `n` is positive. Powers of four are always greater than 0.  
- Use a `while` loop to divide `n` by 4 as long as `n % 4 == 0`.  
- After the loop, if `n` equals 1, return `true`. Otherwise, return `false`.  

# Code
```c
bool isPowerOfFour(int n)
{
    if (n <= 0) return false; // Powers of four must be positive
    
    while (n % 4 == 0) // Keep dividing by 4 while divisible
    {
        n /= 4;
    }

    return n == 1; // If we end up with 1, it was a power of four
}
