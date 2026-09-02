#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

// Turn tracker: 1 = White, 0 = Black
int turn = 1;

// Helper function to check if a piece is White (Uppercase)
// Helper: check if a piece is White (A-Z)
int isWhitePiece(char piece) {
    return (piece >= 'A' && piece <= 'Z');
}

// Helper function to check if a piece is Black (Lowercase)
// Helper: check if a piece is Black (a-z)
int isBlackPiece(char piece) {
    return (piece >= 'a' && piece <= 'z');
}

// Check if straight line path is clear (for Rook and Queen)
int isStraightPathClear(int r1, int c1, int r2, int c2) {
    int stepR = 0;
    int stepC = 0;

    if (r1 == r2) {
        stepC = (c2 > c1) ? 1 : -1;
    } else if (c1 == c2) {
        stepR = (r2 > r1) ? 1 : -1;
    } else {
        return 0; // Not a straight line
    }

    int currR = r1 + stepR;
    int currC = c1 + stepC;
    while (currR != r2 || currC != c2) {
        if (board[currR][currC] != '.') {
            return 0; // Blocked by another piece
        }
        currR += stepR;
        currC += stepC;
    }
    return 1;
}

// Check if diagonal path is clear (for Bishop and Queen)
int isDiagonalPathClear(int r1, int c1, int r2, int c2) {
    int dr = abs(r2 - r1);
    int dc = abs(c2 - c1);

    if (dr != dc) return 0; // Not a diagonal

    int stepR = (r2 > r1) ? 1 : -1;
    int stepC = (c2 > c1) ? 1 : -1;

    int currR = r1 + stepR;
    int currC = c1 + stepC;
    while (currR != r2 && currC != c2) {
        if (board[currR][currC] != '.') {
            return 0; // Blocked by another piece
        }
        currR += stepR;
        currC += stepC;
    }
    return 1;
}

// Validate movement rules for each piece type
int isPieceMoveLegal(char piece, int r1, int c1, int r2, int c2) {
    int dr = abs(r2 - r1);
    int dc = abs(c2 - c1);
    char dest = board[r2][c2];

    switch (piece) {
        // --- KNIGHT (L-Shape, can jump over other pieces) ---
        case 'N':
        case 'n':
            return (dr == 1 && dc == 2) || (dr == 2 && dc == 1);

        // --- ROOK (Straight lines, path must be clear) ---
        case 'R':
        case 'r':
            return (r1 == r2 || c1 == c2) && isStraightPathClear(r1, c1, r2, c2);

        // --- BISHOP (Diagonals, path must be clear) ---
        case 'B':
        case 'b':
            return (dr == dc) && isDiagonalPathClear(r1, c1, r2, c2);

        // --- QUEEN (Straight or Diagonal, path must be clear) ---
        case 'Q':
        case 'q':
            if (r1 == r2 || c1 == c2) {
                return isStraightPathClear(r1, c1, r2, c2);
            }
            if (dr == dc) {
                return isDiagonalPathClear(r1, c1, r2, c2);
            }
            return 0;

        // --- KING (1 step in any direction) ---
        case 'K':
        case 'k':
            return (dr <= 1 && dc <= 1);

        // --- WHITE PAWN ---
        case 'P':
            // 1 square forward (must be empty)
            if (c1 == c2 && r2 == r1 - 1 && dest == '.') {
                return 1;
            }
            // 2 squares forward from starting row 6 (both squares must be empty)
            if (c1 == c2 && r1 == 6 && r2 == 4 && board[5][c1] == '.' && dest == '.') {
                return 1;
            }
            // Capture diagonally (1 step up-left or up-right)
            if (r2 == r1 - 1 && dc == 1 && isBlackPiece(dest)) {
                return 1;
            }
            return 0;

        // --- BLACK PAWN ---
        case 'p':
            // 1 square forward (must be empty)
            if (c1 == c2 && r2 == r1 + 1 && dest == '.') {
                return 1;
            }
            // 2 squares forward from starting row 1 (both squares must be empty)
            if (c1 == c2 && r1 == 1 && r2 == 3 && board[2][c1] == '.' && dest == '.') {
                return 1;
            }
            // Capture diagonally (1 step down-left or down-right)
            if (r2 == r1 + 1 && dc == 1 && isWhitePiece(dest)) {
                return 1;
            }
            return 0;

        default:
            return 0;
    }
}

void printBoard() {
    printf("\n  a b c d e f g h\n");
    printf("\n    a   b   c   d   e   f   g   h\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        printf("%d | ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
            printf("%c | ", board[i][j]);
        }
        printf("%d\n", 8 - i);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("  a b c d e f g h\n\n");
    printf("    a   b   c   d   e   f   g   h\n\n");
}

