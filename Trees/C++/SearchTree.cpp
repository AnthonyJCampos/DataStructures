/** @file SearchTree.cpp
 @author Anthony Campos
 @date 01/11/2022
 TThis implementation file implements a  Binary Search Tree of Nodes
	that hold a Comparable Pointer Object*/

//---------------------------------------------------------------------------
// SearchTree class:  Tree data structure
//   included features:
//   -- allows removal inseration of Comparable object
//	  -- allows for clearing of all Nodes in SearchTree
//   -- allows for comparison of 2 SearchTrees, element by element
//   -- allows for assignment and copy of 2 SearchTrees
//   -- provides height and depth of specific Nodes per Key
//   -- allows for retrieval of Comparable object stored in SearchTree
//
// Assumptions:
//   -- Height is given on a Node basis not whole tree
//---------------------------------------------------------------------------

// included .h files
#include "SearchTree.h"

	/** Friend Methods */

/** overloaded ostream method
diplays the Search object to ostream stream
@pre Must be a Search object
@post Calls ostreamHelper and produces the following format:
example: A 2
			f 8
			, 2
 @param ostream [out] and SearchTree [object]
 @return ostream object that represents an SearchTree*/
std::ostream& operator<<(std::ostream& out, const SearchTree& object) {

	object.ostreamHelper(out, object.root_);

	return out; // return ostream

} // end of overloaded >>

/** Constructors */

/** Defualt Constructor
@pre None
@post SearchTree Object created*/
SearchTree::SearchTree()
	:root_(nullptr) {} // end of Constructor


/** Copy Constructor
@pre must be another SearchTree object
@post source SearchTree deep copied and New SearchTree allocated.
Calls the copySearchTree to copy
@parm SearchTree [source], root of SearchTree to copy.*/
SearchTree::SearchTree(const SearchTree& source) {
	// Copy Tree
	destroySearchTree(root_);
	root_ = copySearchTree(source.root_);

} // end of copy constructor

/** Destructor
@pre none
@post destroy SearchTree and release memory*/
SearchTree::~SearchTree() {

	// release memory for tree
	destroySearchTree(root_);

} // end of destructor

/** Public Methods */

/* Overloaded assigment operator
@pre must be another SearchTree object
@post left hand SearchTree object equals the right hand SearchTree object
Checks for self assignment and calls copySearchTree to copy.
@param SearchTree [rhs] object to equal
@return SearchTree oject is now equal to right hand SearchTree object */
SearchTree& SearchTree::operator=(const SearchTree& rhs) {
	
	// check for self assignment
	if (this == &rhs) {

		return *this;

	} // end if

	// deallocate lhs tree
	destroySearchTree(root_);
	// do copy
	root_ = copySearchTree(rhs.root_);

	// return the existing object so we can chain this operator
	return *this;
	
} // end of overloaded assigment operator

/** Overloaded operator==
@pre must be a SearchTree objects
@post two SearchTree objects equal or not dependent on Node placement,
Node->item_->data and Node count_. Calls comparisonHelper
@param SearchTree [rhs]
@return true if Node placement and data(data, count) is equal, false otherwise */
bool SearchTree::operator==(const SearchTree& rhs) const {
	
	// flag to hold equality value 
	bool flag = true;

	// compare this tree to rhs tree and update flag by reference
	comparisonHelper(root_, rhs.root_, flag);

	return flag; // return if equal 

} // end of overloaded ==


/** Overloaded operator!=
@pre must be a SearchTree objects
@post two SearchTree objects equal or not dependent on Node placement,
Node->item_->data and Node count_. Calls comparisonHelper
@param SearchTree [rhs]
@return false if Node placement and data(data, count) is equal, true otherwise */
bool SearchTree::operator!=(const SearchTree& rhs) const {
	
	// flag to hold equality value 
	bool flag = true;

	// compare this tree to rhs tree and update flag by reference
	comparisonHelper(root_, rhs.root_, flag);

	return !flag; // return if equal 
		

} // end of overloaded !=

/** Mutators Methods */

