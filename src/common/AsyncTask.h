/*
 * AsyncTask.h
 *
 *  Created on: 11-Dec-2018
 *      Author: ashutosh
 */

#ifndef SRC_ASYNCTASK_H_
#define SRC_ASYNCTASK_H_

#include <TaskManager.h>

template<typename ... Params>
class AsyncTask {
public:

	AsyncTask() {
		isInitialized = false;
	}

	~AsyncTask() = default;

	template<typename F>
	AsyncTask(F f, TaskManagerPtr tmPtr) :
			task(f), tmPtr(tmPtr) {
		isInitialized = true;
	}

	void operator()(const Params&... params) {
		Run(params...);
	}

	void Run(const Params&... params) {
		tmPtr->AddTask(task, params...);
	}

	bool IsEmpty() {
		return task.IsEmpty();
	}

private:
	TaskManagerPtr tmPtr;
	Task<Params...> task;
	bool isInitialized;
};

#endif /* SRC_ASYNCTASK_H_ */
