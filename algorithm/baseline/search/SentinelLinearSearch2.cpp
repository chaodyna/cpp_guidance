#include <iostream>
#include <vector>

int sentinelLinearSearch(std::vector<int> array, int key)
{
  int last = array[array.size() - 1];
  array[array.size() - 1] = key;
  int i = 0;
  while(array[i] != key)
  {
    i++;
  }
  array[array.size() - 1] = last;
  if(i < array.size() - 1 || last == key)
  {
    return i;
  }
  else
  {
    return -1;
  }
}

int main()
{
  std::vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int key = 5;
  int index = sentinelLinearSearch(array, key);
  if(index == -1)
  {
    std::cout << key << " is not found in the array. " << std::endl;
  }
  else
  {
    std::cout << key << " is found at index " << " in the array. " << std::endl;
  }
  return 0;
}