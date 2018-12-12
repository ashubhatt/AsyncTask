/*
 * main.cpp
 *
 *  Created on: 11-Dec-2018
 *      Author: ashutosh
 */

#include "Task.h"

void SampleFunction(int x) {

	std::cerr << "\nSampleFunction(" << x << ")\n\n";

}


int main() {

	Task<int> task(SampleFunction);

	task(123);

	while (1) {
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
	return 0;
}

