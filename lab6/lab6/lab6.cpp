#include "BinaryTree.h"

int main()
{
    int choice;
    cout << "Choose the data type: (1 - int, 2 - char): ";
    cin >> choice;

    if (choice == 1)
    {
        int n;
        cout << "Enter the size of the tree: ";
        cin >> n;

        Tree<int> tree;
        tree.generateIntTree(n);
        if (tree.isEmpty())
        {
            cout << "The tree is empty.";
        }
        tree.getSize();
        tree.preOrderTraversal();
        tree.print();
        int key;
        cout << "Enter the key of the element to find: ";
        cin >> key;
        Node<int>* result = tree.search(key);
        if (result != nullptr)
        {
            cout << "Element with key " << key << " found: " << result->data << endl;
        }
        else
        {
            cout << "Element with key " << key << " not found." << endl;
        }

        cout << endl << "Test iterator:" << endl;

        tree.printRoot();

        tree.findNext(key);
        Node<int>* resultNext = tree.findNext(key);
        if (result != nullptr) {
            std::cout << "The next element after " << key << " is: " << resultNext->data << endl;
        }
        else {
            std::cout << "No next element found." << endl;
        }

        cout << endl;
    }
    else if (choice == 2)
    {
        int n;
        cout << "Enter the size of the tree: ";
        cin >> n;

        Tree<char> tree;
        tree.generateCharTree(n);
        if (tree.isEmpty())
        {
            cout << "The tree is empty.";
        }
        tree.getSize();
        tree.preOrderTraversal();
        tree.print();
        char key;
        cout << "Enter the key of the element to find: ";
        cin >> key;
        Node<char>* result = tree.search(key);
        if (result != nullptr)
        {
            cout << "Element with key " << key << " found: " << result->data << endl;
        }
        else
        {
            cout << "Element with key " << key << " not found." << endl;
        }

        cout << endl << "Test iterator:" << endl;

        tree.printRoot();

        tree.findNext(key);
        Node<char>* resultNext = tree.findNext(key);
        if (result != nullptr) {
            std::cout << "The next element after " << key << " is: " << resultNext->data << endl;
        }
        else {
            std::cout << "No next element found." << endl;
        }

        cout << endl;
    }
    else
    {
        cout << "Unsupported data type." << endl;
    }
    return 0;
}



#include "BinaryTree.cpp"