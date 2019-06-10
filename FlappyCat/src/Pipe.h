#pragma once
#include "ofMain.h"

class Pipe {
    
private:
    
    const int kGapSizeBetweenPipes = 450;
    
    int x_coordinate_;
    int top_pipe_y_;
    int bottom_pipe_y_;
    int height_;
    int width_;
    
public:
    void SetupPipe(int height, int width, int x_coordinate);
    void MovePipe(int speed);
    
    int RandomNumber(int minimum, int maximum);
    int GetXCoordinate();
    int GetTopPipe();
    int GetBottomPipe();
    int GetGapSize();
};
