//Programmer Emman Abrar Ali 23k0051 Lab04 Task5
#include<string>
#include<iostream>
using namespace std;
class Office{
string Location; int SeatingCapacity; string *Furniture; //this is a pointer for the array we will assign this to because the question said so.
  public:
  //Para constructor 
  Office (string location = " ", int seatingcapacity = 0 , int NoOfFurniture = 3) : Location(location), SeatingCapacity(seatingcapacity){
      Furniture = new string[NoOfFurniture];//Dynamically allocate memory 
      for (int i=0; i<NoOfFurniture; i++){
          Furniture[i] = " ";
      }//for loop ends here 
  }//end of our constructor (no member initialiser list used here)

  //Deallocation method (basically just a destructor usually a default one exist but for this case we are manually writing one )
  ~Office(){ delete [] Furniture;} 

  void display(){
  cout<<"Location of the Office is: "<<Location<<endl; cout<<"The seating capacity:"<<SeatingCapacity<<endl;cout<<"The Furniture present: ";for(int i=0; i<3; i++){ cout<< Furniture[i]<<" ";} cout<<endl; }//end of function


  };//end of class
 int main(){
Office *PepsiCola = new Office("Clifton Block 3", 60); 
cout<<"Office Details: "<<endl; PepsiCola->display(); 
delete PepsiCola;
return 0;
 }//end main
