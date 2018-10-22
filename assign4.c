//ASSIGNMENT4
#include <stdio.h>
#include <stdlib.h>

void printBoard(int r, int c, char (*arr)[c]);
void placeShip5(int r, int c, char (*arr)[c]);
void placeShip3(int r, int c, char (*arr)[c]);
void placeShip4(int r, int c, char (*arr)[c]);

void main() {
  char board1[11][11] = {{' ','0','1','2','3','4','5','6','7','8','9'},{'0','O','O','O','O','O','O','O','O','O','O'},{'1','O','O','O','O','O','O','O','O','O','O'},{'2','O','O','O','O','O','O','O','O','O','O'},{'3','O','O','O','O','O','O','O','O','O','O'},{'4','O','O','O','O','O','O','O','O','O','O'},{'5','O','O','O','O','O','O','O','O','O','O'},{'6','O','O','O','O','O','O','O','O','O','O'},{'7','O','O','O','O','O','O','O','O','O','O'},{'8','O','O','O','O','O','O','O','O','O','O'},{'9','O','O','O','O','O','O','O','O','O','O'}}; //board where player 1 loads their ship

  char board2[11][11] = {{' ','0','1','2','3','4','5','6','7','8','9'},{'0','O','O','O','O','O','O','O','O','O','O'},{'1','O','O','O','O','O','O','O','O','O','O'},{'2','O','O','O','O','O','O','O','O','O','O'},{'3','O','O','O','O','O','O','O','O','O','O'},{'4','O','O','O','O','O','O','O','O','O','O'},{'5','O','O','O','O','O','O','O','O','O','O'},{'6','O','O','O','O','O','O','O','O','O','O'},{'7','O','O','O','O','O','O','O','O','O','O'},{'8','O','O','O','O','O','O','O','O','O','O'},{'9','O','O','O','O','O','O','O','O','O','O'}}; //board where player 2 loads their ship

  char gameBoard1[11][11] = {{' ','0','1','2','3','4','5','6','7','8','9'},{'0','O','O','O','O','O','O','O','O','O','O'},{'1','O','O','O','O','O','O','O','O','O','O'},{'2','O','O','O','O','O','O','O','O','O','O'},{'3','O','O','O','O','O','O','O','O','O','O'},{'4','O','O','O','O','O','O','O','O','O','O'},{'5','O','O','O','O','O','O','O','O','O','O'},{'6','O','O','O','O','O','O','O','O','O','O'},{'7','O','O','O','O','O','O','O','O','O','O'},{'8','O','O','O','O','O','O','O','O','O','O'},{'9','O','O','O','O','O','O','O','O','O','O'}}; //board where player 2 guesses player 1's ships

  char gameBoard2[11][11] = {{' ','0','1','2','3','4','5','6','7','8','9'},{'0','O','O','O','O','O','O','O','O','O','O'},{'1','O','O','O','O','O','O','O','O','O','O'},{'2','O','O','O','O','O','O','O','O','O','O'},{'3','O','O','O','O','O','O','O','O','O','O'},{'4','O','O','O','O','O','O','O','O','O','O'},{'5','O','O','O','O','O','O','O','O','O','O'},{'6','O','O','O','O','O','O','O','O','O','O'},{'7','O','O','O','O','O','O','O','O','O','O'},{'8','O','O','O','O','O','O','O','O','O','O'},{'9','O','O','O','O','O','O','O','O','O','O'}}; //board where player 1 guesses player 2's ships

  printf("This is a two player game of battlesip. Each player will put 3 ships\n");
  printf("on their board one of length 5, one of length 4, and one of length 3.\n");
  printf("You cannot overlap any of the ship. When loading the ships, you can see \n");
  printf("where you have put them, they will be denoted ith an S. All empty spots\n");
  printf("are denoted with an O. After loading all the ships players will alternate\n"); 
  printf("to guess where their opponints ships are. When you hit a ship, it will\n");
  printf("be denoted with H. If the guess is incorrect, it will be denoted with an X.\n");
  printf("Once all three boats have been sunken, the game is over.\n\n");

  printf("Player one, load your board:\n");
  printBoard(11,11,board1);
  placeShip5(11,11,board1);
  printBoard(11,11,board1);
  placeShip3(11,11,board1);
  printBoard(11,11,board1);
  placeShip4(11,11,board1);
  printBoard(11,11,board1);

  printf("Press enter to clear the screen, then let player two load their board.\n");
  if(getchar()=='\n'){
    system("clear");
  }

  printf("Player two, load your board:\n");
  printBoard(11,11,board2);
  placeShip5(11,11,board2);
  printBoard(11,11,board2);
  placeShip3(11,11,board2);
  printBoard(11,11,board2);
  placeShip4(11,11,board2);
  printBoard(11,11,board2);

  printf("Press enter to clear the screen, then start playing the game.\n");
  if(getchar()=='\n'){
    system("clear");
  }

  int hits1 = 0; //how many hits player one has made on player two's board
  int hits2 = 0; //how many hits player two has made on player one's board
  int depth1 = 0; //player 1's guess on player 2's board
  int depth2 = 0; //player 2's guess on player 2's board
  int width1 = 0; //player 1's guess on player 2's board
  int width2 = 0; //player 2's guess on player 2's board

  do{
    //player 1's turn
    printf("\nPlayer 1: choose coordinate on player 2's board seen below\n");
    printBoard(11,11,gameBoard2);
    printf("Enter depth coordinate:");
    scanf("%d",&depth2);
    printf("Enter width coordinate:");
    scanf("%d",&width2);
    if(board2[depth2+1][width2+1]=='S'){
      printf("HIT!\n");
      gameBoard2[depth2+1][width2+1]='H';
      board2[depth2+1][width2+1]='O';
      hits2++;
    }
    else{
      printf("no hit :'(\n");
    }
    if(hits2==12) break;
    //player 2's turn
    printf("\nPlayer 2: choose coordinate on player 1's board seen below\n");
    printBoard(11,11,gameBoard1);
    printf("Enter depth coordinate:");
    scanf("%d",&depth1);
    printf("Enter width coordinate:");
    scanf("%d",&width1);
    if(board1[depth1+1][width1+1]=='S'){
      printf("HIT!\n");
      gameBoard1[depth1+1][width1+1]='H';
      board1[depth1+1][width1+1]='O';
      hits1++;
    }
    else{
      printf("no hit :'(\n");
    }
  }while(hits1<12&&hits2<12);

  if(hits2==12){
    printf("Player 1 wins");
  }
  if(hits1==12){
    printf("Player 2 wins");
  }
}

