// Problem: 12. Integer to Roman
// Difficulty: Medium
// Link: https://leetcode.com/problems/integer-to-roman/

char* intToRoman(int num)
{
    static char result[32]; // static so it can be safely returned
    result[0] = '\0';

    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    for (int i = 0; i < 13; i++) // Value has 13 values in total, operate from largest to smallest value
    {
        while (num >= value[i])
        {
            strcat(result, symbol[i]); // Add symbol at position i
            num -= value[i]; // Subtract num by value at position i
        }
    }
    return result;
}
