**29. Divide Two Integers - Using Bit Manipulation and Doubling Method in C**

# Intuition
To divide two integers without using multiplication, division, or modulo operators, we can leverage **bit manipulation and doubling**:  

- Division is essentially **repeated subtraction**. For example, `10 / 3` is repeatedly subtracting 3 until the remainder is less than 3.  
- Simple repeated subtraction is too slow for large numbers, so we **double the divisor** and count how many times it fits into the dividend, which speeds up the process exponentially.  
- Handling **signs** and **edge cases** (like `INT_MIN / -1`) is crucial to avoid overflow.  

**Example:**
- `dividend = 15, divisor = 3`
- `15 - 3*4 = 3 → quotient = 4 + 1 = 5`


# Approach
**Handle special cases**:  
   - If `divisor == 0`, return `INT_MAX`.  
   - If `dividend == INT_MIN` and `divisor == -1`, return `INT_MAX` to prevent overflow.  
- **Determine the sign** of the quotient using XOR: negative if exactly one of dividend/divisor is negative.  
- **Convert dividend and divisor to positive long long** to safely handle `INT_MIN`.  
- **Main loop**:  
   - While the remaining dividend is greater than or equal to the divisor:  
     - Start with `D2 = divisor` and `multiple = 1`.  
     - Double `D2` and `multiple` until `D2 << 1` exceeds the remaining dividend.  
     - Subtract `D2` from the dividend and add `multiple` to the quotient.  
- **Apply the sign** to the final quotient.  

This method runs faster because each doubling inside the main loop reduces the remaining dividend exponentially.  

# Code
```c
int divide(int dividend, int divisor)
{
    // Avoid division by zero
    if (divisor == 0) return INT_MAX;

    // Avoid overflow
    if (dividend == INT_MIN)
    {
        if (divisor == 1) return dividend;
        if (divisor == -1) return INT_MAX;
    }

    // Sign of quotient
    bool negative = dividend < 0 ^ divisor < 0;

    // Convert dividend and divisor to positive long long
    long long d = llabs((long long)dividend);
    long long D = llabs((long long)divisor);

    // Initialization
    long long quotient = 0;

    // Main loop
    while (d >= D)
    {
        long long D2 = D;         // Multiple of divisor
        long long multiple = 1;    // How many times D2 fits in remaining dividend

        // Double D2 until it exceeds remaining dividend for faster computing
        while ((D2 << 1) <= d)
        {
            D2 <<= 1;              // Double D2
            multiple <<= 1;         // Double multiple
        }

        d -= D2;                   // Subtract largest possible multiple from dividend
        quotient += multiple;       // Add multiple to quotient
    }

    if (negative) return -quotient;
    return quotient;
}
