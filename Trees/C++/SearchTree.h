/** @file SearchTree.h
 @author Anthony Campos
 @date 01/11/2022
 This header class file implements a  Binary Search Tree of Nodes 
	that hold a Comparable Pointer Object */

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

#pragma once

// included .h files
#include "Comparable.h"

// Included libraries
#include <iostream>
#include <string>


/** SearchTree class */

class SearchTree{

	/** Friend Methods */

	/** overloaded ostream method
	 diplays the Search object to ostream stream 
	 @pre Must be a Search object
	 @post Calls ostreamHelper and produces the following format:
		example: A 2
				f 8
				, 2
	 @param ostream [out] and SearchTree [object]
	 @return ostream object that represents an SearchTree */
	friend std::ostream& operator<<(std::ostream& out, const SearchTree& object);

public:
	
	/** Constructors */

	/** Defualt Constructor
	@pre None
	@post SearchTree Object created */
	SearchTree();

	/** Copy Constructor
	@pre must be another SearchTree object
	@post source SearchTree deep copied and New SearchTree allocated.
	Calls the copySearchTree to copy
	@parm SearchTree [source], root of SearchTree to copy. */ 
	SearchTree(const SearchTree& source);

	/** Destructor
	@pre none
	@post destroy SearchTree and release memory */
	~SearchTree();

	/** Public Methods */

	/* Overloaded assigment operator
	@pre must be another SearchTree object
	@post left hand SearchTree object equals the right hand SearchTree object
	Checks for self assignment and calls copySearchTree to copy.
	@param SearchTree [rhs] object to equal
	@return SearchTree oject is now equal to right hand SearchTree object */
	SearchTree& operator=(const SearchTree& rhs);

	/** Overloaded operator==
	@pre must be a SearchTree objects
	@post two SearchTree objects equal or not dependent on Node placement,
	Node->item_->data and Node count_. Calls comparisonHelper
	@param SearchTree [rhs]
	@return true if Node placement and data(data, count) is equal, false otherwise */
	bool operator==(const SearchTree& rhs) const;

	/** Overloaded operator!=
	@pre must be a SearchTree objects
	@post two SearchTree objects equal or not dependent on Node placement,
	Node->item_->data and Node count_. Calls comparisonHelper
	@param SearchTree [rhs]
	@return false if Node placement and data(data, count) is equal, true otherwise */
	bool operator!=(const SearchTree& rhs) const;

	/** Mutators Methods */

	/** insert
	@pre must be a Comparable Pointer
	@post adds Node with Comparable item if item is not already in SearchTree
	If item is already in SearchTree, the data member count_ is incremented by 1
	Calls insertHelper
	@param Comparable Pointer [item]
	@return true if Comparable item not not found & added, false otherwise */
	bool insert(Comparable* item);

	/** remove
	@pre must be a Comparable Pointer
	@post removes Node with Comparable item if item is already in SearchTree
	and count_ is 1, if count_ > 1 then count_'s value is reduced by 1.
	Calls removeHelper
	@param Comparable Pointer [item]
	@return false if the Comparable is not found, true otherwise */
	bool remove(const Comparable& item);

	/** makeEmpty
	@pre none
	@post removes and deallocates all of the data from the tree.
	calls destroySearchTree */
	void makeEmpty();

	/** Accessor Methods */

	/** retrieve
	@pre must be a Comparable 
	@post finds a Comparable in the tree using a key stored in the parameter 
	otherwise nullptr. 
	@param Comparable [key]
	@return const Comparable Pointer to Comparable object, nullptr otherwise */
	const Comparable* retrieve(const Comparable& key) const;

	/** depth
	@pre must be a Comparable
	@post provides the depth of the node storing the Comparable in the tree. 
	The root has depth 0, -1 if the Comparable is not found.
	calls depthHelper
	@param Comparable [key]
	@return Return -1 if the Comparable is not found, 
	otherwise the depth of the node storing the Comparable in the tree */
	int depth(const Comparable& key) const;

	/** height
	@pre must be a Comparable
	@post provides the height of the node storing the Comparable in the tree.
	leaf has height 0, non-leaf has height 1 more than the larger of the 
	heights of its children, -1 if the Comparable is not found.
	@param Comparable [key]
	@return Return -1 if the Comparable is not found,
	otherwise the height of the node storing the Comparable in the tree */
	int height(const Comparable& key) const;


private:


