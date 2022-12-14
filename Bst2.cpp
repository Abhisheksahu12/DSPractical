#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Node{ 
    public:
    int data;
    Node *left,*right;
};
class BST{
    Node* root=NULL;
    public:
    void insert(int val){
        Node* temp=new Node;
        temp->data=val;
        temp->left=NULL;
        temp->right=NULL;
        if (root==NULL)
        {
            root=temp;
            return;
        }
        Node* curr=root;
        Node* prev=NULL;
        while (curr!=NULL)
        {
            prev=curr;
            if (val>curr->data)
            {
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        if (prev==NULL)
        {
            prev=temp;
        }
        else if(val>prev->data){
            prev->right=temp;
        }
        else{
            prev->left=temp;
        }
        return;
    }
    void deletion(int key){
        Node* curr=root;
        Node* prev=NULL;
        while (curr!=NULL && curr->data!=key)
        {
            prev=curr;
            if (key>curr->data)
            {
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        if (curr==NULL)
        {
            cout<<"Key"<<key<<"does not exist"<<endl;
        }
        if (curr->left == NULL || curr->right == NULL) {
        Node* newCurr;
 
        // if the left child does not exist.
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;
        if (prev == NULL)
            cout<<newCurr->data<<endl;
        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;
        free(curr);
    }
    else {
        Node* p = NULL;
        Node* temp;
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
        if (p != NULL)
            p->left = temp->right;
        else
            curr->right = temp->right;
 
        curr->data = temp->data;
        free(temp);
    }
        
    }
    void inorder(){ 
        if(root==NULL){ 
            cout<<"Empty tree"<<endl;
        }
        stack<Node*> s;
        Node *curr = root;
 
        while (curr != NULL || s.empty() == false)
        {
            while (curr !=  NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        } 
        cout<<endl;
    }
    void preorder(){
        if (root == NULL){
            cout<<"Empty Tree"<<endl;
            return;
        }
        stack<Node*> nodeStack;
        nodeStack.push(root);
        while (nodeStack.empty() == false) {
            Node* node = nodeStack.top();
            printf("%d ", node->data);
            nodeStack.pop();
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        cout<<endl;
    }
    void postOrder(){ 
        if (root == NULL){
            cout<<"Empty Tree"<<endl;
            return;
        }
        stack<Node*> S;
        S.push(root);
        Node* prev = NULL;
        while (!S.empty()) {
            auto current = S.top();
            if (prev == NULL || prev->left == current
                || prev->right == current) {
                if (current->left)
                    S.push(current->left);
                else if (current->right)
                    S.push(current->right);
                else {
                    S.pop();
                    cout<<current->data<<" ";
                }
            }
    
            else if (current->left == prev) {
                if (current->right)
                    S.push(current->right);
                else {
                    S.pop();
                    cout<<current->data<<" ";
                }
            }
            else if (current->right == prev) {
                S.pop();
                cout<<current->data<<" ";
            }
            prev = current;
        }
        cout<<endl;
        return;
    }
    void levelTraversal(){
        if (root == NULL){
            cout<<"Empty tree"<<endl;
            return;
        }
        // Create an empty queue for level order traversal
        queue<Node*> q;
    
        // Enqueue Root and initialize height
        q.push(root);
    
        while (q.empty() == false) {
            // Print front of queue and remove it from queue
            Node* node = q.front();
            cout << node->data << " ";
            q.pop();
    
            /* Enqueue left child */
            if (node->left != NULL)
                q.push(node->left);
    
            /*Enqueue right child */
            if (node->right != NULL)
                q.push(node->right);
        }
    }
    int height(){
        queue<Node*> nodesInLevel;
        int height = 0;
        int nodeCount = 0; 
        Node* currentNode;
        if (root == NULL) {
            return 0;
        }
        nodesInLevel.push(root);
        while (!nodesInLevel.empty()) {
            height++;
            nodeCount = nodesInLevel.size();
            while (nodeCount--) {
                currentNode = nodesInLevel.front();
                if (currentNode->left != NULL) {
                    nodesInLevel.push(currentNode->left);
                }
                if (currentNode->right != NULL) {
                    nodesInLevel.push(currentNode->right);
                }
                nodesInLevel.pop();
            }
        }
        return height;
    }
    bool search(int key){
        Node* curr=root;
        Node* prev=NULL;
        while (curr!=NULL && curr->data!=key)
        {
            prev=curr;
            if (key>curr->data)
            {
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        if (curr==NULL)
        {
            return false;
        }
        return true;
    }
    void searchAndReplace(int key,int x){
        if (search(key))
        {
            deletion(key);
            insert(x);
        }
        else{
            cout<<"Node Not Found"<<endl;
        }
    }
};
int main(){ 
    BST b;
    b.insert(2);
    b.insert(1);
    b.insert(5);
    b.insert(8);
    b.insert(3);
    b.insert(11);
    b.inorder();
    // b.deletion(5);
    // b.inorder();
    // b.searchAndReplace(11,20);
    // b.inorder();
    // b.levelTraversal();
    // cout<<b.height()<<endl;
    // b.preorder();
    // b.postOrder();
    // cout<<b.search(10)<<endl;
    return 0;
}
