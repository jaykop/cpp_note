#include <vector>
#include <iostream>
#include <chrono>

// recursive
int r_fibonacci(int a)
{

    if (a < -1)
        return -1;

    else if (a == 0 || a == 1)
        return 1;

    return r_fibonacci(a - 1) + r_fibonacci(a - 2);
}

int d_fibonacci(int a)
{

    static std::vector<int> list = {1, 1};

    if (a == 0 || a == 1)
        return list[a];

    else
    {

        // if a is out of list,
        // generate new one
        if (int(list.size() <= a))
        {

            // increase the size of vector
            list.resize(a + 1, 0);

            list[a] = d_fibonacci(a - 1) + d_fibonacci(a - 2);
        }

        // unless
        else
        {

            // check if the data has been calculated
            if (list[a] == 0)
                list[a] = d_fibonacci(a - 1) + d_fibonacci(a - 2);
        }

        //
        return list[a];
    }
}

int main(int argc, char **argv)
{

    int a = atoi(argv[1]);

    auto begin1 = std::chrono::steady_clock::now();
    int result = r_fibonacci(a);
    auto end1 = std::chrono::steady_clock::now();

    std::cout << result << "\n";
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() << "ns" << std::endl;

    auto begin2 = std::chrono::steady_clock::now();
    result = d_fibonacci(a);
    auto end2 = std::chrono::steady_clock::now();

    std::cout << result << "\n";
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() << "ns" << std::endl;
    return 0;
}