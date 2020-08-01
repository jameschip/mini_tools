#include <ncurses.h>

int main( int argc, char *argv[] ) {
    
    int row,col;
    int c_row, c_col = 0;
	int ch;
	initscr();
	cbreak();
    noecho();
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }
    
	keypad(stdscr, TRUE);
    getmaxyx( stdscr,row,col );
    move( 0, 0 );
	refresh();

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);    
    init_pair(2, COLOR_WHITE, COLOR_CYAN);
    init_pair(3, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(4, COLOR_WHITE, COLOR_GREEN);    
    init_pair(5, COLOR_WHITE, COLOR_YELLOW); 
    init_pair(6, COLOR_WHITE, COLOR_BLUE); 
    init_pair(7, COLOR_WHITE, COLOR_RED); 
    init_pair(8, COLOR_WHITE, COLOR_BLACK); 
    bkgd( COLOR_PAIR(1) );

    clear();    

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
            
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                attron( COLOR_PAIR( ch - 48 ) );
                addch(' ');
                attroff( COLOR_PAIR( ch - 48 ) );
                break;

            default:
                break;
		}
	}
		
	endwin();
    
	return 0;
}
