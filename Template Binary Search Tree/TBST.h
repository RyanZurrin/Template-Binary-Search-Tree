#ifndef PHYSICSFORMULA_TEMPLATEBST_H
#define PHYSICSFORMULA_TEMPLATEBST_H
#define INT_MAX 2147483647
#include <iomanip>
#include <iostream>
#include <queue>

#define COUNT 10
static int pos = 1;

template<typename T>
struct node
{
    node* left;
    node* right;
    node() : left(nullptr), right(nullptr) {}
    ~node() { delete left; delete right; }
    [[nodiscard]] int max_depth() const {
        const int left_depth = left ? left->max_depth() : 0;
        const int right_depth = right ? right->max_depth() : 0;
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }
    T item;
};


template<typename T>
class TBST
{
    node<T>* root;
    int qty;
    int max;
    /// <summary>
    /// private auxiliary method to help with adding to the tree.
    /// </summary>
    /// <param name="tree">The tree.</param>
    /// <param name="k">The key.</param>
    /// <returns>true if added: else false</returns>
    bool pAdd(node<T>* tree, T& k);
    /// <summary>
    /// private auxiliary method to help with deleting element from tree
    /// </summary>
    /// <param name="tree">The tree.</param>
    /// <param name="k">The key.</param>
    /// <returns>true if deleted: else false</returns>
    bool pDelete(node<T>*& tree, T& k);
    /// <summary>
    /// private auxiliary function called when a node is found to
    /// be deleted from the tree.
    /// </summary>
    /// <param name="tree">The tree.</param>
    /// <returns></returns>
    bool deleteNode(node<T>*& tree);
    /// <summary>
    /// Gets the predecessor node when deleting nodes what need to be relinked
    /// </summary>
    /// <param name="tree">The tree.</param>
    /// <param name="k">The k.</param>
    static void getPredecessor(node<T>* tree, T& k);
    /// <summary>
    /// Counts the nodes.
    /// </summary>
    /// <param name="tree">The tree.</param>
    /// <returns></returns>
    static int countNodes(node<T>* tree);

    static int countLeftNodes(node<T>* tree);

    static int countRightNodes(node<T>* tree);
    /// <summary>
    /// Retrieves the specified tree.
    /// </summary>
    /// <param name="tree">The tree.</param>
    /// <param name="k">The k.</param>
    /// <param name="found">The found.</param>
    /// <returns></returns>
    bool retrieve(node<T>* tree, T k, T& found)const;
    /// <summary>
    /// Copies the tree.
    /// </summary>
    /// <param name="copy">The copy.</param>
    /// <param name="originalTree">The original tree.</param>
    static void copyTree(node<T>*& copy, const node<T>* originalTree);
    /// <summary>
    /// Destroys the specified tree.
    /// </summary>
    /// <param name="tree">The tree.</param>
    void destroy(node<T>*& tree);
    /// <summary>
    /// Prints the tree.
    /// </summary>
    /// <param name="tree">The tree.</param>
    /// <param name="os">The os.</param>
    static void printTree(node<T>* tree);
    /// <summary>
    /// auxiliary pre-order traversal helper
    /// </summary>
    /// <param name="tree">The tree.</param>
    static void preOrderHelper(node<T>* tree);
    /// <summary>
    /// auxiliary in-order traversal helper
    /// </summary>
    /// <param name="tree">The tree.</param>
    static void inOrderHelper(node<T>* tree);
    /// <summary>
    /// auxiliary post-order traversal helper
    /// </summary>
    /// <param name="tree">The tree.</param>
    static void postOrderHelper(node<T>* tree);
    /// <summary>
    /// auxiliary breadth-first-order traversal helper
    /// </summary>
    /// <param name="tree">The tree.</param>
    static void breadthFirstHelper(node<T>* tree);
    /// <summary>
    /// auxiliary reverse-order traversal helper
    /// </summary>
    /// <param name="tree">The tree.</param>
    static void reverseOrderHelper(node<T>* tree);
    /// <summary>
    /// auxiliary 2D-order traversal helper
    /// </summary>
    /// <param name="tree">The tree.</param>
    /// <param name="space">The space between nodes.</param>
    static void twoDimensionalHelper(node<T>* tree, int space);

public:
    /// <summary>
    /// Initializes a new instance of the <see cref="Bll"/> class.
    /// </summary>
    TBST();

