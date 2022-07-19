#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
bool match(int file_no , int no)
{
    if(file_no==no) 
    return true;
    else
    return false;
}
int main()
{
    ifstream in_file;
    unsigned long long int no{};
    unsigned long long int file_no{};
    in_file.open("directory.txt");
    int totalnos{0};
    int choice{};
   
    int flag{0};

    if(!in_file)
    {
        cerr<<"error opening file"<<endl;
        return 1;
    }
    cout<<"enter your mobile no"<<endl;
 cin>>no;
    while(in_file>>file_no)
    {
totalnos++;
   if(match(file_no,no))
   flag=1;


    }
    
    cout<<"total numbers in  the directory"<<"\t"<<totalnos<<endl;
    if(flag==1)
    cout<<"user already registered:"<<"\t"<<endl;
    else{
    cout<<"you are not registered"<<endl;
    cout<<"to register press 1"<<endl<<"to end this press 0"<<endl;
    cin>>choice;
    if(choice==0)
    exit(0);
    }
    
    
    return 0; 
}