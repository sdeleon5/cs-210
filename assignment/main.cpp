/**
 * @file main.cpp
 * @author Steven DeLeon
 * @date 08/16/2025
 * @brief Main entry point for the Corner Grocer item tracking application.
 *
 * This file contains the main function that drives the program. It creates an
 * instance of the ItemTracker class, loads the initial data, and then enters
 * a loop to display a menu and handle user input.
 */

#include "ItemTracker.h"
#include <limits>

using namespace std;

// Function prototypes
void displayMenu();
int getMenuChoice();

int main() {
    ItemTracker tracker; // Create an instance of ItemTracker
    tracker.readDataFromFile("CS210_Project_Three_Input_File.txt");
    tracker.createBackupFile("frequency.dat");

    int choice;
    do {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                tracker.searchForItem();
                break;
            case 2:
                tracker.printFrequencyList();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

/**
 * @brief Displays the user menu.
 * * This function prints the menu options to the console for the user to select from.
 */
void displayMenu() {
    cout << "\n--- Corner Grocer Item Tracker ---" << endl;
    cout << "1. Search for an item" << endl;
    cout << "2. Print frequency of all items" << endl;
    cout << "3. Print histogram of item frequencies" << endl;
    cout << "4. Exit" << endl;
    cout << "----------------------------------" << endl;
    cout << "Enter your choice: ";
}

/**
 * @brief Gets and validates the user's menu choice.
 * * This function prompts the user for their menu choice and validates that the
 * input is an integer. It handles invalid input by clearing the input buffer
 * and prompting the user again.
 * * @return The user's validated menu choice.
 */
int getMenuChoice() {
    int choice;
    while (!(cin >> choice)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}
