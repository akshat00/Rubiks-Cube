//File for graphics

#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void init();
void display();
void reshape(int, int);
void title();
void r();
void u();
void b();
void i();
void k();
void s();


// Array to store the color values of the different faces in the rubik's cube
// vector<vector<vector<vector<int>>>> cube_color = {{{{1, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}}, {{{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}}, {{{0, 0, 1}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}}, {{{1, 1, 0}, {0, 0, 0}, {0, 0, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}}, {{{0, 1, 1}, {0, 0, 0}, {0, 0, 0}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}}, {{{1, 0, 1}, {0, 0, 0}, {0, 0, 0}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}}};
vector<vector<vector<vector<int>>>> cube_color = {{{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}}, {{{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}}, {{{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}}, {{{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}, {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}}, {{{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}, {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}}}, {{{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}, {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}}}};
vector<vector<vector<string>>> cube_pos = {{{"F1", "F2", "F3"}, {"F4", "F5", "F6"}, {"F7", "F8", "F9"}}, {{"B1", "B2", "B3"}, {"B4", "B5", "B6"}, {"B7", "B8", "B9"}}, {{"L1", "L2", "L3"}, {"L4", "L5", "L6"}, {"L7", "L8", "L9"}}, {{"R1", "R2", "R3"}, {"R4", "R5", "R6"}, {"R7", "R8", "R9"}}, {{"U1", "U2", "U3"}, {"U4", "U5", "U6"}, {"U7", "U8", "U9"}}, {{"D1", "D2", "D3"}, {"D4", "D5", "D6"}, {"D7", "D8", "D9"}}};

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

string get_current_pos(); //To get the current configuration of the rubik's cube for solving

void draw_user_buttons(); //To draw the various user buttons on the screen

void rotate_left_face(int flag);   // To rotate the left face for the current face visible
void rotate_right_face(int flag);  // To rotate the right face for the current face visible
void rotate_front_face(int flag);  // To rotate the front face for the current face visible
void rotate_back_face(int flag);   // To rotate the back face for the current face visible
void rotate_top_face(int flag);    // To rotate the top face for the current face visible
void rotate_bottom_face(int flag); // To rotate the bottom face for the current face visible

void shuffle_cube(); //To shuffle the ribik's cube to a random configuration
void solve_cube();   //To automatically solve the rubick's cube to its original configuration

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
//    title();
    cube();
    // get_current_pos();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    gluOrtho2D(-10,10,-10,10);
    gluPerspective(60, 1.67, 2, 50);
    glMatrixMode(GL_MODELVIEW);
}

void detect_button(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (x >= 33 && x <= 137 && y >= 510 && y <= 562)
        {
            rotate_left_face(0);
            return;
        }

        else if (x >= 190 && x <= 295 && y >= 510 && y <= 562)
        {
            rotate_right_face(0);
            return;
        }

        else if (x >= 345 && x <= 450 && y >= 510 && y <= 562)
        {
            rotate_front_face(0);
            return;
        }

        else if (x >= 500 && x <= 605 && y >= 510 && y <= 562)
        {
            rotate_back_face(0);
            return;
        }

        else if (x >= 655 && x <= 760 && y >= 510 && y <= 562)
        {
            rotate_top_face(0);
            return;
        }

        else if (x >= 810 && x <= 925 && y >= 510 && y <= 562)
        {
            rotate_bottom_face(0);
            return;
        }

        else if (x >= 810 && x <= 925 && y >= 195 && y <= 246)
        {
            shuffle_cube();
            return;
     }

        else if (x >= 810 && x <= 925 && y >= 299 && y <= 351)
        {
            solve_cube();
            return;
        }


        btn_x = x;
        btn_y = y;
        flag = 1;
    }

    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        flag = 0;
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        if (x >= 33 && x <= 137 && y >= 510 && y <= 562)
        {
            rotate_left_face(1);
            return;
        }

        else if (x >= 190 && x <= 295 && y >= 510 && y <= 562)
        {
            rotate_right_face(1);
            return;
        }

        else if (x >= 345 && x <= 450 && y >= 510 && y <= 562)
        {
            rotate_front_face(1);
            return;
        }

        else if (x >= 500 && x <= 605 && y >= 510 && y <= 562)
        {
            rotate_back_face(1);
            return;
        }

        else if (x >= 655 && x <= 760 && y >= 510 && y <= 562)
        {
            rotate_top_face(1);
            return;
        }

        else if (x >= 810 && x <= 925 && y >= 510 && y <= 562)
        {
            rotate_bottom_face(1);
            return;
        }
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

        angle1 = (abs((int)angle1) > 360) ? 0 : angle1;
        angle2 = (abs((int)angle2) > 360) ? 0 : angle2;

        btn_x = x;
        btn_y = y;

        // cout << angle1 << " " << angle2 << endl;

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

    glTranslated(0, 0, -10);
    draw_user_buttons();
    title();
    glTranslated(0, 0, -10);

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
            string temp1;

            for (int k = 0; k < (angle / 90); k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp = cube_color[0][i][0];
                    cube_color[0][i][0] = cube_color[5][i][0];
                    cube_color[5][i][0] = cube_color[1][i][0];
                    cube_color[1][i][0] = cube_color[4][i][0];
                    cube_color[4][i][0] = temp;

                    temp1 = cube_pos[0][i][0];
                    cube_pos[0][i][0] = cube_pos[5][i][0];
                    cube_pos[5][i][0] = cube_pos[1][i][0];
                    cube_pos[1][i][0] = cube_pos[4][i][0];
                    cube_pos[4][i][0] = temp1;
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

                temp1 = cube_pos[2][0][0];
                cube_pos[2][0][0] = cube_pos[2][0][2];
                cube_pos[2][0][2] = cube_pos[2][2][2];
                cube_pos[2][2][2] = cube_pos[2][2][0];
                cube_pos[2][2][0] = temp1;

                temp1 = cube_pos[2][0][1];
                cube_pos[2][0][1] = cube_pos[2][1][2];
                cube_pos[2][1][2] = cube_pos[2][2][1];
                cube_pos[2][2][1] = cube_pos[2][1][0];
                cube_pos[2][1][0] = temp1;
            }

            cube();

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

            cube();

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

            cube();

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

    cube();
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
        cube_back_face(cube_color[1][2][2 - i]);
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
        cube_front_face(cube_color[0][2][i]);
        glTranslated(2, 0, 0);
    }
    glTranslated(-6, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        cube_right_face(cube_color[3][2][i]);
        glTranslated(0, 0, -2);
    }

    glTranslated(0, 0, 6);

    for (int i = 0; i < 3; i++)
    {
        cube_back_face(cube_color[1][0][2 - i]);
        glTranslated(-2, 0, 0);
    }

    glTranslated(6, 0, 0);
    for (int i = 0; i < 3; i++)
    {
        cube_left_face(cube_color[2][2][i]);
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

            cube();

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

            cube();

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

            cube();

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
                temp = cube_color[0][2][i];
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

    cube();
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
        cube_top_face(cube_color[4][2][2 - i]);
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
        cube_top_face(cube_color[4][1][2 - i]);
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
        cube_top_face(cube_color[4][0][2 - i]);
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
                    cube_color[2][i][2] = cube_color[4][2][2 - i];
                    cube_color[4][2][2 - i] = cube_color[3][2 - i][0];
                    cube_color[3][2 - i][0] = cube_color[5][0][i];
                    cube_color[5][0][i] = temp;
                }
            }

            for (int k = 0; k < (angle / 90); k++)
            {
                temp = cube_color[0][0][0];
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

            cube();

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
                temp = cube_color[2][2 - i][2];
                cube_color[2][2 - i][2] = cube_color[5][0][2 - i];
                cube_color[5][0][2 - i] = cube_color[3][i][0];
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
                    cube_color[2][i][1] = cube_color[4][1][2 - i];
                    cube_color[4][1][2 - i] = cube_color[3][2 - i][1];
                    cube_color[3][2 - i][1] = cube_color[5][1][i];
                    cube_color[5][1][i] = temp;
                }
            }

            cube();

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
                temp = cube_color[2][2 - i][2];
                cube_color[2][2 - i][1] = cube_color[5][1][2 - i];
                cube_color[5][1][2 - i] = cube_color[3][i][1];
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
                    cube_color[2][i][0] = cube_color[4][0][2 - i];
                    cube_color[4][0][2 - i] = cube_color[3][2 - i][2];
                    cube_color[3][2 - i][2] = cube_color[5][2][i];
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

            cube();

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
                temp = cube_color[2][2 - i][0];
                cube_color[2][2 - i][0] = cube_color[5][2][2 - i];
                cube_color[5][2][2 - i] = cube_color[3][i][2];
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

    cube();
}

