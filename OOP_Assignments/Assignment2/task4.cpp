//Programmer Emman Abrar Ali 23k0051
// Social Media Task 4
#include <iostream>
#include <string>
using namespace std;

static const int MAX_FEED_SIZE = 10;

// Forward declaration for class Post
class Post;

class User {
protected:
    string username;string email; string password;

public:
    User(const string& username, const string& email, const string& password)
        : username(username), email(email), password(password) {} //end

    // Getters and setters
    string getUsername() const {
        return username;
    }
    void setUsername(const string& username) {
        this->username = username;
    }
    bool verifyPassword(const string& inputPassword) {
        return inputPassword == password;
    }
};//eend class User

// Derived classes

class RegularUser : public User {
protected:
    Post* feed[MAX_FEED_SIZE];
    int numPosts;

public:
    RegularUser(const string& username, const string& email, const string& password, int nop)
        : User(username, email, password), numPosts(0) {}

    // Function to add post to feed
    void addToFeed(Post* post) {
        if (numPosts < MAX_FEED_SIZE) {
            feed[numPosts] = post;
            numPosts++;
            cout << "Image added successfully\n" << endl;
        } else {
            cout << "No more space available. Upgrade storage." << endl;
        }
    }

    // Function to view feed
    void viewFeed();

};//end class RegularUser

class BusinessUser : public User {
public:
    BusinessUser(const string& username, const string& email, const string& password)
        : User(username, email, password) {}//end constructor

    // Function to promote the post 
    void promotePost(Post* post);
    void viewFeed();

};//end class BusinessUser

class Post {
protected:
    string postID;
    string postContent;
    int likes;
    string comments;

public:
    Post(const string& id, const string& pc, int l, const string& c)
        : postID(id), postContent(pc), likes(l), comments(c) {}

    // Function to add comments 
    void addComments(const string& comment) {
        comments += comment + "\n";
    }

    // Function to like post
    void likePost() {
        likes++;
        cout << "Post liked" << endl;
    }

    string getPostID() const {
        return postID;
    }

    void displayDetails() {
        cout << "Post content: " << postContent << endl;
        cout<<"Image Id: "<<postID<<endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << comments << endl;
        cout<<"\n \n";
    }

};//end class Post

// Implementations using :: to gain access

void RegularUser::viewFeed() {
    cout << "Viewing feed for " << getUsername() << ":" << endl;
    for (int i = 0; i < numPosts; ++i) {
        feed[i]->displayDetails();
    }
}//end function

void BusinessUser::promotePost(Post* post) {
    cout << "Trending today!\n " << post->getPostID() << endl;
    cout << "....................................." << endl;
    // Logic to increase post likes and views for business user
}//end function 

int main() {
    cout << "Programmer Emman Abrar Ali 23k0051" << endl;
    cout << "----------------------------------\n" << endl;

    RegularUser regularUser("Areeba Hasnain", "Areeba1@gmail.com", "password123", 0);
    BusinessUser businessUser("Papa's Cupcakes", "Papascupcake@gmail.com", "vanillafrosting");
    Post post1("001", "Beach day with friends ", 77, "Looking sunny!");
    Post post2("002", "Our all new Lotus cream cupcake", 550, "LOOKS SO YUMMM!");

//Promoting business user's content
    businessUser.promotePost(&post2);

//Adding images to feed for both users 
    regularUser.addToFeed(&post1);
    regularUser.addToFeed(&post2);

    regularUser.viewFeed();

    return 0;
}//end main 



