# CS-210 - Project: Corner Grocer Item Tracker

## Summary

This is a C++ console-based program designed for a fictional business "Corner Grocer". The purpose of this project
is to analyze sales data by taking in this data from a text file which contains the list of purchased items. The
program calculates the purchase frequency of each unique item and stores this data. Then, it provides a cli menu-driven
interface for the user to perform these actions:

1. Search an item:
    - This is to see how many times it was sold
2. Display a list:
    - This is to see a list of distinct items sold and their frequency
3. Display a histogram:
    - This is to see a graphical representation of the frequency of each item sold

The application also creates a backup of the frequency data in a file named `frequency.dat`.
This tool solves the business problem of tracking item popularity, which is crucial for making informed decisions about inventory management and marketing.

### What I Did Well

I believe I did particularly well in structuring the program and selecting the appropriate data structures.

- Object-Oriented Design: The code is organized into an `ItemTracker` class that encapsulates all the core logic and data. This separates the business logic (reading files, counting frequencies) from the user interface (`main.cpp`), which follows the principle of separation of concerns and makes the code cleaner and easier to manage.

- Effective Use of `std::map`: I chose to use a `std::map` to store the item frequencies. This was an ideal choice because it automatically handles unique items (keys) and provides efficient, logarithmic time complexity for searching and accessing elements, which is perfect for the "Search for an item" feature.

- Code Readability and Documentation: I was diligent about writing clean, readable code with descriptive variable names (e.g., `itemFrequencies`). Furthermore, I used Doxygen-style comments in the header and implementation files to clearly document the purpose of each class, method, and file.

### Where I Could Enhance the Code

While the program is functional and robust, there are several areas for future enhancement:

- Efficiency: For extremely large datasets (millions of items), replacing `std::map` with `std::unordered_map` could provide a performance boost.

- Error Handling: The current error handling for file I/O is basic. It prints a message to stdout if a file can't be opened. A more robust implementation could include more specific error messages (e.g., "file not found" vs. "permission denied") and allow the user to retry entering a filename.

- Testing: The program lacks unit tests, which is crucial for ensuring its correctness and reliability. Adding unit tests would help catch bugs early and provide confidence in the codebase.

- Adaptability: The program could be made more adaptable by allowing the user to specify the input and output filenames via command-line arguments instead of having them hardcoded in `main()`. This would make the application more flexible for use in different scenarios.

### Most Challenging Pieces of Code

The most challenging part was ensuring the user input was handled gracefully, specifically in the `getMenuChoice()` function. When a user enters text instead of a number for a menu choice, it can put the cin stream into an error state, leading to an infinite loop.

To overcome this, I researched proper input validation techniques in C++. I learned that I needed to:

- Check the state of the `cin` stream.
- If it's in an error state, use `cin.clear()` to clear the error flags.
- Use `cin.ignore()` with `numeric_limits<streamsize>::max()` to discard the invalid input remaining in the buffer.

The key resource that helped me was cppreference.com, which has detailed documentation on the iostream library, and various sources found online such as Stack Overflow, GeekForGeeks, etc.

### Transferable Skills

This project helped me solidify several skills that are highly transferable to other projects and future coursework:

- Object-Oriented Programming (OOP): The practice of designing and implementing a class to model a real-world concept is a fundamental skill in software engineering.
- C++ Standard Template Library (STL): I gained significant experience using key STL components like `map` (containers), `string` manipulations, and `fstream` (file I/O), which are essential for writing modern C++.
- Build Systems: Using `CMake` to define the project structure and build process is a practical skill widely used in the C++ industry.
- Data Handling: The entire project revolves around reading, processing, storing, and displaying data, which is a core task in almost every application.

### Maintainability, Readability, and Adaptability

I took several specific steps to ensure the program was maintainable, readable, and adaptable:

- Readability: I used clear and descriptive names for all variables, functions, and the class. I also formatted the code consistently and, most importantly, added comprehensive comments explaining why the code was written a certain way, not just what it does.
- Maintainability: By separating the logic into the `ItemTracker` class, I made the code much easier to maintain. For example, if the method for calculating frequencies needed to change, I would only need to edit `ItemTracker.cpp`, leaving `main.cpp` untouched. This modular design prevents small changes from having a ripple effect across the codebase.
- Adaptability: Functions like `readDataFromFile()` take the filename as a parameter. This design choice means the program is not locked into a single input file. The core logic could be adapted to read from a database or a network stream by simply modifying the implementation of that one function, without altering the rest of the class's interface.
