/*
---------------------------------------
Problem: Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/

Difficulty: Easy

Pattern:
String Traversal

Topics:
Strings
2D Traversal

Brute Force Idea:
Compare every string with every other string and keep
updating the common prefix.

Time : O(n² × m)
Space: O(1)

Optimized Idea:
Use the first string as the reference.
Traverse it character by character.
For every character, compare it with the character at the
same index in every other string.

If every string has the same character:
    Add it to the answer.

Otherwise:
    Return the answer immediately.

Algorithm:
1. Store the answer in an empty string.
2. Traverse the first string character by character.
3. For each character position i:
      Traverse every other string.
4. If any string:
      - ends, OR
      - has a different character,
   return the answer.
5. Otherwise append the character.
6. Return the answer after the loop finishes.

Time Complexity:
O(n × m)

where

n = number of strings
m = length of the shortest string (worst case)

Reason:

Outer Loop:
Runs for every character position.

Worst case:
The common prefix is as long as the shortest string.

≈ m iterations

Inner Loop:
For every character position,
we compare that character with every other string.

≈ n comparisons

Total:

O(m) × O(n)
= O(n × m)

Example:

["flower","flow","flight"]

Total work is proportional to
(number of strings × characters checked).

Space Complexity:
O(1)

Reason:
Only a few variables are used.
(The returned answer string is not counted as extra space.)

Recognition Clues:

- Compare characters at the SAME index.
- Prefix always starts from index 0.
- Stop immediately on the first mismatch.
- Multiple strings need to be compared.

Lessons Learned:


• vector<string> is NOT a 2D vector.

  Type:
      vector<string>

  However, it behaves like a 2D grid of characters because:

      strs[0]
          ↓
      returns a string

  and strings themselves are indexable and traversible 

  Therefore:

      strs[0][2]

  means

      first string
      third character

  Similarly,

      strs[j][i]

  means

      j -> which string (row)
      i -> which character (column)

  Think of it as:

          0 1 2 3 4
  flower  f l o w e
  flow    f l o w
  flight  f l i g h

• Use the first string as the reference.
  Every common prefix must also be a prefix of
  the first string.

• We compare every string with the FIRST string.
  There is no need to compare
      strs[1] with strs[2],
      strs[2] with strs[3], etc.

  If every string matches the first string,
  then they all match each other.

• ans += strs[0][i];

  appends one character to the answer.

Mistakes I Made:

• Initially thought I'd need many if-else cases.

• Thought of finding the shortest string first.

• Didn't understand why

      i == strs[j].size()

  is checked before

      strs[j][i].

  Learned that it prevents accessing an invalid index.

• Confused i with the string number.

  Learned:

      i -> character index (column)

      j -> string index (row)

Interview Takeaway:

Whenever multiple strings are involved,
think of them as rows and compare characters
column-by-column.

Don't compare every pair of strings.
Use one string as the reference.


---------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
    public:
    string longestCommonPrefix (vector<string>& strs) {
        string ans="";

        for (int i=0; i<strs[0].size(); i++) {
            for (int j=1; j<strs.size(); j++) {
                if (i==strs[j].size()||strs[j][i]==strs[0][i]) {
                    return ans;
                }
            }
            ans=ans+strs[0][i];
        }
        return ans;
    }
};

/*int main() {

    Solution sol;

    vector<string> strs = {
        "flower",
        "flow",
        "flight"
    };

    cout << "Longest Common Prefix: "
         << sol.longestCommonPrefix(strs) << endl;

    return 0;
}*/