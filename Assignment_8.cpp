#include <iostream>
#include <string>
using namespace std;
struct node_stack
{
    char data;
    node_stack *next;
};
node_stack *top = NULL;
class stack
{
public:
    string final_exp;
    bool comparison(char operation)
    {
        if (operation = '(')
        {
            return false;
        }
        int value_operation;
        int value_top_data;
        if (operation == top->data)
        {
            return false;
        }
        if (operation == '+' || operation == '-')
        {
            value_operation = 1;
        }
        if (operation == '/' || operation == '*')
        {
            value_operation = 2;
        }
        if (operation == '^')
        {
            value_operation = 3;
        }
        if (top->data == '+' || top->data == '-')
        {
            value_top_data = 1;
        }
        if (top->data == '/' || top->data == '*')
        {
            value_top_data = 2;
        }
        if (top->data== '^')
        {
            value_operation = 3;
        }

        if (value_operation > value_top_data)
        {
            return false;
        }
        else if (value_operation < value_top_data)
        {
            return true;
        }
        return 0;
    }
    void Push(char operation)
    {
        if (top = NULL)
        {
            node_stack *New_Node = new node_stack;
            New_Node->data = operation;
            New_Node->next = NULL;
            top = New_Node;
        }
        else
        {
            node_stack *temp = top;
            node_stack *New_Node = new node_stack;
            New_Node->data = operation;
            New_Node->next = temp;
            top = New_Node;
        }
    }
    void Pop()
    {
        node_stack *temp = top;
        top = top->next;
        free(temp);
    }

    void Postfix(string exp)
    {
        exp += ')';
        Push('(');
        for (int i = 0; i < exp.length(); i++)
        {
            if (exp[i] == '(')
            {
                while (exp[i] != ')')
                {
                    if (comparison(exp[i]) == true)
                    {
                        final_exp += top->data;
                        Pop();
                        Push(exp[i]);
                        i++;
                    }
                    else
                    {
                        Push(exp[i]);
                        i++;
                    }
                }
                while (top->data != '(')
                {
                    final_exp += top->data;
                    Pop();
                }
                Pop();
                i++;
            }
            else
            {
                if (comparison(exp[i]) == true)
                {
                    final_exp += top->data;
                    Pop();
                    Push(exp[i]);
                }
                else
                {
                    Push(exp[i]);
                }
            }
        }
    }
};

int main()
{
    stack obj;
    string Faltu_String;
    cout << "Enter an expression \n";
    cin >> Faltu_String;
    cout << "Where do you want your expression to go\n 1)Prefix \n2)Postfix \n3)Infix\nChoose a Choice\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        
    case 2:
        obj.Postfix(Faltu_String);
        cout<<endl<<obj.final_exp;

    }

    return 0;
}