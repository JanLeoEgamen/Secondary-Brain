#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

// by DL Extention
// Leader: Egamen, Jan Leo
// Members: Ramilo, John Michael
// 	    Razon, Vince Gabriel
//	    Rosalia, Rhea Mae

void Meditate();
void Account();
// Gotoxy and Box
void gotoxy(int x, int y)  // this function is for the gotoxy, for us to be able yo use it in vs code IDE
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Box(int x1, int x2, int y1, int y2) // this function is for the design of the entire console
{ 
            for (x1=x1;y1<=y2;y1++){
                gotoxy(y1,x1);cout <<"o";
                gotoxy(y1,x2);cout <<"o";
            }
            for (y1=x1;x1<=x2;x1++){
                gotoxy(y2,x1);cout <<"o";
                gotoxy(y1,x1);cout <<"o";
            }
}

void loading() // this function is for loading design, for the user to be satisfied
{      int a=39;
       system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);
    gotoxy(30,12); cout << "Loading" ;

    for (int i=0;i<9;i++)
    {
        gotoxy(a,12); cout << "[]";
        a = a+2;
        Sleep(50);
    }
        system("cls");
}

// We use file handling for uur system, it would be a great help for us for the user to save their progress within the system
void Scheduler(string username, string password) // this is the function for our Schdule features
{
int choice;
            string month, day, year, time, name, description, location;
            fstream sched;
    do{
        loading();
        system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);

        gotoxy(35,7);   cout << "Scheduler"<<endl;  // we include academic and non academic for the organization of our system 
        gotoxy(32,9);   cout << "1 - Academic"<<endl; 
        gotoxy(32,10);   cout << "2 - Non Academic"<<endl; 
        gotoxy(32,11);   cout << "3 - Exit"<<endl; 
        gotoxy(32,13);   cout << "Enter choice: "; cin >> choice; 
        cin.ignore();
        system("cls");
        
        switch (choice)
        {
            case 1: 
            //inputting the infos for Academic schedules
                loading();
                system("cls");// function call for design
                Box(1,24,1,79);
                Box(5,20,5,75);
                
                gotoxy(31,7);   cout << "Academic Schedule" <<endl;
                gotoxy(7,9);   cout << "Enter Academic Event"<< endl;
                gotoxy(7,10);   cout << "Event Name:"; getline(cin, name);
                gotoxy(7,11);   cout << "Event Location:"; getline(cin, location);
                gotoxy(7,12);   cout << "Event Description:"; getline(cin, description);
                
                gotoxy(7,14);   cout << "Enter Date" <<endl;
                gotoxy(7,15);   cout << "Month:"; cin >> month;
                gotoxy(7,16);   cout << "Day:"; cin >> day;
                gotoxy(7,17);   cout << "Year:"; cin >> year;
                gotoxy(7,18);   cout << "Time:"; cin >> time;



    sched.open(username + " " + password + "A_schedule.txt", ios:: app); // for inputting schedule in .txt file
    // to save the progress of the user, we use the password and username inputted of the user to be the file name of txt file 

        if(sched.is_open())
        {
            sched << endl << name << " - " << description << endl;
            sched << "Date: " << month << " " << day << " " << year << " Time: " << time  << " @" << location << endl << endl;
            sched.close();
        }
                break;
            
            case 2:
            //inputting the infos for non-Academic schedules
            loading();// function call for design
            system("cls");
            Box(1,24,1,79);
            Box(5,20,5,75);

                gotoxy(31,7);   cout << "Non-Academic Schedule" <<endl;
                gotoxy(7,9);   cout << "Enter Non-Academic Event"<< endl;
                gotoxy(7,10);   cout << "Event Name:"; getline(cin, name);
                gotoxy(7,11);   cout << "Event Location:"; getline(cin, location);
                gotoxy(7,12);   cout << "Event Description:"; getline(cin, description);

                gotoxy(7,14);   cout << "Enter Date" <<endl;
                gotoxy(7,15);   cout << "Month:"; cin >> month;
                gotoxy(7,16);   cout << "Day:"; cin >> day;
                gotoxy(7,17);   cout << "Year:"; cin >> year;
                gotoxy(7,18);   cout << "Time:"; cin >> time;
                
    sched.open(username + " " + password + "NA_schedule.txt", ios:: app); // for inputting schedule in .txt file
    // to save the progress of the user, we use the password and username inputted of the user to be the file name of txt file 
        
        if(sched.is_open())
        {   
            sched << endl << name << " - " << description << endl;
            sched << "Date: " << month << " " << day << " " << year << " Time: " << time  << " @" << location << endl << endl;
            sched.close();
        }

                break;
            
            case 3:
                break;
            
            default:
            //validation
                        system("cls");
                        Box(1,24,1,79);// function call for design
                        Box(5,20,5,75);
                        gotoxy(32,12);   cout << "Wrong Choice!!!";
                        getch();
                        system("cls");
                        loading();
                break;
        }
    } while (choice<3);
        
}


