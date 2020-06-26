#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end,
	int* result)
{
	int sum = 0;
	// sum up specific intervals
	for (auto it = start; it != end; ++it)
		sum += *it;

	*result = sum;

	thread::id this_id = std::this_thread::get_id();

	// why no cout?
	// test it out!
	// - cout is not thread-safe!
	/*std::cout << "thread id: " << this_id
		<< "from " << *start
		<< "to " << *(end - 1)
		<< " - sum: " << sum << std::endl;*/

	printf("thread id: %x from %d to %d - sum: %d\n",
		this_id, *start, *(end - 1), sum);
}

int main()
{
	const int num_of_threads = 4;
	const int data_size = 10000;
	const int offset = data_size / num_of_threads;

	vector<int> data(data_size);
	for (int i = 0; i < data_size; ++i)
		data[i] = i;

	vector<int> partial_sums(num_of_threads);
	vector<thread> workers;

	// here assign 4 workers
	for (int i = 0; i < num_of_threads; ++i)
		workers.push_back(thread(
			worker, 
			data.begin() + i * offset,
			data.begin() + (i + 1) * offset,
			&partial_sums[i]));

	for (int i = 0; i < num_of_threads; ++i)
		workers[i].join();

	int total = 0;
	for (int i = 0; i < num_of_threads; ++i)
		total += partial_sums[i];

	std::cout << "total sum: " << total << "\n";

	return 0;
}