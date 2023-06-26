#include "BinaryTree.h"
using namespace std;

template<typename T>
Node<T>::Node(const T& value) : data(value), left(nullptr), right(nullptr) {}

template<typename T>
void Node<T>::insert(const T& value) {
    if (value < data) {
        if (left == nullptr) {
            left = new Node<T>(value);
        }
        else {
            left->insert(value);
        }
    }
    else if (value > data) {
        if (right == nullptr) {
            right = new Node<T>(value);
        }
        else {
            right->insert(value);
        }
    }
}

template<typename T>
void Node<T>::preOrderTraversal() {
    std::cout << data << " ";

    if (left)
        left->preOrderTraversal();

    if (right)
        right->preOrderTraversal();
}

template<typename T>
int Node<T>::getSize() {
    int size = 1;
    if (left) {
        size += left->getSize();
    }
    if (right) {
        size += right->getSize();
    }
    return size;
}

template<typename T>
Node<T>* Node<T>::search(const T& key) {
    if (key == data) {
        return this;
    }
    else if (key < data) {
        if (left) {
            return left->search(key);
        }
    }
    else {
        if (right) {
            return right->search(key);
        }
    }
    return nullptr;
}

template<typename T>
void Node<T>::printTree(int level) {
    if (this == nullptr)
        return;

    right->printTree(level + 1);

    for (int i = 0; i < level; i++)
        std::cout << "\t";

    std::cout << data << std::endl;

    left->printTree(level + 1);
}

template<typename T>
Tree<T>::Iterator::Iterator(Node<T>* node, Tree<T>* tree) : current(node), prev(nullptr), tree(tree) {}

template<typename T>
void Tree<T>::Iterator::setToRoot() {
    current = tree->root;
    prev = nullptr;
}

template<typename T>
bool Tree<T>::Iterator::isEnd() const {
    return current == nullptr;
}

template<typename T>
T& Tree<T>::Iterator::getData() const {
    if (current)
        return current->data;
    throw std::runtime_error("Invalid iterator: Iterator is not pointing to a valid node.");
}

template<typename T>
void Tree<T>::Iterator::next() {
    if (current != nullptr) {
        if (current->right != nullptr) {
            current = current->right;
            while (current->left != nullptr) {
                current = current->left;
            }
        }
        else {
            prev = current;
            current = tree->findNext(current->data);
        }
    }
}

template<typename T>
Tree<T>::Tree() : root(nullptr) {}

template<typename T>
Node<T>* Tree<T>::findNext(const T& key) const {
    Node<T>* currentNode = root;
    Node<T>* successor = nullptr;

    while (currentNode != nullptr) {
        if (key < currentNode->data) {
            successor = currentNode;
            currentNode = currentNode->left;
        }
        else if (key > currentNode->data) {
            currentNode = currentNode->right;
        }
        else {
            if (currentNode->right != nullptr) {
                successor = currentNode->right;
                while (successor->left != nullptr) {
                    successor = successor->left;
                }
            }
            break;
        }
    }
    return successor;
}

template<typename T>
void Tree<T>::insert(const T& value) {
    if (root == nullptr) {
        root = new Node<T>(value);
    }
    else {
        root->insert(value);
    }
}

template<typename T>
void Tree<T>::print() {
    if (root == nullptr) {
        std::cout << "The tree is empty." << std::endl;
    }
    else {
        root->printTree(0);
    }
}

template<typename T>
int Tree<T>::getSize() {
    if (root) {
        return root->getSize();
    }
    return 0;
}

template<typename T>
void Tree<T>::generateIntTree(int size) {
    if (size <= 0) {
        std::cout << "The size of the tree must be greater than 0." << std::endl;
        return;
    }

    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        int value = rand() % 100;
        insert(value);
    }
}

template<typename T>
void Tree<T>::generateCharTree(int size) {
    if (size <= 0) {
        std::cout << "The size of the tree must be greater than 0." << std::endl;
        return;
    }

    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        char value = 'A' + rand() % 26;
        insert(value);
    }
}

template<typename T>
bool Tree<T>::isEmpty() {
    return (root == nullptr);
}

template<typename T>
void Tree<T>::printRoot() {
    if (root) {
        std::cout << "Value of the root node: " << root->data << std::endl;
    }
    else {
        std::cout << "The tree is empty." << std::endl;
    }
}

template<typename T>
Node<T>* Tree<T>::search(const T& key) {
    if (root) {
        return root->search(key);
    }
    return nullptr;
}

template<typename T>
void Tree<T>::preOrderTraversal() {
    if (root) {
        std::cout << "Pre-order traversal of the tree: ";
        root->preOrderTraversal();
        std::cout << std::endl;
    }
}
