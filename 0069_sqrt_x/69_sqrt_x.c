// Problem: 69. Sqrt(x)
// Difficulty: Easy
// Link: https://leetcode.com/problems/sqrtx/

int mySqrt(int x)
{
    // Start from 1
    int a = 1;

    // Repeat until a² exceeds x & cast a to long long to avoid overflow
    while ( (long long)a * a <= x) a++;

    // Return integer part of √x
    return a - 1;
}
