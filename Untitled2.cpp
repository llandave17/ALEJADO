#include <iostream>
#include <string>
#include <cstdlib> // For std::system

void displayMenu();
void listFiles();
void createDirectory();
void changeDirectory();
void showCurrentDirectory(); // Function declaration

int main() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter the Number: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                listFiles();
                break;
            case 2:
                createDirectory();
                break;
            case 3:
                changeDirectory();
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            case 5:
                showCurrentDirectory();
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
        }
    } while (choice != 4);
    return 0;
}

void displayMenu() {
    std::cout << "\n\t\t\tMAIN MENU\n";
    std::cout << "1. Display List of Files\n";
    std::cout << "2. Create New Directory\n";
    std::cout << "3. Change the Working Directory\n";
    std::cout << "4. Exit\n";
    std::cout << "5. Show Current Directory\n"; // Added option
}

void listFiles() {
    int option;
    std::string extension, name;
    std::cout << "\n\t\tLIST FILE DETAILS\n";
    std::cout << "1. List All Files\n";
    std::cout << "2. List Files by Extension\n";
    std::cout << "3. List Files by Name Pattern\n";
    std::cout << "Enter option: ";
    std::cin >> option;
    switch (option) {
        case 1:
            showCurrentDirectory(); // List all files
            break;
        case 2:
            std::cout << "Enter the extension (e.g., .txt): ";
            std::cin >> extension;
            std::cout << "Files with extension " << extension << ":\n";
            std::system(("dir /b *" + extension).c_str()); // Adjust for Unix-like systems
            break;
        case 3:
            std::cout << "Enter the name pattern (e.g., file*): ";
            std::cin >> name;
            std::cout << "Files matching pattern " << name << ":\n";
            std::system(("dir /b " + name).c_str()); // Adjust for Unix-like systems
            break;
        default:
            std::cout << "Invalid option, returning to the main menu.\n";
    }
}

void createDirectory() {
    std::string dirName;
    std::cout << "Enter the Directory name: ";
    std::cin >> dirName;
    std::string command = "mkdir " + dirName; // Adjust for Unix-like systems
    if (std::system(command.c_str()) == 0) {
        std::cout << dirName << " Directory Successfully Created\n";
    } else {
        std::cout << "Failed to create directory " << dirName << "\n";
    }
}

void changeDirectory() {
    int option;
    std::string newDir;
    showCurrentDirectory(); // Show the current directory before changing
    std::cout << "\t\tChange Directory\n";
    std::cout << "1. Step by Step Backward\n";
    std::cout << "2. Go to Root Directory\n";
    std::cout << "3. Forward Directory\n";
    std::cout << "Enter the number: ";
    std::cin >> option;
    switch (option) {
        case 1:
            std::system("cd .."); // Adjust for Unix-like systems
            break;
        case 2:
            std::system("cd \\"); // Adjust to "/" for Unix-like systems
            break;
        case 3:
            std::cout << "Enter the directory name: ";
            std::cin >> newDir;
            std::system(("cd " + newDir).c_str());
            break;
        default:
            std::cout << "Invalid option, returning to the main menu.\n";
    }
    showCurrentDirectory(); // Show the current directory after changing
}

void showCurrentDirectory() {
#ifdef _WIN32
    std::system("dir /b"); // Windows command to list files in the current directory
#else
    std::system("ls"); // Unix-like command to list files in the current directory
#endif
}
