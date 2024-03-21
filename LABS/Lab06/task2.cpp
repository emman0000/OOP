//image handling task 2
//Porgrammer Emman Abrar Ali 23k0051
#include<iostream>
#include<string>
using namespace std;

class Image{
int width; int height; int* imagedata; //represents the image data stored in memory
public:
//constructor
Image(int w, int h,int* d): width(w), height(h){
  imagedata = new int [w*h];
  for(int i=0; i<w*h; i++){
    imagedata[i]=d[i];
  }//end of for loop  
}//end of constructor
//copy construtor 
Image (const Image &other) : width(other.width),height(other.height){
  imagedata = new int [width*height];
  for(int i=0; i<width*height; i++){
    imagedata[i]=other.imagedata[i];
  }//end of for loop
}//end of copy constructor
//deconstructor
~Image(){ delete [] imagedata;}//end of deconstructor

//function to display
void displayImage()const{
  for(int i=0; i<width*height; i++){
    cout<<imagedata[i]<<" "; cout<<" "; 
  }//end for loop
  cout<<endl; 
}//end of function to display

//function to update
void update(int* newdata){
  for(int i=0;  i<width*height; i++){
    if(newdata[i]<=0){
      imagedata[i]=rand()%255+1;
    }
    else { imagedata [i] = newdata[i];}

  }//end of loop
}//end of function to update

};//end class Image 

int main(){
Image image1(2,3, new int[6]{1,2,3,4,5,6});
Image image2=image1;
 //display inital pictures 
 cout<<"Initial images: "<<endl;
image1.displayImage();
image2.displayImage();
cout<<"\n"<<"------------------------------"<<endl;
cout<<"Updated images:"<<endl;
//update and display again 
image1.update(new int[4]{5,6,7,8});
image1.displayImage();
image2.displayImage();
  return 0;
}//end of main 
