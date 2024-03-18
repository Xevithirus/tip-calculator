#include <iostream>
#include <limits>


void clearInput();
bool checkInput(float n);

int main() {
    float total{};
    float tip{};
    char runCalc{ 'Y' }; // Initialized to 'Y' to enter the loop at least once
    float newtotal{}; // Declare newtotal here

    while (std::toupper(runCalc) == 'Y') { // Moved while loop here
        std::cout << "\nPlease Enter Total Price: ";
        std::cin >> total;
        if (!checkInput(total)) // Validate user input
            continue; // Restart the loop if input is invalid

        std::cout << "\nPlease Enter Tip Amount: "; // Moved inside the loop
        std::cin >> tip;
        if (!checkInput(tip))
            continue;

        newtotal = total + tip; // Calculate new total

        std::cout << "\nYour New Total is: " << newtotal << std::endl;

        // Prompt user if they want to calculate another tip
        std::cout << "\nWould You Like to Calculate Another Tip? (Y/N): ";
        std::cin >> runCalc;

        // Validate user input for runCalc
        while (std::toupper(runCalc) != 'Y' && std::toupper(runCalc) != 'N') {
            std::cout << "Invalid Input. Please Enter Y or N." << std::endl;
            clearInput();
            std::cout << "\nWould You Like to Calculate Another Tip? (Y/N): ";
            std::cin >> runCalc;
        }
    }

    return 0;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool checkInput(float n) {
    if (std::cin.fail()) {
        std::cout << "Invalid Input. Please Enter a Number." << std::endl;
        clearInput();
        return false;
    }
    if (n == 0) {
        std::cout << "Total Price Cannot Be Zero." << std::endl;
        clearInput();
        return false;
    }
    if (n < 0) {
        std::cout << "Total Price Cannot Be Negative." << std::endl;
        clearInput();
        return false;
    }

    return true;
}