/** insert
@pre must be a Comparable Pointer
@post adds Node with Comparable item if item is not already in SearchTree
If item is already in SearchTree, the data member count_ is incremented by 1
Calls insertHelper
@param Comparable Pointer [item]
@return true if Comparable item not not found & added, false otherwise */
bool SearchTree::insert(Comparable* item) {

	// falg to hold if item is already in tree or not
	bool notfound = true;

	// attempts to add item to tree and updates notFound
	insertHelper(root_, item, notfound);

	return notfound; // return if inserted

} // end of insert

/** remove
@pre must be a Comparable Pointer
@post removes Node with Comparable item if item is already in SearchTree
and count_ is 1, if count_ > 1 then count_'s value is reduced by 1.
Calls removeHelper
@param Comparable Pointer [item]
@return false if the Comparable is not found, true otherwise */
bool SearchTree::remove(const Comparable& item) {

	// attempt to remove item from tree
	return removeHelper(root_, item); // return if item removed

} // end of remove
	
/** makeEmpty
@pre none
@post removes and deallocates all of the data from the tree.
calls destroySearchTree*/
void SearchTree::makeEmpty() {
	
	// releases all tree memory
	destroySearchTree(root_);
	// set root_ to nullptr
	root_ = nullptr;

} // makeEmpty

/** retrieve
@pre must be a Comparable
@post finds a Comparable in the tree using a key stored in the parameter
otherwise nullptr.
@param Comparable [key]
@return const Comparable Pointer to Comparable object, nullptr otherwise */
const Comparable* SearchTree::retrieve(const Comparable& key) const {

	Comparable* itemPtr = nullptr;
	Node* nodePtr = getNode(root_, key);

	if (nodePtr != nullptr) {
		
		itemPtr = nodePtr->item_;

	} // end if
	
	return itemPtr;

} // end of retrieve

 /** depth
@pre must be a Comparable
@post provides the depth of the node storing the Comparable in the tree.
The root has depth 0, -1 if the Comparable is not found.
calls depthHelper
@param Comparable [key]
@return Return -1 if the Comparable is not found,
otherwise the depth of the node storing the Comparable in the tree */
int SearchTree::depth(const Comparable& key) const {
	
	int depth = 0;
		
	depthHelper(root_, key, depth);

	return depth;

} // end depth


/** height
@pre must be a Comparable
@post provides the height of the node storing the Comparable in the tree.
leaf has height 0, non-leaf has height 1 more than the larger of the heights
of its children, -1 if the Comparable is not found.
@param Comparable [key]
@return Return -1 if the Comparable is not found,
otherwise the height of the node storing the Comparable in the tree */
int SearchTree::height(const Comparable& key) const {


	int height = -1;

	Node* nodePtr = getNode(root_, key);

	if (nodePtr != nullptr) {

		height = heightHelper(nodePtr);
	}

	return height;

} // end height


/** Private Methods */

/** copySearchTree copies a tree provided another tree's root
@pre none
@post provided tree copied and pointer to the copy returned
@parm Node* [sourceRoot] tree's root to copy
@return a copy of the provided tree */
SearchTree::Node* SearchTree::copySearchTree(const Node* sourceRoot) const {
	
	 
	Node* newTreePtr = nullptr;

	// copy tree nodes during a preorder traversal
	if (sourceRoot != nullptr) {
		
		newTreePtr = new Node;
		newTreePtr->item_ = new Comparable;
		*newTreePtr->item_ = *sourceRoot->item_;
		newTreePtr->count_ = sourceRoot->count_;


		newTreePtr->leftChild_ = copySearchTree(sourceRoot->leftChild_);
		newTreePtr->rightChild_ = copySearchTree(sourceRoot->rightChild_);



	} 
	else {
		newTreePtr = nullptr;
	} // end if

	return newTreePtr;

} // end copySearchTree

/** destroySearchTree destroys the tree object
@pre none
@post all memory for the SearchTree object is deallocated
@parm Node* [sourceRoot] pointer to the root of the tree */
void SearchTree::destroySearchTree(Node*& sourceRoot) {

	// post order traversal
	if (sourceRoot != nullptr) {

		destroySearchTree(sourceRoot->leftChild_);
		destroySearchTree(sourceRoot->rightChild_);

		// release memory
		delete sourceRoot->item_;
		sourceRoot->item_ = nullptr;
		delete sourceRoot;
		sourceRoot = nullptr;

	} // end if

} // end of destroySearchTree

