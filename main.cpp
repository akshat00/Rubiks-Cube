//File for graphics

#include <GL/glut.h>
#include <vector>
#include <iostream>

using namespace std;

void init();
void display();
void reshape(int, int);

// Array to store the color values of the different faces in the rubik's cube
// vector<vector<vector<vector<int>>>> cube_color = {{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}}, {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}}, {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}}, {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}}, {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}}, {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}}};
vector<vector<vector<vector<int>>>> cube_color = {{{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}}, {{{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}}, {{{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}}, {{{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}}, {{{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}}, {{{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}}};

int flag = 0;                 // To check if the mouse left key is pressed or not
float angle1 = 0, angle2 = 0; // Angles to alter the camera view
int btn_x, btn_y;             // To store the value of the location where the left mouse key was pressed and also track its position while it is pressed

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

void cube_face1(); // To display the first face of the cube
void cube_face2(); // To display the second face of the cube
void cube_face3(); // To display the third face of the cube

void cube_rotate_face(int x, int angle, int reverse); // To display the face with rotation

void detect_button(int button, int state, int x, int y); // To detect when the left key is pressed and released

void change_camera_position(int x, int y); // To change the camera view using mouse inputs

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
    glutMouseFunc(detect_button);
    glutMotionFunc(change_camera_position);

    glutMainLoop();

    return 0;
}

void init()
{
    glClearColor(0.31, 0.32, 0.34, 1);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    cube();
    cube_rotate_col(1, 90, 1);
    cube_rotate_row(0, 90, 0);
    cube_rotate_face(2, 90, 1);
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.67, 2, 50);
    glMatrixMode(GL_MODELVIEW);
}

void detect_button(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        btn_x = x;
        btn_y = y;
        flag = 1;
    }

    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        flag = 0;
    }
}

void change_camera_position(int x, int y)
{
    if (flag == 1)
    {

        if (angle1 >= 90 && angle1 <= 270)
        {
            angle2 += (btn_x - x) * 0.5;
        }

        else if (angle1 > -90)
        {
            angle2 -= (btn_x - x) * 0.5;
        }

        else if (angle1 <= -90 && angle1 > -270)
        {
            angle2 += (btn_x - x) * 0.5;
        }

        else if (angle1 <= -270 && angle1 >= -360)
        {
            angle2 -= (btn_x - x) * 0.5;
        }

        angle1 -= (btn_y - y) * 0.5;

        angle1 = (abs(angle1) > 360) ? 0 : angle1;
        angle2 = (abs(angle2) > 360) ? 0 : angle2;

        btn_x = x;
        btn_y = y;

        cube();
    }
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
            glTranslated(0, 0, 2);
        }
        glTranslated(0, -2, -6);
    }

    vector<int> temp = {0, 0, 0};
    glTranslated(-4, 6, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_right_face(temp);
            glTranslated(0, 0, -2);
        }
        glTranslated(0, -2, 6);
    }

    glTranslated(6, 6, 0);
}

void cube_col2()
{
    for (int i = 0; i < 3; i++)
    {
        cube_front_face(cube_color[0][i][1]);

        glTranslated(0, -2, 0);
    }
    glTranslated(0, 6, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_top_face(cube_color[4][i][1]);
        glTranslated(0, 0, 2);
    }
    glTranslated(0, 0, -6);

    glTranslated(-4, -4, 0);
    for (int i = 0; i < 3; i++)
    {
        cube_back_face(cube_color[1][i][1]);
        glTranslated(0, 2, 0);
    }
    glTranslated(4, -2, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_bottom_face(cube_color[5][i][1]);
        glTranslated(0, 0, -2);
    }

    glTranslated(0, 0, 6);

    vector<int> temp = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_left_face(temp);
            glTranslated(0, 0, 2);
        }
        glTranslated(0, -2, -6);
    }

    glTranslated(-4, 6, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_right_face(temp);
            glTranslated(0, 0, -2);
        }
        glTranslated(0, -2, 6);
    }

    glTranslated(6, 6, 0);
}

