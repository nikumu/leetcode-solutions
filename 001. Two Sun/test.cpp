#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> complement_map;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (complement_map.find(complement) != complement_map.end())
            {
                return {complement_map[complement], i};
            }

            complement_map[nums[i]] = i;
        }

        return {};
    }
};

// Test the solution
int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test case 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test case 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test case 3: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}