/** insertHelper
@pre notFound is initially True
@post adds Node with Comparable item if item is not already in SearchTree
If item is already in SearchTree, the data member count_ is incremented by 1
@parm Node* [root] pointer to the root_ of the tree,
Comparable [item] item to insert,
bool [notFound] stores if item was inserted or not */
void SearchTree::insertHelper(Node*& root, Comparable* item, bool& notfound) {


	if (root == nullptr) {
		
		// allocate memory for new node and Comparable objects
		root = new Node;
		root->item_ = item;
		root->count_ = 1;
		root->leftChild_ = nullptr;
		root->rightChild_ = nullptr;

		// item was not found
		notfound = true;

	}
	else if (*root->item_ > *item) {
		
		insertHelper(root->leftChild_, item, notfound);

	}
	else if (*root->item_ < *item) {
		
		insertHelper(root->rightChild_, item, notfound);

	}
	else { // item is == 
		
		// increment count_ by 1. 
		root->count_ += 1;
		// item was found
		notfound = false;

	} // end if

} // end of insertHelper

/** removeHelper
@pre none
@post removes once occurrence of a Comarable item from the tree.
If last node of item then node is removed from tree and memory is deallocated.
Calls deleteNode
@parm Node* [root] pointer to the root of the tree/subtree, Comparable item [item]
@return true if node removed, false otherwise */
bool SearchTree::removeHelper(Node*& root, const Comparable& item) {

	if (root == nullptr) {
		return false;
	}
	// Case 1: item is equal to item_
	else if (*root->item_ == item) {

		// check to see if multi occurrences
		if (root->count_ > 1) {
			
			root->count_ -= 1;

		}
		else {

			// only occurrence of item it tree
			deleteNode(root);
	
		} // end if

	}
	// Case 2: item is less then item_
	else if (*root->item_ > item) {
		return removeHelper(root->leftChild_, item);
	}
	// Case 3: item is greater then then item_
	else {

		return removeHelper(root->rightChild_, item);

	} // end if

	return true;

} // end of removeHelper

/** deleteNode
@pre root is not nullptr
@post removes node from SearchTree and deallocates memory for Node
and item Pointer Calls removeLeftModseNode if Node to delete has two children
@parm Node* [root] pointer to the root of the tree/subtree */
void SearchTree::deleteNode(Node*& root) {

	delete root->item_;
	root->item_ = nullptr;

	// Case 1: root/leaf
	if (root->leftChild_ == nullptr && root->rightChild_ == nullptr) {
		
		// remove root/leaf
		delete root;
		root = nullptr;
	}
	// Case 2: only one child
	else if (root->leftChild_ == nullptr || root->rightChild_ == nullptr) {
		
		Node* temp = root;

		if (root->leftChild_ == nullptr) {
			root = root->rightChild_;

		}
		else {
			root = root->leftChild_;
		} // end if

		// deallocate memory
		delete temp;
		temp = nullptr;
	}
	// Case 3: two children
	else {
		
		root->item_ = removeLeftMostNode(root->rightChild_);
		
	} // end if

} // end deleteNode

/** removeLeftMostNode
@pre root is not nullptr
@post finds and removes left most node from SearchTree
and deallocates memory for Node and item Pointer.
@parm Node* [root] pointer to the root of the tree/subtree */
Comparable* SearchTree::removeLeftMostNode(Node*& root) {


	if (root->leftChild_ == nullptr) {
		

		Comparable* item = root->item_;
		Node* trash = root;

		root = root->rightChild_;
		root->count_ = root->rightChild_->count_;

		// deallocate memory
		delete trash->item_;
		trash->item_ = nullptr;
		delete trash;
		trash = nullptr;

	}
	else {
		return removeLeftMostNode(root->leftChild_);
	} // end if

} // end removeLeftMostNode