string get_current_pos()
{
    string s, temp;

    for (auto item : cube_pos[4])
    {
        for (auto it : item)
        {
            temp = it[0];
            s.append(temp);
        }
    }

    for (auto item : cube_pos[3])
    {
        for (auto it : item)
        {
            temp = it[0];
            s.append(temp);
        }
    }

    for (auto item : cube_pos[0])
    {
        for (auto it : item)
        {
            temp = it[0];
            s.append(temp);
        }
    }

    for (auto item : cube_pos[5])
    {
        for (auto it : item)
        {
            temp = it[0];
            s.append(temp);
        }
    }

    for (auto item : cube_pos[2])
    {
        for (auto it : item)
        {
            temp = it[0];
            s.append(temp);
        }
    }

    for (int i = 2; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            temp = cube_pos[1][i][j][0];
            s.append(temp);
        }
    }

    return s;
}

void draw_user_buttons()
{
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(-9, -4);
    glVertex2d(-9, -5);
    glVertex2d(-7, -5);
    glVertex2d(-7, -4);

    glVertex2d(-6, -4);
    glVertex2d(-6, -5);
    glVertex2d(-4, -5);
    glVertex2d(-4, -4);

    glVertex2d(-3, -4);
    glVertex2d(-3, -5);
    glVertex2d(-1, -5);
    glVertex2d(-1, -4);

    glVertex2d(0, -4);
    glVertex2d(0, -5);
    glVertex2d(2, -5);
    glVertex2d(2, -4);

    glVertex2d(3, -4);
    glVertex2d(3, -5);
    glVertex2d(5, -5);
    glVertex2d(5, -4);

    glVertex2d(6, -4);
    glVertex2d(6, -5);
    glVertex2d(8.2, -5);
    glVertex2d(8.2, -4);

    glVertex2d(6, 1);
    glVertex2d(6, 2);
    glVertex2d(8.2, 2);
    glVertex2d(8.2, 1);

    glVertex2d(6, 0);
    glVertex2d(6, -1);
    glVertex2d(8.2, -1);
    glVertex2d(8.2, 0);

    glEnd();

    string s = "Left Face";
    glColor3f(0, 0, 0);
    glRasterPos3f(-8.6, -4.55, 0.1);
    int len, i;
    len = s.length();
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }

    s = "Right Face";
    glColor3f(0, 0, 0);
    glRasterPos3f(-5.75, -4.55, 0.1);
    len = s.length();
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }

    s = "Front Face";
    glColor3f(0, 0, 0);
    glRasterPos3f(-2.8, -4.55, 0.1);
    len = s.length();
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }

    s = "Back Face";
    glColor3f(0, 0, 0);
    glRasterPos3f(0.2, -4.55, 0.1);
    len = s.length();
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }

    s = "Top Face";
    glColor3f(0, 0, 0);
    glRasterPos3f(3.2, -4.55, 0.1);
    len = s.length();
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }

    s = "Bottom Face";
    glColor3f(0, 0, 0);
    glRasterPos3f(6, -4.55, 0.1);
    len = s.length();
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }

     s = "Shuffle Cube";
    glColor3f(0, 0, 0);
    glRasterPos3f(6, 1.35, 0.1);
    len = s.length();
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }

     s = "Solve Cube";
    glColor3f(0, 0, 0);
    glRasterPos3f(6.1, -0.65, 0.1);
    len = s.length();
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }
}

