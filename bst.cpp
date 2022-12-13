#include <iostream>
#include "queue.cpp"
using namespace std;

template <class X>
class node
{
public:
    node<X> *left;
    node<X> *right;
    X value;
};

template <class X>
class BST
{

public:
    int noe;
    node<X> *root;

    BST()
    {
        root = nullptr;
        noe = 0;
    }

    void insert(X ele)
    {

        if (root == nullptr)
        {
            root = new node<X>;
            root->value = ele;
            noe++;
            root->left = root->right = nullptr;
        }
        else
        {
            node<X> *p = root;
            node<X> *q = new node<X>;
            node<X> *p1 = new node<X>;
            q->value = ele;
            q->left = q->right = nullptr;
            while (p != nullptr)
            {
                if (ele < p->value)
                {
                    p1 = p;
                    p = p->left;
                }
                else
                {
                    p1 = p;
                    p = p->right;
                }
            }
            if (ele < p1->value)
            {
                p1->left = q;
                noe++;
            }
            else if (ele >= p1->value)
            {
                p1->right = q;
                noe++;
            }
        }
    }

    node<X>* deletenode(node<X>* root1, X k)
    {
   
        if (root1 == NULL)
            return root1;
    
 
        if (root1->value > k) {
            root1->left = deletenode(root1->left, k);
            return root1;
        }
        else if (root1->value < k) {
            root1->right = deletenode(root1->right, k);
            return root1;
        }

        if (root1->left == NULL) {
            node<X>* temp = root1->right;
            delete root1;
            return temp;
        }
        else if (root1->right == NULL) {
            node<X>* temp = root1->left;
            delete root1;
            return temp;
        }
        else {
    
            node<X>* succParent = root1;
            node<X>* succ = root1->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            if (succParent != root1)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
            root1->value = succ->value;
            delete succ;
            return root1;
        }
    }

    int height = 0, tempheight = 0;
    void lheightbst(node<X> *temp)
    {

        if (temp->left != nullptr)
        {
            temp = temp->left;
            height++;
            lheightbst(temp);
        }

        else if (temp->right != nullptr)
        {
            temp = temp->right;
            height++;
            lheightbst(temp);
        }
    }
    void rheightbst(node<X> *temp)
    {
        if (temp->right != nullptr)
        {
            temp = temp->right;
            tempheight++;
            rheightbst(temp);
        }

        else if (temp->left != nullptr)
        {
            temp = temp->left;
            tempheight++;
            rheightbst(temp);
        }
    }
    void heightbst(node<X> *root)
    {
        lheightbst(root);
        rheightbst(root);
        height = (tempheight > height) ? tempheight : height;
    }
    
};

template <class X>
class traversals
{
    node<X> *temp;

public:
    void bfs_traverse(node<X> *temp)
    {
        // Implemented Using Queue
        queue<node<X> *> tqueue(4);
        if (temp != nullptr)
        {
            tqueue.enqueue(temp);
            while (!tqueue.isempty())
            {
                temp = tqueue.dequeue();
                cout << temp->value << " ";
                if (temp->left != nullptr)
                {
                    tqueue.enqueue(temp->left);
                }
                else if (temp->right != nullptr)
                {
                    tqueue.enqueue(temp->right);
                }
                
            }
            
        }
    }

