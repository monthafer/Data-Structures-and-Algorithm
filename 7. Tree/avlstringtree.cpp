#include <iostream>
#include "avltree.h"
#include "../String/mystring.h"

void printValue(MyString value) {
    std::cout << value << " ";
}

int main() {
    AVLTree<MyString> avlTree;
    MyString cat = "cat";
    MyString dog = "dog";
    MyString fish = "fish";
    MyString giraffee = "giraffee";
    MyString shrimp = "shrimp";
    MyString tuna = "tuna";
    MyString jackass = "jackass";

    std::cout << "Elements: cat, dog, fish, giraffee, shrimp, tuna, jackass" << std::endl;
    avlTree.insert(cat);
    // std::cout << std::endl;
    // avlTree.printTree();

    avlTree.insert(dog);
    // std::cout << std::endl;
    // avlTree.printTree();

    avlTree.insert(fish);
    // std::cout << std::endl;
    // avlTree.printTree();

    avlTree.insert(giraffee);
    // std::cout << std::endl;
    // avlTree.printTree();

    avlTree.insert(shrimp);
    // std::cout << std::endl;
    // avlTree.printTree();

    avlTree.insert(tuna);
    // std::cout << std::endl;
    // avlTree.printTree();

    avlTree.insert(jackass);

    std::cout << std::endl;
    avlTree.printTree();

    std::cout << std::endl;
    avlTree.inorder(printValue);

    std::cout << std::endl;
    avlTree.preorder(printValue);

    std::cout << std::endl;
    avlTree.postorder(printValue);

    std::cout << "\n\nTree size: " << avlTree.size() << std::endl;

    std::cout << "\nRemoving elements: jackass, shrimp, giraffee" << std::endl;
    avlTree.remove(jackass);
    // std::cout << std::endl;
    // avlTree.printTree();
    avlTree.remove(shrimp);
    // std::cout << std::endl;
    // avlTree.printTree();
    avlTree.remove(giraffee);

    std::cout << std::endl;
    avlTree.printTree();

    std::cout << std::endl;
    avlTree.inorder(printValue);

    std::cout << "\n\nFinding elements:" << std::endl;
    std::cout << "Find dog: " << (avlTree.find(dog) ? "Found" : "Not Found") << std::endl;
    std::cout << "Find shrimp: " << (avlTree.find(shrimp) ? "Found" : "Not Found") << std::endl;

    std::cout << std::endl;
    avlTree.clear();

    std::cout << "Tree size: " << avlTree.size() << std::endl;

    return 0;
}