void cube_col3()
{
    for (int i = 0; i < 3; i++)
    {
        cube_front_face(cube_color[0][i][2]);

        glTranslated(0, -2, 0);
    }
    glTranslated(0, 6, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_top_face(cube_color[4][i][2]);
        glTranslated(0, 0, 2);
    }
    glTranslated(0, 0, -6);

    glTranslated(-4, -4, 0);
    for (int i = 0; i < 3; i++)
    {
        cube_back_face(cube_color[1][i][2]);
        glTranslated(0, 2, 0);
    }
    glTranslated(4, -2, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_bottom_face(cube_color[5][i][2]);
        glTranslated(0, 0, -2);
    }

    glTranslated(0, 0, 6);

    vector<int> temp = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_left_face(temp);
            glTranslated(0, 0, 2);
        }
        glTranslated(0, -2, -6);
    }

    glTranslated(-4, 6, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_right_face(cube_color[3][i][j]);
            glTranslated(0, 0, -2);
        }
        glTranslated(0, -2, 6);
    }

    glTranslated(6, 6, 0);
}

void cube()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(0, 0, -20);
    glRotated(angle1, 1, 0, 0);
    glRotated(angle2, 0, 1, 0);

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
            for (float i = 0; i >= -angle; i -= 0.8)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(angle1, 1, 0, 0);
                glRotated(angle2, 0, 1, 0);

                glRotated(i, 1, 0, 0);
                cube_col1();
                glRotated(-i, 1, 0, 0);

                cube_col2();
                cube_col3();

                glutSwapBuffers();
            }

            vector<int> temp;

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[0][i][0];
                    cube_color[0][i][0] = cube_color[5][i][0];
                    cube_color[5][i][0] = cube_color[1][i][0];
                    cube_color[1][i][0] = cube_color[4][i][0];
                    cube_color[4][i][0] = temp;
                }
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                temp = cube_color[2][0][0];
                cube_color[2][0][0] = cube_color[2][0][2];
                cube_color[2][0][2] = cube_color[2][2][2];
                cube_color[2][2][2] = cube_color[2][2][0];
                cube_color[2][2][0] = temp;

                temp = cube_color[2][0][1];
                cube_color[2][0][1] = cube_color[2][1][2];
                cube_color[2][1][2] = cube_color[2][2][1];
                cube_color[2][2][1] = cube_color[2][1][0];
                cube_color[2][1][0] = temp;
            }

            return;
        }

        for (float i = 0; i <= angle && !reverse; i += 0.8)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(angle1, 1, 0, 0);
            glRotated(angle2, 0, 1, 0);

            glRotated(i, 1, 0, 0);
            cube_col1();
            glRotated(-i, 1, 0, 0);

            cube_col2();
            cube_col3();

            glutSwapBuffers();
        }

        vector<int> temp;

        for (int k = 0; k < (angle / 90); k++)
        {
            for (int i = 0; i < 3; i++)
            {
                temp = cube_color[0][i][0];
                cube_color[0][i][0] = cube_color[4][i][0];
                cube_color[4][i][0] = cube_color[1][i][0];
                cube_color[1][i][0] = cube_color[5][i][0];
                cube_color[5][i][0] = temp;
            }
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            temp = cube_color[2][0][0];
            cube_color[2][0][0] = cube_color[2][2][0];
            cube_color[2][2][0] = cube_color[2][2][2];
            cube_color[2][2][2] = cube_color[2][0][2];
            cube_color[2][0][2] = temp;

            temp = cube_color[2][0][1];
            cube_color[2][0][1] = cube_color[2][1][0];
            cube_color[2][1][0] = cube_color[2][2][1];
            cube_color[2][2][1] = cube_color[2][1][2];
            cube_color[2][1][2] = temp;
        }
    }

    else if (x == 1)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.8)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(angle1, 1, 0, 0);
                glRotated(angle2, 0, 1, 0);

                glLineWidth(2);
                cube_col1();

                glRotated(i, 1, 0, 0);
                cube_col2();
                glRotated(-i, 1, 0, 0);

                cube_col3();

                glutSwapBuffers();
            }

            vector<int> temp;

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[0][i][1];
                    cube_color[0][i][1] = cube_color[5][i][1];
                    cube_color[5][i][1] = cube_color[1][i][1];
                    cube_color[1][i][1] = cube_color[4][i][1];
                    cube_color[4][i][1] = temp;
                }
            }

            return;
        }

        for (float i = 0; i <= angle && !reverse; i += 0.8)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(angle1, 1, 0, 0);
            glRotated(angle2, 0, 1, 0);

            glLineWidth(2);
            cube_col1();

            glRotated(i, 1, 0, 0);
            cube_col2();
            glRotated(-i, 1, 0, 0);

            cube_col3();

            glutSwapBuffers();
        }

        vector<int> temp;

        for (int k = 0; k < (angle / 90); k++)
        {
            for (int i = 0; i < 3; i++)
            {
                temp = cube_color[0][i][1];
                cube_color[0][i][1] = cube_color[4][i][1];
                cube_color[4][i][1] = cube_color[1][i][1];
                cube_color[1][i][1] = cube_color[5][i][1];
                cube_color[5][i][1] = temp;
            }
        }
    }

    else if (x == 2)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.8)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(angle1, 1, 0, 0);
                glRotated(angle2, 0, 1, 0);

                glLineWidth(2);
                cube_col1();
                cube_col2();

                glRotated(i, 1, 0, 0);
                cube_col3();
                glRotated(-i, 1, 0, 0);

                glutSwapBuffers();
            }

            vector<int> temp;

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[0][i][2];
                    cube_color[0][i][2] = cube_color[5][i][2];
                    cube_color[5][i][2] = cube_color[1][i][2];
                    cube_color[1][i][2] = cube_color[4][i][2];
                    cube_color[4][i][2] = temp;
                }
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                temp = cube_color[3][0][0];
                cube_color[3][0][0] = cube_color[3][2][0];
                cube_color[3][2][0] = cube_color[3][2][2];
                cube_color[3][2][2] = cube_color[3][0][2];
                cube_color[3][0][2] = temp;

                temp = cube_color[3][0][1];
                cube_color[3][0][1] = cube_color[3][1][0];
                cube_color[3][1][0] = cube_color[3][2][1];
                cube_color[3][2][1] = cube_color[3][1][2];
                cube_color[3][1][2] = temp;
            }

            return;
        }

        for (float i = 0; i <= angle && !reverse; i += 0.8)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(angle1, 1, 0, 0);
            glRotated(angle2, 0, 1, 0);

            glLineWidth(2);
            cube_col1();
            cube_col2();

            glRotated(i, 1, 0, 0);
            cube_col3();
            glRotated(-i, 1, 0, 0);

            glutSwapBuffers();
        }

        vector<int> temp;

        for (int k = 0; k < (angle / 90); k++)
        {
            for (int i = 0; i < 3; i++)
            {
                temp = cube_color[0][i][2];
                cube_color[0][i][2] = cube_color[4][i][2];
                cube_color[4][i][2] = cube_color[1][i][2];
                cube_color[1][i][2] = cube_color[5][i][2];
                cube_color[5][i][2] = temp;
            }
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            temp = cube_color[3][0][0];
            cube_color[3][0][0] = cube_color[3][0][2];
            cube_color[3][0][2] = cube_color[3][2][2];
            cube_color[3][2][2] = cube_color[3][2][0];
            cube_color[3][2][0] = temp;

            temp = cube_color[3][0][1];
            cube_color[3][0][1] = cube_color[3][1][2];
            cube_color[3][1][2] = cube_color[3][2][1];
            cube_color[3][2][1] = cube_color[3][1][0];
            cube_color[3][1][0] = temp;
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
    vector<int> temp;
    if (x == 0)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.8)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(angle1, 1, 0, 0);
                glRotated(angle2, 0, 1, 0);

                glRotated(i, 0, 1, 0);
                cube_row1();
                glRotated(-i, 0, 1, 0);

                cube_row2();
                cube_row3();

                glutSwapBuffers();
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[0][0][i];
                    cube_color[0][0][i] = cube_color[3][0][i];
                    cube_color[3][0][i] = cube_color[1][2][2 - i];
                    cube_color[1][2][2 - i] = cube_color[2][0][i];
                    cube_color[2][0][i] = temp;
                }
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                temp = cube_color[4][0][0];
                cube_color[4][0][0] = cube_color[4][2][0];
                cube_color[4][2][0] = cube_color[4][2][2];
                cube_color[4][2][2] = cube_color[4][0][2];
                cube_color[4][0][2] = temp;

                temp = cube_color[4][0][1];
                cube_color[4][0][1] = cube_color[4][1][0];
                cube_color[4][1][0] = cube_color[4][2][1];
                cube_color[4][2][1] = cube_color[4][1][2];
                cube_color[4][1][2] = temp;
            }

            return;
        }

        for (float i = 0; i <= angle && !reverse; i += 0.8)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(angle1, 1, 0, 0);
            glRotated(angle2, 0, 1, 0);

            glRotated(i, 0, 1, 0);
            cube_row1();
            glRotated(-i, 0, 1, 0);

            cube_row2();
            cube_row3();

            glutSwapBuffers();
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            for (int i = 0; i < 3; i++)
            {
                temp = cube_color[0][0][i];
                cube_color[0][0][i] = cube_color[2][0][i];
                cube_color[2][0][i] = cube_color[1][2][2 - i];
                cube_color[1][2][2 - i] = cube_color[3][0][i];
                cube_color[3][0][i] = temp;
            }
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            temp = cube_color[4][0][0];
            cube_color[4][0][0] = cube_color[4][0][2];
            cube_color[4][0][2] = cube_color[4][2][2];
            cube_color[4][2][2] = cube_color[4][2][0];
            cube_color[4][2][0] = temp;

            temp = cube_color[4][0][1];
            cube_color[4][0][1] = cube_color[4][1][2];
            cube_color[4][1][2] = cube_color[4][2][1];
            cube_color[4][2][1] = cube_color[4][1][0];
            cube_color[4][1][0] = temp;
        }
    }

    else if (x == 1)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.8)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(angle1, 1, 0, 0);
                glRotated(angle2, 0, 1, 0);

                glLineWidth(2);
                cube_row1();

                glRotated(i, 0, 1, 0);
                cube_row2();
                glRotated(-i, 0, 1, 0);

                cube_row3();

                glutSwapBuffers();
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[0][0][i];
                    cube_color[0][1][i] = cube_color[3][1][i];
                    cube_color[3][1][i] = cube_color[1][1][2 - i];
                    cube_color[1][1][2 - i] = cube_color[2][1][i];
                    cube_color[2][1][i] = temp;
                }
            }

            return;
        }

        for (float i = 0; i <= angle && !reverse; i += 0.8)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(angle1, 1, 0, 0);
            glRotated(angle2, 0, 1, 0);

            glLineWidth(2);
            cube_row1();

            glRotated(i, 0, 1, 0);
            cube_row2();
            glRotated(-i, 0, 1, 0);

            cube_row3();

            glutSwapBuffers();
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            for (int i = 0; i < 3; i++)
            {
                temp = cube_color[0][0][i];
                cube_color[0][1][i] = cube_color[2][1][i];
                cube_color[2][1][i] = cube_color[1][1][2 - i];
                cube_color[1][1][2 - i] = cube_color[3][1][i];
                cube_color[3][1][i] = temp;
            }
        }
    }

    else if (x == 2)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.8)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(angle1, 1, 0, 0);
                glRotated(angle2, 0, 1, 0);

                glLineWidth(2);
                cube_row1();
                cube_row2();

                glRotated(i, 0, 1, 0);
                cube_row3();
                glRotated(-i, 0, 1, 0);

                glutSwapBuffers();
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[0][0][i];
                    cube_color[0][2][i] = cube_color[3][2][i];
                    cube_color[3][2][i] = cube_color[1][0][2 - i];
                    cube_color[1][0][2 - i] = cube_color[2][2][i];
                    cube_color[2][2][i] = temp;
                }
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                temp = cube_color[5][0][0];
                cube_color[5][0][0] = cube_color[5][0][2];
                cube_color[5][0][2] = cube_color[5][2][2];
                cube_color[5][2][2] = cube_color[5][2][0];
                cube_color[5][2][0] = temp;

                temp = cube_color[5][0][1];
                cube_color[5][0][1] = cube_color[5][1][2];
                cube_color[5][1][2] = cube_color[5][2][1];
                cube_color[5][2][1] = cube_color[5][1][0];
                cube_color[5][1][0] = temp;
            }

            return;
        }

        for (float i = 0; i <= angle && !reverse; i += 0.8)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(angle1, 1, 0, 0);
            glRotated(angle2, 0, 1, 0);

            glLineWidth(2);
            cube_row1();
            cube_row2();

            glRotated(i, 0, 1, 0);
            cube_row3();
            glRotated(-i, 0, 1, 0);

            glutSwapBuffers();
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            for (int i = 0; i < 3; i++)
            {
                temp = cube_color[0][0][i];
                cube_color[0][2][i] = cube_color[2][2][i];
                cube_color[2][2][i] = cube_color[1][0][2 - i];
                cube_color[1][0][2 - i] = cube_color[3][2][i];
                cube_color[3][2][i] = temp;
            }
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            temp = cube_color[5][0][0];
            cube_color[5][0][0] = cube_color[5][2][0];
            cube_color[5][2][0] = cube_color[5][2][2];
            cube_color[5][2][2] = cube_color[5][0][2];
            cube_color[5][0][2] = temp;

            temp = cube_color[5][0][1];
            cube_color[5][0][1] = cube_color[5][1][0];
            cube_color[5][1][0] = cube_color[5][2][1];
            cube_color[5][2][1] = cube_color[5][1][2];
            cube_color[5][1][2] = temp;
        }
    }
}

