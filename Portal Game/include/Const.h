#pragma once
#pragma warning(push, 0)
#include <string>
#include <vector>
#pragma warning(pop)

const char PLAYER = 'P', BUTTON_FLOOR = '-';
const std::vector <std::string> PLATER_RIGHT_PIC_NAMES = { "player_right1.png" , "player_right2.png" ,
"player_right3.png" ,"player_right4.png" , "player_right5.png" };

const std::vector <std::string> PLATER_LEFT_PIC_NAMES = { "player_left1.png" , "player_left2.png" ,
"player_left3.png" ,"player_left4.png" , "player_left5.png" };

const int  WINDOW_WIDTH = 1920, WINDOW_HEIGHT = 1080,
NORAML_BUTTON_SIZE = 40, BIG_BUTTON_SIZE = 50, BUTTON_SOUND = 0, LEFT = 0, RIGHT = 1,
DATA_BAR_HEIGHT = 90, DATA_WIDTH = 170, BULLET_MOVE = 3, MENU_VOLUME = 7,
BULLET_LEGNTH = 50, BULLET_WIDTH = 5; 

const float LIMIT = 60, X_GRAVITY = 0, Y_GRAVITY = 10, TIME_STEP = 1.0f / 60.0f;

const int VEL_ITER = 6, POS_ITER = 2, RESET_TIME = 6, EXIT_PORT = 0, ENTER_PORT = 1,
LEVELS_AMOUNT = 3, NO_TIME_LIMIT = -1, FIRST_DATA = 0, SECOND_DATA = 1, TIME_LIMIT = 10,
JUMP_POWER = -30, MUSIC_VOLUME = 5, WALK_SPEED = 5, JUMP_SPEED = 7, ANGLE = 180, START_LOC = 100;

const std::vector <std::string> EXPLENATION_STRINGS = {"Welcome to the portal game!\n We're hopping that you'll enjoy :)\n\nThe mission is reach to the\nelevator that will take you\n to the next level!\n" ,
"Your abilities are-\n\n1) Movement - \nright/left. (with arrows keys)\n\n2) Jumping - \navailable when you are on wall.\n\n3) Picking up box - \nclick (on the box) for picking up and droping.\n\n4) Portals - left click for the entry portal, right click for exit portal.\n available when you have clear path\n to the wanted portal location.\n" ,
"Easy/Hard level are differentiated\nby time limit\nOther game objects are-\n\n1) Bad laser(in red), Acid -\ntouching them will restart the level.\n\n2) Time present - + 10 second.\n\n3) Button - when button interact\n with you/box object\nyou'll have a surface to walk on.\n\n4) Trampoline - helps you to jump higher." ,
"GOOD LUCK!\n" };
const std::string CONTINUE_STRING = "Click to continue"  , 
RESET_LEVEL_STRING = "Level begin in: ";

const std::vector <std::string> IMAGES_NAMES = { "Menu.png"  , "player_jump1.png"   ,
"Watch.png"  ,"Wall.png" , "Box.png" ,  "Acid.png"  , "elevator.png"  ,"Button.png" ,
"Trampoline.png"   , "LaserHouse.png"   ,"BackGround.png" ,
"playerGun.png"  , "mouseGunPic.png"  ,"buttonFloor.png" ,  "LevelCompleted.jpg"  ,
"YouWin.png"  , "ExplenationPic.jpg"  , "enterportal.png"  , "exitportal.png", "Fence.png",
"TryAgain.png"};

enum IMAGES_INDEX
{ 
MENU_PIC , PLAYER_PIC, WATCH_PIC, WALL_PIC, BOX_PIC, ACID_PIC, ELEVATOR_PIC
, BUTTON_PIC, TRAMPOLINE_PIC, LAZER_HOUSE_PIC , BACK_GROUND_PIC , 
PLAYER_GUN_PIC, MOUSE_PIC, BUTTON_FLOOR_PIC, 
LEVEL_COMPLETED_PIC, YOU_WIN_PIC, EXPLENATION_PIC , ENTER_PORTAL_PIC ,
EXIT_PORTAL_PIC , FENCE_PIC , TRY_AGAIN_PIC
};
const std::vector <std::string> SOUNDS_NAMES = {"LevelSound.ogg" , 
"buttonPopMusic.wav", "shotmusic.wav","explenationMusic.wav","DingDong.wav",
"PortalTransfer.wav", "springboardmusic.wav", "elevatormusic.wav",
"extratimemusic.wav","acidmusic.wav"  , "nextlevel.wav"  , "youwin.wav" };

enum SOUNDS_INDEX
{
	GAME_SOUND , MENU_BUTTON_SOUND , SHOT_SOUND , EXPLENATIONS_SOUND , TIMER_SOUND , 
	PORTAL_SOUND , TRAMPOLINE_SOUND , ELEVATOR_SOUND , TIME_PRESENT_SOUND , 
	ACID_SOUND , NEXT_LEVEL_SOUND , YOU_WIN_SOUND,
};

const std::vector <std::string> FONTS_NAMES = { "font.ttf" };
enum FONT_INDEX {
	FONT,
};

const std::vector <std::string> DATA_BAR_STRING = {"Level: "  , "Time Left: "};

enum MENU_BUTTONS {FIRST_BUTTON , SECOND_BUTTON, THIRD_BUTTON};
const std::string DIFFICULY_STRING = "Select Difficulty", 
HARD_STRING = "With Time" , EASY_STRING = "Without Time", EXPLENATION_STRING = "Explenation",
EXIT_STRING = "Exit";

