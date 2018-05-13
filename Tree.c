/*

Platform:
- GCC Version: (Apple LLVM version 9.0.0 (clang-900.0.39.2) Target: x86_64-apple-darwin16.7.0)
- Online Complier (https://www.onlinegdb.com/online_c_compiler)
Author: Tim
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  unsigned long     data;
  struct node* left;
  struct node* right;
}Node;

typedef struct{
  Node*    root;
}BSTHead;

/*
  Create The Binary Search Tree
*/
BSTHead* CreateBST(){
  BSTHead* myTree =  (BSTHead *) malloc (sizeof(BSTHead));
  myTree -> root = NULL;
  return myTree;
}

void AddNodeRecursively(Node* root, unsigned long data){
  if (data>= root->data){
    if (root -> right == NULL){
      Node* pNew = (Node *) malloc(sizeof(Node));
      pNew -> data = data;
      pNew -> left = NULL;
      pNew -> right = NULL;

      root -> right = pNew;

    }else {
      AddNodeRecursively(root -> right, data);
    }
  }else{
    if (root -> left == NULL){
      Node* pNew = (Node *) malloc(sizeof(Node));
      pNew -> data = data;
      pNew -> left = NULL;
      pNew -> right = NULL;

      root -> left = pNew;
    }else {
      AddNodeRecursively(root -> left, data);
    }
  }
}

void AddNode(BSTHead* myBST, unsigned long data){
  if(myBST-> root ==NULL){

    Node* pNew = (Node *) malloc(sizeof(Node));
    pNew -> left = NULL;
    pNew -> right = NULL;
    pNew -> data = data;

    myBST ->root = pNew;

  }else{
    // Node* root =(Node *) malloc(sizeof(Node));
    // root =myBST -> root;
    AddNodeRecursively(myBST -> root, data);
  }
}

void TraversalInOrder(Node* root){
  if (root != NULL){
    TraversalInOrder(root -> left);
    printf ("%lu, ", root->data);
    TraversalInOrder(root -> right);
  }
  // if we prunsigned long it inorder way
  // then the output should be in order
  // if the output is in order, then the program works well
}

void CountNodes(Node* root, unsigned long* p_count){

  if (root !=NULL){

    CountNodes(root -> left, p_count);

    CountNodes(root -> right, p_count);
    ++*p_count;
    // printf("%lu ", *p_count);
  }
}

unsigned long GetHeight(Node* root)
{
   if (root==NULL)
       return 0;
   else
   {

       unsigned long l = GetHeight(root->left);
       unsigned long r = GetHeight(root->right);


       if (l > r) {
         return(l+1);
       }else{
         return(r+1);
       }
   }
}

Node * SearchNodeRecursively(Node *node, unsigned long data){
  if (node -> data == data){
    return node;
  }else{
    if (node -> data > data){
      return SearchNodeRecursively(node -> left, data);
    }else{
      return SearchNodeRecursively(node -> right, data);
    }
  }
}
Node * SearchNode(Node *node, unsigned long data){
  if (node == NULL){
    printf("Error, root is empty");
    return NULL;
  }else{
    return SearchNodeRecursively(node, data);
  }
}


Node * SearchNodeParentRecursively(Node *node, unsigned long data){
  if (node -> left-> data == data || node -> right -> data == data ){
    return node;
  }
  else{
    if (node -> data > data){
      return SearchNodeParentRecursively(node -> left, data);
    }else{
      return SearchNodeParentRecursively(node -> right, data);
    }
  }
}

Node * SearchNodeParent(Node *node, unsigned long data){
  if (node == NULL){
    printf("Error, root is empty");
    return NULL;
  }else{
    return SearchNodeParentRecursively(node, data);
  }
}

unsigned long Search(Node * node, unsigned long data){
  if (SearchNode(node, data) != NULL){
    return 1;
  }else{
    return 0;
  }
}

void DeleteTreeFromRoot(Node *root){
  if (root!=NULL){
    DeleteTreeFromRoot(root->left);
    DeleteTreeFromRoot(root->right);
    free (root);

    if (root -> left != NULL){
      root -> left = NULL;
    }
    if (root -> right != NULL){
      root -> right = NULL;
    }

    root = NULL;


  }
}
void DeleteTree(BSTHead *myBST){
  DeleteTreeFromRoot(myBST->root);

  free(myBST);
  myBST = NULL;
}

