#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{
public:
    Vector(size_t size) : size_(size)
    {
        data_ = new T[size_];
        for (int i = 0; i < size_; i++)
        {
            data_[i] = 3;
        }
    }

    // at returns the value of n-th index, just like [] operator,
    // but at returns it as a const value so does not let modify it.
    const T &at(size_t index) const
    {
        if (index >= size_ || index < 0)
        {
            // Regradless of the return type of the function,
            // this can stop and point out where the exception throw happened
            // * and also std expcetion removes all the stacks to reach this step,
            // so it can release the memory properly...
            throw std::out_of_range("index is out of range");
        }
        return data_[index];
    }
    ~Vector() { delete[] data_; }

private:
    T *data_;
    size_t size_;
};

void c_tpye_example () {

    // malloc returns NULL when it failed to assign a memory
    char *c = (char *)malloc(10000000000);
    if (c == NULL) {
        std::cout << "Error from memory assignment!\n";
        // return -1;
    }
}

int main(void)
{

    // * in c....
    c_tpye_example();
    
    // * in c++?
    Vector<int> vec(3);

    int index, data = 0;
    std::cin >> index;

    try // this covers codes that might cause a problem,
    {
        data = vec.at(index);
    }
    // if nothing happened from "try" -> ignore "catch" part
    // * if a problem happened, all the stacks get removed,
    // * operator jumps to the closest "catch" part.
    catch (std::out_of_range &e /*std::exception& e*/)
    {
        // http://www.cplusplus.com/reference/exception/exception/what/
        std::cout << "exception throw: " << e.what() << std::endl;
    }
    // correct output -> 3
    // incorrect output -> 0
    std::cout << "data read : " << data << std::endl;

    return 0;
}