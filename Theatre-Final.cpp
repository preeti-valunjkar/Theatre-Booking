#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstring>

class theatre
{
 char mname[20], genre[20], location[20], desc[60];
 int hour, minutes, duration;
 float price;

 public:

 void indata();
 void outdata();
 int retname(char s[20]);
 int retgenre(char s[20]);
 int retloc(char s[20]);
 void rettime();
 int retdura();
 float retprice();
 void updt(int n);
} s;

void clrscr() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}


void theatre::indata()
{
 std::cout<<"\nEnter name of movie: ";
 gets(mname);
 std::cout<<"\nEnter genre: ";
 gets(genre);
 std::cout<<"\nDescription (if any): ";
 gets(desc);
 std::cout<<"\nEnter show timings(Hours:Minutes): ";
 std::cin>>hour>>minutes;
 std::cout<<"\nEnter duration in minutes: ";
 std::cin>>duration;
 std::cout<<"\nEnter location of the screening: ";
 gets(location);
 std::cout<<"\nEnter price of ticket: ";
 std::cin>>price;
}

void theatre::outdata() {
 std::cout<<"Name: "<<mname;
 std::cout<<"\nGenre: "<<genre;
 std::cout<<"\nDescription: "<<desc;
 std::cout<<"\nShow Timing: "<<hour<<":"<<minutes;
 std::cout<<"\nDuration: "<<duration;
 std::cout<<"\nLocation: "<<location;
 std::cout<<"\nTicket Price: "<<price<<std::endl<<std::endl;
}


int theatre::retname(char s[20]) {
 if(strcmpi(mname,s)==0)
  return 1;
 else
  return 2;
}


int theatre::retgenre(char s[20]) {
 if(strcmpi(genre,s)==0)
 return 1;
}


int theatre::retloc(char s[20]) {
 if(strcmpi(location,s)==0)
 return 1;
}


void theatre::rettime() {
 std::cout<<hour<<":"<<minutes<<std::endl;
}


int theatre::retdura() {
 return (duration);
}


float theatre::retprice() {
 return(price);
}

void theatre::updt(int n) {
 price=n;
}


