// Problem: 9. Palindrome Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/palindrome-number/

bool isPalindrome(int x)
{
    // Avoid Negative numbers and numbers ending with 0 (except 0 itself)
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int reversed = 0;

    // Reverse half of the number
    while (x > reversed)
    {
        reversed = reversed * 10 + x % 10, x /= 10;
    }
    // Compare the two halves
    return x == reversed || x == reversed / 10;
}
