#pragma once
template<class T>
class Nodes
{

public:
	T value;
	Nodes<T>*left;
	Nodes<T>*right;
	Nodes();
	Nodes(T val);
};
template<class T>
class AVL_tree
{
public:
	Nodes<T>*root;
	AVL_tree(void);
	int hight(Nodes<T>*start);
	int different(Nodes<T>*start);
	Nodes<T>*rr_rotation(Nodes<T>*start);
	Nodes<T>*rl_rotation(Nodes<T>*start);
	Nodes<T>*ll_rotation(Nodes<T>*start);
	Nodes<T>*lr_rotation(Nodes<T>*start);
	Nodes<T>*balance(Nodes<T>*start);
	Nodes<T>*insert(Nodes<T>*start, T val);
	Nodes<T>* findNodes(T val);
	void leaf_Nodes(Nodes<T>*start, Nodes<T>*parant, Nodes<T>* val);
	Nodes<T>* remove(Nodes<T>*start, T val, Nodes<T>*parant);
	void preOrder(Nodes<T>*start);
	bool contains(T val);
	void add(T val);
	void del(T val);
	~AVL_tree(void);
};

