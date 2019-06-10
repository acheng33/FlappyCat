#include <stdio.h>
#include "Pipe.h"

void Pipe::SetupPipe(int height, int width, int x_coordinate) {
    height_ = height;
    width_ = width;
    x_coordinate_ = x_coordinate;
    
    srand(time(NULL));
    int half_of_screen = height / 2;
    top_pipe_y_ = RandomNumber(1, half_of_screen);
    bottom_pipe_y_ = top_pipe_y_ + kGapSizeBetweenPipes;
}

void Pipe::MovePipe(int speed) {
    x_coordinate_ -= speed;
}

int Pipe::RandomNumber(int minimum, int maximum) {
    srand(time(NULL));
    return ((rand() % maximum) + minimum);
}

int Pipe::GetXCoordinate() {
    return x_coordinate_;
}

int Pipe::GetTopPipe() {
    return top_pipe_y_;
}

int Pipe::GetBottomPipe() {
    return bottom_pipe_y_;
}

int Pipe::GetGapSize() {
    return kGapSizeBetweenPipes;
}
