#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::cout, std::cin, std::endl, std::string;
void printBoard(char board[3][3]);
bool checkWin (char board [3][3], char player);

int main(){
cout << "Welcome to Tic-Tac-Toe \n";
string player1;
cout << " Enter a name for player 1 (X): ";
cin >> player1;
string player2;
cout << " Enter a name for player 2 (O): ";
cin >> player2;
char board[3][3] = { // 3 rows and 3 columns
     {' ', ' ', ' '},
     {' ', ' ', ' '},
     {' ', ' ', ' '}
};

string currentPlayer;
std::srand(std::time(0));
int playsFirst = std::rand() % 2;// randomly picks which player goes first
char currentTurn;
  if (playsFirst == 0){
    currentPlayer = player1; // player 1 is X
    currentTurn = 'X';
  } else {
      currentPlayer = player2; // player 2 is O
      currentTurn = 'O';
    }

int turn;
int row;
int col;
  for (turn = 0; turn < 9; turn++){
     printBoard(board);
     while(true){
       cout << currentPlayer << " Enter a row (0-2) and column (0-2): ";
       cin >> row >> col;
       if (row < 0 || row > 2 || col < 0 || col > 2){
         cout << "Invaid move. Try again.";
       }  else {
            break;
          }
     }
     board[row][col] = currentTurn;
     if (checkWin(board, currentTurn)) {
         printBoard(board);
         cout << currentPlayer << " wins!\n";
         break; // Exit the loop after a win.
     }
     if (currentPlayer == player1){ // swaps the players after each turn
        currentPlayer = player2;
        currentTurn = 'O';
     } else {
         currentPlayer = player1;
         currentTurn = 'X';
       }
  }

  if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')){ // ends the game is the board is full
       cout << "Draw! Neither player wins";
  }


return 0;
}

void printBoard(char board[3][3]){ // function to print the board
  for (int i = 0; i < 3; i++){
      cout << " | ";
      for (int j = 0; j < 3; j++){
        cout << board[i][j] << " | ";
      }
      cout << "\n -------------- \n";
  }

}


bool checkWin(char board[3][3], char player){
  for (int i = 0; i < 3; i++){
    if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // checks rows 
       (board[0][i] == player && board[1][i] == player && board[2][i] == player)){ // checks columns
       return true;
    }
  }
  if ((board[0][0] == player && board[1][1] == player && board[2][2] == player)|| // ckecks diagonals
     (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
  }
  return false;
}



