#include <iostream>
using namespace std;

void FIFO(int pages[], int n, int frames) {
    int frame[frames], front = 0, count = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1;
    
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            frame[front] = pages[i];
            front = (front + 1) % frames;
            count++;
        }
    }
    cout << "FIFO Page Faults: " << count << endl;
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

    FIFO(pages, n, frames);
    return 0;
}
