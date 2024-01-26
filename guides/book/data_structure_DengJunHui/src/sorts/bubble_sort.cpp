/**
 * @file bubble_sort.cpp
 * @author chaodyna (li0331_1@163.com)
 * @brief 整数数组的起泡排序
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>


// TODO:Hello
void bubbleSort1A(int A[], int n) { // 起泡排序算法(版本1A):0<=n
  bool sorted = false; // 整体排序标志, 首先假定尚未排序
  while(!sorted) { // 在尚未确认已全局排序之前，逐趟进行扫描交换
    sorted = true;  // 假定已经排序
    for(int i = 1; i < n; i++) {  // 自左向右逐对检查当前范围A[0, n)内的各相邻元素
      if(A[i - 1] > A[i]) {  // 一旦A[i - 1]与A[i]逆序，则
        std::swap(A[i - 1], A[i]);   // 交换之，并
        sorted = false;   // 因整体排序不能保证，需要清除排序标志
      }
    }
    n--;  // 至此末元素必然就位，故可以缩短待排序序列的有效长度
  }
}  // 借助布尔型标志位sorted，可及时提前退出，而不致总是蛮力地做n - 1趟扫描交换