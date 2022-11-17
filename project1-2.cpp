#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<vector>
#include<math.h>
#include<time.h>
using namespace std;


int date_flag=0;                                                 //flag to check that the user has got the date or not 

void signin();             //function for the user to sign in into his already existing account;if not then direct him to registration
void date_selection();    //gives user the privelage of selecting a date manually
void generate_date(int);    // generates an automatic date
void registration();     //function for registration: input details
void date_checker();     //to check if user has got a date or not
void user_end(int);         //to display user account info 


struct end_user{
    string name,address,email,password;
    int age;                                                     //structure to store details of the user
    char c;
    unsigned long long int aadhar_no,mobile_no;
    struct date{
        int monthh;
        int dayy;
        int yearr;
    }d;
};                       


vector<end_user> e;                                               //vector to store no of users     


void signin()
{   
    system("CLS");
    string mail1,pass1;                                 //variables to store values entered by the user

    if(e.size()!=0)
    { hello:
    cout<<"enter your email: ";
      cin>>mail1;
    cout<<"\n enter your password: ";
       cin>>pass1;
       cout<<"validating data";
       for(int i=0;i<6;i++)
       {
        cout<<".";
        Sleep(2000);
       }
       for(int i=0;i<(int)e.size();i++)                              //loop to travel throughout the vector
       //for(auto &emp:e) 
       {
       if(mail1==e[i].email && pass1==e[i].password)
       {
        cout<<"authorization successful!!"<<endl;
         for(int i=0;i<3;i++)
         {
           cout<<" ";
           Sleep(2000);
         }
       system("CLS");
        user_end(i);
       }
       
       
       else
       {
          system("CLS");
        cout<<"\a no such data found!!"<<endl;
        habibi:
        cout<<"press 1 to register as a new user"<<endl;
        cout<<"press 2 to try again"<<endl;
        int x;
        cin>>x;
        switch(x){
            case 1:
            registration();
            break;

            case 2:
              cout<<"please try again";
        for(int i=0;i<3;i++)
        {
            cout<<".";
            Sleep(2000);
        }
        cout<<endl;
        goto hello;
        break;
         
         default:
         cout<<"please select a valid choice"<<endl;
         for(int i=0;i<3;i++)
        {
            cout<<".";
            Sleep(2000);
        }
        goto habibi;

        }
        
       }
       }

       
    
    //date_window();
    }
    else
    {
        cout<<"no users currently present please make a new registration"<<endl;
        cout<<"\n forwarding you to the registration portal"<<endl;
        for(int i=0;i<4;i++)
        {
            cout<<".";
            Sleep(3000);
        } 
        
        registration();
    }
}
void registration(){
       
       end_user e1;
       string t_name,t_address,t_email,t_password;
    int t_age;
    char t_c;
    unsigned long long int t_aadhar_no,t_mobile_no;
    system("CLS");
         
    cout<<"**************welcome to the portal of registration************* "<<endl;
    cout<<endl<<endl;
    cout<<"enter your name: ";
    getline(cin>>ws,t_name);
    e1.name=t_name;
    cout<<endl;      
    cout<<"enter your gender(M/F)";
    cin>>t_c;
    e1.c=t_c;
    cout<<endl;
    cout<<"enter your address: ";
    getline(cin>>ws,t_address);
    e1.address=t_address;
    cout<<endl;
    cout<<"enter your age: ";
    cin>>t_age;
    e1.age=t_age;
    cout<<endl;
    cout<<"enter your aadhar no: ";
    cin>>t_aadhar_no;
    e1.aadhar_no=t_aadhar_no;
    cout<<endl;
    cout<<"enter your mobile no: ";
    cin>>t_mobile_no;
    e1.mobile_no=t_mobile_no;
    cout<<endl;
    cout<<"enter your e-mail: ";
    cin>>t_email;
    e1.email=t_email;
    cout<<endl;
    cout<<"create a password: ";
    cin>>t_password;
    e1.password=t_password;
    cout<<endl;
    e.push_back(e1);
    
    cout<<"you are now registered on the system!!!"<<endl;
    cout<<"directing you to the sign in portal in ";
    for(int i=3;i>=1;i--)
    {
        cout<<i<<" ";
        Sleep(2000);
    }
    cout<<endl;
    signin();
    

}
int main()
{   system("CLS");
   
   
    unsigned long long int uhid_one,uhid_two;
    
    int choice;
   
    
back:
while(1){
      system("CLS");

    cout<<"*********BOOSTER DOZE REGISTRATION PORTAL*************"<<endl;
    cout<<endl;
    cout<<"enter your UHID no for first doze: ";
        cin>>uhid_one;
        
        if(uhid_one<= pow(10,10))                            //100000000000
         {


            cout<<"checking with the system";
            for(int i=0;i<4;i++)
        {
            cout<<".";
            Sleep(1000);
        } 

         }
        else
        {
            cout<<"\a you entered the wrong UHID no for first doze please try again"<<endl;
            goto back;
        } 
        cout<<endl;
    cout<<"enter your UHID no for second doze: ";
        cin>>uhid_two;
        if(uhid_two<=pow(10,10))          
         {
            cout<<endl;
         }
        else
        {
            cout<<"\a you entered the wrong UHID no for second doze please try again"<<endl;
            goto back;
        } 
        cout<<"verifying UHID numbers ";
        for(int i=0;i<5;i++)
        {
            cout<<".";
            Sleep(2000);
        }    
         
         cout<<"UHID verification successful"<<endl;
   system("CLS");
   screentwo:
   
       cout<<"-----Welcome to the registration of booster doze-----"<<endl;
        cout<<"\n 1.new registration"<<endl;
        cout<<"\n 2.sign in (already a user)"<<endl;
        cin>>choice;
        if(choice==1)
        {
            system("CLS");
            registration();
        }
        else if(choice==2)
        {   
            system("CLS");
             signin();

        }
        else
        {
        cout<<"please enter a valid choice"<<endl;
        goto screentwo;
        }
   }
    

    
    
    
    return 0; 
}

       
  