void EmptyTreeFromRoot(Node *root){
  if (root!=NULL){
    EmptyTreeFromRoot(root->left);
    EmptyTreeFromRoot(root->right);
    root -> data =0;
  }
}
void EmptyTree(BSTHead *myBST){
  EmptyTreeFromRoot(myBST->root);
}


Node * GetLeftestNodeParentRecursively(Node *root){
  Node * node = (Node *) malloc(sizeof(Node));
  node = NULL;
  if (root->left-> left == NULL){
    node = root;
  }else{
    node = GetLeftestNodeParentRecursively(root -> left);
  }
  return node;
}

Node * GetLeftestNodeParent(Node *root){
  if (root == NULL){
    printf("Error, root is empty");
    return NULL;
  }else{
    return GetLeftestNodeParentRecursively(root);
  }
}

Node * GetRightestNodeParentRecursively(Node *root){
  Node * node = (Node *) malloc(sizeof(Node));
  node = NULL;
  if (root->right-> right == NULL){
    node = root;
  }else{
    node = GetRightestNodeParentRecursively(root -> right);
  }
  return node;
}

Node * GetRightestNodeParent(Node *root){
  if (root == NULL){
    printf("Error, root is empty");
    return NULL;
  }else{
    return GetRightestNodeParentRecursively(root);
  }
}


Node * GetLeftestNode(Node *root){
  if (root == NULL && root ->left != NULL){
    printf ("Error, root is empty");
    return NULL;
  }

  return GetLeftestNodeParent(root)->left;

}
Node * GetRightestNode(Node *root){
  if (root == NULL && root ->right != NULL){
    printf ("Error, root is empty");
    return NULL;
  }
  return GetRightestNodeParent(root)->right;

}

unsigned long GetSmallest(Node *root){
  unsigned long rv=0;
  if (root != NULL){
    rv = GetLeftestNode(root) -> data;
  }else{
    printf("Error, no root\n");
    rv =-1; //will be a very big number
  }
  return rv;
}
unsigned long GetLargest(Node *root){
  unsigned long rv=0;
  if (root != NULL){
    rv = GetRightestNode(root) -> data;
  }else{
    printf("Error, no root\n");
    rv =-1; //will be a very big number

  }
  return rv;
}


Node* DeleteNode(Node* root, int data)
{

    if (root == NULL) return root;


    if (data < root->data)
        root->left = DeleteNode(root->left, data);


    else if (data > root->data)
        root->right = DeleteNode(root->right, data);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = GetLeftestNode(root->right);

        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data);
    }
    return root;
}




int main(){
  BSTHead* myBST = CreateBST();

  AddNode(myBST, 17);
  AddNode(myBST, 20);
  AddNode(myBST, 11);
  AddNode(myBST, 17);
  AddNode(myBST, 127);
  AddNode(myBST, 1);
  AddNode(myBST, 11);
  AddNode(myBST, 9);

  printf("show the tree: \n");
  TraversalInOrder(myBST -> root);

// searching test
  printf("\nsearching 111 and 127: \n");
  unsigned long s = Search(myBST -> root, 127);
  printf ("result of finding 11 %lu \n", s);

  s = Search(myBST -> root, 127);
  printf ("result of finding 127 %lu \n", s);

// counting test
  printf("count of tree: ");
  unsigned long count;
  CountNodes(myBST -> root, &count) ;
  printf("%lu \n", count);

// get tree height
  unsigned long h=GetHeight(myBST -> root);
  printf("tree height: %lu \n", h);

// test to find a node
  Node * node =SearchNode(myBST -> root, 17);
  if (node!=NULL){
    printf("looking for %lu and it exsists \n", node-> data);
  }

// finding Leftest and Rightest data, they are using the same way to find the node
  unsigned long Leftest = GetSmallest(myBST-> root);
  printf("left most %lu \n", Leftest);

  unsigned long Rightest = GetLargest(myBST-> root);
  printf("right most %lu \n", Rightest);


// delete 9
  printf("deleting a node \n");

  DeleteNode(myBST -> root, 9);
  DeleteNode(myBST -> root, 999);
// and print tree again to see result
  TraversalInOrder(myBST -> root);

  //empty tree
  EmptyTree(myBST);
  // testing after empty the tree
  printf("\nafter empty the data on root is %lu \n", myBST->root -> data);

  // Delete tree
  printf("after deleting the tree: \n");
  DeleteTree(myBST);
  // testing after deleting the tree
  h=GetHeight(myBST -> root);
  printf("tree height: %lu \n", h);
  printf("after delete %lu \n", myBST -> root -> left -> data);

  // system("pause");
  return 0;

}