void TaskManagement(string username, string password) // this is the function for our Task Management features
{
int choice;
            string month, day, year, time, name, description;
            fstream task;
    do{
        loading();
        system("cls");
        Box(1,24,1,79);// function call for design
        Box(5,20,5,75);

        gotoxy(32,7);   cout << "Task Management"<<endl;  // we include academic and non academic for the organization of our system 
        gotoxy(32,9);   cout << "1 - Academic"<<endl; 
        gotoxy(32,10);   cout << "2 - Non Academic"<<endl; 
        gotoxy(32,11);   cout << "3 - Exit"<<endl; 
        gotoxy(32,13);   cout << "Enter choice: "; cin >> choice; 
        cin.ignore();
 
        system("cls");
        
        switch (choice)
        {
            case 1:
            //inputting the infos for Academic task
                loading();
                system("cls");// function call for design
                Box(1,24,1,79);
                Box(5,20,5,75);

                gotoxy(33,7);   cout << "Academic Task Management" <<endl;
                gotoxy(7,9);   cout << "Enter Task"<< endl;
                gotoxy(7,10);   cout << "Task Name:"; getline(cin, name);
                gotoxy(7,11);   cout << "Task Description:"; getline(cin, description);
                
                gotoxy(7,13);   cout << "Enter Due Date" <<endl;
                gotoxy(7,14);   cout << "Month:"; cin >> month;
                gotoxy(7,15);   cout << "Day:"; cin >> day;
                gotoxy(7,16);   cout << "Year:"; cin >> year;
                gotoxy(7,17);   cout << "Time:"; cin >> time;

    task.open(username + " " + password + "A_task.txt", ios:: app); // for inputting task in .txt file
    // to save the progress of the user, we use the password and username inputted of the user to be the file name of txt file 
        
        if(task.is_open())
        {
            task << endl << "Task: " << name << " - " << description << endl;
            task << "Due Date: " << month << " " << day << " " << year << " Time: " << time << endl << endl;
            task.close();
            
        }
                break;
            
            case 2:
            //inputting the infos for non-Academic Task management
                loading();
                system("cls");// function call for design
                Box(1,24,1,79);
                Box(5,20,5,75);

                gotoxy(26,7);   cout << "Non-Academic Task Management" <<endl;
                gotoxy(7,10);   cout << "Enter Task"<< endl;
                gotoxy(7,11);   cout << "Task Name:"; getline(cin, name);
                gotoxy(7,12);   cout << "Task Description:"; getline(cin, description);
                
                gotoxy(7,14);   cout << "Enter Due Date" <<endl;
                gotoxy(7,15);   cout << "Month:"; cin >> month;
                gotoxy(7,16);   cout << "Day:"; cin >> day;
                gotoxy(7,17);   cout << "Year:"; cin >> year;
                gotoxy(7,18);   cout << "Time:"; cin >> time;

                
    task.open(username + " " + password + "NA_task.txt", ios:: app); // for inputting task in .txt file
    // to save the progress of the user, we use the password and username inputted of the user to be the file name of txt file 
        
        if(task.is_open())
        {
            task << endl << "Task: " << name << " - " << description << endl;
            task << "Due Date: " << month << " " << day << " " << year << " Time: " << time << endl << endl;
            task.close();
        }

                break;
            
            case 3:
                break;
            
            default:
            //validation
                        system("cls");// function call for design
                        Box(1,24,1,79);
                        Box(5,20,5,75);
                        gotoxy(32,12);   cout << "Wrong Choice!!!";
                        getch();
                        system("cls");
                break;
        }
    } while (choice<3);       
}

