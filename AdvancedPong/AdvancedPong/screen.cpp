#include "Screen.h"
#include"utils.h"
#include<iostream>
#include"Board.h"
#include <conio.h>


void Screen::ClearScreen()
{
	system("cls");
}

//draw the screen borders
void Screen::MakeLayout()
{
	setColor(COLOR::WHITE_TEXT);
	gotoxy(0, 0);
	std::cout << "	      __   __        __              ___  ___ ___  __     __  \n";
	std::cout << "	     |__) /  \\ |\\ | / _`       __     |  |__   |  |__) | /__` \n";
	std::cout << "	     |    \\__/ | \\| \\__>              |  |___  |  |  \\ | .__/  \n";
                                                           
                                                                
	setColor(COLOR::TEAL_FADE_BACKGROUND);
	gotoxy(0, 3);
	std::cout << "                                                                                 ";
	for (int i = 4; i <= 25; i++)
	{
		gotoxy(0, i);
		std::cout << " ";
		gotoxy(80, i);
		std::cout << " ";
	}
	gotoxy(0, 25);
	for (int i = 0; i <= 80; i++)
	{
		std::cout << ' ';
	}

}

//draw the screen off instructions
void Screen::present()
{
	setColor(COLOR::GREEN_TEXT);
	ClearScreen();
	std::cout << "welcome to Aviram and Yonatan **Pong - Tetris**\n\n";
	std::cout << "Use the following key binds:\n\n";
	std::cout << "      LEFT Player:                    RIGHT Player:\n";
	std::cout << "       UP  |   DOWN                       UP |  DOWN\n";
	std::cout << "    Q or q |  A or a                  P or p |  L or l\n";
	std::cout << "                         ___..-.---.---.--..___\n";
	std::cout << "                   _..-- `.`.   `.  `.  `.      --.._\n";
	std::cout << "                  /    ___________\\   \\   \\______    \\ \n";
	std::cout << "                 |   |.-----------`.  `.  `.---.|   |\n";
	std::cout << "                 |`. |'  \\`.        \\   \\   \\  '|   |\n";
	std::cout << "                 |`. |'   \\ `-._     `.  `.  `.'|   |\n";
	std::cout << "                /|   |'    `-._o)\\  /(o\\   \\   \\|   |\\	\n";
	std::cout << "              .' |   |'  `.     .'  '.  `.  `.  `.  | `.\n";
	std::cout << "             /  .|   |'    `.  (_.==._)   \\   \\   \\ |.  \\         _.--.\n";
	std::cout << "           .' .' |   |'      _.-======-._  `.  `.  `. `. `.    _.-_.-'\\\\ \n";
	std::cout << "          /  /   |   |'    .'   |_||_|   `.  \\   \\   \\  \\  \\ .'_.'     ||\n";
	std::cout << "         / .'    |`. |'   /_.-'========`-._\\  `.  `-._`._`. \\(.__      :|\n";
	std::cout << "        ( '      |`. |'.______________________.'\\      _.) ` )`-._`-._/ /\n";
	std::cout << "         \\\\      |   '.------------------------.'`-._-'    //     `-._.'\n";
	std::cout << "         _\\\\_    \\    |      GOOD LUCK         |    '     //\n";
	std::cout << "        (_  _)    '-._|________________________|_.-'|   _//_\n";
	std::cout << "                                                       (_  _)\n";
	/*std::cout << "      .'   \\     |`-._ `-._   `-._`-._/ /      /    |    \\  \\ \n";
	std::cout << "     /      `.   |    `-._ `-._   `-._|/      /     |    /   `.\n";
	std::cout << "    /  / / /. )  |  `-._  `-._ `-._          /     /   .'      \\ \n";
	std::cout << "   | | | \\ \\|/   |  `-._`-._  `-._ `-._     /     /.  ( .\\ \\ \\  \\ \n";
	std::cout << "    \\ \\ \\ \\/     |  `-._`-._`-._  `-._ `-._/     /  \\  \\|/ / | | | \n";
	std::cout << "     `.\\_\\/       `-._  `-._`-._`-._  `-._/|    /|   \\   \\/ / / /\n";
	std::cout << "                 /    `-._  `-._`-._`-._  ||   / |    \\   \\/_/.'\n";
	std::cout << "               .'         `-._  `-._`-._  ||  /  |     \\ \n";
	std::cout << "              /           / . `-._  `-._  || /   |      \\ \n";
	std::cout << "             '\\          / /      `-._    ||/'._.'       \\ \n";
	std::cout << "              \\`.      .' /           `-._|/              \\ \n";
	std::cout << "               `.`-._.' .'               \\               .'\n";
	std::cout << "                 `-.__\\/                 `\\            .' '\n";
	std::cout << "                                           \\`.       _.' .'\n";
	std::cout << "                                            `.`-._.-' _.'\n";
	std::cout << "                                              `-.__.-'\n";*/
	gotoxy(0, 0);
}



