/*
---------------------------------------
Problem: Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/

Difficulty: Easy

Pattern:
Math

Topics:
Math
Integer Manipulation

Brute Force Idea:
Convert the integer to a string and compare
characters from both ends.

Time : O(d)
Space: O(d)

Optimized Idea:
Reverse the integer mathematically and compare
it with the original number.

Algorithm:
1. Negative numbers are never palindromes.
2. Store the original number.
3. Reverse the digits using % and /.
4. Compare original and reversed number.

Time : O(d)
Space: O(1)
where d is the number of digits in the given number

Recognition Clues:
- Reverse digits
- Integer manipulation
- Palindrome
- No strings allowed

Lessons Learned:

• The last digit of a number is obtained using:
      x % 10

• Remove the last digit using:
      x /= 10

• Reverse a number:
      reversed = reversed * 10 + digit

• Keep a copy of the original number before
  modifying it.

• A negative number can never be a palindrome.

• This solution reverses the entire number.
  The interview-optimal solution reverses only
  half the digits to avoid integer overflow.

---------------------------------------
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers are never palindromes
        if (x < 0)
            return false;

        int original = x;
        long long reversed = 0;

        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};