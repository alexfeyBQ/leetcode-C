// Problem: 2169. Count Operations to Obtain Zero
// Difficulty: Easy
// Link: https://leetcode.com/problems/count-operations-to-obtain-zero/

int countOperations(int num1, int num2)
{
    int counter = 0; // Number of operations
  
    // Repeat until one of the two int is 0
    // Subtract smallest value from biggest value
    while (num1 != 0 && num2 != 0)
    {
        if (num1 >= num2)
        {
            num1 -= num2;
        }
        else
        {
            num2 -= num1;
        }   
        counter++; // Add 1 to count the number of operations
    }
    return counter; // Return the number of operations
}
