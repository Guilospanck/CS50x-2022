#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int number;
  struct node *node_left;
  struct node *node_right;
} node;

void print_tree(node *root);
void free_tree(node *root);
bool search(node *root, int number);

int main(void)
{
  // initiate list
  node *list = NULL;

  node *n = malloc(sizeof(node));
  if (n == NULL)
  {
    return 1;
  }

  n->number = 2;
  n->node_left = NULL;
  n->node_right = NULL;

  list = n;

  n = malloc(sizeof(node));
  if (n == NULL)
  {
    free(list);
    return 1;
  }

  n->number = 1;
  n->node_left = NULL;
  n->node_right = NULL;

  list->node_left = n;

  n = malloc(sizeof(node));
  if (n == NULL)
  {
    free(list->node_left);
    free(list->node_right);
    free(list);

    return 1;
  }

  n->number = 3;
  n->node_left = NULL;
  n->node_right = NULL;

  list->node_right = n;

  print_tree(list);
  int number = 3;
  bool numberExist = search(list, number);
  if (numberExist)
  {
    printf("Number %i exists!\n", number);
  }
  else
  {
    printf("Number %i doesn't exist!\n", number);
  }
  free_tree(list);

  return 0;
}

void print_tree(node *root)
{
  if (root == NULL)
  {
    return;
  }

  print_tree(root->node_left);
  printf("%i\n", root->number);
  print_tree(root->node_right);
}

void free_tree(node *root)
{
  if (root == NULL)
  {
    return;
  }

  free_tree(root->node_left);
  free_tree(root->node_right);
  free(root);
}

bool search(node *root, int number)
{
  if (root == NULL)
  {
    return false;
  }

  if (number > root->number)
  {
    return search(root->node_right, number);
  }

  if (number < root->number)
  {
    return search(root->node_left, number);
  }

  return true;
}
