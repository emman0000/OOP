//game task 2 
//Porgrammer Emman Abrar Ali 23k0051
 #include<iostream>
 #include<string>
 using namespace std;

class Character{
int health; int damage; 
public:
Character(int h, int d): health(h), damage(d){}
//fucntion to display health and damage
//getter and setters
int gethealth()const{return health;}
int getdamage()const{return damage;}

void  sethealth(int h){health=h;}
void  setdamage(int d){damage=d;}


void display(){
  cout<<"Health: "<<health<<endl;
  cout<<"Damage: "<<damage<<endl;
}//end of function
};//end of class character

class Enemy : public Character{
public:
Enemy(int h, int d): Character(h,d){}//end 

//function to display 
void display(){
  cout<<"Health: "<<gethealth()<<endl;
  cout<<"Damage: "<<getdamage()<<endl;
}//end function
};//end class enemy

class Player :public Character{
public:
Player(int h, int d): Character(h,d){}//end construtor

void display(){
  cout<<"Health: "<<gethealth()<<endl;
  cout<<"Damage: "<<getdamage()<<endl;
}//end function
};//end class player

class Wizard: public Player{
int magicpower;  string spells; 
public:
Wizard(int h, int d, int mp, string s): Player(h,d), magicpower(mp), spells(s){}
//end constructor

void display(){
  cout<<"Health: "<<gethealth()<<endl; cout<<"Damage: "<<getdamage()<<endl; cout<<"Magic Power: "<<magicpower<<endl; cout<<"Spells: "<<spells<<endl;
}
};//end class  Wizard

int main(){
Wizard W1(100,20,50,"Fireball");
  W1.display();

  return 0;
}//end main 
