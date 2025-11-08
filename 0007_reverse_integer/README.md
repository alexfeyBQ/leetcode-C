**7. Reverse Integer - Handling Overflow in C**

## Intuition

To reverse an integer, we repeatedly extract its last digit and build a new reversed number.
However, reversing may cause **overflow**, since the reversed integer could exceed the 32-bit signed integer range `[-2³¹, 2³¹ - 1]`.

So, we must **check for overflow** before multiplying or adding digits to the reversed number.

**Example:**

- `x = 123` → `321`
- `x = -456` → `-654`
- `x = 1534236469` → overflow → return `0`

## Approach

- Initialize `reversed = 0`.
- While `x != 0`:

  - Extract the last digit using `x % 10`.
  * Remove the digit with integer division `x /= 10`.
  * Before updating `reversed`, **check if multiplying by 10 would overflow**.
  * If it would overflow, return `0`.
  * Otherwise, update `reversed = reversed * 10 + digit`.
* Return the final `reversed` integer.

## Code

```c
int reverse(int x)
{
    int reversed = 0;
    while (x != 0)
    {
        int digit = x % 10; // Determine last digit
        x /= 10; // Remove last digit

        // Prevent overflow
        if (reversed > INT_MAX / 10 || reversed == INT_MAX) return 0;
        if (reversed < INT_MIN / 10 || reversed == INT_MIN) return 0;

        reversed = reversed * 10 + digit; // Add digit
    }
    return reversed;
}
```
