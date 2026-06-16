#include "avltree.h"

template <class value_type>
AVLTree<value_type>::AVLTree(){
    root = nullptr;
}

template <class value_type>
AVLTree<value_type>::~AVLTree() {
    clear();
}

//-------------------------------------------------------------------------
//private func
template <class value_type>
int AVLTree<value_type>::getHeight(avnode<value_type>* node) const {
    if (node != nullptr) {
        return node -> height;
    } else {
        return 0;
    }
}

template <class value_type>
avnode<value_type>* AVLTree<value_type>::rightRotate(avnode<value_type>* y) {
    avnode<value_type>* x = y -> left;
    avnode<value_type>* T2 = x -> right;

    x -> right = y;
    y -> left = T2;

    // if (getHeight(y->left) > getHeight(y->right)) {
    //     y->height = getHeight(y->left) + 1;
    // } else {
    //     y->height = getHeight(y->right) + 1;
    // }

    // if (getHeight(x->left) > getHeight(x->right)) {
    //     x->height = getHeight(x->left) + 1;
    // } else {
    //     x->height = getHeight(x->right) + 1;
    // }

    y -> height = std::max(getHeight(y -> left), getHeight(y -> right)) + 1;
    x -> height = std::max(getHeight(x -> left), getHeight(x -> right)) + 1;

    return x;
}

template <class value_type>
avnode<value_type>* AVLTree<value_type>::leftRotate(avnode<value_type>* x) {
    avnode<value_type>* y = x -> right;
    avnode<value_type>* T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    x -> height = std::max(getHeight(x -> left), getHeight(x -> right)) + 1;
    y -> height = std::max(getHeight(y -> left), getHeight(y -> right)) + 1;

    return y;
}

template <class value_type>
int AVLTree<value_type>::getBalanceFactor(avnode<value_type>* node) const {
    if (node != nullptr) {
        return getHeight(node -> left) - getHeight(node -> right);
    } else {
        return 0;
    }
}

template <class value_type>
avnode<value_type>* AVLTree<value_type>::balance(avnode<value_type>* node) {
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        if (getBalanceFactor(node -> left) < 0) {
            node -> left = leftRotate(node -> left);
        }
        return rightRotate(node);
    }

    if (balanceFactor < -1) {
        if (getBalanceFactor(node -> right) > 0) {
            node -> right = rightRotate(node -> right);
        }
        return leftRotate(node);
    }

    return node;
}

template <class value_type>
avnode<value_type>* AVLTree<value_type>::insert(avnode<value_type>* node, const value_type& value) {
    if (!node) {
        return new avnode<value_type>(value);
    }

    if (value < node -> data) {
        node -> left = insert(node->left, value);
    } else if (value > node -> data) {
        node -> right = insert(node -> right, value);
    } else {
        return node;
    }

    node -> height = 1 + std::max(getHeight(node -> left), getHeight(node -> right));

    return balance(node);
}

template <class value_type>
avnode<value_type>* AVLTree<value_type>::deleteNode(avnode<value_type>* node, const value_type& value) {
    if (!node) {
        return nullptr;
    }

    if (value < node -> data) {
        node -> left = deleteNode(node -> left, value);
    } else if (value > node -> data) {
        node -> right = deleteNode(node -> right, value);
    } else {
        if (!node -> left || !node -> right) {
            avnode<value_type>* temp = node -> left ? node -> left : node -> right;
            delete node;
            return temp;
        }

        avnode<value_type>* temp = getMinValueNode(node->right);
        node -> data = temp -> data;
        node -> right = deleteNode(node -> right, temp -> data);
    }

    if (node == nullptr) {
        return nullptr;
    }

    node -> height = 1 + std::max(getHeight(node -> left), getHeight(node -> right));

    return balance(node);
}

template <class value_type>
avnode<value_type>* AVLTree<value_type>::getMinValueNode(avnode<value_type>* node) const {
    avnode<value_type>* current = node;
    while (current && current -> left) {
        current = current -> left;
    }
    return current;
}

template <class value_type>
void AVLTree<value_type>::clear(avnode<value_type>*& node) {
    if (!node) {
        return;
    }
    clear(node -> left);
    clear(node -> right);
    delete node;
    node = nullptr;
}

template <class value_type>
std::size_t AVLTree<value_type>::getSize(avnode<value_type>* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + getSize(node -> left) + getSize(node -> right);
}

template <class value_type>
template <class Process>
void AVLTree<value_type>::inorder(avnode<value_type>* node, Process process) const {
    if (!node) return;
    inorder(node -> left, process);
    process(node -> data);
    inorder(node -> right, process);
}

template <class value_type>
template <class Process>
void AVLTree<value_type>::preorder(avnode<value_type>* node, Process process) const {
    if (!node) return;
    process(node -> data);
    preorder(node -> left, process);
    preorder(node -> right, process);
}

template <class value_type>
template <class Process>
void AVLTree<value_type>::postorder(avnode<value_type>* node, Process process) const {
    if (!node) return;
    postorder(node -> left, process);
    postorder(node -> right, process);
    process(node -> data);
}

template <class value_type>
const avnode<value_type>* AVLTree<value_type>::find(const avnode<value_type>* node, const value_type& key) const {
    if (!node) return nullptr;
    if (key < node -> data) return find(node -> left, key);
    if (key > node -> data) return find(node -> right, key);
    return node;
}

//-------------------------------------------------------------------------
//public func
template <class value_type>
void AVLTree<value_type>::insert(const value_type& value) {
    root = insert(root, value);
}

template <class value_type>
void AVLTree<value_type>::remove(const value_type& value) {
    root = deleteNode(root, value);
}


template <typename value_type>
bool AVLTree<value_type>::find(const value_type& key) const {
    return find(root, key);
}

template <class value_type>
void AVLTree<value_type>::clear() {
    clear(root);
}

template <class value_type>
template <class Process>
void AVLTree<value_type>::inorder(Process process) const {
    inorder(root, process);
}

template <class value_type>
template <class Process>
void AVLTree<value_type>::preorder(Process process) const {
    preorder(root, process);
}

template <class value_type>
template <class Process>
void AVLTree<value_type>::postorder(Process process) const {
    postorder(root, process);
}

template <class value_type>
std::size_t AVLTree<value_type>::size() const {
    return getSize(root);
}

//----------------------------------------------------------------
// print tree
template <class value_type>
void AVLTree<value_type>::printTree(const avnode<value_type>* node, int depth) const {
    if (node == nullptr) {
        return;
    }
    printTree(node -> right, depth + 1);
    for (int i = 0; i < depth; ++i) {
        std::cout << "    ";
    }
    std::cout << node -> data << "\n";
    printTree(node -> left, depth + 1);
}

template <class value_type>
void AVLTree<value_type>::printTree() const {
    printTree(root, 0);
}
