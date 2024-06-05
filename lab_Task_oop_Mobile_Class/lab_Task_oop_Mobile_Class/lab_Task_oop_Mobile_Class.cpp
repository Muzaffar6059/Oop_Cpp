#include <iostream>
#include <string>
using namespace std;

class Mobile {
private:
    string name;
    int model;

public:
    // Constructor
    Mobile(string name, int model) {
        this->name = name;
        this->model = model;
    }

    // Getters
    string getName() const {
        return name;
    }

    int getModel() const {
        return model;
    }

    // Setters
    void setModel(int model) {
        this->model = model;
    }

    // Display Information
    void displayInfo() const {
        cout << "Name: " << getName() << endl;
        cout << "Model: " << getModel() << endl;
    }

    // Print Information
    void printInfo() const {
        displayInfo();
    }
};

// Pass by reference to modify the model
void modifyModel(Mobile& mobile) {
    mobile.setModel(4321);
}

// Pass by reference to display details or call getName() and getModel() methods
void displayDetails(const Mobile& mobile) {
    mobile.displayInfo();
}

int main() {
    Mobile mobile("Samsung", 1234);
    modifyModel(mobile); // Modify model by passing by reference
    displayDetails(mobile); // Display details by passing by reference

    return 0;
}
