#include <iostream>
#include <thread>

using std::thread;

void func1()
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "thread 1 running!\n";
	}
}

void func2()
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "thread 2 running!\n";
	}
}

void func3()
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "thread 3 running!\n";
	}
}

int main()
{
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	//t1.join();
	//t2.join();
	//t3.join();

	// even after the main function, it runs to the end
	// main does not wait until they finish
	// some of threads generated before main quits still runs
	t1.detach();
	t2.detach();
	t3.detach();

	// thread without neither detach nor join
	// would crash following c++ standard

	std::cout << "quit main func\n";
	return 0;
}