#include <GL/glut.h>
#include <vector>
#include <iostream>

using namespace std;

void init();
void display();
void reshape(int, int);

// Array to store the color values of the different faces in the rubik's cube
vector<vector<vector<vector<int>>>> cube_color = {{{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}}, {{{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}}, {{{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}}, {{{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}}, {{{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}}, {{{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}}};

void cube(); // To display the stationary cube

void cube_front_face();  // To display a single small square for the front face
void cube_back_face();   // To display a single small square for the back face
void cube_left_face();   // To display a single small square for the left face
void cube_right_face();  // To display a single small square for the right face
void cube_top_face();    // To display a single small square for the top face
void cube_bottom_face(); // To display a single small square for the bottom face

void cube_col1(); // To display the first column of the cube
void cube_col2(); // To display the second column of the cube
void cube_col3(); // To display the third column of the cube

void cube_rotate_col(int x, int angle, int reverse); // To display the column with rotation

void cube_row1(); // To display the first row of the cube
void cube_row2(); // To display the second row of the cube
void cube_row3(); // To display the third row of the cube

void cube_rotate_row(int x, int angle, int reverse); // To display the row with rotation

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Finally the project begins.");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

void init()
{
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    cube();
    cube_rotate_col(2, 90, 1);
    cube_rotate_row(2, 90, 0);
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.67, 2, 50);
    glMatrixMode(GL_MODELVIEW);
}

void cube_front_face(vector<int> &a)
{
    glLineWidth(2);

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3d(-3, 3, 3);
    glVertex3d(-3, 1, 3);
    glVertex3d(-1, 1, 3);
    glVertex3d(-1, 3, 3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(a[0], a[1], a[2]);
    glVertex3d(-3, 3, 3);
    glVertex3d(-3, 1, 3);
    glVertex3d(-1, 1, 3);
    glVertex3d(-1, 3, 3);
    glEnd();
}

void cube_back_face(vector<int> &a)
{
    glLineWidth(2);

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3d(3, 3, -3);
    glVertex3d(3, 1, -3);
    glVertex3d(1, 1, -3);
    glVertex3d(1, 3, -3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(a[0], a[1], a[2]);
    glVertex3d(3, 3, -3);
    glVertex3d(3, 1, -3);
    glVertex3d(1, 1, -3);
    glVertex3d(1, 3, -3);
    glEnd();
}

void cube_left_face(vector<int> &a)
{
    glLineWidth(2);

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3d(-3, 3, -3);
    glVertex3d(-3, 1, -3);
    glVertex3d(-3, 1, -1);
    glVertex3d(-3, 3, -1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(a[0], a[1], a[2]);
    glVertex3d(-3, 3, -3);
    glVertex3d(-3, 1, -3);
    glVertex3d(-3, 1, -1);
    glVertex3d(-3, 3, -1);
    glEnd();
}

void cube_right_face(vector<int> &a)
{
    glLineWidth(2);

    glBegin(GL_LINE_LOOP);
    glColor3d(0, 0, 0);
    glVertex3d(3, 3, 3);
    glVertex3d(3, 1, 3);
    glVertex3d(3, 1, 1);
    glVertex3d(3, 3, 1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3d(a[0], a[1], a[2]);
    glVertex3d(3, 3, 3);
    glVertex3d(3, 1, 3);
    glVertex3d(3, 1, 1);
    glVertex3d(3, 3, 1);
    glEnd();
}

void cube_top_face(vector<int> &a)
{
    glLineWidth(2);

    glBegin(GL_LINE_LOOP);
    glColor3d(0, 0, 0);
    glVertex3d(-3, 3, -3);
    glVertex3d(-3, 3, -1);
    glVertex3d(-1, 3, -1);
    glVertex3d(-1, 3, -3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3d(a[0], a[1], a[2]);
    glVertex3d(-3, 3, -3);
    glVertex3d(-3, 3, -1);
    glVertex3d(-1, 3, -1);
    glVertex3d(-1, 3, -3);
    glEnd();
}

void cube_bottom_face(vector<int> &a)
{
    glLineWidth(2);

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3d(-3, -3, 3);
    glVertex3d(-3, -3, 1);
    glVertex3d(-1, -3, 1);
    glVertex3d(-1, -3, 3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(a[0], a[1], a[2]);
    glVertex3d(-3, -3, 3);
    glVertex3d(-3, -3, 1);
    glVertex3d(-1, -3, 1);
    glVertex3d(-1, -3, 3);
    glEnd();
}

void cube_col1()
{
    for (int i = 0; i < 3; i++)
    {
        cube_front_face(cube_color[0][i][0]);

        glTranslated(0, -2, 0);
    }
    glTranslated(0, 6, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_top_face(cube_color[4][i][0]);
        glTranslated(0, 0, 2);
    }
    glTranslated(0, 0, -6);

    glTranslated(-4, -4, 0);
    for (int i = 0; i < 3; i++)
    {
        cube_back_face(cube_color[1][i][0]);
        glTranslated(0, 2, 0);
    }
    glTranslated(4, -2, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_bottom_face(cube_color[5][i][0]);
        glTranslated(0, 0, -2);
    }

    glTranslated(0, 0, 6);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_left_face(cube_color[2][i][j]);
            glTranslated(0, -2, 0);
        }
        glTranslated(0, 6, 2);
    }

    glTranslated(2, 0, 0);

    vector<int> temp = {0, 0, 0};
    glTranslated(0, 0, -2);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_left_face(temp);
            glTranslated(0, -2, 0);
        }
        glTranslated(0, 6, -2);
    }

    glTranslated(0, 0, 2);
}

void cube_col2()
{
    for (int i = 0; i < 3; i++)
    {
        cube_front_face(cube_color[0][i][0]);

        glTranslated(0, -2, 0);
    }
    glTranslated(0, 6, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_top_face(cube_color[4][i][0]);
        glTranslated(0, 0, 2);
    }
    glTranslated(0, 0, -6);

    glTranslated(-4, -4, 0);
    for (int i = 0; i < 3; i++)
    {
        cube_back_face(cube_color[1][i][0]);
        glTranslated(0, 2, 0);
    }
    glTranslated(4, -2, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_bottom_face(cube_color[5][i][0]);
        glTranslated(0, 0, -2);
    }

    glTranslated(0, 0, 6);

    vector<int> temp = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_left_face(temp);
            glTranslated(0, -2, 0);
        }
        glTranslated(0, 6, 2);
    }

    glTranslated(2, 0, 0);

    glTranslated(0, 0, -2);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_left_face(temp);
            glTranslated(0, -2, 0);
        }
        glTranslated(0, 6, -2);
    }

    glTranslated(0, 0, 2);
}

void cube_col3()
{
    for (int i = 0; i < 3; i++)
    {
        cube_front_face(cube_color[0][i][0]);

        glTranslated(0, -2, 0);
    }
    glTranslated(0, 6, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_top_face(cube_color[4][i][0]);
        glTranslated(0, 0, 2);
    }
    glTranslated(0, 0, -6);

    glTranslated(-4, -4, 0);
    for (int i = 0; i < 3; i++)
    {
        cube_back_face(cube_color[1][i][0]);
        glTranslated(0, 2, 0);
    }
    glTranslated(4, -2, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_bottom_face(cube_color[5][i][0]);
        glTranslated(0, 0, -2);
    }

    glTranslated(0, 0, 6);

    vector<int> temp = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_left_face(temp);
            glTranslated(0, -2, 0);
        }
        glTranslated(0, 6, 2);
    }

    glTranslated(2, 0, 0);

    glTranslated(0, 0, -2);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_left_face(cube_color[3][i][j]);
            glTranslated(0, -2, 0);
        }
        glTranslated(0, 6, -2);
    }

    glTranslated(0, 0, 2);
}

