#include "pch.h"
#include "Tree.h"
#include "List.h"

/*template<class T, typename Tk>
Tree<T, Tk>::Tree()
{
	root = NULL;
}

template<class T, typename Tk>
Tree<T, Tk>::~Tree()
{
	root = deleteTree(root);
}

template<class T, typename Tk>
typename Tree<T, Tk>::TreeNode *Tree<T, Tk>::newNode(Tk key, T value)
{
	TreeNode *temp = new TreeNode;
	temp->key = key;
	temp->value = value;
	temp->left = temp->right = NULL;
	return temp;
}

template<class T, typename Tk>
typename Tree<T, Tk>::TreeNode* Tree<T, Tk>::deleteTree(TreeNode* t)
{
	if (t == NULL)
		return NULL;
	{
		deleteTree(t->left);
		deleteTree(t->right);
		delete t;
	}
	return NULL;
}

template<class T, typename Tk>
typename Tree<T, Tk>::TreeNode* Tree<T, Tk>::searchByKey(TreeNode* t, int key)
{
	if (t == NULL)
	{
		return NULL;
	}
	else if(key < t->key)
	{
		return searchDeep(t->left, key);
	}
	else if (key > t->key)
	{
		return searchDeep(t->right, key);
	}
	else
	{
		return t;
	}
}

template<class T, typename Tk>
typename Tree<T, Tk>::TreeNode* Tree<T, Tk>::searchDeep(TreeNode* t, T value)
{
	if (t == NULL)
	{
		return NULL;
	}
	if (t->value == value)
	{
		return t;
	}
	searchDeep(t->left, value);
	searchDeep(t->right, value);
}

template<class T, typename Tk>
typename Tree<T, Tk>::TreeNode* Tree<T, Tk>::searchWide(TreeNode* t, T value)
{
	Queue<TreeNode> storage;
	storage.addtoQueue(t);

	TreeNode *tmp;
	while (!storage.IsEmtpy())
	{
		tmp = storage.delQueue();
		if (tmp->value == value)
		{
			return tmp;
		}

		if (tmp->left != NULL)
		{
			storage.addtoQueue(tmp->left);
		}
		if (tmp->right != NULL)
		{
			storage.addtoQueue(tmp->right);
		}
	}
	return NULL;
}

template<class T, typename Tk>
typename Tree<T, Tk>::TreeNode* Tree<T, Tk>::insert(Tk key, T value, TreeNode* node)
{
	TreeNode* newnode = newNode(key, value);
	TreeNode* x = root;
	TreeNode* y = NULL;
	while (x != NULL)
	{
		y = x;
		if (key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	if (y == NULL)
	{
		y = newnode;
	}
	else if (key < y->key)
	{
		y->left = newnode;
	}
	else
	{
		y->right = newnode;
	}
	return y;
}

template<class T, typename Tk>
void Tree<T, Tk>::Add(Tk key, T value)
{
	if (root == NULL)
	{
		root = insert(key, value, root);
	} 
	else
	{
		insert(key, value, root);
	}
}

template<class T, typename Tk>
bool Tree<T, Tk>::Remove(Tk key)
{
	TreeNode* tmp;
	searchByKey();
}

template<class T, typename Tk>
bool Tree<T, Tk>::Remove(T value, bool searchType)
{
	if (searchType)
	{

	}
	else
	{

	}
}

template<class T, typename Tk>
bool Tree<T, Tk>::Find(Tk key, T& value)
{
	if (searchByKey(root, key) != NULL)
	{
		value = searchByKey(root, key)->value;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T, typename Tk>
bool Tree<T, Tk>::Find(T value, bool searchtype)
{
	if (searchtype)
	{
		if (searchDeep(root, value) != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (searchWide(root, value) != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}*/

template<typename Tk, class T>
Tree<Tk, T>::Tree()
{
	root = NULL;
}

template<typename Tk, class T>
Tree<Tk, T>::~Tree()
{
	root = deleteTree(root);
}

template<typename Tk, class T>
typename TreeNode<Tk, T>* Tree<Tk, T>::deleteTree(TreeNode<Tk, T>* node)
{
	if (node == NULL)
		return NULL;
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
	return NULL;
}

template<typename Tk, class T>
typename TreeNode<Tk, T>* Tree<Tk, T>::newNode(Tk key, T value, int level)
{
	TreeNode<Tk, T>* temp = new TreeNode<Tk, T>;
	temp->key = key;
	temp->value = value;
	temp->level = level;
	temp->left = temp->right = temp->l_prev = temp->l_next = NULL;
	return temp;
}

template<typename Tk, class T>
typename TreeNode<Tk, T>* Tree<Tk, T>::insert(Tk key, T value)
{
	TreeNode<Tk, T>* current = root;
	TreeNode<Tk, T>* child = NULL;
	int counter = 0;
	while (current != NULL)
	{
		child = current;
		current = ((key < current->key) ? current->left : current->right);
		counter++;
	}
	TreeNode<Tk, T>* newnode = newNode(key, value, counter);
	if (child == NULL)
	{
		child = newnode;
		leftmosts.AddToEnd(child);
	}
	else if (key < child->key)
	{
		child->left = newnode;
		(!leftmosts.IfNodeByIndexExists(counter)) ? 
			leftmosts.AddToEnd(newnode) : leftmosts.Replace(leftmosts.GetValue(counter), newnode);
	}
	else
	{
		child->right = newnode;
		if (!leftmosts.IfNodeByIndexExists(counter))
		{
			leftmosts.AddToEnd(newnode);
		}
	}
	return child;
}

template<typename Tk, class T>
typename TreeNode<Tk, T>* Tree<Tk, T>::assignLevelNodes(TreeNode<Tk, T>* node, int level)
{
	if (node == NULL)
		return;
	else
	{
		assignLevelNodes(node->left, level - 1);
		{
			if (level == 0)
				return node;
			assignLevelNodes(node->right, level - 1);
		}
	}
}

template<typename Tk, class T>
void Tree<Tk, T>::Add(Tk key, T value)
{
	(root == NULL) ? root = insert(key, value) : insert(key, value);
}