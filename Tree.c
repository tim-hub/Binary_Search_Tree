/*

Platform:
- GCC Version: (Apple LLVM version 9.0.0 (clang-900.0.39.2) Target: x86_64-apple-darwin16.7.0)
- Online Complier (https://www.onlinegdb.com/online_c_compiler)
Author: Tim
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int     data;
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

void AddNodeRecursively(Node* root, int data){
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

void AddNode(BSTHead* myBST, int data){
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
    printf ("%d, ", root->data);
    TraversalInOrder(root -> right);
  }
  // if we print it inorder way
  // then the output should be in order
  // if the output is in order, then the program works well
}



void EmptyTreeFromRoot(Node *root){
  if (root!=NULL){
    EmptyTreeFromRoot(root->left);
    EmptyTreeFromRoot(root->right);
  }else{
    free(root);
  }
}
void EmptyTree(BSTHead *myBST){
  EmptyTreeFromRoot(myBST->root);
  free(myBST);
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
// Node * GetSmallestNodeParent(Node *root){
//   if (root == NULL){
//     printf("cannot search, root is null");
//     return NULL;
//   }else if (root -> left ==NULL){
//     printf("the root is smallest");
//     return NULL;
//   }else if(root->left->left ==NULL){
//     return root;
//   }else{
//     return GetSmallestNodeParentRecursively(root);
//   }
// }

int GetSmallestRecursively(Node *root){
  int rv=0;
  if (root->left != NULL){
    rv =GetSmallestRecursively(root -> left);
  }else{
    rv= root -> data;
  }
  return rv;
}

int GetLargestRecursively(Node *root){
  int rv=0;

  if (root->right != NULL){
    rv =GetLargestRecursively(root -> right);
  }else{
    rv= root -> data;
  }
    return rv;


}

int GetSmallest(Node *root){
  int rv=0;
  if (root != NULL){
    rv = GetSmallestRecursively(root);
  }else{
    printf("no root");
    rv =-1;
  }
  return rv;
}
int GetLargest(Node *root){
  int rv=0;
  if (root != NULL){
    rv = GetLargestRecursively(root);
  }else{
    printf("no root");
    rv =-1;
  }
  return rv;
}

void CountNodes(Node* root, int* p_count){

  if (root !=NULL){

    CountNodes(root -> left, p_count);

    CountNodes(root -> right, p_count);
    ++*p_count;
    // printf("%d ", *p_count);
  }
}

int GetHeight(Node* root)
{
   if (root==NULL)
       return 0;
   else
   {

       int l = GetHeight(root->left);
       int r = GetHeight(root->right);


       if (l > r) {
         return(l+1);
       }else{
         return(r+1);
       }
   }
}

int Search(Node * node, int data){
  if (node != NULL){
    if (node -> data == data){
      return 1;
    }else{
      if (node -> data > data){
        Search(node -> left, data);
      }else{
        Search(node -> right, data);
      }
      return 0;
    }
  }else{
    return 0;
  }
}


Node * SearchNode(Node *node, int data){
  if (node -> data == data){
    return node;
  }else{
    if (node -> data > data){
      Search(node -> left, data);
    }else{
      Search(node -> right, data);
    }
  }
  return NULL;
}

int Delete(Node *root, int data){
  if (root != NULL){
    if (root -> data == data){

      Node * node = (Node *) malloc(sizeof(Node));

      if (root -> left == NULL && root -> right == NULL){
        printf("cannot search in left sub tree \n");
        printf("cannot search in right sub tree");

        // delete the only node
        root = NULL;
        return 1;

      }else{
        if (root -> left != NULL) {

        }else{
          printf("the root is smallest");
          node= NULL;
          printf("smalles data %d", root ->data);
        }
      }



      // else if (root -> left ==NULL){

      // }else if(root->left->left ==NULL){
      //   node = root;
      //   printf("smalles data %d", node->left ->data);
      // }
      // else
      // {
      //   node =GetSmallestNodeParentRecursively(root);
      //   printf("smalles data %d", node -> left->data);
      // }



    //   return 1;

    // }else{
    //   if (node -> data > data){
    //     Search(node -> left, data);
    //   }else{
    //     Search(node -> right, data);
    //   }
    //   return 0;
    }
  }else{
    return 0;
  }
}



int main(){
  BSTHead* myBST = CreateBST();

  AddNode(myBST, 7);
  AddNode(myBST, 10);
  AddNode(myBST, 1);
  AddNode(myBST, 7);
  AddNode(myBST, 127);
  AddNode(myBST, -023);
  AddNode(myBST, 1);
  AddNode(myBST, -7);

  printf("show the tree: \n");
  TraversalInOrder(myBST -> root);

// searching test
  printf("\nsearching 7 and 99: ");
  int s = Search(myBST -> root, 7);
  printf ("%d ", s);

  s = Search(myBST -> root, 99);
  printf ("%d \n", s);

// counting test
  printf("count of tree: ");
  int count;
  CountNodes(myBST -> root, &count) ;
  printf("%d \n", count);

// finding smallest and largest data
  int Smallest = GetSmallest(myBST-> root);
  printf("left most %d \n", Smallest);

  int Largest = GetLargest(myBST-> root);
  printf("right most %d \n", Largest);

// finding smallest largest node
  Node * node = (Node *) malloc(sizeof(Node));
  Node * root = myBST -> root;
  if (root == NULL){
    printf("cannot search, root is null");
    node=  NULL;
  }else if (root -> left ==NULL){
    printf("the root is smallest");
    node= NULL;
    printf("smalles data %d", root ->data);
  }else if(root->left->left ==NULL){
    node = root;
    printf("smalles data %d", node->left ->data);
  }
  else
  {
    node =GetSmallestNodeParentRecursively(root);
    printf("smalles data %d", node -> left->data);
  }

  // get tree height
  int h=GetHeight(myBST -> root);
  printf("tree height: %d \n", h);

  //empty tree
  EmptyTree(myBST);
  // testing after empty the tree
  printf(myBST->root -> data);


  // system("pause");
  return 0;

}