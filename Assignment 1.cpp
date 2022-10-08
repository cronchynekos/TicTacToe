// Nathanael Kim CPSC 121 assignment 1

#include <iostream>
#include <ctime>

using namespace std;
const char SPACE = ' ';//declaring all the constants
const char PLAYER = 'x';
const char COMPUTER = 'o';
const string PLAYER_WINS = "The Player wins!";
const string COMPUTER_WINS = "The Computer wins!";
const string DRAW = "Its a Cats Game!";
const string GAME_UNFINISHED = "The game is not yet finished";
const int ROWS = 3;
const int COLUMNS = 3;

void Print(char board[ROWS][COLUMNS]) {//function that prints the board whenever called
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j >= 0 && j < 2) {
                cout << " | ";
            }
        }
        cout << '\n';
        if (i >= 0 && i < 2) {
            cout << " - + - + -" << '\n';
        }
    }
}

void SetPlayerMove(char board[ROWS][COLUMNS]) {//menu for the player. function also checks for invalid spots
    int rowInput, columnInput;
    //rowInput = 0;
    //columnInput = 0;
    do {
        cout << "Please choose a row and column between 0 and 2: ";
        cin >> rowInput >> columnInput;
        if (board[rowInput][columnInput] == PLAYER || board[rowInput][columnInput] == COMPUTER) {
            cout << "Please choose a valid space" << '\n';
        }
        else {
            cout << "You have chosen the space " << rowInput << " " << columnInput << '\n';
        }
    } while (board[rowInput][columnInput] == PLAYER || board[rowInput][columnInput] == COMPUTER);
    board[rowInput][columnInput] = PLAYER;
}

void SetComputerMove(char board[ROWS][COLUMNS]) {//sets computer move. function also checks for invalid spots
    int compChoiceRow = rand() % 3;
    int compChoiceColumn = rand() % 3;
    do {
        compChoiceRow = rand() % 3;
        compChoiceColumn = rand() % 3;
        if (board[compChoiceRow][compChoiceColumn] == PLAYER || board[compChoiceRow][compChoiceColumn] == COMPUTER) {
        }
    } while (board[compChoiceRow][compChoiceColumn] == PLAYER || board[compChoiceRow][compChoiceColumn] == COMPUTER);
    board[compChoiceRow][compChoiceColumn] = COMPUTER;
}

bool CheckRows(char board[ROWS][COLUMNS], char piece) {//function that checks if a row is completed (as in a win)
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == piece) {
                count++;
            }
        }
        if (count == 3) {
            return true;
        }
        count = 0;
    }
    return false;
}

bool CheckColumns(char board[ROWS][COLUMNS], char piece) {//function that checks if a column is completed (as in a win)
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == piece) {
                count++;
            }
        }
        if (count == 3) {
            return true;
        }
        count = 0;
    }
    return false;
}

bool CheckDiagonals(char board[ROWS][COLUMNS], char piece) {//function that checks if a diagonal is completed (as in a win)
    int count = 0;
    if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece) {
        return true;
    }
    else if (board[2][0] == piece && board[1][1] == piece && board[0][2] == piece) {
        return true;
    }
    else {
        return false;
    }
}

bool IsWinner(char board[ROWS][COLUMNS], char piece) {//checks is a player has won
    if (CheckRows(board, piece) == true || CheckColumns(board, piece) == true || CheckDiagonals(board, piece) == true) {
        return true;
    }
    else {
        return false;
    }
}

bool IsBoardfull(char board[ROWS][COLUMNS]) {//checks if the board is full creating a tie
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == PLAYER || board[i][j] == COMPUTER) {
                count++;
            }
        }
    }
    if (count == 9) {
        return true;
    }
    else {
        return false;
    }
}

string DetermineBoardState(char board[ROWS][COLUMNS]) {//if one of the ending conditions is met than this function checks who it is
    if (IsWinner(board, PLAYER) == true) {
        return PLAYER_WINS;
    }
    else if (IsWinner(board, COMPUTER) == true) {
        return COMPUTER_WINS;
    }
    else if (IsBoardfull(board) == true) {
        return DRAW;
    }
    else {
        return GAME_UNFINISHED;
    }
}


int main(int argc, char* argv[]) {//main function, loops the print and player moves until an ending condition is met
    srand(time(0));
    char board[ROWS][COLUMNS];//creates the board

    for (int i = 0; i < ROWS; i++) {//fills board with empty space
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = SPACE;
        }
    }
    do {
        Print(board);
        SetPlayerMove(board);
        SetComputerMove(board);
    } while (DetermineBoardState(board) == GAME_UNFINISHED);
    cout << DetermineBoardState(board);
    return 0;
}