/** comparisonHelper
@pre flag is initially True
@post flag is updated to true if lhs tree is equal to the data in the rhs,
false otherwise
@parm Node* [lhsRoot] root of the left hand side tree root,
Node* [rhsRoot} right hand side tree root, bool [flag] if tree equal or not */
void SearchTree::comparisonHelper(const Node* lhsRoot, const Node* rhsRoot, bool& flag) const {

	// use the flag to end the search

	// preorder traversal
	// Case 1:  both tree/subtrees are empty, flag still true
	if (lhsRoot == nullptr && rhsRoot == nullptr && flag) {

		flag = true;
	}
	// Case 2:  both tree/subtrees are not empty, flag still true
	else if (lhsRoot != nullptr && rhsRoot != nullptr && flag) {

		// if item and count are equal flag set to true, otherwise false;
		if (*lhsRoot->item_ == *rhsRoot->item_ && lhsRoot->count_ == rhsRoot->count_) {
			
			flag = true;
		}
		else {
			flag = false;
		} // end if

		comparisonHelper(lhsRoot->leftChild_, rhsRoot->leftChild_, flag);
		comparisonHelper(lhsRoot->rightChild_, rhsRoot->rightChild_, flag);

	}
	// Case 3: one or the other root is nullptr
	else {
		flag = false;

	} // end if


} // end of comparisonHelper

/** ostreamHelper
@pre must/should be the root of a SearchTree object
@post ostream ojbect in the following format:
out << *root->item_ << " " << root->count_ << "\n"
example: A 2
			f 8
			, 2
updates the ostream [out]
@param std::ostream [out], Node [root] root_ of SearchTree */
void SearchTree::ostreamHelper(std::ostream& out, const Node* root) const {
	
	// in order traversal
	if (root != nullptr) {

		ostreamHelper(out, root->leftChild_);
		out << *root->item_ << " " << root->count_ << "\n";
		ostreamHelper(out, root->rightChild_);

	} // end if
	

} // end of getNodeData

/** depthHelper
@pre depth is equal to 0
@post depth is updated to represent the depth of a specific Node by the Key value
in the SearchTree
@parm Node* [root] root_ of SearchTree, Comparable [key] item_ to search for,
int [depth] stores node depth value */
void SearchTree::depthHelper(Node* root, const Comparable& key, int& depth) const {

	if (root == nullptr) {

		// set depth to -1;
		// item not found
		depth = -1;

	}
	else {

		// binary search, increment depth by 1
		if (*root->item_ > key) {

			depth += 1;
			depthHelper(root->leftChild_, key, depth);

		} // end if

		if (*root->item_ < key) {
			
			depth += 1;
			depthHelper(root->rightChild_, key, depth);

		} // end if

	} // end if

} // end of depthHelper

/** heightHelper
@pre height is equal to -1
@post height is updated to represent the height of a specific Node or Root_
@parm Node* [root] root_ or specific Node of the SearchTree, int [height] stores
node depth value
@return height of whole tree or specific Node, -1 if tree is empty */
int SearchTree::heightHelper(Node* root) const {
	
	// base case
	if (root == nullptr) {
		return -1;
	}
	else {

		return 1 + std::max(heightHelper(root->leftChild_), heightHelper(root->rightChild_));

	} // end if

} // end of heighHelper

/** getNode
@pre none
@post Node for a specific key is returned or nullptr if key is not in SearchTree
@parm Node* [root] root_, Comparable [key] item_ to search for
@return pointer to the node that contains the key, otherwise nullptr */
SearchTree::Node* SearchTree::getNode(Node* root, const Comparable& key) const {

	if (root != nullptr) {


		if (*root->item_ > key) {

			return getNode(root->leftChild_, key);

		}
		if(*root->item_ < key) {

			return getNode(root->rightChild_, key);

		} // end if

	} // end if

	return root;

} // end of getNode


/** Node Methods */

/** Constructors
@pre none
@post Node created, pointers set to nullptr, count to 0 */
SearchTree::Node::Node() 
	:item_(nullptr), count_(0), leftChild_(nullptr), rightChild_(nullptr)
{} // end of Node Constructor

/** End of SearchTree */
