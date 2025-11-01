**258. Add Digits - Repeated Digit Summation Approach in C**
# Intuition
To add the digits of an integer, we first convert it into a string. This allows us to access each digit individually as a character. We then sum the digits, and if the resulting sum has more than one digit, we repeat the process until we are left with a single digit. This single digit is the digital root of the original number.

# Approach
- Declare char ``num_str[32]`` to hold the string representation of the integer. This is large enough to store any ``32-bit`` integer, including the null terminator and potential negative sign.

- Repeat until one digit remains: Use a ``while (1)`` loop that continues until the number has only one digit.

- Convert integer to string: Use ``sprintf(num_str, "%d", num)`` to convert the integer num to a string.

- Use ``strlen(num_str)`` to determine if the number is already a single digit. If so, break the loop.

- Iterate over each character in the string, convert it to an integer with ``num_str[i] - '0'``, and add it to ``digit_sum``.

- Set ``num = digit_sum`` and repeat the process.
- Example: ``38 → 3 + 8 = 11 → 1 + 1 = 2 → return 2``.

# Code
```c []
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
```