    /// <summary>
    /// Initializes a new instance of the <see cref="Bll"/> class.
    /// </summary>
    /// <param name="maxSize">The maximum size.</param>
    explicit TBST(int maxSize);


    /// <summary>
    /// Copy Constructor initializes a new instance of the
    /// <see cref="Bll"/> class.
    /// </summary>
    /// <param name="originalTree">The original tree.</param>
    TBST(const TBST& other);

    /// <summary>
    /// Move Constructor initializes a new instance of the
    /// <see cref="Bll"/> class.
    /// </summary>
    /// <param name="originalTree">The original tree.</param>
    TBST(TBST&& other) noexcept;

    /// <summary>
    /// copy assignment operator
    /// </summary>
    /// <param name="originalTree">The original tree.</param>
    TBST& operator=(const TBST& other);


    /// <summary>
    /// Move operator= copies from the specified original tree.
    /// </summary>
    /// <param name="originalTree">The original tree.</param>
    TBST& operator=(TBST&& originalTree) noexcept;

    /// <summary>
    /// copy assignment operator
    /// </summary>
    /// <param name="originalTree">The original tree.</param>


    /// <summary>
    /// Allows the user to pass one of these into traverseTree method and get
    /// a tree printed out in the order they wish
    /// </summary>
    enum  OrderType {
        PRE_ORDER,
        IN_ORDER,
        POST_ORDER,
        BREADTH_FIRST,
        REVERSE_ORDER,
        TWO_DIMENSIONS
    };
    /// <summary>
    /// Adds item to the tree
    /// </summary>
    /// <param name="k">The key value.</param>
    /// <returns>true if added: else false</returns>
    bool addItem(T k);


    /// <summary>
    /// Deletes the item.
    /// </summary>
    /// <param name="k">The k.</param>
    /// <returns></returns>
    bool deleteItem(T k);
    /// <summary>
    /// Determines whether this instance is empty.
    /// </summary>
    /// <returns>
    ///   <c>true</c> if this instance is empty; otherwise, <c>false</c>.
    /// </returns>
    bool isEmpty()const;
    /// <summary>
    /// Determines whether this instance is full.
    /// </summary>
    /// <returns>
    ///   <c>true</c> if this instance is full; otherwise, <c>false</c>.
    /// </returns>
    bool isFull()const;
    /// <summary>
    /// Makes the tree empty.
    /// </summary>
    /// <returns></returns>
    bool makeEmpty();
    /// <summary>
    /// Traverses the tree.
    /// </summary>
    /// <param name="order">The order to traverse the tree.</param>
    void traverseTree(OrderType order)const;
    /// <summary>
    /// Gets the qty.
    /// </summary>
    /// <returns>the number of elements in the tree</returns>
    int getQty()const;
    /// <summary>
    /// Gets the count.
    /// </summary>
    /// <returns>counts the nodes and returns the count</returns>
    int getCount()const;
    /// <summary>
    /// Finds the item.
    /// </summary>
    /// <param name="k">The key to look for.</param>
    /// <param name="found">The found.</param>
    /// <returns></returns>
    bool findItem(T k, T& found)const;
    /// <summary>
    /// Finds the rank of a node
    /// </summary>
    /// <param name="tree">the tree node</param>
    /// <param name="val">value of height</param>
    /// <returns></returns>
    int rankOf(node<T>* tree, T val);

    node<T>* returnRoot();
    /// <summary>
    /// outputs the tree
    /// </summary>
    /// <param name="os">The output stream if being printed out to file.</param>
    /// <returns>true if prints: else false</returns>
    bool display(std::ofstream& os)const;
    /// <summary>
    /// Finalizes an instance of the <see cref="Bll"/> class.
    /// </summary>
    ~TBST();
};
//////////////////////////////////////////////////////////////////////////////

template<typename T>
inline bool TBST<T>::pAdd(node<T>* tree, T& k)
{
    if (tree->item == k || qty >= max)
    {
        return false; // duplicate item, or max size reached
    }

    if (k < tree->item)//walk left
    {
        if (tree->left == NULL)//add element here
        {
            tree->left = new node<T>;
            tree->left->left = tree->left->right = NULL;
            tree->left->item = k;
            qty++;
            return true;
        }
        else
            return pAdd(tree->left, k);
    }
    else
    {
        if (tree->right == NULL)//add element here
        {
            tree->right = new node<T>;
            tree->right->left = tree->right->right = NULL;
            tree->right->item = k;
            qty++;
            return true;
        }
        else
            pAdd(tree->right, k);
    }
}

