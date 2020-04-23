#include "FamilyTree.hpp"
#include <iostream>
using namespace std;

namespace family
{
    
int count = 0;
int count_help = 0;
int count_help1 = 0;
int i = 0;
int k=0;
int m=0;
TreeNode help5[100];
//string ans[100];
//string ans1[100];

Tree &Tree::addFather(string son_name, string father_name)
{
      ans[k] = son_name;
      k++;
      
      for(int i=0; i<100; i++)
      {
          if(ans[i] == son_name)
          {
              count_help++;
          }
      }
      cout << count_help;
      if(count_help == 2)
      {
            throw std::runtime_error("curly: invalid coconut number");
      }

      else
      {
      count_help = 0;
      TreeNode* help;
      help = new TreeNode;
      help = search1(son_name,root);
    
      TreeNode* new_node;
      new_node = new TreeNode;
      
      help->right = new_node;
      new_node->gen_count = help->gen_count+1;
      new_node->gen1 = "m";
      new_node->person_name = father_name; 
      delete help;
      help = NULL;
    
      return *this;   
      }
    
    
};

Tree &Tree::addMother(string son_name, string mom_name)
{

      ans1[m] = son_name;
      m++;
      for(int i=0; i<100; i++)
      {
          if(ans1[i] == son_name)
          {
              count_help1++;
          }
      }

      if(count_help1 == 2)
      {
         throw std::runtime_error("curly: invalid 1coconut number");
      }
      else
      {

    count_help1 = 0;
   	TreeNode* help1;
    help1 = new TreeNode;
    help1 = search1(son_name,root);
    
    if(help1->left == NULL)
    {
      TreeNode* new_node1;
      new_node1 = new TreeNode;
      help1->left = new_node1;
      new_node1->gen_count = help1->gen_count+1;
      new_node1->gen1 = "f";
      new_node1->person_name = mom_name;
      delete help1;
      help1 = NULL;
    
    return *this;
    }

    }
    return *this;

};

void Tree::display()
{
   inorder_print(root);
};

string Tree::relation(string name)
{
    string append = "";
    string m1 = "great-grandfather";
    string f1 = "great-grandmother";
    
    TreeNode* help_gen;
    help_gen = new TreeNode;
    help_gen = search1(name,root);
    //cout << help_gen->person_name << " ";

    if(help_gen == NULL)
    {
        return "unrelated";
    }

    if(help_gen->gen_count == 0)
    {
        help_gen->gen = "me";
        return "me";
    }

    

    if(help_gen->gen1 == "f")
    {
       if(help_gen->gen_count == 1)
       {
           help_gen->gen = "mother";
           return "mother";
       }
       if(help_gen->gen_count == 2)
       {
           help_gen->gen = "grandmother";
           return "grandmother";
       }
       if(help_gen->gen_count == 3)
       {
           help_gen->gen = "great-grandmother";
           return "great-grandmother";
       }

       if(help_gen->gen_count > 3)
       {
           for(int i=3; i<help_gen->gen_count; i++)
           {
               append+="great-";
           }
           help_gen->gen = append.append(f1);
           append = "";
           return help_gen->gen;
       }

    }
    
    if(help_gen->gen1 == "m")
    {
        if(help_gen->gen_count == 1)
       {
           help_gen->gen = "father";
           return "father";
       }
       if(help_gen->gen_count == 2)
       {
           help_gen->gen = "grandfather";
           return "grandfather";
       }
       if(help_gen->gen_count == 3)
       {
           help_gen->gen = "great-grandfather";
           return "great-grandfather";
       }

       if(help_gen->gen_count > 3)
       {
           for(int i=3; i<help_gen->gen_count; i++)
           {
               append+="great-";

           }
           help_gen->gen = append.append(m1);
           append = "";
           return help_gen->gen;  
       }
    }

    return "";
};

string Tree::find(string name)
{
    TreeNode* currentNode = root;
    currentNode = new TreeNode;
    inorder_print1(root);
    
    for(int i=0; i<100; i++)
    {
        *currentNode = help5[i];
        if(currentNode->gen == name)
        {
           return currentNode->person_name;
        }
    }
        delete currentNode;
        currentNode = NULL;
        throw std::runtime_error("curly: invalid 1coconut number");

    return "";
};

void Tree::remove(string name)
{
    TreeNode* help3;
    help3 = new TreeNode;
    help3 = search1(name,root);
    
    if(help3 == root || help3 == NULL)
    {
        throw std::runtime_error("curly: invalid ffff1coconut number");
    }
    else
    deleteTree(help3);

};

void Tree::deleteTree(TreeNode* &node)  
{  
    if (node == NULL) return;  
    /* first delete both subtrees */
    deleteTree(node->left);  
    deleteTree(node->right);  
      
    /* then delete the node */
    free (node); 
    node = NULL; 
}  

void Tree::inorder_print(TreeNode *ptr)
{
        
  	    if(ptr!=NULL)
	    {
		inorder_print(ptr->left);
		cout<<" "<<ptr->person_name<<" " << endl;
		inorder_print(ptr->right);
        count ++;
	    }
        
}

void Tree::inorder_print1(TreeNode *ptr)
{
  	    if(ptr!=NULL)
	    {
		inorder_print1(ptr->left);
		help5[i] = *ptr;
        //cout<<" "<<ptr->person_name<<" ";
        i++;
        count++;
        
		inorder_print1(ptr->right);
        
	    }
        
}

TreeNode* Tree::search1(string input, TreeNode *root)
{
    TreeNode* currentNode1 = root;
    inorder_print1(root);
    for(int j=0; j<100; j++)
    {
        *currentNode1 = help5[j];
        if(currentNode1->person_name == input)
        {
           return currentNode1;
        }
    }
        //root->gen = "err";
        delete currentNode1;
        currentNode1 = NULL;
        return NULL;

}

}