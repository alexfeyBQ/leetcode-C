**12. Integer to Roman – Using Greedy Method in C**

## Intuition

To convert an integer to a Roman numeral:

* Roman numerals use **specific symbols** for certain values: `I=1, IV=4, V=5, IX=9, X=10`, etc.
* The largest symbol should always be used first (greedy approach).
* Subtractive notation is handled naturally by including values like `900 (CM)` or `4 (IV)` in the symbol list.

**Example:**

* `num = 1994`
* Start with largest symbol ≤ num:

  * `1000 (M)` → subtract → `num = 994` → append `M`
  * `900 (CM)` → subtract → `num = 94` → append `CM`
  * `90 (XC)` → subtract → `num = 4` → append `XC`
  * `4 (IV)` → subtract → `num = 0` → append `IV`
* Result: `"MCMXCIV"`

## Approach

* Define arrays of values and corresponding Roman symbols in **descending order**.
* Initialize an empty string `result`.
* Iterate through the values:

  * While `num >= value[i]`:

    * Append `symbol[i]` to `result`.
    * Subtract `value[i]` from `num`.
* Continue until `num` reaches 0.
* Return the final `result`.

This greedy approach ensures that the Roman numeral is built **from largest to smallest symbols**, respecting standard notation rules.

## Code

```c
char* intToRoman(int num)
{
    static char result[32];
    result[0] = '\0';

    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    for (int i = 0; i < 13; i++)
    {
        while (num >= value[i])
        {
            strcat(result, symbol[i]);
            num -= value[i];
        }
    }

    return result;
}
```