template<typename T>
inline bool TBST<T>::pDelete(node<T>*& tree, T& k)
{
    if (k < tree->item)
    {
        if (tree->left == NULL)
            return false;
        return pDelete(tree->left, k);
    }
    else if (k > tree->item)
    {
        if (tree->right == NULL)
            return false;
        return pDelete(tree->right, k);
    }
    else
        return deleteNode(tree);
}

template<typename T>
inline bool TBST<T>::deleteNode(node<T>*& tree)
{
    T _k = root->item;
    node<T>* tempPtr;

    tempPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
        qty--;
        return true;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
        qty--;
        return true;
    }
    else
    {
        getPredecessor(tree->left, _k);
        tree->item = _k;
        return pDelete(tree->left, _k);
    }
}

template<typename T>
inline void TBST<T>::getPredecessor(node<T>* tree, T& k)
{
    while (tree->right != NULL)
        tree = tree->right;
    k = tree->item;
}

template<typename T>
inline int TBST<T>::countNodes(node<T>* tree)
{
    if (tree == NULL)
        return 0;
    else
        return countNodes(tree->left) + countNodes(tree->right) + 1;
}

template<typename T>
inline int TBST<T>::countLeftNodes(node<T>* tree)
{
    if (tree == NULL)
        return 0;
    else
        return countLeftNodes(tree->left) + 1;
}

template<typename T>
inline int TBST<T>::countRightNodes(node<T>* tree)
{
    if (tree == NULL)
        return 0;
    else
        return countRightNodes(tree->right) + 1;
}

template<typename T>
inline bool TBST<T>::retrieve(node<T>* tree, const T k, T& found) const
{
    if (tree == NULL)
        return false;
    if (k < tree->item)
        retrieve(root->left, k, found);
    else if (k > tree->num)
        retrieve(tree->right, k, found);
    else if (k == tree->item)
    {
        found = tree->item;
        return true;
    }
    else
        return false;
}

template<typename T>
inline void TBST<T>::copyTree(node<T>*& copy, const node<T>* originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new node<T>;
        copy->item = originalTree->item;
        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}

template<typename T>
inline void TBST<T>::destroy(node<T>*& tree)
{
    if (tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        qty--;
        delete tree;
    }
}

template<typename T>
inline void TBST<T>::printTree(node<T>* tree)
{
    if (tree != NULL)
    {
        printTree(tree->left);
        std::cout << std::setw(7) << std::left << tree->item
            << (pos % 10 == 0 ? '\n' : ' ');
        std::cout << tree->item << " ";
        pos++;
        printTree(tree->right);

    }
}

template<typename T>
inline void TBST<T>::preOrderHelper(node<T>* tree)
{
    if (tree != NULL)
    {
        std::cout << tree->item << " ";
        preOrderHelper(tree->left);
        preOrderHelper(tree->right);
    }
}

template<typename T>
inline void TBST<T>::inOrderHelper(node<T>* tree)
{
    if (tree != NULL)
    {
        inOrderHelper(tree->left);
        std::cout << tree->item << " ";
        inOrderHelper(tree->right);
    }
}

template<typename T>
inline void TBST<T>::postOrderHelper(node<T>* tree)
{
    if (tree != NULL)
    {
        postOrderHelper(tree->left);
        postOrderHelper(tree->right);
        std::cout << tree->item << " ";
    }
}

template<typename T>
inline void TBST<T>::breadthFirstHelper(node<T>* tree)
{
    if (tree == NULL)
        return;
    std::queue<node<T>*> bFList;
    bFList.push(tree);
    while (bFList.empty() == false)
    {
        int nodeCount = bFList.size();
        while (nodeCount > 0)
        {
            node<T>* node = bFList.front();
            std::cout << node->item << " ";
            bFList.pop();
            if (node->left != NULL)
                bFList.push(node->left);
            if (node->right != NULL)
                bFList.push(node->right);
            nodeCount--;
        }
        std::cout << std::endl;
    }
}

template<typename T>
inline void TBST<T>::reverseOrderHelper(node<T>* tree)
{
    if (tree != NULL)
    {
        reverseOrderHelper(tree->right);
        std::cout << tree->item << " ";
        reverseOrderHelper(tree->left);
    }
}

