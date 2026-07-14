/*
---------------------------------------
Problem: Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/

Difficulty: Easy

Pattern:
Hash Map + String Traversal (that's what I thought but this turned out to be different)

Topics:
Hash Map
String
Switch Case

Brute Force Idea:
Use multiple if-else statements to check all Roman numeral
combinations (IV, IX, XL, XC, CD, CM).

Time : O(n)
Space: O(1)

Optimized Idea:
Store each Roman numeral and its value in an unordered_map.
Traverse the string once and compare the current value with
the next value.

If current < next:
    subtract current
Else:
    add current

Finally, add the last Roman numeral since it has no next
character to compare with.

Algorithm:
1. Create an unordered_map<char, int>.
2. Store all Roman numeral values.
3. Traverse the string from index 0 to size()-2.
4. Get the current and next values from the hashmap.
5. If current < next, subtract current.
6. Otherwise, add current.
7. Add the last Roman numeral.
8. Return the answer.

Time Complexity:
O(n)

Reason:
- Creating the hashmap stores only 7 fixed values → O(1).
- We traverse the string exactly once.
- Each unordered_map lookup is O(1) average.
- Total = O(n).

Space Complexity:
O(1)

Reason:
The hashmap always stores exactly 7 key-value pairs,
regardless of input size.

Recognition Clues:
- Characters map to values.
- Need fast character -> value lookup.
- Compare adjacent elements.
- Traverse string only once.

Lessons Learned:

• Accessing:
      mp[key]
  returns the value of that key.

• If a key doesn't exist,
      mp[key]
  creates it with a default value (0 for int).

• Instead of memorizing all six subtraction cases
  (IV, IX, XL, XC, CD, CM),
  use one rule:

      current < next


• Prefer .size() over .length() because .size() works
  for strings, vectors, maps, sets and most STL containers.

• s.back() returns the last character of a string.
  Equivalent to:

      s[s.size() - 1]

• For a small fixed mapping (7 Roman numerals),
  switch is usually faster than unordered_map,
  which is usually faster than a long if-else chain.

Mistakes I Made:

• Initially thought many if-else statements were needed.

• Realized all subtraction cases are covered by one rule:
      current < next.
If you write:

for (int i : s)

it works, but i is not the index.

It is the character's ASCII value.

For example:

string s = "ABC";

for (int i : s) {
    cout << i << " ";
}

Output:

65 66 67

->Rule of thumb

Use a range-based for loop when you only need each element:

for (int x : nums)
for (char c : s)

Use an index-based loop when you need:

the index,
the next/previous element,
or to modify specific positions.

->
Lesson to remember
mp[key] → looks up the key, but creates it with a default value if it's missing.
mp.find(key) → checks whether the key exists without inserting anything.
mp.at(key) → retrieves the value, but throws an error if the key doesn't exist.
---------------------------------------

• switch is often faster than unordered_map when mapping
  a very small fixed set of values.

• Strings can be traversed like arrays:
      s[i]
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
    int value(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
        int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.size() - 1; i++) {

            int current = value(s[i]);
            int next = value(s[i + 1]);

            if (current < next)
                ans -= current;
            else
                ans += current;
        }
        ans+=value(s.back());
        return ans;
    }
};