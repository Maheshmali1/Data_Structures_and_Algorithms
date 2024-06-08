#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  /**
   * @brief Finds the maximum possible sum of exactly B elements picked from either end of the array.
   *
   * Given an integer array A of size N, this function calculates the maximum possible sum by picking
   * exactly B elements from either the left or right end of the array.
   *
   * @param A The input integer array.
   * @param B The number of elements to pick.
   * @return The maximum possible sum of picked elements.
   */
  int maxSumFromBothSides(vector<int> &A, int B)
  {
    int size = A.size();
    if (B > size)
      return 0; // If B is greater than the array size, return 0 as it's invalid

    // Initialize the sum of the first B elements
    int firstBSum = 0;
    for (int i = 0; i < B; i++)
    {
      firstBSum += A[i];
    }

    int maxSum = firstBSum; // Initialize the maximum sum with the sum of the first B elements

    // Try to include elements from the end one by one while excluding from the start
    for (int i = 0; i < B; i++)
    {
      firstBSum = firstBSum - A[B - 1 - i] + A[A.size() - 1 - i];
      maxSum = max(maxSum, firstBSum);
    }

    return maxSum;
  }
};

/**
 * Approach:
 * - The problem is approached by initially taking the sum of the first B elements.
 * - The idea is to then iteratively replace elements from the start with elements from the end of the array.
 * - For each iteration, the sum is updated by removing one element from the start and adding one from the end.
 * - The maximum sum encountered during these iterations is the answer.

 * Time Complexity:
 * - The time complexity is O(B), where B is the number of elements to pick.
 * - This is because we first calculate the sum of the first B elements in O(B) time and then perform B updates in the second loop.

 * Space Complexity:
 * - The space complexity is O(1) because we only use a few additional variables, and the space used does not depend on the size of the input array.
 */

int main()
{
  Solution solution;

  // Example 1
  vector<int> A1 = {5, -2, 3, 1, 2};
  int B1 = 3;
  int result1 = solution.maxSumFromBothSides(A1, B1);
  cout << "Example 1: Maximum sum of " << B1 << " elements: " << result1 << endl;
  return 0;
}
