//Programmer Emman Ali lab10 task 1 
#include<iostream>
#include<string>
using namespace std;

class convert{
protected : float val1; float val2;
public:
convert(float v1, float v2):val1(v1),val2(v2){}

virtual float compute();//end function 

};//end class 

//derived class 

class ltog : public convert{
public:
ltog(float v1):convert(v1,0){}
float compute()override{
    val2 = val1*0.264172;
    return val2;

}//end function 
};//end class 

class ftoc: public convert {
    public:
    ftoc(float v1) :convert(v1,0){}
    float compute()override{
val2 = (val1-32)* 5/9;
return val2;
    }//end function
};//end class 

int main(){
ltog *ltogpointer = new ltog(4);
ftoc *ftocpointer = new ftoc(70);

cout<<"4 LTR -> Gallons: "<<ltogpointer->compute()<<endl;
cout<<"70 F -> C: "<<ftocpointer->compute()<<endl;
    return 0;
}//end main 


