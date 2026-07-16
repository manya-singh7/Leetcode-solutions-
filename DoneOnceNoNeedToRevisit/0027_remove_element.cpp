/*
---------------------------------------
Problem: Remove Element
LeetCode: 27

Difficulty:
Easy

Pattern:
Two Pointers

What I first thought:
Traverse the array and remove every occurrence
of the given value.

Problem:
Removing elements using erase() shifts all
remaining elements to the left, making each
removal O(n). In the worst case, this results
in O(n²) time complexity.

Optimized Idea:
Use two pointers.

Time Complexity:
O(n)
- Traverse the array exactly once.

Space Complexity:
O(1)
- Only two integer pointers (indices) are used.
---------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {

    int i = 0;

    for (int j = 0; j < nums.size(); j++) {

        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}

/*
int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int val;
    cout << "Enter value to remove: ";
    cin >> val;

    int k = removeElement(nums, val);

    cout << "\nNumber of remaining elements = " << k << endl;

    cout << "Updated array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
*/