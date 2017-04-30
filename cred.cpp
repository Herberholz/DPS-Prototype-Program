/* DPS_Cred.cpp */

/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "cred.h"



Credential::Credential(void): user_id{'\0'} {}

Credential::Credential(char * number_id) : Node()
{
    user_id = new char[strlen(number_id) + 1];
    strcpy(user_id, number_id);

    key_value = user_id;


}

Credential::~Credential(void)
{
    if(user_id)
    {
        delete [] user_id;
        user_id = NULL;
        key_value = NULL;
    }
}

void Credential::display(void){}
void Credential::get_info(void){}

void Credential::load_from_file(ifstream &){}
void Credential::save_to_file(ofstream &){}

/*
void Credential::load_from_file(Node *&, ifstream &){}
void Credential::save_to_file(Node *&, ifstream &){}
*/



