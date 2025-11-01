// Problème : 231. Power of Two
// Lien : https://leetcode.com/problems/power-of-two/
// Langage : C
// Approche : Continuer à diviser n par 2 jusqu'à ce que nous atteignons 1

bool isPowerOfTwo(int n)
{
    if (n <= 0) return false;
    while (n % 2 == 0)
    {
        n /= 2;
    }

    return n == 1;
}
