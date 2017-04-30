/* DPS_Node.h */

/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;



//Purpose:
class Node
{
    public:
        Node();
        //Node(const char * file_name);
        virtual ~Node();
        
        char * get_key_value(void);

        void next_node(Node *);
        Node *& next_node(void);

        virtual void display(void) = 0;
        virtual void get_info(void) = 0;

        virtual void load_from_file(ifstream &) = 0;
        virtual void save_to_file(ofstream &) = 0;



    protected:
        void clear_screen();
        char * key_value;//value report is sorted by 
        Node * next;
};



//Purpose:
class List
{
    public:
        List();
        List(const char * file_to_load);
        ~List();
        void insert(Node *& to_add);
        void display_list();
        bool find(const char * to_find);
        bool remove(const char * to_remove);
        bool edit(const char * to_edit);
        void delete_list();

        void load_from_file(char * file_name);
        void save_to_file(char * file_name);

    private:
        char * file_name;
        Node * head;

        void insert(Node *& head, Node *& to_add);
        void display_list(Node * head);
        bool find(Node * head, const char * to_find);
        bool remove(Node *& head, const char * to_remove);
        bool edit(Node *& head, const char * to_edit);
        void delete_list(Node *& head);

        void load_from_file(Node *& head, Node *& to_load, ifstream &);
        void save_to_file(Node * head, ofstream &);
};
#endif
