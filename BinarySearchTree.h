#pragma once
#include "Node.h"
#include "Visitor.h"
#include "BinarySearchTreeInterface.h"

using namespace std; 

template <typename T>
class BinarySearchTree : public BinaryTreeInterface<T> {
private:
	Node<T>* root;
	Node<T>* add(Node<T>* currentRoot, Node<T>* newNode);
	void inOrderTraverse(Node<T>* currentRoot) const;
	void preOrderTraverse(Node<T>* currentRoot) const;
	void postOrderDelete(Node<T>* currentRoot) const;


	//visitor helper
	void inorderVisitHelper(Node<T>* currRoot, Visitor& visitor) const;


public:
	BinarySearchTree();
	~BinarySearchTree();
	bool isEmpty() const;
	bool add(const T& newItem);

	//orders
	void inOrderTraverse() const;
	void preOrderTraverse() const;
	void postOrderDelete() const;

	//the visitor
	void inorderVisit(Visitor& visitor) const;

	Node<T>* getRoot() const;
};


template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	//complete this method
	root = nullptr;
}


template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	//destructor
	postOrderDelete(root);
}


template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
	//complete this method
	return root == nullptr;
}


//--------------------outward-------------------
template <typename T>
bool BinarySearchTree<T>::add(const T& data) { //outward facing
	//complete this method
	Node<T>* newNode = new Node<T>(data);
	root = add(root, newNode);
	return true;
}


//--------------------inward facing--------------
template <typename T>
Node<T>* BinarySearchTree<T>::add(Node<T>* currentRoot, Node<T>* newNode) {
	if (currentRoot == nullptr)
		return newNode;
	else {
		if (newNode->getData() < currentRoot->getData()) {
			//cout << "Going left" << endl;
			Node<T>* tempPtr = add(currentRoot->getLeftChild(), newNode);
			currentRoot->setLeftChild(tempPtr);
		}
		else {
			//cout << "Going right" << endl;
			//without instantiating tempTpr
			currentRoot->setRightChild(add(currentRoot->getRightChild(), newNode));
		}
		return currentRoot;
	}
}


//inorder traversal-------- outward facing----------
template <typename T>
void BinarySearchTree<T>::inOrderTraverse() const {
	//complete this method
	if (isEmpty()) {
		cout << "empty tree...\n";
		return;
	}
	cout << "inorder traversal....\n";
	inOrderTraverse(root); //calls private method
}


//---------------inward facing----------------------
template <typename T>
void BinarySearchTree<T>::inOrderTraverse(Node<T>* currentRoot) const {
	if (currentRoot != nullptr) {
		inOrderTraverse(currentRoot->getLeftChild());
		cout << currentRoot->getData() << endl;
		inOrderTraverse(currentRoot->getRightChild());
	}
}


//Preorder traversal-----------outward facing--------------------
template <typename T>
void BinarySearchTree<T>::preOrderTraverse() const {
	//complete this method
	if (isEmpty()) {
		cout << "Is empty..." << endl;
		return;
	}

	cout << "\npreorder traversal..." << endl;
	preOrderTraverse(root);
}


//----------------------inward facing-----------------------------
template <typename T>
void BinarySearchTree<T>::preOrderTraverse(Node<T>* currentRoot) const {
	//complete this method
	if (currentRoot != nullptr) {
		cout << currentRoot->getData().getCurrent2() << endl;
		preOrderTraverse(currentRoot->getLeftChild());
		preOrderTraverse(currentRoot->getRightChild());
	}

}//end preordertraverse()


//---------------------outward facing-------------------------------
template <typename T>
void BinarySearchTree<T>::postOrderDelete() const {
	//complete this method
	if (isEmpty()) {
		cout << "Is empty..." << endl;
		return;
	}

	cout << "Postorder deleting..." << endl;
	postOrderDelete(root);
}


//----------------------inward facing--------------------------------
template <typename T>
void BinarySearchTree<T>::postOrderDelete(Node<T>* currentRoot) const {
	if (currentRoot != nullptr) {
		postOrderDelete(currentRoot->getLeftChild());
		postOrderDelete(currentRoot->getRightChild());

		cout << "Deleting apartment at address: "
			<< currentRoot->getData().getStreetAddress()
			<< ", Borough: " << currentRoot->getData().getBorough() << ", Rent: " << currentRoot->getData().getMonthlyRent() << endl;

		delete currentRoot;
	}
}//end postOrderDelete


//=============outward facing======================
template <typename T>
void BinarySearchTree<T>::inorderVisit(Visitor& visitor) const {
	inorderVisitHelper(root, visitor);

}


//===========inward facing========================
template <typename T>
void BinarySearchTree<T>::inorderVisitHelper(Node<T>* currRoot, Visitor& visitor) const {
	if (currRoot != nullptr) {

		inorderVisitHelper(currRoot->getLeftChild(), visitor);

		visitor.visit(currRoot->getData());

		inorderVisitHelper(currRoot->getRightChild(), visitor);
	}
}


template <typename T>
Node<T>* BinarySearchTree<T>::getRoot() const {
	return root;
}