//game over screen
void Screen::gameover()
{
	setColor(COLOR::RED_TEXT);
	std::cout << " #####     #    #     # ####### ####### #     # ####### ######\n";
	std::cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
	std::cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
	std::cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
	std::cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
	std::cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
	std::cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
	Sleep(5000);

}

//when continue game re draw everything
void Screen::Redrawgame(const Board *L, const Board *R,const Ball &b,const Bricks &brickmanager)
{
	ClearScreen();
	MakeLayout();
	L->draw();
	R->draw();
	b.draw();
	brickmanager.draw();
	drawLifes(L,R);
	
	

}
//launch screen
void Screen::launch()
{
	gotoxy(0, 8);
	setColor(COLOR::RED_TEXT);
	std::cout << " /$$$$$$$                                                    /$$$$$$$$             /$$               /$$          \n";
	std::cout << "| $$__  $$                                                  |__  $$__/            | $$              |__/          \n";
	std::cout << "| $$  \\ $$  /$$$$$$  /$$$$$$$   /$$$$$$                        | $$     /$$$$$$  /$$$$$$    /$$$$$$  /$$  /$$$$$$$\n";
	std::cout << "| $$$$$$$/ /$$__  $$| $$__  $$ /$$__  $$       /$$$$$$         | $$    /$$__  $$|_  $$_/   /$$__  $$| $$ /$$_____/\n";
	std::cout << "| $$____/ | $$  \\ $$| $$  \\ $$| $$  \\ $$      |______/         | $$   | $$$$$$$$  | $$    | $$  \\__/| $$|  $$$$$$ \n";
	std::cout << "| $$      | $$  | $$| $$  | $$| $$  | $$                       | $$   | $$_____/  | $$ /$$| $$      | $$ \\____  $$\n";
	std::cout << "| $$      |  $$$$$$/| $$  | $$|  $$$$$$$                       | $$   |  $$$$$$$  |  $$$$/| $$      | $$ /$$$$$$$/\n";
	std::cout << "|__/       \\______/ |__/  |__/ \\____  $$                       |__/    \\_______/   \\___/  |__/      |__/|_______/ \n";
	std::cout << "                               /$$  \\ $$                                                                          \n";
	std::cout << "                              |  $$$$$$/                                                                          \n";
	std::cout << "                               \\______/                                                                           \n";
	Sleep(1500);
	ClearScreen();
                                                                                               

	setColor(COLOR::TEAL_TEXT);
	std::cout << "		__________________________________________________________\n";
	std::cout << "		| OFFo oON                                               |\n";
	std::cout << "		| .----------------------------------------------------. |\n";
	std::cout << "		| |  .----------------------------------------------.  | |\n";
	std::cout << "		| |  |              *Aviram & Yonatan*              |  | |\n";
	std::cout << "		| |))|                Pong - Tetris                 |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(1) Start a new game - Human vs Human";
	setColor(COLOR::TEAL_TEXT);
	std::cout << "       |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(2) Start a new game - Human vs Computer";
	setColor(COLOR::TEAL_TEXT);
	std::cout << "    |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(3) Start a new game - Computer vs Computer";
	setColor(COLOR::TEAL_TEXT);
	std::cout << " |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(8) Present instructions and keys";
	setColor(COLOR::TEAL_TEXT);
	std::cout << "           |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(9)Exit";
	setColor(COLOR::TEAL_TEXT);
	std::cout << "                                     |  | |\n";
	std::cout << "		| |  |                                              |  | |\n";
	std::cout << "		| |  '----------------------------------------------'  | |\n";
	std::cout << "		| |__GAME BOY_________________________________________/  |\n";
	std::cout << "		|                       ________                         |\n";
	std::cout << "		|         .            (Nintendo)                        |\n";
	std::cout << "		|       _| |_           \"\"\"\"\"\"\"\"            . - .        |\n";
	std::cout << "		|     -[_   _]-                      . - .  (   )        |\n";
	std::cout << "		|        |_|                         (   )   '-'         |\n";
	std::cout << "		|         '                          ' - '    A          |\n";
	std::cout << "		|                                      B                 |\n";
	std::cout << "		|             ___  ___                                   |\n";
	std::cout << "		|            (___)(___)                               ,.,|\n";
	std::cout << "		|           select start                             ;:;:/\n";
	std::cout << "		|                                                  ,;:;'/\n";
	std::cout << "		|                                               ,:;:'.'/\n";
	std::cout << "		'-----------------------------------------------------`\n";
}

