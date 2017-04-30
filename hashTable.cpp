/* DPS_HashTable.cpp */



/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "hashTable.h"



//Constructor
//Task:
//Input: 
//Output:
Hash_table::Hash_table()
{
    table_size = TABLE_SIZE;
    table_array = new Node*[table_size];
    for(int i = 0; i < table_size; ++i)
    {
        table_array[i] = NULL;
    }
}

//Constructor with input

//Task:
//Input: 
//Output:
Hash_table::Hash_table(const char * file_name)
{

    table_size = TABLE_SIZE;
    table_array = new Node*[table_size];
    
    for(int i = 0; i < table_size; ++i)
    {
        table_array[i] = NULL; 
    }
    load_from_file(file_name);

}


//Destructor
//Task:
//Input: 
//Output:
Hash_table::~Hash_table()
{
    if(table_array)
    {
        for(int i = 0; i < table_size; ++i)
        {
            if(table_array[i])
            {
                delete_chain(table_array[i]);
                
            }
        }
        delete [] table_array;
        table_array = NULL;
    }
}



//Task:
//Input: 
//Output:
void Hash_table::load_from_file(const char * file_name)
{
    int index = 0; 
    char login_id[100];
    Node * to_add = NULL;

    //cout << file_name;
    ifstream file_in;
    file_in.open(file_name);
    
    //cout << endl << "Opened the file" << endl;    
    file_in.get(login_id, 10000, '\n');
    file_in.ignore(10000,'\n');

    //cout << endl << "Retrieved " << login_id << endl;

    while(file_in && !file_in.eof())
    {
        index = hash_function(login_id);
        to_add = new Credential(login_id);
     
        insert(table_array[index], to_add);
    
        file_in.get(login_id, 10000,  '\n');
        file_in.ignore(10000,'\n');
    }



    //std::cout << std::endl << login_id << std::endl;

}



//Task:
//Input: 
//Output:
void Hash_table::insert(Node *& head, Node * to_add)
{
    /*
    to_add->next_Node(head);
    head->next_Node(to_add);
    return;*/

    
    if(!head)
    {
        head = to_add;
        to_add->next_node(NULL);
        return;
    }

    if(0 < strcmp(head->get_key_value(),to_add->get_key_value()))
    {
            return insert(head->next_node(), to_add);
    }

    to_add->next_node(head);
    head = to_add;
    return;
    
}



//Task:
//Input: 
//Output:
bool Hash_table::validate(const char * login_id)
{
    int index = 0;
    index = hash_function(login_id);
    return validate(table_array[index], login_id); 
}


//Task:
//Input: 
//Output:
bool Hash_table::validate(Node * head, const char * login_id)
{
    if(!head)
    {   
        cout << endl << login_id << " not found." << endl;
        return false;
    }
    
    if(!strcmp(head->get_key_value(), login_id))
    {
        return true;
    }

    return validate(head->next_node(), login_id);
}


//Task:
//Input: 
//Output:
int Hash_table::hash_function(const char * to_hash)
{
    int index = 1;
    for(int i = 0; i < 9; ++i)
    {
        index += to_hash[i];
    }


    return index % table_size;
}


//Task:
//Input: 
//Output:
void Hash_table::delete_chain(Node *& head)
{
    if(!head)
        return;
    delete_chain(head->next_node());
    delete head;
    head = NULL;
    return;
}
