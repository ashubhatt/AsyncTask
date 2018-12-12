/*
 * main.cpp
 *
 *  Created on: 11-Dec-2018
 *      Author: ashutosh
 */

#include "AsyncTask.h"

void SampleFunction(int x) {

	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cerr << "\nSampleFunction(" << x << ")\n";

}


int main() {
	{
		TaskManagerPtr tmPtr = std::make_shared<TaskManager>();
		AsyncTask<int> myTask(SampleFunction, tmPtr);

		if (!myTask.IsEmpty())
			myTask(5);
	}
	while (1) {
		std::cerr << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
	return 0;
}

