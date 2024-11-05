# Caterpillar Game

A simple, engaging Caterpillar game implemented using Object-Oriented Programming (OOP) principles and design patterns. This project was developed using the SFML library and incorporates core OOP principles, such as inheritance, encapsulation, and polymorphism, along with key design patterns like Singleton and Factory.

## Table of Contents
- [Features](#features)
- [Game Rules](#game-rules)
- [Project Structure](#project-structure)
- [Design Patterns](#design-patterns)
- [Getting Started](#getting-started)
- [How to Play](#how-to-play)
- [Testing](#testing)

---

## Features
- **Game Mechanics**: Classic Snake-style gameplay with a twist; the snake grows each time it consumes an apple.
- **Screen-Wrapping**: When the snake moves off one edge, it appears on the opposite side.
- **Walls and Obstacles**: Randomly generated walls add a new layer of difficulty.
- **Audio**: Background music and sound effects for actions like eating and collisions.
- **Scoreboard**: Tracks the current score and best score, updating in real-time.
- **Game States**: Start, pause, resume, and game over states for smooth gameplay control.

## Game Rules
1. Use arrow keys or 'A', 'W', 'D', 'S' to control the snake’s movement.
2. Eat apples to grow in length and increase your score.
3. Avoid colliding with walls or yourself, or the game will end.
4. The game wraps around the edges; moving off one side brings you to the opposite side.
5. Aim for the highest score possible!


## Design Patterns
- **Singleton Pattern**:
  - `GraphicsRenderer` and `SoundRenderer` use Singleton to ensure only one instance of each renderer exists, managing graphics and audio consistently.
  - `SnakeGame` is also a singleton to ensure only one active instance of the game logic.

- **Factory Pattern**:
  - `BlockFactory` class generates wall blocks and adds them to the game grid, optimizing wall creation.

## Getting Started

### Prerequisites
- [SFML Library](https://www.sfml-dev.org/download.php): The game requires the SFML library for rendering, audio, and window management.

### Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/iravelmakina/snake-game.git
   cd snake-game
   ```
2. Compile the game (assuming SFML is installed):
   ```bash
   g++ src/*.cpp -o caterpillar-game -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
   ```

3. Run the game:
   ```bash
   ./caterpillar-game
   ```

### How to play
- **Controls**:
  - Arrow keys or 'A', 'W', 'D', 'S to move the snake.
  - `P` to pause and resume the game.
  - `R` to restart after a game over.
<p align="center">
  <img src="https://github.com/user-attachments/assets/e65f6089-34f7-4c4d-a29f-2a881cef7fc8" alt="Caterpillar Game GIF" width="320">
</p>


### Testing
The game has been tested for core mechanics, including snake movement, collision handling, score updating, and game state transitions. Key test cases include:
1. **Core Mechanics**: Movement, self-collision, apple consumption, and wall collision.
2. **Wrap-Around**: Verify that the snake wraps around edges correctly.
3. **Game State Transitions**: Test start, pause, resume, and game over states.
4. **Scoring**: Confirm current and best scores update as expected.
5. **Rendering and Audio**: Check visual rendering and sound effects for actions.
For a detailed testing guide, see the [Testing](https://github.com/user-attachments/files/17636034/Ass5-6.docx)
 section of the report.







