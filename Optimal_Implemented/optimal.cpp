#include <iostream>
using namespace std;

void Optimal(int pages[], int n, int frames) {
    int frame[frames], count = 0;
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
            int replace = 0, farthest = -1;
            for (int j = 0; j < frames; j++) {
                int next_use = n;
                for (int k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        next_use = k;
                        break;
                    }
                }
                if (next_use > farthest) {
                    farthest = next_use;
                    replace = j;
                }
            }
            frame[replace] = pages[i];
            count++;
        }
    }
    cout << "Optimal Page Faults: " << count << endl;
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

    Optimal(pages, n, frames);
    return 0;
}
