#include "tree.h"
#include <iostream>
using namespace std;

int depth(TreeNode* startingPoint, TreeNode* end){
	int count = 0;
	while (startingPoint != end){
		if (startingPoint == NULL){
			break;
		}
		else if (end->value > startingPoint->value){
			count++;
			startingPoint = startingPoint->right;
		}
		else{
			count++;
			startingPoint = startingPoint->left;
		}
	}
	return count;
}

Tree::Tree(){
	start = NULL;
}

Tree::Tree(const Tree& other){
	copyOther(other);
}

Tree::~Tree(){
	cout << "Inside destructor." << endl;
	clear();
}

Tree& Tree::operator=(const Tree& other){
	if (this->start != NULL){
		this->clear();
		this->start = NULL;
	}
	copyOther(other);
	return *this;
}

void Tree::push(int value){
	TreeNode* node = new TreeNode();
	node->value = value;
	if (start == NULL){
		start = node;
	}
	else
		pushFrom(start, node);
}

TreeNode* Tree::find(int value) const{
	return findFrom(start, value);
}

void Tree::print() const{
	if (start == NULL)
		return;
	else{
		printFrom(start, depth(start, start));
	}
}

void Tree::deleteNode(int value){
	if (NULL == start)
		return;
	else
		deleteFrom(start, value);
}

void Tree::copyOther(const Tree& other){
	if (other.start == NULL)
		return;
	this->copyFrom(other.start);
}

void Tree::clear(){
	if (start == NULL)
		return;
	else
		clearFrom(start);
}

void Tree::pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush){
	if (startingPoint->value <= nodeToPush->value){
		if (startingPoint->right == NULL)
			startingPoint->right = nodeToPush;
		else
			pushFrom(startingPoint->right, nodeToPush);
	}
	else{
		if (startingPoint->left == NULL)
			startingPoint->left = nodeToPush;
		else
			pushFrom(startingPoint->left, nodeToPush);
	}
}

TreeNode* Tree::findFrom(TreeNode* startingPoint, int value) const{
	if (startingPoint == NULL){
		return NULL;
	}
	if (value == startingPoint->value)
		return startingPoint;
	else if (value > startingPoint->value){
		findFrom(startingPoint->right, value);
	}
	else{
		findFrom(startingPoint->left, value);
	}
}

void Tree::printFrom(TreeNode* startintPoint, int numSpaces) const{
	if (startintPoint == NULL){
		return;
	}
	for (int i = 0; i < numSpaces; i++)
		cout << " ";
	cout << startintPoint->value << endl;
	printFrom(startintPoint->left, depth(start, startintPoint) + 1);
	printFrom(startintPoint->right, depth(start, startintPoint) + 1);
}

void Tree::copyFrom(TreeNode* startintPoint){
	if (startintPoint == NULL)
		return;
	push(startintPoint->value);
	copyFrom(startintPoint->left);
	copyFrom(startintPoint->right);
}

TreeNode* findMax(TreeNode* startingPoint){
	if (startingPoint == NULL)
		return startingPoint;
	while (startingPoint->right != NULL)
		startingPoint = startingPoint->right;
	return startingPoint;
}