    void inorder_rec(node<X> *root)
    {
        if (root != nullptr)
        {
            inorder_rec(root->left);
            cout << root->value << " ";
            inorder_rec(root->right);
        }
    }
    void preorder_rec(node<X> *root)
    {

        if (root != nullptr)
        {
            cout << root->value << " ";
            preorder_rec(root->left);

            preorder_rec(root->right);
        }
    }
    void postorder_rec(node<X> *root)
    {
        if (root != nullptr)
        {

            postorder_rec(root->left);
            postorder_rec(root->right);
            cout << root->value << " ";
        }
    }
};
int main()
{
    system("cls");
    int choice;
    cout << "Enter Datatype choice : 1. Integer\n2.Char\n3.Float\n4.String\nINput : ";

    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        system("cls");
        BST<int> t1;
        int c2=0;
        
        while (c2 != 4)
        {
        cout << "1.For Inserting in the BST\n2.For Traversal\n3.For Height of BST\n4.Deletion in BST\n5.To Exit\nEnter : ";
        cin >> c2;
        switch (c2)
        {
        case 1:
        {
            int noe;
            cout << "Enter number of values to Enter : ";
            cin >> noe;
            for (int i = 0; i < noe; i++)
            {
                int val;
                cout << "Enter" << i + 1 << "th element";
                cin >> val;
                t1.insert(val);
            }
            break;
        }
        case 2:
        {
            traversals<int> trav;
            int c3;
            cout << "1.In order traversal\n2.Pre Order Traversal\n3.Post-Order Traversal\n4.Breadth-First-Search\nEnter :";
            cin >> c3;
            switch (c3)
            {
            case 1:
            {
                trav.inorder_rec(t1.root);
                break;
            }
            case 2:
            {
                trav.preorder_rec(t1.root);
                break;
            }
            case 3:
            {
                trav.postorder_rec(t1.root);
                break;
            }
            case 4:
            {
                trav.bfs_traverse(t1.root);break;
            }
            default:
            {

                break;
            }
            }
        }
        case 3:
        {
            t1.heightbst(t1.root);
            cout << "Height: " << t1.height << endl;
            break;
        }
        case 4:
        {
            int val;
            cout<<"ENter the value to be deleted :";
            cin>>val;
            node<int> *deleted = t1.deletenode(t1.root,val);
            break;
        }
        default:
        {
            break;
        }
        }
        }

        
        break;
    }
    case 2:
    {
        system("cls");
        BST<char> t1;
        int c2;
        cout << "1.For Inserting in the BST\n2.For Traversal\n3.For Height of BST\n4.Deletion in BST\n5.To Exit\nEnter : ";
        cin >> c2;
        switch (c2)
        {
        case 1:
        {
            int noe;
            cout << "Enter number of values to Enter : ";
            cin >> noe;
            for (int i = 0; i < noe; i++)
            {
                char val;
                cout << "Enter" << i + 1 << "th element";
                cin >> val;
                t1.insert(val);
            }
            break;
        }
        case 2:
        {
            traversals<char> trav;
            int c3;
            cout << "1.In order traversal\n2.Pre Order Traversal\n3.Post-Order Traversal\n4.Breadth-First-Search\nEnter :";
            cin >> c3;
            switch (c3)
            {
            case 1:
            {
                trav.inorder_rec(t1.root);
                break;
            }
            case 2:
            {
                trav.preorder_rec(t1.root);
                break;
            }
            case 3:
            {
                trav.postorder_rec(t1.root);
                break;
            }
            case 4:
            {
                trav.bfs_traverse(t1.root);
            }
            default:
            {

                break;
            }
            }
        }
        case 3:
        {
            t1.heightbst(t1.root);
            cout << "Height: " << t1.height << endl;
            break;
        }
        case 4:
        {
            char val;
            cout<<"ENter the value to be deleted :";
            cin>>val;
            node<char> *deleted = t1.deletenode(t1.root,val);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case 3:
    {
        system("cls");
        BST<float> t1;
        int c2;
        cout << "1.For Inserting in the BST\n2.For Traversal\n3.For Height of BST\n4.Deletion in BST\n5.To Exit\nEnter : ";
        cin >> c2;
        switch (c2)
        {
        case 1:
        {
            int noe;
            cout << "Enter number of values to Enter : ";
            cin >> noe;
            for (int i = 0; i < noe; i++)
            {
                float val;
                cout << "Enter" << i + 1 << "th element";
                cin >> val;
                t1.insert(val);
            }
            break;
        }
        case 2:
        {
            traversals<float> trav;
            int c3;
            cout << "1.In order traversal\n2.Pre Order Traversal\n3.Post-Order Traversal\n4.Breadth-First-Search\nEnter :";
            cin >> c3;
            switch (c3)
            {
            case 1:
            {
                trav.inorder_rec(t1.root);
                break;
            }
            case 2:
            {
                trav.preorder_rec(t1.root);
                break;
            }
            case 3:
            {
                trav.postorder_rec(t1.root);
                break;
            }
            case 4:
            {
                trav.bfs_traverse(t1.root);
            }
            default:
            {

                break;
            }
            }
        }
        case 3:
        {
            t1.heightbst(t1.root);
            cout << "Height: " << t1.height << endl;
            break;
        }
        case 4:
        {
            float val;
            cout<<"ENter the value to be deleted :";
            cin>>val;
            node<float> *deleted = t1.deletenode(t1.root,val);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case 4:
    {
        system("cls");
        BST<string> t1;
        int c2;
        cout << "1.For Inserting in the BST\n2.For Traversal\n3.For Height of BST\n4.Deletion in BST\n5.To Exit\nEnter : ";
        cin >> c2;
        switch (c2)
        {
        case 1:
        {
            int noe;
            cout << "Enter number of values to Enter : ";
            cin >> noe;
            for (int i = 0; i < noe; i++)
            {
                string val;
                cout << "Enter" << i + 1 << "th element";
                cin >> val;
                t1.insert(val);
            }
            break;
        }
        case 2:
        {
            traversals<string> trav;
            int c3;
            cout << "1.In order traversal\n2.Pre Order Traversal\n3.Post-Order Traversal\n4.Breadth-First-Search\nEnter :";
            cin >> c3;
            switch (c3)
            {
            case 1:
            {
                trav.inorder_rec(t1.root);
                break;
            }
            case 2:
            {
                trav.preorder_rec(t1.root);
                break;
            }
            case 3:
            {
                trav.postorder_rec(t1.root);
                break;
            }
            case 4:
            {
                trav.bfs_traverse(t1.root);
                break;
            }
            default:
            {

                break;
            }
            }
        }
        case 3:
        {
            t1.heightbst(t1.root);
            cout << "Height: " << t1.height << endl;
        }
        case 4:
        {
            string val;
            cout<<"ENter the value to be deleted :";
            cin>>val;
            node<string> *deleted = t1.deletenode(t1.root,val);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    default:
        break;
    }

    return 0;
}