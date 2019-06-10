# Final Project Proposal

## Description 
A flappy bird-esque game with cats instead of the traditional bird. Essentially, Flappy Cat. My goal is to build a simple game that involves movement on screen, key inputs from the user, and graphics, which is mainly the pipes, which should be generated at varying heights which will create a challenge to  the player. I also want to implement different flap heights based on what key the user presses. The score is based on how many pipes the player passes through. The final score will be reported to the player at the end of the game when they collide with a pipe or hit the ground.

## Harder Implementations
 * Implement two players
    * Each side of the keyboard will control each bird
    * The players can screw with each other while playing the game
* Have different worlds the flappy cat will travel through.
    * No player selection, instead, the cat will go straight to the next world after a certain amount of points has been reached.
* Difficulty gets harder as the player advances
    * Smaller openings in the pipes 
    * Scrolling speed increases
    * Pipes are closer together

## Libraries for Implementation
 * Shapes 
    * For pipes
 * Image 
    * For cat image rendering
 * Events 
    * Points
    * Mouse movement
    * Timer for life span
    * Key pressed by the user
* Sound
    * Sound effects of flapping or dying
    * Music in the background as the player plays
* App 
    * Multiple windows to hold high score and main game

