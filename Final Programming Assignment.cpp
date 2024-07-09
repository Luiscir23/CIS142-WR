// CIS142 Introduction to C++ Summer 2024
// Final Programming Assignment
// Mao Bergan
// 25 July 2024

// Final Programming Assignment.cpp

/* Shakey’s garden can contain other objects which may be movable or immovable based upon its
physical nature; e.g Flowers. Flowers can be stepped on and destroyed. Trees are immovable and
cannot be destroyed */

#include <iostream>
#include <vector>

class Garden {
public:
    // control the console view of all elements in 2D array.
    void printGarden(std::vector<std::vector<std::string>>& locGarden, int locRows, int locColumns) {
        for (int i = 0; i < locRows; i++) {
            for (int j = 0; j < locColumns; j++) {
                std::cout << locGarden[i][j]; // print each element in the predefined garden.
            }
        std::cout << std::endl; // create a new row after each row is complete.
        }
    }

    /* TEMPORARY -----> set the location of the robot. <----- TEMPORARY */
    void location(std::vector<std::vector<std::string>>& locGarden, int x, int y) {
        locGarden[x][y] = "S ";
        std::system("cls");
    }
};

int main() {
    int rows;
    int columns;
    std::cout << "Enter rows: ";
    std::cin >> rows;
    std::cout << "Enter columns: ";
    std::cin >> columns;
    // create a 2D array named garden, with the user defined size.
    std::vector<std::vector<std::string>> garden(rows, std::vector<std::string>(columns));

    // allocate the user defined array with the element below.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            garden[i][j] = "* "; // set each element in the 2D array to this element.
        }
    }

    Garden shakey; // create object shakey the robot.
    shakey.printGarden(garden, rows, columns);
    shakey.location(garden, 0, 0); // set [1, 1] to S for shakey?
    shakey.printGarden(garden, rows, columns);
    return 0;
}



#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ShakeyRobot {
private:
    int position;
    vector<std::string> inventory;

public:
    ShakeyRobot() : position(0) {}

    void moveLeft() {
        position--;
        cout << "Moved left to position " << position << endl;
    }

    void moveRight() {
        position++;
        cout << "Moved right to position " << position << endl;
    }

    void pickUpItem(const string& item) {
        inventory.push_back(item);
        cout << "Picked up " << item << endl;
    }

    void showInventory() const {
        cout << "Inventory: ";
        for (const auto& item : inventory) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    ShakeyRobot shakey;
    char choice;
    string item;

    do {
        cout << "Options:\n";
        cout << "L - Move Left\n";
        cout << "R - Move Right\n";
        cout << "P - Pick Up Item\n";
        cout << "I - Show Inventory\n";
        cout << "Q - Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 'L':
        case 'l':
            shakey.moveLeft();
            break;
        case 'R':
        case 'r':
            shakey.moveRight();
            break;
        case 'P':
        case 'p':
            cout << "Enter item to pick up: ";
            cin >> item;
            shakey.pickUpItem(item);
            break;
        case 'I':
        case 'i':
            shakey.showInventory();
            break;
        case 'Q':
        case 'q':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}

  













