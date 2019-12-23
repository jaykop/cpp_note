#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <sstream>
#include <cstring>

#include "BSTree.h"
#include "AVLTree.h"

using std::cout;
using std::endl;

//*********************************************************************
// Printing/Debugging
//*********************************************************************
static int Position;
template <typename T>
void SetTreePositions(const typename BSTree<T>::BinTreeNode *tree, 
                      int depth, 
                      std::map<const typename BSTree<T>::BinTreeNode *, 
                      std::pair<int, int> >& NodePositions)
{
  if (!tree)
    return;

  SetTreePositions<T>(tree->pLeft, depth + 1, NodePositions);
  std::pair<int, int>XY(Position++, depth);
  std::pair<const typename BSTree<T>::BinTreeNode *, std::pair<int, int> > pr(tree, XY);
  NodePositions.insert(pr);
  SetTreePositions<T>(tree->pRight, depth + 1, NodePositions);
}

template <typename T>
void SetTreePositions(const BSTree<T> &tree, 
                      std::map<const typename BSTree<T>::BinTreeNode *, 
                      std::pair<int, int> >& NodePositions)
{
  Position = 0;
  NodePositions.clear();
  SetTreePositions<T>(tree.Root(), 0, NodePositions);
}

template <typename T>
std::vector<std::pair<const typename BSTree<T>::BinTreeNode *, int> >
GetNodesAtLevel(int level, 
                std::map<const typename BSTree<T>::BinTreeNode *, 
                std::pair<int, int> >& NodePositions)
{
  std::vector<std::pair<const typename BSTree<T>::BinTreeNode *, int> >nodes;
  typename std::map<const typename BSTree<T>::BinTreeNode *, std::pair<int, int> >::iterator it;
  for (it = NodePositions.begin(); it != NodePositions.end(); ++it)
  {
    std::pair<int, int>XY = it->second;
    if (XY.second == level)
    {
      std::pair<const typename BSTree<T>::BinTreeNode *, int> pr( it->first, XY.first);
      nodes.push_back(pr);
    }
  }
  return nodes;
}  

template <typename T>
bool SortNodes(const std::pair<const typename BSTree<T>::BinTreeNode *, int>&a, 
               const std::pair<const typename BSTree<T>::BinTreeNode *, int>&b)
{
  if (a.second < b.second)
    return true;
  else
    return false;
}

template <typename T>
class fSortNodes
{
public:
  bool operator()(const std::pair<const typename BSTree<T>::BinTreeNode *, int>&a, 
                  const std::pair<const typename BSTree<T>::BinTreeNode *, int>&b)
  {
    if (a.second < b.second)
      return true;
    else
      return false;
  }
};

template <typename T>
void PrintBST(const BSTree<T> &tree)
{
  std::map<const typename BSTree<T>::BinTreeNode *, std::pair<int, int> > NodePositions;

  SetTreePositions(tree, NodePositions);
  int height = tree.height();
  int offset = 0;
  for (int i = 0; i <= height; i++)
  {
    std::vector<std::pair<const typename BSTree<T>::BinTreeNode *, int> >nodes = GetNodesAtLevel<T> (i, NodePositions);
    // Borland doesn't like the function, wants a function object
    //std::sort(nodes.begin(), nodes.end(), SortNodes<T>);
    std::sort(nodes.begin(), nodes.end(), fSortNodes<T>());
    typename std::vector<std::pair<const typename BSTree<T>::BinTreeNode *, int> >::iterator iter;
    char buffer[1024 * 2] = {0};
    std::memset(buffer, ' ', 1024 * 2);

    for (iter = nodes.begin(); iter != nodes.end(); ++iter)
    {
      //char data[60] = {0};
      T value = (*iter).first->data;
      //std::sprintf(data, "%g", value);  // <<**>>

      std::stringstream ss;
      ss << value;

      offset = (height / 2) + iter->second * 3;  // fudge factor (change to 4 for big numbers)
      //strncpy(buffer + offset, data, strlen(data));
      strncpy(buffer + offset, ss.str().c_str(), ss.str().length());
    }
    buffer[offset + 4] = 0; // should handle 4 digits easily
    std::cout << buffer << std::endl << std::endl;
  }
}

