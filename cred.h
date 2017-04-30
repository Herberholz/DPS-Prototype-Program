/* DPS_Cred.h */

/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "node.h"



//Purpose:
class Credential: public Node
{
    public:
        Credential(void);
        Credential(char * number_id);
        ~Credential(void);

        void display(void);
        void get_info(void);

        void load_from_file(ifstream &);
        void save_to_file(ofstream &);


    private:
        //void load_from_file(Node *&, ifstream &);
        //void save_to_file(Node *&, ifstream &);

        char * user_id;
};

