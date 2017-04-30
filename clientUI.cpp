/* CS300.004 ChocAn DPS Prototype Program
   
   Israel Bond
   Brandon Craig
   Sender Escobar
   Marissa Hagglund
   Cody Herberholz 
   
   Spring 2016, Portland State University */

#include "clientUI.h"



//Constructor
UI_ChocAnDPS::UI_ChocAnDPS(): hash_ptr(0), pointer(0) {}

//Destructor
UI_ChocAnDPS::~UI_ChocAnDPS()
{
    if(pointer)
    {
        delete pointer;
        pointer = NULL;
    }
    if(hash_ptr)
    {
        delete hash_ptr;
        hash_ptr = NULL;
    }
}

//Task:
//Input:
//Output:
void UI_ChocAnDPS::clear_screen(void)
{
    for(int i = 0; i < 100; ++i)
        cout << endl;
    return;
}

//Task: This function takes in a static array to be filled with the 
//      manager/provider user login info. Verifies input. 
//Input: static array for login id, fills array from user input. 
//Output: return true/false based on string validity.
bool UI_ChocAnDPS::user_login(char * login_id)
{
   bool valid = true;

   clear_screen();
   cout << "Please enter your user ID: ";
   login_id[9] = 'a';
   cin.get(login_id, 11, '\n');
   cin.ignore(100000000, '\n');
   
   if(login_id[9] != '\0')
       return false;
  
   for(int i = 0; i < 9; ++i)
   {
        if(!isdigit(login_id[i]))
            valid = false;

   }
   return valid;
}



//Task:   This function provides a controlled flow which directs the user to 
//        the appropriate provider/manager menu 
//Input:  No Input
//Output: No Output
void UI_ChocAnDPS::start(void)
{
    char response;
    char login_id[10];
   
    do
    {
        response = menu();

        switch(response)
        {
            case '1':{ 
                         if(!user_login(login_id))
                            break;
                         
                         if(verification(login_id, "Codes/Provider.txt"))
                         {
                            pointer = new Provider_UI(login_id);
                            pointer->start();
                            //if(pointer)
                            //{
                            //    delete pointer;
                            //    pointer = NULL;
                            //}

                         } 
                         break;
                     }
            case '2':{
                         if(!user_login(login_id))
                             break;

                         if(verification(login_id, "Codes/Manager.txt"))
                         {
                            cout << "Case 2" << endl;
                            pointer = new Manager_UI;
                            pointer->start();
                            //if(pointer)
                            //{
                            //    delete pointer;
                            //    pointer = NULL;
                            //}

                         }
                         break;
                     }
            case '3':    cout << "Case 3... Quitting." << endl; break;
                     
            default: response = '\0';
        }

        if(pointer)
        {
            delete pointer;
            pointer = NULL;
        }

    }while(response != '3');
    
    return;
}


//Task:   Provides the user with a user interface that allows them to choose 
//        whether to login as a provider, manager, or exit
//Input:  No input
//Output: Returns response of user for menu selection 
char UI_ChocAnDPS::menu(void)
{  
    char response[2];

    clear_screen();
    cout<<"\t\t\t\t\t\t  ChocolateChocolateChocolateChocolateChocolate"<<endl;
    cout <<"\t\t\t\t\t\t(\tPlease select option by number:\t\t)" << endl
    << "\t\t\t\t\t\t(\t1.) Provider Login\t\t\t)" << endl
    << "\t\t\t\t\t\t(\t2.) Manager Login\t\t\t)" << endl
    << "\t\t\t\t\t\t(\t3.) Quit\t\t\t\t)" << endl;
    cout<<"\t\t\t\t\t\t  ChocolateChocolateChocolateChocolateChocolate"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t";

    cin.get(response, 3,'\n');
    cin.ignore(100000, '\n');
    if(response[1] != '\0')
        return '\0';
    return response[0];
}


//Task:   This function takes in the user verification number and their role, 
//        then uses that info to verify their status to login to the appropriate
//        area
//Input:  Function takes in the user's verification number and their role of
//        provider or manager
//Output: Returns True if verification was successful and false otherwise
bool UI_ChocAnDPS::verification(const char * user_number, const char * role)
{
      bool valid = true;
      
      if(hash_ptr)
        delete hash_ptr;
      
      hash_ptr = new Hash_table(role);
      valid = hash_ptr->validate(user_number);
      delete hash_ptr;
      hash_ptr = NULL;
      
      return valid;
}


