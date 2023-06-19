#include "gobang.h"
#include <iostream>
#include <string>
using namespace std;

void GOBANG::draw(GOBANG c[15][15]){
    cout<<"   a  b  c  d  e  f  g  h  i  j  k  l  m  n  o"<<endl;
    for(int i=0; i<15; i++){
        if(i<9){   
            cout<<i+1<<"  ";
        }
        else{
            cout<<i+1<<" ";
        }
        for(int j=0; j<15; j++){
            cout<<c[i][j].chess<<"  ";
        }
        cout<<endl;
    }   
}

int GOBANG::white(int num, char abc, GOBANG c[15][15]){
    int a;
    if(abc=='a'){a=0;} if(abc=='b'){a=1;} if(abc=='c'){a=2;} if(abc=='d'){a=3;} if(abc=='e'){a=4;} if(abc=='f'){a=5;} if(abc=='g'){a=6;} if(abc=='h'){a=7;} if(abc=='i'){a=8;} if(abc=='j'){a=9;} if(abc=='k'){a=10;} if(abc=='l'){a=11;} if(abc=='m'){a=12;} if(abc=='n'){a=13;} if(abc=='o'){a=14;}
    if(c[num-1][a].chess==whi||c[num-1][a].chess==bla){
        return 0;
    }
    else{
        c[num-1][a].chess=whi;
        return 1;
    }    
}
int GOBANG::black(int num, char abc, GOBANG c[15][15]){
    int a;
    if(abc=='a'){a=0;} if(abc=='b'){a=1;} if(abc=='c'){a=2;} if(abc=='d'){a=3;} if(abc=='e'){a=4;} if(abc=='f'){a=5;} if(abc=='g'){a=6;} if(abc=='h'){a=7;} if(abc=='i'){a=8;} if(abc=='j'){a=9;} if(abc=='k'){a=10;} if(abc=='l'){a=11;} if(abc=='m'){a=12;} if(abc=='n'){a=13;} if(abc=='o'){a=14;}
    if(c[num-1][a].chess==whi||c[num-1][a].chess==bla){
        return 0;
    }
    else{
        c[num-1][a].chess=bla;
        return 1;
    }    
}

int GOBANG::win(GOBANG c[15][15]){
    for(int i=0; i<15; i++){      //横向
        for(int j=0; j<11; j++){
            if(c[i][j].chess==whi&&c[i][j+1].chess==whi&&c[i][j+2].chess==whi&&c[i][j+3].chess==whi&&c[i][j+4].chess==whi){                
                    return 1;    //1代表白方赢
            }
            if(c[i][j].chess==bla&&c[i][j+1].chess==bla&&c[i][j+2].chess==bla&&c[i][j+3].chess==bla&&c[i][j+4].chess==bla){  
                    return 2;    //2代表黑方赢
            }
        }
    }
    for(int i=0; i<11; i++){      //纵向
        for(int j=0; j<15; j++){
            if(c[i][j].chess==whi&&c[i+1][j].chess==whi&&c[i+2][j].chess==whi&&c[i+3][j].chess==whi&&c[i+4][j].chess==whi){
                    return 1;
            }
            if(c[i][j].chess==bla&&c[i+1][j].chess==bla&&c[i+2][j].chess==bla&&c[i+3][j].chess==bla&&c[i+4][j].chess==bla){
                    return 2;
            }
        }
    }
    for(int i=0; i<11; i++){      //左斜
        for(int j=4; j<15; j++){
            if(c[i][j].chess==whi&&c[i+1][j-1].chess==whi&&c[i+2][j-2].chess==whi&&c[i+3][j-3].chess==whi&&c[i+4][j-4].chess==whi){
                    return 1;    //1代表白方赢
            }
            if(c[i][j].chess==bla&&c[i+1][j-1].chess==bla&&c[i+2][j-2].chess==bla&&c[i+3][j-3].chess==bla&&c[i+4][j-4].chess==bla){
                    return 2;    //2代表黑方赢
            }
        }
    }
    for(int i=0; i<11; i++){      //右斜
        for(int j=0; j<11; j++){
            if(c[i][j].chess==whi&&c[i+1][j+1].chess==whi&&c[i+2][j+2].chess==whi&&c[i+3][j+3].chess==whi&&c[i+4][j+4].chess==whi){
                    return 1;    //1代表白方赢
            }
            if(c[i][j].chess==bla&&c[i+1][j+1].chess==bla&&c[i+2][j+2].chess==bla&&c[i+3][j+3].chess==bla&&c[i+4][j+4].chess==bla){
                    return 2;    //2代表黑方赢
            }
        }
    }
    return 0;            
}

