**9. Palindrome Number - Using Half Reversal Method in C**

## Intuition
A **palindrome number** reads the same backward and forward, such as `121` or `1331`.  
Reversing the entire number may cause integer overflow and is unnecessary — we only need to reverse **half** of the digits and compare.  
- Negative numbers can never be palindromes (`-121 ≠ 121-`).
- Any number ending with `0` (except `0` itself) cannot be a palindrome because leading zeros are not allowed (`10 ≠ 01`).
- By reversing only half of the number, we can check for symmetry efficiently without using extra memory or converting to a string.

**Example:** 
- $$x = 1221$$
- `→ reverse right half → 12`
- `→ compare left and reversed right halves → 12 == 12 → true`
  
## Approach
- If `x` is negative → not a palindrome.  
- If `x` ends with `0` but is not `0` → not a palindrome.  
**Reverse only half** of the digits:  
   - While the original half `x` is greater than the reversed half `reversed`:  
     - Add the last digit of `x` to `reversed`.  
     - Remove that digit from `x`.  
**Compare halves**:  
   - For even-length numbers, `x == reversed`.  
   - For odd-length numbers, ignore the middle digit → `x == reversed / 10`.  

## Code
```c
bool isPalindrome(int x)
{
    // Avoid negative numbers and numbers ending with 0 (except 0 itself)
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int reversed = 0;

    // Reverse half of the number
    while (x > reversed)
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // Compare the two halves
    return x == reversed || x == reversed / 10;
}

