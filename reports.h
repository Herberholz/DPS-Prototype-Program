/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "node.h"



//Purpose:
class Receipt: public Node
{
    public:
        Receipt();
	Receipt(char*, char*, char*, char*, double); //used w/ fields for Prov UI PR
        ~Receipt();
        void get_info();
        void display();
        void load_file();
        void save_file();

    protected:
        char * curr_date_time;
        char * trans_date_time;
        char * provider_num;
        char * member_num;
        char * member_name;
        char * service_fee;
        char * service_code;
        char * comments;
        int members_helped;
        double total_weekly_fee;

};



//Purpose: Part of this class is to serve as a sort of node for storing 
//the information that is kept in a log for the PR. It needs to be stored
//in a LLL by date and then is written back out after some info is changes
class Provider_report
{
    public:
	Provider_report();
	Provider_report(char *, char *, char*, char*, int);
	Provider_report *& get_next();
	void write_out(char *file); //writes into out to PR file

    private: 
	Provider_report * next;
	char mem_code[10];
	char service_code[7];
	int fees;
	char date[11];
	char * name;
	
};
