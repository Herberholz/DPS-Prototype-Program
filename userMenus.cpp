/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "userMenus.h"



/***********************************************/
/*   Abstract Base_UI Class Implementation     */
/***********************************************/

//Constructor
Base_UI::Base_UI(void)    {}

//Destructor: Virtual
Base_UI::~Base_UI(void)   {}

//Start Function: Virtual
void Base_UI::start(void) {}



//Task:
//Input: 
//Output:
void Base_UI::clear_screen(void)
{
    for(int i = 0; i < 100; ++i)
        cout << endl;
    return;
}




/***********************************************/
/*      Provider_UI Class Implementation       */
/***********************************************/

//Constructor
Provider_UI::Provider_UI(void): mem_code{'\0'},service_code{'\0'},service_name{'\0'},date{'\0'},comments{'\0'},consultations(0),total_fees(0) 
{}

//2nd constructor
Provider_UI::Provider_UI(char * file_name)
{
	char file[40] = "Records/Providers/";
	strcat(file, file_name);
	strcat(file, ".txt");
	info = new Basic_Info(file);
	head = NULL;
	consultations = total_fees = 0;
}

//Destructor
Provider_UI::~Provider_UI(void)
{
	if(info)
		delete info;
	if(service_name)
		delete [] service_name;
	if(comments)
		delete [] comments;
}



//Task:
//Input:
//Output:
void Provider_UI::start(void)
{
    cout << "\t\t\t\t\t\t\tYour are in the Provider Interface" << endl;
    char response;
    
    do
    {
        response = menu();

        switch(response)
        {
            case '1':{ //checking in a member                   
                        member_validation();      
                        break;
                     }
            /*case '2':{ //checking out a member (also updating reports)
                        member_billing();
                        break;
                     }*/
            case '2':{ //displays their providers weekly report
                        provider_report();
                        break;
                     }
            case '3':{ //displays the provider directory
                        provider_directory();
                        break;
                     }
	    case '4':{ //displays their own basic info
			display_info();
			break;
		     }
            case '5':    cout << "\t\t\t\t\t\t\tCase 5... Quitting." << endl; break;
                 
            default: response = '\0';
        }

    }while(response != '5');
    clear_screen();
    return;


}

//Task:
//Input:
//Output:
char Provider_UI::menu(void)
{
    char response[2];

    //clear_screen();
    cout<<"\t\t\t\t\t\t  ChocolateChocolateChocolateChocolateChocolate"<<endl;
    cout << "\t\t\t\t\t\t(\tPlease select option by number: " << endl
         << "\t\t\t\t\t\t(\t1.) Member Validation" << endl
         << "\t\t\t\t\t\t(\t2.) Provider Report" << endl
         << "\t\t\t\t\t\t(\t3.) Provider Directory" << endl
	     << "\t\t\t\t\t\t(\t4.) Basic Information" << endl
         << "\t\t\t\t\t\t(\t5.) Quit" << endl;
    cout<<"\t\t\t\t\t\t  ChocolateChocolateChocolateChocolateChocolate"<<endl;

    cin.get(response, 100, '\n');
    cin.ignore(100, '\n');
    if(response[1] != '\0')
        return '\0';
    return response[0];


}