template <typename T>
void PrintInfo(const T& tree)
{
  std::cout << "type: " << typeid(tree).name() << ", height: " << tree.height();
  std::cout << ", nodes: " << tree.size() << std::endl;
}

//*********************************************************************
// End Printing/Debugging
//*********************************************************************

int RandomInt(int low, int high)
{
  return std::rand() % (high - low + 1) + low;
}

template <typename T>
void SwapInt(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <typename T> void Shuffle(T *array, int count, int stride = 1)
{
  for (int i = 0; i < count; i += stride)
  {
    int r = RandomInt(0, count - 1);
    SwapInt(array[i], array[r]);
  }
}

void GetValues(int *array, int size)
{
  std::srand(1);
  for (int i = 0; i < size; i++)
    array[i] = i;

  Shuffle(array, size);
}

template <typename T>
void Test1(void)
{
  T tree;
  const int size = 10;
  int vals[size];
  GetValues(vals, size);
  const char *test = "Test1 - random insert";

  std::cout << "\n====================== " << test << " ======================\n";
  std::cout << typeid(T).name() << std::endl;
  try
  {
    for (int i = 0; i < size; i++)
      tree.insert(vals[i]);
    std::cout << "height: " << tree.height() << std::endl;
    std::cout << " nodes: " << tree.size() << std::endl;
    if (tree.empty())
      std::cout << "tree is empty\n\n";
    else
      std::cout << "tree is NOT empty\n\n";

    PrintBST(tree);
  }
  catch (const BSTException &e)
  {
    std::cout << "Caught BSTException in " << test;
    int value = e.code();
    if (value == BSTException::E_DUPLICATE)
      std::cout << "E_DUPLICATE" << std::endl;
    else if (value == BSTException::E_NO_MEMORY)
      std::cout << "E_NO_MEMORY" << std::endl;
    else
      std::cout << "Unknown error code." << std::endl;
  }
  catch (...)
  {
    std::cout << "Caught unknown exception in " << test << std::endl;
  }
}

template <typename T>
void Test2(void)
{
  T tree;
  const int size = 10;
  const char *test = "Test2 - sorted insert";

  std::cout << "\n====================== " << test << " ======================\n";
  std::cout << typeid(T).name() << std::endl;
  try
  {
    for (int i = 0; i < size; i++)
      tree.insert(i);
    std::cout << "height: " << tree.height() << std::endl;
    std::cout << " nodes: " << tree.size() << std::endl;
    if (tree.empty())
      std::cout << "tree is empty\n\n";
    else
      std::cout << "tree is NOT empty\n\n";

    PrintBST(tree);
  }
  catch (const BSTException &e)
  {
    std::cout << "Caught BSTException in " << test;
    int value = e.code();
    if (value == BSTException::E_DUPLICATE)
      std::cout << "E_DUPLICATE" << std::endl;
    else if (value == BSTException::E_NO_MEMORY)
      std::cout << "E_NO_MEMORY" << std::endl;
    else
      std::cout << "Unknown error code." << std::endl;
  }
  catch (...)
  {
    std::cout << "Caught unknown exception in " << test << std::endl;
  }
}

template <typename T>
void Test3(void)
{
  T tree;
  const int size = 10;
  int vals[size];
  GetValues(vals, size);
  const char *test = "Test3 - random insert/remove";

  std::cout << "\n====================== " << test << " ======================\n";
  std::cout << typeid(T).name() << std::endl;
  try
  {
    for (int i = 0; i < size; i++)
      tree.insert(vals[i]);
  
    PrintBST(tree);
    std::cout << "remove 2, 6, 3:\n";
    tree.remove(2);
    tree.remove(6);
    tree.remove(3);

    std::cout << "height: " << tree.height() << std::endl;
    std::cout << " nodes: " << tree.size() << std::endl;
    if (tree.empty())
      std::cout << "tree is empty\n\n";
    else
      std::cout << "tree is NOT empty\n\n";

    PrintBST(tree);
  }
  catch (const BSTException &e)
  {
    std::cout << "Caught BSTException in " << test;
    int value = e.code();
    if (value == BSTException::E_DUPLICATE)
      std::cout << "E_DUPLICATE" << std::endl;
    else if (value == BSTException::E_NO_MEMORY)
      std::cout << "E_NO_MEMORY" << std::endl;
    else
      std::cout << "Unknown error code." << std::endl;
  }
  catch (...)
  {
    std::cout << "Caught unknown exception in " << test << std::endl;
  }
}

template <typename T>
void Test4(void)
{
  T tree;
  const int size = 10;
  int vals[size];
  GetValues(vals, size);
  const char *test = "Test4 - random insert/remove all";

  std::cout << "\n====================== " << test << " ======================\n";
  std::cout << typeid(T).name() << std::endl;
  try
  {
    for (int i = 0; i < size; i++)
      tree.insert(vals[i]);

    std::cout << "remove all and then some:\n";

    for (int i = 0; i < size + 2; i++)
      tree.remove(i);

    std::cout << "height: " << tree.height() << std::endl;
    std::cout << " nodes: " << tree.size() << std::endl;
    if (tree.empty())
      std::cout << "tree is empty\n\n";
    else
      std::cout << "tree is NOT empty\n\n";

    PrintBST(tree);
  }
  catch (const BSTException &e)
  {
    std::cout << "Caught BSTException in " << test;
    int value = e.code();
    if (value == BSTException::E_DUPLICATE)
      std::cout << "E_DUPLICATE" << std::endl;
    else if (value == BSTException::E_NO_MEMORY)
      std::cout << "E_NO_MEMORY" << std::endl;
    else
      std::cout << "Unknown error code." << std::endl;
  }
  catch (...)
  {
    std::cout << "Caught unknown exception in " << test << std::endl;
  }
}

template <typename T>
void Test5(void)
{
  T tree;
  const int size = 10;
  int vals[size];
  GetValues(vals, size);
  const char *test = "Test5 - random insert/clear";

  std::cout << "\n====================== " << test << " ======================\n";
  std::cout << typeid(T).name() << std::endl;
  try
  {
    for (int i = 0; i < size; i++)
      tree.insert(vals[i]);

    std::cout << "clear:\n";
    tree.clear();

    std::cout << "height: " << tree.height() << std::endl;
    std::cout << " nodes: " << tree.size() << std::endl;
    if (tree.empty())
      std::cout << "tree is empty\n\n";
    else
      std::cout << "tree is NOT empty\n\n";

    PrintBST(tree);
  }
  catch (const BSTException &e)
  {
    std::cout << "Caught BSTException in " << test;
    int value = e.code();
    if (value == BSTException::E_DUPLICATE)
      std::cout << "E_DUPLICATE" << std::endl;
    else if (value == BSTException::E_NO_MEMORY)
      std::cout << "E_NO_MEMORY" << std::endl;
    else
      std::cout << "Unknown error code." << std::endl;
  }
  catch (...)
  {
    std::cout << "Caught unknown exception in " << test << std::endl;
  }
}

template <typename T>
void Test6(void)
{
  T tree;
  const int size = 10;
  int vals[size];
  GetValues(vals, size);
  const char *test = "Test6 - random insert/find";

  std::cout << "\n====================== " << test << " ======================\n";
  std::cout << typeid(T).name() << std::endl;
  try
  {
    for (int i = 0; i < size; i++)
      tree.insert(vals[i]);

    PrintBST(tree);
    int value;
    unsigned compares;
    bool found;

    value = 1;
    compares = 0;
    found = tree.find(value, compares);
    if (found)
      std::cout << "Value " << value << " found with " << compares << " compares\n";
    else
      std::cout << "Value " << value << " NOT found with " << compares << " compares\n";

    value = 3;
    compares = 0;
    found = tree.find(value, compares);
    if (found)
      std::cout << "Value " << value << " found with " << compares << " compares\n";
    else
      std::cout << "Value " << value << " NOT found with " << compares << " compares\n";

    value = 5;
    compares = 0;
    found = tree.find(value, compares);
    if (found)
      std::cout << "Value " << value << " found with " << compares << " compares\n";
    else
      std::cout << "Value " << value << " NOT found with " << compares << " compares\n";

    value = 50;
    compares = 0;
    found = tree.find(value, compares);
    if (found)
      std::cout << "Value " << value << " found with " << compares << " compares\n";
    else
      std::cout << "Value " << value << " NOT found with " << compares << " compares\n";
  }
  catch (const BSTException &e)
  {
    std::cout << "Caught BSTException in " << test;
    int value = e.code();
    if (value == BSTException::E_DUPLICATE)
      std::cout << "E_DUPLICATE" << std::endl;
    else if (value == BSTException::E_NO_MEMORY)
      std::cout << "E_NO_MEMORY" << std::endl;
    else
      std::cout << "Unknown error code." << std::endl;
  }
  catch (...)
  {
    std::cout << "Caught unknown exception in " << test << std::endl;
  }
}

#include <string>
template <typename T>
void TestStrings(void)
{
  const char *test = "TestStrings";
  std::cout << "\n====================== " << test << " ======================\n";

  try
  {
    T tree;

    const char *strs[] = {"abe", "for", "fad", "one", "two", "six", "box", 
                          "zoo", "car", "dog", "dig", "fat", "fav", "hit", 
                          "cab", "abd", "sox", "man", "boy", "sow", "abc",
    };

    int size = sizeof(strs) / sizeof(*strs);
    for (int i = 0; i < size; i++)
      tree.insert(strs[i]);

    PrintInfo(tree);
    PrintBST(tree);

#if 1
    unsigned compares;
    bool found;
    std::string value = "dig";
    compares = 0;
    found = tree.find(value, compares);
    if (found)
      std::cout << "Value " << value << " found with " << compares << " compares\n";
    else
      std::cout << "Value " << value << " NOT found with " << compares << " compares\n";

    value = "abe";
    compares = 0;
    found = tree.find(value, compares);
    if (found)
      std::cout << "Value " << value << " found with " << compares << " compares\n";
    else
      std::cout << "Value " << value << " NOT found with " << compares << " compares\n";

    value = "hot";
    compares = 0;
    found = tree.find(value, compares);
    if (found)
      std::cout << "Value " << value << " found with " << compares << " compares\n";
    else
      std::cout << "Value " << value << " NOT found with " << compares << " compares\n";

    value = "abcd";
    compares = 0;
    found = tree.find(value, compares);
    if (found)
      std::cout << "Value " << value << " found with " << compares << " compares\n";
    else
      std::cout << "Value " << value << " NOT found with " << compares << " compares\n";
#endif
  }
  catch (const BSTException &e)
  {
    std::cout << "Caught BSTException in: " << test << ": ";
    int value = e.code();
    if (value == BSTException::E_DUPLICATE)
      std::cout << "E_DUPLICATE" << std::endl;
    else if (value == BSTException::E_NO_MEMORY)
      std::cout << "E_NO_MEMORY" << std::endl;
    else
      std::cout << "Unknown error code." << std::endl;
  }
  catch(...)
  {
    std::cout << "Unknown exception." << std::endl;
  }
}

int main(void)
{
  typedef int T;
  typedef std::string U;

  Test1<BSTree<T> >();
  Test2<BSTree<T> >();
  Test3<BSTree<T> >();
  Test4<BSTree<T> >();
  Test5<BSTree<T> >();
  Test6<BSTree<T> >();
  Test1<AVLTree<T> >();
  Test2<AVLTree<T> >();
  Test3<AVLTree<T> >();
  Test4<AVLTree<T> >();
  Test5<AVLTree<T> >();
  Test6<AVLTree<T> >();
  TestStrings<BSTree<U> >();
  TestStrings<AVLTree<U> >();

  return 0;
}
