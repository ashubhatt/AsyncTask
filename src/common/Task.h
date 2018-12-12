/*
 * Task.h
 *
 *  Created on: 11-Dec-2018
 *      Author: ashutosh
 */

#ifndef SRC_TASK_H_
#define SRC_TASK_H_

#include <bits/stdc++.h>

template<typename ... Params>
class Task {
private:
	typedef std::function<void(const Params& ...)> FunctionType;

public:

	~Task() = default;

	template<typename F>
	Task(const F& func) :
			func(func) {
	}

	void operator()(const Params&... params) {
		Run(params...);
	}

	void Run(const Params&... params) {
		if (func)
			func(params...);
	}

	bool IsEmpty() {
		return (!func);
	}

private:
	FunctionType func;
};

#endif /* SRC_TASK_H_ */