//Task: This function will display their own provider report
//Input: none
//Output: display
void Provider_UI::provider_report(void)
{
	char temp[25];
	char location[60] = "Reports/Provider/";
	int length;
	ifstream file_in; //for getting the provider report
	
	clear_screen();
	info->get_name(temp); //saves the prov name
	//replaces any space w/in the prov name with a _
	length = strlen(temp);
	for(int i=0; i<length;++i)
	{
		if(temp[i] == ' ')
			temp[i] = '_';
	}


	strcat(location, temp);
	strcat(location, "Current.txt");

	//naming will be provider_nameCurrent.txt
	file_in.open(location);

	if(!file_in)
	{
		cout << "\nSorry, there is no Provider Report for this week yet\n\n\n";
		return;
	}

	file_in.get(temp, 25, '\n'); file_in.ignore();
	cout << "\nName: " << temp;
	file_in.get(temp, 10, '\n'); file_in.ignore();
	cout << "\nCode: " << temp;
	file_in.get(temp, 25, '\n'); file_in.ignore();
    cout << "\nAddress: " << temp;
	file_in.get(temp, 15, '\n'); file_in.ignore();
    cout << "\nCity: " << temp;
    file_in.get(temp, 3, '\n'); file_in.ignore();
    cout << "\nState: " << temp;
    file_in.get(temp, 6, '\n'); file_in.ignore();
    cout << "\nZip Code: " << temp;
	file_in.get(temp, 5, '\n'); file_in.ignore();
    cout << "\nNumber of Consultations: " << temp;
    file_in.get(temp, 6, '\n'); file_in.ignore();
    cout << "\nTotal fees: " << temp;
	cout << "\nLog of Consultations:\n";
    while(!file_in.eof())
    {
        file_in.get(temp, 11, ';'); file_in.ignore(); //10 digits for date
        if(!temp[0] || temp[0] == ' ') //checks to make sure its not empty
            return;
	cout << "\nService Date: " << temp;

	file_in.get(temp, 20, ';'); file_in.ignore(); //10 digits for date, 10 for time
       	cout << "\nDate Logged: " << temp;
	file_in.get(temp, 25, ';'); file_in.ignore();
	cout << "\nMember Name: " << temp;
	file_in.get(temp, 10, ';'); file_in.ignore();
	cout << "\nMember Code: " << temp;
	file_in.get(temp, 7, ';'); file_in.ignore();
	cout << "\nService Code: " << temp;
	file_in.get(temp, 7, '\n'); file_in.ignore();
	cout << "\nFee to be Paid: " << temp << endl;
   }

    return;
}

//Task: This displays the contents of the PD - name,cost, and code
//for the Provider or Manager
//Input: N/A
//Output: 
void Provider_UI::provider_directory(void)
{
	ifstream file_in; //to read in from PD
	char temp[25]; //temp for displaying the info

	clear_screen();
	cout << "Provider Directory:" << endl; 
	file_in.open("Records/ProviderDirectory.txt");

	//if its empty
	if(file_in.eof())
		cout << "\nSorry, nothing in this file.\n";

	//displays contents of the file
	while(file_in && !file_in.eof())
	{
		file_in.get(temp, 25, ';'); file_in.ignore();
		if(!temp[0] || temp[0] == ' ') //checks to make sure its not empty
			return;
		cout << "\nService Name: " << temp;
		
		file_in.get( temp, 7, ';'); file_in.ignore();
		cout << "\nService Fee: " << temp;
	
		file_in.get(temp, 7, ';'); file_in.ignore();
		cout << "\nService Code: " << temp << endl;

	}

	file_in.close();

    return;
}

//Task: This function displays the basic info within the provider class of the provider
//Input: none
//Output: the display
void Provider_UI::display_info(void)
{
	clear_screen();
	if(!info->display())
		cout << "\nSorry, you have no records with ChocAn.\n";
	return;
}

//This function takes the member code entered and makes sure that it
//is a real member
int Provider_UI::verify_member()
{
	char code[10];
	char again;
	ifstream file_in;

	file_in.open("Codes/Member.txt");

	while(!file_in.eof())
	{
		file_in.get(code, 10, '\n'); 
                file_in.ignore(1000, '\n');
		if(strcmp(code, mem_code)==0)
			return 1;
	}

	cout << "\nSorry, that is not a valid member number. Would you like to try again? (Y or N): ";
	cin >> again;
	cin.ignore(100, '\n');
	again = toupper(again);

	if(again == 'Y')
		return 0;

	return 3;
}

void Provider_UI::get_service()
{
	char again = 'Y';
 do{
	provider_directory(); //displays the PD for then to see what they need to enter
	cout << "\nPlease enter the corresponding code to the service provided: ";
	cin >> service_code;
	cin.ignore(100, '\n');
	while(!search_PD()) //searches to make sure it's a valid code
	{
		cout << "\nThat is not a valid code. Please try again.";
		cout << "\nPlease enter the corresponding code to the service provided: ";
		cin >> service_code;
		cin.ignore(100, '\n');
	}

	//verifies to make sure it is correct
	cout << "\nService Name: " << service_name << "\nIs this correct? (Y or N): ";
	cin >> again;
	cin.ignore(100, '\n');
	again = toupper(again);
	cout << "\nHere are the fees for that service: $" << fee;

  } while(again != 'Y'); //loop until correct
  
}

