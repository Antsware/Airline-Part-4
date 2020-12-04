/*
    Descritption:  Allows the user to deposit into one
    of his/her accounts

    Class: COP3014CE_502_2208
    Date Due: 12/04/2020

    Author: Anthony Williams
                                                            */

//Libraries
#include <iostream>  //users interaction
#include <fstream> //read and write to file
#include <string>  //to store names and passwords
#include <cmath>   //to do calculations

using namespace std;

void menu()
{
    //ask for what they want to do
    cout << "\nTo Deposit press '1'"; //asks the user to deposit
    cout << "\nTo Withdraw press '2'"; //asks the user to withdraw
    cout << "\nTo Balance Inquiry press '3'"; //asks the user to display balance
    cout << "\nTo Transfer Balance press '4'"; //asks the user to transfer their balance
    cout << "\nTo Log Out press '5'" << endl; //stops program
    cout << "Enter your selection: ";
}

struct account //declares structure variable
{
    string Fname; //firstname
    string Lname; //lastname
    string password; //holds password
    string userName; //holds username
   // string customer; //holds customer name
    int saveAccount; //holds savings
    int checkAccount; //holds chrckings
    int amount = 0; //requests amount
    int selection;       //users choice
    char accountType;  //holds which account
    char accountType1; //holds the transfer to
    
    
};

void read(account client[4])
{
    ifstream infile; //input variable
    ofstream outfile; //output variable
    
    infile.open("account.dat"); //opens file for reading

    if(!infile) //checks if the file is open
    {
      cout << "file was not read" << endl;
    }
    
    int x = 0;
    while(x <= 4) //reads and saves data into variables
    {
        infile >> client[x].Fname; //reads and stores first name
        infile >> client[x].Lname; //reads and stores last name
        infile >> client[x].userName; //reads and stores user name
        infile >> client[x].password; //reads and stores password
        infile >> client[x].saveAccount; //reads and stores savings account
        infile >> client[x].checkAccount; //reads and stores checkings account
        x++;
    }
    
}

//depsit function
void deposit(account client[4], fstream& outfile)
{
    
    
        //which account
        cout << "\nChoose which account you would like to Deposit from" << endl;
        cout << "('c' for Checkings and 's' for Savings: ";
        cin >> client->accountType;
        
        //users amount
        cout << "\nEnter the amount you would like to deposit: ";
        cin >> client->amount;
        
    //decides users choice
        switch (client->accountType)
        {
        
    case 'c':
                cout << "=================================================" << endl;
                client->checkAccount += client->amount; //formula for checkings
                cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount; //displays results
                cout << "\n\t\tSavings: $" << client->saveAccount << endl; //displays results
                cout << "\nYou have quit your session" << endl;// dipslays results
                outfile << client->checkAccount;
                break;
    case 'C':
                cout << "=================================================" << endl;
                client->checkAccount += client->amount; //formula foe checkings
                cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount; //displays results
                cout << "\n\t\tSavings: $" << client->saveAccount << endl;//displays results
                cout << "\nYou have quit your session" << endl;//amsks the user foe selection
                
                break;
    case 's':
                cout << "=================================================" << endl;
                client->saveAccount += client->amount; //formula fo savings account
                cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount; //displays results
                cout << "\n\t\tSavings: $" << client->saveAccount << endl; //displays results
                cout << "\nYou have quit your session" << endl; //asks the user for selection
               
                break;
    case 'S':
                cout << "=================================================" << endl;
                client->saveAccount += client->amount; //formula for savings
                cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount; //displays results
                cout << "\n\t\tSavings: $" << client->saveAccount << endl; //displays results
                cout << "\nYou have quit your session" << endl; // tells the user progam ends
                
                break;
        }
   
}

//withdraw function
void withcdraw(account client[], fstream& outfile)
{
    
    do
    {
        
    //which account
    cout << "\nChoose which account you would like to withdraw" << endl;
    cout << "('c' for Checkings and 's' for Savings or 'q' to Quit): " << endl;
    cin >> client->accountType;
        
        if(client->accountType == 'q')
         {
             cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount;
             cout << "\n\t\tSavings: $" << client->saveAccount << endl;
             cout << "\nYou have quit your session" << endl;
             break;
         }
        
    //input amount
    cout << "\n\tEnter Withdraw amount: ";
    cin >> client->amount;
        
        //if negative amount in checkings
        if(client->amount > client->checkAccount && client->accountType == 'c')
        {
            cout << "INSUFFICIENT FUNDS";
            cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount; //prints to display
            cout << "\n\t\tSavings: $" << client->saveAccount << endl; // prints to display
            cout << "\nYou have quit your session" << endl; //prints to display
            break;
        }
        
        //if negative amount in savings
        else if(client->amount > client->saveAccount && client->accountType == 's')
        {
            cout << "INSUFFICIENT FUNDS";
            cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount;
            cout << "\n\t\tSavings: $" << client->saveAccount << endl;
            cout << "\nYou have quit your session" << endl;
            break;
        }
        
        else if(client->accountType == 'c' && client->amount < client->checkAccount)
        {
            cout << "=================================================" << endl;
            client->checkAccount -= client->amount;
            cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount;
            cout << "\n\t\tSavings: $" << client->saveAccount << endl;
            cout << "\nYou have quit your session" << endl;
            outfile << client->checkAccount;
        }
        
        else if(client->accountType == 'C' && client->amount < client->checkAccount)
        {
            cout << "=================================================" << endl;
            client->checkAccount -= client->amount;
            cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount;
            cout << "\n\t\tSavings: $" << client->saveAccount << endl;
            cout << "\nYou have quit your session" << endl;
            outfile << client->checkAccount;
        }
        
        else if(client->accountType == 's' && client->amount < client->saveAccount)
        {
            cout << "=================================================" << endl;
            client->saveAccount -= client->amount;
            cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount;
            cout << "\n\t\tSavings: $" << client->saveAccount << endl;
            cout << "\nYou have quit your session" << endl;
            outfile << client->saveAccount;
        }
        
        else if(client->accountType == 'S' && client->amount < client->saveAccount)
        {
            cout << "=================================================" << endl;
            client->saveAccount -= client->amount;
            cout << "\n" << client->Fname << " " << client->Lname << "\t Checkings: $" << client->checkAccount;
            cout << "\n\t\tSavings: $" << client->saveAccount << endl;
            cout << "\nYou have quit your session" << endl;
            outfile << client->saveAccount;
        }
        
    }
    while(client->accountType != 'q');
}

