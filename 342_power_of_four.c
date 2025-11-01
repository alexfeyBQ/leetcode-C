// Problème : 342. Power of Four
// Lien : https://leetcode.com/problems/power-of-four/
// Langage : C
// Approche : Keep dividing n by 4 until we reach 1

bool isPowerOfFour(int n)
{
    if (n <= 0) return false;
    while (n % 4 == 0)
    {
        n /= 4;
    }

    return n == 1;
}
