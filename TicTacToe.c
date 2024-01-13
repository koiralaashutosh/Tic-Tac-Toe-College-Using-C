// TICTACTOE IN C BETWEEN TWO USERS

#include <stdio.h> //to include the standard input and output library functions

char square[10] = {
    '0', '1', '2', '3', '4', '5','6', '7', '8', '9'}; // global array of type 'char' that stores 10 elements

int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark);

// void gives no return value, int gives return value

int main() {

  int gameStatus;
  char mark;
  player = 1;
  do {
    displayBoard();
    // change turns

    if (player % 2) {
      player = 1;
    } else {
      player = 2;
    }

    printf("Player %d is requested to enter a number: ", player);
    scanf("%d", &choice);

    // set the correct character based on player turn
    if (player == 1) {
      mark = 'X';
    } else {
      mark = 'O';
    }

    // set board choice on user choice or invalid choice
    markBoard(mark); // updating the choice of Player
    gameStatus = checkForWin();
    player++; // turn goes to player 2
  } while (gameStatus == -1);

  if (gameStatus == 1) {
    printf("==>Player %d wins\n\n", --player);
  } else {
    printf("==>Draw\n\n");
  }

  displayBoard();
  return 0;
}
/*
Function to return game status
1 for game is over with result
-1 for game is in progress
0 for game is over and no result
*/
int checkForWin() {
  int returnValue = 0;
  if (square[1] == square[2] && square[2] == square[3]) {
    returnValue = 1;
  }

  else if (square[4] == square[5] && square[5] == square[6]) {
    returnValue = 1;
  }

  else if (square[7] == square[8] && square[8] == square[9]) {
    returnValue = 1;
  }

  else if (square[1] == square[4] && square[4] == square[7]) {
    returnValue = 1;
  }

  else if (square[2] == square[5] && square[5] == square[8]) {
    returnValue = 1;
  }

  else if (square[3] == square[6] && square[6] == square[9]) {
    returnValue = 1;
  }

  else if (square[1] == square[5] && square[5] == square[9]) {
    returnValue = 1;
  }

  else if (square[3] == square[5] && square[5] == square[7]) {
    returnValue = 1;
  }

  else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
           square[4] != '4' && square[5] != '5' && square[6] != '6' &&
           square[7] != '7' && square[8] != '8' && square[9] != '9') {
    returnValue = 0;
  }

  else {
    returnValue = -1;
  }
  return returnValue;
}
/*
FUNCTION THAT DRAWS TIC TAC TOE BOARD WITH PLAYERS
*/
void displayBoard() {
  printf("\n\n\t TIC TAC TOE \n\n");
  printf("Player 1 (X) - Player 2 (O)\n\n\n");
  printf("  |   |   \n");
  printf("%c | %c | %c \n", square[1], square[2], square[3]);
  printf("__| __| __\n");
  printf("  |   | \n");
  printf("%c | %c | %c \n", square[4], square[5], square[6]);
  printf("__| __| __\n");
  printf("%c | %c | %c \n", square[7], square[8], square[9]);
  printf("  |   | \n\n");
}

/*Set the board with correct character X and O in the correct spot*/
void markBoard(char mark) {
  if (choice == 1 && square[1] == '1')
    square[1] = mark;
  else if (choice == 2 && square[2] == '2') {
    square[2] = mark;
  } 
  else if (choice == 3 && square[3] == '3') {
    square[3] = mark;
  } 
  else if (choice == 4 && square[4] == '4') {
    square[4] = mark;
  } 
  else if (choice == 5 && square[5] == '5') {
    square[5] = mark;
  } 
  else if (choice == 6 && square[6] == '6') {
    square[6] = mark;
  } 
  else if (choice == 7 && square[7] == '7') {
    square[7] = mark;
  } 
  else if (choice == 8 && square[8] == '8') {
    square[8] = mark;
  } 
  else if (choice == 9 && square[9] == '9') {
    square[9] = mark;
  } 
  else {
    printf("Invalid Move");
    player--; // turn goes to the person who made the Invalid move
  }
}