int GOBANG::chessauto(GOBANG c[15][15]){
    //强势进攻
    for(int i=0; i<15; i++){      //横向四个
        for(int j=1; j<11; j++){
            if(c[i][j].chess==bla&&c[i][j+1].chess==bla&&c[i][j+2].chess==bla&&c[i][j+3].chess==bla){
                if(c[i][j-1].chess==blank){
                    c[i][j-1].chess=bla;
                    return 0;
                }
                else if(c[i][j+4].chess==blank){
                    c[i][j+4].chess=bla;
                    return 0;
                }
            }
        }
    }
    for(int i=1; i<11; i++){      //纵向四个
        for(int j=0; j<15; j++){
            if(c[i][j].chess==bla&&c[i+1][j].chess==bla&&c[i+2][j].chess==bla&&c[i+3][j].chess==bla){
                if(c[i-1][j].chess==blank){
                    c[i-1][j].chess=bla;
                    return 0;
                }
                else if(c[i+4][j].chess==blank){
                    c[i+4][j].chess=bla;
                    return 0;
                }
            }
        }
    }
    for(int i=1; i<11; i++){      //左斜四个
        for(int j=4; j<14; j++){
            if(c[i][j].chess==bla&&c[i+1][j-1].chess==bla&&c[i+2][j-2].chess==bla&&c[i+3][j-3].chess==bla){
                if(c[i-1][j+1].chess==blank){
                    c[i-1][j+1].chess=bla;
                    return 0;
                }
                else if(c[i+4][j-4].chess==blank){
                    c[i+4][j-4].chess=bla;
                    return 0;
                }
            }
        }
    }
    for(int i=1; i<11; i++){      //右斜四个
        for(int j=1; j<11; j++){
            if(c[i][j].chess==bla&&c[i+1][j+1].chess==bla&&c[i+2][j+2].chess==bla&&c[i+3][j+3].chess==bla){
                if(c[i-1][j-1].chess==blank){
                    c[i-1][j-1].chess=bla;
                    return 0;
                }
                else if(c[i+4][j+4].chess==blank){
                    c[i+4][j+4].chess=bla;
                    return 0;
                }
            }
        }
    }
    //防守
    for(int i=0; i<15; i++){      //横向四个
        for(int j=0; j<11; j++){
            if(c[i][j].chess==whi&&c[i][j+1].chess==whi&&c[i][j+2].chess==blank&&c[i][j+3].chess==whi&&c[i][j+4].chess==whi){
                c[i][j+2].chess=bla;    
                return 0;
            }
        }
    }
    for(int i=0; i<11; i++){      //纵向四个
        for(int j=0; j<15; j++){
            if(c[i][j].chess==whi&&c[i+1][j].chess==whi&&c[i+2][j].chess==blank&&c[i+3][j].chess==whi&&c[i+4][j].chess==whi){
                c[i+2][j].chess=bla;    
                return 0;
            }
        }
    }
    for(int i=0; i<11; i++){      //左斜四个
        for(int j=4; j<15; j++){
            if(c[i][j].chess==whi&&c[i+1][j-1].chess==whi&&c[i+2][j-2].chess==blank&&c[i+3][j-3].chess==whi&&c[i+4][j-4].chess==whi){
                c[i+2][j-2].chess=bla;    
                return 0;
            }
        }
    }
    for(int i=0; i<11; i++){      //右斜四个
        for(int j=0; j<11; j++){
            if(c[i][j].chess==whi&&c[i+1][j+1].chess==whi&&c[i+2][j+2].chess==blank&&c[i+3][j+3].chess==whi&&c[i+4][j+4].chess==whi){
                c[i+2][j+2].chess=bla;    
                return 0;
            }
        }
    }
    for(int i=0; i<15; i++){      //横向三个
        for(int j=1; j<12; j++){
            if(c[i][j].chess==whi&&c[i][j+1].chess==whi&&c[i][j+2].chess==whi){
                if(c[i][j-1].chess==blank){
                    c[i][j-1].chess=bla;
                    return 0;
                }
                else if(c[i][j+3].chess==blank){
                    c[i][j+3].chess=bla;
                    return 0;
                }
            }
        }
    }  
    for(int i=1; i<12; i++){      //纵向三个
        for(int j=0; j<15; j++){
            if(c[i][j].chess==whi&&c[i+1][j].chess==whi&&c[i+2][j].chess==whi){
                if(c[i-1][j].chess==blank){
                    c[i-1][j].chess=bla;
                    return 0;
                }
                else if(c[i+3][j].chess==blank){
                    c[i+3][j].chess=bla;
                    return 0;
                }
            }
        }
    }
    for(int i=1; i<12; i++){      //左斜三个
        for(int j=3; j<14; j++){
            if(c[i][j].chess==whi&&c[i+1][j-1].chess==whi&&c[i+2][j-2].chess==whi){
                if(c[i-1][j+1].chess==blank){
                    c[i-1][j+1].chess=bla;
                    return 0;
                }
                else if(c[i+3][j-3].chess==blank){
                    c[i+3][j-3].chess=bla;
                    return 0;
                }
            }
        }
    }
    for(int i=1; i<12; i++){      //右斜三个
        for(int j=1; j<12; j++){
            if(c[i][j].chess==whi&&c[i+1][j+1].chess==whi&&c[i+2][j+2].chess==whi){
                if(c[i-1][j-1].chess==blank){
                    c[i-1][j-1].chess=bla;
                    return 0;
                }
                else if(c[i+3][j+3].chess==blank){
                    c[i+3][j+3].chess=bla;
                    return 0;
                }
            }
        }
    }
    //弱势进攻
    for(int i=0; i<15; i++){      //横向三个
        for(int j=1; j<12; j++){
            if(c[i][j].chess==bla&&c[i][j+1].chess==bla&&c[i][j+2].chess==bla){
                if(c[i][j-1].chess==blank){
                    c[i][j-1].chess=bla;
                    return 0;
                }
                else if(c[i][j+3].chess==blank){
                    c[i][j+3].chess=bla;
                    return 0;
                }
            }
        }
    }
    for(int i=1; i<12; i++){      //纵向三个
        for(int j=0; j<15; j++){
            if(c[i][j].chess==bla&&c[i+1][j].chess==bla&&c[i+2][j].chess==bla){
                if(c[i-1][j].chess==blank){
                    c[i-1][j].chess=bla;
                    return 0;
                }
                else if(c[i+3][j].chess==blank){
                    c[i+3][j].chess=bla;
                    return 0;
                }
            }
        }
    }
    for(int i=1; i<12; i++){      //左斜三个
        for(int j=3; j<14; j++){
            if(c[i][j].chess==bla&&c[i+1][j-1].chess==bla&&c[i+2][j-2].chess==bla){
                if(c[i-1][j+1].chess==blank){
                    c[i-1][j+1].chess=bla;
                    return 0;
                }
                else if(c[i+3][j-3].chess==blank){
                    c[i+3][j-3].chess=bla;
                    return 0;
                }
            }
        }
    }
    for(int i=1; i<12; i++){      //右斜三个
        for(int j=1; j<12; j++){
            if(c[i][j].chess==bla&&c[i+1][j+1].chess==bla&&c[i+2][j+2].chess==bla){
                if(c[i-1][j-1].chess==blank){
                    c[i-1][j-1].chess=bla;
                    return 0;
                }
                else if(c[i+3][j+3].chess==blank){
                    c[i+3][j+3].chess=bla;
                    return 0;
                }
            }
        }
    }
    
    for(int i=1; i<14; i++){      //例外情况
        for(int j=1; j<14; j++){
            if(c[i][j].chess==bla){
                if(c[i-1][j].chess==blank){
                    c[i-1][j].chess=bla;
                    return 0;
                }
                if(c[i+1][j].chess==blank){
                    c[i+1][j].chess=bla;
                    return 0;
                }
                if(c[i][j-1].chess==blank){
                    c[i][j-1].chess=bla;
                    return 0;
                }
                if(c[i][j+1].chess==blank){
                    c[i][j+1].chess=bla;
                    return 0;
                }
            }
        }
    }
}

int GOBANG::storethechess(GOBANG s[15][15], GOBANG c[15][15], string f){
    if(f=="F0"||f=="F5"){
        return 0;
    }
    else if(f=="F3"){
        for(int i=0; i<15; i++){      
            for(int j=0; j<15; j++){
                s[i][j].chess=c[i][j].chess;
            }
        }
        cout<<"Save successfully!"<<endl;
        return 0;
    }
}

void GOBANG::givechess(GOBANG s[15][15], GOBANG c[15][15]){
    for(int i=0; i<15; i++){      
        for(int j=0; j<15; j++){
            c[i][j].chess=s[i][j].chess;
        }
    }
}

void GOBANG::quit(GOBANG c[15][15]){
    for(int i=0; i<15; i++){      
        for(int j=0; j<15; j++){
            c[i][j].chess=blank;
        }
    }
}