void generate_date(int a)
{      

    time_t timer;
    struct tm x_years;
    struct tm* current;
   
    srand (time(NULL));
   
    
    int randomDays = (rand()%30)+1;


    time(&timer);  /* get current time; same as: timer = time(NULL)  */
    current = localtime(&timer);
    x_years.tm_hour = 0;
    x_years.tm_min = 0;
    x_years.tm_sec = 0;
    x_years.tm_year = current->tm_year;
    x_years.tm_mon = current->tm_mon; 
    x_years.tm_mday = (current->tm_mday - randomDays) <= 0 ? current->tm_mday + (30-randomDays) : current->tm_mday + randomDays;

    //returns seconds ever since the random generated date until now
  
    cout<<"today's date: ";
    cout<< current->tm_mday<< "/" << (current->tm_mon)+1 << "/" <<  current->tm_year+1900 <<endl;    
   
    cout << endl;

    cout<<"generating date";
    for(int i=0;i<3;i++)
    {
        cout<<".";
        Sleep(2000);
    }

    cout<<endl<<"date generated: ";
     
      for(int i=0;i<3;i++)
    {
        cout<<" ";
        Sleep(2000);
    }
    cout<<endl;
    cout<<"you can have your booster doze on: ";
    e[a].d.dayy=x_years.tm_mday;
    e[a].d.monthh= (x_years.tm_mon)+1;
    e[a].d.yearr=x_years.tm_year+1900;
    
    cout<<e[a].d.dayy<<"/"<<e[a].d.monthh<<"/"<<e[a].d.yearr<<endl;
        
         for(int i=0;i<7;i++)
    {
        cout<<" ";
        Sleep(2000);
    }
    date_flag=1;
}

void user_end(int a)
{   int b,c;
  bjorn:
    system("CLS");
    cout<<"welcome "<< e[a].name<<setw(25)<<"aadhar no: "<<e[a].aadhar_no<<endl;
    cout<<endl;
    cout<<setw(5)<<"age: "<<e[a].age<<endl;
    cout<<setw(5)<<"address: "<<e[a].address<<endl;
    cout<<setw(5)<<"mobile no: "<<e[a].mobile_no<<endl;
    cout<<setw(5)<<"mail-id: "<<e[a].email<<endl;
    cout<<endl;
    cout<<"press 1 to check your booking status"<<endl;
    cout<<"press 2 to log out"<<endl;
    cin>>b;
    switch(b)
    {
        case 1:

           if(date_flag==1)
     {
    cout<<"date appointed: YES"<<endl;
    cout<<"you can visit your nearby covid vaccine centre on "<<e[a].d.dayy<<"/"<<e[a].d.monthh<<"/"<<e[a].d.yearr<<endl;
     }
    else
    {
        ragnar:
    cout<<"date appointed: NO"<<endl;
    cout<<"press 1 to book a date"<<endl;
    cin>>c;
    if(c==1)
    {
        generate_date(a);
    }
    else
    {
    cout<<"invalid choice: please select again";
    for(int i=0;i<3;i++)
    {
        cout<<".";
        Sleep(2000);
    }
    goto ragnar;
    }
   
   break;

   case 2:
   signin();
   break;
   default:
   cout<<"invalid choice: please select again";
    for(int i=0;i<3;i++)
    {
        cout<<".";
        Sleep(2000);
    }
    goto bjorn;
    break;


}


    }
}
    