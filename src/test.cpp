#include <ncurses.h>
#include <string>
class test
{
private:
    int row,col;
    WINDOW *win;
    void cprint (const char *format, ...)
    {
        char buffer[256];
        va_list args;
        va_start (args, format);
        std::string in = buffer;
        mvwprintw(win,row/2,(col-vsprintf(buffer,format, args))/2,"%s",in.c_str()); 
        va_end (args);
        return;
    }
public:
    test(WINDOW*);
    ~test();
};

test::test(WINDOW* _win)
{
    win=_win;
    getmaxyx(win,row,col);
    delwin(_win); //idk if this will remove the other
}

test::~test()
{
    delwin(win);
}
