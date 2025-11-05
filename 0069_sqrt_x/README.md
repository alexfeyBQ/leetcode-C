**69. Sqrt(x) - Using Iterative Method in C**

## Intuition

To compute the integer square root of a number `x`:

* We want the largest integer `a` such that `a * a ≤ x`.
* Simply iterating from `1` upwards and checking `a * a` works, but we need to be careful with **overflow** for large `x`.

**Example:**

* `x = 8` → `1*1 = 1 ≤ 8`, `2*2 = 4 ≤ 8`, `3*3 = 9 > 8` → return `3 - 1 = 2`

## Approach

* Start with `a = 1`.
* While `a * a ≤ x` (cast to `long long` to avoid overflow), increment `a`.
* Once `a * a > x`, return `a - 1` as the integer square root.

## Code

```c
int mySqrt(int x)
{
    // Start from 1
    int a = 1;

    // Repeat until a² exceeds x & cast a to long long to avoid overflow
    while ((long long)a * a <= x) a++;

    // Return integer part of √x
    return a - 1;
}
```
