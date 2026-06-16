#include <iostream>
#include "avltree.h"

void printValue(int value) {
    std::cout << value << " ";
}

int main() {
    AVLTree<int> avlTree;

    std::cout << "Elements: 5, 3, 2, 4, 7, 6, 8" << std::endl;
    avlTree.insert(5);
    std::cout << std::endl;
    avlTree.printTree();

    avlTree.insert(3);
    std::cout << std::endl;
    avlTree.printTree();

    avlTree.insert(2);
    std::cout << std::endl;
    avlTree.printTree();

    avlTree.insert(4);
    std::cout << std::endl;
    avlTree.printTree();

    avlTree.insert(7);
    std::cout << std::endl;
    avlTree.printTree();

    avlTree.insert(6);
    std::cout << std::endl;
    avlTree.printTree();

    avlTree.insert(8);

    std::cout << std::endl;
    avlTree.printTree();

    std::cout << std::endl;
    avlTree.inorder(printValue);

    std::cout << std::endl;
    avlTree.preorder(printValue);

    std::cout << std::endl;
    avlTree.postorder(printValue);

    std::cout << "\n\nTree size: " << avlTree.size() << std::endl;

    std::cout << "\nRemoving elements: 2, 3, 5" << std::endl;
    avlTree.remove(2);
    std::cout << std::endl;
    avlTree.printTree();
    avlTree.remove(3);
    std::cout << std::endl;
    avlTree.printTree();
    avlTree.remove(5);

    std::cout << std::endl;
    avlTree.printTree();

    std::cout << std::endl;
    avlTree.inorder(printValue);

    std::cout << "\n\nFinding elements:" << std::endl;
    std::cout << "Find 7: " << (avlTree.find(7) ? "Found" : "Not Found") << std::endl;
    std::cout << "Find 5: " << (avlTree.find(5) ? "Found" : "Not Found") << std::endl;

    std::cout << std::endl;
    avlTree.clear();

    std::cout << "Tree size: " << avlTree.size() << std::endl;

    return 0;
}
