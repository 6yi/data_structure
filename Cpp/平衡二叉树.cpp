#include<stdio.h>
#include<stdlib.h>

typedef struct Node

{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}BTNode;

int max(int a, int b);

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

BTNode* newNode(int key)
{
    struct Node* node = (BTNode*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

BTNode* ll_rotate(BTNode* y)
{
    BTNode *x = y->left;
    y->left = x->right;
    x->right = y;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

BTNode* rr_rotate(BTNode* y)
{
    BTNode *x = y->right;
    y->right = x->left;
    x->left = y;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

int getBalance(BTNode* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

BTNode* insert(BTNode* node, int key)
{

    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return ll_rotate(node);


    if (balance < -1 && key > node->right->key)
        return rr_rotate(node);


    if (balance > 1 && key > node->left->key)
    {
        node->left = rr_rotate(node->left);
        return ll_rotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = ll_rotate(node->right);
        return rr_rotate(node);
    }

    return node;
}


BTNode * minValueNode(BTNode* node)
{
    BTNode* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

BTNode* deleteNode(BTNode* root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            BTNode* temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            BTNode* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }


    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);


    if (balance > 1 && getBalance(root->left) >= 0)
        return ll_rotate(root);


    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = rr_rotate(root->left);
        return ll_rotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) //RRÐÍ
        return rr_rotate(root);

    if (balance < -1 && getBalance(root->right) > 0)  //RlÐÍ
    {
        root->right = ll_rotate(root->right);
        return rr_rotate(root);
    }

    return root;
}


void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int count(BTNode*root){
    if (!root)
    return 0;
    return count(root->left)+count(root->right)+1;
}

int find(BTNode*root,int k){
    int pos=count(root->left);
    if (pos==k-1){
        return root->key;
    }
    if (pos>k-1){
        return find(root->left,k);
    }
    return find(root->right,k-1-pos);
}

int find2(BTNode*root, int k,int count){
    if (root!=NULL){
        count=find2(root->left,k,count);
        if (count!=NULL){
            if (count==k){
                printf("%d",root->key);
                return NULL;
            }else if(count<k){
                return ++count;
            }
            count=find2(root->right,k,count);
        } else{
            return NULL;
        }
    }else{
        return ++count;
    }
}

int main()
{
    BTNode *root = NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    find2(root,7,0);
//    preOrder(root);
//    root = deleteNode(root, 10);
//    printf("\n");
//    preOrder(root);
    return 0;
}
