/* DPS_Node.cpp */

/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "node.h"




Node::Node(void): key_value(NULL), next(0) {}


/*Node::node(const char * file_to_load)
{
   

}*/




Node::~Node(void)
{
    if(key_value)
    {
        delete [] key_value;
        key_value = NULL;
    }

    next = NULL;
}



char *  Node::get_key_value()
{
    return key_value;
}

void Node::next_node(Node * to_next)
{
    next = to_next;
    return;
}

Node *& Node::next_node(void)
{
    return next;
}

void Node::clear_screen()
{
    for(int i = 0; i < 5; ++i )
        cout<<"\n\n\n\n\n\n\n\n\n\n";
}





List::List()
{
    head = NULL;
    file_name = NULL;
}

List::List(const char * file_to_load)
{
    head = NULL;
    
    file_name = new char[strlen(file_to_load) + 1];
    strcpy(file_name, file_to_load);

    load_from_file(file_name);
}

List::~List()
{
    if(file_name)
    {
        save_to_file(file_name);
        delete [] file_name;
        file_name = NULL;
    }

    delete_list(head);
}


void List::insert(Node *& to_insert)
{
    return insert(head, to_insert);
}

void List::insert(Node *& head, Node *& to_insert)
{
    if(!head)
    {
        head = to_insert;
        return;
    }
    if(0 < strcmp(head->get_key_value(),to_insert->get_key_value()))
        return insert(head->next_node(), to_insert);

    to_insert->next_node(head);
    head = to_insert;
    return;
 
}

void List::display_list(void)
{
    return display_list(head);
}

void List::display_list(Node * head)
{
    if(!head)
        return;
    head->display();
    return display_list(head->next_node());
}

bool List::find(const char * to_find)
{
    return find(head, to_find);
}



bool List::find(Node * head, const char * to_find)
{
    if(!head)
    {   
        cout << endl << to_find << " not found." << endl;
        return false;
    }
    
    if(!strcmp(head->get_key_value(), to_find))
    {
        cout << endl << "Comparing " << to_find << " with " << head->get_key_value() << endl;
        cout << endl << to_find << " found." << endl;
        return true;
    }

    return find(head->next_node(), to_find);

}

bool List::remove(const char * to_remove)
{
    return remove(head, to_remove);
}


bool List::remove(Node *& head, const char * to_remove)
{
     if(!head)
        return false;
     if(!strcmp(head->get_key_value(), to_remove))
     {
        Node * temp = head->next_node();
        delete head;
        head = temp;
        return true;
     }
     return remove(head->next_node(), to_remove);
}



bool List::edit(const char * to_edit)
{
    return edit(head, to_edit);
}

bool List::edit(Node *& head, const char * to_edit)
{
    if(!head)
        return false;
    if(!strcmp(head->get_key_value(), to_edit))
    {
        head->get_info();
        return true;
    }
    return edit(head->next_node(), to_edit);
}

void List::delete_list()
{
    return delete_list(head);
}

void List::delete_list(Node *& head)
{
    if(!head)
        return;
    delete_list(head->next_node());
    delete head;
    head = NULL;
    return;
}


void List::load_from_file(char * file_name)
{
/*    Node * to_load;
    ifstream file_in;
    file_in.open(file_name);
    
    if(!strcmp(file_name, "Codes/Manager.txt") || !strcmp(file_name, "Codes/Provider.txt"))
    {

        while(file_in && !file_in.eof())
        {
            to_load = new Credential;
            to_load->load_from_file(file_in);
            insert(to_load);
        }
        file_in.close();
    }
    if(!strcmp(file_name, "Codes/Manager.txt") || !strcmp(file_name, "Codes/Provider.txt"))
    {

        while(file_in && !file_in.eof())
        {
            to_load = new ;
            to_load->load_from_file(file_in);
            insert(to_load);
        }
        file_in.close();
    }
    


 */


}

void List::load_from_file(Node *& head, Node *& to_load, ifstream & file_in)
{


}

void List::save_to_file(char * file_name)
{
    if(!head)
        return;
    ofstream file_out;
    file_out.open(file_name);

    return save_to_file(head, file_out);
}

void List::save_to_file(Node * head, ofstream & file_out)
{

}