//Task: The provider checks in a member here, gets all the appropriate info and then
// verifies with them that it can be committed/written out to disk
//Input:
//Output:
void Provider_UI::member_validation(void)
{
	char temp[101];
	int verify;
	clear_screen();

	//initial check in of member
    do{
	cout << "\nPlease enter in Member ID: ";
	cin.get(mem_code, 10, '\n');
	cin.ignore(100, '\n');

	verify = verify_member();
	if(verify == 3)
	{
		clear_screen();
		return;
	}
   
    }while(!verify);

	get_service();
	
	//gets additional info that is stored to be written to certain files
	cout << "\nPlease enter the date in the format MM/DD/YYYY: ";
	cin >> date;
	cin.ignore(100, '\n');

   
	cout << "\nPlease enter additional comments about the visit: ";
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	comments = new char[strlen(temp)+1];
	strcpy(comments, temp);

	cout << "\nThese changes are now going to be committed\n";

	//THIS IS THE POINT WHERE FUNCTIONS NEED TO BE WRITTEN TO WRITE APPROPRAITE INFO OUT TO FILES
	change_EFT();
	//change_MR();
	//change_PR();	
		
	//clear_screen();
	return;
}


//This function writes the appropraite data out to the correct EFT file
void Provider_UI::change_EFT()
{
	char location[60] = "Reports/EFT/";
	char temp[25];
	char names[25];
	int dollars = 0;
	ifstream file_in;
	ofstream file_out;
	
	//gets the complete file path - Reports/Provider/<ID#>EFT.txt
	info->get_ID(temp);
	strcat(location, temp);
	strcat(location, "EFT.txt");
	//goes to that place and if there is not one, creates a new one.
	file_in.open(location);
	file_out.open(location);
	if(!file_in) //if there isn't one there, creates one
	{
		cout << "\nCreating new EFT.... " << location;
		info->get_name(names); //gets the name of the provider frmo basic info
		//writes out to file
		file_out << names << ';' << temp << ';' << fee << '\n';
	}
	else //if there is one, need to increment $
	{
		cout << "\nAppending to EFT..... " << location;
		file_in.get(names, 25, ';'); file_in.ignore();
	//	info->get_name(names);
		cout << "\nName: " << names;
		file_in.get(temp, 10, ';'); file_in.ignore();
	//	info->get_ID(temp);
		cout << "\nCode: " << temp;
		file_in >>  dollars; file_in.ignore();
		cout << "\nDollars: " << dollars;
	
		dollars += fee;
		file_out << names << ';' << temp << ';' << dollars << '\n';
	}

	file_in.close();
	file_out.close();
}

