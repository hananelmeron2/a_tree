#include "FamilyTree.hpp"
#include <iostream>
using namespace std;



namespace family
{
    
int count = 0;
int count1 = 0;
int i = 0;
TreeNode help[100];
TreeNode help1[100];
Tree &Tree::addFather(string son_name, string father_name)
{
    TreeNode* help;
    help = new TreeNode;
    help = search(son_name,root);

    TreeNode* new_node;
    new_node = new TreeNode;

    help->right = new_node;
    new_node->gen_count = help->gen_count+1;
    new_node->gen1 = "m";
    new_node->person_name = father_name;    
    
    return *this;
};



Tree &Tree::addMother(string son_name, string mom_name)
{
   	TreeNode* help;
    help = new TreeNode;
    help = search(son_name,root);

    TreeNode* new_node;
    new_node = new TreeNode;

    help->left = new_node;
    new_node->gen_count = help->gen_count+1;
    new_node->gen1 = "f";
    new_node->person_name = mom_name;
    
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
    if(help_gen->gen_count == 0)
    {
        help_gen->gen = "me";
        return "me";
    }

    if(root->gen == "err")
    {
        return "unrelated";
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
    inorder_print1(root);
    
    for(int i=0; i<count; i++)
    {
        *currentNode = help1[i];
        if(currentNode->gen == name)
        {
           return currentNode->person_name;
        }
    }
        throw invalid_argument("wrong input !");

    return "";
};

void Tree::remove(string name)
{
    TreeNode* help;
    help = new TreeNode;
    help = search(name,root);
    //cout << help->person_name;
    deleteTree(help);
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
		help[i] = *ptr;
        help1[i] = *ptr;
        i++;
        count++;
		inorder_print1(ptr->right);
	    }
}

TreeNode* Tree::search(string input, TreeNode *root)
{
    
    TreeNode* currentNode = root;
    if(currentNode->person_name == input)
	{
		return currentNode;
	}
    else if(currentNode->right != NULL)
    {
        currentNode=currentNode->right;
        return search(input,currentNode);
        
    }
    else if(currentNode->left != NULL)
    {
        currentNode=currentNode->left;
        return search(input,currentNode);
    }

    throw invalid_argument("wrong input !");
   
}

TreeNode* Tree::search1(string input, TreeNode *root)
{
    TreeNode* currentNode = root;
    inorder_print1(root);
    for(int i=0; i<count; i++)
    {
        *currentNode = help[i];
        if(currentNode->person_name == input)
        {
           return currentNode;
        }
    }
        root->gen = "err";
        return root;

}





}
