#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
using namespace std::literals;
int main()
{
	// 创建原子布尔变量，表示所有任务是否完成
	std::atomic<bool> all_tasks_completed{ false };

	// 创建原子无符号整数，表示完成的任务数量
	std::atomic<unsigned> completion_count{};

	// 创建包含16个std::future<void>对象的数组，用于存储异步任务的future
	std::future<void> task_futures[16];

	// 创建原子无符号整数，表示未完成的任务数量，初始值为16
	std::atomic<unsigned> outstanding_task_count{ 16 };
	// 生成多个任务，每个任务模拟不同耗时，然后递减未完成任务数量
	for (std::future<void>& task_future : task_futures)
		task_future = std::async([&]
			{
				// 模拟真实工作...
				std::this_thread::sleep_for(50ms);

				// 增加已完成任务数量，递减未完成任务数量
				++completion_count;
				--outstanding_task_count;
				// 当未完成任务数量减至零时，通知等待者（在本例中为主线程）
				if (outstanding_task_count.load() == 0)
				{
					all_tasks_completed = true;
					all_tasks_completed.notify_one();
				}
			});
	// 等待所有任务完成
	all_tasks_completed.wait(false);
	// 输出已完成任务的数量
	std::cout << "Tasks completed = " << completion_count.load() << '\n';
}