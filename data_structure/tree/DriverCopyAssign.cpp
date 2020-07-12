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

  //NodePositions.clear();
}

//*********************************************************************
// End Printing/Debugging
//*********************************************************************

template <typename T, typename U>
void CopyTree(const std::vector<U>& values)
{
  T tree;
  for (unsigned i = 0; i < values.size(); i++)
    tree.insert(values[i]);

  std::cout << "------------------------------\n";
  std::cout << "height: " << tree.height() << std::endl;
  std::cout << " nodes: " << tree.size() << std::endl << std::endl;
  PrintBST(tree);

  std::cout << "Making a copy...\n";
  T copy(tree);
  std::cout << "------------------------------\n";
  std::cout << "height: " << copy.height() << std::endl;
  std::cout << " nodes: " << copy.size() << std::endl << std::endl;
  PrintBST(copy);

  std::cout << "Original tree:\n";
  std::cout << "height: " << tree.height() << std::endl;
  std::cout << " nodes: " << tree.size() << std::endl << std::endl;
  PrintBST(tree);

}

void CopyTest1(void)
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

  CopyTree<BSTree<T>, T>(values);
  std::cout << "-------------------------------\n";
  CopyTree<AVLTree<T> >(values);
}

template <typename T, typename U>
void AssignTree(const std::vector<U>& values)
{
  T tree;
  for (unsigned i = 0; i < values.size(); i++)
    tree.insert(values[i]);

  std::cout << "------------------------------\n";
  std::cout << "height: " << tree.height() << std::endl;
  std::cout << " nodes: " << tree.size() << std::endl << std::endl;
  PrintBST(tree);

  std::cout << "Assigning...\n";
  T copy;
  copy = tree;
  std::cout << "------------------------------\n";
  std::cout << "height: " << copy.height() << std::endl;
  std::cout << " nodes: " << copy.size() << std::endl << std::endl;
  PrintBST(copy);

  std::cout << "Original tree:\n";
  std::cout << "height: " << tree.height() << std::endl;
  std::cout << " nodes: " << tree.size() << std::endl << std::endl;
  PrintBST(tree);

}

void AssignTest1(void)
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

  AssignTree<BSTree<T>, T>(values);
  std::cout << "-------------------------------\n";
  AssignTree<AVLTree<T> >(values);
}


int main(void)
{

  CopyTest1();
  AssignTest1();

  #ifdef __BORLANDC__
    std::string s;
    std::cout << "Press any key to continue . . . ";
    std::getline(std::cin, s);
  #endif
 return 0;

}
