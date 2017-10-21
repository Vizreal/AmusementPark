#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<ctype.h>
class rides
 {
  public:
  char nameofride[20];
  float height;
  int   maint;
  int cost,ir;
  int total;
  int notu;
  int profit;
  void ride()
   {
    cout<<"Ride Code(integer value) - ";
    cin>>ir;
    cout<<"Enter the name of the ride:";
    cin>>nameofride;
    cout<<"Enter the height required(Inches):";
    cin>>height;
    cout<<"Enter daily maintainance charge Rs.";
    cin>>maint;
    cout<<"Enter the cost per ride Rs.";
    cin>>cost;
   }
  void dispride()
   {
    cout<<"Ride Code is "<<ir;
    cout<<"\nName- "<<nameofride;
    cout<<"\nHeight Required(Inches)- "<<height;
    cout<<"\nDaily maintainance charge is Rs."<<maint;
    cout<<"\nCost per ride is Rs."<<cost;
    cout<<"\nTodays Profit is "<<profit;
   }
  void report()
   {
    cout<<"Ride Code "<<ir<<"\nEnter the number of times used today- ";
    cin>>notu;
    total=cost*notu;
    profit=total-maint;
   }
 }r;
class food
 {
  public:
  int earn,rent,pr;
  void store()
   {
    cout<<"Enter the amount earned by the food court in the month - Rs.";
    cin>>earn;
    cout<<"\nEnter the daily maintainance charges - Rs.";
    cin>>rent;
    pr=earn-rent;
    cout<<"\nTodays profit is Rs."<<pr;
   }
 }food;
class card
 {
  public:
  char name[50];
  int age;
  char address[100];
  int security;
  int i;
  int amount;
  int t;
  int height;
  void enter()
   {
    cout<<"ID (integer) - ";
    cin>>i;
    cout<<"Enter the name:";
    gets(name);
    cout<<"Age:";
    cin>>age;
    cout<<"Height(inches):";
    cin>>height;
    cout<<"Address:";
    gets(address);
    cout<<"Enter the amount(Rs.100 will be deducted as card security):";
    cin>>t;
    amount=t-100;
    security=t-amount;
   }
  void disp()
   {
    cout<<"\n"<<i<<"\nNAME-";
    puts(name);
    cout<<"AGE-"<<age<<"\nHEIGHT-";
    cout<<height<<"\nADDRESS-";
    puts(address);
    cout<<"AMOUNT-"<<amount;
   }
 }c;
void main()
 {clrscr();
  int ch1,am,id,flag;
  fstream f,g,h;
  do
   {
    cout<<"\n\t\t\tThe Amusement Park\t\t\t\t\t\t\t\t New Delhi-110017\n";
    cout<<"\n\nChoose from menu:\n1.Making a card\n2.Adding value\n3.Deleting the card\n4.Display a card record\n5.Create a ride\n6.Enter daily report\n7.Display ride record\n8.Food store\n9.Exit\n";
    cin>>ch1;
    switch(ch1)
     {
      case 1:
       clrscr();
       f.open("card.data",ios::app,ios::binary);
       c.enter();
       f.write((char*)&c,sizeof(c));
       f.close();
       break;
      case 2:
       clrscr();
       cout<<"Enter the ID:";
       cin>>id;
       cout<<"Enter the amount";
       cin>>am;
       flag=0;
       f.open("card.data",ios::in,ios::binary);
       g.open("temp.data",ios::out,ios::binary);
       while(!f.eof())
	{
	 f.read((char*)&c,sizeof(c));
	 if(c.i==id)
	  {
	   flag=1;
	   c.amount=c.amount+am;
	   cout<<"Now your total amount is "<<c.amount;
	  }
	 if (f.eof())
	 break;
	 g.write((char*)&c,sizeof(c));
	}
       if (flag==0)
	cout<<"Record not found!!!";
       f.close();
       g.close();
       remove("card.data");
       rename("temp.data","card.data");
       break;
      case 3:
       clrscr();
       flag=0;
       f.open("card.data",ios::in,ios::binary);
       g.open("temp.data",ios::out,ios::binary);
       cout<<"Enter the ID:";
       cin>>id;
       while(!f.eof())
	{
	 f.read((char*)&c,sizeof(c));
	 if(c.i==id)
	  {
	   am=c.amount;
	   f.read((char*)&c,sizeof(c));
	   flag=1;
	  }
	 g.write((char*)&c,sizeof(c));
	 if(f.eof())
	 break;
	}
       if (flag==0)
       cout<<"Record not found!!!";
       else
       cout<<"You get "<<am;
       f.close();
       g.close();
       remove("card.data");
       rename("temp.data","card.data");
       break;
      case 4:
       clrscr();
       flag=0;
       f.open("card.data",ios::in,ios::binary);
       cout<<"Your ID is:";
       cin>>id;
       while(!f.eof())
	{
	 f.read((char*)&c,sizeof(c));
	 if (f.eof())
	  break;
	 if(c.i==id)
	  {
	   flag=1;
	   c.disp();
	  }
	}
       if (flag==0)
       cout<<"Record not found!!!";
       f.close();
       break;
      case 5:
       clrscr();
       f.open("rides.data",ios::app,ios::binary);
       r.ride();
       f.write((char*)&r,sizeof(r));
       f.close();
       break;
      case 6:
       clrscr();				 //Adding notu value
       cout<<"Enter the ride code:";
       cin>>id;
       flag=0;
       f.open("rides.data",ios::in,ios::binary);
       g.open("temp.data",ios::out,ios::binary);
       while(!f.eof())
	{
	 f.read((char*)&r,sizeof(r));
	 if (f.eof())
	 break;
	 if(r.ir==id)
	  {
	   flag=1;
	   r.report();
	  }

	 g.write((char*)&r,sizeof(r));
	}
       if (flag==0)
       cout<<"Record not found!!!";
       f.close();
       g.close();
       remove("rides.data");
       rename("temp.data","rides.data");
       break;
      case 7:
       clrscr();
       flag=0;
       f.open("rides.data",ios::in,ios::binary);
       cout<<"Ride code is";
       cin>>id;
       while(!f.eof())
	{
	 f.read((char*)&r,sizeof(r));
	 if(r.ir==id)
	  {
	   if(r.notu==0)
	    {
	     cout<<"Add number of times used first";
	     goto p;
	    }
	   flag=1;
	   r.dispride();
	  }
	 if(f.eof())
	  break;
	}
       if (flag==0)
       cout<<"Record not found!!!";
       p:
       f.close();
       break;
      case 8:
       clrscr();
       f.open("food.data",ios::app,ios::binary);
       food.store();
       f.write((char*)&food,sizeof(food));
       f.close();
       break;
      case 9:
       exit(0);
      default:
       cout<<"\nEnter a valid choice";
     }
   }while(ch1<=9);
 }









