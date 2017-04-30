/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "reports.h"
#include <cstdlib>


//This class is used to add/remove/update members/providers
class Basic_Info
{
    public:
        Basic_Info(void);
        Basic_Info(char * file_name);
        ~Basic_Info(void);
	        
        void update_profile(void); //update/add mem/providers
        void remove_profile(void); //remove members/providers
        int display(void);
	void get_name(char *mem_code); //gets the mem/prv name
	void get_ID(char temp[]); //gets the  mem/prov code

	void write_out(char file_name[], int, int); //will write out basic info to a file
	void write_out(char file_name[]); //will write out basic info to a file
    private:
        char * name;
        char * code;
        char * street_address;
        char * city;
        char * state;
        char * zip_code;

};


/* I commented this out because it is just repeating what is in Provider_UI
	so there is no point for this class
//Purpose:
class Provider : public Node 
{
    public:
        Provider(void);
        ~Provider(void);
        void display();
    

    private:
        Basic_Info info; //instance of this provider's info to display
        char service_code[7];
        char service_name[26];
        char date[11]; //date input in form MM/DD/YYYY
        char comments[101]; //additional comments the provider may have
	
};
*/


//Purpose:
class Member : public Node 
{
    public:
        Member(void);
        ~Member(void);
        void display();
    

    private:
        Basic_Info info; //instance of this provider's info to display
        char service_code[7];
        char service_name[26];
        char date[11]; //date input in form MM/DD/YYYY
        char comments[101]; //additional comments the provider may have
	
};
