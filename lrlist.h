#ifndef lrlist_included /*prevents multiple inclusion of lrlist.c*/
#define lrlist_included


/*binary search tree parent/child*/
typedef struct BSTp
{
  struct BSTp *left, *right;
  char* data;
} BSTp;

/*binary search tree*/
typedef struct
{
  BSTp *r;
}BSTList;

/*creates a new empty tree*/
BSTList *Create();

/*deletes a specified item off of the tree*/
void DeleteVal(BSTp *p, char *d);

/*prints out the list in order starting from the root r*/
void Print(BSTp *r);

/* inserts a copy of the data d into the tree */
void Insert(BSTList *p, char *d);

/*deletes from the tree given*/
void Delete(BSTList *p, char *d);

/*adds value into bst parent/child*/
BSTp *Add(char *d);

/* finds the minimum value in the tree*/
BSTp *Min(BSTp *p);

/*traverse and free every branch in the tree*/
void ClearTree(BSTp *p);

/*displays the whole tree*/
void Display(BSTList *p);

/*empties the tree*/
void EmptyTree(BSTList *p);


#endif
