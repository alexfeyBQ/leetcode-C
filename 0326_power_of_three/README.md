**326. Power of Three - Using Maximum 32-bit Power Method in C**

# Intuition
To check whether a number `n` is a power of three, one method is to use **mathematical properties** instead of iterative loops or recursion:  

- The largest power of three that fits in a 32-bit signed integer is `3^19 = 1162261467`.  
- If `n` is a power of three, it must divide `1162261467` exactly.  
- This approach avoids loops entirely and runs in **O(1) time**.  

**Example:**
- `27 → 1162261467 % 27 == 0 → true`
- `45 → 1162261467 % 45 != 0 → false`

# Approach
- Check if `n` is **positive**. Powers of three are always greater than 0.  
- Divide the largest 32-bit power of three (`1162261467`) by `n`.  
  - If there is no remainder, `n` is a power of three → return `true`.  
  - Otherwise, return `false`.  
- This method works only because 1162261467 is exactly `3^19` and the largest power of three in 32-bit signed integers.  

# Code
```c
bool isPowerOfThree(int n)
{
    // Check if n positive and if n divides largest power of three in 32 bits
    if ((n > 0) && (1162261467 % n == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
