# 2D Shape Drawer

## Overview
Welcome to my 2D Shape Drawer project! This interactive application is built using OpenGL and GLFW, allowing users to create and manipulate various geometric shapes within a 2D space. My goal for this project was to explore fundamental graphics programming concepts such as transformations, user input handling, and dynamic rendering techniques.

## Features
- **Shape Variety**: Draw and interact with different shapes including triangles, circles, ovals, pentagons, and more.
- **Interactive Controls**: Users can move, rotate, scale, and change the color of shapes using simple keyboard inputs.
- **Color Cycling**: Cycle through different colors to apply to the shapes for dynamic visual effects.
- **Mode Switching**: Easily toggle between outline and fill modes to change how shapes are displayed.
- **Path Animation**: Activate movement of shapes along a circular path for animated effects.

## Installation Instructions

### Prerequisites
Before you begin, ensure the following are installed on your system:
- OpenGL for rendering graphics.
- GLFW for window and input management.
- GLEW for managing OpenGL extensions.

### Setting Up the Project
1. **Clone the Repository**
   
   git clone https://github.com/shakib2412/2D-Shape-Drawer.git
   
2. **Compile the Project**
   Navigate to the project directory:
  
   cd 2D-Shape-Drawer
   
   Compile the project using:
  
   g++ -o ShapeDrawer main.cpp -lGL -lglfw -lGLEW
   
   This compiles the source code into an executable.

3. **Run the Application**
   Start the application by running:
  
   ./ShapeDrawer
 

## User Guide

### Keyboard Controls
- **Shape Selection**
  - 1-9, 0`: Switch between various shapes.
- **Transformations**
  - W, S, A, D`: Move the shape up, down, left, and right.
  - E, R`: Rotate the shape clockwise and counter-clockwise.
  - F, G`: Scale the shape up and down.
- **Other Controls**
  - C`: Cycle through predefined colors.
  - V`: Toggle between line and fill modes.
  - Z`: Toggle circular motion.
  - T, Y`: Adjust line thickness.
  - X`: Exit the application.

### Additional Notes
- Use the arrow keys for additional movement control.
- The mouse scroll wheel can be used to zoom in and out for a better view of the canvas.

## Contributions
I welcome contributions to improve the project or add new features. If you're interested in enhancing the application, please fork the repository, make your changes, and submit a pull request.