void Notes(string username, string password) // this is the function for our Notes features
{   
    string topic, content, month, day, year;
        fstream notes;
// function call for design
        system("cls");
        loading();
        system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);
        
        gotoxy(37,7);   cout << "Notes" <<endl;
        gotoxy(7,9);   cout << "Enter the following" << endl << endl;
        gotoxy(7,10);   cout << "Topic:"; getline(cin, topic);
        gotoxy(7,11);   cout << "Content:"; getline(cin, content);
                
        gotoxy(7,13);   cout << "Enter Date" <<endl;
        gotoxy(7,14);   cout << "Month:"; cin >> month;
        gotoxy(7,15);   cout << "Day:"; cin >> day;
        gotoxy(7,16);   cout << "Year:"; cin >> year;
                    
    notes.open(username + " " + password + "notes.txt", ios:: app); // for inputting schedule in .txt file
    // to save the progress of the user, we use the password and username inputted of the user to be the file name of txt file 

        if(notes.is_open())
        {
            notes << endl << "Date: " << month << " " << day << " " << year << endl;
            notes << "Topic: " << topic << endl;
            notes << "Content: " << content << endl << endl;
            notes.close();
        }

}
void Bookmark(string username, string password)// this is the function for our bookmark features
{   
    string bookname, page, month, day, year;
        // function call for design
        loading();
        system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);

        gotoxy(36,7);   cout << "Bookmark" <<endl;
        gotoxy(7,9);   cout << "Please input the following:" <<endl << endl;
        gotoxy(7,10);   cout << "Book Name:"; getline(cin, bookname);
        gotoxy(7,11);   cout << "Book Page:"; getline(cin, page);
                
        gotoxy(7,13);   cout << "Enter Date" <<endl;
        gotoxy(7,14);   cout << "Month:"; cin >> month;
        gotoxy(7,15);   cout << "Day:"; cin >> day;
        gotoxy(7,16);   cout << "Year:"; cin >> year;
                    
    fstream book;
    book.open(username + " " + password + "bookmark.txt", ios:: app); // for inputting bookmark in .txt file
            // to save the progress of the user, we use the password and username inputted of the user to be the file name of txt file 
        if(book.is_open())
        {
            book << endl << "Book Name: " << bookname << endl;
            book << "Book page: " << page << endl;
            book << "Date: " << month << " " << day << " " << year << endl << endl;
            book.close();
        }
}


