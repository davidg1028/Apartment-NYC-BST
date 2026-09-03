#pragma once

template <typename T>
class Node {
private:
	T data;
	Node<T>* left;
	Node<T>* right;
public:
	// Constructors
	Node();
	Node(T val);
	// Getter and Setter for data on the node
	T& getData();
	void setData(T data);
	// Getter and Setter for left child
	Node<T>* getLeftChild() const;
	void setLeftChild(Node<T>* node);
	// Getter and Setter for right child
	Node<T>* getRightChild() const;
	void setRightChild(Node<T>* node);
};


//constructors
template <typename T>
Node<T>::Node() {
	left = right = nullptr;
}


template <typename T>
Node<T>::Node(T val) {
	data = val;
	left = right = nullptr;
}


// Getter for left child
template <typename T>
Node<T>* Node<T>::getLeftChild() const {
	return left;
}


// Setter for left child
template <typename T>
void Node<T>::setLeftChild(Node<T>* newNode) {
	left = newNode;
}


// Getter for data
template <typename T>
T& Node<T>::getData(){
	return data;
} 


// Setter for data
template <typename T>
void Node<T>::setData(T data) {
	this->data = data;
}


// Getter for right child
template <typename T>
Node<T>* Node<T>::getRightChild() const {
	return right;
}


// Setter for right child
template <typename T>
void Node<T>::setRightChild(Node<T>* node) {
	right = node;
}