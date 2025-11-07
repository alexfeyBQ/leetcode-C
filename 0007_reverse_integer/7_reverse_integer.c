// Problem: 7. Reverse Integer
// Difficulty: Medium
// Link: https://leetcode.com/problems/reverse-integer/

int reverse(int x)
{
    int reversed = 0;
    while (x != 0)
    {
        int digit = x % 10; // Determine last digit
        x /= 10; // Remove last digit

        // Prevent overflow
        if (reversed > INT_MAX / 10 || reversed == INT_MAX) return 0;
        if (reversed < INT_MIN / 10 || reversed == INT_MIN) return 0;

        reversed = reversed * 10 + digit; // Add digit
    }
    return reversed;
}