void cube_face1()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_front_face(cube_color[0][i][j]);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, -2, 0);
    }

    glTranslated(0, 6, 4);

    for (int i = 0; i < 3; i++)
    {
        cube_left_face(cube_color[2][i][2]);
        glTranslated(0, -2, 0);
    }

    glTranslated(0, 6, -4);

    for (int i = 0; i < 3; i++)
    {
        cube_bottom_face(cube_color[5][0][i]);
        glTranslated(2, 0, 0);
    }

    glTranslated(-6, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_right_face(cube_color[3][i][0]);
        glTranslated(0, -2, 0);
    }

    glTranslated(4, 6, 4);

    for (int i = 0; i < 3; i++)
    {
        cube_top_face(cube_color[4][2][i]);
        glTranslated(-2, 0, 0);
    }

    vector<int> temp = {0, 0, 0};

    glTranslated(-2, -4, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_back_face(temp);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, 2, 0);
    }
    glTranslated(4, -2, -6);
}

void cube_face2()
{
    vector<int> temp = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_front_face(temp);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, -2, 0);
    }

    glTranslated(0, 6, 4);

    for (int i = 0; i < 3; i++)
    {
        cube_left_face(cube_color[2][i][1]);
        glTranslated(0, -2, 0);
    }

    glTranslated(0, 6, -4);

    for (int i = 0; i < 3; i++)
    {
        cube_bottom_face(cube_color[5][1][i]);
        glTranslated(2, 0, 0);
    }

    glTranslated(-6, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_right_face(cube_color[3][i][1]);
        glTranslated(0, -2, 0);
    }

    glTranslated(4, 6, 4);

    for (int i = 0; i < 3; i++)
    {
        cube_top_face(cube_color[4][1][i]);
        glTranslated(-2, 0, 0);
    }

    glTranslated(-2, -4, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_back_face(temp);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, 2, 0);
    }
    glTranslated(4, -2, -6);
}

