/**
 * @file ItemTracker.cpp
 * @author Steven DeLeon
 * @date 08/16/2025
 * @brief Implementation file for the ItemTracker class.
 *
 * This file contains the implementation of the member functions for the
 * ItemTracker class. It handles the logic for file I/O, data processing,
 * and console output for the grocery item tracking application.
 */

#include "ItemTracker.h"
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * @brief Reads grocery item data from a specified file and populates the itemFrequencies map.
 * * This function opens the given file, reads each item line by line, and updates
 * the frequency count for each unique item in the itemFrequencies map.
 * * @param filename The name of the file to read data from.
 */
void ItemTracker::readDataFromFile(const string& filename) {
    ifstream inputFile(filename); // Input file stream
    string item; // Variable to hold each item read from the file

    if (inputFile.is_open()) {
        while (inputFile >> item) {
            itemFrequencies[item]++;
        }
        inputFile.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }
}

/**
 * @brief Creates a backup of the item frequency data to a file named frequency.dat.
 * * This function iterates through the itemFrequencies map and writes each item
 * and its corresponding frequency to the backup file.
 * * @param filename The name of the backup file to create.
 */
void ItemTracker::createBackupFile(const string& filename) const {
    ofstream outputFile(filename); // Output file stream

    if (outputFile.is_open()) {
        for (const auto& pair : itemFrequencies) {
            outputFile << pair.first << " " << pair.second << endl;
        }
        outputFile.close();
    } else {
        cerr << "Error: Unable to create backup file " << filename << endl;
    }
}

/**
 * @brief Prompts the user to enter an item and displays its frequency.
 * * This function takes user input for an item name and searches for it in the
 * itemFrequencies map. It then prints the frequency of the item if found,
 * or a message indicating the item was not found.
 */
void ItemTracker::searchForItem() const {
    string searchItem; // Variable to hold the item to search for
    cout << "Enter the item you wish to look for: ";
    cin >> searchItem;

    // Capitalize the first letter of the search item for case-insensitive comparison
    if (!searchItem.empty()) {
        searchItem[0] = toupper(searchItem[0]);
        for (size_t i = 1; i < searchItem.length(); ++i) {
            searchItem[i] = tolower(searchItem[i]);
        }
    }

    auto it = itemFrequencies.find(searchItem);
    if (it != itemFrequencies.end()) {
        cout << "Frequency of " << it->first << ": " << it->second << endl;
    } else {
        cout << "Item not found." << endl;
    }
}

/**
 * @brief Prints a list of all items and their frequencies.
 * * This function iterates through the itemFrequencies map and prints each
 * item and its frequency in a formatted list.
 */
void ItemTracker::printFrequencyList() const {
    cout << "\n--- Item Frequencies ---" << endl;
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << "------------------------" << endl;
}

/**
 * @brief Prints a histogram of item frequencies.
 * * This function iterates through the itemFrequencies map and prints a text-based
 * histogram where each asterisk represents one unit of frequency for an item.
 */
void ItemTracker::printHistogram() const {
    cout << "\n--- Item Frequency Histogram ---" << endl;
    for (const auto& pair : itemFrequencies) {
        cout << setw(14) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;
}
