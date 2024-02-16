//Programmer Emman Ali-23k0051 LAB03-Task4 
#include<string>
#include <iostream>
using namespace std;

class Smartphone {
    string brand; string model; string dr; int Ram; int Rom; int strg; 
    public:
    void setbrand(string b){ brand = b;}
    void setmodel(string m){model=m;}
    void setdisplay(string d){dr=d;}
    void setRam(int ram){Ram=ram;}
    void setRom(int rom){ Rom=rom;}
    void setStorage(int s){ strg=s;}

    string getbrand(){return brand;} string getmodel(){return model;} string getdisplay(){return dr;} int getRam(){return Ram;} int getRom(){return Rom;} int getstorage(){return strg;} 
    void phonecall(){ cout<< "Calling..."<<endl;}
    void sendmsgs(){cout<<"Sending Message..."<<endl;}
    void wificonnection(){cout<<"Connecting to network..."<<endl;}
    void browse(){cout<<"Searching..."<<endl;}
};//ending class

int main() {
Smartphone Phone1; Smartphone Phone2; Smartphone Phone3;
//set it 1
Phone1.setbrand("Apple"); Phone1.setmodel("Iphone 13"); Phone1.setdisplay("Super nice! :)"); Phone1.setRam(6); Phone1.setRom(128); Phone1.setStorage(128);

//set it 2
Phone2.setbrand("Apple"); Phone2.setmodel("Iphone 15"); Phone2.setdisplay("Super nice! :)"); Phone2.setRam(8); Phone2.setRom(256); Phone2.setStorage(256);

//set it 3
Phone3.setbrand("Apple"); Phone3.setmodel("Iphone 14"); Phone3.setdisplay("Super nice! :)"); Phone3.setRam(6); Phone3.setRom(128); Phone3.setStorage(128);

  //get it 
  cout<<"Brand of the Phone is: "<<Phone1.getbrand()<<endl; cout<< "Model of the Phone is: "<<Phone1.getmodel()<<endl; cout<<"Display of the Phone is:"<<Phone1.getdisplay()<<endl; cout<<"Ram of the Phone is: "<<Phone1.getRam()<<endl; cout<<"Rom of the Phone is: "<<Phone1.getRom()<<endl; cout<<"Storage of the Phone is:"<<Phone1.getstorage()<<endl; cout<<endl;

  cout<<"Brand of the Phone is: "<<Phone2.getbrand()<<endl; cout<< "Model of the Phone is: "<<Phone2.getmodel()<<endl; cout<<"Display of the Phone is:"<<Phone2.getdisplay()<<endl; cout<<"Ram of the Phone is: "<<Phone2.getRam()<<endl; cout<<"Rom of the Phone is: "<<Phone2.getRom()<<endl; cout<<"Storage of the Phone is:"<<Phone2.getstorage()<<endl; cout<<endl;

  cout<<"Brand of the Phone is: "<<Phone3.getbrand()<<endl; cout<< "Model of the Phone is: "<<Phone3.getmodel()<<endl; cout<<"Display of the Phone is:"<<Phone3.getdisplay()<<endl; cout<<"Ram of the Phone is: "<<Phone3.getRam()<<endl; cout<<"Rom of the Phone is: "<<Phone3.getRom()<<endl; cout<<"Storage of the Phone is:"<<Phone3.getstorage()<<endl; cout<<endl;

//functionality of each phone 
Phone1.phonecall(); Phone1.sendmsgs(); Phone1.wificonnection(); Phone1.browse(); cout<<endl;
Phone2.phonecall(); Phone2.sendmsgs(); Phone2.wificonnection(); Phone2.browse(); cout<<endl;
Phone3.phonecall(); Phone3.sendmsgs(); Phone3.wificonnection(); Phone3.browse(); cout<<endl;


    return 0;
}//end main 