//This functionwrotes the appropraite data out to the Provider Report
void Provider_UI::change_PR()
{
	char location[40] = "Reports/Provider/";
	char loc[40] = "Records/Members/";
	char temp[25];
	char names[25];
	char mcode[10];
	char scode[7];
	int length;
	Basic_Info * member;
	ifstream file_in;
	ifstream file;
	ofstream file_out;

	info->get_name(temp);
	length = strlen(temp);
	 for(int i=0; i<length;++i)
        {
                if(temp[i] == ' ')
                        temp[i] = '_';
        }

        strcat(location, temp);
        strcat(location, "Current.txt");

	strcat(loc, mem_code);
        strcat(loc, ".txt");
        member = new Basic_Info(loc);

        member->get_name(temp); //copies over member name
        //goes to that place and if there is not one, creates a new one.
        file_in.open(location);
        if(!file_in) //if there isn't one there, creates one
	{
		total_fees = fee;
		cout << "\nCreating new PR..... " << location << endl;
		info->write_out(location, 1, total_fees); //writes out the basic info to start with
        	file_out.open(location, ios::app);
		//now the fields of each log entry are written out. Only 1 now through
		file_out << date << ';' << date << ';'
			 << temp << ';' //writes out the member's name
			 << mem_code << ';' //writes out their code
			 << service_code << ';' //writes out service code
			 << total_fees << '\n'; //only 1 service now so adds fee
	}
	else
	{
		cout << "\nPR exists.... " << location << endl;
		//first gets the basic info out
		file_in.get(temp, 25, '\n'); file_in.ignore();
		file_in.get(temp, 10, '\n'); file_in.ignore();
		file_in.get(temp, 25, '\n'); file_in.ignore();
		file_in.get(temp, 25, '\n'); file_in.ignore();
		file_in.get(temp, 25, '\n'); file_in.ignore();
		file_in.get(temp, 25, '\n'); file_in.ignore();
		file_in >> consultations; file_in.ignore();
		file_in >> total_fees; file_in.ignore();
		
		//reads the log of the consultations in
		while(!file_in.eof())
		{
			cout << "\nGoing through the loop";
			//reads in each data member, stores it in a temp
			//& then keeps those in a LLL for each one
			file_in.get(temp, 11, ';'); file_in.ignore();
			if(!temp[0] || temp[0] == ' ') //checks to make sure its not empty
				break;
			cout << "\nMade it past the check";
			file_in.get(temp, 11, ';'); file_in.ignore();
			file_in.get(names, 25, ';'); file_in.ignore();
			file_in.get(mcode, 10, ';'); file_in.ignore();
			file_in.get(scode, 7, ';'); file_in.ignore();
			file_in >> length; file_in.ignore();
			cout << "\nGoing to store: " << names<< temp<< ' '<< mcode<< ' '<< scode<< ' '<< length;
			store_log(names, temp, mcode, scode, length); //adds a new node to the list
		}
		if(!temp[0] || temp[0] == ' ')
		{
		++consultations;
		total_fees += fee;
		info->write_out(location, consultations, total_fees);
		file_out.open(location, ios::app);
		//file_out << consultations << '\n' << total_fees << '\n';
		//HERE WE WRITE OUT THE CONSULTATIONS READ IN
		write_out(head, location); //will go through the list of services stored and write them out
		//here the new info is added to the end
		member->get_name(names);
		file_out << date << ';' << date << ';'
			 << names  << ';' << mem_code << ';'
			 << service_code << ';' << fee<< '\n';
		}
      }
	remove_list(head);
	head = NULL;
	file_in.close();
	file_out.close();
}

void Provider_UI::remove_list(Provider_report * head)
{
	if(!head)
		return;

	remove_list(head->get_next());

	delete head;
	head = NULL;
}


//This function recursively goes through the logs and write them out
void Provider_UI::write_out(Provider_report * head, char * file_name)
{
	if(!head)
		return;

	head->write_out(file_name);
	
	write_out(head->get_next(), file_name);

	return;
}

//This function takes in all of the correct info from
void Provider_UI::store_log(char * name, char * dates, char * mcode, char * scode, int amount)
{
	Provider_report * current = head;
	//if there is not list
	if(!head)
	{
		head = new Provider_report(name, dates, mcode, scode, amount);
	}
	else
	{
		while(current->get_next())
			current = current->get_next();
		current->get_next() = new Provider_report(name, dates, mcode, scode, amount);
	}
}

//This function writes appropraite info to Member Report
void Provider_UI::change_MR()
{
	char location[40] = "Reports/Member/";
	char loc[40] = "Records/Members/";
	char temp[25];
	char prov[25];
	int length;
	Basic_Info * member;
	ifstream file_in;
	ofstream file_out;
	
	strcat(loc, mem_code);
	strcat(loc, ".txt");
	member = new Basic_Info(loc);
	
	member->get_name(temp); //copies over member name
	length = strlen(temp);
        for(int i=0; i<length;++i)
        {
                if(temp[i] == ' ')
                        temp[i] = '_';
        }
	strcat(location, temp);
	strcat(location, "Current.txt");
	info->get_name(prov);
	file_in.open(location);
	if(!file_in) //if there is not a Member Report for that member, make one
	{
		//write out the basic info first
		member->write_out(location);
		//then write out the log part
		file_out.open(location, ios::app);
		file_out << '\n' << service_name << '\n' << prov << '\n' << date;
	}
	else
	{
		file_out.open(location, ios::app);
		file_out << '\n' << service_name << '\n' << prov << '\n' << date;
	}

	file_in.close();
	file_out.close();

	delete member;
}

