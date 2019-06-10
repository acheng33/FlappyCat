# Development

## Task List
- [x] Create necessary classes for the game
- [x] Identify what should be housed where
- [x] Play around with sound files and images
- [x] Figure out possible game states
- [x] Movement across the screen
- [x] Adding in the logic for a second player
- [x] Play around with physics (how fast to fall, rise)


## Player
 * location (x coordinate)
 
 ## Pipes
  * the height, width, location
  * distance between each top and bottom pipe
 

## ofApp
  * with setup
    * create the pipes, load background
    * create the cat 
    * load sounds 
  * check for collisions between pipes and image
  * which keys are pressed and what they should do
  * end of game screen
  * beginning game screen
  * resetting the game
  * generate the pipes
  * moving the game
  * current state of the game
  
  ## Issues Ran Into
   * setting color to black makes everything in the window appear black
    * including images
    * making sure the background of images are transparent so that you can see the background image
    * pipe images, had to find one that worked for the height of the window
    * how the cat should rise and fall (making sure the cat would rise and fall at a reasonable rate)
    * collision logic 
    * having the game end properly with two players

## Plan
- [x] create FlappyCat as a single player game first
- [x] integrate a second player into the game

### Sunday Apr 21st
Spent some time loading in an image and realized setting the color of things would affect images as well (so everything will show up as the color you set). Spent some time figuring out what things each class needs to house such as the height and width of the cat and pipes. Need to figure out how to find the  difference between the game states (paused, start, end, etc).

### Monday Apr 22nd
Fixed the image that is being used for the pipes. 

### Thursday Apr 25th
Started with actual game play. Spent most of my time focusing on the player class and the pipe class to figure hopefully get a preliminary prototype of the game before the end of the day. Started figuring out where things should be positioned for the best game play experience by the user.

### Friday Apr 26th
Continuing to finish up the methods for playing.  Spent most of my time figuring out how the cat was going to fly and making sure the cat was rising or falling at a reasonable seeming rate. Still need to get rid of the magic numbers that were used for the rate of falling and rising. Figuring out the collision logic was a bit tricky as I couldn't have the conditional be equal to each other because then all that would happen is that a new pipe would be generated. Added in sound effects for flying and game overs as well.

### Monday Apr 29th
Today is trying to setup the images of the two cats and pipes on the same window. From there, it will be a matter of making sure I'm keeping track of the right things per cat. Ran into some issues with having the game end properly

### Tuesday Apr 30th
Fixed the collission issues and the issues that came with implementing two players. Originally had kept track of the game states of both cats separately, but it is much easier to just keep track of one. What's left is cleaning up the code and getting rid of magic numbers. 

### Wednesday May 1st
Working on fixing the magic numbers in the code and cleaning up the code. 
