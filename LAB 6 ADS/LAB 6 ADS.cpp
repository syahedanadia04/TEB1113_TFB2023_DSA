#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value){
        data = value;
        left= right = nullptr;
    }
};

class BinaryTree{
public:

    Node* root;
    
    BinaryTree(){
        root = nullptr;
    }
    
    //insert new value into Tree
    Node* insert (Node* node, int value){
        if (node == nullptr)
            return new Node (value);
            
        if (value <node->data)
            node-> left= insert (node->left, value);
        else if (value > node->data)
            node -> right = insert (node->right,value);
            
        return node;
    }
    
    void insert (int value){
        root = insert (root, value);
    }
    
    Node * search (Node* node, int key){
        if (node == nullptr || node->data == key)
            return node;
            
        if (key < node-> data)
            return search (node-> left, key);
        else
            return search (node-> right, key);
    }
    //update value 
    void update (int oldValue, int newValue){
        Node*node = search (root, oldValue);
        if (node != nullptr)
            node -> data = newValue;
        else
            cout << "Value not foun\n";
            
    }
    
    //delete node
    Node* deleteNode (Node*node, int value){
        if (node == nullptr)
        return node;
        
        if (value < node->data)
            node -> left =deleteNode (node->left, value);
        else if (value > node->data)
            node -> left =deleteNode (node->right, value);
        else {
            if (node->left == nullptr)
                return node -> right;
            else if (node->right == nullptr)
                return node -> left;
            
            Node * temp = minValueNode (node-> right);
            node-> data = temp->data;
            node->right = deleteNode (node->right, temp->data);
        }
        return node;
    }
    
    Node* minValueNode (Node*node){
        Node * current = node;
        while (current && current ->left != nullptr)
            current = current ->left;
        return current;
    }
    
    void remove (int value){
        root = deleteNode (root,value);
    }
    
    void inorder (Node* node){
        if (node == nullptr) return;
        inorder (node->left);
        cout << node->data << " ";
        inorder (node-> right);
    }
    void preorder (Node* node){
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder (node->left);
        preorder (node-> right);
        
    }
    void postorder (Node* node){
        if (node == nullptr) return;
        postorder (node->left);
        postorder (node-> right);
        cout << node->data << " ";
        
    }
    
    
};

int main (){
    BinaryTree tree;
    
    //inserting elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(40);
    tree.insert(70);
    tree.insert(20);
    tree.insert(60);
    tree.insert(80);
    
    cout << "Inorder traversal:";
    tree.inorder (tree.root);
    cout << endl;
    
    cout << "preorder traversal:";
    tree.preorder(tree.root);
    cout << endl;
    
    cout << "postorder traversal:";
    tree.postorder (tree.root);
    cout << endl;
    
    cout << "\nDeleting 20...\n";
    tree.remove(20);
    tree.inorder(tree.root);
    cout << endl;
    
    cout << "updating 40->45...\n";
    tree.update(40,45);
    tree.inorder(tree.root);
    cout << endl;
    
    return 0;
}