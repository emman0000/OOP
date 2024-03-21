//hair salon task 3
//Programmer Emman Abrar Ali 23k0051
#include<iostream>
#include<string>
using namespace std;

class Appointment{
string name; string phoneNumber; string date; string typeofwork; int price=0;
static int numOfAppointments; static int totalearnings; //static data members declared 
public:
//constructor
Appointment(string n, string p, string d, string t, int pr):name(n), phoneNumber(p), date(d), typeofwork( 
t), price(pr){
  numOfAppointments++;
  totalearnings+=pr;

}//end of constructor 

//getter and setter for price since it can be changed but is a private data member 
int getPrice(){return price;}
void setPrice(int pr){price=pr;}

void display(){
  cout<<"Name: "<<name<<endl;
  cout<<"Phone Number: "<<phoneNumber<<endl;
  cout<<"Date: "<<date<<endl;
  cout<<"Type of work: "<<typeofwork<<endl;
  cout<<"Price: "<<price<<endl;
}//end function to display the details of the clients

static int calcaveragecost(){
  return totalearnings/numOfAppointments;
}//end function for average cost 

};//end of class appointment
int Appointment::numOfAppointments=0;
int Appointment::totalearnings=0;


int main (){
Appointment appointment1("Emman Abrar Ali", "0300-1234567", "12/12/2022", "haircut", 100);
Appointment appointment2("Areeba Hasnain", "0300-1234567", "12/12/2022", "blow-dry", 200);

//Show details of appointmens
appointment1.display();
appointment2.display();
 cout<<"\n ****************************"<<endl;
//calling static function to do its thing
cout<<"Average cost of appointments: "<<Appointment::calcaveragecost()<<endl;

  return 0;
}//end main
