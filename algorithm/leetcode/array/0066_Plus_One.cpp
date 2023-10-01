/**
 * @file 0066_Plus_One.cpp
 * @author chaodyna (li0331_1@163.com)
 * @brief
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 * https://leetcode.com/problems/plus-one/
 */

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    for (int i = digits.size(); i--; digits[i] = 0) {
      if (digits[i]++ < 9) {
        return digits;
      }
    }
    digits[0]++;
    digits.push_back(0);
    return digits;
  }
};

int main() {
  Solution st;
  std::vector<int> num = {4, 3, 2, 1};
  std::vector<int> res = st.plusOne(num);
  std::cout << "case 2: " << std::endl;
  std::cout << "the res is: " << std::endl;
  for (int i = 0; i < res.size(); ++i) {
    std::cout << " " << res[i];
  }
  return 0;
}