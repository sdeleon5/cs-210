/**
 * @file ItemTracker.h
 * @author Steven DeLeon
 * @date 08/16/2025
 * @brief Header file for the ItemTracker class.
 *
 * This file contains the declaration of the ItemTracker class, which is designed
 * to read grocery items from a file, track their purchase frequency, and
 * provide various methods to display this data.
 */

#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
 * Class: ItemTracker
 * Description: This class is responsible for tracking the frequency of grocery items.
 * It can read items from an input file, store their frequencies, create a backup,
 * and display the data in various formats.
 */
class ItemTracker {
public:
    // Public member functions
    void readDataFromFile(const string& filename);
    void createBackupFile(const string& filename) const;
    void searchForItem() const;
    void printFrequencyList() const;
    void printHistogram() const;

private:
    // Private member variables
    map<string, int> itemFrequencies; // Map to store item frequencies
};

#endif // ITEM_TRACKER_H
