#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *node_left;
  struct node *node_right;
} node;

void print_tree(node *root);
void free_tree(node *root);

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