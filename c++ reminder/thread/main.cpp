#include <thread>
#include <iostream>
#include <vector>

struct B
{
	int count;
};

class A
{
public :
	void count(B* b) { std::cout << b->count << std::endl; }
	void run()
	{
		B b;
		b.count = 10;
		
		std::vector<std::thread> v;
		std::thread t(&A::count, this, &b);
		v.emplace_back(t);

		for (auto& th : v)
			th.join();
	}
};


int main()
{
	A b;
	b.run();

	return 0;
}