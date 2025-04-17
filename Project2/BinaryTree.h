#pragma once

#include <iostream>
#include <string.h>

template<typename T>
class BinaryTree
{
private:

	struct Node  //nested class
	{
		T data;
		Node* left;
		Node* right;
		explicit Node(T value) : data(value), left(nullptr), right(nullptr) {}
	};


	Node* root;


	bool insert(Node*& node, T value) //ми можемо змінювати сам вказівник Node*
	{
		if (node == nullptr)
		{
			node = new Node(value);
			return true;
		}
		else if (value < node->data)
		{
			insert(node->left, value);
		}
		else if (value > node->data)
		{
			insert(node->right, value);
		}

		return false;
	}


	void inorder(Node* node) const //обхід дерева left->root->right
	{
		if (node != nullptr)
		{
			inorder(node->left);
			std::cout << node->data << " ";
			inorder(node->right);
		}
	}

	void preorder(Node* node) const //обхід дерева root->left->right
	{
		if (node != nullptr)
		{
			std::cout << node->data << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}

	void postorder(Node* node) const //обхід дерева left->right->root
	{
		if (node != nullptr)
		{
			postorder(node->left);
			postorder(node->right);
			std::cout << node->data << " ";
		}
	}

	void destroy(Node* node)
	{
		if (node != nullptr)
		{
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}

	bool find(Node* node, T value) const
	{
		if (node == nullptr)
			return false;
		if (node->data == value)
			return true;
		else if (value < node->data)
			return find(node->left, value);
		else
			return find(node->right, value);
	}

public:

	BinaryTree() : root(nullptr) {};

	BinaryTree(const BinaryTree&) = delete;
	BinaryTree& operator=(const BinaryTree&) = delete;

	BinaryTree(BinaryTree&& other) noexcept : root(other.root)  //r-value reference
	{
		other.root = nullptr;
	}

	BinaryTree& operator=(BinaryTree&& other) noexcept
	{
		if (*this != other)
		{
			destroy(root);
			root = other.root;
			other.root = nullptr;
		}
		return *this;
	}

	bool isEmpty() const
	{
		return root == nullptr;
	}

	~BinaryTree() //деструктор
	{
		destroy(root);
	}

	void insert(T value)
	{
		insert(root, value);
	}

	void inorder() const
	{
		inorder(root);
		std::cout << std::endl;
	}

	void preorder() const
	{
		preorder(root);
		std::cout << std::endl;
	}

	void postorder() const
	{
		postorder(root);
		std::cout << std::endl;
	}

	bool find(const T& value) const
	{
		return find(root, value);
	}

	void print(std::string type)
	{
		if (type == "inorder") {
			inorder();
		}
		else if (type == "preorder") {
			preorder();
		}
		else if (type == "postorder") {
			postorder();
		}
		else {
			std::cout << "Invalid traversal type: " << type << std::endl;
		}
	}
};