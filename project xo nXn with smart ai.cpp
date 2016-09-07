
#include<iostream>
#include "color.h"
#include<math.h>
#include <iomanip> // sizeofvalue
#include <conio.h>   // get
#include <fstream>
#include <time.h>
#include <string.h>

using namespace std;

#define linemenu "\n\t===================================================================\n" ;
#define cen "\t\t\t\t" ;
#define tab "\t\t" ;
typedef struct {
string name="",who ;
int point=0 ;
}p ;



class xo {
private :
    p eing[2] ;
    int row, colum, n, player=0, i, j, anws, winner=2,check=0;
    char **table;
    void line() {
        textcolor( 14 , 0 );
        cout << "\t\t\t" ;
        for( int col = 0 ; col < this->colum ; col++) {
            for( int row = 0 ; row < 5 ; row++) {
                cout << "-" ;
            }
            if( col < this->colum-1)
                cout << "|" ;
        }
        cout << endl;
        resetcolor();
     }
  /* void settable(){
        for( i = 0  ; i < this->row ; i++){
            for( j = 0; j < this->colum ; j++){
                    this->table[i][j] = 'A' ;
                }
            }
        }
 */

public :
    xo() {

    }
     //===============================================================================

    xo(int n) {
        this->row = n ;
        this->colum = n ;
        this->table = new char* [this->row];
        for( i = 0 ; i < this->row ; i++ ) {
            this->table[i] = new char [this->colum];
        }

    }

     //===============================================================================
    void buildtable(int n) {
        this->row = n ;
        this->colum = n ;
        this->table = new char* [this->row];
        for( i = 0 ; i < this->row ; i++ ) {
                this->table[i] = new char [this->colum];
        }
        resetTable();
        for ( int j = 0 ; j < 2 ; j++ ) {
            if( eing[j].name == "" ) {

                for ( i = 0 ; i < 2 ; i++ ) {
                    cout << "Who is " ;
                            if( this->i == 0) {
                                cout << 'X' ;
                                eing[i].who='X' ;
                            }
                            else {
                                cout << 'O' ;
                                eing[i].who='O' ;
                            }
                    cout << " : " ;
                    cin >> eing[i].name ;

                }
            }
        }
    }

    //===============================================================================

