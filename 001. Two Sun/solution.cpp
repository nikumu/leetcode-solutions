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