//Programmer Emman Abrar Ali 23k0051 Assignment Task1
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//class Pet
class Pet {
    string species;string healthStatus;int hungerlvl;int happinesslvl;vector<string> specialSkills;
public:
//constructor for pet class
    Pet(string species, string healthStatus, int hungerlvl, int happinesslvl, vector<string> specialSkills) :
        species(species), healthStatus(healthStatus), hungerlvl(hungerlvl), happinesslvl(happinesslvl), specialSkills(specialSkills) {}
//basic function that displays details of pets 
    void displayPetDetails() {
        cout << "Species of Pet: " << species << endl;
        cout << "Health Status: " << healthStatus << endl;
        cout << "Hunger Level: " << hungerlvl << endl;
        cout << "Happiness Level: " << happinesslvl << endl;
        cout << "Special Skills: ";
        for (const string& skill : specialSkills) {
            cout << skill << ", ";
        }//end for loop
        cout << endl;
    }//end function displayPetDetails
//function to update happiness level of pets 
    void updateHappiness(int amount) {
        happinesslvl += amount;
        if (happinesslvl > 10) {
            happinesslvl = 10;
        }
        else if (happinesslvl < 0) {
            happinesslvl = 0;
        }
    }//end of function of Happiness
//function to update health status of pets 
    void updateHealth(string health) {
        healthStatus = health;
    }//end of function
//function to update a hunger level of pets
    void updateHunger(int amount) {
        hungerlvl += amount;
        if (hungerlvl < 0) {
            hungerlvl = 0;
        }
    }//end of function 

//getter functions that are calling the name of the species , happiness level , hunger level and health status of the pets
    string getSpecies() {
        return species;
    }//end 

    int getHappinesslvl() {
        return happinesslvl;
    }//end 

    int getHungerlvl() {
        return hungerlvl;
    }//end 
};//end of the class Pet.

//class of Adopter begins 
class Adopter {
    string Adoptername;
    string adopterMobileNum;
    vector<Pet*> AdoptedPets;

public:
//construtor for adopter class
    Adopter(string name, string num) : Adoptername(name), adopterMobileNum(num) {}
//function of to adopt a pet 
    void adoptPet(Pet* pet) {
        AdoptedPets.push_back(pet);
        cout << "Pet " << pet->getSpecies() << " has been adopted by " << Adoptername << endl;
    }//end of function 
//function to return the pets 
    void returnPet(Pet* pet) {
        for (auto it = AdoptedPets.begin(); it != AdoptedPets.end(); ++it) {
            if (*it == pet) {
                AdoptedPets.erase(it);
                cout << "Pet " << pet->getSpecies() << " has been returned by " << Adoptername << endl;
                return;
            }//end of it 
        }//end of for loop
        cout << "This pet has not been adopted by " << Adoptername << endl;
    }//end of function

    void displayAllPets() {
        cout << "Pets that have been adopted by:  " << Adoptername << " are: ";
        for (const auto& pet : AdoptedPets) {
            pet->displayPetDetails();
        }
    }
};

int main() {
  cout<<"Emman Abrar Ali 23k0051"<<endl;
    //create pet objects
    Pet p1("Dog", "Healthy", 5, 8, {"Fetch", "Playful", "Loyal"});
    Pet p2("Cat", "Healthy", 3, 6, {"Playful", "Curious", "Affectionate"});
    Pet p3("Bird", "Healthy", 2, 9, {"Sing", "Chirp", "Loyal"});

    //create adopter objects
    Adopter a1("Emman", "57748748794");
    Adopter a2("Areeba", "57748748794");
    Adopter a3("Rum", "9034589443");

    //adopt pets
    a1.adoptPet(&p1);
    a2.adoptPet(&p2);
    a2.adoptPet(&p3);

    //display adopted Pets of all adopters
    a1.displayAllPets();
    a2.displayAllPets();
    a3.displayAllPets();

    //updating information
    p1.updateHappiness(5);
    p2.updateHappiness(3);
    p2.updateHunger(2);
    p3.updateHappiness(2);
    p3.updateHunger(-1);
    p1.updateHealth("Unhealthy");
    p2.updateHealth("Obese");

    //display adopted details of updated pet information
    cout << "Updated Pet Details of Adopter1 : " << endl;
    a1.displayAllPets();
    cout << "Updated Pet Details of Adopter2 : " << endl;
    a2.displayAllPets();
    cout << "Updated Pet Details of Adopter3 : " << endl;
    a3.displayAllPets();

    //return pets
    a3.returnPet(&p3);
    cout << "Adopter 3 has returned the pet " << p3.getSpecies() << endl;
    a3.displayAllPets();

    return 0;
}//end main