void Display(string username, string password) // this function is for displaying all the inputted infos by the user
{
    int choice;
    fstream myfile;
    string line;

    do{
        loading();// function call for design
        system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);
        

                gotoxy(36,7);   cout << "Display"<<endl; // these are the included fir displaying
                gotoxy(28,9);   cout << "1 - Academic Schedule"<<endl; 
                gotoxy(28,10);   cout << "2 - Non-Academic Schedule"<<endl; 
                gotoxy(28,11);   cout << "3 - Academic Task"<<endl; 
                gotoxy(28,12);   cout << "4 - Non-Academic Task"<<endl; 
                gotoxy(28,13);   cout << "5 - Notes"<<endl; 
                gotoxy(28,14);   cout << "6 - Bookmark"<<endl; 
                gotoxy(28,15);   cout << "7 - Exit"<<endl; 
                gotoxy(30,17);   cout << "Enter Choice: "; cin >> choice;
    
                loading();
                system("cls");


        switch (choice)
        {
        case 1:
                
        // Academic Schedule
            cout << "Academic Schedule" << endl; 
        myfile.open(username + " " + password + "A_schedule.txt", ios:: in); // for inputting schedule in .txt file
        // this function is for outputting the infos in .txt file to console, it would output the saved infos of the user using the password and username arguments. 
            if(myfile.is_open())
            {
                while(getline(myfile, line)) // code bauty taught us this
                {
                    cout << line << endl;
                }
                myfile.close();
            }

            getch();

            break;

        case 2:
        //Non-Academic Schedule
            cout << "Non-Academic Schedule" << endl; 

        myfile.open(username + " " + password + "NA_schedule.txt", ios:: in); // for inputting schedule in .txt file
        // this function is for outputting the infos in .txt file to console, it would output the saved infos of the user using the password and username arguments. 
        
            if(myfile.is_open())
            {
                while(getline(myfile, line))
                {
                    cout << line << endl;
                }
                myfile.close();
            }

            getch();


            break;

        case 3:
        //Academic Task

        cout << "Academic Task" << endl; 


        myfile.open(username + " " + password + "A_task.txt", ios:: in); // for inputting schedule in .txt file
        // this function is for outputting the infos in .txt file to console, it would output the saved infos of the user using the password and username arguments. 
        
            if(myfile.is_open())
            {
                while(getline(myfile, line))
                {
                    cout << line << endl;
                }
                myfile.close();
            }

            getch();


            break;

        case 4:
        //Non-Academic Task
        cout << "Non-Academic Task" << endl; 
        // this function is for outputting the infos in .txt file to console, it would output the saved infos of the user using the password and username arguments. 
        
        myfile.open(username + " " + password + "NA_task.txt", ios:: in); // for inputting schedule in .txt file
        
            if(myfile.is_open())
            {
                while(getline(myfile, line))
                {
                    cout << line << endl;
                }
                myfile.close();
            }

            getch();

            break;

        case 5:
        //Notes
        cout << "Notes" << endl; 
        // this function is for outputting the infos in .txt file to console, it would output the saved infos of the user using the password and username arguments. 

        myfile.open(username + " " + password + "notes.txt", ios:: in); // for inputting schedule in .txt file
        
            if(myfile.is_open())
            {
                while(getline(myfile, line))
                {
                    cout << line << endl;
                }
                myfile.close();
            }

            getch();


            break;

        case 6:
        //Bookmark
        
        cout << "Book mark" << endl; 
    
    myfile.open(username + " " + password + "bookmark.txt", ios:: in); // for inputting schedule in .txt file
        // this function is for outputting the infos in .txt file to console, it would output the saved infos of the user using the password and username arguments. 
        
            if(myfile.is_open())
            {
                while(getline(myfile, line))
                {
                    cout << line << endl;
                }
                myfile.close();
            }
            getch();
            break;

        case 7:
        //Exit


            break;
        
        default:
                        system("cls");
                        Box(1,24,1,79);// function call for design
                        Box(5,20,5,75);
                        gotoxy(32,12);   cout << "Wrong Choice!!!";
                        getch();
                        system("cls");
            break;
        }
        
    }while(choice<7);
}

