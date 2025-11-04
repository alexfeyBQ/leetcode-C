// Problem: 13. Roman to Integer
// Difficulty: Easy
// Link: https://leetcode.com/problems/roman-to-integer/

int romanToInt(char* s)
{
    int value(char c) // Associate roman numerals to arabic numerals
    {
        switch (c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int result = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int a = value(s[i]); // value at current position
        int b = value(s[i + 1]); // value at nextt position

        if (a < b)
        {
            result -= a; // ex: starting at i = 0: IV → I (1) < V (5) → a < b → subtract 1 → "IV = -1"
        }
        else
        {
            result += a; // ex: i = 1: IV → V (5) >= I (1) → a > b → add 5 → IV = 4
        }
    }
    return result;
}
