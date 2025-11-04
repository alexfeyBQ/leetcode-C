**13. Roman to Integer - Using Subtractive Notation Method in C**

## Intuition
Roman numerals use both **additive** and **subtractive** notation:  
- Normally, letters are added: `VI = 5 + 1 = 6`.  
- In subtractive cases, a smaller numeral before a larger numeral is **subtracted**: `IV = 5 - 1 = 4`.  

To convert a Roman numeral to an integer (arabic numerals):  
- Examine each character and compare it with the next one.  
- If the current numeral is smaller than the next → subtract it.  
- Otherwise → add it.  

**Example:**  
- `s = "MCMXCIV"`
- `M(1000) ≥ C(100)` → `+1000`
- `C(100) < M(1000)` → `-100`
- `M(1000) ≥ X(10)` → `+1000`
- `X(10) < C(100)` → `-10`
- `C(100) ≥ I(1)` → `+100`
- `I(1) < V(5)` → `-1`
- `V(5)` → `+5`
- `Result = 1994`

**Note:** It is guaranteed that `s` is a valid Roman numeral in the range `[1, 3999]`.

## Approach
- Define a helper function `value(char c)` to map Roman characters to integers.  
- Initialize `result = 0`.  
- Iterate through the string `s`:  
   - Let `a = value(s[i])` and `b = value(s[i+1])`.  
   - If `a < b` → subtract `a` from `result`.  
   - Otherwise → add `a` to `result`.  
- Return `result` after the loop ends.  

This method works for all valid Roman numerals within the given range.

## Code
```c
int romanToInt(char* s)
{
    int value(char c) // Associate Roman numerals to Arabic numerals
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
        int a = value(s[i]);       // value at current position
        int b = value(s[i + 1]);   // value at next position

        if (a < b)
        {
            result -= a; // subtract if smaller than next
        }
        else
        {
            result += a; // otherwise add
        }
    }

    return result;
}
