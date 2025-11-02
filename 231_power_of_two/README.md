**231. Power of Two - Using Iterative Division Method in C**

# Intuition
To determine if a number `n` is a power of two, we can repeatedly divide it by 2:  

- Powers of two are numbers that can be expressed as `2^k` where `k ≥ 0`.  
- If `n` is a power of two, dividing it by 2 repeatedly should eventually reduce it to 1.  
- If at any step `n` is not divisible by 2, it cannot be a power of two.  

**Example:** 
- `16 → 16/2=8 → 8/2=4 → 4/2=2 → 2/2=1 → true`
- `18 → 18/2=9 → 9 is not divisible by 2 → false`

# Approach
- Check if `n` is positive. Powers of two are always greater than 0.  
- Use a `while` loop to divide `n` by 2 as long as `n % 2 == 0`.  
- After the loop, if `n` equals 1, return `true`. Otherwise, return `false`.  

# Code
```c
bool isPowerOfTwo(int n)
{
    if (n <= 0) return false; // Powers of two must be positive
    
    while (n % 2 == 0) // Keep dividing by 2 while divisible
    {
        n /= 2;
    }

    return n == 1; // If we end up with 1, it was a power of two
}

