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
    void Optimal(int pages[], int n);
};

void PageReplacement::Optimal(int pages[], int n) {
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < numFrames; j++)
            if (frames[j] == pages[i]) found = true;

        if (!found) {
            int replaceIndex = -1, farthest = i;
            for (int j = 0; j < numFrames; j++) {
                int k;
                for (k = i + 1; k < n; k++)
                    if (frames[j] == pages[k]) break;

                if (k == n) {
                    replaceIndex = j;
                    break;
                }
                if (k > farthest) {
                    farthest = k;
                    replaceIndex = j;
                }
            }
            frames[replaceIndex] = pages[i];
            pageFaults++;
        }
    }
    cout << "Optimal Page Faults: " << pageFaults << endl;
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
    simulator.Optimal(pages, numPages);

    return 0;
}
