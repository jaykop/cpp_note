
#ifndef BSTREE_H
#define BSTREE_H

#ifdef _MSC_VER
// suppress warning: C++ Exception Specification ignored
#pragma warning( disable : 4290 ) 
#endif

#include <string>    // std::string
#include <stdexcept> // std::exception


class BSTException : public std::exception
{
public:
	enum BST_EXCEPTION { E_DUPLICATE, E_NO_MEMORY };
	BSTException(int errorCode, const std::string& message) :
		m_errorCode(errorCode), m_message(message) {}

	virtual int code(void) const { return m_errorCode; }
	virtual const char* what(void) const throw() { return m_message.c_str(); }
	virtual ~BSTException() throw() {}


private:
	int m_errorCode;
	std::string m_message;
};

//template <typename T>
class BSTree
{
public:

	struct BinTreeNode
	{
		BinTreeNode(void) : pLeft(0), pRight(0), data(0), balanceFactor(0) {};
		BinTreeNode(const int& value) :
			pLeft(0), pRight(0), data(value), balanceFactor(0) {};
		BinTreeNode* pLeft;
		BinTreeNode* pRight;
		//T data;
		int data;
		int balanceFactor; // optional

	};
	typedef BinTreeNode* BinTree;

	BSTree(void);
	BSTree(const BSTree& rhs);
	virtual ~BSTree();

	virtual void insert(const int& value) throw(BSTException);

		
	virtual void remove(const int& value);
	unsigned     size(void) const;
	BSTree& operator=(const BSTree& rhs);
	BinTree      Root(void) const;
	void         clear(void);
	bool         find(const int& value, unsigned& compares) const;
	bool         empty(void) const;
	int          height(void) const;

	// newly added
	void insert_item(BinTreeNode* tree, int Data);
	void delete_item(BinTreeNode* tree, int Data);

protected:
	BinTree& GetRoot(void);
	BinTree     MakeNode(const int& value);
	void        FreeNode(BinTree node);
	void        FindPredecessor(BinTree tree, BinTree& predecessor) const;
	int         TreeHeight(BinTree tree) const;

private:
	// private stuff 
	int depth_;
	int size_;
	BinTree  m_pRoot;
};

// #include "BSTree.cpp"

#endif
//---------------------------------------------------------------------------
