#include "btclass.h"
#include "node.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void collectTraversal(vector<T>& result, T data) {
    result.push_back(data);
}

int main() {
    binary_tree<int> bt;

    bt.create_first_node(10);
    cout << "Root node: " << bt.retrieve() << endl;

    bt.shift_to_root();
    bt.current -> left = new bnode<int>(5);
    bt.current -> right = new bnode<int>(15);
    
    bt.shift_left();
    bt.current -> left = new bnode<int>(3);
    bt.current -> right = new bnode<int>(7);

    bt.shift_to_root();

    cout << "Tree size: " << bt.size() << endl;

    cout << "Inorder traversal: ";
    
    vector<int> inorderResult;
    inorder([&inorderResult](int data) { collectTraversal(inorderResult, data); }, bt.root);
    for (int val : inorderResult) cout << val << " ";
    cout << endl;

    cout << "Preorder traversal: ";
    vector<int> preorderResult;
    preorder([&preorderResult](int data) { collectTraversal(preorderResult, data); }, bt.root);
    for (int val : preorderResult) cout << val << " ";
    cout << endl;

    cout << "Postorder traversal: ";
    vector<int> postorderResult;
    postorder([&postorderResult](int data) { collectTraversal(postorderResult, data); }, bt.root);
    for (int val : postorderResult) cout << val << " ";
    cout << endl;

    cout << "Tree structure:\n";
    print(bt.root, 0);

    bnode<int>* copiedTree = tree_copy(bt.root);
    cout << "Copied tree structure:\n";
    print(copiedTree, 0);

    bnode<int>* rootPtr = bt.root;
    tree_clear(rootPtr);
    if (bt.root == nullptr) {
        cout << "Original tree cleared successfully!" << endl;
    }

    tree_clear(copiedTree);
    if (copiedTree == nullptr) {
        cout << "Copied tree cleared successfully!" << endl;
    }

    return 0;
}
