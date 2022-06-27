  
   EPITECH PROJECT, 2021
   readme.md
   File description:
   Description file of my_rpg project
  

# B-MUL-200-LIL-2-1-myrpg-thibault2.brumaire

## my_rpg

- Compilation : using Makefile (with "clean", "fclean" and "re" rules)
- Usage       : ./my_rpg

### Description

The main goal of this project is to be able to create a real RPG using knowledge we acquired on previous graphical projects.

Our starting-block is the first Pokemon film where the main antagonist is Mewtwo. Our rpg is based on the events happening during this movie.

### TODO

- Requirements:
  - [ ] The following features are MANDATORY:
    - [x] The window can be closed using events.
    - [ ] The game manages the input from the mouse click and keyboard.
    - [ ] The game contains animated sprites rendered thanks to sprite sheets.
    - [ ] Animations in the program are frame rate independent.
    - [ ] Animations and movements in the program are timed by clocks.
  - [ ] Technical Requirements:
    - [ ] A collision system including moving and static elements with different shapes.
    - [ ] A simple particle system that can display at least 2 types of partciles.
    - [ ] Particle effects (changing colors, scaling, bouncing, fading) to simulate realistic environment (wind, fire, rain, snow...).
    - [ ] Camera movements (zoom, translation, rotation).
    - [ ] 3D effects (depth scaling, isometric projection...).
  - [ ] The game MUST have:
    - [ ] A starting menu with at least two buttons, one to launch the game, and one to quit the game.
    - [ ] A 'escape' key to pause the game when launched.
    - [ ] A menu when the game is paused with at least two buttons, one to go to the starting menu and the other to leave the game.
    - [ ] A basic fighting system.
    - [ ] An inventory and status menu.
  - [ ] The game SHOULD:
    - [ ] Have a window sticking between 800x600 pixels and 1920x1080 pixels.
    - [ ] Have an 'How To Play' menu, explaining how to play the game.
    - [ ] Have NPC(s) with whom the player can interact (fight, quest, discuss).
    - [ ] Have as much as information as possible about the game should be stored in a configuration file.
    - [ ] Have at least three visual states for the buttons in the game: idle, hover and clicked.
    - [ ] Have cutscenes or animated intro, which the player can skip.
    - [ ] Have a beggining and an end.
    - [ ] Have an advanced collision system to manage complex fighting.
  - [ ] The game COULD:
    - [ ] Let the player save and load its own save.
    - [ ] Let the user customize its character.
    - [ ] Have different types of enemies.
    - [ ] Have a skill tree, unlocking different abilities (active and passive).
    - [ ] Have a 'settings' menu that could contain sound options and/or screen size options.
    - [ ] Have a particle engine.
    - [ ] Use scripting to describe entities.
    - [ ] Have a map editor.
  - [ ] The game WOULD:
    - [ ] Be a real video game, fun to play, with objectives to attain

- Authorized functions:
  - From the CSFML library:
    - All functions.
  - From the math library:
    - All functions.
  - From the C library:
    - malloc | free | memset | (s)rand | getline | (f)open | (f)read | (f)close | (f)write | opendir | readdir | closedir