void rotate_left_face(int flag)
{
    if (angle1 <= 45 && angle1 >= -45 && angle2 <= 45 && angle2 >= -45)
        cube_rotate_col(0, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -45 && angle2 >= -135) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 315 && angle2 >= 225))
        cube_rotate_face(0, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -135 && angle2 >= -225) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 225 && angle2 >= 135))
        cube_rotate_col(2, 90, !flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -225 && angle2 >= -315) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 135 && angle2 >= 45))
        cube_rotate_face(2, 90, !flag);
}

void rotate_right_face(int flag)
{
    if (angle1 <= 45 && angle1 >= -45 && angle2 <= 45 && angle2 >= -45)
        cube_rotate_col(2, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -45 && angle2 >= -135) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 315 && angle2 >= 225))
        cube_rotate_face(2, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -135 && angle2 >= -225) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 225 && angle2 >= 135))
        cube_rotate_col(0, 90, !flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -225 && angle2 >= -315) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 135 && angle2 >= 45))
        cube_rotate_face(0, 90, !flag);
}

void rotate_front_face(int flag)
{
    if (angle1 <= 45 && angle1 >= -45 && angle2 <= 45 && angle2 >= -45)
        cube_rotate_face(0, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -45 && angle2 >= -135) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 315 && angle2 >= 225))
        cube_rotate_col(2, 90, !flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -135 && angle2 >= -225) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 225 && angle2 >= 135))
        cube_rotate_face(2, 90, !flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -225 && angle2 >= -315) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 135 && angle2 >= 45))
        cube_rotate_col(0, 90, flag);
}

