#include <iostream>
#include <thread>
#include <vector>

using std::vector;
using std::thread;

const int count = 10000;
const int num_of_workers = 4;

void worker(int& counter)
{
	for (int i = 0; i < count; ++i)
		counter += 1;
}

int main()
{
	int counter = 0;

	vector<thread> workers;
	for (int i = 0; i < num_of_workers; ++i)
		workers.emplace_back(thread(worker, std::ref(counter)));
	
	for (int i = 0; i < num_of_workers; ++i)
		workers[i].join();

	std::cout << "Final counter: " << counter << std::endl;

	return 0;
}