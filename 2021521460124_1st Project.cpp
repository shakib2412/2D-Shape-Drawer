/*****************************************************************************
        Student Information
        Student ID: 2021521460124
        Student Name: SHAKIB AL HASAN
*****************************************************************************/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

enum ShapeType {
    SQUARE = 1,
    TRIANGLE = 2,
    CIRCLE = 3,
    PENTAGON = 4,
    OVAL = 5,
    TRAPEZIUM = 6,
    PARALLELOGRAM = 7,
    HEXAGON = 8,
    HEPTAGON = 9,
    OCTAGON = 0
};

float lineSize = 1.0f;

float translateX = 0.0f;
float translateY = 0.0f;
float rotateAngle = 0.0f;

float LineX = 0.0f;
float LineY = 0.0f;

bool isLineMode = true;

ShapeType selectedShape = TRIANGLE;

float circularPathAngle = 0.0f;
bool moveAlongCircularPath = false;

GLfloat colors[][3] = {
    {0.0f, 1.0f, 1.0f}, // Cyan
    {0.0f, 1.0f, 0.0f}, // Green
    {0.0f, 0.0f, 1.0f}, // Blue
    {1.0f, 1.0f, 0.0f}, // Yellow
    {1.0f, 0.0f, 1.0f}, // Magenta
    {0.0f, 0.5f, 1.0f}, // Light Blue
    {0.5f, 0.5f, 0.5f}, // Gray
    {1.0f, 0.5f, 0.0f}, // Orange
    {0.0f, 0.8f, 0.0f}  // Lime Green
};

int currentColorIndex = 0;

void setColor() {
    glColor3fv(colors[currentColorIndex]);
}

void cycleColor() {
    currentColorIndex = (currentColorIndex + 1) % (sizeof(colors) / sizeof(colors[0]));
}

void drawTriangle() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);    glVertex2f(0.0f, 0.1f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glEnd();
}

void drawOval() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);
    for (int i = 0; i <= 360; i += 5) {
        float angle = i * 3.14159265358979323846 / 180;
        glVertex2f(0.15f * cos(angle), 0.1f * sin(angle));
    }
    glEnd();
}

void drawCircle() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);
    for (int i = 0; i <= 360; i += 5) {
        float angle = i * 3.14159265358979323846 / 180;
        glVertex2f(0.1f * cos(angle), 0.1f * sin(angle));
    }
    glEnd();
}

void drawTrapezium() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glEnd();
}
void drawSquare() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
}

void drawParallelogram() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
}

void drawPentagon() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);    for (int i = 0; i < 5; ++i) {
        float angle = i * 2 * 3.14159265358979323846 / 5;
        glVertex2f(0.1f * cos(angle), 0.1f * sin(angle));
    }
    glEnd();
}

void drawHexagon() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);
    for (int i = 0; i < 6; ++i) {
        float angle = i * 2 * 3.14159265358979323846 / 6;
        glVertex2f(0.1f * cos(angle), 0.1f * sin(angle));
    }
    glEnd();
}

void drawHeptagon() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);
    for (int i = 0; i < 7; ++i) {
        float angle = i * 2 * 3.14159265358979323846 / 7;
        glVertex2f(0.1f * cos(angle), 0.1f * sin(angle));
    }
    glEnd();
}

void drawOctagon() {
    glLineWidth(lineSize);
    glBegin(isLineMode ? GL_LINE_LOOP : GL_POLYGON);
    for (int i = 0; i < 8; ++i) {
        float angle = i * 2 * 3.14159265358979323846 / 8;
        glVertex2f(0.1f * cos(angle), 0.1f * sin(angle));
    }
    glEnd();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            
            case GLFW_KEY_X:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
                
            case GLFW_KEY_1:
                selectedShape = TRIANGLE;
                break;
            case GLFW_KEY_2:
                selectedShape = OVAL;
                break;
            case GLFW_KEY_3:
                selectedShape = CIRCLE;
                break;
            case GLFW_KEY_4:
                selectedShape = TRAPEZIUM;
                break;
            case GLFW_KEY_5:
                selectedShape = SQUARE;
                break;
            case GLFW_KEY_6:
                selectedShape = PARALLELOGRAM;
                break;
            case GLFW_KEY_7:
                selectedShape = PENTAGON;
                break;
            case GLFW_KEY_8:
                selectedShape = HEXAGON;
                break;
            case GLFW_KEY_9:
                selectedShape = HEPTAGON;
                break;
            case GLFW_KEY_0:
                selectedShape = OCTAGON;
                break;
                
            case GLFW_KEY_W:
                translateY += 0.1f;
                break;
            case GLFW_KEY_S:
                translateY -= 0.1f;
                break;
            case GLFW_KEY_A:
                translateX -= 0.1f;
                break;
            case GLFW_KEY_D:
                translateX += 0.1f;
                break;
            case GLFW_KEY_E:
                rotateAngle += 0.3f;
                break;
            case GLFW_KEY_R:
                rotateAngle -= 0.3f;
                break;
            case GLFW_KEY_F:
                LineX += 0.05f;
                LineY += 0.05f;
                break;
            case GLFW_KEY_G:
                LineX -= 0.05f;
                LineY -= 0.05f;
                break;
            case GLFW_KEY_C:
                cycleColor();
                break;
            case GLFW_KEY_V:
                isLineMode = !isLineMode;
                break;
            case GLFW_KEY_Z:
                moveAlongCircularPath = true; // Set the flag to true when 'P' is pressed
                break;
            case GLFW_KEY_T:
                 lineSize += 4.0f;
                break;
            case GLFW_KEY_Y:
                 lineSize -= 4.0f;
                break;
            default:
                moveAlongCircularPath = false; // Reset the flag for other keys
                selectedShape = static_cast<ShapeType>(key - GLFW_KEY_0);
                break;
                

        }
    }
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glScalef(1.8f, 2.0f, 1.0f);
    glTranslatef(translateX, translateY, 0.0f);
    glRotatef(rotateAngle * 180.0f / 3.14159265358979323846, 0.0f, 0.0f, 1.0f);
    glTranslatef(LineX, LineY, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    if (moveAlongCircularPath) {
        circularPathAngle += 0.03f; // Adjust the speed of movement along the circular path
        LineX = 0.2f * cos(circularPathAngle);
        LineY = 0.2f * sin(circularPathAngle);
    }

    switch (selectedShape) {
        case TRIANGLE:
            drawTriangle();
            break;
        case OVAL:
            drawOval();
            break;
        case CIRCLE:
            drawCircle();
            break;
        case TRAPEZIUM:
            drawTrapezium();
            break;
        case SQUARE:
            drawSquare();
            break;
        case PARALLELOGRAM:
            drawParallelogram();
            break;
        case PENTAGON:
            drawPentagon();
            break;
        case HEXAGON:
            drawHexagon();
            break;
        case HEPTAGON:
            drawHeptagon();
            break;
        case OCTAGON:
            drawOctagon();
            break;
    }
    glPopMatrix();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "2D SCENE", NULL, NULL);
    if (!window) {
        std::cerr << "Window creation failed" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW initialization failed" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, keyCallback);


    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        
        glClear(GL_COLOR_BUFFER_BIT);

        setColor();

        // Draw the shapes
        drawScene();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
