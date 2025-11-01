// Problem: 231. Power of Two
// Link: https://leetcode.com/problems/power-of-two/
// Approach: Divide n by 2 until we reach 1

bool isPowerOfTwo(int n)
{
    if (n <= 0) return false;
    while (n % 2 == 0)
    {
        n /= 2;
    }

    return n == 1;
}
