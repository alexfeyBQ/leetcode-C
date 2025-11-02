// Problem: 326. Power of Three
// Difficulty: Easy
// Link: https://leetcode.com/problems/power-of-three/

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
