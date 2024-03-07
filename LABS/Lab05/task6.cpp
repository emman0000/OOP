//Task 06 Lab05 23k0051 Emman Abrar Ali
#include<iostream>
#include<string>
using namespace std;

class GraphicsEngine{
public:
void renderGraphicsEngine(){
  cout<<"Graphics Engine is rendering graphics... "<<endl;
}//end function
};//end the class 

class InputHandler{
public:
void handleInput(){
  cout<<"Input Handler is handling the input... "<<endl;
}//end function
};//end class Input Handler

class PhysicsEngine{
public:
void handlePhysics(){
cout<<"Physics Engine is handling the physics... "<<endl;/
}//end function
};//end of class Physics Engine

class GameEngine{
GraphicsEngine graphicwalaengine;
InputHandler inputwalahandler;
PhysicsEngine physicswalaengine;

public:
void startgame(){

  graphicwalaengine.renderGraphicsEngine();
  inputwalahandler.handleInput();
  physicswalaengine.handlePhysics();

}//end function
};//end class  Engine

int main (){
cout<<"Emman Abrar Ali 23k0051"<<endl;
GameEngine gameengine;
  gameengine.startgame();
  return 0;
}//end main
