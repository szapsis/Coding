/* The Most Common Chess Openings 

https://www.thesprucecrafts.com/most-common-chess-openings-611517

Keys: Space - change opening, ESC - exit. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void fillChess(char chess[][8], int i, int j) {

    char black[] = { "rnbqkbnrp" };
    char white[] = { "RNBQKBNRP" };

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {
            if (i == 0) { // fill with black and white figures
                chess[i][j] = black[j];
            }
            else if (i == 1) {
                chess[i][j] = black[8];
            }
            else if (i == 6) {
                chess[i][j] = white[8];
            }
            else if (i == 7) {
                chess[i][j] = white[j];
            }
            else {
                chess[i][j] = ' ';
            }
        }
    }
}

void printChess(char chess[][8], int i, int j) {

    char line[] = { "  -------------------------------------------------" };

    char fillLetters[] = { "@@@@@" };
    char fillEmpty[] = { "     " };

    printf("\n      a     b     c     d     e     f     g     h\n %s", line);

    for (int i = 0, scaleY = 8; i < 8; i++, scaleY--) {

        char fillSymbol1[100] = {
            "|     |@@@@@|     |@@@@@|     |@@@@@|     |@@@@@|" };
        char fillSymbol2[100] = {
            "|@@@@@|     |@@@@@|     |@@@@@|     |@@@@@|     |" };

        if (i % 2 != 0) {
            strcpy(fillSymbol2, fillSymbol1);
        }
        else {
            strcpy(fillSymbol1, fillSymbol2);
        }

        printf("\n   %s", fillSymbol1);

        for (int j = 0; j < 8; j++) {

            if (j == 0) {

                if (i == 2 && j == 0 || i == 4 && j == 0) { // fill cells: a6 and a4
                    printf("\n %d |%s", scaleY, fillLetters);
                }
                else if (i == 3 && j == 0 ||
                    i == 5 && j == 0) { // fill cells: a5 and a3
                    printf("\n %d |%s", scaleY, fillEmpty);
                }
                else {
                    printf("\n %d |  %c  ", scaleY, chess[i][j]);
                }

            }
            else if (j == 2 && i == 2 || j == 4 && i == 2 || j == 6 && i == 2) {
                if (chess[i][j] == ' ') {
                    printf("|%s", fillLetters);
                }
                else {
                    printf("|  %c  ", chess[i][j]);
                }
            }
            else if (j == 1 && i == 3 || j == 3 && i == 3 || j == 5 && i == 3) {
                if (chess[i][j] == ' ') {
                    printf("|%s", fillLetters);
                }
                else {
                    printf("|  %c  ", chess[i][j]);
                }
            }
            else if (j == 2 && i == 4 || j == 4 && i == 4 || j == 6 && i == 4) {
                if (chess[i][j] == ' ') {
                    printf("|%s", fillLetters);
                }
                else {
                    printf("|  %c  ", chess[i][j]);
                }
            }
            else if (j == 1 && i == 5 || j == 3 && i == 5 || j == 5 && i == 5) {
                if (chess[i][j] == ' ') {
                    printf("|%s", fillLetters);
                }
                else {
                    printf("|  %c  ", chess[i][j]);
                }
            }

            else if (j == 7) {
                if (j == 7 && i == 2 || j == 7 && i == 4) { // fill cell h6 and h4
                    printf("|%s| %d\n", fillEmpty, scaleY);
                }
                else if (j == 7 && i == 3 ||
                    j == 7 && i == 5) { // fill cell h5 and h3
                    printf("|%s| %d\n", fillLetters, scaleY);
                }
                else {
                    printf("|  %c  | %d\n", chess[i][j], scaleY);
                }
            }
            else {
                printf("|  %c  ", chess[i][j]);
            }
        }
        printf("   %s\n %s", fillSymbol1, line);
    }

    printf("\n      a     b     c     d     e     f     g     h\n");
}

void ruyLopez(char chess[][8], int i, int j) {

    char line7[] = { "ppp pppp" };
    char line6[] = { "   p    " };
    char line4[] = { "    P   " };
    char line2[] = { "PPPP PPP" };

    for (i = 0; i < 8; i++) {

        for (j = 1; j < 2; j++) {
            chess[j][i] = line7[i];
        }
        for (j = 2; j < 3; j++) {
            chess[j][i] = line6[i];
        }
        for (j = 4; j < 5; j++) {
            chess[j][i] = line4[i];
        }
        for (j = 6; j < 7; j++) {
            chess[j][i] = line2[i];
        }
    }
}

void italianGame(char chess[][8], int i, int j) {

    char line8[] = { "r bqkbnr" };
    char line7[] = { "pppp ppp" };
    char line6[] = { "  n     " };
    char line5[] = { "    p   " };
    char line4[] = { "  B P   " };
    char line3[] = { "     N  " };
    char line2[] = { "PPPP PPP" };
    char line1[] = { "RNBQK  R" };

    for (i = 0; i < 8; i++) {

        for (j = 0; j < 1; j++) {
            chess[j][i] = line8[i];
        }

        for (j = 1; j < 2; j++) {
            chess[j][i] = line7[i];
        }
        for (j = 2; j < 3; j++) {
            chess[j][i] = line6[i];
        }
        for (j = 3; j < 4; j++) {
            chess[j][i] = line5[i];
        }
        for (j = 4; j < 5; j++) {
            chess[j][i] = line4[i];
        }
        for (j = 5; j < 6; j++) {
            chess[j][i] = line3[i];
        }
        for (j = 6; j < 7; j++) {
            chess[j][i] = line2[i];
        }
        for (j = 7; j < 8; j++) {
            chess[j][i] = line1[i];
        }
    }
}

void sicilianDefense(char chess[][8], int i, int j) {

    char line7[] = { "pp ppppp" };
    char line5[] = { "  p     " };
    char line4[] = { "    P   " };
    char line2[] = { "PPPP PPP" };

    for (i = 0; i < 8; i++) {

        for (j = 1; j < 2; j++) {
            chess[j][i] = line7[i];
        }
        for (j = 3; j < 4; j++) {
            chess[j][i] = line5[i];
        }
        for (j = 4; j < 5; j++) {
            chess[j][i] = line4[i];
        }
        for (j = 6; j < 7; j++) {
            chess[j][i] = line2[i];
        }
    }
}

void frenchDefense(char chess[][8], int i, int j) {

    char line7[] = { "pppp ppp" };
    char line6[] = { "    p   " };
    char line4[] = { "    P   " };
    char line2[] = { "PPPP PPP" };

    for (i = 0; i < 8; i++) {

        for (j = 1; j < 2; j++) {
            chess[j][i] = line7[i];
        }

        for (j = 2; j < 3; j++) {
            chess[j][i] = line6[i];
        }

        for (j = 4; j < 5; j++) {
            chess[j][i] = line4[i];
        }

        for (j = 6; j < 7; j++) {
            chess[j][i] = line2[i];
        }
    }
}

void caroKannDefense(char chess[][8], int i, int j) {

    char line7[] = { "pp ppppp" };
    char line6[] = { "  p     " };
    char line4[] = { "    P   " };
    char line2[] = { "PPPP PPP" };

    for (i = 0; i < 8; i++) {

        for (j = 1; j < 2; j++) {
            chess[j][i] = line7[i];
        }

        for (j = 2; j < 3; j++) {
            chess[j][i] = line6[i];
        }

        for (j = 4; j < 5; j++) {
            chess[j][i] = line4[i];
        }

        for (j = 6; j < 7; j++) {
            chess[j][i] = line2[i];
        }
    }
}

void pircDefense(char chess[][8], int i, int j) {

    char line7[] = { "ppp pppp" };
    char line6[] = { "   p    " };
    char line4[] = { "    P   " };
    char line2[] = { "PPPP PPP" };

    for (i = 0; i < 8; i++) {

        for (j = 1; j < 2; j++) {
            chess[j][i] = line7[i];
        }

        for (j = 2; j < 3; j++) {
            chess[j][i] = line6[i];
        }

        for (j = 4; j < 5; j++) {
            chess[j][i] = line4[i];
        }

        for (j = 6; j < 7; j++) {
            chess[j][i] = line2[i];
        }
    }
}

void queensGambit(char chess[][8], int i, int j) {

    char line7[] = { "ppp pppp" };
    char line5[] = { "   p    " };
    char line4[] = { "  PP    " };
    char line2[] = { "PP  PPPP" };

    for (i = 0; i < 8; i++) {

        for (j = 1; j < 2; j++) {
            chess[j][i] = line7[i];
        }
        for (j = 3; j < 4; j++) {
            chess[j][i] = line5[i];
        }
        for (j = 4; j < 5; j++) {
            chess[j][i] = line4[i];
        }
        for (j = 6; j < 7; j++) {
            chess[j][i] = line2[i];
        }
    }
}

void indianDefenses(char chess[][8], int i, int j) {

    char line8[] = { "rnbqkb r" };
    char line6[] = { "     n  " };
    char line4[] = { "   P    " };
    char line2[] = { "PPP PPPP" };

    for (i = 0; i < 8; i++) {

        for (j = 0; j < 1; j++) {
            chess[j][i] = line8[i];
        }
        for (j = 2; j < 3; j++) {
            chess[j][i] = line6[i];
        }
        for (j = 4; j < 5; j++) {
            chess[j][i] = line4[i];
        }
        for (j = 6; j < 7; j++) {
            chess[j][i] = line2[i];
        }
    }
}

void englishOpening(char chess[][8], int i, int j) {

    char line4[] = { "  P     " };
    char line2[] = { "PP PPPPP" };

    for (i = 0; i < 8; i++) {

        for (j = 4; j < 5; j++) {
            chess[j][i] = line4[i];
        }
        for (j = 6; j < 7; j++) {
            chess[j][i] = line2[i];
        }
    }
}

void retiOpening(char chess[][8], int i, int j) {

    char line3[] = { "     N  " };
    char line1[] = { "RNBQKB R" };

    for (i = 0; i < 8; i++) {

        for (j = 5; j < 6; j++) {
            chess[j][i] = line3[i];
        }
        for (j = 7; j < 8; j++) {
            chess[j][i] = line1[i];
        }
    }
}

void keyFuction() {

    int z;
    do {
        z = getch();
        if (z == 27) {
            exit(0);
        }
    } while (z != 32);
}

int main(void) {

    while (1) {

        char chess[8][8];
        char cross[] = { "---------- " };

        system("cls");
        fillChess(chess, 8, 8);
        printf("\n\t    The Most Common Chess Openings");
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        ruyLopez(chess, 8, 8);
        printf("\n\t %s Ruy Lopez %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        fillChess(chess, 8, 8);
        italianGame(chess, 8, 8);
        printf("\n\t %s Italian Game %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        fillChess(chess, 8, 8);
        sicilianDefense(chess, 8, 8);
        printf("\n\t %s Sicilian Defense %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        fillChess(chess, 8, 8);
        frenchDefense(chess, 8, 8);
        printf("\n\t %s French Defense %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        fillChess(chess, 8, 8);
        caroKannDefense(chess, 8, 8);
        printf("\n\t %s Caro-Kann Defense %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        fillChess(chess, 8, 8);
        pircDefense(chess, 8, 8);
        printf("\n\t %s Pirc Defense %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        fillChess(chess, 8, 8);
        queensGambit(chess, 8, 8);
        printf("\n\t %s Queen's Gambit %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        fillChess(chess, 8, 8);
        indianDefenses(chess, 8, 8);
        printf("\n\t %s Indian Defenses %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        fillChess(chess, 8, 8);
        englishOpening(chess, 8, 8);
        printf("\n\t %s English Opening %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

        system("cls");
        fillChess(chess, 8, 8);
        retiOpening(chess, 8, 8);
        printf("\n\t %s Reti Opening %s", cross, cross);
        printChess(chess, 8, 8);
        keyFuction();

    }

    return 0;
}
