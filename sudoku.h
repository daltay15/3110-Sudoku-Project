using namespace std;

#define SIZE 6
const int boxRowSize = 2; // sets the rows in a box to 2 for small sudoku puzzle
const int boxColSize = 3; // sets the columns in a box to 3 for small sudoku puzzle

class sudoku
{
private:
public:
     void printGrid(int arr[SIZE][SIZE]);
     bool isSafe(int sudokuGrid[SIZE][SIZE], int row, int col, int num);
     bool attemptSolve(int sudokuGrid[SIZE][SIZE], int row, int col);
};