void rotate_back_face(int flag)
{
    if (angle1 <= 45 && angle1 >= -45 && angle2 <= 45 && angle2 >= -45)
        cube_rotate_face(2, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -45 && angle2 >= -135) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 315 && angle2 >= 225))
        cube_rotate_col(0, 90, !flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -135 && angle2 >= -225) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 225 && angle2 >= 135))
        cube_rotate_face(0, 90, !flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -225 && angle2 >= -315) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 135 && angle2 >= 45))
        cube_rotate_col(2, 90, flag);
}

void rotate_top_face(int flag)
{
    if (angle1 <= 45 && angle1 >= -45 && angle2 <= 45 && angle2 >= -45)
        cube_rotate_row(0, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -45 && angle2 >= -135) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 315 && angle2 >= 225))
        cube_rotate_row(0, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -135 && angle2 >= -225) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 225 && angle2 >= 135))
        cube_rotate_row(0, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -225 && angle2 >= -315) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 135 && angle2 >= 45))
        cube_rotate_row(0, 90, flag);
}

void rotate_bottom_face(int flag)
{
    if (angle1 <= 45 && angle1 >= -45 && angle2 <= 45 && angle2 >= -45)
        cube_rotate_row(2, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -45 && angle2 >= -135) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 315 && angle2 >= 225))
        cube_rotate_row(2, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -135 && angle2 >= -225) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 225 && angle2 >= 135))
        cube_rotate_row(2, 90, flag);

    else if ((angle1 <= 45 && angle1 >= -45 && angle2 <= -225 && angle2 >= -315) || (angle1 <= 45 && angle1 >= -45 && angle2 <= 135 && angle2 >= 45))
        cube_rotate_row(2, 90, flag);
}

void shuffle_cube()
{
    {
    int x, i;
    srand((unsigned) time(0));
    for(i = 0; i < 30; i++)
    {
        x = (int)rand()%12 + 1;
        switch(x)
        {
        case 1:
            rotate_top_face(0);
            break;
        case 2:
            rotate_bottom_face(0);
            break;
        case 3:
            rotate_left_face(0);
            break;
        case 4:
            rotate_front_face(0);
            break;
        case 5:
            rotate_right_face(0);
            break;
        case 6:
            rotate_back_face(0);
            break;
        case 7:
            rotate_top_face(1);
            break;
        case 8:
            rotate_bottom_face(1);
            break;
        case 9:
            rotate_left_face(1);
            break;
        case 10:
            rotate_right_face(1);
            break;
        case 11:
            rotate_front_face(1);
            break;
        case 12:
            rotate_back_face(1);
            break;
        }
    }
}

}
void title(){

//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();

    glPointSize(30.0);

    r();
    u();
    b();
    i();
    k();
    s();

}
void r()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);

    glVertex2f(-8,9);
    glVertex2f(-8,8);
    glVertex2f(-8,7);
    glVertex2f(-8,6);
    glVertex2f(-8,5);
    glVertex2f(-8,4);
    glVertex2f(-7.4,9);
    glVertex2f(-7.4,7);
    glVertex2f(-6.6,8);
    glVertex2f(-6.5,5.8);
    glVertex2f(-6.5,4);
    glVertex2f(-6.5,5);
    glVertex2f(-8,9);
