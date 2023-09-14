#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

int in[10100]; // 存入度
vector<int> v[10100]; // 存关系 构件图

int main()
{
  int m, n;
  int x, y;
  while(cin >> n >> m) // 根据题目要求可以改动
  {
    memset(in, 0, sizeof(in)); // 清空入度
    for(int i = 1; i <= n; i++)
    {
      v[i].clear(); // 清空vector
    }
    while(m--)  // m组数据
    {
      cin >> y >> x;
      in[y]++; // y的关系大于x，x指向y y的入度+1
      v[x].push_back(y); // 就y放进x后面
    }
    queue<int> q;  // 定义一个队列 最后为节点的删除
    for(int i = 1; i <= n; i++)
    {
      if(!in[i])
      { // 入度为零的节点放入 队列
        q.push(i);
      }
    }
    while(!q.empty())
    {
      int xx =  q.front();  // 如果队列中一次存了大于1个节点
      q.pop();              // 说明该图有 2->3 && 2->4 这种情况 有点个点之间没有关系
      n--;                  // 总节点数 -1;
      for(int i = 0; i < v[xx].size(); i++)
      {  // 遍历这个节点后面的一点
        int yy = v[xx][i];
        in[yy]--;           // 删除 x 后 yy 的入度数 -1;
        if(!in[yy])
        {  // 如果此时 yy 入度为零放入队列 遍历它的下一个节点
          q.push(yy);
        }
      }
    }
    if(n)
    {
      cout << "该图有环" << endl;  // 如果总结点数没减为零 说明有环的存在
    }
  }
  return 0;
}