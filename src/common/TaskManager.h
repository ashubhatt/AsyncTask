/*
 * AsyncTask.h
 *
 *  Created on: 10-Dec-2018
 *      Author: ashutosh
 */

#ifndef SRC_TASKMANAGER_H_
#define SRC_TASKMANAGER_H_

#include <Task.h>

class TaskManager {
public:
	TaskManager() {
		workInProgress.store(false);
		keepWorkerRunning = true;
		workerThread = std::thread(std::bind(&TaskManager::DoWork, this));
	}

	~TaskManager() {
		StopWork();
	}

	template<typename ... Params>
	void AddTask(Task<Params...> task, Params&& ... params) {
		auto func = std::bind(task, params...);

		taskQueue.push(func);
		if (!workInProgress.load())
			sleepyTask.notify_one();
	}

	template<typename Func, typename ... Params>
	void AddTask(Func fn, Params&&... params) {
		std::function<std::result_of_t<Func(Params...)>()> rFunc = std::bind(fn,
				params...);

		taskQueue.push(rFunc);
		if (!workInProgress.load())
			sleepyTask.notify_one();
	}

	void StopWork() {
		keepWorkerRunning = false;
		sleepyTask.notify_one();
	}

private:
	void DoWork() {
		while (keepWorkerRunning) {
			// Check if queue has any data
			if (!taskQueue.empty() && taskQueue.size() > 0) {
				workInProgress.store(true);

				// Fetch the task and run it
				auto task = taskQueue.front();
				task();

				// Remove from queue in the end
				taskQueue.pop();

			} else {
				// No data; wait for some data
				workInProgress.store(false);
				std::unique_lock<std::mutex> uniLock(mutex);
				sleepyTask.wait(uniLock);
			}
		}
	}

private:
	std::queue<std::function<void(void)>> taskQueue;

	std::thread workerThread;
	std::atomic<bool> workInProgress;
	bool keepWorkerRunning;
	std::condition_variable sleepyTask;
	std::mutex mutex;
};

typedef std::shared_ptr<TaskManager> TaskManagerPtr;

#endif /* SRC_TASKMANAGER_H_ */
