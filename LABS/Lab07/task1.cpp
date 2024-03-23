 //Book task1 
 //Programmer Emman Abrar Ali 23k0051

 #include<iostream>
 #include<string>
 using namespace std;

 class Book{
 string title; string author; string publisher;
 public:
 Book(string t, string a, string p): title(t), author(a), publisher(p){}//end construtor
 //getters and setters for each of the data members
 string getTitle()const{return title;}
 string getAuthor()const{return author;}
 string getPublisher()const{return publisher;}

 void settitle(string t){title=t;}
 void setauthor(string a){author=a;}
 void setpublisher(string p){publisher = p;}

 //function to display book details

 void display(){
   cout<<"Title: "<<title<<endl;
   cout<<"Author: "<<author<<endl;
   cout<<"Publisher: "<<publisher<<endl;
 }//end function 
 };//end class

 class FictionBook : public Book{
 string genre; string protagonist;
 public:
 FictionBook(string g, string pr, string t, string a, string p): genre(g), protagonist(pr),Book(t,a,p) {}//end of constructor

 //display function
 void display(){
   Book :: display();
   cout<<"Genre: "<<genre<<endl;
   cout<<"Protagonist: "<<protagonist<<endl;
 }//end function 


 };//end class 

int main (){
 FictionBook book1("Dork Diaries", "Renne Russell", "Young Adult", "Nikki" ,"Penguin Books" );
  book1.display();


  return 0;
