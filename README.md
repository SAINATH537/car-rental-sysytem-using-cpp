# Car Rental System

A simple console-based Car Rental System built in C++ using object-oriented programming concepts such as inheritance and polymorphism.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Class Structure](#class-structure)
- [How to Use](#how-to-use)
- [Installation](#installation)
- [Usage](#usage)
- [Future Enhancements](#future-enhancements)
- [License](#license)

## Introduction

This Car Rental System allows users to view available cars, rent a car for a specified number of days, and return a rented car. It uses concepts of single and multilevel inheritance in C++ to organize information about vehicles, cars, and rental cars.

## Features

- **Display Available Cars**: Shows details of cars available for rent.
- **Rent a Car**: Allows users to rent a car for a specified number of days, calculating the total rental cost.
- **Return a Car**: Allows users to return a rented car, making it available for future rentals.
- **Fixed-size Array of Cars**: Contains a pre-loaded array of three rental cars.

## Class Structure

### Vehicle (Base Class)
- Stores basic information like brand and year.
- Virtual `display()` function to display basic vehicle info.

### Car (Derived from Vehicle)
- Adds additional information specific to a car, such as model and availability status.
- `rentCar()` and `returnCar()` functions to manage rental status.

### RentalCar (Derived from Car)
- Includes rental-specific details, such as the rental price per day.
- `calculateRentalCost(int days)` to calculate the total cost for a rental period.

### CarRentalSystem
- Manages an array of `RentalCar` objects.
- Contains functions to display available cars, rent a car, and return a car.

## How to Use

1. **View Available Cars**: The system displays all cars currently available for rent.
2. **Rent a Car**: Choose a car by model and specify the rental duration. The system calculates and displays the total rental cost.
3. **Return a Car**: When done with the rental, specify the model to return it.

## Installation

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/car-rental-system.git
    ```
2. Navigate to the project directory:
    ```bash
    cd car-rental-system
    ```
3. Compile the code using a C++ compiler:
    ```bash
    g++ -o car_rental car_rental.cpp
    ```

## Usage

Run the executable to start the Car Rental System:
```bash
./car_rental
