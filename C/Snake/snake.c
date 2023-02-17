#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(){

    char field[10][21];
    int tail[100][2];
    int length = 1;
    tail[0][0] = 5;
    tail[0][1] = 5;
    int apple_x = 5, apple_y = 3;
    char key;

    srand(time(NULL));

    while (key != 'e'){
        system("cls");
        sprintf(field[0], "####################");

        for (int i = 1; i < 9; i++){
            sprintf(field[i], "#                  #");
        }

        sprintf(field[9], "####################");
        field[apple_y][apple_x] = '*';

        for (int i = 0; i < length; i++){
            if (i == 0){
            	field[tail[0][0]][tail[0][1]] = '@';
            }else
            field[tail[i][0]][tail[i][1]] = '.';
            }

        for (int i = 0; i < 10; i++){
            printf("%s\n", field[i]);
        }

        printf("your length = %d", length);

        key = getch();

        int ox = tail[0][1], oy = tail[0][0];

        if (key == 'w'){
            tail[0][0]--;
        }

        if (key == 's'){
            tail[0][0]++;
        }

        if (key == 'd'){
            tail[0][1]++;
        }

        if (key == 'a'){
            tail[0][1]--;
        }

        if (field[tail[0][0]][tail[0][1]] == '#' || field[tail[0][0]][tail[0][1]] == '.'){
            tail[0][1] = ox;
            tail[0][0] = oy;
            printf("\nGame over...");
            return 1;
        }else{
            for (int i = 1; i < length; i++){
                int temp = tail[i][1];
                tail[i][1] = ox;
                ox = temp;
                temp = tail[i][0];
                tail[i][0] = oy;
                oy = temp;
            }
        }

        if (tail[0][0] == apple_y && tail[0][1] == apple_x){
            while (tail[0][0] == apple_y && tail[0][1] == apple_x || field[apple_y][apple_x] == '.'){
                apple_y = rand() * 1.0 / RAND_MAX * 8 + 1;
                apple_x = rand() * 1.0 / RAND_MAX * 17 + 1;
            }

            tail[length][0] = oy;
            tail[length][1] = ox;
            length++;
        }
    }
    
    return 0;
}
