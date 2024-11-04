#include<iostream>
#include<string>
using namespace std;

// Base Class for Single and Multilevel Inheritance
class Vehicle {
public:
    string brand;
    int year;
    Vehicle(){}
  

    Vehicle(string b, int y) : brand(b), year(y) {}

    virtual void display() {
        cout << "Vehicle Brand: " << brand << ", Year: " << year << endl;
    }

     virtual ~ Vehicle() {} // Destructor to ensure proper resource management
};

// Derived Class for Single Inheritance
class Car : public Vehicle {
public:
    string model;
    bool isAvailable;
    Car(){}

    Car(string b, int y, string m, bool available = true) 
        : Vehicle(b, y), model(m), isAvailable(available) {}

    void displayCar() {
        cout << "Car Model: " << model << " (Available: " << (isAvailable ? "Yes" : "No") << ")" << endl;
    }

    void rentCar() {
        if (isAvailable) {
            isAvailable = false;
            cout << model << " rented successfully!" << endl;
        } else {
            cout << model << " is already rented!" << endl;
        }
    }

    void returnCar() {
        isAvailable = true;
        cout << model << " returned successfully!" << endl;
    }
};

// Derived Class for Multilevel Inheritance
class RentalCar : public Car {
public:
    float rentalPricePerDay;
    RentalCar(){}

    RentalCar(string b, int y, string m, float price) 
        : Car(b, y, m), rentalPricePerDay(price) {}

    void displayRentalInfo() {
        cout << "Rental Car: " << brand << " " << model 
             << " for $" << rentalPricePerDay << " per day" << endl;
    }

    float calculateRentalCost(int days) {
        return rentalPricePerDay * days;
    }
};

// Main Class handling Car Rentals without using vector
class CarRentalSystem {
    RentalCar availableCars[3]; // Fixed-size array for simplicity

public:
    CarRentalSystem() {
        // Preloading some cars for the rental system
        availableCars[0] = RentalCar("Toyota", 2020, "Corolla", 50);
        availableCars[1] = RentalCar("Honda", 2019, "Civic", 45);
        availableCars[2] = RentalCar("Ford", 2021, "Fusion", 60);
    }

    void displayAvailableCars() {
        cout << "Available Cars for Rent:" << endl;
        for (int i = 0; i < 3; ++i) {
            if (availableCars[i].isAvailable) {
                availableCars[i].display();
                availableCars[i].displayCar();
                availableCars[i].displayRentalInfo();
                cout << endl;
            }
        }
    }

    void rentCar(string model, int days) {
        for (int i = 0; i < 3; ++i) {
            if (availableCars[i].model == model && availableCars[i].isAvailable) {
                availableCars[i].rentCar();
                float totalCost = availableCars[i].calculateRentalCost(days);
                cout << "Total rental cost for " << days << " days: $" << totalCost << endl;
                return;
            }
        }
        cout << "Sorry, the car is either unavailable or does not exist." << endl;
    }

    void returnCar(string model) {
        for (int i = 0; i < 3; ++i) {
            if (availableCars[i].model == model && !availableCars[i].isAvailable) {
                availableCars[i].returnCar();
                return;
            }
        }
        cout << "No rented car with the model: " << model << endl;
    }
};

// Main function to demonstrate the car rental system
int main() {
    CarRentalSystem system;
    string carModel;
    int rentalDays;
    int option;

    cout << "Welcome to the Car Rental System!" << endl;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. View available cars" << endl;
        cout << "2. Rent a car" << endl;
        cout << "3. Return a car" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cin.ignore(); // To handle input buffer

        switch (option) {
        case 1:
            system.displayAvailableCars();
            break;
        case 2:
            cout << "Enter the car model you want to rent: ";
            getline(cin, carModel);
            cout << "Enter the number of days you want to rent: ";
            cin >> rentalDays;
            system.rentCar(carModel, rentalDays);
            break;
        case 3:
            cout << "Enter the car model you want to return: ";
            getline(cin, carModel);
            system.returnCar(carModel);
            break;
        case 4:
            cout << "Thank you for using the Car Rental System!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

    } while (option != 4);

    return 0;
}

    
        
