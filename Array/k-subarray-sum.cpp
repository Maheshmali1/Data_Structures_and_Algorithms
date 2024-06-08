#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /**
   * @brief Determines if there exists a subarray of at least size 2 whose elements sum up to a multiple of k.
   *
   * Given an integer array nums and an integer k, the function returns true if there is a subarray
   * of size at least 2 whose sum is a multiple of k, and false otherwise. A subarray is a contiguous
   * part of the array, and an integer x is a multiple of k if there exists an integer n such that x = n * k.
   *
   * @param nums The input integer array.
   * @param k The integer to check multiples against.
   * @return true if there exists a valid subarray, false otherwise.
   */
  bool checkSubarraySum(vector<int> &nums, int k)
  {
    int nsize = nums.size();
    if (nsize < 2)
      return false; // A subarray must have at least two elements

    unordered_map<int, int> mp; // To store remainders and their indices
    mp[0] = -1;                 // Initialize with remainder 0 at index -1 to handle cases where the subarray starts from index 0

    int run_sum = 0; // Running sum of elements
    for (int j = 0; j < nsize; j++)
    {
      run_sum += nums[j]; // Update the running sum
      if (k != 0)
      {
        run_sum = run_sum % k; // Calculate the remainder of the running sum with k
      }
      if (mp.find(run_sum) != mp.end())
      {
        // If the remainder has been seen before and the subarray size is at least 2
        if (j - mp[run_sum] > 1)
        {
          return true; // A valid subarray has been found
        }
      }
      else
      {
        // Store the index of the first occurrence of this remainder
        mp[run_sum] = j;
      }
    }
    return false; // No valid subarray found
  }
};

int main()
{
  vector<int> nums = {23, 2, 4, 6, 7};
  int k = 6;
  Solution obj;
  cout << obj.checkSubarraySum(nums, k) << endl;
  return 0;
}
/**
 * Approach:
 * - The problem is approached using a hashmap to store the remainders of the running sum when divided by k.
 * - The idea is based on the property that if the sums of two subarrays have the same remainder when divided by k,
 *   then the subarray between these two sums must have a sum that is a multiple of k.
 * - We initialize the hashmap with a remainder of 0 at index -1 to handle cases where the subarray starts from the beginning.
 * - As we iterate through the array, we calculate the running sum and its remainder when divided by k.
 * - If this remainder has been seen before and the distance between the current index and the index where the remainder was
 *   first seen is greater than 1, we have found a valid subarray.
 * - Otherwise, we store the current index for this remainder.

 * Time Complexity:
 * - The time complexity is O(n), where n is the number of elements in the input array nums.
 * - This is because we iterate through the array once, and each lookup and insertion in the hashmap takes O(1) on average.

 * Space Complexity:
 * - The space complexity is O(min(n, k)), where n is the number of elements in the input array and k is the value
 *   of the divisor. This is because the hashmap stores at most n different remainders, but if k is smaller, it will store
 *   at most k different remainders.
 */
