/*
 * main.cpp
 *
 *  Created on: 11-Dec-2018
 *      Author: ashutosh
 */

#include "common/ChangeThreadContext.h"

TaskManagerPtr tmPtr = std::make_shared<TaskManager>();


void SampleFunction(int x) {

	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cerr << "\nSampleFunction(" << x << ")\n";
	x++;
	ChangeThreadContext<int> thread(std::bind(SampleFunction, x), tmPtr);

}

int main() {

	SampleFunction(5);

	while (1) {
		std::cerr << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
	return 0;
}

