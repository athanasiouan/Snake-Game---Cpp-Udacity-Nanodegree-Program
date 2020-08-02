# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## The Capstone project meets the following requirements:
### 1. Instructions:
The game has a terminal main menu with the following choices:
  1. You have the choice to start a new game by pressing 1 and you can terminate it by pressing esc. Before starting the game, the player will be asked for the player name. When the game is finished you can see some informations. Also you can see statistics(Name and score) which are saved at game_statistics.txt.
  2. You have the choice Top score where a list of top game scores(game_statistics.txt) is displayed. If the file doesn't exist will be created automatically.
  3. Quit game which terminates the game.

### 2. Explanation of how my submission satisfies the necessary rubric:
  1. Input/Output: read and write the file or creates one if not exist(DataManager class).
  2. Loops and Function: to handle and avoid fail states.
  3. Main menu is an interactive interface with the game(GameManager.class).
  4. The project supports OOP techniques and principles.
  5. Use access specifiers  for class members.
  6. The project use references in function declarations(HeadDistanceTravel() in snake.h.).
  
## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.