void UserGuidelines() // this function is for the guidlines of user
{
    int choices;

do {
    system ("cls");
    Box(1,24,1,79);
    Box(5,20,5,75);

    gotoxy(32,7);   cout << "User Guidelines" << endl;
    gotoxy(30,9);   cout << "1 - Scheduler" << endl;
    gotoxy(30,10);  cout << "2 - Task Management" << endl;
    gotoxy(30,11);  cout << "3 - Notes" << endl;
    gotoxy(30,12);  cout << "4 - Bookmark" << endl;
    gotoxy(30,13);  cout << "5 - Display" << endl;
    gotoxy(30,14);  cout << "6 - Meditation" << endl;
    gotoxy(30,15);  cout << "7 - Exit" << endl;
    gotoxy(30,17);  cout << "Enter a Number: ";
    cin >> choices;

    system ("cls");
    Box(1,24,1,79);
    Box(5,20,5,75);


        switch (choices) {
            case 1:
            // guidelines for scheduler
                gotoxy(35,7);    cout << "Scheduler" << endl;
                gotoxy(15,9);    cout << "1 - Provide the necessary information for the event,";
                gotoxy(15,10);   cout << "including the event name, location, description, date,";
                gotoxy(15,11);   cout <<  "and time.";
                gotoxy(15,12);   cout << "2 - The schedule will be stored in separate files based";
                gotoxy(15,13);   cout << "on the event type and your username and password." << endl;
                getch();
                break;

            case 2:
            // guidelines for task management
                gotoxy(33,7);    cout << "Task Management" << endl;
                gotoxy(15,9);    cout << "1 - Enter the task name, description, due date, and ";
                gotoxy(15,10);   cout << "time to add a task to your list.";
                gotoxy(15,11);   cout << "2 - The tasks will be stored in separate files based on"; 
                gotoxy(15,12);   cout << "the task type and your username and password.";
                getch();
                break;

            case 3:
            // guidelines for notes
                gotoxy(35,7);    cout << "Notes" << endl;
                gotoxy(15,9);    cout << "1 - Provide a topic and content for your"; 
                gotoxy(15,10);    cout << "note, along with the date.";
                gotoxy(15,11);    cout << "2 - The notes will be stored in a file named username"; 
                gotoxy(15,12);    cout << "password notes.txt based on your username and password.";
                getch();
                break;

            case 4:
            // guidelines for bookmark
                gotoxy(35,7);    cout << "Bookmark" << endl;
                gotoxy(15,9);    cout << "1 - Enter the book name, page number,"; 
                gotoxy(15,10);    cout << "and the date of the bookmark.";
                gotoxy(15,11);    cout << "2 - The bookmarks will be stored in a file"; 
                gotoxy(15,12);    cout << "named username password bookmark.txt based on your"; 
                gotoxy(15,13);    cout << "username and password.";
                getch();
                break;

            case 5:
            // guidelines for Display
                gotoxy(35,7);    cout << "Display" << endl;
                gotoxy(15,9);    cout << "1 - Choose the corresponding option to display"; 
                gotoxy(15,10);    cout << "the desired information.";
                gotoxy(15,11);    cout << "2 - The information will be read from the respective"; 
                gotoxy(15,12);    cout << "files and displayed on the console.";
                getch();
                break;

            case 6:
            // guidelines for meditation
                gotoxy(35,7);    cout << "Meditation" << endl;
                gotoxy(20,9);    cout << "1 - Follow the step indicates in the meditation";
                gotoxy(20,10);    cout << "2 - At the end of the meditation the"; 
                gotoxy(20,11);    cout << "user would expect to have peace of mind";
                getch();
            break;


            case 7:
                break;

            default:
                    // validation
                        system("cls");
                        Box(1,24,1,79);// function call for design
                        Box(5,20,5,75);
                        gotoxy(32,12);   cout << "Wrong Choice!!!";
                        getch();
                        system("cls");
            UserGuidelines();
                break;
        }

}while(choices<7);

}


void MainMenu(string username, string password) // this is the function for the main menu of the secondary brain system, it includes the argument of password and username for saving the progress of the user

{   
    int choice;

      do 
        { 
            system("cls");
                Box(1,24,1,79);
                Box(5,20,5,75);
                
                gotoxy(32,7);  cout << "Secondary Brain"<<endl; 
                gotoxy(30,9);  cout << "0 - User Guidelines"<<endl; 
                gotoxy(30,10); cout << "1 - Scheduler"<<endl; 
                gotoxy(30,11); cout << "2 - Task Management"<<endl; 
                gotoxy(30,12); cout << "3 - Notes"<<endl; 
                gotoxy(30,13); cout << "4 - Bookmark"<<endl; 
                gotoxy(30,14); cout << "5 - Display"<<endl; 
                gotoxy(30,15); cout << "6 - Meditation"<<endl; 
                gotoxy(30,16); cout << "7 - Exit"<<endl; 
                gotoxy(32,18); cout << "Enter choice: "; cin>>choice; 
                cin.ignore();

                switch (choice)
                {

                    
                    case 0:
                       UserGuidelines();

                        break;

                    case 1:

                        Scheduler(username, password);

                        break;

                    case 2:

                        TaskManagement(username, password);

                        break;

                    case 3:
                        
                        Notes(username, password);

                        break;

                    case 4:
                    
                        Bookmark(username, password);

                        break;

                    case 5:

                        Display(username, password);

                        break;

                    case 6:
                    
                        Meditate();

                        break;

                    case 7:
                    
                        Account();

                        break;
                    
                    default:
                        loading();
                        system("cls");
                        Box(1,24,1,79);// function call for design
                        Box(5,20,5,75);
                        gotoxy(32,12);   cout << "Wrong Choice!!!";
                        getch();
                        system("cls");
                        MainMenu(username, password);
                        break;
                }


        }while(choice<7);
}




