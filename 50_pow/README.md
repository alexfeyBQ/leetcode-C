**Using Exponentiation by Squaring in C**
# Intuition
Multiplying `x` by itself `n` times is slow and will **time out for large `n`**.  
We use **exponentiation by squaring** to reduce the number of multiplications by exploiting the properties of even and odd exponents.

We recall:
**By definition,**
- A number `a` is **even** if it is divisible by 2. Then there exists an integer `n` such that $$a = 2n$$.  
- A number `a` is **odd** if it is not divisible by 2. Then there exists an integer `n` such that $$a = 2n + 1$$.  

**Corollaries:**  
- If `n` is even, $$n = 2k$$ and then $$x^n = x^{2k} = (x^k)^2$$

- If `n` is odd, $$n = 2k + 1$$ and then $$x^n = x^{2k+1} = x \cdot (x^k)^2$$

This reduces the number of multiplications from $$O(n) → O(log(n))$$, making the algorithm efficient even for very large `n`.

# Approach
- Case `n = 0`,  return `1`, by definition `x^0 = 1`.
- Case `n < 0`, invert `x` and convert `n` to positive with `N = -N`.
- Case `n > 0`, if `N` is odd, multiply `X` by the current base `x`.
- Square the base `x`.
- Halve `N`.

# Code
```c []
double myPow(double x, int n)
{
    double X = 1.0;
    long N = n;

    if (N == 0) return 1;
    
    if (N < 0)
    {
        x = 1 / x; // Invert x
        N = -N;    // Convert n to positive
    }

    while (N > 0)
    {
        if (N % 2 == 1) // Multiply X by x if N is odd
        {
            X *= x;

        }
        x *= x; // Square the base
        N /= 2; // Halve N
    }
    return X;
}

```
