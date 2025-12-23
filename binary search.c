
#include <stdio.h>
#include <stdlib.h>

struct Node
{
int data;
struct Node *left, *right;
};

struct Node *createNode(int value)
{
struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
newnode->data = value;
newnode->left = NULL;
newnode->right = NULL;
return newnode;
}

struct Node *insert(struct Node *root, int value)
{
if (root == NULL)
return createNode(value);

if (value < root->data)
root->left = insert(root->left, value);
else if (value > root->data)
root->right = insert(root->right, value);

return root;
}

void inorder(struct Node *root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

void preorder(struct Node *root)
{
if (root != NULL)
{
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}

void postorder(struct Node *root)
{
if (root != NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}

int main()
{
struct Node *root = NULL;
int n, value, i;

printf("Enter number of elements: ");
scanf("%d", &n);

printf("Enter elements to insert into BST:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &value);
root = insert(root, value);
}

printf("\nIn-order Traversal: ");
inorder(root);

printf("\nPre-order Traversal: ");
preorder(root);

printf("\nPost-order Traversal: ");
postorder(root);

return 0;
}