void cube()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(0, 0, -20);
    glRotated(60, 1, 1, 0);

    glLineWidth(2);
    cube_col1();
    cube_col2();
    cube_col3();

    glutSwapBuffers();
}

void cube_rotate_col(int x, int angle, int reverse)
{
    if (x == 0)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.5)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(60, 1, 1, 0);

                glRotated(i, 1, 0, 0);
                cube_col1();
                glRotated(-i, 1, 0, 0);

                cube_col2();
                cube_col3();

                glutSwapBuffers();
            }
        }

        for (float i = 0; i <= angle && !reverse; i += 0.5)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(60, 1, 1, 0);

            glRotated(i, 1, 0, 0);
            cube_col1();
            glRotated(-i, 1, 0, 0);

            cube_col2();
            cube_col3();

            glutSwapBuffers();
        }
    }

    else if (x == 1)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.5)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(60, 1, 1, 0);

                glLineWidth(2);
                cube_col1();

                glRotated(i, 1, 0, 0);
                cube_col2();
                glRotated(-i, 1, 0, 0);

                cube_col3();

                glutSwapBuffers();
            }
        }

        for (float i = 0; i <= angle && !reverse; i += 0.5)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(60, 1, 1, 0);

            glLineWidth(2);
            cube_col1();

            glRotated(i, 1, 0, 0);
            cube_col2();
            glRotated(-i, 1, 0, 0);

            cube_col3();

            glutSwapBuffers();
        }
    }

    else if (x == 2)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.5)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(60, 1, 1, 0);

                glLineWidth(2);
                cube_col1();
                cube_col2();

                glRotated(i, 1, 0, 0);
                cube_col3();
                glRotated(-i, 1, 0, 0);

                glutSwapBuffers();
            }
        }

        for (float i = 0; i <= angle && !reverse; i += 0.5)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(60, 1, 1, 0);

            glLineWidth(2);
            cube_col1();
            cube_col2();

            glRotated(i, 1, 0, 0);
            cube_col3();
            glRotated(-i, 1, 0, 0);

            glutSwapBuffers();
        }
    }
}

