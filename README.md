# Snake Game
### Team members
- Lai, Pok Hang
- Lo, Ian Leong Ting

### Introduction
- Snake game based on C++
- Group Project of ENGG1340
- Work in progress

### Games Rules
- Player uses arrow keys or WASD to control the snake.
- Snake should move only inside the yellow border and search for food (red apple).
- Once the food was eaten, the snake body grows one unit in length.
- Pressing spacebar can pause the game.
- Game ends if the snake crashes with itself or to the wall.
- Try to control the snake to eat as many apples as possible!

### Game Elements
1. Generation of random game sets or events
    - The apples are generated in random (uniformly distrubuted) around the map.
    - mt19937 pseudo-random generator is used.
2. Data structures for storing game status
    - Class `Snake`, will be storing all the properties of the current snake.
3. Dynamic memory management
    - `new` operator is used to allocate memory on the free store for the `Snake` object.
    - `delete` operator is called to restore the memory allocated when the game ends.
4. File input/output
    - The pause menu provides option to save current game status .
    - At start menu, saved game can be loaded from the `log.txt` file, and continue to play.
    - After the game ends, the score will be recorded in the `rank.txt` file.
5. Program codes in multiple files
    - (include file tree here after the game is finalized)

### External Libraries
- `ncurses`