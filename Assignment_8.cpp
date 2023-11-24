#include <iostream>
using namespace std;
struct node_stack
{
    string data;
    node_stack *next;
};
node_stack *top=NULL;
class stack
{
 public:
    void Push(string operation)
    {   
        if(top=NULL)
        {
            node_stack *New_Node= new node_stack;
            New_Node->data=operation;
            New_Node->next=NULL;
            top=New_Node;
        }
        else
        {
            node_stack *temp=top;
            node_stack *New_Node= new node_stack;
            New_Node->data=operation;
            New_Node->next=temp;
            top=New_Node;
        }
    }    
    void Pop(string operation)
    {
        node_stack *temp=top;
        
    }
};