#pragma once
#include "AVL_tree.h"
#include <assert.h>
template<class T>
Nodes<T>::Nodes()
{
	left = right = nullptr;
}
template<class T>
Nodes<T>::Nodes(T val)
{
	left = right = nullptr;
	value = val;
}
template<class T>
AVL_tree<T>::AVL_tree(void)
{
	root = nullptr;
}
template<class T>
int AVL_tree<T>::hight(Nodes<T>*temp)
{
	int h = 0;
	if (temp != nullptr)
	{
		int lh = hight(temp->left);
		int rh = hight(temp->right);
		int max_hight = max(lh, rh);
		h = max_hight + 1;
	}
	return h;
}
template<class T>
int AVL_tree<T>::different(Nodes<T>*temp)
{
	int lh = hight(temp->left);
	int rh = hight(temp->right);
	int diff = lh - rh;
	return diff;
}
template<class T>
Nodes<T>* AVL_tree<T>::rr_rotation(Nodes<T>*parent)
{
	Nodes<T>*temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	if (parent == root)
		root = temp;
	return temp;
}
template<class T>
Nodes<T>* AVL_tree<T>::ll_rotation(Nodes<T>*parent)
{
	Nodes<T>*temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	if (parent == root)
		root = temp;
	return temp;
}
template<class T>
Nodes<T>* AVL_tree<T>::lr_rotation(Nodes<T>*parent)
{
	Nodes<T>*temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}
template<class T>
Nodes<T>* AVL_tree<T>::rl_rotation(Nodes<T>*parent)
{
	Nodes<T>*temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}
template<class T>
Nodes<T>* AVL_tree<T>::balance(Nodes<T>*temp)
{
	int balanced = different(temp);
	if (balanced>1)
	{
		if (different(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (balanced < -1)
	{
		if (different(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}
template<class T>
Nodes<T> *AVL_tree<T>::insert(Nodes<T> *start, T value)
{
	assert(!contains(value));
	if (root == nullptr)
	{
		Nodes<T>*newNodes = new Nodes<T>(value);
		root = newNodes;
		return start;
	}
	if (start == nullptr)
	{
		Nodes<T>*newNodes = new Nodes<T>(value);
		start = newNodes;
		return start;
	}
	else if (value < start->value)
	{
		start->left = insert(start->left, value);
		start = balance(start);
	}
	else if (value > start->value)
	{
		start->right = insert(start->right, value);
		start = balance(start);
	}
	return start;
}
template<class T>
void AVL_tree<T>::leaf_Nodes(Nodes<T>*start, Nodes<T>*parant, Nodes<T>* val)
{
	if (start->left != nullptr)
	{
		leaf_Nodes(start->left, start, val);
		if (parant->left == start)
			parant->left = balance(start);
		else
			parant->right = balance(start);
	}
	else if (start->left == nullptr)
	{
		if (parant->left == start&&start->right == nullptr)
			parant->left = nullptr;
		else if (parant->left == start&&start->right != nullptr)
			parant->left = start->right;
		else	if (parant->right == start&&start->right == nullptr)
			parant->right = nullptr;
		else if (parant->right == start&&start->right != nullptr)
			parant->right = start->right;
		val->value = start->value;

		delete start;
	}
}
template<class T>
Nodes<T>* AVL_tree<T>::remove(Nodes<T> *start, T value, Nodes<T>*parant)
{
	assert(contains(value));
	if (start->value == value)
	{
		if (start->left == nullptr&&start->right == nullptr)
		{
			if (parant->left != nullptr)
			{
				if (parant->left->value == value)
					parant->left = nullptr;
			}
			if (parant->right != nullptr)
			{
				if (parant->right->value == value)
					parant->right = nullptr;
			}
			delete start;
		}
		else if ((start->left != nullptr&&start->right == nullptr) || (start->left == nullptr&&start->right != nullptr))
		{
			if (start->left != nullptr&&start->right == nullptr)
			{
				if (start->value>parant->value)
				{
					parant->right = start->left;
					delete start;
				}
				else if (start->value<parant->value)
				{
					parant->left = start->left;
					delete start;
				}
			}
			else if (start->left == nullptr&&start->right != nullptr)
			{
				if (start->value>parant->value)
				{
					parant->right = start->right;
					delete start;
				}
				else if (start->value<parant->value)
				{
					parant->left = start->right;
					delete start;
				}
			}
		}
		else
		{
			bool rooot = false;
			if (root->value == value)
				rooot = true;
			leaf_Nodes(start->right, start, start);

			Nodes<T>*test = balance(start);

			if (rooot)
				root = test;
			else
			{
				if (test->value<parant->value)
					parant->left = test;
				else
					parant->right = test;
			}
		}
	}
	else if (value < start->value)
	{
		remove(start->left, value, start);
		start = balance(start);
	}
	else if (value > start->value)
	{
		remove(start->right, value, start);
		start = balance(start);
	}
	return start;
}


template<class T>
void AVL_tree<T>::preOrder(Nodes<T>* start)
{
	if (start != nullptr)
	{
		cout << start->value << endl;
		preOrder(start->left);
		preOrder(start->right);
	}
}
template <class T>
bool AVL_tree<T>::contains(T val)
{
	Nodes<T>* tmp = findNodes(val);

	return (tmp != nullptr);
}
template <class T>
Nodes<T>* AVL_tree<T>::findNodes(T val)
{
	Nodes<T>* tmp = root;
	while ((tmp != nullptr) && (tmp->value != val))
		if (tmp->value>val)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	return tmp;
}
template <class T>
void AVL_tree<T>::add(T val)
{
	insert(root, val);
}
template <class T>
void AVL_tree<T>::del(T val)
{
	remove(root, val, nullptr);
}
template<class T>
AVL_tree<T>::~AVL_tree(void)
{
}
