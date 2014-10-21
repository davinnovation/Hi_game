#include "hi.h"

void setup_game(void)
{
	system("clear");
	
	cout << "========================================================\n" <<
			" The Game : Hi_________________ Concept CGI\n\n" <<
			" Coded by Davi Innovation ( davinnovation@gmail.com) \n" <<
			" Version : 0.1v\n" <<
			"========================================================\n\n" << endl;
	
}

void play_game(void)
{
	char input = -1;
	
	cout << "Start game : p\tEnd game : e\n" <<endl;
	
	cin >> input;
	
	switch (input)
	{
		case 'p':
			playing_hi();
			break;
		case 'e':
			cout << "Ending game..." << endl;
			break;
		default:
			cout << "Wrong input!!!" << endl; 
	}
}

void end_game(void)
{
	cout << "Thank you for playing...\n" <<endl;
	
	cout << "Coded by Davi Innovation\n\nEg Project" << endl;
}

void playing_hi(void)
{
	char enemy[MAX_Enemy];
	int length_enemy=0;
	int score=0;
	char input_attack=1;
	
	time_t pre_time;
	time_t post_time;
	
	time(&pre_time);	// get current time
	post_time = pre_time + 1000;
	
	while (1)
	{
		system("clear");

		if(post_time - pre_time >= 1)
		{
			//add_enemy();
			enemy[length_enemy]=rand()%('z'-'a') + 'a';
			length_enemy++;
			enemy[length_enemy]='\0';
			//reset_time();
			time(&pre_time);
			post_time = pre_time;
		}
		
		else
		{
			time(&post_time);
		}
		
		cout << "\nscore : " << score << endl;
		print_enemy(length_enemy,enemy);

		
		system("sleep 0.1");
		if(kbhit())
		{
			input_attack = readch();
		}
		
		if(input_attack == ' ')	// spacebar pressed... close
			return ;
		
		if(input_attack == enemy[length_enemy-1])
		{
			//success_attack();
			enemy[length_enemy - 1] = '\0';
			length_enemy--;
			score++;
			input_attack = -1;
		}
		
		if(length_enemy >= MAX_Enemy)
			break;
	}
}

void init_keyboard()
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}

void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}

int kbhit()
{
    char ch;
    int nread;

    if(peek_character != -1)
        return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);

    if(nread == 1) {
        peek_character = ch;
        return 1;
    }
    return 0;
}

int readch()
{
    char ch;

    if(peek_character != -1) {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0,&ch,1);
    return ch;
}

void print_enemy(int length_enemy,const char enemy[])
{
	for (int i = length_enemy - 1 ; i >= 0 ; i--)
	{
		cout << enemy[i];
	}
	
	cout << endl;
}