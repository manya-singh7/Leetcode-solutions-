/*
---------------------------------------
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/

Difficulty: Easy

Pattern:
Hash Map

What I first thought:
Brute Force:
For every element,
search the remaining array for the complement.

Time : O(n²)
Space: O(1)

Optimized Idea:
Store previous numbers in an unordered_map.

Key = value
Value = index

Algorithm:
1. need = target - nums[i]
2. If need exists in hashmap
      return stored index and current index
3. Else
      store current value and index

Time : O(n)
Space : O(n)

Lessons Learned

• unordered_map searches using the KEY, not the VALUE.

• The KEY is hashed.
  The hash function computes a bucket number and
  directly jumps to that bucket.

• Average Complexity
      Search : O(1)
      Insert : O(1)

• Traversing once = O(n)

• Searching repeatedly = O(n²)

• Store value -> index.

• Search before inserting.

Recognition Clues

- Pair
- Complement
- Seen before
- Return indices

=> Think Hash Map

---------------------------------------
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
    vector<int> TwoSum ( vector<int> & nums, int target) {
        unordered_map <int,int> mp;
        for (int i=0; i<nums.size(); i++) {
            int need=target-nums[i];
            if (mp.find(need)!=mp.end()) {
                return {mp[need],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};