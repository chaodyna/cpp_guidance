/**
 * @file 0118_Pascal's_Triangle.cpp
 * @author chaodyna (li0331_1@163.com)
 * @brief
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 * https://leetcode.com/problems/pascals-triangle/description/
 */
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> r(numRows);
    for (int i = 0; i < numRows; i++) {
      r[i].resize(i + 1);
      r[i][0] = r[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
      }
    }
    return r;
  }
};

int main() {
  Solution st;
  int numRow = 5;
  std::vector<std::vector<int>> res = st.generate(numRow);
  std::cout << "the case 2 : " << std::endl;
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < res.size(); ++j) {
      std::cout << res[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
