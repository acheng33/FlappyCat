#include "ofApp.h"
#include <iostream>

void ofApp::setup() {
    
    ofSetWindowTitle("Flappy Cat");
    cat_image_.load("cat.png");
    second_cat_image_.load("cat.png");
    top_pipe_image_.load("top_pipes.png");
    second_top_pipe_image_.load("top_pipes.png");
    bottom_pipe_image_.load("bottom_pipes.png");
    second_bottom_pipe_image_.load("bottom_pipes.png");
    flap_sound_effect_.load("flap_sound.mp3");
    game_over_effect_.load("game_over.mp3");
    cat_.SetupCat(ofGetWidth() / 6, kImageTextYLocation, ofGetHeight(), ofGetWidth());
    second_cat_.SetupCat(kImageXLocation, kImageTextYLocation, ofGetHeight(), ofGetWidth());
    pipe_.SetupPipe(ofGetHeight() / 2, kImageXLocation, kImageXLocation);
    second_cat_pipe_.SetupPipe(ofGetHeight(), ofGetWidth(), ofGetWidth());
}

void ofApp::update() {
    if (current_state_ == FALLING) {
        MovePipes();
        
        if (pipe_.GetXCoordinate() < cat_.GetXCoordinate()) {
            GeneratePipes();
        }
        
        cat_.ChangeYCoordinate(kFallingFactor);
        second_cat_.ChangeYCoordinate(kFallingFactor);
        
        if (CollisionOccured()) {
            game_over_effect_.play();
        }
        
    }
}

void ofApp::draw() {
    
    ofSetBackgroundColor(0, 0, 0);
    
    if (current_state_ == START) {
        ResetGame();
        DrawStart();
    } else if (current_state_ == PAUSED) {
        DrawPausedGame();
    } else if (current_state_ == FALLING || current_state_ == JUMP) {
        DrawCat();
        DrawPipes();
    } else if (current_state_ == END) {
        DrawEndGame();
    }
}

void ofApp::keyPressed(int key) {
    int upper_key_ = toupper(key);
    
    if (current_state_ != END) {
        if (upper_key_ == 'W') {
            current_state_ = JUMP;
            flap_sound_effect_.play();
            cat_.ChangeYCoordinate(kJumpHeight);
            current_state_ = FALLING;
        }
        if (upper_key_ == 'I') {
            current_state_ = JUMP;
            flap_sound_effect_.play();
            second_cat_.ChangeYCoordinate(kJumpHeight);
            current_state_ = FALLING;
        }
    }
    
    if (current_state_ == FALLING || current_state_ == JUMP) {
        if (upper_key_ == 'P') {
            current_state_ = PAUSED;
        }
    }
    if (current_state_ == END) {
        if (upper_key_ == ' ') {
            current_state_ = START;
        }
    }
}

void ofApp::DrawStart() {
    
    ofDrawBitmapString("Instructions: ", kTextXLocation, kImageTextYLocation);
    ofDrawBitmapString("Player 1 press 'w' to jump, Player 2 press 'i' to jump!", kTextXLocation, kImageTextYLocation + 20);
    ofDrawBitmapString("Press 'p' to pause the game", kTextXLocation, kImageTextYLocation + 40);
}

void ofApp::DrawCat() {
    
    cat_image_.draw(cat_.GetXCoordinate(), cat_.GetYCoordinate(), 75, 75);
    second_cat_image_.draw(second_cat_.GetXCoordinate(), second_cat_.GetYCoordinate(), 75, 75);
}

void ofApp::DrawPipes() {
    
    top_pipe_image_.draw(pipe_.GetXCoordinate() / 2, 0);
    bottom_pipe_image_.draw(pipe_.GetXCoordinate() / 2, pipe_.GetBottomPipe());
    second_top_pipe_image_.draw(second_cat_pipe_.GetXCoordinate(), 0);
    second_bottom_pipe_image_.draw(second_cat_pipe_.GetXCoordinate(), second_cat_pipe_.GetBottomPipe());
}

void ofApp::DrawEndGame() {
    
    if (score_ > second_cat_score_) {
        ofDrawBitmapString("Player 1 won with " + ofToString(score_ + 1 ) + " points!", kTextXLocation, kImageTextYLocation);
    } else if (second_cat_score_ > score_){
        ofDrawBitmapString("Player 2 won with " + ofToString(second_cat_score_ + 1) + " points!", kTextXLocation, kImageTextYLocation);
    } else {
        ofDrawBitmapString("The two players have tied with " + ofToString(score_ + 1) + " points!", kTextXLocation, kImageTextYLocation);
    }
    
}

void ofApp::DrawPausedGame() {
    
    ofDrawBitmapString("The game is currently paused.", kTextXLocation, kImageTextYLocation);
    ofDrawBitmapString("Press the space bar to continue playing.", kTextXLocation, kImageTextYLocation + 20);
}

void ofApp::ResetGame() {
    
    score_ = 0;
    second_cat_score_ = 0;
    cat_.SetupCat(ofGetWidth() / 6, kImageTextYLocation, ofGetHeight(), ofGetWidth());
    second_cat_.SetupCat(kImageXLocation, kImageTextYLocation, ofGetHeight(), ofGetWidth());
    pipe_.SetupPipe(ofGetHeight(), ofGetWidth(), ofGetWidth());
    second_cat_pipe_.SetupPipe(ofGetHeight(), ofGetWidth(), ofGetWidth());
}

void ofApp::MovePipes() {
    
    pipe_.MovePipe(kMovingSpeed);
    second_cat_pipe_.MovePipe(kMovingSpeed / 2);
}

void ofApp::GeneratePipes() {
    
    pipe_.SetupPipe(ofGetHeight(), ofGetWidth(), ofGetWidth());
    second_cat_pipe_.SetupPipe(ofGetHeight(), ofGetWidth(), ofGetWidth());
    score_++;
    second_cat_score_++;
}

bool ofApp::CollisionOccured() {
    
    if (cat_.GetXCoordinate() >= pipe_.GetXCoordinate() || second_cat_.GetXCoordinate() >= second_cat_pipe_.GetXCoordinate()) {
        
        if (cat_.GetYCoordinate() <= pipe_.GetTopPipe() || cat_.GetYCoordinate() >= pipe_.GetBottomPipe()) {
            current_state_ = END;
            score_ = score_ - 1;
            return true;
            
        }
        
        if (second_cat_.GetYCoordinate() <= second_cat_pipe_.GetTopPipe() || second_cat_.GetYCoordinate() >= second_cat_pipe_.GetBottomPipe()) {
            current_state_ = END;
            second_cat_score_ = second_cat_score_ - 1;
            return true;
        }
    }
    return false;
}
