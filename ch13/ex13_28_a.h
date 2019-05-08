#include <iostream>

using namespace std;

class TreeNode{
public:
	TreeNode(const string &s = string()) : value(s), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right) {++*count;}
   	TreeNode& operator=(const TreeNode &tn);
	~TreeNode();	
private:
	string value;
	int *count; //using int count cause bug on assignment. (e.g. TreeNode t1 = t0, t2 = t0)
	TreeNode *left;
	TreeNode *right;
};

TreeNode& TreeNode::operator=(const TreeNode &tn){
	++*tn.count;
	if(--*count == 0){
		delete count;
		delete left;
		delete right;
	}

	value = tn.value;
	count = tn.count;
	left = tn.left;
	right = tn.right;
	return *this;
}

TreeNode::~TreeNode(){
	if(*--count == 0){
		delete count;
		delete left;
		delete right;
	}
}

class BinStrTree{
public:
	BinStrTree() : root(new TreeNode()) {}
	BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) {}
	BinStrTree& operator=(const BinStrTree &bst);
	~BinStrTree();
private:
	TreeNode *root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree &bst){
	auto temp = new TreeNode(*bst.root);
	delete root;
	root = temp;
	return *this;
}

BinStrTree::~BinStrTree(){
	delete root;
}
