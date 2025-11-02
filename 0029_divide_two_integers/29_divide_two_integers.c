// Problem: 29. Divide Two Integers
// Difficulty: Medium
// Link: https://leetcode.com/problems/divide-two-integers/

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

    // Convert dividend and divisor in positive long long
    long long d = llabs((long long)dividend);
    long long D = llabs((long long)divisor);

    // Initialization
    long long quotient = 0;

    // Main loop
    while (d >= D)
    {
        long long D2 = D;    // Multiple of divisor
        long long multiple = 1; // How many times D2 fits in remaining dividend

        // Double D2 until it exceeds remaining dividend for faster computing
        while ((D2 << 1) <= d)
        {
            D2 <<= 1;   // Double D2
            multiple <<= 1; // Double multiple
        }

        d -= D2;    // Substract largest possible multiple from dividend
        quotient += multiple;   // Add multiple to quotient
    }
    if (negative) return quotient * (-1);
    return quotient;
}
