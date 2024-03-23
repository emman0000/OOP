//game engine task 3
//Programmer Emman Abrar Ali 23k0051

#include<iostream>
#include<string>
using namespace std;

class Position{
int x; int y; int z;
public:
Position(int x, int y, int z){}//end constructor
int getX()const{return x;} int getY()const{return y;} int getZ()const{return z;}
void coordinate(int x , int y, int z){
  cout<<x<<","<<y<<","<<z<<endl;
}//
};//end of class Position

class Health{
int health;
public:
Health(int h): health(h){}  //end 
int gethealth(){return health;}
};//end class health

class Character : public Position , public Health{
string name; string weapon; int damage;
public:
Character(string n , string w, int d, int x, int y, int z): Position(x,y,z), Health(100), name(n), weapon(w), damage(d){}//end 

void display(){
  cout<<"Name: "<<name<<endl; cout<<"Weapon: "<<weapon<<endl; cout<<"Damage: "<<damage<<endl; cout<<"Health: "<<gethealth()<<endl;

}
};//end of class Player 

int main(){
Character Character1("Emman Abrar Ali", "Sword", 50, 0, 0, 0);
Character1.display();
  return 0;
}//end main 