void Register() // this function is for user account registration, i
{
    string username, password;
    bool check;

    retry:

        system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);
    gotoxy(36,9); cout << "Register" << endl;
    gotoxy(23,11); cout << "Instruction: Input the following.\n";
    // for inputting the username and password, this is very important argument to save the progress of indiviyal user
    gotoxy(23,13);cout << "Username: ";
    getline(cin, username);
    gotoxy(23,14);cout << "Password: ";
    getline(cin, password);

    fstream checker;
    string line;
    fstream myfile;
    system("cls");

    checker.open("UserInfo.txt", ios::in);
    if (checker.is_open()) // this is for validation that if there is an account existing, you need to input another entry for password and username
    {
        while (getline(checker, line))
        {
            //this will check the UserInfo.txt line by line if the enrty for account is existing 
            if (username + " " + password == line)
            {
                check = true; // the bool would be initialize to true 
                break;
            }
        }
        checker.close();
    }

    if (check) // if existing
    {
        Box(1,24,1,79);
        Box(5,20,5,75);
        gotoxy(7,12); cout << "Please retry, the username or password you have inputted is taken.";// validation
        getch();
        system("cls");
        Register();// the console will go to register again using recursive function
        }
    else
    {
        // if the entry for username and password is new, automatic it would be creating an account, it would be save in .txt file
    myfile.open("UserInfo.txt", ios::app);

    if (myfile.is_open())
    {
        myfile << username << " " << password << endl; // this is the stored saved account, it would be save in UserInfo.txt file
        myfile.close();
    }
    
    loading();

    Box(1,24,1,79);
    Box(5,20,5,75);

    gotoxy(27,12);cout<< "Account has been created!";
    getch();
    system("cls");
    }
}

string hideWord() // we got this function in web, this function would be use in hiding the password while entering in Log in
{
    string word;
    char pass[32];
    char a;
    int i = 0;
    while (true)
    {
        a = _getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            pass[i] = a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            cout << "\b \b";
            --i;
        }
        if (a == '\r')
{
    ++i;  // Increment i before setting the null character
    pass[i] = '\0';
    break;
}
    }

    int size = strlen(pass);
    for (size_t i = 0; i < size; i++)
    {
        word += pass[i];
    }

    return word;
}

void LogIn() // this function is for logging in
{
    string username, password;
    bool check;
    int attempt = 3; // the user will only have 3 attempts to enter the password 
        retry:
        system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);
        gotoxy(36,9); cout << "Log in" << endl;

        // for user entering the username and password
        gotoxy(25,11); cout << "Enter username: ";
        getline(cin, username);
        gotoxy(25,12); cout << "Enter password: ";
        hideWord(); // function call for hiding the password
        password = hideWord();// after going to hideword function the value of the return value wouyld be pass to the password argument

    fstream myfile;
    string line;

    system("cls");
    myfile.open("UserInfo.txt", ios::in);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (username + " " + password == line) // this would check if the account entered by the user is existing
            {
                check = true; // if the accoount is existing 
                break;
            }
        }
        myfile.close();
    }

    if (!check) // if not existing the user will be given another attempt
    {   
        attempt--; // decreament of attemot
        Box(1,24,1,79);
        Box(5,20,5,75);
            gotoxy(26,12); cout << "Invalid username or password" << endl; // 
            gotoxy(26,13); cout << "Attempt left:" << attempt << endl;
        getch();
        system("cls");

        if (attempt==0) // if the attempt became 0 the prpgram would be exiting
        {
            Box(1,24,1,79);
            Box(5,20,5,75);
            gotoxy(20,12);cout << "Locked! try to run the program again..."; 
            exit(0);
        }
        goto retry;
    }

    else
    {   loading();
        Box(1,24,1,79);
        Box(5,20,5,75);
        gotoxy(29,12);cout << "Successfuly logged in!" << endl; // if true and the account is existing, it would be go in Main menu
        getch();
        system("cls");
        MainMenu(username, password); // it would pass the argument of username and password for saving and storing the progress of the account
    }
}

// log in or register menu , to save the progress of the user
void Account()
{

    int choice;
        loading();
        system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);
        gotoxy(26,9); cout << "Welcome to Secondary Brain!\n";
        gotoxy(33,11); cout << "1. Log in\n";
        gotoxy(33,12); cout << "2. Register\n";
        gotoxy(33,13); cout << "3. Exit\n";
        gotoxy(30,15); cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character after reading the choice

    system("cls");

        switch (choice)
        {

        case 1:
            loading();
            LogIn(); //funtion for log in
            break;

        case 2:
            loading();
            Register(); //code for register
            Account(); // to go back menu  after registering an account
            break;

        case 3:
            exit(0);
            break;

        default:
                        loading();
                        system("cls");
                        Box(1,24,1,79);
                        Box(5,20,5,75);
                        gotoxy(32,12);   cout << "Wrong Choice!!!";
                        getch();
                        system("cls");
                        Account();
            break;
        }

}

