#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Pipe.h"
#include <vector>

class ofApp : public ofBaseApp{
    
    enum GameState {
        START,
        FALLING,
        JUMP,
        PAUSED,
        END
    };
    
private:
    GameState current_state_ = START;
    
    ofImage cat_image_;
    ofImage second_cat_image_;
    ofImage top_pipe_image_;
    ofImage second_top_pipe_image_;
    ofImage bottom_pipe_image_;
    ofImage second_bottom_pipe_image_;
    
    ofSoundPlayer flap_sound_effect_;
    ofSoundPlayer game_over_effect_;
    
    Player cat_;
    Player second_cat_;
    Pipe second_cat_pipe_;
    Pipe pipe_;
    
    const int kGravityConstant = 8;
    const int kMovingSpeed = 2;
    const int kFallingFactor = -1;
    const int kJumpHeight = 50;
    const int kImageTextYLocation = ofGetHeight() / 3;
    const int kTextXLocation = ofGetWidth() / 3;
    const int kImageXLocation = ofGetWidth() / 2;
    
    int score_ = 0;
    int second_cat_score_ = 0;
    
    void DrawStart();
    void DrawCat();
    void DrawPipes();
    void DrawEndGame();
    void DrawPausedGame();
    void ResetGame();
    void MovePipes();
    void GeneratePipes();
    
    bool CollisionOccured();
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
};
