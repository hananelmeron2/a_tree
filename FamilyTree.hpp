#include <iostream>
#include <string>
using namespace std;

namespace family
{
    
    // struct to create family tree node
    struct TreeNode
    {
      public:
	  string person_name;
      int gen_count;
      int count_right = 0 ;
      string gen;
      string gen1;
      TreeNode* left;
      TreeNode* right;
      TreeNode* parent;
      
      
    };

    
    class Tree
    {
        TreeNode* root; 
        string input;
        string ans[100];
        string ans1[100];

        public:

        Tree(string person_name)
        {
            input = person_name;
            root = new TreeNode; // create new node, need to be removed!
            root->person_name = input;  //the given name
            root->left = NULL;
            root->right = NULL;
            root->parent = NULL;
            root->count_right = 0;
            root->gen_count = 0;
            root->gen = "";
             
        }

        //the family tree function

        Tree &addFather(string son_name, string father_name); // add father function
        Tree &addMother(string son_name, string mom_name);    // add mother function
        string relation(string name);                        // return the relation of the input family member to the root(yourself)
        string find(string name);                            // get realation and return the family member that suit
        void remove(string name);                            //remove the given name and all his relation 
        void display();                                      // dispaly the family tree
        

        private:
        
        TreeNode* search1(string input, TreeNode *root);
        void inorder_print(TreeNode *ptr);                 //help function for display
        void inorder_print1(TreeNode *ptr);
        void deleteTree(TreeNode* &node);

        

    };

};