int main()
{
    //this is for customizing the console appearance
    
    // Set console buffer size
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {80, 40}; // Width, Height
    SetConsoleScreenBufferSize(hOut, bufferSize);

    // Set console window size
    SMALL_RECT windowSize = {0, 0, 79, 39}; // Left, Top, Right, Bottom
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);
    
    // Set console font size
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hOut, FALSE, &fontInfo);
    fontInfo.dwFontSize.X = 12; // Width of each character
    fontInfo.dwFontSize.Y = 24; // Height of each character
    SetCurrentConsoleFontEx(hOut, FALSE, &fontInfo);

    SetConsoleTitleA("Secondary Brain - DL Extention");
    // Get the handle to the console window
    HWND consoleHandle = GetConsoleWindow();

    // Get the handle to the console's output buffer
    HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the background color to beige
    SetConsoleTextAttribute(consoleOutput, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

    // Refresh the console window to apply the changes
    RedrawWindow(consoleHandle, NULL, NULL, RDW_INVALIDATE | RDW_ALLCHILDREN);

    Account();
    return 0;
}



//for outputting the quotes in meditation
void quotes(int choice)
{
    switch(choice)
    {
        
        case 1:
            gotoxy(12,12);   cout << "The greatest glory in living lies not in never falling,";
            gotoxy(12,13);   cout <<  "but in rising every time we fall. -Nelson Mandela";
            break;
        
        
        case 2:
            gotoxy(12,12);   cout << "The way to get started is to quit talking and begin";
            gotoxy(12,13);   cout << "doing. -Walt Disney" << endl;

            break;
        
        
        case 3:
            gotoxy(12,12);   cout << "Your time is limited, so don't waste it living someone"; 
            gotoxy(12,13);   cout << "else's life. Don't be trapped by dogma - which is living";
            gotoxy(12,14);   cout << "with the results of other people's thinking. -Steve Jobs";

            break;
        
        
        case 4:
            gotoxy(12,12);   cout << "If you look at what you have in life, you'll always have";
            gotoxy(12,13);   cout << "more. If you look at what you don't have in life, you'll";
            gotoxy(12,14);   cout << "never have enough. -Oprah Winfrey";

            break;
        
        
        case 5:
            gotoxy(12,12);   cout << "If you set your goals ridiculously high and it's a failure,";
            gotoxy(12,13);   cout << " you will fail above everyone else's success. -James Cameron";

            break;
        
        
        case 6:
            gotoxy(12,12);   cout << "Life is what happens when you're busy making other plans.";
            gotoxy(12,13);   cout << "-John Lennon";

            break;
        
        
        case 7:
            gotoxy(12,12);   cout << "Spread love everywhere you go. Let no one ever come to you ";
            gotoxy(12,13);   cout << "without leaving happier. -Mother Teresa";

            break;
        
        
        case 8:
            gotoxy(12,12);   cout << "When you reach the end of your rope, tie a knot in it and hang ";
            gotoxy(12,13);   cout << "on. -Franklin D. Roosevelt";

            break;
        
        
        case 9:
            gotoxy(12,12);   cout << "Always remember that you are absolutely unique. Just like ";
            gotoxy(12,13);   cout << "everyone else. -Margaret Mead";

            break;
        
        
        case 10:
            gotoxy(12,12);   cout << "Don't judge each day by the harvest you reap but by the seeds";
            gotoxy(12,13);   cout << "that you plant. -Robert Louis Stevenson";

            break;
        
        
        case 11:
            gotoxy(12,12);   cout << "The future belongs to those who believe in the beauty of their";
            gotoxy(12,13);   cout << "dreams. -Eleanor Roosevelt";

            break;
        
        
        case 12:
            gotoxy(12,12);   cout << "Tell me and I forget. Teach me and I remember. Involve me and";
            gotoxy(12,13);   cout << " I learn. -Benjamin Franklin";

            break;
        
        
        case 13:
            gotoxy(12,12);   cout << "The best and most beautiful things in the world cannot be seen";
            gotoxy(12,13);   cout << " or even touched — they must be felt with the heart. -Helen Keller";

            break;
        
        
        case 14:
            gotoxy(12,12);   cout << "It is during our darkest moments that we must focus to see ";
            gotoxy(12,13);   cout << "the light. -Aristotle";

            break;
        
        
        case 15:
            gotoxy(12,12);   cout << "Whoever is happy will make others happy too. -Anne Frank";

            break;
        
        
        case 16:
            gotoxy(12,12);   cout << "Do not go where the path may lead, go instead where there";
            gotoxy(12,13);   cout << "is no path and leave a trail. -Ralph Waldo Emerson";

            break;
        
        
        case 17:
            gotoxy(12,12);   cout << "Spread love everywhere you go. Let no one ever come to ";
            gotoxy(12,13);   cout << "you without leaving happier. -Mother Teresa";

            break;
        
        
        case 18:
            gotoxy(12,12);   cout << "When you reach the end of your rope, tie a knot in it ";
            gotoxy(12,13);   cout << "and hang on. -Franklin D. Roosevelt";

            break;
        
        
        case 19:
            gotoxy(12,12);   cout << "Always remember that you are absolutely unique. Just like";
            gotoxy(12,13);   cout << " everyone else. -Margaret Mead";

            break;
        
        
        case 20:
            gotoxy(12,12);   cout << "Do not go where the path may lead, go instead where there ";
            gotoxy(12,13);   cout << "is no path and leave a trail. -Ralph Waldo Emerson";

            break;
    }
}

