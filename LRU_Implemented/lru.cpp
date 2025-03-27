#include <iostream>
using namespace std;

void LRU(int pages[], int n, int frames) {
    int frame[frames], age[frames], count = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1, age[i] = 0;
    
    for (int i = 0; i < n; i++) {
        int lru = 0;
        bool found = false;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                age[j] = i;
                break;
            }
        }
        if (!found) {
            for (int j = 1; j < frames; j++)
                if (age[j] < age[lru]) lru = j;
            frame[lru] = pages[i];
            age[lru] = i;
            count++;
        }
    }
    cout << "LRU Page Faults: " << count << endl;
}

int main() {
    int n, frames;
    cout << "Enter number of pages: ";
    cin >> n;
    int pages[n];
    cout << "Enter the page reference sequence: ";
    for (int i = 0; i < n; i++) cin >> pages[i];
    cout << "Enter number of frames: ";
    cin >> frames;

    LRU(pages, n, frames);
    return 0;
}
