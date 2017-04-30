/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "profiles.h"



//Constructor
Basic_Info::Basic_Info(): name{'\0'}, code{'\0'}, street_address{'\0'}, city{'\0'}, state{'\0'}, zip_code{'\0'} 
{}

//Constructor
Basic_Info::Basic_Info(char * file_name)
{
	//needs to read in from the provider file & store values
	ifstream file_in;
	char temp[26];

	
	file_in.open(file_name);
	
	//gets the name
	file_in.get(temp, 25, '\n'); 
        file_in.ignore(100, '\n');
	name = new char[strlen(temp)+1];
	strcpy(name, temp);
	
	//copies over the code
	file_in.get(temp,10, '\n'); 
        file_in.ignore(100, '\n');
	code = new char[10];
	strcpy(code, temp);

	//gets the street address
	file_in.get(temp, 26, '\n'); 
        file_in.ignore(100, '\n');
	street_address = new char[strlen(temp)+1];
	strcpy(street_address, temp);

	//gets the city
	file_in.get(temp, 15, '\n'); 
        file_in.ignore(100, '\n');
	city = new char[strlen(temp)+1];
	strcpy(city, temp);

	//gets the state
	file_in.get(temp, 3, '\n'); 
        file_in.ignore(100, '\n');
	state = new char[3];
	strcpy(state, temp);

	//gets the zip code
	file_in.get(temp, 6, '\n'); 
        file_in.ignore(100, '\n');
	zip_code = new char[6];
	strcpy(zip_code, temp);

	file_in.close();

}

//Destructor
Basic_Info::~Basic_Info() 
{
	if(name)
	{
		delete [] name;
                name = NULL;
        }
        if(code)
        {
                delete [] code;
                code = NULL;
        }
        if(street_address)
    	{
		delete [] street_address;
                street_address = NULL;
        }
        if(city)
        {
                delete [] city;
                city = NULL;
        }
        if(state)
        {
            delete [] state;
            state = NULL;
        }
        if(zip_code)
        {
            delete [] zip_code;
            zip_code = NULL;
        }

}


//This is a getter for the name of the prov/mem
void Basic_Info::get_name(char prov_name[])
{
	strcpy(prov_name, name);
}

//This function gets the code of the prov/mem
void Basic_Info::get_ID(char temp[])
{
	strcpy(temp, code);
}

//This function takes in the write out var from other func then it can write out
void Basic_Info::write_out(char file_name[], int consultations, int fees)
{
	ofstream file_out;
	file_out.open(file_name);

	file_out << name << '\n' << code << '\n' << street_address << '\n'
		 << city << '\n' << state << '\n' << zip_code << '\n';
	file_out << consultations << '\n' <<fees << '\n';
        file_out.close();
}
//This function takes in the write out var from other func then it can write out
void Basic_Info::write_out(char file_name[])
{
	ofstream file_out;
	file_out.open(file_name);

	file_out << name << '\n' << code << '\n' << street_address << '\n'
		 << city << '\n' << state << '\n' << zip_code << '\n';
        file_out.close();
}


//Task:
//Input:
//Output:
void Basic_Info::update_profile() 
{
    
    char response[2];
    char temp[100];
    
    do
    {
    
        //clear_screen();
        cout << "Please select option by number: " << endl
        << "1.) Change member name" << endl
        << "2.) Member street address" << endl
        << "3.) Member city" << endl
        << "4.) Member state" << endl
        << "5.) Member zip_code" << endl
        << "6.) Quit" << endl;

        cin.get(response, 2, '\n');
        cin.ignore(100, '\n');
    
        if(response[1] != '\0')
            continue;     

        switch(response[0])
        {
            case '1':{                    
                        cout << "Update name to new name here:" << endl;
                        if(name)
                            delete [] name;

                        cin.get(temp, 100, '\n');
                        cin.ignore(100, '\n');
                        name = new char[strlen(temp) + 1];
                        strcpy(name, temp);

                        break;
                     }
            case '2':{
                        cout << "What is the new street address:" << endl;
                        if(street_address)
                            delete [] street_address;
                        
                        cin.get(temp, 100, '\n');
                        cin.ignore(100, '\n');
                        street_address = new char[strlen(temp) + 1];
                        strcpy(street_address, temp);

                        break;
                     }
            case '3':{
                        cout << "What is the new city:" << endl;
                        if(city)
                            delete [] city;
                        
                        cin.get(temp, 100, '\n');
                        cin.ignore(100, '\n');
                        city = new char[strlen(temp) + 1];
                        strcpy(city, temp);
                        
                        break;
                     }
            case '4':{
                        cout << "What is the new state:" << endl; 
                        if(state)
                            delete [] state;
                        
                        cin.get(temp, 100, '\n');
                        cin.ignore(100, '\n');
                        state = new char[strlen(temp) + 1];
                        strcpy(state, temp);
                        
                        break;
                     }
            case '5':{
                        cout << "What is the new zip_code:" << endl;
                        if(zip_code)
                            delete [] zip_code;
                        
                        cin.get(temp, 100, '\n');
                        cin.ignore(100, '\n');
                        zip_code = new char[strlen(temp) + 1];
                        strcpy(zip_code, temp);
                        
                        break;
                     }
            case '6':{
                         cout <<"Quitting... " << endl;

                         break;
                     }
            default: response[0] ='\0';
        }

    }while(response[0] != '6');
    
    return;
}


//Task:
//Input:
//Output:
void Basic_Info::remove_profile() {}



//Task:This function displays the info stored
//Input:
//Output:
int Basic_Info::display()
{
	if(!name[0])
		return 0;

    cout<<"\t\t\t\t\t\t  ChocolateChocolateChocolateChocolateChocolate"<<endl;
	cout << "\t\t\t\t\t\t(\tName: " << name << "\t\t)" << endl
	     << "\nCode: " << code << "\t\t)" << endl
 	     << "\nAddress: " << street_address << "\t\t)" << endl
	     << "\nCity: " << city <<"\t\t)" << endl
	     << "\nState: " << state << "\t\t)" << endl
	     << "\nZip Code: " << zip_code << "\t\t)" << endl;  
    cout<<"\n\n\t\t\t\t\t\t\t\t\t";
	cout << "Name: " << name << endl
	     << "\nCode: " << code << endl
 	     << "\nAddress: " << street_address  << endl
	     << "\nCity: " << city << endl
	     << "\nState: " << state << endl
	     << "\nZip Code: " << zip_code << endl;  

	return 1;
}

/***************************************************************************/
/*
//Constructor
Provider::Provider(): service_code{'\0'}, service_name{'\0'}, date{'\0'}, comments{'\0'} 
{}

//Destructor
Provider::~Provider() {}



//Task:
//Input:
//Output:
void Provider::display()
{
    cout << "*****Provider Info*****" << endl;
    info.display();
    cout << "Service Code: " << service_code 
         << "\nService Name: " << service_name
         << "\nDate: " << date
         << "\nComments: " << comments << endl;

}*/

/****************************************************************************/

//Constructor
Member::Member(): service_code{'\0'}, service_name{'\0'}, date{'\0'}, comments{'\0'}
{}

//Destructor
Member::~Member()
{}

//Task:
//Input:
//Output:
void Member::display()
{
    cout << "*****Member Info*****" << endl;
    info.display();
    cout << "Service Code: " << service_code 
         << "\nService Name: " << service_name
         << "\nDate: " << date
         << "\nComments: " << comments << endl;

}