void Tree::deleteFrom(TreeNode* startintPoint, int value){
	if (startintPoint == NULL){
		return;
	}
	else if (startintPoint->value == value && startintPoint == start){
		TreeNode* deleter = start;
		if (deleter->left == NULL && deleter->right == NULL){
			start->right = deleter->right;
			delete deleter;
			deleter = NULL;
		}
		else if (deleter->left == NULL){
			start = deleter->right;
			delete deleter;
			deleter = NULL;
		}
		else if (deleter->right == NULL){
			start = deleter->left;
			delete deleter;
			deleter = NULL;
		}
		else{
			deleter->value = findMax(deleter->left)->value;
			deleteFrom(deleter->left, deleter->value);
		}
	}
	else if (value > startintPoint->value){
		if (value > startintPoint->right->value)
			deleteFrom(startintPoint->right, value);
		else if (value < startintPoint->right->value)
			deleteFrom(startintPoint->right, value);
		else{
			if (startintPoint->left != NULL && startintPoint->left->value == value){
				TreeNode* deleter = startintPoint->left;
				if (deleter->left == NULL && deleter->right == NULL){
					startintPoint->left = deleter->left;
					delete deleter;
					deleter = NULL;
				}
				else if (deleter->left == NULL){
					startintPoint->left = deleter->right;
					delete deleter;
					deleter = NULL;
				}
				else if (deleter->right == NULL){
					startintPoint->left = deleter->left;
					delete deleter;
					deleter = NULL;
				}
				else{
					deleter->value = findMax(deleter->left)->value;
					deleteFrom(deleter, deleter->value);
				}
			}
			else if (startintPoint->right != NULL && startintPoint->right->value == value){
				TreeNode* deleter = startintPoint->right;
				if (deleter->left == NULL && deleter->right == NULL){
					startintPoint->right = deleter->right;
					delete deleter;
					deleter = NULL;
				}
				else if (deleter->left == NULL){
					startintPoint->left = deleter->right;
					delete deleter;
					deleter = NULL;
				}
				else if (deleter->right == NULL){
					startintPoint->right = deleter->left;
					delete deleter;
					deleter = NULL;
				}
				else{
					deleter->value = findMax(deleter->left)->value;
					deleteFrom(deleter, deleter->value);
				}
			}
		}
	}
	else if (value < startintPoint->value){
		if (value < startintPoint->left->value)
			deleteFrom(startintPoint->left, value);
		else if (value > startintPoint->left->value)
			deleteFrom(startintPoint->left, value);
		else{
			if (startintPoint->left != NULL && startintPoint->left->value == value){
				TreeNode* deleter = startintPoint->left;
				if (deleter->left == NULL && deleter->right == NULL){
					startintPoint->left = deleter->left;
					delete deleter;
					deleter = NULL;
				}
				else if (deleter->left == NULL){
					startintPoint->left = deleter->right;
					delete deleter;
					deleter = NULL;
				}
				else if (deleter->right == NULL){
					startintPoint->left = deleter->left;
					delete deleter;
					deleter = NULL;
				}
				else{
					deleter->value = findMax(deleter->left)->value;
					deleteFrom(deleter, deleter->value);
				}
			}
			else if (startintPoint->right != NULL && startintPoint->right->value == value){
				TreeNode* deleter = startintPoint->right;
				if (deleter->left == NULL && deleter->right == NULL){
					startintPoint->left = deleter->left;
					delete deleter;
					deleter = NULL;
				}
				else if (deleter->left == NULL){
					startintPoint->left = deleter->right;
					delete deleter;
					deleter = NULL;
				}
				else if (deleter->right == NULL){
					startintPoint->right = deleter->left;
					delete deleter;
					deleter = NULL;
				}
				else{
					deleter->value = findMax(deleter->left)->value;
					deleteFrom(deleter, deleter->value);
				}
			}
		}
	}
	else{
		if (startintPoint->left != NULL && startintPoint->left->value == value){
			TreeNode* deleter = startintPoint->left;
			if (deleter->left == NULL && deleter->right == NULL){
				startintPoint->left = deleter->left;
				delete deleter;
				deleter = NULL;
			}
			else if (deleter->left == NULL){
				startintPoint->left = deleter->right;
				delete deleter;
				deleter = NULL;
			}
			else if (deleter->right == NULL){
				startintPoint->left = deleter->left;
				delete deleter;
				deleter = NULL;
			}
			else{
				deleter->value = findMax(startintPoint->left)->value;
				deleteFrom(deleter, deleter->value);
			}
		}
		else if (startintPoint->right != NULL && startintPoint->right->value == value){
			TreeNode* deleter = startintPoint->right;
			if (deleter->left == NULL && deleter->right == NULL){
				startintPoint->left = deleter->left;
				delete deleter;
				deleter = NULL;
			}
			else if (deleter->left == NULL){
				startintPoint->left = deleter->right;
				delete deleter;
				deleter = NULL;
			}
			else if (deleter->right == NULL){
				startintPoint->left = deleter->left;
				delete deleter;
				deleter = NULL;
			}
			else{
				deleter->value = findMax(deleter->left)->value;
				deleteFrom(deleter, deleter->value);
			}
		}
	}
}

void Tree::clearFrom(TreeNode* startingPoint){
	if (startingPoint == NULL)
		return;
	clearFrom(startingPoint->left);
	clearFrom(startingPoint->right);
	deleteNode(startingPoint->value);
}