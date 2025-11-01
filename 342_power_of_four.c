// Problem: 342. Power of Four
// Link: https://leetcode.com/problems/power-of-four/

bool isPowerOfFour(int n)
{
    if (n <= 0) return false;
    while (n % 4 == 0)
    {
        n /= 4;
    }

    return n == 1;
}
