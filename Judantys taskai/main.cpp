#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
int taskuSk = 0;

float manoRandom()
{
    return (rand()%1000)/1000.0;
}

struct Taskas
{
     float greitisX;
     float greitisY;
     float dydis;
     float r;
     float g;
     float b;
     float posX;
     float posY;

     //constructor
     Taskas();
     void Vaizduok();

};

Taskas::Taskas()
{
    posX = 0;
    posY = 0;
    r = manoRandom();
    g = manoRandom();
    b = manoRandom();
    greitisX = (manoRandom()*2-1)*0.001;
    greitisY = (manoRandom()*2-1)*0.001;
    dydis = manoRandom()*3+2;

}

void Taskas::Vaizduok()
{
     glPointSize(dydis);
        glBegin(GL_POINTS);
            glColor3f(r,g,b);
            glVertex2f(posX,posY);
        glEnd();
        posX+=greitisX;
        posY+=greitisY;
        if (posX>=0.9)
        {
            greitisX*=-1;
        }
        else if (posX<=-0.9)
        {
            greitisX*=-1;
        }
        //=======================//
        if (posY>=0.9)
        {
            greitisY*=-1;
        }
        else if (posY<=-0.9)
        {
            greitisY*=-1;
        }
}

//kuriam globalu tasku sarasa
vector<Taskas> manoTaskai;

void ManoVaizdas()//pagrindine paisymo funkcija
{
    glClear(GL_COLOR_BUFFER_BIT);//buferio valymo funkcija

    //paisom geltona rema

    glBegin(GL_LINE_LOOP);
        glColor3f(1,1,0);
        glVertex2f(0.9,-0.9);
        glVertex2f(-0.9,-0.9);
        glVertex2f(-0.9,0.9);
        glVertex2f(0.9,0.9);
    glEnd();

    //paisom taskus
    for (int i=0;i<taskuSk;i++)
    {
        manoTaskai.at(i).Vaizduok();
    }

    //glFlush();//refresh
    glutSwapBuffers();
    glutPostRedisplay();
}

void init()
{
    glClearColor(0,0,0,0);//background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char* argv[])
{
    cout << "Iveskite tasku sk: ";
    cin >> taskuSk;
    for (int i=0;i<taskuSk;i++)
    {
        Taskas t;//kuriam nauja taska
        manoTaskai.push_back(t);
    }
    glutInit(&argc,argv);//grafikos inicializavimas
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Mano Pirma proga");
    glutDisplayFunc(ManoVaizdas);
    init();
    glutMainLoop();
    return 0;
}
