//Programmer Emman Abrar Ali 23k0051
// Social Media Task 4
#include <iostream>
#include <string>
using namespace std;
static const int MAX_FEED_SIZE = 10; //making a constant size for the number of pictures per account.

class Post {
protected:
    string postID; string postContent; int likes; string comments;

public:
    Post(const string& id, const string& pc, int l, const string& c)
        : postID(id), postContent(pc), likes(l), comments(c) {}//end 

    virtual void displayDetails() {
        cout<<"_____________________________________"<<endl;
        cout << "Post content: " << postContent << endl;
        cout << "Post ID: " << postID << endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << comments << endl;
        cout << endl;
         cout<<"_____________________________________"<<endl;
    }//end function 

    virtual ~Post() {} // virtual destructor to ensure proper cleanup of derived classes
};//end class

class User {
protected:
    string username; string email; string password;
 
 public:
    User(const string& username, const string& email, const string& password)
        : username(username), email(email), password(password) {}

    virtual void viewFeed() const = 0; // pure virtual function, making User an abstract class

    virtual ~User() {} // virtual destructor to ensure proper cleanup of derived classes
};//end class 

class RegularUser : public User {
protected:
    Post* feed[MAX_FEED_SIZE];
    int numPosts;

public:
    RegularUser(const string& username, const string& email, const string& password)
        : User(username, email, password), numPosts(0) {}

    void addToFeed(Post* post) {
        cout<<"Adding Post..."<<endl;
        if (numPosts < MAX_FEED_SIZE) {
            feed[numPosts++] = post;
            cout << "Post added successfully\n" << endl;
            cout<<"******************************"<<endl;
        } else {
            cout << "No more space available. Upgrade storage." << endl;
        }//end else 
    }//end function 

    void viewFeed() const override {
        cout << "Viewing feed for " << username << ":" << endl;
        for (int i = 0; i < numPosts; ++i) {
            feed[i]->displayDetails();
        }//end for loop
    }//end function 
};//end class 

class BusinessUser : public User {
public:
    BusinessUser(const string& username, const string& email, const string& password)
        : User(username, email, password) {}

    void promotePost(Post* post) {
        cout << "Trending today!" << endl;
        post->displayDetails();
    }//end function 

    void viewFeed() const override {
//empty function shows nothing just kept it there 
    }//end function
};//end class

int main() {
    RegularUser regularUser("Areeba Hasnain", "Areeba1@gmail.com", "password123");
    BusinessUser businessUser("Papa's Cupcakes", "Papascupcake@gmail.com", "vanillafrosting");
    Post post1("001", "Beach day with friends", 77, "Looking sunny!");
    Post post2("002", "Our all new Lotus cream cupcake", 550, "LOOKS SO YUMMM!");

    businessUser.promotePost(&post2);
    regularUser.addToFeed(&post1);
    regularUser.addToFeed(&post2);
    regularUser.viewFeed();
    businessUser.viewFeed();

    return 0;
}//end main 
