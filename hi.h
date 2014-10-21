#include <iostream>
#include <curses.h>
#include <ctime>
#include <vector.h>

//from recognize keyboard real time
#include <termios.h>
#include <term.h>
#include <unistd.h>

#include <sys/select.h>

#define MAX_Enemy 100

using namespace std;

void setup_game(void);

void play_game(void);

void end_game(void);

void playing_hi(void);

void print_enemy(int length_enemy,const char enemy[]);

//keyboard recognize & input - real time

static struct termios initial_settings, new_settings;
static int peek_character = -1;

void init_keyboard();
void close_keyboard();
int kbhit();
int readch();

//end