void cube_face3()
{
    vector<int> temp = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_front_face(temp);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, -2, 0);
    }

    glTranslated(0, 6, 4);

    for (int i = 0; i < 3; i++)
    {
        cube_left_face(cube_color[2][i][0]);
        glTranslated(0, -2, 0);
    }

    glTranslated(0, 6, -4);

    for (int i = 0; i < 3; i++)
    {
        cube_bottom_face(cube_color[5][2][i]);
        glTranslated(2, 0, 0);
    }

    glTranslated(-6, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_right_face(cube_color[3][i][2]);
        glTranslated(0, -2, 0);
    }

    glTranslated(4, 6, 4);

    for (int i = 0; i < 3; i++)
    {
        cube_top_face(cube_color[4][0][i]);
        glTranslated(-2, 0, 0);
    }

    glTranslated(-2, -4, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube_back_face(cube_color[1][i][j]);
            glTranslated(2, 0, 0);
        }
        glTranslated(-6, 2, 0);
    }
}

void cube_rotate_face(int x, int angle, int reverse)
{
    vector<int> temp;
    if (x == 0)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.8)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(angle1, 1, 0, 0);
                glRotated(angle2, 0, 1, 0);

                glRotated(i, 0, 0, -1);
                cube_face1();
                glRotated(-i, 0, 0, -1);

                cube_face2();
                cube_face3();

                glutSwapBuffers();
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[2][i][2];
                    cube_color[2][i][2] = cube_color[4][2][i];
                    cube_color[4][2][i] = cube_color[3][i][0];
                    cube_color[3][i][0] = cube_color[5][0][i];
                    cube_color[5][0][i] = temp;
                }
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                temp = cube_color[4][0][0];
                cube_color[0][0][0] = cube_color[0][0][2];
                cube_color[0][0][2] = cube_color[0][2][2];
                cube_color[0][2][2] = cube_color[0][2][0];
                cube_color[0][2][0] = temp;

                temp = cube_color[0][0][1];
                cube_color[0][0][1] = cube_color[0][1][2];
                cube_color[0][1][2] = cube_color[0][2][1];
                cube_color[0][2][1] = cube_color[0][1][0];
                cube_color[0][1][0] = temp;
            }

            return;
        }

        for (float i = 0; i <= angle && !reverse; i += 0.8)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(angle1, 1, 0, 0);
            glRotated(angle2, 0, 1, 0);

            glRotated(i, 0, 0, -1);
            cube_face1();
            glRotated(-i, 0, 0, -1);

            cube_face2();
            cube_face3();

            glutSwapBuffers();
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            for (int i = 0; i < 3; i++)
            {
                temp = cube_color[2][i][2];
                cube_color[2][i][2] = cube_color[5][0][i];
                cube_color[5][0][i] = cube_color[3][i][0];
                cube_color[3][i][0] = cube_color[4][2][i];
                cube_color[4][2][i] = temp;
            }
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            temp = cube_color[0][0][0];
            cube_color[0][0][0] = cube_color[0][2][0];
            cube_color[0][2][0] = cube_color[0][2][2];
            cube_color[0][2][2] = cube_color[0][0][2];
            cube_color[0][0][2] = temp;

            temp = cube_color[0][0][1];
            cube_color[0][0][1] = cube_color[0][1][0];
            cube_color[0][1][0] = cube_color[0][2][1];
            cube_color[0][2][1] = cube_color[0][1][2];
            cube_color[0][1][2] = temp;
        }
    }

    else if (x == 1)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.8)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(angle1, 1, 0, 0);
                glRotated(angle2, 0, 1, 0);

                glLineWidth(2);
                cube_face1();

                glRotated(i, 0, 0, -1);
                cube_face2();
                glRotated(-i, 0, 0, -1);

                cube_face3();

                glutSwapBuffers();
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[2][i][1];
                    cube_color[2][i][1] = cube_color[4][1][i];
                    cube_color[4][1][i] = cube_color[3][i][1];
                    cube_color[3][i][1] = cube_color[5][1][i];
                    cube_color[5][1][i] = temp;
                }
            }

            return;
        }

        for (float i = 0; i <= angle && !reverse; i += 0.8)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(angle1, 1, 0, 0);
            glRotated(angle2, 0, 1, 0);

            glLineWidth(2);
            cube_face1();

            glRotated(i, 0, 0, -1);
            cube_face2();
            glRotated(-i, 0, 0, -1);

            cube_face3();

            glutSwapBuffers();
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            for (int i = 0; i < 3; i++)
            {
                temp = cube_color[2][i][2];
                cube_color[2][i][1] = cube_color[5][1][i];
                cube_color[5][1][i] = cube_color[3][i][1];
                cube_color[3][i][1] = cube_color[4][1][i];
                cube_color[4][1][i] = temp;
            }
        }
    }

    else if (x == 2)
    {
        if (reverse == 1)
        {
            for (float i = 0; i >= -angle; i -= 0.8)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();

                glTranslated(0, 0, -20);
                glRotated(angle1, 1, 0, 0);
                glRotated(angle2, 0, 1, 0);

                glLineWidth(2);
                cube_face1();
                cube_face2();

                glRotated(i, 0, 0, -1);
                cube_face3();
                glRotated(-i, 0, 0, -1);

                glutSwapBuffers();
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[2][i][0];
                    cube_color[2][i][0] = cube_color[4][0][i];
                    cube_color[4][0][i] = cube_color[3][i][2];
                    cube_color[3][i][2] = cube_color[5][2][i];
                    cube_color[5][2][i] = temp;
                }
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                temp = cube_color[1][0][0];
                cube_color[1][0][0] = cube_color[1][2][0];
                cube_color[1][2][0] = cube_color[1][2][2];
                cube_color[1][2][2] = cube_color[1][0][2];
                cube_color[1][0][2] = temp;

                temp = cube_color[1][0][1];
                cube_color[1][0][1] = cube_color[1][1][0];
                cube_color[1][1][0] = cube_color[1][2][1];
                cube_color[1][2][1] = cube_color[1][1][2];
                cube_color[1][1][2] = temp;
            }

            return;
        }

        for (float i = 0; i <= angle && !reverse; i += 0.8)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            glTranslated(0, 0, -20);
            glRotated(angle1, 1, 0, 0);
            glRotated(angle2, 0, 1, 0);

            glLineWidth(2);
            cube_face1();
            cube_face2();

            glRotated(i, 0, 0, -1);
            cube_face3();
            glRotated(-i, 0, 0, -1);

            glutSwapBuffers();
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            for (int i = 0; i < 3; i++)
            {
                temp = cube_color[2][i][0];
                cube_color[2][i][0] = cube_color[5][2][i];
                cube_color[5][2][i] = cube_color[3][i][2];
                cube_color[3][i][2] = cube_color[4][0][i];
                cube_color[4][0][i] = temp;
            }
        }

        for (int k = 0; k < (angle / 90); k++)
        {
            temp = cube_color[1][0][0];
            cube_color[1][0][0] = cube_color[1][0][2];
            cube_color[1][0][2] = cube_color[1][2][2];
            cube_color[1][2][2] = cube_color[1][2][0];
            cube_color[1][2][0] = temp;

            temp = cube_color[1][0][1];
            cube_color[1][0][1] = cube_color[1][1][2];
            cube_color[1][1][2] = cube_color[1][2][1];
            cube_color[1][2][1] = cube_color[1][1][0];
            cube_color[1][1][0] = temp;
        }
    }
}