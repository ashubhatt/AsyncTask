/*
 * ChangeThread.h
 *
 *  Created on: 11-Dec-2018
 *      Author: ashutosh
 */

#ifndef SRC_CHANGETHREAD_H_
#define SRC_CHANGETHREAD_H_

#include <TaskManager.h>

template<typename ... Params>
class ChangeThreadContext {

public:

	template<typename F>
	ChangeThreadContext(F f, TaskManagerPtr tmPtr) :
			task(f) {
		tmPtr->AddTask(f);
	}

private:

	Task<Params...> task;
};


#endif /* SRC_CHANGETHREAD_H_ */
