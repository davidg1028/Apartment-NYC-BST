#pragma once

template<typename T>
class BinaryTreeInterface {
public:
	//interface methods
	virtual bool isEmpty() const = 0;
	virtual bool add(const T& newItem) = 0; //outward facing
	//outward facing traversals
	virtual void inOrderTraverse() const = 0;
	virtual void preOrderTraverse() const = 0;
};


