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
    
    start_color();
    
	keypad(stdscr, TRUE);

    getmaxyx( stdscr,row,col );

	refresh();

    move( 0, 0 );

    init_pair(1, COLOR_WHITE, COLOR_WHITE);    
    init_pair(2, COLOR_WHITE, COLOR_CYAN);
    init_pair(3, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(4, COLOR_WHITE, COLOR_GREEN);    
    init_pair(5, COLOR_WHITE, COLOR_YELLOW); 
    init_pair(6, COLOR_WHITE, COLOR_BLUE); 
    init_pair(7, COLOR_WHITE, COLOR_RED); 
    init_pair(8, COLOR_WHITE, COLOR_BLACK); 

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
                getyx( stdscr, c_row, c_col );
                attron( COLOR_PAIR( 1 ) );
                addch(' ');
                attroff( COLOR_PAIR( 1 ) );
                move( c_row, c_col );
                break;

            case '2':
                getyx( stdscr, c_row, c_col );
                attron( COLOR_PAIR( 2 ) );
                addch(' ');
                attroff( COLOR_PAIR( 2 ) );
                move( c_row, c_col );
                break;


            case '3':
                getyx( stdscr, c_row, c_col );
                attron( COLOR_PAIR( 3 ) );
                addch(' ');
                attroff( COLOR_PAIR( 3 ) );
                move( c_row, c_col );
                break;

            case '4':
                getyx( stdscr, c_row, c_col );
                attron( COLOR_PAIR( 4 ) );
                addch(' ');
                attroff( COLOR_PAIR( 4 ) );
                move( c_row, c_col );
                break;

            case '5':
                getyx( stdscr, c_row, c_col );
                attron( COLOR_PAIR( 5 ) );
                addch(' ');
                attroff( COLOR_PAIR( 5 ) );
                move( c_row, c_col );
                break;

            case '6':
                getyx( stdscr, c_row, c_col );
                attron( COLOR_PAIR( 6 ) );
                addch(' ');
                attroff( COLOR_PAIR( 6 ) );
                move( c_row, c_col );
                break;

            case '7':
                getyx( stdscr, c_row, c_col );
                attron( COLOR_PAIR( 7 ) );
                addch(' ');
                attroff( COLOR_PAIR( 7 ) );
                move( c_row, c_col );
                break;

            case '8':
                getyx( stdscr, c_row, c_col );
                attron( COLOR_PAIR( 8 ) );
                addch(' ');
                attroff( COLOR_PAIR( 8 ) );
                move( c_row, c_col );
                break;

            default:
                break;
		}
	}
		
	endwin();
    
	return 0;
}
