#include <iostream>
using namespace std;

#define MAX_FRAMES 10
#define MAX_PAGES 100

class PageReplacement {
protected:
    int frames[MAX_FRAMES];
    int numFrames;
public:
    PageReplacement(int n) {
        numFrames = n;
        for (int i = 0; i < numFrames; i++)
            frames[i] = -1;
    }
    void displayFrames() {
        cout << "Frames: ";
        for (int i = 0; i < numFrames; i++)
            cout << frames[i] << " ";
        cout << endl;
    }
};

int main() {
    int numFrames;
    cout << "Enter number of frames: ";
    cin >> numFrames;

    PageReplacement simulator(numFrames);
    simulator.displayFrames();

    return 0;
}