    void prttable() {
        system("cls");
        int count = 1;
        //line();
        cout << endl << endl ;
        for( i = 0 ; i < this->row  ; i++) {
            cout << "\t\t\t" ;
            for( j = 0 ; j < this->colum ; j++ ){
                if( j == 0 )
                    cout << setw(3) << fixed;
                else {
                    cout << setw(3) << fixed;
                    textcolor( 14 , 0 ) ;
                    cout << "|" ;
                    resetcolor() ;
                    cout << setw(3) << fixed;
                }
                if(this->table[i][j] != 'O' && this->table[i][j] != 'X') {
                    cout << count++;
                } else {
                    if( table[i][j]=='X' ) {
                    textcolor( 12 , 0 );
                    cout << table[i][j];
                    resetcolor();
                    } else {
                    textcolor( 9 , 0 );
                    cout << table[i][j];
                    resetcolor();
                      }
                    count++;
                  }

            }
            cout << "\n" ;
            if(i < this->row - 1 )
                line();

        }


            //cout << line3 ;

    }
    //===============================================================================
    void inputtable() {
        int row,colum ;
        for(int k = 0 ; k < pow(this->row , 2 ) && winner == 2 ; k++) {
            prttable();
            this->player = k % 2 ;
            do {
                    //cout << player << "\n" ;
                    cout << "Player  " ;
                    if( this->player == 0)
                        cout << 'X' ;
                    else
                        cout << 'O' ;
                    if(eing[this->player].name == "COM") {
                        anws = inputComOX();
                    }
                    else {
                        cout << "  choose : " ;
                        cin  >>  anws ;
                    }
                    row = --anws / this->row;
                    colum = anws % this->row;
                    //cout << row << colum ;
                    if( (table[row][colum] == 'X' || table[row][colum] == 'O') && eing[this->player].name != "COM") {
                        cout<<"NO !"<<endl ;
                        getch() ;
                    }
            }while ( anws < 0 || anws > pow(this->row,2) || table[row][colum] == 'X' || table[row][colum] == 'O' );
        this->table[row][colum] = (this->player==0) ? 'X':'O';
           // cin  this->table[row][colum];
        cout<<"OK. !"<<endl ;
        getch() ;
        checkwin();
        }
    }
        //===============================================================================
    void checkwin() {

        if( this->check == 0) {
            //µÐá¤§«éÒÂ
            for( i = 1 ; i < this->row ; i++ ) {
                    if( (this->table[0][0] == 'O' || this->table[0][0] == 'X' ) && this->table[0][0] == this->table[i][i] )
                        this->check=1 ;
                    else {
                        this->check=0 ;
                          break ;
                    }
            }
        }

        if( this->check == 0) {
            //µÐá¤§¢ÇÒ
            for( int last=this->row-1, i = 0 ; i < this->row ; i++, last-- ) {
                if( (this->table[0][this->row-1] == 'O' || this->table[0][this->row-1]== 'X' ) && this->table[0][this->row-1] == this->table[i][last] )
                    this->check = 1 ;
                else {
                    this->check = 0 ;
                    break ;
                }

            }
        }
        if( this->check == 0) {
          //á¹Ç¹Í¹
            for( i = 0 ; i < this->row ; i++ ) {
                for ( j = 1 ; j < this->row ; j++ ) {
                    if( ( this->table[i][0] == 'O' || this->table[i][0] == 'X' ) && this->table[i][0] == this->table[i][j] )
                        this->check=1 ;
                    else {
                        this->check=0 ;
                          break ;
                    }

                }
             if( this->check == 1 )
                    break ;
            }
        }

        if( this->check == 0) {
             //á¹ÇµÑé§
             for( i = 0 ; i < this->row ; i++ ) {
                for ( j = 1 ; j < this->row ; j++ ) {
                    if( ( this->table[0][i] == 'O' || this->table[0][i] == 'X' ) && this->table[0][i] == this->table[j][i] )
                        this->check=1 ;
                    else {
                        this->check=0 ;
                          break ;
                    }
                }
              if( this->check == 1 )
                    break ;
            }
        }

      //  getch();
            if(this->check == 1) {
                this->winner = this->player;
            }
    }

