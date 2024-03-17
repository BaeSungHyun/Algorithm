#include <iostream>

using namespace std;

// Node
struct Node {
    int data; 
    Node* parent;
    Node* left;
    Node* right;
    char color; // 1 byte for char

    // Constructor
    Node (int data) 
    : data(data), left(nullptr), right(nullptr), parent(nullptr), color('R') {}
};

class RedBlackTree {
public:
    RedBlackTree() : root(nullptr) {}

    void insert(int data) {
        if (root == nullptr) {
            root = new Node(data);
            root->color = 'B';
        } else 
            root = insertHelp(root, data);
    }

    // Function to perform Inorder Traversal of the tree
    void inorderTraversal() {
        inorderTraverseHelper(root);
    }

    // Function to print the tree
    void printTree() {
        printTreeHelper(root, 0);
    }
        
private:
    Node* root;
    // 1000 - Left-Left
    // 0100 - Right-Right (Mirror of Left-Left)
    // 0010 - Left-Right
    // 0001 - Right-Left (Mirror of Left-Right)
    char rotationFlag {0b0000}; 

    // pointer a, b
    // a = b; 는 pointer a 가 가리키는 memory를 b로 바꾼다는 뜻.
    // 즉 내용물을 바꾼다는 뜻. 
    // c->next = a; 라는 것은 여전히 pointer a를 가리키지만 a의 내용물만 바뀐 상태.

    // Left Rotation
    Node* rotateLeft(Node*& node) {            
        Node* currentRight = node->right;
        Node* currentRightLeft = currentRight->left;

        // each other
        currentRight->left = node; node->parent = currentRight;

        // each other 
        node->right = currentRightLeft;
        if (currentRightLeft != nullptr)
            currentRightLeft->parent = node;

        return currentRight; // new parent node

        // Question : no connection between 'new parent node' and grandparent node -> made in outer function.
    }

    // 왜 이렇게 힘들게 짤까.. 에 대한 생각이 있었는데,
    // Node*& as parameter : pointer와 아예 같아지다 보니 잠시 다른 variable을 만드는 이유가 없다. 그냥 같은 거 또 하나가 생김. changing current node changes reference so doesn't help.
    // Node wasCurrent = *node in function body : stack 으로 만들다 보니 당연히 새로운 애가 만들어 진거고 function이 끝나면 사라짐
    // 함수 안에서 parameter 로 주어진 node를 바꾸는 법... 왜냐하면 현재 node의 parent를 변경할 수는 있지만 node의 parent의 child를 변경하기가 까다롭다.
    // 그래서 node 가 point하는 reference 자체를 변경하면 어떨까 하는...  

    // Right Rotation
    Node* rotateRight(Node* node) {
        Node* currentLeft = node->left;
        Node* currentLeftRight = currentLeft->right;

        // each other
        currentLeft->right = node; node->parent = currentLeft;

        // each other
        node->left = currentLeftRight;
        if (currentLeftRight != nullptr) {
            currentLeftRight->parent = node;
        }

        return currentLeft; // new parent node

        // Question : no connection between 'new parent node' and grandparent node -> made in outer function.
    } 

    // Helper function for insertion
    Node* insertHelp(Node* root, int data) {
        bool f = false;

        if (root == nullptr) { // nullptr == black, so don't change color
            return new Node(data);
        } else if (data < root->data) {
            // traverse down until insertion point. -> nullptr
            root->left = insertHelp(root->left, data);
            // if it reaches here, means it return new Node(data) with RED
            root->left->parent = root; // connection between new node and parent
            if (root != this->root) { // not root
                if (root->color == 'R' && root->left->color == 'R') // RED-RED
                    f = true;
            }
        } else {
            // traverse down until insertion point -> nullptr
            root->right = insertHelp(root->right, data);
            // reaches here, means it return new Node(data) with BLACK
            root->right->parent = root; // connection between new node and parent
            if (root != this->root) { // not root
                if (root->color == 'R' && root->right->color == 'R') // RED-RED
                    f = true;
            }
        }

        // perform rotations
        if (rotationFlag == 0b0001) { // left-left
            root = rotateRight(root);
            root->color = 'B';
            root->right->color = 'R';
            rotationFlag = 0b0000;
        } else if (rotationFlag == 0b0010) { // right-right
            root = rotateLeft(root);
            root->color = 'B';
            root->left->color = 'R';
            rotationFlag = 0b0000;
        } else if (rotationFlag == 0b0100) { // left-right
            root->left = rotateLeft(root->left);
            root->left->parent = root; // connection made
            root = rotateRight(root);
            root->color = 'B';
            root->right->color = 'R';
            rotationFlag = 0b0000;
        } else if (rotationFlag == 0b1000) { // right-left
            root->right = rotateRight(root->right);
            root->right->parent = root;
            root = rotateLeft(root);
            root->color = 'B';
            root->left->color = 'R';
            rotationFlag = 0b0000;
        }

        // Handle RED-RED conflicts
        if (f) { // root == parent, look above
            if (root->parent->right == root) { // current node is parent's right child with 'R' 
                if (root->parent->left == nullptr || root->parent->left->color == 'B') { // left sibling is 'B'
                    if (root->left != nullptr && root->left->color == 'R')
                        rotationFlag = 0b1000; // right-left
                    else if (root->right != nullptr && root->right->color == 'R') 
                        rotationFlag = 0b0010; // right-right
                } else { // root->parent->left->color == 'R' (uncle)
                    root->parent->left->color = 'B'; // uncle color -> 'B'
                    root->color = 'B'; // parent color -> 'B'
                    if (root->parent != this->root)  // grandparent -> 'R'
                        root->parent->color = 'R';
                } 
            } else { // current node is parent's left child with 'R'
                if (root->parent->right == nullptr || root->parent->right->color == 'B') { // right sibling is 'B'
                    if (root->left != nullptr && root->left->color == 'R') 
                        rotationFlag = 0b0001; // left-left
                    else if (root->right != nullptr && root->right->color == 'R') 
                        rotationFlag = 0b0100; // left-right
                } else {  // if uncle == 'R'
                    root->parent->right->color = 'B'; // uncle color -> 'B'
                    root->color = 'B'; 
                    if (root->parent != this->root) 
                        root->parent->color = 'R';
                }
            }
            f = false;
        }
        return root;
    }

    // Helper function to perform Inorder Traversal
    void inorderTraverseHelper(Node* node) {
        if (node != nullptr) {
            inorderTraverseHelper(node->left);
            cout << node->data << " ";
            inorderTraverseHelper(node->right);
        }
    }

    void printTreeHelper(Node* root, int space) {
        if (root != nullptr) {
            space += 10;
            printTreeHelper(root->right, space);
            cout << endl;
            for (int i = 10; i < space; i++) {
                cout << " ";
            }
            cout << root->data << endl;
            printTreeHelper(root->left, space);
        }
    }
};


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    RedBlackTree t;
    int arr[] = {1, 0, 4, 8, 3, 9, 5, 6, 7};
    for (int i = 0; i < 9; i++) {
        t.insert(arr[i]);
        cout << endl;
        t.inorderTraversal();
        t.printTree();
        cout << endl;
    }
    return 0;
}