int makeMove(char col1, int row1, char col2, int row2) {
    col1 = tolower(col1);
    col2 = tolower(col2);

    int startCol = col1 - 'a';
    int startRow = 8 - row1;
    int endCol = col2 - 'a';
    int endRow = 8 - row2;

    // 1. Check if coordinates are inside the 8x8 board
    // 1. Boundary check
    if (startCol < 0 || startCol > 7 || startRow < 0 || startRow > 7 ||
        endCol < 0 || endCol > 7 || endRow < 0 || endRow > 7) {
        printf("Error: Coordinates out of board bounds! Use a-h and 1-8.\n");
        return 0; // Move failed
        printf(">> [Error] Coordinates out of bounds! Columns: a-h, Rows: 1-8.\n");
        return 0;
    }

    char srcPiece = board[startRow][startCol];
    char destPiece = board[endRow][endCol];

    // 2. Check if source square is empty
    // 2. Cannot pick an empty square
    if (srcPiece == '.') {
        printf("Error: There is no piece on the starting square!\n");
        printf(">> [Error] No piece at %c%d!\n", col1, row1);
        return 0;
    }

    // 3. Check if it is the current player's piece
    // 3. Ensure the player moves their own piece
    if (turn == 1 && !isWhitePiece(srcPiece)) {
        printf("Error: It is White's turn! You must pick a White piece (capital letter).\n");
        printf(">> [Error] It's White's turn! Select a White piece (Uppercase).\n");
        return 0;
    }
    if (turn == 0 && !isBlackPiece(srcPiece)) {
        printf("Error: It is Black's turn! You must pick a Black piece (lowercase letter).\n");
        printf(">> [Error] It's Black's turn! Select a Black piece (lowercase).\n");
        return 0;
    }

    // 4. Prevent capturing your own piece (Friendly Fire)
    // 4. Prevent capturing own piece
    if (turn == 1 && isWhitePiece(destPiece)) {
        printf("Error: You cannot capture your own White piece!\n");
        printf(">> [Error] You cannot capture your own White piece at %c%d!\n", col2, row2);
        return 0;
    }
    if (turn == 0 && isBlackPiece(destPiece)) {
        printf("Error: You cannot capture your own Black piece!\n");
        printf(">> [Error] You cannot capture your own Black piece at %c%d!\n", col2, row2);
        return 0;
    }

    // Move is valid for now -> update the board
    // 5. Check piece-specific movement rules
    if (!isPieceMoveLegal(srcPiece, startRow, startCol, endRow, endCol)) {
        printf(">> [Error] Illegal move for %c from %c%d to %c%d!\n", srcPiece, col1, row1, col2, row2);
        return 0;
    }

    // 6. Execute the move
    board[endRow][endCol] = srcPiece;
    board[startRow][startCol] = '.';

    // Switch turn (1 becomes 0, 0 becomes 1)
    // 7. Switch turns
    turn = 1 - turn;
    return 1; // Move successful
    printf(">> [Success] Moved %c from %c%d to %c%d\n", srcPiece, col1, row1, col2, row2);
    return 1;
}

int main() {
    char input[100];
    char c1, c2;
    int r1, r2;

    printf("=========================================\n");
    printf("        WELCOME TO C-CHESS GAME          \n");
    printf("=========================================\n");
    printf("How to play: Type moves like 'e2 e4' or 'e2e4'\n");
    printf("Type 'quit' or 'q' anytime to exit.\n");

    while (1) {
        printBoard();

        if (turn == 1) {
            printf("[White's Turn] Enter move (e.g., e2 e4) or 'q 0 q 0' to quit: ");
            printf("[White's Turn] Enter move: ");
        } else {
            printf("[Black's Turn] Enter move (e.g., e7 e5) or 'q 0 q 0' to quit: ");
            printf("[Black's Turn] Enter move: ");
        }
        fflush(stdout); // Ensures the prompt appears immediately in terminal

        if (scanf(" %c%d %c%d", &c1, &r1, &c2, &r2) != 4) {
            printf("Exiting game...\n");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        if (c1 == 'q') {
            printf("Game ended.\n");
        // Check for quit
        if (input[0] == 'q' || input[0] == 'Q' || strncmp(input, "exit", 4) == 0) {
            printf("\nThanks for playing! Goodbye.\n");
            break;
        }

        // Parse move: try "e2 e4", "e2e4", "e2-e4"
        int parsed = sscanf(input, " %c%d %c%d", &c1, &r1, &c2, &r2);
        if (parsed != 4) {
            parsed = sscanf(input, " %c%d%c%d", &c1, &r1, &c2, &r2);
        }
        if (parsed != 4) {
            parsed = sscanf(input, " %c%d-%c%d", &c1, &r1, &c2, &r2);
        }

        if (parsed != 4) {
            printf(">> [Invalid format] Please enter your move like: e2 e4 (from square to square)\n");
            continue;
        }

        makeMove(c1, r1, c2, r2);
    }

    return 0;
}