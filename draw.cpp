#include <ncurses.h>

void add_colour( int c ) {
    attron( COLOR_PAIR( c ) );  
    addch(' ');
    attron( COLOR_PAIR( c ) );
}

int main( int argc, char *argv[] ) {
    
    int row,col;
    int c_row, c_col = 0;
	int ch;
    bool line = false;
    int last_colour = 8;
    
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
    init_pair(1, COLOR_WHITE, COLOR_BLACK); 
    init_pair(2, COLOR_WHITE, COLOR_RED); 
    init_pair(3, COLOR_WHITE, COLOR_GREEN);    
    init_pair(4, COLOR_WHITE, COLOR_YELLOW); 
    init_pair(5, COLOR_WHITE, COLOR_CYAN);
    init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(7, COLOR_WHITE, COLOR_BLUE); 
    init_pair(8, COLOR_BLACK, COLOR_WHITE);    
    bkgd( COLOR_PAIR(8) );

    clear();    

	while((ch = getch()) != KEY_F(1))
	{	
		getyx( stdscr, c_row, c_col );
        switch(ch)
		{	

            case KEY_LEFT:
                if ( c_col > 0) {
                    if ( line ) {
                        add_colour( last_colour );
                        wmove( stdscr, c_row, c_col - 1 );
                    } else {
                        wmove( stdscr, c_row, c_col - 1 );
                    }
                }
				break;

			case KEY_RIGHT:
                if ( c_col < col )
                    if ( line ) {
                        add_colour( last_colour ); 
                        wmove( stdscr, c_row, c_col + 1 );
                    } else {
                        wmove( stdscr, c_row, c_col + 1 );
                    }
				break;

			case KEY_UP:
                if ( c_row > 0)
                    if ( line ) {
                        add_colour( last_colour );
                        wmove( stdscr, c_row - 1, c_col );    
                    } else {
                        wmove( stdscr, c_row - 1, c_col );
                    }
                break;

			case KEY_DOWN:
                if ( c_row < row ) {
                    if ( line ) {
                        add_colour( last_colour );
                        wmove( stdscr, c_row + 1, c_col );     
                    } else {
                        wmove( stdscr, c_row + 1, c_col);
                    }
                }
				break;
            
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                last_colour = ch - 48;
                add_colour( last_colour );
                line = false;
                break;

            case 'l':
                line = !line;            

            default:
                break;
		}
	}
		
	endwin();
    
	return 0;
}

