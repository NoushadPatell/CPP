#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int id;
    string name;

    Item(int i, const string& n) : id(i), name(n) {}
};

void displayItem(const Item& item) {
    cout << "ID: " << item.id << ", Name: " << item.name << endl;
}

bool compareById(const Item& a, const Item& b) {
    return a.id < b.id;
}

int main() {
    vector<Item> items = { {3, "Keyboard"}, {1, "Monitor"}, {2, "Mouse"} };

    cout << "Original Items:\n";
    for_each(items.begin(), items.end(), displayItem);

    sort(items.begin(), items.end(), compareById);

    cout << "\nSorted Items by ID:\n";
    for_each(items.begin(), items.end(), displayItem);

    int searchId = 2;
    auto result = binary_search(items.begin(), items.end(), Item(searchId, ""), compareById);

    cout << "\nItem with ID " << searchId << (result ? " found." : " not found.") << endl;

    return 0;
}
