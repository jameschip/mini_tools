#include <ncurses.h>

#include <fstream>
#include <iostream>
#include <string>


int main( int argc, char *argv[] ) {
    
    int row,col;
    int c_row, c_col = 0;
	int ch;
	initscr();
	cbreak();
    
	keypad(stdscr, TRUE);

    getmaxyx( stdscr,row,col );

	refresh();

    if ( argc >= 2 ) {

        std::fstream the_file ( argv[1] );

        if ( the_file.is_open() ) {

            std::string tp;
            int i = 0;

            while(std::getline(the_file, tp)){
                mvwprintw( stdscr, i++, 0, "%s", tp.c_str() );            
            }

            the_file.close();                   

        }
    }
    move( 0, 0 );
	while((ch = getch()) != KEY_F(1))
	{	
        switch(ch)
		{	

            case KEY_LEFT:
				getyx( stdscr, c_row, c_col );
                if ( c_col > 0)
                    wmove( stdscr, c_row, c_col - 1 );
				break;

			case KEY_RIGHT:
				getyx( stdscr, c_row, c_col );
                if ( c_col < col )
                    wmove( stdscr, c_row, c_col + 1 );
				break;

			case KEY_UP:
				getyx( stdscr, c_row, c_col );
                if ( c_row > 0)
                    wmove( stdscr, c_row - 1, c_col );
                break;

			case KEY_DOWN:
				getyx( stdscr, c_row, c_col );
                if ( c_row < row)
                    wmove( stdscr, c_row + 1, c_col );
				break;

            case KEY_BACKSPACE:
            case 127:
                getyx( stdscr, c_row, c_col );
                if ( c_col > 0) {
                    waddch( stdscr, ' ' );
                    wmove( stdscr, c_row, c_col );
                }
                break;
            
            case KEY_F(2): {
                std::remove( argv[1] );
                std::ofstream f;
                f.open( argv[1] );
                getyx( stdscr, c_row, c_col );
                if ( f.is_open() ) {

                    for ( int l = 0; l < row; l++ ) {
                        char * tmp = (char *)calloc( 1000, sizeof( char ) );
                        move( l, 0 );
                        instr( tmp );
                        f << tmp << std::endl;                    
                    }
                    f.close();
                move( c_row, c_col );
                }
                break;
            }
            default:
                break;
		}
	}
		
	endwin();
    
	return 0;
}
