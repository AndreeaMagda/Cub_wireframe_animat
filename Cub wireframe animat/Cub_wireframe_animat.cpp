#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

static GLfloat alfaX = 0.0f;
static GLfloat alfaY = 0.0f;
static GLfloat alfaZ = 0.0f;

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
}


void CALLBACK RotesteXSus()
{
    alfaX = alfaX + 10;
}

void CALLBACK RotesteXJos()
{
    alfaX = alfaX - 10;
}

void CALLBACK RotesteYStanga()
{
    alfaY = alfaY - 10;
}

void CALLBACK RotesteYDreapta()
{
    alfaY = alfaY + 10;
}

void CALLBACK RotesteZs()
{
    alfaZ = alfaZ + 10;
}

void CALLBACK RotesteZj()
{
    alfaZ = alfaZ - 10;
}




void CALLBACK display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0, 0, -500.0);

    glColor3f(0.50, 0, 1);
    glRotatef(30, 1.0, 1.0, 0.0);
    glRotatef(alfaX, 1.0, 0.0, 0.0);
    glRotatef(alfaY, 0.0, 1.0, 0.0);
    glRotatef(alfaZ, 0.0, 0.0, 1.0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_TRIANGLES);
    {
        //spate 
        glColor3f(0.50, 0, 1);
        glVertex3f(100.0f, -100.0f, -300.0f);
        glVertex3f(100.0f, 100.0f, -300.0f);
        glVertex3f(-100.0f, -100.0f, -300.0f);
        glVertex3f(-100.0f, -100.0f, -300.0f);
        glVertex3f(-100.0f, 100.0f, -300.0f);
        glVertex3f(100.0f, 100.0f, -300.0f);

        //fata

        glVertex3f(-100.0f, -100.0f, -100.0f);
        glVertex3f(-100.0f, 100.0f, -100.0f);
        glVertex3f(100.0f, -100.0f, -100.0f);
        glVertex3f(100.0f, -100.0f, -100.0f);
        glVertex3f(100.0f, 100.0f, -100.0f);
        glVertex3f(-100.0f, 100.0f, -100.0f);

        //dreapta

        glVertex3f(100.0f, -100.0f, -100.0f);
        glVertex3f(100.0f, 100.0f, -100.0f);
        glVertex3f(100.0f, -100.0f, -300.0f);
        glVertex3f(100.0f, -100.0f, -300.0f);
        glVertex3f(100.0f, 100.0f, -300.0f);
        glVertex3f(100.0f, 100.0f, -100.0f);

        //stanga

        glVertex3f(-100.0f, -100.0f, -300.0f);
        glVertex3f(-100.0f, 100.0f, -300.0f);
        glVertex3f(-100.0f, -100.0f, -100.0f);
        glVertex3f(-100.0f, -100.0f, -100.0f);
        glVertex3f(-100.0f, 100.0f, -100.0f);
        glVertex3f(-100.0f, 100.0f, -300.0f);

        //sus

        glVertex3f(-100.0f, 100.0f, -100.0f);
        glVertex3f(-100.0f, 100.0f, -300.0f);
        glVertex3f(100.0f, 100.0f, -100.0f);
        glVertex3f(100.0f, 100.0f, -100.0f);
        glVertex3f(100.0f, 100.0f, -300.0f);
        glVertex3f(-100.0f, 100.0f, -300.0f);


        //jos

        glVertex3f(-100.0f, -100.0f, -100.0f);
        glVertex3f(-100.0f, -100.0f, -300.0f);
        glVertex3f(100.0f, -100.0f, -100.0f);
        glVertex3f(100.0f, -100.0f, -100.0f);
        glVertex3f(100.0f, -100.0f, -300.0f);
        glVertex3f(-100.0f, -100.0f, -300.0f);


    }
    glEnd();

    glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 800, 600);
    auxInitWindow("Cub wireframe animat");
    myInit();


    auxReshapeFunc(myReshape);
    auxKeyFunc(AUX_q, RotesteXSus);
    auxKeyFunc(AUX_a, RotesteXJos);
    auxKeyFunc(AUX_w, RotesteYStanga);
    auxKeyFunc(AUX_s, RotesteYDreapta);
    auxKeyFunc(AUX_e, RotesteZs);
    auxKeyFunc(AUX_d, RotesteZj);
    auxMainLoop(display);
    return(0);
}