// this function is for our special features, the meditation
void Meditate()
{
    int choice;
    loading();
    system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);
    
    gotoxy(35,7);   cout << "Meditation";
    gotoxy(12,9);   cout << "Instructions:"; // these are the instructions
    gotoxy(12,10);   cout << "1. Find a quiet space: Choose a quiet and comfortable ";
    gotoxy(12,11);   cout << "space where you can sit undisturbed for a few minutes. ";
    getch();
    gotoxy(12,12);   cout << "2. Sit comfortably: Find a comfortable seated position,";
    gotoxy(12,13);   cout << "either on a chair or on the floor. Relax your body and ";
    gotoxy(12,14);   cout << "keep your back straight.";
    getch();
    gotoxy(12,15);   cout << "3. Take deep breaths: Take a few slow, deep breaths in ";
    gotoxy(12,16);   cout << "through your nose and exhale through your mouth. Allow ";
    gotoxy(12,17);   cout << "yourself to relax with each breath.";
    getch();
    
    system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);
        
    gotoxy(35,7);   cout << "Meditation" << endl << endl;
    gotoxy(12,9);   cout << "4. Choose quotation: Pick a random number " << endl;
    gotoxy(12,10);   cout << "Enter number: "; cin >> choice;
    quotes(choice);

    getch();

    gotoxy(12,16);   cout << "5. Embrace the words: Allow the words of the quotation";
    gotoxy(12,17);   cout << "to sink in. Reflect on its deeper meaning and let it ";
    gotoxy(12,18);   cout << "guide your thoughts and emotions. " << endl;
    getch();
    system("cls");
        Box(1,24,1,79);
        Box(5,20,5,75);
        
    gotoxy(35,7);   cout << "Meditation" << endl << endl;
    gotoxy(12,9);   cout << "6. Stay present: Remain present with the quotation, ";
    gotoxy(12,10);   cout << "letting it create a sense of calm and clarity within ";
    gotoxy(12,11);   cout << "you. Be fully absorbed in the words and their significance." << endl;
    getch();
    gotoxy(12,12);   cout << "7. Notice distractions: If your mind wanders or distractions";
    gotoxy(12,13);   cout << "arise, gently acknowledge them without judgment. Return your";
    gotoxy(12,14);   cout << "focus back to the quotation, letting it anchor your attention." << endl;
    getch();
    gotoxy(12,15);   cout << "8. End with gratitude: When you are ready to conclude your";
    gotoxy(12,16);   cout << "meditation, take a moment to express gratitude for this ";
    gotoxy(12,17);   cout << "practice and for the wisdom contained within the ";
    gotoxy(12,18);  cout <<"chosen quotation." << endl;
    getch();

}