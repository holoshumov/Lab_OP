#pragma once
#include "BinaryTree.h"


/*Спроектувати АТД "Бінарне дерево" для колекції, що містить дані довільного типу. Інтерфейс АТД включає такі обов'язкові операції (у рекурсивній формі):
//визначення розміру дерева,
//перевірка дерева на пустоту,
//- ітератор для доступу до елементів дерева з операціями:
//1) встановлення на корінь дерева,
//2) перевірка кінця дерева,
//3) доступ до даних поточного елемента дерева,
//4) перехід до наступного за значенням ключа елементу дерева,
//прямий обхід дерева (за схемою > Lt -Rt),
//пошук елемента із заданим ключем*/
//
//#include <iostream>
//#include <stack>
//using namespace std;
//
//template<typename T>
//class Tree;
//
//template<typename T>
//class Node
//{
//private:
//    T data;
//    Node<T>* left, * right;
//public:
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
//    void print()
//    {
//        std::cout << data << " ";
//        if (left)
//        {
//            left->print();
//        }
//        if (right)
//        {
//            right->print();
//        }
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
//    friend class Tree<T>;
//};
//
//template<typename T>
//class Tree
//{
//private:
//    Node<T>* root;
//public:
//    Tree() : root(nullptr) {}
//
//    void print()
//    {
//        if (root)
//        {
//            root->print();
//        }
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
//    int getSize()
//    {
//        if (root)
//        {
//            return root->getSize();
//        }
//        return 0;
//    }
//};
//
//template<typename T>
//class TreeIterator
//{
//private:
//    Node<T>* current;
//    std::stack<Node<T>*> parentStack;
//
//public:
//    TreeIterator(Node<T>* root = nullptr)
//    {
//        current = root;
//        initializeIterator();
//    }
//
//    void initializeIterator()
//    {
//        while (current)
//        {
//            parentStack.push(current);
//            current = current->left;
//        }
//    }
//
//    void setCurrent(Node<T>* node)
//    {
//        current = node;
//        initializeIterator();
//    }
//
//    bool isEnd() const
//    {
//        return (current == nullptr) && parentStack.empty();
//    }
//
//    T& getData() const
//    {
//        if (current)
//        {
//            return current->data;
//        }
//        throw std::runtime_error("Invalid iterator");
//    }
//
//    void next()
//    {
//        if (current)
//        {
//            if (current->right)
//            {
//                current = current->right;
//                initializeIterator();
//            }
//            else if (!parentStack.empty())
//            {
//                current = parentStack.top();
//                parentStack.pop();
//            }
//            else
//            {
//                current = nullptr;
//            }
//        }
//    }
//
//    Node<T>* search(const T& key)
//    {
//        Node<T>* node = current;
//        while (node)
//        {
//            if (key == node->data)
//            {
//                return node;
//            }
//            else if (key < node->data)
//            {
//                node = node->left;
//            }
//            else
//            {
//                node = node->right;
//            }
//        }
//        return nullptr; // Key not found
//    }
//};
//
//
//
// 
//        int main()
//        {
//            
//            return 0;
//        }
//
