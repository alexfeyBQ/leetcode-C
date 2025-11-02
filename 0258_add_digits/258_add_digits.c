// Problem: 258. Add Digits
// Difficulty: Easy
// Link: https://leetcode.com/problems/add-digits/

// String-based approach
int addDigits(int num)
{
    char num_str[32];

    while (1)
    {
        int digit_sum = 0;
        sprintf(num_str, "%d", num);
        int length = strlen(num_str);
        
        if (length == 1)
        {
            break;
        }

        for (int i = 0; i < length; i++)
        {
            digit_sum += num_str[i] - '0';
        }

        num = digit_sum;
    }

    return num;
}
