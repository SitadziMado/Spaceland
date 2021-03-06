#include "stdafx.h"

#include <iostream>

#include <GL/freeglut.h>

#include "Game.h"
#include <algorithm>

using namespace Core;

Game game = Game();

void initGl()
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    glLoadIdentity();               // Reset the model-view matrix

    for (auto&& entity : game.world_.entities_)
    {
        auto[x, y, _] = entity->getPosition().asTuple();

        glPushMatrix();                     // Save model-view matrix setting
        glTranslatef(0.6f, -0.6f, 0.0f);    // Translate
        // glRotatef(180.0f + angle, 0.0f, 0.0f, 1.0f); // Rotate 180+angle degree
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2d(x, y);
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex2d(x + 1., y);
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex2d(x, y + 1.);
        glEnd();
        glPopMatrix();                      // Restore the model-view matrix 
    }

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    height = std::max(height, 1);

    const auto aspect = static_cast<GLfloat>(width) / static_cast<GLfloat>(height);

    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport.
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix.
    glLoadIdentity();

    static constexpr auto Scale = 12.f;

    if (width >= height)
    { // Aspect >= 1, set the height from -1 to 1, with larger width.
        gluOrtho2D(-Scale * aspect, Scale * aspect, -Scale, Scale);
    }
    else 
    { // Aspect < 1, set the width to -1 to 1, with larger height.
        gluOrtho2D(-Scale, Scale, -Scale / aspect, Scale / aspect);
    }
}

void timer(int value) 
{
    game.onTick(Game::FrameMilliseconds);

    glutPostRedisplay();
    glutTimerFunc(
        static_cast<unsigned>(Game::FrameMilliseconds), 
        timer,
        0
    );
}

int main(int argc, char* argv[])
{
    game.createEntity("Human");
    game.start();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Game");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    initGl();
    glutMainLoop();

    game.stop();

    /* using namespace std::chrono_literals;
    using namespace std::this_thread;

    auto game = Game();

    game.start();

    std::string input;

    while (game.isAlive())
    {
        std::getline(std::cin, input);

        if (input == "exit")
        {
            game.stop();
            sleep_for(500ms);
        }
        else if (input == "pause")
        {
            game.pause();
        }
    } */

    return 0;
}