          //===============================================================================
        void prtwinner () {
        if( this->winner != 2) {
            cout << "Cong. for  " ;
            if( this->player == 0)
                    cout << 'X' ;
                else
                    cout << 'O' ;
            cout << "  is winner .\n\n" ;

            } else {
            cout << "You are draw.\n\n" ;

                }
        }
        //===============================================================================
        //menu
     void headmenu () {
            system("cls") ;
            textcolor( 10 , 0 ) ;
            cout << linemenu ;
            resetcolor() ;
            cout << "                 \\\\        //         ================  \n" ;
            cout << "                  \\\\      //          ||            ||  \n" ;
            cout << "                   \\\\    //           ||            ||  \n" ;
            cout << "                    \\\\  //            ||            ||  \n" ;
            cout << "                     \\\\//             ||            ||  \n" ;
            cout << "                     //\\\\             ||            ||  \n" ;
            cout << "                    //  \\\\            ||            ||  \n" ;
            cout << "                   //    \\\\           ||            ||  \n" ;
            cout << "                  //      \\\\          ||            ||  \n" ;
            cout << "                 //        \\\\         ================  \n" ;
            textcolor( 10 , 0 ) ;
            cout << linemenu ;
            resetcolor() ;

        }
        //===============================================================================
    void menu () {
        int n ;
        do {
            headmenu () ;
            cout << "\t\t\t\t[1] PLAY\n" ;
            cout << "\t\t\t\t[2] HOW TO PLAY\n" ;
            cout << "\t\t\t\t[3] RANK\n" ;
            cout << "\t\t\t\t[4] DEV.\n" ;
            cout << "\t\t\t\t[5] EXIT\n" ;
            textcolor( 5 , 0 ) ;
            cout << "\t\t\tYOU : " ;
            resetcolor() ;
            cin >> n ;
            if( n == 1 )
               menuplay() ;
            else if ( n == 2 )
                menuhowtoplay() ;
            else if ( n == 3 )
                menurank() ;
            else if ( n == 4 )
                menudev() ;

            } while( n != 5 ) ;

        //===============================================================================

        }
        void menuplay() {
            int b ;
            do {
                headmenu () ;
                cout << cen ;
                cout << "Enter table do you want ?\n" << cen;
                cout << "[1] EASY 3*3\n" << cen;
                cout << "[2] MEDIUM 5*5\n" << cen;
                cout << "[3] HARD 7*7\n" << cen;
                cout << "[4] N table\n" << cen;
                cout << "[5] back\n" << cen;
                cout << "YOU : " ;
                cin >> b;
                if ( b == 1 ) {
                    buildtable(3) ;
                    inputtable();
                    system("cls");

                    //end game
                    prttable() ;
                    prtwinner() ;

                    //addfile
                    rank() ;
                    showscore();
                    getch() ;
                } else if( b == 2 ) {
                    buildtable(5) ;
                    inputtable();
                    system("cls");

                    //end game
                    prttable() ;
                    prtwinner() ;

                    //addfile
                    rank();
                    showscore();
                } else if ( b == 3) {
                    buildtable(7) ;
                    inputtable();
                    system("cls");

                    //end game
                    prttable() ;
                    prtwinner() ;

                    //addfile
                    rank();
                    showscore();
                    getch() ;
                } else if ( b == 4 ) {
                    int c ;
                    cout << "What is table do you want ? : " ;
                    cin >> c;
                    buildtable(c) ;
                    inputtable();
                    system("cls");

                    //end game
                    prttable() ;
                    prtwinner() ;

                    //addfile
                    rank();
                    showscore();
                    getch() ;

                }
            player=0, winner=2,check=0 ;
        } while ( b != 5 );
    }
    //===============================================================================
    void  menuhowtoplay() {
        do {
            headmenu() ;
            cout << cen;
            textcolor( 12 , 0 ) ;
            cout << "HOW TO PLAY\n" ;
            resetcolor() ;
            cout << tab;
            cout << "X always goes first.\n" ;
            cout << tab;
            cout << "Players alternate placing X and O on the board until either\n" ;
            cout << tab;
            cout << "one player has straight row, horizontally,\n" ;
            cout << tab;
            cout << "vertically or diagonally\n" ;
            cout << tab;
            cout << "[1] BACK : " ;
            cin >> n;
        } while ( n != 1 ) ;

    }
    //===============================================================================
    void  menudev() {
        int n ;
        do {
        headmenu() ;
        cout << "\n" << cen;
        textcolor( 12 , 0 ) ;
        cout << "Name : Witthawin    Sirisiwaphak\n" ;
        resetcolor() ;
        cout << cen;
        textcolor( 12 , 0 ) ;
        cout << "ID_STD : 56-040626-3021-0\n" ;
        resetcolor() ;
        cout << cen;
        textcolor( 12 , 0 ) ;
        cout << "SEC 2 RC\n" ;
        resetcolor() ;
        cout << cen;
        cout << "[1] BACK : " ;
        cin >> n;
        } while ( n != 1 ) ;

     }
     //===============================================================================
     void menurank() {
         int b ;
        do {
            headmenu();
            showscore() ;

            cout << endl << cen ;
            cout << "[1] RESET\n" ;
            cout << cen ;
            cout << "[2] BACK  \n" ;
            cout << cen;
            cout << "YOU : " ;
            cin >> b ;
            if ( b == 1 ) {
                unlink("score.txt") ;
                for(i = 0 ; i < 2 ; i++) {
                    eing[i].point = 0;
                    eing[i].name = "";
                    eing[i].who = "";
                }
                cout << cen;
                cout << "THE SCORE IS RESETED ALREADY." ;
                getch();
            }
        } while ( b != 2 ) ;
     }
    //===============================================================================
    void showscore() {
        int i=0 ;
        ifstream fptr ; //inputfilestream
        fptr.open("score.txt") ;

        while( fptr  >>  eing[i].name  >>  eing[i].who  >>  eing[i].point ) {
            cout << tab ;
            cout <<"Name : "<<eing[i].name << "\tplay "<< eing[i].who << "\thas "<< eing[i].point <<" point ."<< endl ;
            i++ ;

        }
        fptr.close() ;
        if(fptr !=NULL)
        cout<<"\npress any key to continue" ;

    }
    //===============================================================================
    //file
    void rank() {
        ofstream fptr ; // outputfilestream
        fptr.open("score.txt") ;
        eing[winner].point+=1 ;
        for( i = 0 ; i < 2 ; i++ ) {
            fptr << eing[i].name  << " " << eing[i].who  << " " << eing[i].point << endl;
        }
         fptr.close() ;
    }

