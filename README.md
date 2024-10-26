Tetris Game in C++ Using Raylib
Overview:
This is a Tetris game developed in C++ using the Raylib library and Visual Studio. The game replicates the classic Tetris experience, where players arrange falling blocks (tetrominoes) to form complete horizontal lines. Completed lines disappear, and the game progresses with increasing speed.

Features:
Core Tetris Mechanics: Players can rotate, move, and drop blocks to clear lines.
Score System: Points are awarded for each line cleared.
Progressive Difficulty: The speed of falling blocks increases as the player scores more.
Game Over Condition: The game ends when the stack of blocks reaches the top of the screen.

Requirements:
To run this project, you will need:

Visual Studio: The project is set up for Visual Studio.
Raylib Library: Raylib handles graphics and input in this project.
Additional Libraries: Ensure that Raylib dependencies (like OpenGL, GDI32, and WinMM) are configured in Visual Studio.
Installation
Clone or download this repository.
Make sure Raylib and its required dependencies are installed and linked in Visual Studio.
Set up Raylib by going to Project Properties > VC++ Directories and add the include and library paths.
Under Linker > Input, add raylib.lib, OpenGL32.lib, GDI32.lib, and WinMM.lib to the list of dependencies.
Build and run the project to start the game.

Controls:
Left Arrow: Move block left
Right Arrow: Move block right
Up Arrow: Rotate block
Down Arrow: Drop block faster
Esc: Exit the game

How to Play:
The objective is to clear lines by creating complete horizontal rows of blocks without gaps. As more lines are cleared, the game speeds up, increasing the challenge. The game ends when the blocks reach the top of the screen.
