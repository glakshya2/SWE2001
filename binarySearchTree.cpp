#include <iostream>
using namespace std;

class BST
{
public:
	int data;
	BST *left, *right;
	BST();
	BST(int);
	BST *Insert(BST *, int);
	void Inorder(BST *);
	BST *removeNode(BST *, int);
};

BST::BST()
{
	data = 0;
	left = right = NULL;
}

BST::BST(int value)
{
	data = value;
	left = right = NULL;
}

BST *BST::Insert(BST *root, int value)
{
	if (!root)
	{
		return new BST(value);
	}
	if (value > root->data)
	{
		root->right = Insert(root->right, value);
	}
	else if (value < root->data)
	{
		root->left = Insert(root->left, value);
	}
	return root;
}

void BST::Inorder(BST *root)
{
	if (!root)
	{
		return;
	}
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

int getRightMin(BST *root)
{
	BST *temp = root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->data;
}

BST *BST::removeNode(BST *root, int key)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data < key)
	{
		root->right = removeNode(root->right, key);
	}
	else if (root->data > key)
	{
		root->left = removeNode(root->left, key);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if (root->left == NULL)
		{
			BST *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			BST *temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			int rightMin = getRightMin(root->right);
			root->data = rightMin;
			root->right = removeNode(root->right, rightMin);
		}
	}
	return root;
}

int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	root = b.Insert(root, 30);
	root = b.Insert(root, 20);
	root = b.Insert(root, 40);
	root = b.Insert(root, 70);
	root = b.Insert(root, 60);
	root = b.Insert(root, 80);
	b.Inorder(root);
	cout << endl;
	root = b.removeNode(root, 50);
	b.Inorder(root);
	return 0;
}