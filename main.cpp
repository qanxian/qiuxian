#include "gobang.h"
#include <iostream>
#include <string>
using namespace std;

int mon;   //0代表白方 1代表黑方
int remon;
int num;
int read=0;  //1代表F1 2代表F2
char abc;
string F;
string f;

int main(){
    GOBANG Chess;
    GOBANG sparechess[15][15];
    GOBANG chess[15][15];
    mon=0;

    for(int i=1; i>0; i++){
        cout<<"Welcome to the game of gobang!"<<endl;
        cout<<endl;
        cout<<"F1 Human-machine battle mode"<<endl;
        cout<<"F2 Two-player battle mode"<<endl;
        cout<<"F3 Save the current game information"<<endl;
        cout<<"F4 Read game information"<<endl;
        cout<<"F5 Exit the game"<<endl;
        cout<<"Please select a game mode:";
        cin>>F;

        if(F=="F4"&&read==0){
            cout<<"Read failed!"<<endl;
        }

        if(F=="F1"||(F=="F4"&&read==1)){
            mon=0;
            cout<<"Human-machine battle mode"<<endl;
            cout<<"You are the white side"<<endl;
            if(F=="F1"){
                Chess.black(8, 'h', chess);
            }
            if(F=="F4"&&read==1){
                Chess.givechess(sparechess,chess);
            }
            while(Chess.win(chess)==0){
                if(mon==0){
                    Chess.draw(chess);
                    cout<<"(F0 pass F3 save F5 quit) ";
                    cin>>f;
                    Chess.storethechess(sparechess,chess,f);
                    if(f=="F3"){
                        read=1;
                    }
                    if(f=="F5"){
                        break;
                    }
                    cout<<"Please drop the pawn:";
                    cin>>num>>abc;
                    if((num!=1&&num!=2&&num!=3&&num!=4&&num!=5&&num!=6&&num!=7&&num!=8&&num!=9&&num!=10&&num!=11&&num!=12&&num!=13&&num!=14&&num!=15)||(abc!='a'&&abc!='b'&&abc!='c'&&abc!='d'&&abc!='e'&&abc!='f'&&abc!='g'&&abc!='h'&&abc!='i'&&abc!='j'&&abc!='k'&&abc!='l'&&abc!='m'&&abc!='n'&&abc!='o')){
                        cout<<"Input error, please re-enter"<<endl;
                    }
                    else{
                        if(Chess.white(num, abc, chess)==0){
                            cout<<"Input error, please re-enter"<<endl;
                        }
                        else{mon=1;}
                    }
                }
                else{
                    Chess.chessauto(chess);
                    mon=0;
                }
            }
            if(f=="F5"){
                Chess.quit(chess);
                f="";
                continue;
            }
            if(Chess.win(chess)==1){
                Chess.draw(chess);
                cout<<"You win!"<<endl;
                break;
            }
            if(Chess.win(chess)==2){
                Chess.draw(chess);
                cout<<"You lose!"<<endl;
                break;
            }
        }

        else if(F=="F2"||(F=="F4"&&read==2)){
            cout<<"Two-player battle mode"<<endl;
            if(F=="F4"&&read==2){
                Chess.givechess(sparechess,chess);
                mon=remon;
            }
            while(Chess.win(chess)==0){
                if(mon==0){
                    Chess.draw(chess);
                    cout<<"(F0 pass F3 save F5 quit) ";
                    cin>>f;
                    Chess.storethechess(sparechess,chess,f);
                    if(f=="F3"){
                        remon=0;
                        read=2;
                    }
                    if(f=="F5"){
                        break;
                    }
                    cout<<"White side, please drop the pawn:";
                    cin>>num>>abc;
                    if((num!=1&&num!=2&&num!=3&&num!=4&&num!=5&&num!=6&&num!=7&&num!=8&&num!=9&&num!=10&&num!=11&&num!=12&&num!=13&&num!=14&&num!=15)||(abc!='a'&&abc!='b'&&abc!='c'&&abc!='d'&&abc!='e'&&abc!='f'&&abc!='g'&&abc!='h'&&abc!='i'&&abc!='j'&&abc!='k'&&abc!='l'&&abc!='m'&&abc!='n'&&abc!='o')){
                        cout<<"Input error, please re-enter"<<endl;
                    }
                    else{
                        if(Chess.white(num, abc, chess)==0){
                            cout<<"Input error, please re-enter"<<endl;
                        }
                        else{mon=1;}
                    }
                }
                else{
                    Chess.draw(chess);
                    cout<<"(F0 pass F3 save F5 quit) ";
                    cin>>f;
                    Chess.storethechess(sparechess,chess,f);
                    if(f=="F3"){
                        remon=1;
                        read=2;
                    }
                    if(f=="F5"){
                        break;
                    }
                    cout<<"Black side, please drop the pawn:";
                    cin>>num>>abc;
                    if((num!=1&&num!=2&&num!=3&&num!=4&&num!=5&&num!=6&&num!=7&&num!=8&&num!=9&&num!=10&&num!=11&&num!=12&&num!=13&&num!=14&&num!=15)||(abc!='a'&&abc!='b'&&abc!='c'&&abc!='d'&&abc!='e'&&abc!='f'&&abc!='g'&&abc!='h'&&abc!='i'&&abc!='j'&&abc!='k'&&abc!='l'&&abc!='m'&&abc!='n'&&abc!='o')){
                        cout<<"Input error, please re-enter"<<endl;
                    }
                    else{
                        if(Chess.black(num, abc, chess)==0){
                            cout<<"Input error, please re-enter"<<endl;
                        }
                        else{mon=0;}
                    }    
                }
            }
            if(f=="F5"){
                Chess.quit(chess);
                f="";
                continue;
            }
            if(Chess.win(chess)==1){
                Chess.draw(chess);
                cout<<"Congratulations to the white side for the victory!"<<endl;
                break;
            }
            if(Chess.win(chess)==2){
                Chess.draw(chess);
                cout<<"Congratulations to the black side for the victory!"<<endl;
                break;
            }
        }
    }
    
    system("pause");
	return 0;
}