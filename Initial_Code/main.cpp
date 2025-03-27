#include <iostream>
using namespace std;

// Function to check if a page is in memory
bool isPresent(int frame[], int frames, int page) {
    for (int i = 0; i < frames; i++) {
        if (frame[i] == page)
            return true;
    }
    return false;
}

// Initial Code for User Input and Menu
void menu() {
    int choice, n, frames;
    cout << "Enter number of pages: ";
    cin >> n;
    int pages[n];
    cout << "Enter the page reference sequence: ";
    for (int i = 0; i < n; i++) cin >> pages[i];
    cout << "Enter number of frames: ";
    cin >> frames;
    
    do {
        cout << "\nPage Replacement Algorithms:\n";
        cout << "1. FIFO\n";
        cout << "2. LRU\n";
        cout << "3. Optimal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "FIFO selected (Functionality to be added)\n";
                break;
            case 2:
                cout << "LRU selected (Functionality to be added)\n";
                break;
            case 3:
                cout << "Optimal selected (Functionality to be added)\n";
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again!\n";
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}
