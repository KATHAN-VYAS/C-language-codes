  #include <stdio.h>
#include <stdlib.h>
  
  struct node 
  {
    int data ;
    struct node* left;
    struct node* right ;
  };

  struct node* creatnode(int x)
  {
    struct node* root = (struct node*)malloc(sizeof (struct node));
    root -> data =x;
    root -> left = NULL;
    root -> right = NULL;
    return root;
  }
  

  void preorder(struct node* root)
  {
    if (root == NULL)
    {
        return ;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
  }
  void inorder(struct node* root)
  {
    if (root == NULL)
    {
        return ;
    }
    inorder(root ->left );
    printf("%d",root->data);
    inorder(root->right);
  }
  void postorder(struct node* root)
  {
    if (root == NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf ("%d",root ->data);
  }

  
  int search(struct node* root, int num) {
    if (root == NULL) {
        return 0; 
    }

    if (root->data == num) {
        return 1; 
    }

 
    int left_search = search(root->left, num);
    if (left_search) {
        return 1; 
    }

    int right_search = search(root->right, num);
    if (right_search) {
        return 1; 
    }

    return 0; 
}

  int main ()
  {
    int num;
    struct node* root = creatnode(1);
    root -> left = creatnode(2);
    root -> right = creatnode(3);
    (root ->right)-> left = creatnode(4);
    (root ->right)-> right = creatnode(5);
    printf("preorder traversal:\n");
    preorder(root);
    printf("\n");
    printf("postorder traversal:\n");
    postorder(root);
    printf("\n");
    printf("inorder traversal:\n");
    inorder(root);
    printf("\n");
    
    num = 2;
    if (search(root, num)) {
        printf("Element %d found\n", num);
    } else {
        printf("Element %d not found\n", num);
    }
    num = 100;
    if (search(root, num)) {
        printf("Element %d found\n", num);
    } else {
        printf("Element %d not found\n", num);
    }
   
    return 0;
  }
    