    //===============================================================================
    void resetTable() {
        for(int i = 0 ;  i < this->row ; i++) {
            for(int j = 0 ;  j < this->row ; j++) {
                this->table[i][j] = NULL;
            }
        }
    }

    //===============================================================================
     int inputComOX() {
        int ans, num = 0;
        //µÐá¤§«éÒÂ
        for( i = 0 ; i < this->row ; i++ ) {
            if( (this->table[0][0] == 'O' || this->table[0][0] == 'X' ) && this->table[0][0] == this->table[i][i] ) {
                num++;
            } else if(this->table[i][i] == NULL){
                ans = (((this->row - 1) * i) + 1) + i + i;
            } else {
                num = 0;
            }
        }
        if(num == this->row-1) {
            return ans;
        }

        for( int last=this->row-1, i = 0 ; i < this->row ; i++, last-- ) {
            if( (this->table[0][this->row-1] == 'O' || this->table[0][this->row-1]== 'X' ) && this->table[0][this->row-1] == this->table[i][last] ) {
                num++;
            } else if(this->table[i][last] == NULL){
                ans = (((this->row - 1) * i) + 1) + i + last;
            } else {
                num = 0;
            }
        }
        if(num == this->row-1) {
            return ans;
        }

        for( i = 0 ; i < this->row ; i++ ) {
            for ( j = 0 ; j < this->row ; j++ ) {
                if( ( this->table[i][0] == 'O' || this->table[i][0] == 'X' ) && this->table[i][0] == this->table[i][j] ) {
                    num++;
                } else if(this->table[i][j] == NULL) {
                    ans = (((this->row - 1) * i) + 1) + i + j;
                } else {
                    num = 0;
                }
            }
            if(num == this->row-1) {
                break;
            } else {
                num = 0;
            }
        }
        if(num == this->row-1) {
            return ans;
        }
        //á¹ÇµÑé§
         for( i = 0 ; i < this->row ; i++ ) {
            for ( j = 0 ; j < this->row ; j++ ) {
                if( ( this->table[0][i] == 'O' || this->table[0][i] == 'X' ) && this->table[0][i] == this->table[j][i] ) {
                    num++;
                } else if(this->table[j][i] == NULL) {
                    ans = (((this->row - 1) * j) + 1) + j + i;
                } else {
                    num = 0;
                }
            }
            if(num == this->row-1) {
                break;
            } else {
                num = 0;
            }
        }
        if(num == this->row-1) {
            return ans;
        }

        srand (time(NULL));
        cout << "RAN : ";
        ans = rand() % ((this->row * this->row)) + 1;
        cout << ans << endl;
        return ans;
    }
};
    //===============================================================================
int main() {
    xo xoe;
    xoe.menu() ;
}
