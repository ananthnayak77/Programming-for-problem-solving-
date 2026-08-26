#include <stdio.h>

// Board representation: Uppercase = White, Lowercase = Black, '.' = Empty
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

void printBoard() {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("  a b c d e f g h\n\n");
}

void parseInput(char col1, int row1, char col2, int row2) {
    int startCol = col1 - 'a';
    int startRow = 8 - row1;
    int endCol = col2 - 'a';
    int endRow = 8 - row2;

    // Simple boundary check
    if (startCol < 0 || startCol > 7 || startRow < 0 || startRow > 7 ||
        endCol < 0 || endCol > 7 || endRow < 0 || endRow > 7) {
        printf("Invalid coordinates! Please enter valid board squares (e.g., e2 e4).\n");
        return;
    }

    // Move execution
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = '.';
}

int main() {
    char c1, c2;
    int r1, r2;

    while (1) {
        printBoard();
        printf("Enter move (e.g., e2 e4): ");
        if (scanf(" %c%d %c%d", &c1, &r1, &c2, &r2) != 4) {
            break; // Exit if invalid input structure
        }
        parseInput(c1, r1, c2, r2);
    }

    return 0;
}