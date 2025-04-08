

#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score;
int tailx[100], taily[100];

int ntail = 0;
enum edirection { stop = 0, Left, Right, Doen, Up };
edirection dir;

void setup() {
    gameover = false;
    dir = stop;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;



}
void draw() {
    system("cls");

    for (int i = 0; i < width + 1; i++)
        cout << '#';
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 or j == width - 1)
                cout << '#';
            if (i == y and j == x) 
                cout << '0';
            else if (i == fruity and j == fruitx)
                cout << 'f';          
            else {
                bool print = false;
                for (int k = 0; k < ntail; k++) {
                    if (tailx[k] == j and taily[k] == i) {
                        print = true;
                        cout << 'o';
                    }
                }
                if (!print) {
                    cout << ' ';
                }
            }

        }
        cout << endl;
    }
    for (int i = 0; i < width + 1; i++)
        cout << '#';
    cout << endl;
    cout << "Score " << " " << score << endl;



}
void input() {
    if (_kbhit()) {
        switch (_getch())
        {
        case 'a':
            dir = Left;
            break;
        case 'd':
            dir = Right;
            break;
        case 'w':
            dir = Up;
            break;
        case 's':
            dir = Doen;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }

}
void logic() {
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0] = x;
    taily[0] = y;
    for (int i = 1; i < ntail; i++) {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;


    }
    switch (dir)
    {
    case Left:
        x--;
        break;
    case Right:
        x++;
        break;
    case Doen:
        y++;
        break;
    case Up:
        y--;
        break;
    }
    //if (x > width or x < 0 or y > height or y < 0)
    //
    if (x >= width - 1) {
        x = 0;
    }
    else if (x < 0) {
        x = width - 2;
    }
    if (y >= height) {
        y = 0;
    }
    else if (y < 0) {
        y = height - 2;
    }
    for (int i = 0; i < ntail; i++) {
        if (tailx[i] == x and taily[i] == y) {
            gameover = true;
        }
    }
    if (x == fruitx and y == fruity) {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        ntail++;
    }

}

int main()
{
    setup();
    while (gameover == false) {
        draw();
        input();
        logic();
        Sleep(100);
    }

    return 0;
}

