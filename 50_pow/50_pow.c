// Problem: 50. Pow(x, n)
// Difficulty: Medium
// Link: https://leetcode.com/problems/powx-n/

double myPow(double x, int n)
{
    double X = 1.0;
    long N = n;

    if (N == 0) return 1;
    
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }

    while (N > 0)
    {
        if (N % 2 == 1)
        {
            X *= x;

        }
        x *= x;
        N /= 2;
    }
    return X;
}