void printBoard(int r, int c, char (*arr)[c]) { 
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%c ", arr[i][j]); 
    }
  printf("\n");
  }
}

void placeShip5(int r, int c, char (*arr)[c]) {
  int depth, width, option;
  int canPlace = 0; //like boolean to see if any valid coordinates were entered
  int up = 0;
  int right = 0;
  int down = 0;
  int left = 0;
  int count = 1;
  printf("Enter depth coordinate of length 5 ship:");
  scanf("%d",&depth);
  printf("Enter width coordinate of length 5 ship:");
  scanf("%d",&width);
  if(depth+5<=10&&depth>-1&&width>-1&&width<10) { //can put in down orienation
    printf("\nOption %d: ", count);
    //for loop for vertictal option from point going down
    for (int i=depth;i<depth+5; i++) {
      printf("(%d,%d) ", i, width);
    }
    down = count;
    count++;
    canPlace = 1;
    //down = 1;
  }
  if (width+5<=10&&width+1>0&&depth>-1&&depth<10) { //can put in right orientation
    printf("\nOption %d: ", count);
    //for loop for horizontal option from point going right
    for (int i=width;i<width+5; i++) {
      printf("(%d,%d) ", depth, i);
    }
    right = count;
    count++;
    canPlace = 1;
    //right = 1;
  }
  if (depth-5>=-1&&depth<10&&width>-1&&width<10) {  //can put in up orientation
    printf("\nOption %d: ", count);
    //for loop for vertictal option from point going up
    for (int i=depth;i>depth-5; i--) {
      printf("(%d,%d) ", i, width);
    }
    up = count;
    count++;
    canPlace = 1;
    //up = 1;
  }
  if (width-5>=-1&&width<10&&depth>-1&&depth<10) { //can put in left orientation
    printf("\nOption %d: ", count);
    //for loop for horizontal option from point going left
    for (int i=width;i>width-5; i--) {
      printf("(%d,%d) ", depth, i);
    }
    left = count;
    count++;
    canPlace = 1;
    //left = 1;
  }
  if(canPlace) {
    printf("\nWhich option ? ");
    scanf("%d", &option);
    if(down==option){
        for (int i=depth+1;i<=depth+5; i++) {
          arr[i][width+1] = 'S';
        }
    }
    else if(right==option) {
      for (int i=width+1;i<=width+5; i++) {
        arr[depth+1][i] = 'S';
      }
    }
    else if(up==option) {
      for (int i=depth+1;i>depth-4; i--) {
        arr[i][width+1] = 'S';
      }
    }
    else if(left==option){
      for (int i=width+1;i>width-4; i--) {
        arr[depth+1][i] = 'S';
      }
    }
    else {
      printf("not valid option\n");
    }
  }
  else {
    printf("not valid coordinates\n");
  }
}

