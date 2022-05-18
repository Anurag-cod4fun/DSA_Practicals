// Beginning with an empty binary search tree, construct binary search tree by inserting the values in the given order.
// after constructing a binary tree
// 1. insert a new node
// 2. Find the minimum nodes in the longest path
// 3. Change the tree so that the roles of left and right pointers and swapped at every node
// 4. search a value

// Name - Anurag S. Patil   Roll no. - SEAIDA04

#include <bits/stdc++.h>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* getnewnode(int data) {
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        root = getnewnode(data);
    }
    else if (data <= root -> data) {
        root -> left = Insert(root->left , data);
    }
    else {
        root -> right = Insert(root->right , data);
    }
    return root;
}


void printInorder(BstNode* root)
{
    if (root == NULL)
        return;
 
    printInorder(root->left);
 
    cout << root->data << " ";
 
    printInorder(root->right);
}

void SwapprintInorder(BstNode* root)
{
    if (root == NULL)
        return;
 
    printInorder(root->right);
 
    cout << root->data << " ";
 
    printInorder(root->left);
}

bool Search(BstNode* root, int data) {
    if (root == NULL) return false;
    else if (root -> data == data) return true;
    else if(data <= root->data) return Search(root->left , data);
    else return Search(root->right , data);
}

int Findmin(BstNode* root) {
    if (root == NULL) {
        cout << "Error: Tree is empty !";
        return -1;
    }

    while (root -> left != NULL) {
        root = root -> left;
    }
    return root -> data;
}

int FindHeight(BstNode* root) {
    if ( root == NULL) {
        return -1;
    }
    int leftH = FindHeight(root -> left);
    int rightH = FindHeight(root -> right);

    return max(leftH , rightH) + 1;
}

int main() {
  BstNode* root = NULL;
      cout << "1. Insert new node" << "\n";
      cout << "2. Find number of nodes in longest path" << "\n";
      cout << "3. Minimum data value in the tree" << "\n";
      cout << "4. Swap left and right pointers" << "\n";
      cout << "5. Search a value" << "\n";
      cout << "6. Diaply in Inorder" << "\n";
      cout << "7. Exit" << "\n";
  while(true) {
      int o;
      cout << "Enter the any option : ";
      cin >> o;

      if (o == 1) {
          int data;
          cout << "Enter the value of data to be insert : ";
          cin >> data;
          root = Insert(root , data);
      }

      if (o == 2) {
          int h = FindHeight(root);
          cout << "Max Height is " << h << "\n";
      }

      if (o == 3) {
          int min = Findmin(root);
          cout << "Minimum data value : "<< min << "\n";
      }

      if ( o == 4) {
          SwapprintInorder(root);
          cout << "\n";
      }

      if (o == 5) {
          int data;
          cout << "Enter the value to be searched : ";
          cin >> data;
          bool ans = Search(root , data);
          if (ans) {
              cout << data << " " << "is present in the tree !" << "\n";
          }
          else {
              cout << data << " " << "is not present in the tree !" << "\n";
          }
      }

      if (o == 6) {
          printInorder(root);
          cout << "\n";
      }

      if (o == 7) {
          exit(0);
      }
  } 
}