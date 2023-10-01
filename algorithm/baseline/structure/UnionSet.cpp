/**
 * @file UnionSet.cpp
 * @author chaodyna (li0331_1@163.com)
 * @brief
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> parent;
  std::vector<int> rank;
  int Find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  bool Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX == rootY) {
      return false;
    } else {
      if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
      } else if (rank[rootY] > rank[rootX]) {
        parent[rootX] = rootY;
      } else {
        parent[rootX] = rootY;
        rank[rootY]++;
      }
    }
    return true;
  }
  std::vector<int>
  findRedundantConnection(std::vector<std::vector<int>> &edges) {
    for (int i = 0; i <= edges.size(); i++) {
      parent.push_back(i);
      rank.push_back(0);
    }

    for (int i = 0; i < edges.size(); i++) {
      if (!Union(edges[i][0], edges[i][1])) {
        return std::vector<int>{edges[i][0], edges[i][1]};
      }
    }
    return {};
  }
};