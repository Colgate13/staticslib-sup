#include <stdio.h>
#include <stdlib.h>

struct node
{
  int value;
  struct node *left;
  struct node *right;
};

typedef struct node Node;

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insertNode(Node *root, int value)
{

  if (root == NULL)
  {
    root = createNode(value);
    return;
  }

  if (value < root->value)
  {
    if (root->left == NULL)
      root->left = createNode(value);

    else
      insertNode(root->left, value);
  }
  else
  {
    if (root->right == NULL)
      root->right = createNode(value);

    else
      insertNode(root->right, value);
  }
}

void removeNode(Node *root, int value)
{
  if (value == root->value)
  {
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
    }
  }
}

// @printTree
// @param root: root of the tree
// @param leftOrRight: 0 for left, 1 for right, -1 for root
void printTree(Node *root, int leftOrRight, int level)
{

  if (leftOrRight == -1)
  {
    printf("\n\n%d\n\n", root->value);

    if (root->left != NULL)
      printTree(root->left, 0, level + 1);
    if (root->right != NULL)
      printTree(root->right, 1, level + 1);
  }
  else
  {
    if (leftOrRight == 0)
    {
      if (root->value)
      {
        printf("--|");
        printf("%d\n", root->value);
        for (int i = 0; i < level; i++)
          printf("\t\t\t");
        printf("%d\n", root->value);

        if (root->left != NULL)
        {
          printTree(root->left, 0, level + 1);
        }

        if (root->right != NULL)
        {
          printTree(root->right, 1, level + 1);
        }
      }
    }
    else
    {
      if (root->value)
      {
        for (int i = 0; i < level; i++)
          printf("\t");
        printf("%d\n", root->value);

        if (root->left != NULL)
        {
          printTree(root->left, 0, level + 1);
        }

        if (root->right != NULL)
        {
          printTree(root->right, 1, level + 1);
        }
      }
    }
  }

  // printf("\n\n");
}

void print(Node *root, int depth)
{
  if (root == NULL)
  {
    return;
  }

  // Imprime a subarvore direita
  print(root->right, depth + 1);

  // Imprime a raiz
  for (int i = 0; i < depth; i++)
  {
    printf("   ");
  }
  printf("└──");
  printf("%d\n", root->value);

  // Imprime a subarvore esquerda
  print(root->left, depth + 1);
}

int main()
{

  Node *tree = createNode(10);
  insertNode(tree, 5);
  insertNode(tree, 15);
  insertNode(tree, 8);
  insertNode(tree, 14);
  print(tree, 1);
  // printTree(tree, -1, 0);
  printf("\n\n");
}