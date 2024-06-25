#include<stdio.h>

char game_board[13][13];

void init_game_board() {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            game_board[i][j] = '~'; // initialize with water characters
        }
    }
}

void print_game_board(){
    int x = 1;
    char y = 'A';
    for(int i = 0; i <= 12; i++ ){
        for(int j = 0; j <= 12; j++){
            if(j == 0 && i >= 2 && i <= 11){
                printf("%c", y);
                y++;            
            }
            if(j == 0 && i == 0){
                printf("  ");
            }
            if(j == 1 && i >= 2 && i <=  11){
                printf("%c", '|');
            }
            if(j == 12 && i >= 2 && i < 12){
                printf("%c", '|');
            }
            if(i == 0 && j >= 2 && j <= 11){
                printf("%2d", x);
                x++;
            }
            if(i == 1 && j >= 2){
                printf("%2c", '-');
            }
            if(i == 12 && j >= 2){
                printf("%2c", '-');
            } else if (i >= 2 && j >= 2 && i <= 11 && j <= 11) {
                printf("%2c", game_board[i][j]); // print the game board cell
            }
        }
        printf("\n");
    }
}

void place_ship(int row, int col, int orientation, int size) {
    if (orientation == 0) { // horizontal
        for (int i = 0; i < size; i++) {
            game_board[row][col + i] = 'S'; // mark the ship's cells with 'S'
        }
    } else { // vertical
        for (int i = 0; i < size; i++) {
            game_board[row + i][col] = 'S'; // mark the ship's cells with 'S'
        }
    }
}

int main(){
    init_game_board();

    printf("MY_WATER_AREA\n");
    print_game_board();

    int ship_size = 4;
    int orientation;
    int row, col;

    printf("Place a ship on 4 cells:\n");
    printf("Enter orientation (0 for horizontal, 1 for vertical): ");
    scanf("%d", &orientation);

    printf("Enter starting row (A-J): ");
    char row_char;
    scanf(" %c", &row_char);
    row = row_char - 'A' + 2;

    printf("Enter starting column (1-10): ");
    scanf("%d", &col);
    col = col + 1;

    place_ship(row, col, orientation, ship_size);

    printf("MY_WATER_AREA\n");
    print_game_board();

    return 0;
}
