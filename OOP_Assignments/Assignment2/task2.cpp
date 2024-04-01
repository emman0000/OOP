//Gaming environment Task 2
//Programmer Emman Abrar Ali 23k0051
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    int id; string name; int health;
public:
    Player(int id, string name) : id(id), name(name), health(100) {} //initalised the player health to 100 
 // Getters
    string getName() const {
        return name;
    }
    int getHealth() const {
        return health;
    }
};//end of class Player

class Weapon {
private:
    string* weaponsList;

public:
    Weapon(string* weaponsList) : weaponsList(new string[6]) {
        for (int i = 0; i < 6; ++i) {
            this->weaponsList[i] = weaponsList[i]; //use  -> to access private member of class it points to an array of strings that holds the weapons
        }//end for loop
    }//end of constructor 

    // Function to display available weapons
    void displayWeapons() {
        cout << "CHOOSE YOUR WEAPON:" << endl;
        for (int i = 0; i < 6; ++i) {
            cout << i + 1 << ". " << weaponsList[i] << endl;
        }
    }//end function that displays the weapons 

    // Function to prompt user for weapon choice
    string chooseWeapon() {
        displayWeapons();
        int choice;
        cout << "PICK A NUMBER TO DETERMINE YOUR FATE! CHOOSE WISELY: ";
        cin >> choice;
        if (choice >= 1 && choice <= 6) {
            return weaponsList[choice - 1];
        } else {
            cout << "Invalid choice. Choosing the first weapon." << endl;
            return weaponsList[0];
        }
    }//end function to choose weapon
};//end of class Waepon

class Character : public Player {
private:
    int points;
    string experience;

public:
    Character(int id, string name) : Player(id, name), points(0), experience("Beginner") {}

    void levelUp() {
        if (points >= 10) {
            points -= 10;
            if (experience == "Beginner") {
                experience = "Intermediate";
            } else if (experience == "Intermediate") {
                experience = "Advanced";
            } else if (experience == "Advanced") {
                experience = "Expert";
            }
        }
    }

    void playGame(Weapon& weapon, Player& enemy) {
        string weaponUsed = weapon.chooseWeapon();
        cout << "You attack using " << weaponUsed << endl;
        int enemyHealth = enemy.getHealth();
        enemyHealth -= 10; // Decreased enemy's health by 10
        cout << "Enemy health reduced to " << enemyHealth << endl;
        points += 10;
    }

    void resetPoints() {
        points = 0;
    }

    string getExperience() const {
        return experience;
    }
};

class Enemy : public Player {
private:
    int damage;

public:
    Enemy(int id, string name, int dmg) : Player(id, name), damage(dmg) {}//end constrcutor

    // Function to simulate enemy's attack
     void attack(Character& character) {
        cout << "Enemy attacks with damage: " << damage << endl;
        int characterHealth = character.getHealth();
        characterHealth -=10; 
        cout << "Your health reduced to " << characterHealth << endl;
    }//end function for attack 

};//end class Enemy

int main() {
  cout<<"\nProgrammer Emman Abrar Ali 23k0051\n\n***********************\n";
    // Instances of Weapon and Character
    Player enemyPlayer(001, "The Plague Doctor");
    Enemy enemy(002, "THANOS", 10);
    string weapons[] = {"Chappal", "Nokia Brick", "Frying Pan", "Lego", "Broom", "Belt"};
    Weapon weapon(weapons);
    Character player(1, "LOKI");

    // Simulate game loop

    for (int i = 0; i < 3; ++i) { //only kept the simulation for 3 levels 
        cout << "Player: " << player.getName() << ", Experience: " << player.getExperience() << ", Health: " << player.getHealth() << endl;
        player.playGame(weapon, enemyPlayer);
        enemy.attack(player);
        player.levelUp();
    }//end for loop
    return 0; 
}//end main
