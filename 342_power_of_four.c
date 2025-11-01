// Problème : 342. Power of Four
// Lien : https://leetcode.com/problems/power-of-four/
// Langage : C
// Approche : Continuer à diviser n par 4 jusqu'à ce que nous atteignons 1

bool isPowerOfFour(int n)
{
    if (n <= 0) return false;
    while (n % 4 == 0)
    {
        n /= 4;
    }

    return n == 1;
}
