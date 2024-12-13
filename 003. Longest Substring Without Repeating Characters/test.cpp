#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution
{
public:
    int lengthOfLongestSubstring(const std::string &s)
    {
        std::unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end)
        {
            char currentChar = s[end];

            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start)
            {
                start = charIndexMap[currentChar] + 1;
            }

            charIndexMap[currentChar] = end;

            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main()
{
    std::string s;
    std::cout << "Digite a string: ";
    std::cin >> s;

    Solution solution;
    int result = solution.lengthOfLongestSubstring(s);
    std::cout << "O comprimento da maior substring sem caracteres repetidos é: " << result << std::endl;

    return 0;
}
