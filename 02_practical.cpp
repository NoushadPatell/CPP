#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char* name;
    int rollNumber;
    char* className;
    char division;
    char* dob;
    char* bloodGroup;
    char* contactAddress;
    char* telephoneNumber;
    char* drivingLicense;

public:
    Student()
        : name(nullptr), rollNumber(0), className(nullptr), division('A'), dob(nullptr),
          bloodGroup(nullptr), contactAddress(nullptr), telephoneNumber(nullptr),
          drivingLicense(nullptr) {}

    Student(const char* n, int roll, const char* cls, char div, const char* d, const char* blood,
            const char* address, const char* phone, const char* license)
        : rollNumber(roll), division(div) {
        initializeString(&name, n);
        initializeString(&className, cls);
        initializeString(&dob, d);
        initializeString(&bloodGroup, blood);
        initializeString(&contactAddress, address);
        initializeString(&telephoneNumber, phone);
        initializeString(&drivingLicense, license);
    }

    Student(const Student& other)
        : rollNumber(other.rollNumber), division(other.division) {
        copyString(&name, other.name);
        copyString(&className, other.className);
        copyString(&dob, other.dob);
        copyString(&bloodGroup, other.bloodGroup);
        copyString(&contactAddress, other.contactAddress);
        copyString(&telephoneNumber, other.telephoneNumber);
        copyString(&drivingLicense, other.drivingLicense);
    }

    ~Student() {
        delete[] name;
        delete[] className;
        delete[] dob;
        delete[] bloodGroup;
        delete[] contactAddress;
        delete[] telephoneNumber;
        delete[] drivingLicense;
    }

    void displayInfo() const {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nClass: " << className
             << "\nDivision: " << division << "\nDate of Birth: " << dob << "\nBlood Group: " << bloodGroup
             << "\nContact Address: " << contactAddress << "\nTelephone Number: " << telephoneNumber
             << "\nDriving License: " << drivingLicense << endl;
    }

private:
    void initializeString(char** dest, const char* src) {
        *dest = src ? strdup(src) : nullptr;
    }

    void copyString(char** dest, const char* src) {
        *dest = src ? strdup(src) : nullptr;
    }
};

int main() {
    try {
        Student student1("John Doe", 101, "12th", 'A', "01-01-2000", "O+", "123 Main St", "555-1234", "DL123456");

        cout << "Student Information:\n";
        student1.displayInfo();

        Student student2 = student1;

        cout << "\nCopied Student Information:\n";
        student2.displayInfo();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
