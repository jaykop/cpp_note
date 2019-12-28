#include <iostream>
#include <stdexcept>

class Resource
{
public:
    // * If exception thrwon inside a constructor, it does not call destructor of it. 
    // * So need to release manually inside the catch part
    Resource(int id) : id_(id) {}
    ~Resource() { std::cout << "Release res: " << id_ << std::endl; }

private:
    int id_;
};

int func3()
{
    Resource r(3);
    // once thrown, it jumps to the closest catch
    // * "only" calling all the stack destructors.
    throw std::runtime_error("Exception from fuction 3!\n");
}
int func2()
{
    Resource r(2);
    func3();
    std::cout << "executed!" << std::endl;
    return 0;
}
int func1()
{
    Resource r(1);
    func2();
    std::cout << "executed!" << std::endl;
    return 0;
}

int main()
{
    try
    {
        func1();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception : " << e.what();
    }
}