//pausing sreen
void Screen::start()
{
	setColor(COLOR::TEAL_TEXT);
	std::cout << "		__________________________________________________________\n";
	std::cout << "		| OFFo oON                                               |\n";
	std::cout << "		| .----------------------------------------------------. |\n";
	std::cout << "		| |  .----------------------------------------------.  | |\n";
	std::cout << "		| |  |              *Aviram & Yonatan*              |  | |\n";
	std::cout << "		| |))|                Pong - Tetris                 |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(1) Start a new game - Human vs Human";
	setColor(COLOR::TEAL_TEXT);
	std::cout << "       |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(2) Start a new game - Human vs Computer";
	setColor(COLOR::TEAL_TEXT);
	std::cout << "    |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(3) Start a new game - Computer vs Computer";
	setColor(COLOR::TEAL_TEXT);
	std::cout << " |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(4) Continue a paused game";
	setColor(COLOR::TEAL_TEXT);
	std::cout << "                  |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(8) Present instructions and keys";
	setColor(COLOR::TEAL_TEXT);
	std::cout << "           |  | |\n";
	std::cout << "		| |  |  ";
	setColor(COLOR::WHITE_TEXT);
	std::cout << "(9)Exit";
	setColor(COLOR::TEAL_TEXT);
	std::cout << "                                     |  | |\n";
	std::cout << "		| |  |                                              |  | |\n";
	std::cout << "		| |  '----------------------------------------------'  | |\n";
	std::cout << "		| |__GAME BOY_________________________________________/  |\n";
	std::cout << "		|                       ________                         |\n";
	std::cout << "		|         .            (Nintendo)                        |\n";
	std::cout << "		|       _| |_           \"\"\"\"\"\"\"\"            . - .        |\n";
	std::cout << "		|     -[_   _]-                      . - .  (   )        |\n";
	std::cout << "		|        |_|                         (   )   '-'         |\n";
	std::cout << "		|         '                          ' - '    A          |\n";
	std::cout << "		|                                      B                 |\n";
	std::cout << "		|             ___  ___                                   |\n";
	std::cout << "		|            (___)(___)                               ,.,|\n";
	std::cout << "		|           select start                             ;:;:/\n";
	std::cout << "		|                                                  ,;:;'/\n";
	std::cout << "		|                                               ,:;:'.'/\n";
	std::cout << "		'-----------------------------------------------------`\n";
}

