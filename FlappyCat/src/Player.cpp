#include "Player.h"

void Player::ChangeYCoordinate(int value) {
    y_coordinate_ -= value;
}

void Player::SetupCat(int x, int y, int height, int width) {
    x_coordinate_ = x;
    y_coordinate_ = y;
    height_of_screen_ = height;
    width_of_screen_ = width;
}

int Player::GetXCoordinate() {
    return x_coordinate_;
}

int Player::GetYCoordinate() {
    return y_coordinate_;
}
