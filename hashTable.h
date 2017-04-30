/* DPS_HashTable.h */

/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "cred.h"

const int TABLE_SIZE = 17;



//Purpose:
class Hash_table
{
    public:
        Hash_table();
        Hash_table(const char * file_name);
        ~Hash_table();
        
        bool validate(const char * login_id);

    private:
        bool validate(Node * head, const char * login_id);
        void load_from_file(const char * file_name);
        int hash_function(const char * to_hash);
        void delete_chain(Node *&);        
        void insert(Node *& head, Node * to_add);

        Node ** table_array;
        int table_size;
};
