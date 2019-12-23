#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <typeinfo>

#include "BSTree.h"
//#include "AVLTree.h"

//*********************************************************************
// Printing/Debugging
//*********************************************************************
static int Position;
typedef std::map<const BSTree::BinTreeNode *, std::pair<int, int> > TNodePositions;
typedef std::pair<const BSTree::BinTreeNode *, std::pair<int, int> > TNodePosition;
typedef std::pair<const BSTree::BinTreeNode *, int> TNodeLevel;

static TNodePositions NodePositions;

void SetTreePositions(const BSTree::BinTreeNode *tree, int depth)
{
  if (!tree)
    return;

  SetTreePositions(tree->pLeft, depth + 1);
  std::pair<int, int>XY(Position++, depth);
  TNodePosition pr(tree, XY);
  NodePositions.insert(pr);
  SetTreePositions(tree->pRight, depth + 1);
}

void SetTreePositions(const BSTree &tree)
{
  Position = 0;
  NodePositions.clear();
  SetTreePositions(tree.Root(), 0);
}

std::vector<std::pair<const BSTree::BinTreeNode *, int> >GetNodesAtLevel(int level)
{
  std::vector<std::pair<const BSTree::BinTreeNode *, int> >nodes;

  TNodePositions::iterator it;
  for (it = NodePositions.begin(); it != NodePositions.end(); ++it)
  {
    std::pair<int, int>XY = it->second;
    if (XY.second == level)
    {
      std::pair<const BSTree::BinTreeNode *, int> pr( it->first, XY.first);
      nodes.push_back(pr);
    }
  }
  return nodes;
}  

bool SortNodes(const std::pair<const BSTree::BinTreeNode *, int>&a, const std::pair<const BSTree::BinTreeNode *, int>&b)
{
  if (a.second < b.second)
    return true;
  else
    return false;
}

void PrintBST(const BSTree &tree)
{
  SetTreePositions(tree);
  int height = tree.height();
  int offset = 0;
  for (int i = 0; i <= height; i++)
  {
    std::vector<TNodeLevel>nodes = GetNodesAtLevel(i);
    std::sort(nodes.begin(), nodes.end(), SortNodes);
    std::vector<TNodeLevel>::iterator iter;
    char buffer[1024] = {0};
    std::memset(buffer, ' ', 1024);
    for (iter = nodes.begin(); iter != nodes.end(); ++iter)
    {
      char data[10] = {0};
      int value = (*iter).first->data;
      std::sprintf(data, "%i", value); 

      offset = (height / 2) + iter->second * 3;  // fudge factor
      strncpy(buffer + offset, data, strlen(data));
    }
    buffer[offset + 3] = 0;
    std::cout << buffer << std::endl << std::endl;
  }
  NodePositions.clear();
}
//*********************************************************************
// End Printing/Debugging
//*********************************************************************

void VisitNode(const BSTree::BinTreeNode* tree)
{
  std::cout << tree->data << std::endl;
}

void TraverseInOrder(const BSTree::BinTreeNode* tree)
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
void TestTree(std::vector<int> values)
{
  T tree;
  for (unsigned int i = 0; i < values.size(); i++)
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


template <typename T>
void TestSorted(void)
{
  std::vector<int> values;
  for (int i = 0; i < 15; i++)
    values.push_back(i);
  TestTree<T>(values);
  std::cout << "-------------------------------\n";
}

void SimpleTest1(void)
{
  std::vector<int> values;
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

  TestTree<BSTree>(values);
  std::cout << "-------------------------------\n";
  //TestTree<AVLTree>(values);
}

template <typename T>
void SimpleTest2(void)
{
  int ia[] = {2, 4, 6, 10, 8, 22, 12, 9, 19, 20};
  int size = sizeof(ia) / sizeof(*ia);

  T tree;
  try
  {
    for (int i = 0; i < size; i++)
      tree.insert(ia[i]);

    PrintInfo(tree);
    PrintBST(tree);

    int value = 19;
    unsigned compares = 0;
    if (tree.find(value, compares))
      std::cout << value << " was found after " << compares << " compares.\n";
    else
      std::cout << value << " was not found after " << compares << " compares.\n";

    value = 21;
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

    value = 10;
    compares = 0;
    if (tree.find(value, compares))
      std::cout << value << " was found after " << compares << " compares.\n";
    else
      std::cout << value << " was not found after " << compares << " compares.\n";

    tree.insert(5);
    value = 10;
    compares = 0;
    if (tree.find(value, compares))
      std::cout << value << " was found after " << compares << " compares.\n";
    else
      std::cout << value << " was not found after " << compares << " compares.\n";

    PrintInfo(tree);
    tree.remove(20);
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
    tree.insert(5);
  }
  catch(const BSTException& e)
  {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
}

int main(void)
{
  typeid(BSTree).name();  // DO NOT REMOVE
  //typeid(AVLTree).name(); // DO NOT REMOVE

  SimpleTest1();
  std::cout << "--------------------------------\n";
  //TestSorted<BSTree>();
  std::cout << "--------------------------------\n";
  //TestSorted<AVLTree>();
  std::cout << "--------------------------------\n";
  //SimpleTest2<BSTree>();
  std::cout << "--------------------------------\n";
  //SimpleTest2<AVLTree>();

  return 0;
}
