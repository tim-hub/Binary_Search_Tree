/*

Platform:
- GCC Version: (Apple LLVM version 9.0.0 (clang-900.0.39.2) Target: x86_64-apple-darwin16.7.0)
- Online Complier (https://www.onlinegdb.com/online_c_compiler)
Author: Tim
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  signed long     data;
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

void AddNodeRecursively(Node* root, signed long data){
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

void AddNode(BSTHead* myBST, signed long data){
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
  // if we prsigned long it inorder way
  // then the output should be in order
  // if the output is in order, then the program works well
}

void CountNodes(Node* root, signed long* p_count){

  if (root !=NULL){

    CountNodes(root -> left, p_count);

    CountNodes(root -> right, p_count);
    ++*p_count;
    // printf("%lu ", *p_count);
  }
}

signed long GetHeight(Node* root)
{
   if (root==NULL)
       return 0;
   else
   {

       signed long l = GetHeight(root->left);
       signed long r = GetHeight(root->right);


       if (l > r) {
         return(l+1);
       }else{
         return(r+1);
       }
   }
}

Node * SearchNodeRecursively(Node *node, signed long data){
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
Node * SearchNode(Node *node, signed long data){
  if (node == NULL){
    printf("Error, root is empty");
    return NULL;
  }else{
    return SearchNodeRecursively(node, data);
  }
}


Node * SearchNodeParentRecursively(Node *node, signed long data){
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

Node * SearchNodeParent(Node *node, signed long data){
  if (node == NULL){
    printf("Error, root is empty");
    return NULL;
  }else{
    return SearchNodeParentRecursively(node, data);
  }
}

signed long Search(Node * node, signed long data){
  if (SearchNode(node, data) != NULL){
    return 1;
  }else{
    return 0;
  }
}

//delete all nodes expect header
void EmptyAllNodes(Node *root){
  if (root!=NULL){
    EmptyAllNodes(root->left);
    EmptyAllNodes(root->right);
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
void EmptyTree(BSTHead *myBST){
  EmptyAllNodes(myBST->root);
  myBST -> root = NULL;
  free (myBST -> root);
  myBST -> root = NULL;

}

void DeleteTree(BSTHead *myBST){
  EmptyTree(myBST);
  free(myBST);
  myBST = NULL;
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

signed long GetSmallest(Node *root){
  signed long rv=0;
  if (root != NULL){
    rv = GetLeftestNode(root) -> data;
  }else{
    printf("Error, no root\n");
    rv =-1; //will be a very big number
  }
  return rv;
}
signed long GetLargest(Node *root){
  signed long rv=0;
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

void PopulateTree(BSTHead* myBST, int length){
  for (int i=0; i<length; i++){
    AddNode(myBST, (rand()%(10000+1-1)) +1);
  }
}



int main(){
  BSTHead* myBST = CreateBST();

// populate the tree automatically
  PopulateTree(myBST, 10);

// populate the tree manually
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
  signed long s = Search(myBST -> root, 127);
  printf ("result of finding 11: (1 means exist) %lu \n", s);

  s = Search(myBST -> root, 127);
  printf ("result of finding 127: (1 means exist) %lu \n", s);

// counting test
  printf("count of tree: ");
  signed long count;
  CountNodes(myBST -> root, &count) ;
  printf("%lu \n", count);

// get tree height
  signed long h=GetHeight(myBST -> root);
  printf("tree height: %lu \n", h);

// test to find a node
  Node * node =SearchNode(myBST -> root, 17);
  if (node!=NULL){
    printf("looking for %lu and it exsists \n", node-> data);
  }

// finding Leftest and Rightest data, they are using the same way to find the node
  signed long Leftest = GetSmallest(myBST-> root);
  printf("left most %lu \n", Leftest);

  signed long Rightest = GetLargest(myBST-> root);
  printf("right most %lu \n", Rightest);


// delete 9
  printf("deleting a node 9 which exist \n");

  DeleteNode(myBST -> root, 9);
// and print tree again to see result
  TraversalInOrder(myBST -> root);

// delete a node which does not exist
  printf("deleting a node 999 which does not exist \n");
  DeleteNode(myBST -> root, 999);
// and print tree again to see result
  TraversalInOrder(myBST -> root);

  //empty tree
  printf("\n go to empty the tree \n");
  EmptyTree(myBST);
  // testing after empty the tree
  printf("\n empty the tree \n");



  // Delete tree
  printf("after deleting the tree: \n");
  DeleteTree(myBST);
  // testing after deleting the tree
  h=GetHeight(myBST -> root);
  printf("return error after delete %lu \n", myBST -> root -> left -> data);

  // system("pause");
  return 0;

}