#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Tree;

template<typename T>
class Node {
public:
    T data;
    Node<T>* left, * right;
    Node<T>* parent;
    Node(const T& value);
    void insert(const T& value);
    void preOrderTraversal();
    int getSize();
    Node<T>* search(const T& key);
    void printTree(int level);
    friend class Tree<T>;
};

template<typename T>
class Tree {
private:
    Node<T>* root;
public:
    class Iterator {
    private:
        Node<T>* current;
        Node<T>* prev;
        Tree<T>* tree;
    public:
        Iterator(Node<T>* node, Tree<T>* Tree);
        void setToRoot();
        bool isEnd() const;
        T& getData() const;
        void next();
    };

    Tree();
    Node<T>* findNext(const T& key) const;
    void insert(const T& value);
    void print();
    int getSize();
    void generateIntTree(int size);
    void generateCharTree(int size);
    bool isEmpty();
    void printRoot();
    Node<T>* search(const T& key);
    void preOrderTraversal();
};






//#include <iostream>
//using namespace std;
//
//template<typename T>
//class Tree;
//
//template<typename T>
//class Node
//{
//public:
//    T data;
//    Node<T>* left, * right;
//    Node<T>* parent;
//
//    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
//
//    void insert(const T& value)
//    {
//        if (value < data)
//        {
//            if (left == nullptr)
//            {
//                left = new Node<T>(value);
//            }
//            else
//            {
//                left->insert(value);
//            }
//        }
//        else if (value > data)
//        {
//            if (right == nullptr)
//            {
//                right = new Node<T>(value);
//            }
//            else
//            {
//                right->insert(value);
//            }
//        }
//    }
//
//    void preOrderTraversal()
//    {
//        cout << data << " ";
//
//        if (left)
//            left->preOrderTraversal();
//
//        if (right)
//            right->preOrderTraversal();
//    }
//
//    int getSize()
//    {
//        int size = 1;
//        if (left)
//        {
//            size += left->getSize();
//        }
//        if (right)
//        {
//            size += right->getSize();
//        }
//        return size;
//    }
//
//    Node<T>* search(const T& key)
//    {
//        if (key == data)
//        {
//            return this;
//        }
//        else if (key < data)
//        {
//            if (left)
//            {
//                return left->search(key);
//            }
//        }
//        else
//        {
//            if (right)
//            {
//                return right->search(key);
//            }
//        }
//        return nullptr;
//    }
//
//    void printTree(int level)
//    {
//        if (this == nullptr)
//            return;
//
//        right->printTree(level + 1);
//
//        for (int i = 0; i < level; i++)
//            cout << "\t";
//
//        cout << data << endl;
//
//        left->printTree(level + 1);
//    }
//
//    friend class Tree<T>;
//};
//
//template<typename T>
//class Tree
//{
//private:
//    Node<T>* root;
//public:
//    class Iterator {
//    private:
//        Node<T>* current;
//        Node<T>* prev;
//        Tree<T>* tree;
//
//    public:
//        Iterator(Node<T>* node, Tree<T>* Tree) : current(node), prev(nullptr), tree(Tree) {}
//
//        void setToRoot() {
//            current = tree->root;
//            prev = nullptr;
//        }
//
//        bool isEnd() const {
//            return current == nullptr;
//        }
//
//        T& getData() const {
//            if (current)
//                return current->data;
//            throw std::runtime_error("Invalid iterator: Iterator is not pointing to a valid node.");
//        }
//
//        void next() {
//            if (current != nullptr) {
//                if (current->right != nullptr) {
//                    current = current->right;
//                    while (current->left != nullptr) {
//                        current = current->left;
//                    }
//                }
//                else {
//                    prev = current;
//                    current = tree->findNext(current->data);
//                }
//            }
//        }
//    };
//
//    Tree() : root(nullptr) {}
//
//    Node<T>* findNext(const T& key) const {
//        Node<T>* currentNode = root;
//        Node<T>* successor = nullptr;
//
//        while (currentNode != nullptr) {
//            if (key < currentNode->data) {
//                successor = currentNode;
//                currentNode = currentNode->left;
//            }
//            else if (key > currentNode->data) {
//                currentNode = currentNode->right;
//            }
//            else {
//                if (currentNode->right != nullptr) {
//                    successor = currentNode->right;
//                    while (successor->left != nullptr) {
//                        successor = successor->left;
//                    }
//                }
//                break;
//            }
//        }
//        return successor;
//    }
//
//    void insert(const T& value)
//    {
//        if (root == nullptr)
//        {
//            root = new Node<T>(value);
//        }
//        else
//        {
//            root->insert(value);
//        }
//    }
//
//    void print()
//    {
//        if (root == nullptr)
//        {
//            cout << "The tree is empty." << endl;
//        }
//        else
//        {
//            root->printTree(0);
//        }
//    }
//
//    int getSize()
//    {
//        if (root)
//        {
//            return root->getSize();
//        }
//        return 0;
//    }
//
//    void generateIntTree(int size)
//    {
//        if (size <= 0)
//        {
//            cout << "The size of the tree must be greater than 0." << endl;
//            return;
//        }
//
//        srand(time(nullptr));
//        for (int i = 0; i < size; i++)
//        {
//            int value = rand() % 100;
//            insert(value);
//        }
//    }
//
//    void generateCharTree(int size)
//    {
//        if (size <= 0)
//        {
//            cout << "The size of the tree must be greater than 0." << endl;
//            return;
//        }
//
//        srand(time(nullptr));
//        for (int i = 0; i < size; i++)
//        {
//            char value = 'A' + rand() % 26;
//            insert(value);
//        }
//    }
//
//    bool isEmpty()
//    {
//        return (root == nullptr);
//    }
//
//    void printRoot() {
//        if (root) {
//            cout << "Value of the root node: " << root->data << endl;
//        }
//        else {
//            cout << "The tree is empty." << endl;
//        }
//    }
//
//    Node<T>* search(const T& key)
//    {
//        if (root)
//        {
//            return root->search(key);
//        }
//        return nullptr;
//    }
//
//    void preOrderTraversal()
//    {
//        if (root)
//        {
//            cout << "Pre-order traversal of the tree: ";
//            root->preOrderTraversal();
//            cout << endl;
//        }
//    }
//};