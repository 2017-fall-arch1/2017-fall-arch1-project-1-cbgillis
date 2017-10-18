#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lrlist.h"

int main()
{
  BSTList *tree = Create();
  int yOrN;
  char in[100];

  for(int i = 10; i > 0; i--)
     {
      printf("Please enter a name to store (%d remaining):", i);
      scanf("%s", in);
      printf("\nyou entered the name %s", in);
      Insert(tree, in);
      }
  printf("List of contents in tree: \n");
  Display(tree);
  
  for(int j = 3; j > 0; j--)
    {
      printf("Let's delete some values (%d deletes remaining):", j);
      scanf("%s", in);
      Delete(tree, in);
      printf("\nthe value %d should have been deleted", in);
    }
  
  
  while(yOrN != 1)
    {
      printf("\nremaining contents in tree: ");
      Display(tree);
      printf("\nIf you wish to delete the tree, please enter 1\notherwise, enter 0");
      scanf("%d", &yOrN);
    }
  EmptyTree(tree);
  Display(tree);
  return 0;
}