//Task: This function goes through the PD to make sure that the service code entered was a valid one
//INPUT: none
//OUTPUT: True if a match, false if no match
int Provider_UI::search_PD()
{
	char names[25];
	char temp[7];
	int fees;
	ifstream file_in;

	file_in.open("Records/ProviderDirectory.txt");

        if(file_in.eof())
                cout << "\nSorry, nothing in this file.\n";

        //displays contents of the file
        while(!file_in.eof())
        {
                file_in.get(names, 25, ';'); file_in.ignore(); //service name

                file_in >> fees; file_in.ignore(); //fee

                file_in.get(temp, 7, ';'); file_in.ignore(); //service code
		if(strcmp(temp, service_code)==0) //if they match
		{
			//saves the service name
			service_name = new char[strlen(names)+1];
			strcpy(service_name, names);
			fee = fees; //saves the fee for that one service
			file_in.close();
			return 1;	
		}
        }

        file_in.close();

	return 0;
}


/***********************************************/
/*      Manager_UI Class Implementation       */
/***********************************************/

//Constructor
Manager_UI::Manager_UI(void)  {}

//Destructor
Manager_UI::~Manager_UI(void) {}



//Task:
//Input:
//Output:
void Manager_UI::start(void)
{
    cout << "You are in the Manager Interface" << endl;
    char response;
    
    do
    {
        response = main_menu();

        switch(response)
        {
            case '1':{                    
                        start_report(); 
                        break;
                     }
            case '2':{
                        edit_members();
                        break;
                     }
            case '3':{
                        edit_providers();
                        break;
                     }
            case '4':   cout << "Case 5... Quitting." << endl; break;
                 
            default: response = '\0';
        }

    }while(response != '4');
    return;


    
}
        
//Task:
//Input:
//Output:
char Manager_UI::main_menu(void)
{
    
    char response[2];

//    clear_screen();
    cout << "Please select option by number: " << endl
         << "1.) Report Menu" << endl
         << "2.) Add/Edit/Remove Members" << endl
         << "3.) Add/Edit/Remove Providers" << endl
         << "4.) Quit" << endl;

    cin.get(response, 100, '\n');
    cin.ignore(100, '\n');
    if(response[1] != '\0')
        return '\0';
    return response[0];


}

//Task:
//Input:
//Output:
char Manager_UI::report_menu(void)
{
    char response[2];

//    clear_screen();
    cout << "Please select option by number: " << endl
         << "1.) EFT Report" << endl
         << "2.) Member Reports" << endl
         << "3.) Provider Reports" << endl
         << "4.) Quit" << endl;

    cin.get(response, 100, '\n');
    cin.ignore(100, '\n');
    if(response[1] != '\0')
        return '\0';
    return response[0];
}

//Task:
//Input:
//Output:
void Manager_UI::start_report(void)
{
    cout << "You are in the Report section" << endl;
    char response;
    
    do
    {
        response = report_menu();

        switch(response)
        {
            case '1':{                    
                        cout << "EFT Reports will go here." << endl;
                        break;
                     }
            case '2':{
                        cout << "Member Reports will go here." << endl;
                        break;
                     }
            case '3':{
                        cout << "Provider Reports will go here." << endl;
                        break;
                     }
            case '4':   cout << "Case 4... Quitting." << endl; break;
                 
            default: response = '\0';
        }

    }while(response != '4');
    return;

}

//Task:
//Input:
//Output:
void Manager_UI::edit_members(void)
{
    char response[2];
    
    do
    {
    
        //clear_screen();
        cout << "Please select option by number: " << endl
        << "1.) Edit member" << endl
        << "2.) Add member" << endl
        << "3.) Remove member" << endl
        << "4.) Quit" << endl;

        cin.get(response, 2, '\n');
        cin.ignore(100, '\n');
    
        if(response[1] != '\0')
            continue; //return edit_members();
    

        switch(response[0])
        {
            case '1':{                    
                        cout << "Update member file." << endl;
                        update_members();           
                        break;
                     }
            case '2':{
                        cout << "Add member file." << endl;
                        
                        break;
                     }
            case '3':{
                        cout << "Remove member.." << endl;
                        
                        break;
                     }
            case '4':{
                        cout << "Case 4... Quitting." << endl; 
                        break;
                     }
            default: response[0] ='\0';
        }

    }while(response[0] != '4');
    
    return;
}

