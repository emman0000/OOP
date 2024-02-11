//Programmer Emman Ali-23k0051 LAB02 Task 2
#include<iostream>
#include<string>
using namespace std;
//created a structure here for book and included the variables with a range of data types.
struct Book{
    string title; string author; int year; string genre;  
};//end struct
//Function to display previously added books already in the system (straightforward)
void displayBook(const Book& book){
  cout<<" Title of the Book: "<<book.title<<endl; cout<<" Author of the Book:"<<book.author<<endl; cout<<" Year of Publishing:"<<book.year<<endl; cout<<" Genre of the Book:\n"<<book.genre<<endl;
}//end function 

//function to search book either by title or by author name uses bool and compares the stored data itself. Could have used a strlen method too.
void searchBook(const Book books[], int s, const string& comp){
bool exists = false; for(int i=0; i<s; i++){
  if(books[i].title==comp || books[i].author==comp){ displayBook(books[i]); exists = true;}}//end loop
if (!exists) {cout<<"No book found with the given title or author."<<endl;}
}//end function

//function to add a new book to the system (straightforward)
void addABook(Book books[], int&NoOfBooks){
  int addedBooks; cout<<"Enter the number of books you want to add:"; cin>>addedBooks; cin.ignore();
//loop for adding books 
  for(int i=0; i<addedBooks; i++){ cout<<"Details for Book Number: "<<i+1<<endl;
  cout<<"Enter Book Title: "; getline(cin,books[NoOfBooks].title);
  cout<<"Enter Author's Name: "; getline(cin,books[NoOfBooks].author);
  cout<<"Enter Year of Publishing: "; cin>>books[NoOfBooks].year; 
  cin.ignore(); //to help prevent the next getline from taking the enter as input.
  cout<<"Enter the Genre of the Book: \n"; getline(cin,books[addedBooks].genre);  //increment number of books 
 NoOfBooks++;}//end loop
}//end function
//Function to display all the new books added in the array                
void AllBooks(const Book books[], int NoOfBooks){
  cout<<"Books in the Inventory are: "<<endl; for(int i=0; i<NoOfBooks; i++){
  displayBook(books[i]);}}//end function
//main function starts
int main () {
const int Total_Capacity = 7; //total capacity of the array allows size of array to remain fixed whilst code is running
Book books[Total_Capacity]; int NoOfBooks = 0; //NoOfBooks when user is yet to add any books.

 books[NoOfBooks++] = {"Are You Afraid Of The Dark?", "Sidney Sheldon", 2004, "Thriller"};
 books[NoOfBooks++] = {"IT", "Stephen King", 1986, "Horror"};

  AllBooks(books, NoOfBooks); //display all the books in the system)
  string comp; cout << "Search for book using title or author's name: ";
  getline(cin, comp);  searchBook(books, NoOfBooks, comp);

  addABook(books , NoOfBooks); AllBooks(books , NoOfBooks);
}//end main
