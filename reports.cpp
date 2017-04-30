/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "reports.h"



Receipt::Receipt()
{
    curr_date_time = trans_date_time = provider_num = member_num =
        member_name = service_fee = service_code = comments  = NULL;
    next = NULL;
    members_helped = 0;
    total_weekly_fee = 0.0;

}


Receipt::~Receipt()
{
    if(curr_date_time)
        delete []curr_date_time;
    if(trans_date_time)
        delete []trans_date_time;
    if(provider_num)
        delete []provider_num;
    if(member_num)
        delete []member_num;
    if(member_name)
        delete []member_name;
    if(service_fee)
        delete []service_fee;
    if(service_code)
        delete []service_code;
    if(comments)
        delete []comments;
    members_helped =0;
    total_weekly_fee = 0.0;
} 
 

void Receipt::display()
{

}

void Receipt::get_info()
{

}

Provider_report::Provider_report()
{
	next = NULL;
	name = NULL;
}


Provider_report::Provider_report(char * names, char * dates, char * mcode, char * scode, int amount)
{
	//copies all of the info over
	strcpy(mem_code, mcode);
	strcpy(service_code, scode);
	strcpy(date, dates);
	fees = amount;
	name = new char[strlen(names)+1];
	strcpy(name, names);
	next = NULL;
	cout << "\nNow storing: " << date << name << mem_code << ' ' << service_code << ' ' << fees;
}
/*
Provider_report::~Provider_report()
{
	if(name)
		delete [] name;
	if(next)
		delete next;
}*/


Provider_report *& Provider_report::get_next()
{
	return next;
}

void Provider_report::write_out(char * file_name)
{
	ofstream file_out;

	file_out.open(file_name, ios::app); //append to end
	file_out << date << ';' << date << ';'
		 << name << ';' << mem_code << ';'
		 << service_code << ';' << fees << '\n';
	cout << "\nThe LLL just wrote out: " << date << name << mem_code << ' ' << service_code << ' ' << fees;
	file_out.close();
 	return;
}

