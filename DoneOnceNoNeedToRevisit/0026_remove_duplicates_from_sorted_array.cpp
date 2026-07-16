/*
---------------------------------------
Problem: Remove Duplicates from Sorted Array
LeetCode: 26

Difficulty:
Easy

Pattern:
Two Pointers

What I first thought:
Convert the array into a set to remove duplicates,
then copy the unique elements back into the array.

Time : O(n log n)
Space: O(n)

Optimized Idea:
Since the array is already sorted,
duplicates are always adjacent.

Use two pointers:
i -> Points to the last unique element.
j -> Traverses the array.

Whenever nums[j] is different from nums[i]:
1. Increment i.
2. Copy nums[j] to nums[i].

The first (i + 1) elements of the array
will contain all unique elements.

Time Complexity:
O(n)
- The array is traversed exactly once.

Space Complexity:
O(1)
- Only two integer pointers (indices) are used.
---------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {

    if (nums.size() == 1) {
        return 1;
    }

    int i = 0;

    for (int j = 1; j < nums.size(); j++) {

        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

/*
int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    cout << "\nNumber of unique elements = " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
*/