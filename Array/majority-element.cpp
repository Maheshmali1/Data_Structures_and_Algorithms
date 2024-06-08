#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  /**
   * @brief Finds the majority element in the given array.
   *
   * Given an array nums of size n, this function returns the majority element.
   * The majority element is the element that appears more than ⌊n / 2⌋ times.
   *
   * @param nums The input array of integers.
   * @return The majority element.
   */
  int majorityElement(vector<int> &nums)
  {
    int majorityInd = 0;     // Initialize majority index to the first element
    int cnt = 1;             // Initialize count of majority element occurrences
    int nsize = nums.size(); // Size of the array
    for (int i = 1; i < nsize; i++)
    {
      if (nums[i] == nums[majorityInd])
      {
        cnt++; // Increment count if the current element matches the majority element
      }
      else
      {
        cnt--; // Decrement count if the current element is different from the majority element
      }

      if (cnt == 0)
      {
        // If count becomes zero, update the majority index and reset count to 1
        majorityInd = i;
        cnt = 1;
      }
    }
    return nums[majorityInd]; // Return the majority element
  }
};

/**
 * Approach:
 * - The problem is approached using the Boyer-Moore Voting Algorithm.
 * - We initialize the majority index and count.
 * - We iterate through the array, updating the count and majority index accordingly.
 * - If the count becomes zero, we update the majority index to the current element.
 * - Finally, we return the element at the majority index.
 *
 * Time Complexity:
 * - The time complexity is O(n), where n is the size of the input array.
 * - This is because we iterate through the array once to find the majority element.
 *
 * Space Complexity:
 * - The space complexity is O(1) because we use only a few additional variables.
 */

int main()
{
  Solution solution;

  // Example
  vector<int> nums = {3, 2, 3};
  int majorityElementAns = solution.majorityElement(nums);
  cout << "Majority element: " << majorityElementAns << endl;

  return 0;
}