void cube_row1()
{
    for (int i = 0; i < 3; i++)
    {
        cube_front_face(cube_color[0][0][i]);
        glTranslated(2, 0, 0);
    }
    glTranslated(-6, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_right_face(cube_color[3][0][i]);
        glTranslated(0, 0, -2);
    }

    glTranslated(0, 0, 6);

    for (int i = 0; i < 3; i++)
    {
        cube_back_face(cube_color[1][0][i]);
        glTranslated(-2, 0, 0);
    }

    glTranslated(6, 0, 0);
    for (int i = 0; i < 3; i++)
    {
        cube_left_face(cube_color[2][0][i]);
        glTranslated(0, 0, 2);
    }
    glTranslated(0, 0, -6);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_top_face(cube_color[4][i][j]);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, 0, 2);
    }

    glTranslated(0, 4, -6);

    vector<int> temp = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_bottom_face(temp);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, 0, -2);
    }
    glTranslated(0, -6, 6);
}

void cube_row2()
{
    for (int i = 0; i < 3; i++)
    {
        cube_front_face(cube_color[0][1][i]);
        glTranslated(2, 0, 0);
    }
    glTranslated(-6, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_right_face(cube_color[3][1][i]);
        glTranslated(0, 0, -2);
    }

    glTranslated(0, 0, 6);

    for (int i = 0; i < 3; i++)
    {
        cube_back_face(cube_color[1][1][i]);
        glTranslated(-2, 0, 0);
    }

    glTranslated(6, 0, 0);
    for (int i = 0; i < 3; i++)
    {
        cube_left_face(cube_color[2][1][i]);
        glTranslated(0, 0, 2);
    }
    glTranslated(0, 0, -6);

    vector<int> temp = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_top_face(temp);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, 0, 2);
    }

    glTranslated(0, 4, -6);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_bottom_face(temp);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, 0, -2);
    }
    glTranslated(0, -6, 6);
}

void cube_row3()
{
    for (int i = 0; i < 3; i++)
    {
        cube_front_face(cube_color[0][1][i]);
        glTranslated(2, 0, 0);
    }
    glTranslated(-6, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_right_face(cube_color[3][1][i]);
        glTranslated(0, 0, -2);
    }

    glTranslated(0, 0, 6);

    for (int i = 0; i < 3; i++)
    {
        cube_back_face(cube_color[1][1][i]);
        glTranslated(-2, 0, 0);
    }

    glTranslated(6, 0, 0);
    for (int i = 0; i < 3; i++)
    {
        cube_left_face(cube_color[2][1][i]);
        glTranslated(0, 0, 2);
    }
    glTranslated(0, 0, -6);

    vector<int> temp = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_top_face(temp);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, 0, 2);
    }

    glTranslated(0, 4, -6);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_bottom_face(cube_color[5][i][j]);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, 0, -2);
    }
    glTranslated(0, -6, 6);
}

void cube_rotate_row(int x, int angle, int reverse)
{
    if (x == 0)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.5)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(60, 1, 1, 0);

                glRotated(i, 0, 1, 0);
                cube_row1();
                glRotated(-i, 0, 1, 0);

                cube_row2();
                cube_row3();

                glutSwapBuffers();
            }
        }

        for (float i = 0; i <= angle && !reverse; i += 0.5)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(60, 1, 1, 0);

            glRotated(i, 0, 1, 0);
            cube_row1();
            glRotated(-i, 0, 1, 0);

            cube_row2();
            cube_row3();

            glutSwapBuffers();
        }
    }

    else if (x == 1)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.5)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(60, 1, 1, 0);

                glLineWidth(2);
                cube_row1();

                glRotated(i, 0, 1, 0);
                cube_row2();
                glRotated(-i, 0, 1, 0);

                cube_row3();

                glutSwapBuffers();
            }
        }

        for (float i = 0; i <= angle && !reverse; i += 0.5)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(60, 1, 1, 0);

            glLineWidth(2);
            cube_row1();

            glRotated(i, 0, 1, 0);
            cube_row2();
            glRotated(-i, 0, 1, 0);

            cube_row3();

            glutSwapBuffers();
        }
    }

    else if (x == 2)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.5)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(60, 1, 1, 0);

                glLineWidth(2);
                cube_row1();
                cube_row2();

                glRotated(i, 0, 1, 0);
                cube_row3();
                glRotated(-i, 0, 1, 0);

                glutSwapBuffers();
            }
        }

        for (float i = 0; i <= angle && !reverse; i += 0.5)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(60, 1, 1, 0);

            glLineWidth(2);
            cube_row1();
            cube_row2();

            glRotated(i, 0, 1, 0);
            cube_row3();
            glRotated(-i, 0, 1, 0);

            glutSwapBuffers();
        }
    }
}