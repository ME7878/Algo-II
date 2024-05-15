#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, tag;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        this->tag = 0;
        left = NULL;
        right = NULL;
    }
};

class Bin_S_Tree
{
private:
    Node *pres = NULL;
    Node *createNode(int data)
    {
        Node *temp = new Node(data);
        temp->right = NULL;
        temp->left = NULL;
        return temp;
    }
    Node *insert(Node *pres, int key)
    {
        if (pres == NULL)
        {
            pres = createNode(key);
            return pres;
        }
        if (key > (pres)->data)
            (pres)->right = insert((pres)->right, key);
        else if (key <= (pres)->data)
            (pres)->left = insert((pres)->left, key);
        return pres;
    }
    Node *descend_left(Node *prev)
    {
        Node *temp = pres->left;
        pres->left = prev;
        pres->tag = 0;
        prev = pres;
        pres = temp;
        return prev;
    }
    Node *descend_right(Node *prev)
    {
        Node *temp = pres->right;
        pres->right = prev;
        pres->tag = 1;
        prev = pres;
        pres = temp;
        return prev;
    }
    Node *ascend_left(Node *prev)
    {
        Node *temp = prev->left;
        prev->left = pres;
        pres = prev;
        prev = temp;
        return prev;
    }
    Node *ascend_right(Node *prev)
    {
        Node *temp = prev->right;
        prev->right = pres;
        pres = prev;
        prev = temp;
        return prev;
    }

public:
    void setTree(int data)
    {
        pres = insert(pres, data);
    }
    void getInOrderTree()
    {
        Node *prev;
        prev = NULL;
        int flag = 0;
        if (pres == NULL)
        {
            cout << "No Data In The Tree" << endl;
            return;
        }
        do
        {
            if (pres->left != NULL && flag == 0)
            {
                prev = descend_left(prev); // descend left child
                flag = 0;
            }
            else
            {
                if (flag != 2)
                {
                    cout <<pres->data<< "\t"; // visit pres
                    if (prev == NULL && pres->right == NULL)
                    {
                        flag = 2;
                    }
                }
                if (pres->right != NULL && flag != 2)
                {
                    prev = descend_right(prev);
                    flag = 0;
                }
                else if (prev != NULL && prev->tag == 0)
                {
                    prev = ascend_left(prev); // ascend from the left subtree
                    flag = 1;
                }
                else if (prev != NULL && prev->tag == 1)
                {
                    prev = ascend_right(prev); // ascend from the right subtree
                    flag = 2;
                }
            }
        } while (prev != NULL || flag != 2);
    }
    void getPreOrderTree()
    {
        Node *prev = NULL;
        int flag = 0;
        if (pres == NULL)
        {
            cout << "No Data In The Tree";
            return;
        }
        do
        {
            if (flag == 0)
            {
                cout << pres->data << "\t"; // visit pres
                if (prev == NULL && pres->right == NULL && pres->left == NULL)
                    flag = 2;
            }
            if (pres->left != NULL && flag == 0)
            {
                prev = descend_left(prev); // descend left child
                flag = 0;
            }
            else
            {
                if (pres->right != NULL && flag != 2)
                {
                    prev = descend_right(prev); // descend right child
                    flag = 0;
                }
                else if (prev != NULL && prev->tag == 0)
                {
                    prev = ascend_left(prev); // ascend from the left subtree
                    if (prev == NULL && pres->right == NULL)
                    {
                        flag = 2;
                    }
                    else
                        flag = 1;
                }
                else if (prev != NULL && prev->tag == 1)
                {
                    prev = ascend_right(prev); // ascend from the right subtree
                    flag = 2;
                }
            }
        } while (prev != NULL || flag != 2);
    }
    void getPostOrderTree()
    {
        Node *prev = NULL;
        int flag = 0;
        if (pres == NULL)
        {
            cout << "No Data In The Tree";
            return;
        }
        do
        {
            if (pres->left != NULL && flag == 0)
            {
                prev = descend_left(prev); // descend left child
                flag = 0;
            }
            else
            {
                if (pres->right != NULL && flag != 2)
                {
                    prev = descend_right(prev); // descend right child
                    flag = 0;
                }
                else if (prev != NULL && prev->tag == 0)
                {
                    prev = ascend_left(prev); // ascend from the left subtree
                    if (prev == NULL && pres->right == NULL)
                    {
                        flag = 2;
                    }
                    else
                        flag = 1;
                }
                else if (prev != NULL && prev->tag == 1)
                {
                    prev = ascend_right(prev); // ascend from the right subtree
                    flag = 2;
                }
            }
            if ((flag == 2) || (pres->right == NULL && flag == 1) || (pres->right == NULL && pres->left == NULL && flag == 0))
            {
                cout << pres->data <<"\t"; // visit pres
                if (prev == NULL && pres->right == NULL &&  pres->left == NULL)
                    flag = 2;
            }
        } while (prev != NULL || flag != 2);
    }
};

int main()
{
    Bin_S_Tree Tree;
    int n, data;
    cout << "Enter number of elements you want to insert: ";
    cin >> n;
    cout << "\nEnter element to be inserted" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        Tree.setTree(data);
    }
    cout << "Printing The Tree..." << endl;
    cout << "Inorder ->" << endl;
    Tree.getInOrderTree();
    cout << "\nPreOrder ->" << endl;
    Tree.getPreOrderTree();
    cout << "\nPostorder ->" << endl;
    Tree.getPostOrderTree();
    return 0;
}