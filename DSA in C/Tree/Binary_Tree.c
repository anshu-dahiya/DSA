#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int x;
    struct node *newnode;

    newnode =(struct node *)malloc(sizeof(struct node));

    printf("Enter data (OR -1 to exit): ");
    scanf("%d",&x);

    if (x == -1)
    {
        return 0;
    }

    newnode->data = x;

    printf("\nEnter left child of %d : ",x);
    newnode->left = create();

    printf("\nEnter right child of %d : ",x);
    newnode->right = create();

    return newnode;
    
}

void preOrder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    printf("%d",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    inOrder(root->left);
    printf("%d",root->data);
    inOrder(root->right);
}


void postOrder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d",root->data);
}

void main()
{
    struct node *root;
    root = NULL;
    root = create();

    printf("\nPreorder is : ");
    preOrder(root);

    printf("\nIneorder is : ");
    inOrder(root);

    printf("\nPostorder is : ");
    postOrder(root);
}
