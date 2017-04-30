/* DPS_UserMenus.h */

/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "hashTable.h"
#include "profiles.h"



//Purpose:
class Base_UI
{
    public:
        Base_UI(void);
        virtual ~Base_UI(void);
        virtual void start(void) = 0;

    protected:
        void clear_screen(void);  

};



/*This classes functions as the specific provider menu with its functions for each option
It also contains the data members necessary to save info to when loading in information
or saving it to write out to a file*/
class Provider_UI: public Base_UI
{
    public:
        Provider_UI(void);
        Provider_UI(char * file_name); //uses file name to then go and initialize basic info
        ~Provider_UI(void);

        void start(void); //top level menu that determin

    private:
        char menu(void); 
        void provider_report(void); //displays their own provider report
        void provider_directory(void); //displays the PD
        int search_PD(); //this searches the PD the make sure code entered is valid
        void display_info(void); //displays own provider basic info
        void member_validation(void); //check member in
        int verify_member(); //verifies that they are a real member
        void get_service(); //this just gets the service code for a member
        void change_EFT(); //appends correct info to EFT report
        void change_PR(); //updates provider report
        void change_MR(); //updates the member report
	    void store_log(char*, char*, char*, char*, int); //makes LLL to store log from PR
	    void write_out(Provider_report *, char*); //recursively writes out to PR
	    void remove_list(Provider_report*);
	    
        //datamembers
        Basic_Info * info; //instance of this provider's info to display
        class Provider_report * head; //this is used for a LLL when reading in from PR
	    char mem_code[10]; //used to look a member up
        char service_code[7];
        char * service_name;
        int fee;
        char date[11]; //date input in form MM/DD/YYYY
        char * comments; //additional comments the provider may have
        int consultations; //total # consultations
        int total_fees; //the total amount of fees form that week
};



//Purpose:
class Manager_UI: public Base_UI
{
    public:
        Manager_UI(void);
        ~Manager_UI(void);

        void start(void);

    private:

        char main_menu(void);
        char report_menu(void);
        void start_report(void);//entry to the report menu

        void edit_members(void);
        void update_members(void);
        void add_member(void);

        void edit_providers(void);//menu for editing providers
        void update_providers(void);//editing a provider 
        void add_provider(void); //adds provider to the system

        int verify_members(char ID[]);
        int verify_providers(char ID[]);// verify provider ID

        //void edit_provider_directory(void);

};
