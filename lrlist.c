#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*for strcmp*/
#include "lrlist.h" /*header file lrlist.h*/

BSTList *Create()
{
  BSTList *p = (BSTList *)malloc(sizeof(BSTList));
  p->r = NULL;
  return p;
}

/*finds the smallest value in the tree*/
BSTp *Min(BSTp *p)
{
  BSTp *t = p;
  while(t->left != NULL)
    {
      t = t->left;
    }
  return t;
}

/*shows which tree to delete from*/
void Delete(BSTList *p, char *d)
{
  BSTp *o = p->r;
  DeleteVal(o, d);
}

/*deletes specific values off the tree*/
void DeleteVal(BSTp *p, char *d)
{
  if(p == NULL)
    {
      return;
    }
  
  if(strcmp(p->data, d) < 0)
    {
      DeleteVal(p->left, d);
    }
  else if(strcmp(p->data, d) > 0)
    {
      DeleteVal(p->right, d);
    }
  /*after we've found the correct data value*/
  else
    {
      /*checks for single child or no child*/
      if(p->left == NULL)
	{
	  BSTp *t = p->right;
	  free(p);
	}
      else if(p->right == NULL)
	{
	  BSTp *tem = p->left;
	  free(p);
	}
      /*copies the smallest value at that point and deletes old child*/
      BSTp *tmp = Min(p->right);
      p->data = tmp->data;
      DeleteVal(p->right, tmp->data);
    }
}

/*empties the tree*/
void EmptyTree(BSTList *p)
{
  BSTp *t = p->r;
  ClearTree(t);
  p->r = NULL;
}

/*traverse and free the branches in the tree*/
void ClearTree(BSTp *p)
{
  if(p->data == NULL)
    {
      return;
    }
  ClearTree(p->left);
  p->left = NULL;
  ClearTree(p->right);
  p->right = NULL;
  free(p->data);
  free(p);
}

/*eliminates the tree*/
void Free(BSTList *p)
{
  EmptyTree(p);
  free(p);
  p = NULL;
}

/*puts an item in the list*/
void Insert(BSTList *p, char *d)
{
  BSTp *o = p->r;
  BSTp *c = Add(d);
  int ins = 0;
  while(!ins)
    {
      if(strcmp(o->data, c->data) < 0)
	{
	  if(!(o->right))
	    {
	      o->right = c;
	      ins = 1;
	    }
	  else
	    {
	      o = o->right;
	    }
	}
      else if(strcmp(o->data, c->data) > 0)
	{
	  if(!(o->left))
	    {
	      o->left = c;
	      ins = 1;
	    }
	  else
	    {
	      o = o->left;
	    }
	}
      else
	{
	  printf("this item has already been inserted!\n");
	}
    }
}

/*adds the given value onto the tree*/
BSTp *Add(char *d)
{
  char *dat;
  int length, c;
  BSTp *i;
  /*length of string*/
  for (length = 0; d[length]; length++)
    {
      dat = (char *)malloc(length+1);
    }
  /*copying string*/
  for (length = 0; d[length]; length++)
    {
      dat[length] = d[length];
    }
  dat[length] = 0; /*eliminating use of copied info*/
  i->data = d;
  i->left = i->right = NULL;
  return i;
  
}
/*display tree*/
void Display(BSTList *p)
{
  if (p!=NULL)
    {
      Print(p->r);
      printf("\n");
    }
  else
    {
      printf("Tree is empty!");
    }
}

/*prints the list in order*/
void Print(BSTp *r)
{
  if(r!=NULL)
    {
      Print(r->left);
      printf("%s ", r->data);
      Print(r->right);
    }
  else
    {
      printf("the list has nothing here!\n");
    }
}