	/** Private Attributes */

	struct Node {

		/** Constructors
		@pre none
		@post Node created, pointers set to nullptr, count to 0*/
		Node();

		/** Attributes */

		// Pointer to Comparable object
		Comparable* item_;
		// holds frequency of item_->data_ 
		int count_;

		// Pointer to Left Child Node
		Node* leftChild_;

		// Pointer to Right Child Node
		Node* rightChild_;

	}; // end of Node

	// holds root of SearchTree
	Node* root_;

	/** Private Methods */

	/** copySearchTree copies a tree provided another tree's root
	@pre none
	@post provided tree copied and pointer to the copy returned
	@parm Node* [sourceRoot] tree's root to copy
	@return a copy of the provided tree*/
	Node* copySearchTree(const Node* sourceRoot) const;

	/** destroySearchTree destroys the tree object
	@pre none
	@post all memory for the SearchTree object is deallocated
	@parm Node* [sourceRoot] pointer to the root of the tree*/
	void destroySearchTree(Node*& sourceRoot);

	/** insertHelper
	@pre notFound is initially True
	@post adds Node with Comparable item if item is not already in SearchTree
	If item is already in SearchTree, the data member count_ is incremented by 1
	@parm Node* [root] pointer to the root_ of the tree,
	Comparable [item] item to insert, 
	bool [notFound] stores if item was inserted or not*/
	void insertHelper(Node*& root, Comparable* item, bool& notFound);

	/** removeHelper
	@pre none
	@post removes once occurrence of a Comarable item from the tree.
	If last node of item then node is removed from tree and memory is deallocated
	Calls deleteNode
	@parm Node* [root] pointer to the root of the tree/subtree,
	Comparable item [item]
	@return true if node removed, false otherwise*/
	bool removeHelper(Node*& root, const Comparable& item);

	/** deleteNode
	@pre root is not nullptr
	@post removes node from SearchTree and deallocates memory for Node
	and item Pointer
	Calls removeLeftModseNode if Node to delete has two children
	@parm Node* [root] pointer to the root of the tree/subtree*/
	void deleteNode(Node*& root);

	/** removeLeftMostNode
	@pre root is not nullptr
	@post finds and removes left most node from SearchTree 
	and deallocates memory for Node and item Pointer.
	@parm Node* [root] pointer to the root of the tree/subtree*/
	Comparable* removeLeftMostNode(Node*& root);

	/** comparisonHelper
	@pre flag is initially True
	@post flag is updated to true if lhs tree is equal to the data in the rhs,
	false otherwise
	@parm Node* [lhsRoot] root of the left hand side tree root, 
	Node* [rhsRoot} right hand side tree root, bool [flag] if tree equal or not*/
	void comparisonHelper(const Node* lhsRoot, const Node* rhsRoot, bool& flag) const;

	/** ostreamHelper
	@pre must/should be the root of a SearchTree object
	@post ostream ojbect in the following format:
	out << *root->item_ << " " << root->count_ << "\n"
	example: A 2
				f 8
				, 2

	updates the ostream [out]
	@param std::ostream [out], Node [root] root_ of SearchTree*/
	void ostreamHelper(std::ostream& out, const Node* root) const;


	/** depthHelper
	@pre depth is equal to 0
	@post depth is updated to represent the depth of a specific Node by the Key
	value in the SearchTree
	@parm Node* [root] root_ of SearchTree, Comparable [key] item_ to search for, 
	int [depth] stores node depth value*/
	void depthHelper(Node* root, const Comparable& key, int& depth) const;

	/** heightHelper
	@pre height is equal to -1
	@post height is updated to represent the height of a specific Node or Root_
	@parm Node* [root] root_ or specific Node of the SearchTree,
	int [height] stores node depth value
	@return height of whole tree or specific Node, -1 if tree is empty*/
	int heightHelper(Node* root) const;

	/** getNode
	@pre none
	@post Node for a specific key is returned or nullptr if key is not in
	SearchTree
	@parm Node* [root] root_, Comparable [key] item_ to search for
	@return pointer to the node that contains the key, otherwise nullptr*/
	Node* getNode(Node* root, const Comparable& key) const;
	
}; // end of SearchTree