void placeShip3(int r, int c, char (*arr)[c]) {
  int depth, width, option;
  int overlap = 1; // checks to see if coordinate of ship overlaps with existing ships
  //0=false means there is overlap, 1=true means no overlap
  if(overlap){
    int canPlace = 0; //like boolean to see if any valid coordinates were entered
    int up = 0;
    int right = 0;
    int down = 0;
    int left = 0;
    int count = 1;
    while(!canPlace){
    printf("Enter depth coordinate of length 3 ship:");
    scanf("%d",&depth);
    printf("Enter width coordinate of length 3 ship:");
    scanf("%d",&width);
    //check to see if entered coordinate overlaps with any existing ships
    if(arr[depth+1][width+1]=='S'){
      printf("overlap\n");
      overlap=0;
    }
    if(overlap){
      if(depth+3<=10&&depth>-1&&width>-1&&width<10&&arr[depth+1][width+1]!='S'&&arr[depth+2][width+1]!='S'&&arr[depth+3][width+1]!='S') { //can put in down orienation
        printf("\nOption %d: ", count);
        //for loop for vertictal option from point going down
        for (int i=depth;i<depth+3; i++) {
          printf("(%d,%d) ", i, width);
        }
        down = count;
        count++;
        canPlace = 1;
        //down = 1;
      }
      if (width+3<=10&&width>-1&&depth>-1&&depth<10&&arr[depth+1][width+1]!='S'&&arr[depth+1][width+2]!='S'&&arr[depth+1][width+3]!='S') { //can put in right orientation
        printf("\nOption %d: ", count);
        //for loop for horizontal option from point going right
        for (int i=width;i<width+3; i++) {
          printf("(%d,%d) ", depth, i);
        }
        right = count;
        count++;
        canPlace = 1;
        //right = 1;
      }
      if (depth-3>=-1&&depth<10&&width>-1&&width<10&&arr[depth+1][width+1]!='S'&&arr[depth][width+1]!='S'&&arr[depth-1][width+1]!='S') {  //can put in up orientation
        printf("\nOption %d: ", count);
        //for loop for vertictal option from point going up
        for (int i=depth;i>depth-3; i--) {
          printf("(%d,%d) ", i, width);
        }
        up = count;
        count++;
        canPlace = 1;
        //up = 1;
      }
      if (width-3>=-1&&width<10&&depth>-1&&depth<10&&arr[depth+1][width+1]!='S'&&arr[depth+1][width]!='S'&&arr[depth+1][width-1]!='S') { //can put in left orientation
        printf("\nOption %d: ", count);
        //for loop for horizontal option from point going left
        for (int i=width;i>width-3; i--) {
          printf("(%d,%d) ", depth, i);
        }
        left = count;
        count++;
        canPlace = 1;
        //left = 1;
      }
      if(canPlace) {
        printf("\nWhich option ? ");
        scanf("%d", &option);
        if(down==option){
          for (int i=depth+1;i<=depth+3; i++) {
            arr[i][width+1] = 'S';
          }
        }
        else if(right==option) {
          for (int i=width+1;i<=width+3; i++) {
            arr[depth+1][i] = 'S';
          }
        }
        else if(up==option) {
          for (int i=depth+1;i>depth-2; i--) {
            arr[i][width+1] = 'S';
          }
        }
        else if(left==option){
          for (int i=width+1;i>width-2; i--) {
            arr[depth+1][i] = 'S';
          }
        }
        else {
          printf("not valid option\n");
        }
      }
      else {
        printf("not valid coordinates\n");
      }
    }
  }
  }
}

