/* DPS_ClientUI.h */

/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "userMenus.h"



//Class: derived from Virtual Base Class
class UI_ChocAnDPS
{
    public:
        UI_ChocAnDPS();
        ~UI_ChocAnDPS();

        /* For security, only two public functions.  */
        void start(void);
        void clear_screen(void);

    private:

        char menu(void);
        bool verification(const char * login_id, const char * role);
        bool user_login(char * login_id);        

        Hash_table * hash_ptr;
        Base_UI * pointer;
         
};