//Task:
//Input:
//Output:
void Manager_UI::update_members(void)
{
    char ID[14], location[35] = "Records/Members/";

    ifstream fin;
    
    cout << "Enter member ID number" << endl;
    cin.get(ID, 10, '\n');// 10 characters to limit the code givin for file IO
    cin.ignore(100, '\n');
    
    if( verify_members(ID) )
    {
        strcat(ID, ".txt");
        strcat(location, ID);
        fin.open(location);
        
        Basic_Info member(location); //Creating a temp member to write to file.
        cout << "Current member information: " << endl;
        member.display();
        
        member.update_profile();
        cout << "Member information updated: " << endl;
        member.display();
    
        member.write_out(location);
    }
}


//Task:
void Manager_UI::add_member(void)
{


}

//Task:
int Manager_UI::verify_members(char ID[])
{
	char code[10];
	ifstream file_in;

	file_in.open("Codes/Member.txt");
        
	while( !file_in.eof() )
	{
		file_in.get(code, 10, '\n'); 
                file_in.ignore(1000, '\n');
		
                if( strcmp(code, ID) == 0 )
		    return 1;
	}

	cout << "\nSorry, that is not a valid member number. Please try again.\n";
	return 0;
}


//Task:
//Input:
//Output:
void Manager_UI::edit_providers(void)
{
    cout << "Edit Providers will go here." << endl;
    char response[2];
    
    do
    {
    
        clear_screen();
        cout << "Please select option by number: " << endl
        << "1.) Edit provider" << endl
        << "2.) Add provider" << endl
        << "3.) Remove provider" << endl
        << "4.) Quit" << endl;

        cin.get(response, 2, '\n');
        cin.ignore(100, '\n');
    
        if(response[1] != '\0')
            continue; //return edit_members();
    

        switch(response[0])
        {
            case '1':{                    
                        cout << "Update provider file." << endl;
                        update_providers();           
                        break;
                     }
            case '2':{
                        cout << "Add provider file." << endl;
                        add_provider();                       
                        break;
                     }
            case '3':{
                        cout << "Remove provider.." << endl;
                        
                        break;
                     }
            case '4':{
                        cout << "Case 4... Quitting." << endl; 
                        
                        break;
                     }
            default: response[0] ='\0';
        }
    }while(response[0] != '4');
    
    return;
}


//Task:
//Input:
//Output:
void Manager_UI::update_providers(void)
{
    char ID[14], location[35] = "Records/Providers/";

    ifstream fin;
    
    cout << "Enter provider ID number" << endl;
    cin.get(ID, 10, '\n');// 10 characters to limit the code givin for file IO
    cin.ignore(100, '\n');
    
    if( verify_providers(ID) )
    {
        strcat(ID, ".txt");
        strcat(location, ID);
        fin.open(location);
        
        if( fin.eof() )
            cout << "Test: Error in opening file." << endl;
       
        Basic_Info provider(location);
        provider.display();
        provider.update_profile();
        provider.display();
        provider.write_out(location);
        fin.close();
    }
    
}



int Manager_UI::verify_providers(char ID[])
{
    char code[10];
	ifstream file_in;

	file_in.open("Codes/Provider.txt");
        
	while( !file_in.eof() )
	{
		file_in.get(code, 10, '\n'); 
        file_in.ignore(1000, '\n');
		if(strcmp(code, ID)==0)
                file_in.ignore(100, '\n');
		
        if( strcmp(code, ID) == 0 )
                return 1;
	}

	cout << "\nSorry, that is not a valid provider number. Please try again.\n";
	return 0;
}

void Manager_UI::add_provider(void)
{
    Basic_Info new_provider;


    


}

/*
//Task:
//Input:
//Output:
void Manager_UI::edit_provider_directory(void)
{
    cout << "Edit Provider Directory will go here." << endl;
    
    return;
}
*/
