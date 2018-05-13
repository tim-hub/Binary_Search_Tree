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



Node * GetSmallestNodeParentRecursively(Node *root){
  Node * node = (Node *) malloc(sizeof(Node));

  if (root->left-> left == NULL){
    node = root;
  }else{
    node = GetSmallestNodeParentRecursively(root -> left);
  }
  return node;
}

Node * GetLargestNodeParentRecursively(Node *root){
  Node * node = (Node *) malloc(sizeof(Node));

  if (root->right-> right == NULL){
    node = root;
  }else{
    node = GetLargestNodeParentRecursively(root -> right);
  }
  return node;
}


unsigned long GetSmallestRecursively(Node *root){
  unsigned long rv=0;
  if (root->left != NULL){
    rv =GetSmallestRecursively(root -> left);
  }else{
    rv= root -> data;
  }
  return rv;
}

unsigned long GetLargestRecursively(Node *root){
  unsigned long rv=0;

  if (root->right != NULL){
    rv =GetLargestRecursively(root -> right);
  }else{
    rv= root -> data;
  }
    return rv;


}

unsigned long GetSmallest(Node *root){
  unsigned long rv=0;
  if (root != NULL){
    rv = GetSmallestRecursively(root);
  }else{
    printf("no root");
    rv =-1;
  }
  return rv;
}
unsigned long GetLargest(Node *root){
  unsigned long rv=0;
  if (root != NULL){
    rv = GetLargestRecursively(root);
  }else{
    printf("no root");
    rv =-1;
  }
  return rv;
}



unsigned long Delete(Node *root, unsigned long data){
  /*
  * The idea to safely delete a node on a binary search tree
  * Find the node, nodeD
  * Find the largest node on left side of node
  * If null node on left, find right smallest node, it is nodeAlter
  * Set data of this node is the data from nodeD we found on last step
  * connect nodeD"s child to nodeD"s parent
  */
  Node * nodeD = (Node *) malloc(sizeof(Node));
  Node * nodeAlter = (Node *) malloc(sizeof(Node));
  Node * nodeAlter_Parent = (Node *) malloc(sizeof(Node));

  if (root != NULL){
    printf("Error, please do not give me an empty tree\n");
    return 0;
  }
  else{
    // find the first node whose data equals to data
    nodeD = SearchNode(root, data);
    if (nodeD == NULL){
      printf("Error, we cannot find data %lu \n", data);
      return 0;
    }

    // find left largest of nodeD





  }

  return 0;

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
  printf("looking for %lu and it exsists \n", SearchNode(myBST -> root, 7)-> data);

// finding smallest and largest data
  unsigned long Smallest = GetSmallest(myBST-> root);
  printf("left most %lu \n", Smallest);

  unsigned long Largest = GetLargest(myBST-> root);
  printf("right most %lu \n", Largest);

// finding smallest largest node
  Node * node = (Node *) malloc(sizeof(Node));
  Node * root = myBST -> root;
  if (root == NULL){
    printf("cannot search, root is null");
    node=  NULL;
  }else if (root -> left ==NULL){
    printf("the root is smallest");
    node= NULL;
    printf("smalles data %lu", root ->data);
  }else if(root->left->left ==NULL){
    node = root;
    printf("smalles data %lu", node->left ->data);
  }
  else
  {
    node =GetSmallestNodeParentRecursively(root);
    printf("smalles data %lu \n", node -> left->data);
  }








  //empty tree
  EmptyTree(myBST);
  // testing after empty the tree
  printf("after empty the data on root is %lu \n", myBST->root -> data);

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