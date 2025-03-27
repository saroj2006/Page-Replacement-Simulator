Page Replacement Algorithm Simulator

Overview
This project simulates three common page replacement algorithms used in operating systems:
FIFO (First-In-First-Out)
LRU (Least Recently Used)
Optimal Page Replacement

It allows users to input a sequence of pages and analyze how different algorithms handle page faults based on a fixed number of memory frames.

Features
->FIFO Page Replacement Algorithm
->LRU Page Replacement Algorithm
->Optimal Page Replacement Algorithm
->Tracks and displays page faults
->Simple command-line interface for easy use

How to Run
1. Compile the C++ file:
   ```sh
   g++ main.cpp -o simulator
   ```
2. Run the executable:
   ```sh
   ./simulator
   ```
3. Provide input:
   - Enter the number of memory frames
   - Enter number of pages
   - Enter the sequence of page requests
     
4. View the results:
   - The program will display the number of page faults for each algorithm

Example:
Enter number of frames: 3
Enter number of pages: 10
Enter page sequence: 7 0 1 2 0 3 4 2 3 0

Sample Output:
FIFO Page Faults: 7
LRU Page Faults: 6
Optimal Page Faults: 5


Project Structure
```
Page-Replacement-Simulator/
│── Initial_Code/         # Basic structure 
│── FIFO_Added/           # FIFO algorithm implemented
│── LRU_Implemented/      # LRU algorithm implemented
│── Optimal_Implemented/  # Optimal algorithm implemented
│── Final/                # Final integerated code 
│── ChangeLog.txt         # Tracks code modifications
│── README.md              # Project details & usage
```

Additional Notes
- The code is written in *C++*.


