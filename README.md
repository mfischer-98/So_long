# So_long 🐶🧦

A 2D game where you play as Max, the pug, collecting socks in a messy house! My first experience at 42, making a game in C, with no engine and using the school's graphical library.

## About the project
- **Mandatory**: Map validation (parsing), collecting items, reaching the exit to win
- **Bonus**: Animations, enemies, lose condition, and extra features!

## Project Goals
Master these core concepts through game development:
- Window management
- Event handling  
- Color/texture rendering

**Built with**: MiniLibX (42's graphical library)  
**Featuring**: Custom 2D art and animations created by me 🎨

## The Story
Play as Max, a pug who must gather all lost socks on moving day! Navigate through the house, collect socks, and bring them to your fortress (aka bed).

## How to Play
- **Controls**: Arrow keys to move
- **Objective**: Collect all socks (moves are counted!)
- **Bonus Danger**: Watch out for the sleepy cat - you might not want to get too close!

## Bonus and Features ✨
- Diverse wall types and random furniture
- 3 different sock types to collect
- 😼 Reactive cat:
  - Sleeps when you're far
  - Alerts when you approach
  - Attacks if you stand beside it (right or left tile)

## Map Format Example
`111111`<br>
`1P0C01`<br>
`10N0E1`<br>
`111111`

`1` - Walls
`0` - Floor
`P` - Player (Max)
`C` - Collectable (socks)
`E` - Exit (bed)
`N` - Enemy (cat)

## Technical Skills
- Using MiniLibX graphics library
- Code organization with multiple files
- Map parsing and validation
- Handling key events and window management
- Implementing player movement
- Rendering text on game window
- Game logic for win conditions (collect all socks!)

**Animation Challenges**:
- Created different character states (idle, moving, attacking)
- Managed frame timing and animation speed
- Implemented attack animations (cat overlaps player)

**Future Improvements**:
While the game is complete, some potential enhancements:
- Smoother animations with more in-between frames
- Key release detection for smoother movement (no repeated key presses)

## Creative Process
I knew exactly what I wanted - a pug named Max obsessed with socks and a grumpy cat! Here's how it came together:

1. **Concept**: deciding what the story would be
2. **Design**:
   - Created color palette and tile sets for floor, bed and socks
   - Designed Max and the cat characters
   - Made 8 wall types for proper borders
3. **Animation**:
   - Frame-by-frame animation with minimal frames
   - State management for different actions
   - Special attack animation effects

## ⚙️ Installation & Play
```bash
git clone https://github.com/mfischer-98/So_long.git
cd so_long

# Mandatory version
make
./so_long maps/map1.ber

# Bonus version
make bonus
./so_long_bonus maps/map1_bonus.ber
