#include <iostream>
#include <stdlib.h>
#include <fstream>


using namespace std;

int seat(int n,int x){
    int y;
    int a[] ={101,105,103,102,121,124,123,126,112,115,117};
    int s[10];

     for(int j=0; j<=10;j++){
        if(a[j]==n){                 //calculation of the remaining seats out of 20
            y = 20-x;
            s[j] = y;
            }
     }

    return y;    //returns remaining seats
}

struct passenger {
    char name[20];
    char gender;
    char email[50];
    int age;
}p[50];

void data(int x){
     // saving all the personal information using structure
 fstream new_file;
      new_file.open("new_file_write.txt",ios::out);
      if(!new_file)
      {
        cout<<"File creation failed";
      }
     else{
    new_file<<"Learning File handling";
    for(int i=0; i<x; i++){
         cout <<"\n\n\t\t\t"<<"Enter name: ";
           cin >> p[i].name;
           new_file<<"\n"<<p[i].name<<endl;

         cout <<"\t\t\t"<< "Enter gender: ";
           cin >> p[i].gender;
           new_file<<p[i].gender<<endl;

         cout<<"\t\t\t" << "Enter email: ";
           cin >> p[i].email;
           new_file<<p[i].email<<endl;

         cout<<"\t\t\t" << "Enter age: ";
           cin >> p[i].age;
           new_file<<p[i].age<<endl;
           new_file.close();
        }
     }
}
int info(int n){

    int x,choice,y,b;

    //takes seats to book
  cout<<"\t\t"<<"maximum seats available is 20"<<endl;
  seats:
  cout<<"\t\t"<<"No.of seats to book: ";
  cin>>x;

cout<<"\n\n"<<endl<<"Press 1 to CONTINUE AND CONFIRM ticket."<<endl;

buttons:
cout<<"Press 2 to BOOK ANOTHER ticket."<<endl<<"Press 3 to EXIT. "<<endl;
cout<<"\n"<<"Enter your choice: ";
cin>>choice;

switch(choice){
//according to choices
case 1:
       y = seat(n,x);  //calls function seat

       if(y==0){
          cout<<"Seats NOT available."<<endl;
          goto seats;//if the returned seat is zero or less
         }
       cout<<"\n\t\t"<<"Enter personal information:-"<<endl;
       data(x);                                               //calls function data
       cout<<"\n"<<"Your seat has been confirmed."<<endl;
       cout<<" Seats available now:"<<y<<"\n"<<endl;
       goto buttons;     //goes to button label to provide with options again
       break;

case 2:
       b=0;
       break;

case 3:
      b=1;
      break;
}
return b;    // returns the value of b to int main
}

int main(){

    char from[100],to[100];
    int n,b,o;

    cout<<"\t\t"<<"BUS TICKET RESERVATION IN MAHARASHTRA(DIVISIONS)"<<endl;
    origin:

  cout<<"\n"<<"(In lowercase)"<<endl;
    cout<<"From: ";
    cin>>from;                           //ORIGIN AND DESTINATION USER INPUT
    cout<<"To: ";
    cin>>to;
     //PLACES (DIVISIONS) NOT IN MAHARASHTRA
      if(to[0]=='e'|| to[0]=='f'|| to[0]=='g'|| to[0]=='h'|| to[0]=='i'|| to[0]=='q'
         || to[0]=='x'|| to[0]=='y'|| to[0]=='z')
     {
         cout<<"\t\t"<<"THE DESTINATION IS NOT IN MAHARASHTRA"<<endl;
         goto origin;     //GOES TO FIRST 1
     }

     cout<<"\t\t\t"<<"BUSES AVAILABLE"<<endl;
     cout<<"\t\t\t"<<"---------------"<<endl;

     cout<<"\t\t"<<"Bus Number:- "<<"\t\t"<<"Time:- "<<endl;
     cout<<"\t"<<"=================================================="<<endl;

     //PLACES IN MAHARASHTRA

     if(to[0]=='r'|| to[0]=='s'|| to[0]=='t'|| to[0]=='k'|| to[0]=='m')    //checks Starting letter of destination
     {
         //shows bus numbers and timings
         cout<<"\t\t"<<"101"<<"\t\t\t"<<"6:30am"<<"\n\t\t"<<"105"<<"\t\t\t"<<"7:45am" <<"\n\t\t"<<"103"<<"\t\t\t"<<"9:00am"
                  <<"\n\t\t"<<"102"<<"\t\t\t"<<"8:00pm"<<endl;

         cout<<"Select a bus number: ";
         number:
         cin>>n;
         //select bus number from the list
                if(101<=n&&n<=106)
                    {
                       b = info(n);   //calls function info and passes argument n(bus number)

                    }

                else {
                        cout<<"Wrong bus number."<<endl;
                        cout<<"Select bus number: ";
                        goto number;     //goes to bus.no selection
                  }
    }

    //same as before
     if(to[0]=='a'|| to[0]=='v'|| to[0]=='w'|| to[0]=='b'|| to[0]=='c'|| to[0]=='p')
     {
         cout<<"\t\t"<<"121"<<"\t\t\t"<<"7:30am"<<"\n\t\t"<<"124"<<"\t\t\t"<<"8:45am"<<"\n\t\t"<<"123"<<"\t\t\t"<<"9:00am"
               <<"\n\t\t"<<"126"<<"\t\t\t"<<"9:30pm"<<endl<<endl;


         cout<<"Select a bus number: ";
          num:
         cin>>n;
         if(120<=n&&n<=126){

              b= info(n);
         }
           else {
                cout<<"Wrong bus number."<<endl;
                 cout<<"Select bus number: ";
                    goto num;
           }

     }

     //same as before
     if(to[0]=='d'|| to[0]=='j'|| to[0]=='l'|| to[0]=='n'|| to[0]=='o'|| to[0]=='u')
     {
         cout<<"\t\t"<<"112"<<"\t\t\t"<<"6:00am"<<"\n\t\t"<<"115"<<"\t\t\t"<<"7:15am"<<"\n\t\t"<<"117"<<"\t\t\t"<<"9:20pm"<<endl;

         cout<<"Select a bus number: ";
         val:
         cin>>n;
         if(111<=n&&n<=117){

                b= info(n);
         }
           else {
            cout<<"Wrong bus number."<<endl;
                 cout<<"Select bus number: ";
                goto val;
           }
    }

     if(b==0){
              goto origin;     //goes to origin label to continue booking
            }
    else{
          exit;             //quits the whole program
        }
return 0;
}