void Screen::choose_difficult()
{
	ClearScreen();
	/*std::cout << "  _____ _                                                         _ _  __  __ _            _ _          \n";
	std::cout << " / ____| |                                                       | (_)/ _|/ _(_)          | | |         \n";
	std::cout << "| |    | |__   ___   ___  ___  ___   _   _  ___  _   _ _ __    __|  _  |_| |_ _  ___ _   _| | |_ _   _  \n";
	std::cout << "| |    | '_ \\ / _ \\ / _ \\/ __|/ _ \\ | | | |/ _ \\| | | | '__|  / _` | |  _|  _| |/ __| | | | | __| | | | \n";
	std::cout << "| |____| | | | (_) | (_) \\__ \\  __/ | |_| | (_) | |_| | |    | (_| | | | | | | | (__| |_| | | |_| |_| | \n";
	std::cout << " \\_____|_| |_|\\___/ \\___/|___/\\___|  \\__, |\\___/ \\__,_|_|     \\__,_|_|_| |_| |_|\\___|\\__,_|_|\\__|\\__, | \n";
	std::cout << "                                      __/ |                                                       __/ | \n";
	std::cout << "                                     |___/                                                       |___/  \n";
	*/
	std::cout << "  __             ____            _                                        __  __  __     \n";
	std::cout << " / _|           |  _ \\          | |                                      / / /_ | \\ \\    \n";
	std::cout << "| |_ ___  _ __  | |_) | ___  ___| |_    _ __  _ __ ___  ___ ___         | |   | |  | |   \n";
	std::cout << "|  _/ _ \\| '__| |  _ < / _ \\/ __| __|  | '_ \\| '__/ _ \\/ __/ __|        | |   | |  | |   \n";
	std::cout << "| || (_) | |    | |_) |  __/\\__ \\ |_   | |_) | | |  __/\\__ \\__ \\        | |   | |  | |   \n";
	std::cout << "|_| \\___/|_|    |____/ \\___||___/\\__|  | .__/|_|  \\___||___/___/        | |   |_|  | |   \n";
	std::cout << "                                       | |                              \\_\\        /_/    \n";
	std::cout << "                                       |_|                             \n";


	std::cout << "  __              _____                 _                                 __  ___   __   \n";
	std::cout << " / _|            / ____|               | |                               / / |__ \\  \\ \\  \n";
	std::cout << "| |_ ___  _ __  | |  __  ___   ___   __| |   _ __  _ __ ___  ___ ___    | |     ) |  | | \n";
	std::cout << "|  _/ _ \\| '__| | | |_ |/ _ \\ / _ \\ / _` |  | '_ \\| '__/ _ \\/ __/ __|   | |    / /   | | \n";
	std::cout << "| || (_) | |    | |__| | (_) | (_) | (_| |  | |_) | | |  __/\\__ \\__ \\   | |   / /_   | | \n";
	std::cout << "|_| \\___/|_|     \\_____|\\___/ \\___/ \\__,_|  | .__/|_|  \\___||___/___/   | |  |____|  | | \n";
	std::cout << "                                            | |                          \\_\\  ____  /_/  \n";
	std::cout << "                                            |_|                          \n";

	std::cout << "  __             _   _            _                                       __  ____   __  \n";
	std::cout << " / _|           | \\ | |          (_)                                     / / |___ \\  \\ \\ \n";
	std::cout << "| |_ ___  _ __  |  \\| | _____   ___  ___ ___   _ __  _ __ ___  ___ ___  | |    __) |  | |\n";
	std::cout << "|  _/ _ \\| '__| | . ` |/ _ \\ \\ / / |/ __/ _ \\ | '_ \\| '__/ _ \\/ __/ __| | |   |__ <   | |\n";
	std::cout << "| || (_) | |    | |\\  | (_) \\ V /| | (_|  __/ | |_) | | |  __/\\__ \\__ \\ | |   ___) |  | |\n";
	std::cout << "|_| \\___/|_|    |_| \\_|\\___/ \\_/ |_|\\___\\___| | .__/|_|  \\___||___/___/ | |  |____/   | |\n";
	std::cout << "                                              | |                        \\_\\         /_/ \n";
	std::cout << "                                              |_|                                        \n";
}




                                                                                                    
 /*     nice picture
						.:/+ssyhhhhhhyyso/:.                                                        
                    ./oyyyyyyyyyyyyyyyyyyyyhhs+-                                                    
                 .+yyyyyyyyyyyyyyyyyyyyhhddhhyhhho-                                                 
               -syyyyyyyyyyyyyyyyyyyyyydmmdddddyyhhy+`                              ```             
             -syyhdmNNmyyyyyyyyysssssyyyyyyyyyhhyyyhhh+`                         `..```...          
           `oyyyddhhhhyyyyyyyyyyoosossyyo///oyyyyyyyhhhh/                       -`       `-         
          -yyyyhhyyyysssyyyyyyyysssssyo`     `:yyyyyyyyyys.                     -         ..        
         :hyyyyyyyy:````.:syyyyyyyyyy+         .yyyyysyhhhh-                    :         -`        
        :hyyyyyyyy.       `:yyyyyyyyh`   `--`   -hyyyyyhhhhh:                   `-.`    `.`         
       .hyyyyyyyh:          -hyyyyyyy   .do/h-   yyyyyyyhhhhh-                    `.....`           
       yy++yyyyyh.   -ssy:   /hyyyyyy   sM-`dh   syyyyyyhhhhhh`                                     
      /h+--yyyyyh:   ho /M+  `hyyyyyh-  +MNmMh   hyyyyyyyhhhhho                    ``               
      yy---yyyyyys   sNshMN   hyyyyyyy. `ommh-  +hyyyyyyyhhhhhd.                 .-../       ``     
     `do---yyyyyyh+  `yNMMy  -hyyyyyyyy:` `.  `+yyyyyyyyyhhhhhh+                 /   :`    .-../``  
     -h+--/yyyyyyyyo.  -:-` .yyyyyyyyyyys+/:/oyyyyyyyyyyyhhhhhhy                 :.  :`  `-. .-../  
     -h+--oyyyyyyyyyyo:...-+yyyyyyyyysyyyyyyyyyyyyyyyyyyyyyhhhhd                 .-  `---.`.-``.-/  
     -ho:/ssssyyyyyyyyyyyyhyyyyyyyysyyyyyyyyyyyyyyyyyyysssssyhhd               `-.      `--.`-.``/  
  `---dysoossssyyyyyyyyyyyyyyyyyhyyyyhhyyyyyyyyyyyyyyyyosyssyhhh              --          `.-` `:`  
  /` `+yyssssyyyyyyyyyyyyyyyyyyyyhhhhhyyyyyyhyyyyyyyyyyyyyyyhhhy             `:   ``      .`  .-`   
  /    syyyyyyyyyyyyyyyyyyydyysyyyyyyyyyyyy/+yyyyyyyyyyyhhhhhhho.``          /: `-.--       .-.     
  `:   -hyyyyyyyyyyyyyyyyyyh+oyyyyyyyyyo/-``syyyyyyyyyyhhhhhhhh..-.---.`````-:      `.   `.-.       
   `: .:/----+yyyyyyyyyyyyyyy.`..---..``-/sddyyyyyyyyyyhhhhhhh+``     ``...` -:.`::...---.`         
    :/`       +yyyyyyyyyyyyyyddyysssyhdmmmmmyyyyyyyyyyhhhhhhhy```            .-:--````              
    /      .--+syyyyyyyyyyyyyyhmmmmmmmddhhmhyyyyyyyyyhhhhhhhy.``        `.-..`                      
   .:     ``   `yyyyyyyyyyyyyyyydmdyyyyyhhyyyyyyyyyyhhhhhhhh-.....--.....                           
   .-          `yyyyyyyyyyyyyyyyyyyhhhhyyyyyyyyyyyyhhhhhhho ````                                    
   /:       .---+yyyyyyyyyyyyyyyyyyhhhhhhyyyyyhhhhyyssosy-                                          
  .:/           `hyyyyyyyyyyyyyyyssyhhyysso+//::-----/+-                                            
   /`/          //shyyyhhhyyssoo:::-.-:/:::o-------/+-                                              
   `:-+-`   `.--`  .+so/-.......``.s-..````so----:+-                                                
     ```.---.`        `.::::.......y/``````os:--+:                                                  
                          ``-:::...o/-`````s:o:o`                                                   
                              `.::-o`+----:s-ss`                                                    
                                 `-s--+..../+:o                                                     
                                   -/`o.....s-o`                                                    
                                    o`o.....:o:+                                                    
                                    o`o......o:o.                                                   
                                    o`o......-o:+                                                   
                                    /./-......+/o.                                                  
                                    -:::.......s:o                                                  
                                    `+.+.......//+.                                                 
                                     o`o........s:o                                                 
                                     o`o........:++-                                                
                                     +`o.........s/:                                                
                                     ./o.........-y-                                                
                                      :y-.........s.                                                
                                       +/.....-:/:-                                                 
                                        `-----.`                                          

      

	  */