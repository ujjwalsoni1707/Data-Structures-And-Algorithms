#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "Dictionary.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;
//template <Key, Value>
class BSTree : public Dictionary<Key, Value> {
 
 private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;

virtual void insert(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
  // is this a new tree?
  if(isEmpty()) root = t;
  else
  {
    //Note: ALL insertions are as leaf nodes
    tree_node* curr;
    curr = root;
    // Find the Node's parent
    while(curr)
    {
        parent = curr;
        if(t->data > curr->data) curr = curr->right;
        else curr = curr->left;
    }

    if(t->data < parent->data)
       parent->left = t;
    else
       parent->right = t;
  }
}

virtual void remove(int d)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr->data == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->data) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {
        cout<<" Data not found! "<<endl;
        return;
    }


		 // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
&& curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

		 //We're looking at a leaf node
		 if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
		 		 delete curr;
		 		 return;
    }


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		 		 		 		 curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
		 		 		    curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}
        
  virtual int getHeight();
  /*o
   * This method returns the total number of elements in the binary search tree.
   */
  virtual int size();
  /*
   * This method prints the key value pairs of the binary search tree, sorted by
   * their keys.
   */
  virtual void print();
  /*
   *This method takes as an argument a function func.
   *Then it traverses along the tree in in-order traversal, and calls func
   *with every key value pair in the BSTree.
   */
  virtual void in_order(void (*fun)(const Key& key, const Value& value));
/*
   *This method takes as an argument a function func.
   *Then it traverses along the tree in pre-order traversal, and calls func
   *with every key value pair in the BSTree.
   */
  virtual void preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<" "<<p->data<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

/*
   *This method takes as an argument a function func.
   *Then it traverses along the tree in post-order traversal, and calls func
   *with every key value pair in the BSTree.
   */
  virtual void post_order(void (*fun)(const Key& key, const Value& value));

  /*
   *This method print all the key value pairs of the binary search tree, as
   *observed in an in order traversal.
   */
  virtual void print_in_order();
  /*
   *This method print all the key value pairs of the binary search tree, as
   *observed in an pre order traversal.
   */
  virtual void print_pre_order();
  /*
   *This method print all the key value pairs of the binary search tree, as
   *observed in a post order traversal.
   */
  {
  preorder(root);
}
  virtual void print_post_order();
  /*
   *This method returns the minimum element in the BST.
   */
  virtual Key minimun();
  /*
   * This method returns the maximum element in the BST.
   */
  virtual Key maximum();
  /*
   *This method returns the successor, i.e, the next larget element in the
   *BSTree, after Key.
   */
  virtual Key successor(const Key& key);
  /*
   * This method returns the predessor, ie, the next smallest element in the
   * BSTree, after Key.
   */
  virtual Key predecessor(const Key& key);
}

#endif /* ifndef BSTREE_HPP */