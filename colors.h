#pragma once
#include <raylib.h>
#include <vector>
extern const  Color darkGrey;//extern keyword allow us to declare variable in 1 file and use in another
extern const  Color green;
extern const  Color red;
extern const  Color orange;
extern const  Color yellow;
extern const  Color purple;
extern const  Color cyan;
extern const  Color blue;
extern const  Color LightBlue;
extern const  Color DarkBlue;

std::vector<Color> GetCellColors();