void balance(account client[])
{
    cout << "=================================================" << endl;
    cout << "\t\tCurrent Balance" << endl;
    cout << "\nChecckings: $" << client->checkAccount << endl;
    cout << "Savings: $" << client->saveAccount << endl;
}

void transfer(account client[], fstream& outfile)
{
    //which account to transfer from
    cout << "\nChoose which account you would like to transfer from" << endl;
    cout << "('c' for Checkings and 's' for Savings or 'q' to Quit): " << endl;
    cin >> client->accountType;
    
    //which account to transfer to
    cout << "\nChoose which account you would like to transfer to" << endl;
    cout << "('c' for Checkings and 's' for Savings or 'q' to Quit): " << endl;
    cin >> client->accountType1;
    
    cout << "\nEnter the amount to transfer" << endl;
    cin >> client->amount;
    
     if(client->accountType == 'c' && client->accountType1 == 's')
    {
        client->checkAccount -= client->amount; //subtracts amount
        client->saveAccount += client->amount;  // adds amount
        cout << "=================================================" << endl;
        cout <<"\t\tCurrent Balance" << endl;
        cout << "\nCheckings: $" << client->checkAccount << endl;
        cout << "Savings: $" << client->saveAccount << endl;
    }
    
    else if(client->accountType == 'C' && client->accountType1 == 'S')
    {
        client->checkAccount -= client->amount; //subtracts amount
        client->saveAccount += client->amount;  // adds amount
        cout << "=================================================" << endl;
        cout <<"\t\tCurrent Balance" << endl;
        cout << "\nCheckings: $" << client->checkAccount << endl;
        cout << "Savings: $" << client->saveAccount << endl;
    }
    
    else if(client->accountType == 's' && client->accountType1 == 'c')
    {
        client->saveAccount -= client->amount;  // subtracts amount
        client->checkAccount += client->amount; //adds amount
        cout << "=================================================" << endl;
        cout <<"\t\tCurrent Balance" << endl;
        cout << "\nCheckings: $" << client->checkAccount << endl;
        cout << "Savings: $" << client->saveAccount << endl;
        outfile << client->saveAccount;
        outfile << client->checkAccount;
    }
    
    else if(client->accountType == 'S' && client->accountType1 == 'C')
    {
        client->saveAccount -= client->amount;  // subtracts amount
        client->checkAccount += client->amount; //adds amount
        cout << "=================================================" << endl;
        cout <<"\t\tCurrent Balance" << endl;
        cout << "\nCheckings: $" << client->checkAccount << endl;
        cout << "Savings: $" << client->saveAccount << endl;
        outfile << client->saveAccount;
        outfile << client->checkAccount;
    }
    
    else
    {
        cout << "Invalid Entry" << endl;
    }
  
}

struct account getClient(string uName, string uPassword, account a[])
{
    account b;
    for(int i = 0; i < 4; i++)
    {
        if(a[i].userName == uName && a[i].password == uPassword)
        {
            b = a[i];
            return b;
        }
    }
    return b;
}

void logOut()
{
    exit(0);
}

int main()
{
    //declare variables
    account client[4];
    string uName;
    string uPassword;
    int selection;
    int a = 0; // for the while
    fstream outfile;
    outfile.open("account.dat");
    
    read(client); //calls read function
    
    // Welcome
    cout << "Welcome to out banking system!" << endl;
    
    bool k = false;
    while(!k)
    {
        //ask for username
        cout << "\nHello, please enter your userName: "; //asks user for username
        cin >> uName; //input users name
     
        // ask password
        cout << "\nPlease enter your password: "; // asks user for password
        cin >> uPassword; //inputs password
    
       
  
       
        account obj = getClient(uName, uPassword, client);
        if(obj.Fname.empty())
        {
            continue;
        }
        
        else
        {
            //checks if input macthes records
            cout << "\nWelcome " << obj.Fname << " " << obj.Lname << endl;
            cout << "\nChecckings: $" << obj.checkAccount << endl;
            cout << "Savings: " << obj.saveAccount << endl;
            k = true;
        }
    }
    
    
    while(a < 3)
    {
        menu(); //prints menu
        cin >> selection; //gathers users selection
    
        //decides what the user chooses
        if(selection == 1)
        {
            deposit(client, outfile); //calls deposit function
            a++; //increment for only 3 loops
        }
    
        if(selection == 2)
        {
            withcdraw(client, outfile); //calls withdraw function
            a++; //increment for only 3 loops
        }
    
        if(selection == 3)
        {
            balance(client); // calls balance function
            a++; //increment for only 3 loops
        }
        
        if(selection == 4)
        {
            transfer(client, outfile); //calls tansfer function
            a++; //increment for only 3 loops
        }
        
        if(selection == 5)
        {
            logOut(); //calls logout function
        }
    }
    }
    