void book()
{char arr[15][15] =
    {
        {'A','1','2','3','4','5','6','7','8','9'},
        {'B','1','2','3','4','5','6','7','8','9'},
        {'C','1','2','3','4','5','6','7','8','9'},
        {'D','1','2','3','4','5','6','7','8','9'},
        {'E','1','2','3','4','5','6','7','8','9'},
        {'F','1','2','3','4','5','6','7','8','9'}

    };
   int i, j;
   std::cout<<"SCREEN HERE"<<std::endl;
   for(i=0; i<15; i++)
	{
		for(j=0; j<15; j++)
		{
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<"\n";
	}
   char row;
   int seatno, temp;
   std::cout<<"Enter row: ";
   std::cin>>row;
   std::cout<<"Enter seat number: ";
   std::cin>>seatno;
   switch(row)
   {
    case 'A':temp=0;
             break;
    case 'B':temp=1;
             break;
    case 'C':temp=2;
             break;
    case 'D':temp=3;
             break;
    case 'E':temp=4;
             break;
    case 'F':temp=5;
             break;
   }
	arr[temp][seatno]='X';
   std::cout<<"\nSCREEN HERE"<<std::endl;
   for(i=0; i<15; i++)
	{
		for(j=0; j<15; j++)
		{
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	getch();
 std::cout<<"\nBooking Done";
}

void check() {
 std::cout<<"\nChecked and displayed";
}

void add() {
 std::ofstream o1;
 o1.open("Movies.dat", std::ios::binary|std::ios::app);
 std::cout<<"\nEnter data of new movie: \n";
 s.indata();
 o1.write((char *)&s,sizeof(s));
 o1.close();
}

void disp() {
 std::ifstream i1;
 i1.open("Movies.dat", std::ios::binary);
 std::cout<<std::endl<<"\nList of current movies \n"<<std::endl<<std::endl;
 while(i1.read((char *)&s,sizeof(s)))
 {
  s.outdata();
  std::cout<<std::endl<<"\n";
 }
 i1.close();
}

void dele() {
 char na[20];
 std::ifstream i1;
 std::ofstream o1;
 i1.open("Movies.dat", std::ios::binary);
 o1.open("New.dat", std::ios::binary);
 std::cout<<"\nEnter name of the movie to be removed: ";
 gets(na);
 while(i1.read((char *)&s, sizeof(s)))
 {
  if(s.retname(na)==2)
  o1.write((char *)&s, sizeof(s));
 }
 i1.close();
 o1.close();
 remove("Movies.dat");
 rename("New.dat","Movies.dat");
 std::cout<<"\nMovie removed";
}

void search()
{
 char na[20];
 std::ifstream i1;
 i1.open("Movies.dat", std::ios::binary);
 std::cout<<"\nEnter movie to be searched: ";
 gets(na);
 while(i1.read((char *)&s,sizeof(s)))
 {
  if(s.retname(na)==1)
   s.outdata();
 }
 i1.close();
}

void locate()
{
 char loc[20];
 std::ifstream i1;
 i1.open("Movies.dat", std::ios::binary);
 std::cout<<"\nEnter preferred location: ";
 gets(loc);
 while(i1.read((char *)&s,sizeof(s)))
 {
  if(s.retloc(loc)==1)
  s.outdata();
 }
 i1.close();
}

void findg()
{
 char gen[20];
 std::ifstream i1;
 i1.open("Movies.dat", std::ios::binary);
 std::cout<<"\nEnter preferred genre: ";
 gets(gen);
 while(i1.read((char *)&s,sizeof(s)))
 {
  if(s.retgenre(gen)==1)
  s.outdata();
 }
 i1.close();
}

void update()
{
 int pr, newpr;
 char na[20];
 std::ifstream i1;
 std::ofstream o1;
 i1.open("Movies.dat", std::ios::binary);
 o1.open("Movies.dat", std::ios::binary|std::ios::ate);
 std::cout<<"\nEnter movie whose price is to be modified: ";
 gets(na);
 std::cout<<"\nEnter price to be modified: ";
 std::cin>>pr;
 std::cout<<"\nEnter new price: ";
 std::cin>>newpr;
 while(i1.read((char *)&s,sizeof(s)))
 {
  if(s.retprice()==pr && s.retname(na)==1)
  {
   o1.seekp(i1.tellg()-sizeof(s));
   s.updt(newpr);
   o1.write((char *)&s,sizeof(s));
  }
 }
 i1.close();
 o1.close();
}


int main()
{
 int choice1,choice2;
 char ch;
 std::cout<<"\t\t\t\t\tWELCOME TO A.P.T CINEMAS!";
 std::cout<<"\n\nSelect from the below choices: ";
 std::cout<<"\n1.Customer ";
 std::cout<<"\n2.Staff ";
 std::cout<<"\nEnter type of user: ";
 std::cin>>choice1;
 if(choice1==1)
 {
  do
  {
   clrscr();
   std::cout<<"Select from the below choices: ";
   std::cout<<"\n1.Book a seat ";
   std::cout<<"\n2.Check booking ";
   std::cout<<"\n3.View list of movies ";
   std::cout<<"\n4.Search a movie ";
   std::cout<<"\n5.Find movies at your location ";
   std::cout<<"\n6.Search movies in preferred genre ";
   std::cout<<"\nEnter choice: ";
   std::cin>>choice2;
   switch(choice2)
   {
    case 1:book();
           break;
    case 2:check();
           break;
    case 3:disp();
           break;
    case 4:search();
           break;
    case 5:locate();
           break;
    case 6:findg();
           break;
   }
   std::cout<<"\nDo you wish to continue?";
   std::cin>>ch;
  }while(ch=='y'||ch=='Y');
 }
 else if(choice1==2)
 {
  do
  {
   clrscr();
   std::cout<<"Select from below choices: ";
   std::cout<<"\n1.Add movies to list ";
   std::cout<<"\n2.Display list of movies available ";
   std::cout<<"\n3.Remove old movies ";
   std::cout<<"\n4.Update prices ";
   std::cout<<"\nEnter choice: ";
   std::cin>>choice2;
   switch(choice2)
   {
    case 1:add();
           break;
    case 2:disp();
           break;
    case 3:dele();
           break;
    case 4:update();
           break;
   }
   std::cout<<"\nDo you wish to continue?";
   std::cin>>ch;
  }while(ch=='y'||ch=='Y');
 }
getch();
return 0;
}
