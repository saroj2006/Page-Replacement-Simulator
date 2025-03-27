#include <iostream>
using namespace std;

#define MAX_FRAMES 10
#define MAX_PAGES 100

class PageReplacement {
private:
    int frames[MAX_FRAMES], numFrames;
public:
    PageReplacement(int n) {
        numFrames = n;
        for (int i = 0; i < numFrames; i++)
            frames[i] = -1;
    }
    void FIFO(int pages[], int n);
};

void PageReplacement::FIFO(int pages[], int n) {
    int index = 0, pageFaults = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < numFrames; j++)
            if (frames[j] == pages[i]) found = true;

        if (!found) {
            frames[index] = pages[i];
            index = (index + 1) % numFrames;
            pageFaults++;
        }
    }
    cout << "FIFO Page Faults: " << pageFaults << endl;
}

int main() {
    int numFrames, numPages, pages[MAX_PAGES];
    cout << "Enter number of frames: ";
    cin >> numFrames;
    cout << "Enter number of pages: ";
    cin >> numPages;

    cout << "Enter page sequence: ";
    for (int i = 0; i < numPages; i++)
        cin >> pages[i];

    PageReplacement simulator(numFrames);
    simulator.FIFO(pages, numPages);

    return 0;
}
