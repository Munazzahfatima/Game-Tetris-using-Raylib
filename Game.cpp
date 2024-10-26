#include <raylib.h>
#include "GameElements.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double intervel) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= intervel) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;

}
 
int main() {
	InitWindow(600, 620, "Raylib Tetris");
	SetTargetFPS(60);

	Font font = LoadFontEx("font summer/Summerfriday.otf",64,0,0);

	Game game = Game();
	
	while (WindowShouldClose() == false) {
		game.HandleInput();
		if (EventTriggered(0.2)) {
			game.MoveBlockDown();
		}
		BeginDrawing();
		ClearBackground(DarkBlue);
		
		DrawTextEx(font, "Score", { 400,15 }, 38, 2, WHITE);
		
		char scoretext[10];
		sprintf_s(scoretext,sizeof(scoretext),"%d",game.score);
		Vector2 textSize =MeasureTextEx(font,scoretext,38,2) ;
		
		DrawRectangleRounded({ 370,55,170,60 }, 0.3, 6, LightBlue);
		DrawTextEx(font,scoretext , { 370 + (170-textSize.x)/2,65}, 38, 2, WHITE);
		
		
		DrawTextEx(font, "Next", { 410,175 }, 38, 2, WHITE);
		DrawRectangleRounded({ 370,215,170,180 }, 0.3, 6, LightBlue);

		if (game.gameOver) {
			DrawTextEx(font, "GAME OVER !", { 370,459 }, 38, 2, WHITE);
		}
		

		game.Draw();
		EndDrawing();
	}
	CloseWindow();
}