//    glVertex2f(-8,9);
    glEnd();
}
void u()
{
    glColor3f(0,1,0);
    glBegin(GL_POINTS);

    glVertex2f(-5.5,9);
    glVertex2f(-5.5,8);
    glVertex2f(-5.5,7);
    glVertex2f(-5.5,6);
    glVertex2f(-5.5,5);
    glVertex2f(-5,4);
    glVertex2f(-4.5,4);
    glVertex2f(-4,9);
    glVertex2f(-4,7);
    glVertex2f(-4,8);
    glVertex2f(-4,6);
    glVertex2f(-4,5);

    glEnd();
}
void b()
{
    glColor3f(0,0,1);
    glBegin(GL_POINTS);

    glVertex2f(-3,9);
    glVertex2f(-3,8);
    glVertex2f(-3,7);
    glVertex2f(-3,6);
    glVertex2f(-3,5);
    glVertex2f(-3,4);
    glVertex2f(-2.4,9);
    glVertex2f(-1.6,8);
    glVertex2f(-2.4,7);
    glVertex2f(-1.6,6);
    glVertex2f(-1.6,5);
    glVertex2f(-2.4,4);

    glEnd();

}
void i()
{
    glColor3f(0,1,1);
    glBegin(GL_POINTS);

    glVertex2f(-0.6,9);
    glVertex2f(-0.6,8);
    glVertex2f(-0.6,7);
    glVertex2f(-0.6,6);
    glVertex2f(-0.6,5);
    glVertex2f(-0.6,4);

    glEnd();

}
void k()
{
    glColor3f(1,1,0);
    glBegin(GL_POINTS);

    glVertex2f(0.6,9);
    glVertex2f(0.6,8);
    glVertex2f(0.6,7);
    glVertex2f(0.6,6);
    glVertex2f(0.6,5);
    glVertex2f(0.6,4);
    glVertex2f(2.1,9);
    glVertex2f(1.8,8);
    glVertex2f(1.4,7);
    glVertex2f(1.7,6);
    glVertex2f(2,5);
    glVertex2f(2.3,4);

    glEnd();

}
void s()
{
    glColor3f(1,0,1);
    glBegin(GL_POINTS);

    glVertex2f(3.3,9);
    glVertex2f(3.3,8);
    glVertex2f(3.3,7);
    glVertex2f(4.8,6);
    glVertex2f(4.8,5);
    glVertex2f(3.3,4);
    glVertex2f(4,9);
    glVertex2f(4.8,9);
    glVertex2f(4,7);
    glVertex2f(4.8,7);
    glVertex2f(4,4);
    glVertex2f(4.8,4);

    glEnd();

}

void solve_cube()
{
    angle1 = 0;
    angle2 = 30;
    ofstream fout("C:\\Users\\agmoh\\Desktop\\CG PROJECT\\POSITION.txt", ios::out);
    fout<<get_current_pos();

    fout.close();


    ifstream fin;

    fin.open("C:\\Users\\agmoh\\Desktop\\CG PROJECT\\SOLUTION.txt", ios::in);

    string ch;

    while(fin){
        getline(fin, ch);
    }

    fin.close();
    int length = ch.length();
    char x;

    for(int i = 0; i < length; i++)
    {
        x = ch[i];

        i++;
        if(ch[i] == '\'' && i < length)
        {
            switch(x){
            case 'U':
                cout<<"U1";
                rotate_top_face(1);
                i++;
                break;
            case 'D':
                cout<<"D1";
                rotate_bottom_face(1);
                i++;
                break;
            case 'L':
                cout<<"L1";
                rotate_left_face(1);
                i++;
                break;
            case 'R':
                cout<<"R1";
                rotate_right_face(1);
                i++;
                break;
            case 'F':
                cout<<"F1";
                rotate_front_face(1);
                i++;
                break;
            case 'B':
                cout<<"B1";
                rotate_back_face(1);
                i++;
                break;
            }
        }
        else if (ch[i] == '2' && i < length)
            {
                switch(x)
                {
                    case 'U':
                        rotate_top_face(0);
                        rotate_top_face(0);
                        cout<<"UU";
                        i++;
                        break;
                    case 'D':
                        rotate_bottom_face(0);
                        rotate_bottom_face(0);
                        cout<<"DD";
                        i++;
                        break;
                    case 'L':
                        rotate_left_face(0);
                        rotate_left_face(0);
                        cout<<"LL";
                        i++;
                        break;
                    case 'R':
                        cout<<"RR";
                        rotate_right_face(0);
                        rotate_right_face(0);
                        i++;
                        break;
                    case 'F':
                        cout<<"FF";
                        rotate_front_face(0);
                        rotate_front_face(0);
                        i++;
                        break;
                    case 'B':
                        cout<<"BB";
                        rotate_back_face(0);
                        rotate_back_face(0);
                        i++;
                        break;
                }
            }
        else
            {
            switch(x)
            {

                case 'U':
                    cout<<"U";
                    rotate_top_face(0);
                    break;
                case 'D':
                    cout<<"D";
                    rotate_bottom_face(0);
                    break;
                case 'L':
                    cout<<"L";
                    rotate_left_face(0);
                    break;
                case 'R':
                    cout<<"R";
                    rotate_right_face(0);
                    break;
                case 'F':
                    cout<<"F";
                    rotate_front_face(0);
                    break;
                case 'B':
                    cout<<"B";
                    rotate_back_face(0);
                    break;
            }
        }
    }
}
