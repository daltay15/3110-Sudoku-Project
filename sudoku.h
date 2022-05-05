using namespace std;

#define SIZE 6

class sudoku
{
private:
public:
    int getBoxHeight();
    int getBoxWidth();
    void getInput(int sudokuGrid[SIZE][SIZE]);
    void printGrid(int arr[SIZE][SIZE]);
    bool isSafe(int sudokuGrid[SIZE][SIZE], int row, int col, int num);
    bool attemptSolve(int sudokuGrid[SIZE][SIZE], int row, int col);
};