void placeShip4(int r, int c, char (*arr)[c]) {
  int depth, width, option;
  int canPlace = 0; //like boolean to see if any valid coordinates were entered
  int up = 0;
  int right = 0;
  int down = 0;
  int left = 0;
  int count = 1;
  while(!canPlace){
  printf("Enter depth coordinate of length 4 ship:");
  scanf("%d",&depth);
  printf("Enter width coordinate of length 4 ship:");
  scanf("%d",&width);
  if(depth+4<=10&&depth>-1&&width>-1&&width<10&&arr[depth+1][width+1]!='S'&&arr[depth+2][width+1]!='S'&&arr[depth+3][width+1]!='S'&&arr[depth+4][width+1]!='S') { //can put in down orienation
    printf("\nOption %d: ", count);
    //for loop for vertictal option from point going down
    for (int i=depth;i<depth+4; i++) {
      printf("(%d,%d) ", i, width);
    }
    down = count;
    count++;
    canPlace = 1;
    //down = 1;
  }
  if (width+4<=10&&width>-1&&depth>-1&&depth<10&&arr[depth+1][width+1]!='S'&&arr[depth+1][width+2]!='S'&&arr[depth+1][width+3]!='S'&&arr[depth+1][width+4]!='S') { //can put in right orientation
    printf("\nOption %d: ", count);
    //for loop for horizontal option from point going right
    for (int i=width;i<width+4; i++) {
      printf("(%d,%d) ", depth, i);
    }
    right = count;
    count++;
    canPlace = 1;
    //right = 1;
  }
  if (depth-4>=-1&&depth<10&&width>-1&&width<10&&arr[depth+1][width+1]!='S'&&arr[depth][width+1]!='S'&&arr[depth-1][width+1]!='S'&&arr[depth-2][width+1]!='S') {  //can put in up orientation
    printf("\nOption %d: ", count);
    //for loop for vertictal option from point going up
    for (int i=depth;i>depth-4; i--) {
      printf("(%d,%d) ", i, width);
    }
    up = count;
    count++;
    canPlace = 1;
    //up = 1;
  }
  if (width-4>=-1&&width<10&&depth>-1&&depth<10&&arr[depth+1][width+1]!='S'&&arr[depth+1][width]!='S'&&arr[depth+1][width-1]!='S'&&arr[depth+1][width-2]!='S') { //can put in left orientation
    printf("\nOption %d: ", count);
    //for loop for horizontal option from point going left
    for (int i=width;i>width-4; i--) {
      printf("(%d,%d) ", depth, i);
    }
    left = count;
    count++;
    canPlace = 1;
    //left = 1;
  }
  if(canPlace) {
    printf("\nWhich option ? ");
    scanf("%d", &option);
    if(down){
      for (int i=depth+1;i<=depth+4; i++) {
        arr[i][width+1] = 'S';
      }
    }
    else if(right) {
      for (int i=width+1;i<=width+4; i++) {
        arr[depth+1][i] = 'S';
      }
    }
    else if(up) {
      for (int i=depth+1;i>depth-3; i--) {
        arr[i][width+1] = 'S';
      }
    }
    else if(left){
      for (int i=width+1;i>width-3; i--) {
        arr[depth+1][i] = 'S';
      }
    }
    else {
      printf("not valid option");
    }
  }
  else {
    printf("not valid coordinates\n");
  }
  }
}
