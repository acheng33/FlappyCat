#pragma once
#include "ofMain.h"

class Player {
    
private:
    int x_coordinate_;
    int y_coordinate_;
    int height_of_screen_;
    int width_of_screen_;
    
public:
    void ChangeYCoordinate(int value);
    void SetupCat(int x, int y, int height, int width);
    
    int GetXCoordinate();
    int GetYCoordinate();
};
