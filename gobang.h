#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

class GOBANG{
    protected:
        char chess;
        char whi='o';
        char bla='x';
        char blank=' ';
    public:
        GOBANG(){
            chess=blank;
        }
        void draw(GOBANG c[15][15]);
        int white(int num, char abc, GOBANG c[15][15]);
        int black(int num, char abc, GOBANG c[15][15]);
        int win(GOBANG c[15][15]);
        int chessauto(GOBANG c[15][15]);
        int storethechess(GOBANG s[15][15], GOBANG c[15][15], string f);
        void givechess(GOBANG s[15][15], GOBANG c[15][15]);
        void quit(GOBANG c[15][15]);
};

#endif