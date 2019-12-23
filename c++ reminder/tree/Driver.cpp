#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <typeinfo>
#include <sstream>
#include <cstring>


#include "BSTree.h"
#include "AVLTree.h"

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

//*********************************************************************
// End Printing/Debugging
//*********************************************************************

template <typename T>
void VisitNode(const typename BSTree<T>::BinTreeNode* tree)
{
  std::cout << tree->data << std::endl;
}

template <typename T>
void TraverseInOrder(const typename BSTree<T>::BinTreeNode* tree)
{
  if (tree == 0)
    return;
  else
  {
    TraverseInOrder(tree->pLeft);
    VisitNode(tree);
    TraverseInOrder(tree->pRight);
  }
}

template <typename T>
void dump(const T& tree)
{
  TraverseInOrder(tree->root());
}

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

template <typename T>
void Shuffle(T *array, int count, int stride = 1)
{
  for (int i = 0; i < count; i += stride)
  {
    int r = RandomInt(0, count - 1);
    SwapInt(array[i], array[r]);
  }
}

template <typename T>
void Print(T *array, int count)
{
  for (int i = 0; i < count; i++)
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

template <typename T, typename U>
void TestTree(const std::vector<U>& values)
{
  T tree;
  for (unsigned i = 0; i < values.size(); i++)
    tree.insert(values[i]);

  std::cout << "------------------------------\n";
  std::cout << "height: " << tree.height() << std::endl;
  std::cout << " nodes: " << tree.size() << std::endl << std::endl;
  PrintBST(tree);
}


template <typename T>
void PrintInfo(const T& tree)
{
  std::cout << "type: " << typeid(tree).name() << ", height: " << tree.height();
  std::cout << ", nodes: " << tree.size() << std::endl;
}


template <typename T, typename U>
void TestSorted(int offset = 0)
{
  std::vector<U> values;
  for (int i = 0 + offset; i < 15 + offset; i++)
    values.push_back(static_cast<U>(i));
  TestTree<T>(values);
  std::cout << "-------------------------------\n";
}

void SimpleTest1(void)
{
  typedef int T;
  std::vector<T> values;
  values.push_back(2);
  values.push_back(4);
  values.push_back(6);
  values.push_back(10);
  values.push_back(8);
  values.push_back(22);
  values.push_back(12);
  values.push_back(9);
  values.push_back(19);
  values.push_back(20);
  values.push_back(7);

  TestTree<BSTree<T>, T>(values);
  std::cout << "-------------------------------\n";
  TestTree<AVLTree<T> >(values);
}

template <typename T, typename U>
void SimpleTest2(int offset)
{
  U ia[] = {2, 4, 6, 10, 8, 22, 12, 9, 19, 20};
  int size = sizeof(ia) / sizeof(*ia);

  for (int i = 0; i < size; i++)
    ia[i] = static_cast<U>(ia[i] + static_cast<U>(offset));
  
  T tree;
  try
  {
    for (int i = 0; i < size; i++)
      tree.insert(ia[i]);

    PrintInfo(tree);
    PrintBST(tree);

    U value = static_cast<U>(19 + static_cast<U>(offset));
    unsigned compares = 0;
    if (tree.find(value, compares))
      std::cout << value << " was found after " << compares << " compares.\n";
    else
      std::cout << value << " was not found after " << compares << " compares.\n";

    value = static_cast<U>(21 + static_cast<U>(offset));
    compares = 0;
    if (tree.find(value, compares))
      std::cout << value << " was found after " << compares << " compares.\n";
    else
      std::cout << value << " was not found after " << compares << " compares.\n";
    

    tree.remove(ia[3]);
    PrintInfo(tree);
    PrintBST(tree);

    tree.remove(ia[0]);
    tree.remove(ia[4]);
    tree.remove(ia[6]);
    PrintInfo(tree);
    PrintBST(tree);

    if (tree.empty())
      std::cout << "Tree is empty.\n";
    else
      std::cout << "Tree is not empty.\n";

    tree.clear();
    if (tree.empty())
      std::cout << "Tree is empty.\n";
    else
      std::cout << "Tree is not empty.\n";

    value = static_cast<U>(10 + static_cast<U>(offset));
    compares = 0;
    if (tree.find(value, compares))
      std::cout << value << " was found after " << compares << " compares.\n";
    else
      std::cout << value << " was not found after " << compares << " compares.\n";

    tree.insert(static_cast<U>(5 + static_cast<U>(offset)));
    value = static_cast<U>(10 + static_cast<U>(offset));
    compares = 0;
    if (tree.find(value, compares))
      std::cout << value << " was found after " << compares << " compares.\n";
    else
      std::cout << value << " was not found after " << compares << " compares.\n";

    PrintInfo(tree);
    tree.remove(static_cast<U>(20 + static_cast<U>(offset)));
    PrintInfo(tree);
  }
  catch(const BSTException& e)
  {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  catch(...)
  {
    std::cout << "Unknown exception." << std::endl;
  }

  try
  {
    tree.insert(static_cast<U>(5 + static_cast<U>(offset)));
  }
  catch(const BSTException& e)
  {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
}

void AVLInsertRemoveTest(void)
{
  const char *p = "DIGPENSTUOCHLY";
  size_t size = strlen(p);

  AVLTree<char> tree;
  try
  {
    for (size_t i = 0; i < size; i++)
      tree.insert(p[i]);

    PrintInfo(tree);
    PrintBST(tree);

    while (!tree.empty())
    {
      BSTree<char>::BinTreeNode *node = tree.Root();
      char letter = node->data;
      tree.remove(letter);
      PrintInfo(tree);
      PrintBST(tree);
    }
  }
  catch(const BSTException& e)
  {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  catch(...)
  {
    std::cout << "Unknown exception." << std::endl;
  }
}

void AVLStress(void)
{
  int *ia = 0;
  try
  {
    AVLTree<int> tree;

    int size;
    if (AVLTree<int>::ImplementedBalanceFactor())
      size = 1000000;
    else
      size = 10000;

    ia = new int[size];
    for (int i = 0; i < size; i++)
      ia[i] = i;

    Shuffle(ia, size, 1);
    //Print(ia, size);

    for (int i = 0; i < size; i++)
      tree.insert(ia[i]);

    PrintInfo(tree);
    //PrintBST(tree);

    Shuffle(ia, size, 1);
    for (int i = 0; i < size - 10; i++)
    {
      tree.remove(ia[i]);
      //PrintInfo(tree);
      //PrintBST(tree);
    }
    PrintInfo(tree);
    PrintBST(tree);
  }
  catch(const BSTException& e)
  {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  catch(...)
  {
    std::cout << "Unknown exception." << std::endl;
  }

  delete [] ia;
}

#include <string>
template <typename T>
void TestStrings(void)
{
  const char *test = "TestStrings";

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

int main(int argC, const char** argV)
{
  typedef char TYPE;

    // DO NOT REMOVE THESE typeid lines
  typeid(BSTree<char>).name();
  typeid(AVLTree<char>).name();
  typeid(BSTree<int>).name();
  typeid(AVLTree<int>).name();
  typeid(BSTree<std::string>).name();  
  typeid(AVLTree<std::string>).name(); 
  typeid(BSTree<TYPE>).name();
  typeid(AVLTree<TYPE>).name();
  
  const int ARG_COUNT = 2;
  
  if(argC != ARG_COUNT)
  {
    std::cout << "Usage: <Executable> <Test Number>" << std::endl;
	return -1;
  }
  
  switch(std::atoi(argV[1]))
  {
    case 0:
	{
	  //Output<compiler>.txt
      SimpleTest1();
      std::cout << "--------------------------------\n";
      TestSorted<BSTree<TYPE>, TYPE>(100);
      std::cout << "--------------------------------\n";
      TestSorted<AVLTree<TYPE>, TYPE>(100);
      std::cout << "--------------------------------\n";
      SimpleTest2<BSTree<TYPE>, TYPE>(65);
      std::cout << "--------------------------------\n";
      SimpleTest2<AVLTree<TYPE>, TYPE>(65);
      std::cout << "--------------------------------\n";
	}
	break;
	case 1:
	{
	  //Output.InsertRemove.?.txt
      AVLInsertRemoveTest();
	}
	break;
	case 2:
	{
	  //OutputStress<Compiler>.txt
      AVLStress();
	}
	break;
	default:
	  std::cout << "Test Number should be 0-2" << std::endl;
  }
  

  //These are also tested in driver-sample2.cpp
  //TestStrings<BSTree<std::string> >();
  //TestStrings<AVLTree<std::string> >();


  return 0;
}
