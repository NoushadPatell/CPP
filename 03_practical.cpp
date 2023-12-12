#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    void getData() {
        cout << "Enter title: ";
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // Clear the newline character from the input buffer
    }

    void displayData() const {
        cout << "Title: " << title << "\nPrice: $" << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() {
        Publication::getData(); // Call base class method
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore(); // Clear the newline character from the input buffer
    }

    void displayData() const {
        Publication::displayData(); // Call base class method
        cout << "Page Count: " << pageCount << " pages" << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void getData() {
        Publication::getData(); // Call base class method
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        cin.ignore(); // Clear the newline character from the input buffer
    }

    void displayData() const {
        Publication::displayData(); // Call base class method
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    try {
        Book book;
        Tape tape;

        cout << "Enter book information:\n";
        book.getData();

        cout << "\nEnter tape information:\n";
        tape.getData();

        cout << "\nDisplaying book information:\n";
        book.displayData();

        cout << "\nDisplaying tape information:\n";
        tape.displayData();
    } catch (...) {
        cerr << "An exception occurred. Setting all values to zero." << endl;
    }

    return 0;
}