template<typename T>
inline void TBST<T>::twoDimensionalHelper(node<T>* tree, int space)
{
    if (tree == NULL)
        return;
    space += COUNT;
    twoDimensionalHelper(tree->right, space);
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << tree->item << "\n";
    twoDimensionalHelper(tree->left, space);
}

template<typename T>
inline TBST<T>::TBST()
{
    qty = 0;
    max = INT_MAX;
    root = NULL;
}

template<typename T>
inline TBST<T>::TBST(int maxSize)
{
    qty = 0;
    max = maxSize;
    root = NULL;
}

template<typename T>
inline TBST<T>::TBST(const TBST<T>& other)
{
    qty = other.qty;
    max = other.max;
    copyTree(root, other.root);
}

template<typename T>
inline TBST<T>& TBST<T>::operator=(TBST&& originalTree) noexcept
{
    if (this != &originalTree)
    {
        destroy(root);
        root = originalTree.root;
        originalTree.root = NULL;
        qty = originalTree.qty;
        max = originalTree.max;
    }

}

template<typename T>
inline bool TBST<T>::addItem(T k)
{
    if (isFull())
        return false;
    if (root == NULL)
    {
        root = new node<T>;
        root->left = NULL;
        root->right = NULL;
        root->item = k;
        qty++;
        return true;
    }

    return pAdd(root, k);
}

template<typename T>
inline bool TBST<T>::deleteItem(T k)
{
    return pDelete(root, k);
}

template<typename T>
inline bool TBST<T>::isEmpty() const
{
    return root == NULL;
}

template<typename T>
inline bool TBST<T>::isFull() const
{
    return qty >= max;
}

template<typename T>
inline bool TBST<T>::makeEmpty()
{
    if (isEmpty())
        return false;
    else
    {
        destroy(root);
        root = NULL;
        return true;
    }
}

template<typename T>
inline void TBST<T>::traverseTree(OrderType order) const
{
    switch (order)
    {
    case PRE_ORDER:		std::cout << "\nPre-Order tree traversal:\n";
        preOrderHelper(root);
        break;
    case IN_ORDER:		std::cout << "\nIn-Order tree traversal:\n";
        inOrderHelper(root);
        break;
    case POST_ORDER:	std::cout << "\nPost-Order tree traversal:\n";
        postOrderHelper(root);
        break;
    case BREADTH_FIRST: std::cout << "Breadth-first traversal:\n";
        breadthFirstHelper(root);
        break;
    case REVERSE_ORDER: std::cout << "\nReverse-Order tree traversal:\n";
        reverseOrderHelper(root);
        break;
    case TWO_DIMENSIONS: std::cout << "\nTwo-Dimensional-Order tree traversal:\n";
        twoDimensionalHelper(root, 0);
        break;
    default:
        std::cout << "Invalid traversal order\n";
        break;
    }
    std::cout << std::endl;
}

template<typename T>
inline int TBST<T>::getQty() const
{
    return qty;
}

template<typename T>
inline int TBST<T>::getCount() const
{
    return countNodes(root);
}

template<typename T>
inline bool TBST<T>::findItem(T k, T& found) const
{
    return retrieve(root, k, found);
}

template<typename T>
inline int TBST<T>::rankOf(node<T>* tree, T val)
{
    int rank = 1;
    while (tree) {
        if (val < tree->item) // move to left subtree
            tree = tree->left;
        else if (val > tree->item) {
            rank += 1 + countLeftNodes(tree->left);
            tree = tree->right;
        }
        else
            return rank + countLeftNodes(tree->left) + 1;
    }
    return -1; // not found
}

template<typename T>
inline node<T>* TBST<T>::returnRoot()
{
    return root;
}

template<typename T>
inline bool TBST<T>::display(std::ofstream& os) const
{
    printTree(root, os);
    return true;
}

template<typename T>
inline TBST<T>::~TBST()
{
    destroy(root);
}

template<typename T>
TBST<T>::TBST(TBST&& other) noexcept {
    root = other.root;
    qty = other.qty;
    max = other.max;
    other.root = NULL;
    return *this;
}

template<typename T>
TBST<T>& TBST<T>::operator=(const TBST& other) {
    if (this != &other) {
        destroy(root);
        root = NULL;
        qty = other.qty;
        max = other.max;
        copyTree(root, other.root);
    }
    return *this;
}

#endif //PHYSICSFORMULA_TEMPLATEBST_H
