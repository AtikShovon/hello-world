#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include<Windows.h>
#include<mmsystem.h>
using namespace std;


float _movef = 0.0f;///fish
float _moveft = 0.0f;///train
float _movec = 0.0f;///Blue and Yellow car
float _movefb = 0.0f;///yellow fish
float _move3 = 0.0f;///boat
float _move6 = 0.0f;///cloud1
float _move7 = 0.0f;///cloud2
float speed = 0.0f;///Red car
float speedt = 0.0f;///train speed
float sr=0.52;///sky red
float sg=0.80;
float sb=0.98;
float cr=1.0;///cloud red
float cg=1.0;
float cb=1.0;
float str=0.52;///star red
float stg=0.80;
float stb=0.98;
float mr=1.0;//moon and sun
float mg=1.0;
float mb=0.0;
float mr1=0.52;///moon and sun red
float mg1=0.80;
float mb1=0.98;
float br= 130;///building and train window red
float bg= 150;
float bb= 137;
float la=0.4;///car light red
float lb=0.4;
float lc=0.4;
float ra=0.4;///road red
float rb=0.4;
float rc=0.4;
float savedSpeed = 0.0f;
bool paused = false;
float _angle1 = 0.0f;
float _move = 0.0f;
float tr=0;
float tg=1;
float tb=0;
float tr2=0;
float tg2=0;
float tb2=0;
int dcheck=0;///day and night check
float a=0.0;///Yellow car
float b=0.0;///blue car
float flag=0,traffic_regulator=1,control_keyl,control_keyr;
GLfloat red=0,blue=1,green=.3;

GLfloat p=0,q=0,r=1;



float getR(float x){
return x/255.00;
}

float getG(float y){
return y/255.00;
}

float getB(float x){
return x/255.00;
}

float getX(float x){
return x/750.00;
}
float getY(float y){
return y/400.00;
}

void update2(int value)
{
a=a+.006;
if(a-1.1 > 1.0)
    {
        a = -1.5;

    }
b=b+.006;
if(b-1.1 > 1.0)
    {
        b = -1.5;

    }

/*making day to night*/


glutPostRedisplay();
}


void drawScene() {

     if(traffic_regulator)
glutTimerFunc(50,update2,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity(); ///Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

	///sky
glPushMatrix();
    glBegin(GL_POLYGON);
 glColor3f(sr,sg,sb);
        glVertex3f(1.00f,  getY(36), 0.0f);
        glVertex3f(1.00f, getY(400), 0.0f);
        glVertex3f(-1.00f,getY(400), 0.0f);
        glVertex3f(-1.00f, getY(36), 0.0f);
	glEnd();
    glPopMatrix();
    ///Stars///

    glPushMatrix();


                    glPointSize(2.0);
                   glColor3d(str,stg,stb);

                   glBegin(GL_POINTS);



                   glVertex3f(getX(250),getY(260),0.0f);
                    glVertex3f(getX(-250),getY(280),0.0f);
                     glVertex3f(getX(-320),getY(320),0.0f);
                      glVertex3f(getX(450),getY(350),0.0f);
                       glVertex3f(getX(500),getY(270),0.0f);
                        glVertex3f(getX(-400),getY(320),0.0f);
                         glVertex3f(getX(-310),getY(258),0.0f);
                          glVertex3f(getX(-140),getY(310),0.0f);
                           glVertex3f(getX(50),getY(360),0.0f);
                            glVertex3f(getX(170),getY(385),0.0f);
                             glVertex3f(getX(200),getY(415),0.0f);
                              glVertex3f(getX(100),getY(440),0.0f);
                              glVertex3f(getX(-560),getY(298),0.0f);
                              glVertex3f(getX(-420),getY(358),0.0f);

       glEnd();



    glPopMatrix();

	///Moon and sun //
   //Sun//
     //Sun//
     glPushMatrix();
   glTranslatef(0.8, 0.85, 0.0);
   glColor3f(mr1,mg1,mb1);
	glBegin(GL_POLYGON);

	for(int i=0;i<650;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
   glTranslatef(0.787, 0.87, 0.0);
   glColor3f(mr,mg,mb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();





///clouds///
	///cloud1///

	    glPushMatrix();
   glTranslatef(_move6+0.2, 0.8, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

       glPushMatrix();
   glTranslatef(_move6+0.28, 0.8, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

  glPushMatrix();
   glTranslatef(_move6+0.35, 0.8, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move6+0.2, 0.75, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move6+0.28, 0.75, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move6+0.35, 0.75, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move6+0.15, 0.77, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move6+0.39, 0.77, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

///Cloud 2///
            glPushMatrix();
   glTranslatef(_move7+0.6, 0.6, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move7+0.68, 0.6, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move7+0.75, 0.6, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move7+0.6, 0.65, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move7+0.68, 0.65, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move7+0.75, 0.65, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move7+0.55, 0.62, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix();
   glTranslatef(_move7+0.79, 0.62, 0.0);
   glColor3f(cr,cg,cb);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

///Cloud End///

    ///Road Start
     glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(ra,rb,rc);
        glVertex3f(1.00f,  +0.03-0.16, 0.0f);
        glVertex3f(1.00f, +.03-0.30, 0.0f);
        glVertex3f(-1.00f, +0.03-0.30f, 0.0f);
        glVertex3f(-1.00f, +0.03-0.16f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3d(ra,rb,rc);
        glVertex3f(1.00f, -0.04+0.09, 0.0f);
        glVertex3f(1.00f, -0.04-0.05, 0.0f);
        glVertex3f(-1.00f, -0.04-0.05f, 0.0f);
        glVertex3f(-1.00f,-0.04+0.09f, 0.0f);
	glEnd();
    glPopMatrix();
    ///road white strips
    glPushMatrix();

    glColor3d(1,1,1);

    for(float i=-1;i<3;i+=0.06){

        glBegin(GL_POLYGON);
        glVertex3f(i,+0.04-0.16, 0.0f);
        glVertex3f(i,+0.04 -0.14, 0.0f);
        glVertex3f(i+0.04f, +0.04-0.14f, 0.0f);
        glVertex3f(i+0.04f,+0.04-0.16f, 0.0f);
        glEnd();

    }
glPopMatrix();
///road finished

///Rail Tracks///
glPushMatrix();
    for(float i=-1;i<3;i+=0.06){
        glColor3d(0.47,0.21,0.02);
        glBegin(GL_POLYGON);
        glVertex3f(0.02+i,-0.02-0.15-0.16, 0.0f);
        glVertex3f(0.02+i,-0.02-0.15 -0.14, 0.0f);
        glVertex3f(0.02+i+0.04f,-0.02-0.15-0.14f, 0.0f);
        glVertex3f(0.02+i+0.04f,-0.02-0.15-0.16f, 0.0f);
        glEnd();

        glColor3d(0.60,0.60,0.60);
        glBegin(GL_POLYGON);
        glVertex3f(+0.009+0.02+i,-0.02-0.15-0.16, 0.0f);
        glVertex3f(-0.009+0.02+i+0.04f,-0.02-0.15-0.16f, 0.0f);
        glVertex3f(-0.009+0.02+i+0.04f,+0.02-0.30-0.14f, 0.0f);
        glVertex3f(+0.009+0.02+i,+0.02-0.30 -0.14, 0.0f);


        glEnd();
        glColor3d(0.47,0.21,0.02);
        glBegin(GL_POLYGON);
        glVertex3f(0.02+i,+0.02-0.30-0.16, 0.0f);
        glVertex3f(0.02+i,+0.02-0.30 -0.14, 0.0f);
        glVertex3f(0.02+i+0.04f,+0.02-0.30-0.14f, 0.0f);
        glVertex3f(0.02+i+0.04f,+0.02-0.30-0.16f, 0.0f);
        glEnd();

    }
glPopMatrix();

///Train///
glPushMatrix();
glTranslatef(_moveft, 0.00f, 0.0f);
    ///TrB1 Train Engine blue
    glPushMatrix();
        glBegin(GL_POLYGON);
     glColor3d(getR(0),getG(43),getB(85));
                glVertex3f(-0.7+0.5,-0.38, 0.0f);
                glVertex3f(-0.7+0.13,-0.38, 0.0f);
                glVertex3f(-0.7+0.1,-0.41, 0.0f);
                glVertex3f(-0.7+0.5,-0.41, 0.0f);
        glEnd();
        glBegin(GL_POLYGON);
     glColor3d(getR(0),getG(43),getB(85));
                glVertex3f(-0.7+0.5,-0.38, 0.0f);
                glVertex3f(-0.7+0.13,-0.38, 0.0f);
                glVertex3f(-0.7+0.13,-0.32, 0.0f);
                glVertex3f(-0.7+0.5,-0.32, 0.0f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3d(1,1,1);
                glVertex3f(-0.7+0.5,-0.32, 0.0f);
                glVertex3f(-0.7+0.13,-0.32, 0.0f);
                glVertex3f(-0.7+0.14,-0.30, 0.0f);
                glVertex3f(-0.7+0.5,-0.30, 0.0f);
        glEnd();
    glPopMatrix();
///Connectors///
glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3d(.60,0.0,0.31);
        glVertex3f(-0.7+0.5,-0.40, 0.0f);
        glVertex3f(-0.7+0.5,-0.385, 0.0f);
        glVertex3f(-0.7+0.52,-0.385, 0.0f);
        glVertex3f(-0.7+0.52,-0.40, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3d(.60,0.0,0.31);
        glVertex3f(-0.7+0.92,-0.40, 0.0f);
        glVertex3f(-0.7+0.92,-0.385, 0.0f);
        glVertex3f(-0.7+0.94,-0.385, 0.0f);
        glVertex3f(-0.7+0.94,-0.40, 0.0f);
    glEnd();
glPopMatrix();

    ///TrB2 Train Body 1 green
    glPushMatrix();
        glBegin(GL_POLYGON);
     glColor3d(0,.38,0);
                    glVertex3f(-0.7+0.92,-0.41, 0.0f);
                    glVertex3f(-0.7+0.52,-0.41, 0.0f);
                    glVertex3f(-0.7+0.52,-0.30, 0.0f);
                    glVertex3f(-0.7+0.92,-0.30, 0.0f);
        glEnd();
    glPopMatrix();
    ///TrB3 Train Body 2 white
    glPushMatrix();
        glBegin(GL_POLYGON);
     glColor3d(1.0,0.0,0.0);
                    glVertex3f(-0.7+0.94,-0.41, 0.0f);
                    glVertex3f(-0.7+1.34,-0.41, 0.0f);
                    glVertex3f(-0.7+1.34,-0.30, 0.0f);
                    glVertex3f(-0.7+0.94,-0.30, 0.0f);
        glEnd();
    glPopMatrix();
    ///TrWndB1 Train Engine
    glPushMatrix();
        for(float i=0.15;i<0.5;i+=0.05){
            glBegin(GL_POLYGON);
            glColor3d(0,0,0);
                glVertex3f(-0.7+i-0.002,-0.373, 0.0f);
                glVertex3f(-0.7+i+0.022,-0.373, 0.0f);
                glVertex3f(-0.7+i+0.022,-0.327, 0.0f);
                glVertex3f(-0.7+i-0.002,-0.327, 0.0f);
            glEnd();
        }
        for(float i=0.15;i<0.5;i+=0.05){
            glBegin(GL_POLYGON);
     glColor3d(getR(br),getG(bg),getB(bb));
                glVertex3f(-0.7+i,-0.37, 0.0f);
                glVertex3f(-0.7+i+0.02,-0.37, 0.0f);
                glVertex3f(-0.7+i+0.02,-0.33, 0.0f);
                glVertex3f(-0.7+i,-0.33, 0.0f);
            glEnd();
        }
    glPopMatrix();
    ///TrWndB2
    glPushMatrix();
        for(float i=0.54;i<0.92;i+=0.05){
            glBegin(GL_POLYGON);
            glColor3d(0,0,0);
                glVertex3f(-0.7+i-0.002,-0.373, 0.0f);
                glVertex3f(-0.7+i+0.022,-0.373, 0.0f);
                glVertex3f(-0.7+i+0.022,-0.327, 0.0f);
                glVertex3f(-0.7+i-0.002,-0.327, 0.0f);
            glEnd();
        }
        for(float i=0.54;i<0.92;i+=0.05){
            glBegin(GL_POLYGON);
     glColor3d(getR(br),getG(bg),getB(bb));
                glVertex3f(-0.7+i,-0.37, 0.0f);
                glVertex3f(-0.7+i+0.02,-0.37, 0.0f);
                glVertex3f(-0.7+i+0.02,-0.33, 0.0f);
                glVertex3f(-0.7+i,-0.33, 0.0f);
            glEnd();
        }
    glPopMatrix();
    ///TrWndB3
    glPushMatrix();
        for(float i=0.96;i<1.34;i+=0.05){
            glBegin(GL_POLYGON);
            glColor3d(0,0,0);
                glVertex3f(-0.7+i-0.002,-0.373, 0.0f);
                glVertex3f(-0.7+i+0.022,-0.373, 0.0f);
                glVertex3f(-0.7+i+0.022,-0.327, 0.0f);
                glVertex3f(-0.7+i-0.002,-0.327, 0.0f);
            glEnd();
        }
        for(float i=0.96;i<1.34;i+=0.05){
            glBegin(GL_POLYGON);
     glColor3d(getR(br),getG(bg),getB(bb));
                glVertex3f(-0.7+i,-0.37, 0.0f);
                glVertex3f(-0.7+i+0.02,-0.37, 0.0f);
                glVertex3f(-0.7+i+0.02,-0.33, 0.0f);
                glVertex3f(-0.7+i,-0.33, 0.0f);
            glEnd();
        }
    glPopMatrix();
    ///TrB1whealf
    glPushMatrix();
           glColor3d(0,0,0);
           glTranslatef(-0.7+0.17,-0.41, 0.0f);
           glutSolidSphere(0.017, 50, 50);
    glPopMatrix();
    ///TrB1whealb
    glPushMatrix();
           glColor3d(0,0,0);
           glTranslatef(-0.7+0.43,-0.41, 0.0f);
           glutSolidSphere(0.017, 50, 50);
    glPopMatrix();
    ///TrB2whealf
    glPushMatrix();
           glColor3d(0,0,0);
           glTranslatef(-0.7+0.59,-0.41, 0.0f);
           glutSolidSphere(0.017, 50, 50);
    glPopMatrix();
    ///TrB2whealb
    glPushMatrix();
           glColor3d(0,0,0);
           glTranslatef(-0.7+0.85,-0.41, 0.0f);
           glutSolidSphere(0.017, 50, 50);
    glPopMatrix();
    ///TrB3whealf
    glPushMatrix();
           glColor3d(0,0,0);
           glTranslatef(-0.7+1.01,-0.41, 0.0f);
           glutSolidSphere(0.017, 50, 50);
    glPopMatrix();
    ///TrB3whealb
    glPushMatrix();
           glColor3d(0,0,0);
           glTranslatef(-0.7+1.27,-0.41, 0.0f);
           glutSolidSphere(0.017, 50, 50);
    glPopMatrix();
glPopMatrix();

///Car1_Begin Red

///CarT1Uplane
    glPushMatrix();
glTranslatef(_angle1, +0.35f, 0.0f);

    glPushMatrix();
    ///LBody///
   glBegin(GL_POLYGON);
    glColor3d(la,lb,lc);
        glVertex3f(-0.99f, -0.35f, 0.0f);
        glVertex3f(-0.99f, -0.36f, 0.0f);
        glVertex3f(-1.1f, -0.40f, 0.0f);
        glVertex3f(-1.1f, -0.33f, 0.0f);
	glEnd();
    ///LBody///
    glBegin(GL_POLYGON);
    glColor3d(1.0,0.0,0.0);
        glVertex3f(-1.00f, -0.40f, 0.0f);
        glVertex3f(-0.99f, -0.34f, 0.0f);
        glVertex3f(-0.71f, -0.34f, 0.0f);
        glVertex3f(-0.70f, -0.40f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	///UBody///
    glColor3d(1.0,0.0,0.0);
        glVertex3f(-0.92f, -0.34f, 0.0f);
        glVertex3f(-0.880f, -0.29f, 0.0f);
        glVertex3f(-0.820f, -0.29f, 0.0f);
        glVertex3f(-0.78f, -0.34f, 0.0f);
	glEnd();
	///BWin///
	glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(-0.915f, -0.34f, 0.0f);
        glVertex3f(-0.875f, -0.295f, 0.0f);
        glVertex3f(-0.852f, -0.295f, 0.0f);
        glVertex3f(-0.852f, -0.34f, 0.0f);
	glEnd();
	///MidLine///
	glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(-0.851f, -0.34f, 0.0f);
        glVertex3f(-0.851f, -0.295f, 0.0f);
        glVertex3f(-0.848f, -0.295f, 0.0f);
        glVertex3f(-0.848f, -0.34f, 0.0f);
	glEnd();
	///FWin///
	glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(-0.785f, -0.34f, 0.0f);
        glVertex3f(-0.825f, -0.295f, 0.0f);
        glVertex3f(-0.847f, -0.295f, 0.0f);
        glVertex3f(-0.847f, -0.34f, 0.0f);
	glEnd();
	glPopMatrix();
    ///BWheal///
    glPushMatrix();
	   glColor3d(0.0,0,0);
	   glTranslatef (-0.95, -0.40f, 0.0f);
	   glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    ///FWheal///
    glPushMatrix();
	   glColor3d(0.0,0,0);
	   glTranslatef (-0.75, -0.40f, 0.0f);
	   glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    glPopMatrix();

///car1_Finish

///Car2_Begin Blue
     glPushMatrix();
    glTranslatef(b, +0.20f, 0.0f);
    glPushMatrix();
    ///LBody///
    glBegin(GL_POLYGON);
    glColor3d(la,lb,lc);
        glVertex3f(-0.72f, -0.35f, 0.0f);
        glVertex3f(-0.72f, -0.36f, 0.0f);
        glVertex3f(-0.64f, -0.40f, 0.0f);
        glVertex3f(-0.64f, -0.33f, 0.0f);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3d(0.1,0.6,0.5);
        glVertex3f(-1.00f, -0.40f, 0.0f);
        glVertex3f(-0.99f, -0.34f, 0.0f);
        glVertex3f(-0.71f, -0.34f, 0.0f);
        glVertex3f(-0.70f, -0.40f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	///UBody///
    glColor3d(0.1,0.6,0.5);
        glVertex3f(-0.92f, -0.34f, 0.0f);
        glVertex3f(-0.880f, -0.29f, 0.0f);
        glVertex3f(-0.820f, -0.29f, 0.0f);
        glVertex3f(-0.78f, -0.34f, 0.0f);
	glEnd();
	///BWin///
	glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(-0.915f, -0.34f, 0.0f);
        glVertex3f(-0.875f, -0.295f, 0.0f);
        glVertex3f(-0.852f, -0.295f, 0.0f);
        glVertex3f(-0.852f, -0.34f, 0.0f);
	glEnd();
	///MidLine///
	glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(-0.851f, -0.34f, 0.0f);
        glVertex3f(-0.851f, -0.295f, 0.0f);
        glVertex3f(-0.848f, -0.295f, 0.0f);
        glVertex3f(-0.848f, -0.34f, 0.0f);
	glEnd();
	///FWin///
	glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(-0.785f, -0.34f, 0.0f);
        glVertex3f(-0.825f, -0.295f, 0.0f);
        glVertex3f(-0.847f, -0.295f, 0.0f);
        glVertex3f(-0.847f, -0.34f, 0.0f);
	glEnd();
	glPopMatrix();
    ///BWheal///
    glPushMatrix();
	   glColor3d(0.0,0,0);
	   glTranslatef (-0.95, -0.40f, 0.0f);
	   glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    ///FWheal///
    glPushMatrix();
	   glColor3d(0.0,0,0);
	   glTranslatef (-0.75, -0.40f, 0.0f);
	   glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    glPopMatrix();

///car2_Finish


    ///MiniBus_start
     glPushMatrix();
    glTranslatef(a, +0.21f, 0.0f);
    ///LBody///
    glBegin(GL_POLYGON);
    glColor3d(la,lb,lc);
        glVertex3f(0.59f, -0.35f, 0.0f);
        glVertex3f(0.59f, -0.36f, 0.0f);
        glVertex3f(0.7f, -0.40f, 0.0f);
        glVertex3f(0.7f, -0.34f, 0.0f);
	glEnd();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1.0,1.0,0.0);
        glVertex3f(+1.3-1.00f, -0.40f, 0.0f);
        glVertex3f(+1.3-1.00f, -0.34f, 0.0f);
        glVertex3f(+1.3-0.71f, -0.34f, 0.0f);
        glVertex3f(+1.3-0.70f, -0.40f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	///UBody///
    glColor3d(1.0,1.0,0.0);
        glVertex3f(+1.3-1.0f, -0.34f, 0.0f);
        glVertex3f(+1.3-1.0f, -0.29f, 0.0f);
        glVertex3f(+1.325-0.820f, -0.29f, 0.0f);
        glVertex3f(+1.325-0.78f, -0.34f, 0.0f);
	glEnd();

	///MidLine///
	glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(+1.325-0.851f, -0.34f, 0.0f);
        glVertex3f(+1.325-0.851f, -0.295f, 0.0f);
        glVertex3f(+1.325-0.848f, -0.295f, 0.0f);
        glVertex3f(+1.325-0.848f, -0.34f, 0.0f);
	glEnd();
	///FWin///
	glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(+1.325-0.785f, -0.34f, 0.0f);
        glVertex3f(+1.325-0.825f, -0.295f, 0.0f);
        glVertex3f(+1.325-0.847f, -0.295f, 0.0f);
        glVertex3f(+1.325-0.847f, -0.34f, 0.0f);
	glEnd();
	glPopMatrix();
    ///BWheal///
    glPushMatrix();
	   glColor3d(0.0,0,0);
	   glTranslatef (+1.3-0.95, -0.40f, 0.0f);
	   glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    ///FWheal///
    glPushMatrix();
	   glColor3d(0.0,0,0);
	   glTranslatef (+1.3-0.75, -0.40f, 0.0f);
	   glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    glPopMatrix();
///MiniBus_start
///MiniBus_start

///GrassField///
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0,0.8,0.1);
        glVertex3f(1.00f,  -0.48, 0.0f);
        glVertex3f(1.00f, -0.58, 0.0f);
        glVertex3f(-1.00f, -0.58f, 0.0f);
        glVertex3f(-1.00f, -0.48f, 0.0f);
	glEnd();
    glPopMatrix();

///Building Start//

    ///building1 Right Most Building
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.42, 0.0, 0.0);
        glVertex3f(getX(720), getY(36), 0.0f);
        glVertex3f(getX(720), getY(300), 0.0f);
        glVertex3f(getX(600), getY(300), 0.0f);
        glVertex3f(getX(600), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
    ///buildings1 right corner
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.25, 0.0, 0.0);
        glVertex3f(getX(740), getY(36), 0.0f);
        glVertex3f(getX(740), getY(250), 0.0f);
        glVertex3f(getX(720), getY(300), 0.0f);
        glVertex3f(getX(720), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
    ///b1 gate
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(getX(690), getY(36), 0.0f);
        glVertex3f(getX(690), getY(72), 0.0f);
        glVertex3f(getX(630), getY(72), 0.0f);
        glVertex3f(getX(630), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
     ///b1 windows
    glPushMatrix();
    glBegin(GL_POLYGON);
   glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(700), getY(100), 0.0f);
        glVertex3f(getX(700), getY(125), 0.0f);
        glVertex3f(getX(680), getY(125), 0.0f);
        glVertex3f(getX(680), getY(100), 0.0f);
	glEnd();
    glPopMatrix();
    //
     glPushMatrix();
    glBegin(GL_POLYGON);
  glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(620), getY(100), 0.0f);
        glVertex3f(getX(620), getY(125), 0.0f);
        glVertex3f(getX(640), getY(125), 0.0f);
        glVertex3f(getX(640), getY(100), 0.0f);
	glEnd();
    glPopMatrix();
        //
     glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));

        glVertex3f(getX(620), getY(155), 0.0f);
        glVertex3f(getX(620), getY(180), 0.0f);
        glVertex3f(getX(640), getY(180), 0.0f);
        glVertex3f(getX(640), getY(155), 0.0f);
	glEnd();
    glPopMatrix();
       //
     glPushMatrix();
    glBegin(GL_POLYGON);
glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(700), getY(155), 0.0f);
        glVertex3f(getX(700), getY(180), 0.0f);
        glVertex3f(getX(680), getY(180), 0.0f);
        glVertex3f(getX(680), getY(155), 0.0f);
	glEnd();
    glPopMatrix();
     //
     glPushMatrix();
    glBegin(GL_POLYGON);
glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(700), getY(205), 0.0f);
        glVertex3f(getX(700), getY(230), 0.0f);
        glVertex3f(getX(680), getY(230), 0.0f);
        glVertex3f(getX(680), getY(205), 0.0f);
	glEnd();
    glPopMatrix();
    //
     glPushMatrix();
    glBegin(GL_POLYGON);
   glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(620), getY(205), 0.0f);
        glVertex3f(getX(620), getY(230), 0.0f);
        glVertex3f(getX(640), getY(230), 0.0f);
        glVertex3f(getX(640), getY(205), 0.0f);
	glEnd();
    glPopMatrix();
    //
 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(620), getY(255), 0.0f);
        glVertex3f(getX(620), getY(280), 0.0f);
        glVertex3f(getX(640), getY(280), 0.0f);
        glVertex3f(getX(640), getY(255), 0.0f);
	glEnd();
    glPopMatrix();

  ///building1 Light window
 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1.000, 0.647, 0.000);
        glVertex3f(getX(700), getY(255), 0.0f);
        glVertex3f(getX(700), getY(280), 0.0f);
        glVertex3f(getX(680), getY(280), 0.0f);
        glVertex3f(getX(680), getY(255), 0.0f);
	glEnd();
    glPopMatrix();

        ///building 2
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.28, 0.0, 0.28);
        glVertex3f(getX(550), getY(36), 0.0f);
        glVertex3f(getX(550), getY(300), 0.0f);
        glVertex3f(getX(400), getY(300), 0.0f);
        glVertex3f(getX(400), getY(36), 0.0f);
	glEnd();
    glPopMatrix();

     ///buildings2 right corner
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.14, 0.0, 0.14);
        glVertex3f(getX(565), getY(36), 0.0f);
        glVertex3f(getX(565), getY(250), 0.0f);
        glVertex3f(getX(550), getY(300), 0.0f);
        glVertex3f(getX(550), getY(36), 0.0f);
	glEnd();
    glPopMatrix();

    ///b2 door
   glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(getX(540), getY(36), 0.0f);
        glVertex3f(getX(540), getY(72), 0.0f);
        glVertex3f(getX(500), getY(72), 0.0f);
        glVertex3f(getX(500), getY(36), 0.0f);
	glEnd();
    glPopMatrix();

    ///b2 windows
    glPushMatrix();
    glBegin(GL_POLYGON);
glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(520), getY(90), 0.0f);
        glVertex3f(getX(520), getY(115), 0.0f);
        glVertex3f(getX(500), getY(115), 0.0f);
        glVertex3f(getX(500), getY(90), 0.0f);
	glEnd();
    glPopMatrix();
    //
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(430), getY(90), 0.0f);
        glVertex3f(getX(430), getY(115), 0.0f);
        glVertex3f(getX(450), getY(115), 0.0f);
        glVertex3f(getX(450), getY(90), 0.0f);
	glEnd();
    glPopMatrix();
    //
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(430), getY(145), 0.0f);
        glVertex3f(getX(430), getY(170), 0.0f);
        glVertex3f(getX(450), getY(170), 0.0f);
        glVertex3f(getX(450), getY(145), 0.0f);
	glEnd();
    glPopMatrix();
     //
    glPushMatrix();
    glBegin(GL_POLYGON);
   glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(520), getY(145), 0.0f);
        glVertex3f(getX(520), getY(170), 0.0f);
        glVertex3f(getX(500), getY(170), 0.0f);
        glVertex3f(getX(500), getY(145), 0.0f);
	glEnd();
    glPopMatrix();

     ///building2 closed window
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(getX(520), getY(200), 0.0f);
        glVertex3f(getX(520), getY(225), 0.0f);
        glVertex3f(getX(500), getY(225), 0.0f);
        glVertex3f(getX(500), getY(200), 0.0f);
	glEnd();
    glPopMatrix();
      //
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(430), getY(200), 0.0f);
        glVertex3f(getX(430), getY(225), 0.0f);
        glVertex3f(getX(450), getY(225), 0.0f);
        glVertex3f(getX(450), getY(200), 0.0f);
	glEnd();
    glPopMatrix();
    //
    glPushMatrix();
    glBegin(GL_POLYGON);
  glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(430), getY(250), 0.0f);
        glVertex3f(getX(430), getY(275), 0.0f);
        glVertex3f(getX(450), getY(275), 0.0f);
        glVertex3f(getX(450), getY(250), 0.0f);
	glEnd();
    glPopMatrix();

   ///building2 closed window
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(getX(520), getY(250), 0.0f);
        glVertex3f(getX(520), getY(275), 0.0f);
        glVertex3f(getX(500), getY(275), 0.0f);
        glVertex3f(getX(500), getY(250), 0.0f);
	glEnd();
    glPopMatrix();

    ///buildings3 Left Most Building
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.78, 0.0, 0.0);
        glVertex3f(getX(-720), getY(36), 0.0f);
        glVertex3f(getX(-720), getY(300), 0.0f);
        glVertex3f(getX(-600), getY(300), 0.0f);
        glVertex3f(getX(-600), getY(36), 0.0f);
	glEnd();
    glPopMatrix();

   ///buildings3 right corner
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.47, 0.0, 0.0);
        glVertex3f(getX(-585), getY(36), 0.0f);
        glVertex3f(getX(-585), getY(250), 0.0f);
        glVertex3f(getX(-600), getY(300), 0.0f);
        glVertex3f(getX(-600), getY(36), 0.0f);
	glEnd();
    glPopMatrix();

    ///b3 gate
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(getX(-690), getY(36), 0.0f);
        glVertex3f(getX(-690), getY(72), 0.0f);
        glVertex3f(getX(-630), getY(72), 0.0f);
        glVertex3f(getX(-630), getY(36), 0.0f);
	glEnd();
    glPopMatrix();

     ///b3 windows
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-700), getY(100), 0.0f);
        glVertex3f(getX(-700), getY(125), 0.0f);
        glVertex3f(getX(-680), getY(125), 0.0f);
        glVertex3f(getX(-680), getY(100), 0.0f);
	glEnd();
    glPopMatrix();
    //
     glPushMatrix();
    glBegin(GL_POLYGON);
   glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-620), getY(100), 0.0f);
        glVertex3f(getX(-620), getY(125), 0.0f);
        glVertex3f(getX(-640), getY(125), 0.0f);
        glVertex3f(getX(-640), getY(100), 0.0f);
	glEnd();
    glPopMatrix();

    ///building3 Light window
     glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1.000, 0.647, 0.000);
        glVertex3f(getX(-620), getY(155), 0.0f);
        glVertex3f(getX(-620), getY(180), 0.0f);
        glVertex3f(getX(-640), getY(180), 0.0f);
        glVertex3f(getX(-640), getY(155), 0.0f);
	glEnd();
    glPopMatrix();
       //
     glPushMatrix();
    glBegin(GL_POLYGON);
   glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-700), getY(155), 0.0f);
        glVertex3f(getX(-700), getY(180), 0.0f);
        glVertex3f(getX(-680), getY(180), 0.0f);
        glVertex3f(getX(-680), getY(155), 0.0f);
	glEnd();
    glPopMatrix();
     //
     glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-700), getY(205), 0.0f);
        glVertex3f(getX(-700), getY(230), 0.0f);
        glVertex3f(getX(-680), getY(230), 0.0f);
        glVertex3f(getX(-680), getY(205), 0.0f);
	glEnd();
    glPopMatrix();
    //
     glPushMatrix();
    glBegin(GL_POLYGON);
   glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-620), getY(205), 0.0f);
        glVertex3f(getX(-620), getY(230), 0.0f);
        glVertex3f(getX(-640), getY(230), 0.0f);
        glVertex3f(getX(-640), getY(205), 0.0f);
	glEnd();
    glPopMatrix();

    ///building3 closed window
 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(getX(-620), getY(255), 0.0f);
        glVertex3f(getX(-620), getY(280), 0.0f);
        glVertex3f(getX(-640), getY(280), 0.0f);
        glVertex3f(getX(-640), getY(255), 0.0f);
	glEnd();
    glPopMatrix();

  //
 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-700), getY(255), 0.0f);
        glVertex3f(getX(-700), getY(280), 0.0f);
        glVertex3f(getX(-680), getY(280), 0.0f);
        glVertex3f(getX(-680), getY(255), 0.0f);
	glEnd();
    glPopMatrix();

        ///building 4
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.0, 0.37, 0.0);
        glVertex3f(getX(-550), getY(36), 0.0f);
        glVertex3f(getX(-550), getY(300), 0.0f);
        glVertex3f(getX(-400), getY(300), 0.0f);
        glVertex3f(getX(-400), getY(36), 0.0f);
	glEnd();
    glPopMatrix();

     ///building4 right corner
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.0, 0.15, 0.0);
        glVertex3f(getX(-385), getY(36), 0.0f);
        glVertex3f(getX(-385), getY(250), 0.0f);
        glVertex3f(getX(-400), getY(300), 0.0f);
        glVertex3f(getX(-400), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
    ///b4 door
   glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(getX(-540), getY(36), 0.0f);
        glVertex3f(getX(-540), getY(72), 0.0f);
        glVertex3f(getX(-500), getY(72), 0.0f);
        glVertex3f(getX(-500), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
    ///b4 windows
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-520), getY(90), 0.0f);
        glVertex3f(getX(-520), getY(115), 0.0f);
        glVertex3f(getX(-500), getY(115), 0.0f);
        glVertex3f(getX(-500), getY(90), 0.0f);
	glEnd();
    glPopMatrix();

    ///building4 closed window
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0,0,0);
        glVertex3f(getX(-430), getY(90), 0.0f);
        glVertex3f(getX(-430), getY(115), 0.0f);
        glVertex3f(getX(-450), getY(115), 0.0f);
        glVertex3f(getX(-450), getY(90), 0.0f);
	glEnd();
    glPopMatrix();
    ///
    glPushMatrix();
    glBegin(GL_POLYGON);
   glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-430), getY(145), 0.0f);
        glVertex3f(getX(-430), getY(170), 0.0f);
        glVertex3f(getX(-450), getY(170), 0.0f);
        glVertex3f(getX(-450), getY(145), 0.0f);
	glEnd();
    glPopMatrix();

     ///building4 light window
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1.000, 0.843, 0.000);
        glVertex3f(getX(-520), getY(145), 0.0f);
        glVertex3f(getX(-520), getY(170), 0.0f);
        glVertex3f(getX(-500), getY(170), 0.0f);
        glVertex3f(getX(-500), getY(145), 0.0f);
	glEnd();
    glPopMatrix();

     ///
    glPushMatrix();
    glBegin(GL_POLYGON);
   glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-520), getY(200), 0.0f);
        glVertex3f(getX(-520), getY(225), 0.0f);
        glVertex3f(getX(-500), getY(225), 0.0f);
        glVertex3f(getX(-500), getY(200), 0.0f);
	glEnd();
    glPopMatrix();
      ///
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-430), getY(200), 0.0f);
        glVertex3f(getX(-430), getY(225), 0.0f);
        glVertex3f(getX(-450), getY(225), 0.0f);
        glVertex3f(getX(-450), getY(200), 0.0f);
	glEnd();
    glPopMatrix();
    ///
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-430), getY(250), 0.0f);
        glVertex3f(getX(-430), getY(275), 0.0f);
        glVertex3f(getX(-450), getY(275), 0.0f);
        glVertex3f(getX(-450), getY(250), 0.0f);
	glEnd();
    glPopMatrix();
    ///
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(getR(br),getG(bg),getB(bb));
        glVertex3f(getX(-520), getY(250), 0.0f);
        glVertex3f(getX(-520), getY(275), 0.0f);
        glVertex3f(getX(-500), getY(275), 0.0f);
        glVertex3f(getX(-500), getY(250), 0.0f);
	glEnd();
    glPopMatrix();



///Playground
glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(getR(1),getG(166),getB(17));
        glVertex3f(getX(15), getY(36), 0.0f);
        glVertex3f(getX(50), getY(240), 0.0f);
        glVertex3f(getX(250), getY(240), 0.0f);
        glVertex3f(getX(285), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
///field Mid line
glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(1,1,1);
        glVertex3f(getX(35), getY(150), 0.0f);
        glVertex3f(getX(35), getY(153), 0.0f);
        glVertex3f(getX(265), getY(153), 0.0f);
        glVertex3f(getX(265), getY(150), 0.0f);
	glEnd();
    glPopMatrix();
///
   ///field Circle
 glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(0.2, 0.37, 0.0);
	glBegin(GL_LINES);
	for(int i=0;i<50;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.07;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
///bar1
glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(1,1,1);
        glVertex3f(getX(115), getY(36), 0.0f);
        glVertex3f(getX(115), getY(65), 0.0f);
        glVertex3f(getX(118), getY(65), 0.0f);
        glVertex3f(getX(118), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
//
glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(1,1,1);
        glVertex3f(getX(115+70), getY(36), 0.0f);
        glVertex3f(getX(115+70), getY(65), 0.0f);
        glVertex3f(getX(118+70), getY(65), 0.0f);
        glVertex3f(getX(118+70), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
///
glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(1,1,1);
        glVertex3f(getX(115), getY(65), 0.0f);
        glVertex3f(getX(115), getY(68), 0.0f);
        glVertex3f(getX(118+70), getY(68), 0.0f);
        glVertex3f(getX(118+70), getY(65), 0.0f);
	glEnd();
    glPopMatrix();
///bar 2
glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(1,1,1);
        glVertex3f(getX(115), getY(240), 0.0f);
        glVertex3f(getX(115), getY(255), 0.0f);
        glVertex3f(getX(118), getY(255), 0.0f);
        glVertex3f(getX(118), getY(240), 0.0f);
	glEnd();
    glPopMatrix();
//
glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(1,1,1);
        glVertex3f(getX(115+70), getY(240), 0.0f);
        glVertex3f(getX(115+70), getY(255), 0.0f);
        glVertex3f(getX(118+70), getY(255), 0.0f);
        glVertex3f(getX(118+70), getY(240), 0.0f);
	glEnd();
    glPopMatrix();
//
glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(1,1,1);
        glVertex3f(getX(115), getY(255), 0.0f);
        glVertex3f(getX(115), getY(258), 0.0f);
        glVertex3f(getX(118+70), getY(258), 0.0f);
        glVertex3f(getX(118+70), getY(255), 0.0f);
	glEnd();
    glPopMatrix();
///Trees start




   ///tree3
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(.3843,.305,.1725);

        glVertex3f(getX(-25-340), getY(-100), 0.0f);
        glVertex3f(getX(-35-340), getY(-100), 0.0f);
        glVertex3f(getX(-26-340), getY(-155), 0.0f);
        glVertex3f(getX(-26-340), getY(-165), 0.0f);
        glVertex3f(getX(-35-340), getY(-200), 0.0f);
        glVertex3f(getX(-27-340), getY(-196), 0.0f);
        glVertex3f(getX(-25-340), getY(-200), 0.0f);
        glVertex3f(getX(-23-340), getY(-196), 0.0f);
        glVertex3f(getX(-5-340), getY(-200), 0.0f);
        glVertex3f(getX(-14-340), getY(-165), 0.0f);
        glVertex3f(getX(-14-340), getY(-155), 0.0f);

        glVertex3f(getX(-5-340), getY(-100), 0.0f);
        glVertex3f(getX(-10-340), getY(-100), 0.0f);
        glVertex3f(getX(-15-340), getY(-150), 0.0f);
        glVertex3f(getX(-25-340), getY(-100), 0.0f);
	glEnd();
    glPopMatrix();
    ///tree up

       glPushMatrix();
         glTranslatef(-.45,-0.25,0.0);
      glColor3f(0,0.8,0.1);
             glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

            glPushMatrix();
         glTranslatef(-0.48,-0.195,0.0);
      glColor3f(0,0.8,0.1);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

            glPushMatrix();
         glTranslatef(-.51,-0.25,0.0);
         glColor3f(0,0.8,0.1);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

  ///tree4
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(.3843,.305,.1725);

        glVertex3f(getX(-25-530), getY(-100), 0.0f);
        glVertex3f(getX(-35-530), getY(-100), 0.0f);
        glVertex3f(getX(-26-530), getY(-155), 0.0f);
        glVertex3f(getX(-26-530), getY(-165), 0.0f);
        glVertex3f(getX(-35-530), getY(-200), 0.0f);
        glVertex3f(getX(-27-530), getY(-196), 0.0f);
        glVertex3f(getX(-25-530), getY(-200), 0.0f);
        glVertex3f(getX(-23-530), getY(-196), 0.0f);
        glVertex3f(getX(-5-530), getY(-200), 0.0f);
        glVertex3f(getX(-14-530), getY(-165), 0.0f);
        glVertex3f(getX(-14-530), getY(-155), 0.0f);

        glVertex3f(getX(-5-530), getY(-100), 0.0f);
        glVertex3f(getX(-10-530), getY(-100), 0.0f);
        glVertex3f(getX(-15-530), getY(-150), 0.0f);
        glVertex3f(getX(-25-530), getY(-100), 0.0f);
	glEnd();
    glPopMatrix();
    ///tree up

       glPushMatrix();
         glTranslatef(-.7,-0.25,0.0);
      glColor3f(0,0.8,0.1);
             glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

            glPushMatrix();
         glTranslatef(-0.73,-0.195,0.0);
      glColor3f(0,0.8,0.1);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

            glPushMatrix();
         glTranslatef(-.75,-0.25,0.0);
         glColor3f(0,0.8,0.1);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();
/////////////////////////////////////////////////




   ///tree32
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(.3843,.305,.1725);
       glVertex3f(getX(-25+375), getY(-100), 0.0f);
        glVertex3f(getX(-35+375), getY(-100), 0.0f);
        glVertex3f(getX(-26+375), getY(-155), 0.0f);
        glVertex3f(getX(-26+375), getY(-165), 0.0f);
        glVertex3f(getX(-35+375), getY(-200), 0.0f);
        glVertex3f(getX(-27+375), getY(-196), 0.0f);
        glVertex3f(getX(-25+375), getY(-200), 0.0f);
        glVertex3f(getX(-23+375), getY(-196), 0.0f);
        glVertex3f(getX(-5+375), getY(-200), 0.0f);
        glVertex3f(getX(-14+375), getY(-165), 0.0f);
        glVertex3f(getX(-14+375), getY(-155), 0.0f);

        glVertex3f(getX(-5+375), getY(-100), 0.0f);
        glVertex3f(getX(-10+375), getY(-100), 0.0f);
        glVertex3f(getX(-15+375), getY(-150), 0.0f);
        glVertex3f(getX(-25+375), getY(-100), 0.0f);
	glEnd();
    glPopMatrix();
    ///tree up

       glPushMatrix();
         glTranslatef(.45,-0.25,0.0);
      glColor3f(0,0.8,0.1);
             glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

            glPushMatrix();
         glTranslatef(0.48,-0.195,0.0);
      glColor3f(0,0.8,0.1);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

            glPushMatrix();
         glTranslatef(.51,-0.25,0.0);
         glColor3f(0,0.8,0.1);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

  ///tree42
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(.3843,.305,.1725);
         glVertex3f(getX(-25+565), getY(-100), 0.0f);
        glVertex3f(getX(-35+565), getY(-100), 0.0f);
        glVertex3f(getX(-26+565), getY(-155), 0.0f);
        glVertex3f(getX(-26+565), getY(-165), 0.0f);
        glVertex3f(getX(-35+565), getY(-200), 0.0f);
        glVertex3f(getX(-27+565), getY(-196), 0.0f);
        glVertex3f(getX(-25+565), getY(-200), 0.0f);
        glVertex3f(getX(-23+565), getY(-196), 0.0f);
        glVertex3f(getX(-5+565), getY(-200), 0.0f);
        glVertex3f(getX(-14+565), getY(-165), 0.0f);
        glVertex3f(getX(-14+565), getY(-155), 0.0f);

        glVertex3f(getX(-5+565), getY(-100), 0.0f);
        glVertex3f(getX(-10+565), getY(-100), 0.0f);
        glVertex3f(getX(-15+565), getY(-150), 0.0f);
        glVertex3f(getX(-25+565), getY(-100), 0.0f);
	glEnd();
    glPopMatrix();
    ///tree up

       glPushMatrix();
         glTranslatef(.7,-0.25,0.0);
      glColor3f(0,0.8,0.1);
             glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

            glPushMatrix();
         glTranslatef(0.73,-0.195,0.0);
      glColor3f(0,0.8,0.1);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

            glPushMatrix();
         glTranslatef(.75,-0.25,0.0);
         glColor3f(0,0.8,0.1);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.04;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();
  ///tree finish

///mosq Mosque start
 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.0, 0.0, 0.32);
        glVertex3f(getX(-350), getY(36), 0.0f);
        glVertex3f(getX(-350), getY(150), 0.0f);
        glVertex3f(getX(-100), getY(150), 0.0f);
        glVertex3f(getX(-100), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
///mosque right corner
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0.0, 0.0, 0.15);
        glVertex3f(getX(-100), getY(36), 0.0f);
        glVertex3f(getX(-100), getY(150), 0.0f);
        glVertex3f(getX(-80), getY(120), 0.0f);
        glVertex3f(getX(-80), getY(36), 0.0f);
	glEnd();
    glPopMatrix();
///mosque left door
 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(getX(-320-10), getY(38), 0.0f);
        glVertex3f(getX(-320-10), getY(85), 0.0f);
        glVertex3f(getX(-280-10), getY(85), 0.0f);
        glVertex3f(getX(-280-10), getY(38), 0.0f);
	glEnd();
    glPopMatrix();

    ///mosque middle door
 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(getX(-320+70), getY(38), 0.0f);
        glVertex3f(getX(-320+70), getY(85), 0.0f);
        glVertex3f(getX(-280+70), getY(85), 0.0f);
        glVertex3f(getX(-280+70), getY(38), 0.0f);
	glEnd();
    glPopMatrix();


    ///mosque right door
 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(getX(-320+150), getY(38), 0.0f);
        glVertex3f(getX(-320+150), getY(85), 0.0f);
        glVertex3f(getX(-280+150), getY(85), 0.0f);
        glVertex3f(getX(-280+150), getY(38), 0.0f);
	glEnd();
    glPopMatrix();

///line  of middle door
glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(getR(205),getG(133),getB(63));
        glVertex3f(getX(-228), getY(38), 0.0f);
        glVertex3f(getX(-228), getY(85), 0.0f);
        glVertex3f(getX(-232), getY(85), 0.0f);
        glVertex3f(getX(-232), getY(38), 0.0f);
	glEnd();
    glPopMatrix();

///mos line bottom to up
 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(getX(-350), getY(105), 0.0f);
        glVertex3f(getX(-350), getY(108), 0.0f);
        glVertex3f(getX(-100), getY(108), 0.0f);
        glVertex3f(getX(-100), getY(105), 0.0f);
	glEnd();
	glPopMatrix();

	///mos line 2
	glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(getX(-350), getY(105+10), 0.0f);
        glVertex3f(getX(-350), getY(109+10), 0.0f);
        glVertex3f(getX(-100), getY(109+10), 0.0f);
        glVertex3f(getX(-100), getY(105+10), 0.0f);
	glEnd();
    glPopMatrix();

    ///mos line 3
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex3f(getX(-350), getY(105+10+10), 0.0f);
        glVertex3f(getX(-350), getY(108+10+10), 0.0f);
        glVertex3f(getX(-100), getY(108+10+10), 0.0f);
        glVertex3f(getX(-100), getY(105+10+10), 0.0f);
	glEnd();
    glPopMatrix();
///big dome middle step1
glPushMatrix();
         glTranslatef(-.305,0.37,0.0);
    glColor3d(0.0, 0.0, 0.32);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.03;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();

///big dome step2
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0, 0, 0.50);
        glVertex3f(getX(-245), getY(155), 0.0f);
        glVertex3f(getX(-245), getY(180), 0.0f);
        glVertex3f(getX(-215), getY(180), 0.0f);
        glVertex3f(getX(-215), getY(155), 0.0f);
	glEnd();
    glPopMatrix();
///big dome step3
glPushMatrix();
         glTranslatef(-.305,0.45,0.0);
    glColor3d(0, 0, 0.50);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.025;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();
///big dome step4
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0, 0, 0.50);
        glVertex3f(getX(-243), getY(185), 0.0f);
        glVertex3f(getX(-243), getY(215), 0.0f);
        glVertex3f(getX(-218), getY(215), 0.0f);
        glVertex3f(getX(-218), getY(185), 0.0f);
	glEnd();
    glPopMatrix();
///big dome step5
glPushMatrix();
         glTranslatef(-.305,0.53,0.0);
    glColor3d(0, 0, 0.50);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.023;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();
///big dome step6
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0, 0, 0.50);
        glVertex3f(getX(-240), getY(215), 0.0f);
        glVertex3f(getX(-240), getY(245), 0.0f);
        glVertex3f(getX(-220), getY(245), 0.0f);
        glVertex3f(getX(-220), getY(215), 0.0f);
	glEnd();
    glPopMatrix();

glPushMatrix();
         glTranslatef(-.3065,0.62,0.0);
    glColor3d(0, 0, 0.50);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.0205;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();
///big dome step7
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0, 0, 0.50);
        glVertex3f(getX(-238), getY(245), 0.0f);
        glVertex3f(getX(-238), getY(275), 0.0f);
        glVertex3f(getX(-223), getY(275), 0.0f);
        glVertex3f(getX(-223), getY(245), 0.0f);
	glEnd();
    glPopMatrix();
      ///big dome step8
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3d(0, 0, 0.50);
        glVertex3f(getX(-235), getY(275), 0.0f);
        glVertex3f(getX(-235), getY(285), 0.0f);
        glVertex3f(getX(-228), getY(285), 0.0f);
        glVertex3f(getX(-228), getY(275), 0.0f);
	glEnd();
    glPopMatrix();

///Mosque finish


    ///grass1
     glPushMatrix();
    glBegin(GL_POLYGON);
	glColor3f(0,0.8,0.1);
        glVertex3f(getX(-740+20),getY(-200),0.0f);
        glVertex3f(getX(-750+20),getY(-170+10),0.0f);
        glVertex3f(getX(-736+20),getY(-185+10),0.0f);
        glVertex3f(getX(-725+20),getY(-150+10),0.0f);
        glVertex3f(getX(-710+20),getY(-185+10),0.0f);
        glVertex3f(getX(-695+20),getY(-175+10),0.0f);
        glVertex3f(getX(-710+20),getY(-200),0.0f);
        //glVertex3f(getX(-725),getY(-100),0.0f);
        //glVertex3f(getX(-712.5),getY(-200),0.0f);



	glEnd();
    glPopMatrix();


           ///grass2///
        glPushMatrix();
        glBegin(GL_POLYGON); //Mushroom
        glColor3f(0,0.8,0.1);
        glVertex3f(getX(-740+70),getY(-200),0.0f);
        glVertex3f(getX(-750+70),getY(-170+10),0.0f);
        glVertex3f(getX(-736+70),getY(-185+10),0.0f);
        glVertex3f(getX(-725+70),getY(-150+10),0.0f);
        glVertex3f(getX(-710+70),getY(-185+10),0.0f);
        glVertex3f(getX(-695+70),getY(-175+10),0.0f);
        glVertex3f(getX(-710+70),getY(-200),0.0f);
        //glVertex3f(getX(-725),getY(-100),0.0f);
       // glVertex3f(getX(-712.5),getY(-200),0.0f);



	glEnd();
    glPopMatrix();


    ///grass3///
glPushMatrix();
    glBegin(GL_POLYGON); //Mushroom
	glColor3f(0,0.8,0.1);
        glVertex3f(getX(740-20-50),getY(-200),0.0f);
        glVertex3f(getX(750-20-50),getY(-170+10),0.0f);
        glVertex3f(getX(736-20-50),getY(-185+10),0.0f);
        glVertex3f(getX(725-20-50),getY(-150+10),0.0f);
        glVertex3f(getX(710-20-50),getY(-185+10),0.0f);
        glVertex3f(getX(695-20-50),getY(-175+10),0.0f);
        glVertex3f(getX(710-20-50),getY(-200),0.0f);
        //glVertex3f(getX(-725),getY(-100),0.0f);
       // glVertex3f(getX(-712.5),getY(-200),0.0f);



	glEnd();
    glPopMatrix();




    ///grass4///
glPushMatrix();
    glBegin(GL_POLYGON); //Mushroom
	glColor3f(0,0.8,0.1);
        glVertex3f(getX(740-20),getY(-200),0.0f);
        glVertex3f(getX(750-20),getY(-170+10),0.0f);
        glVertex3f(getX(736-20),getY(-185+10),0.0f);
        glVertex3f(getX(725-20),getY(-150+10),0.0f);
        glVertex3f(getX(710-20),getY(-185+10),0.0f);
        glVertex3f(getX(695-20),getY(-175+10),0.0f);
        glVertex3f(getX(710-20),getY(-200),0.0f);
        //glVertex3f(getX(-725),getY(-100),0.0f);
       // glVertex3f(getX(-712.5),getY(-200),0.0f);



	glEnd();
    glPopMatrix();


    ///Lake///
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.4,.4,1.1);
        glVertex3f(1.00f,  -0.51, 0.0f);
        glVertex3f(1.00f, -1.0f, 0.0f);
        glVertex3f(-1.00f, -1.00f, 0.0f);
        glVertex3f(-1.00f, -0.51f, 0.0f);
	glEnd();
    glPopMatrix();
    ///Fish1_start///
        ///Fish1_start Yellow///
   ///

	glPushMatrix();
glTranslatef(_movefb, -0.00f, 0.0f);
    glColor3f(1.0,1.0,0.0);//yellow fish
    glBegin(GL_TRIANGLES);
    glVertex3f(0.75f, -0.66f, 0.0);

     glVertex3f(0.75f, -0.583f, 0.0);
     glVertex3f(0.85f, -0.63f, 0.0);

    glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(_movefb, -0.00f, 0.0f);
    glColor3f(1.0,1.0,0.0);//yellow fish
    glBegin(GL_TRIANGLES);
    glVertex3f(0.75f, -0.66f, 0.0);

     glVertex3f(0.75f, -0.583f, 0.0);
     glVertex3f(0.70f, -0.63f, 0.0);

    glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(_movefb, -0.00f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.83f, -0.63f, 0.0);
    glColor3f(-1.8,0.5,0.0);
    glVertex3f(0.9f,-0.66f,0.0);
    glVertex3f(0.9f,-0.583f,0.0);
    glEnd();
 glPopMatrix();

    glPushMatrix();
    glTranslatef(_movefb, -0.00f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(0.76f,-0.65f,0.0);
    glVertex3f(0.79f,-0.64f,0.0);
    glVertex3f(0.80f,-0.68f,0.0);
    glEnd();
     glPopMatrix();


    glPushMatrix();
    glTranslatef(_movefb, -0.00f, 0.0f);
    glBegin(GL_TRIANGLES);
	glVertex3f(0.76f,-0.59f,0.0);
    glVertex3f(0.79f,-0.61f,0.0);
    glVertex3f(0.80f,-0.55f,0.0);
    glEnd();
     glPopMatrix();

      glPushMatrix();
     glTranslatef(_movefb, -0.00f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex3f(0.73f, -0.62f, 0.0);
    glEnd();
    glPopMatrix();
	///

	  ///Fish1_finish Yellow///


///Fish2_Start Yellow and Red///

 glPushMatrix();
glTranslatef(_movef, -0.00f, 0.0f);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.77, -0.85);
    glVertex2f(-0.75, -0.89);
    glVertex2f(-0.77, -0.91);
    glEnd();
    glPopMatrix();
    glPushMatrix();
glTranslatef(_movef, -0.00f, 0.0f);

    //fishTail
    glColor3f(1.0, 1.0, 0.0); //yellow fish
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.93);
    glVertex2f(-0.75, -0.89);
    glVertex2f(-0.85,-0.93);
    glVertex2f(-0.75, -0.96);
    glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(_movef, -0.00f, 0.0f);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.83, -0.93);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-0.90, -0.97);
    glVertex2f(-0.87, -0.93);
    glVertex2f(-0.90, -0.89);
    glEnd();
    glPopMatrix();



glPushMatrix();
glTranslatef(_movef, -0.00f, 0.0f);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.75, -0.96);
    glVertex2f(-0.77, -0.955);
    glVertex2f(-0.763, -0.999);
    glEnd();
    glPopMatrix();

glPushMatrix();
glTranslatef(_movef, -0.00f, 0.0f);

    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(-0.73, -0.93);
    glEnd();
    glPopMatrix();


///Fish2_finish Yellow and Red///

///traffic light
	  glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(1,1,1);
        glVertex3f(getX(-15+700), getY(36-72), 0.0f);
        glVertex3f(getX(-25+700), getY(36-72), 0.0f);
        glVertex3f(getX(-25+700), getY(116-72), 0.0f);
        glVertex3f(getX(-15+700), getY(116-72), 0.0f);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3d(0,0,0);

        glVertex3f(getX(-35+700), getY(116-72), 0.0f);
        glVertex3f(getX(-05+700), getY(116-72), 0.0f);
        glVertex3f(getX(-05+700), getY(176-72), 0.0f);
        glVertex3f(getX(-35+700), getY(176-72), 0.0f);
	glEnd();
    glPopMatrix();

glPushMatrix();

	   glColor3d(p,0.0,0.0);
	   glTranslatef (-0.025f+0.93f, 0.41f-.18f, 0.0f);
	   glutSolidSphere(0.015, 50, 50);

	glPopMatrix();
	glPushMatrix();

	   glColor3d(q,q,0.0);
	   glTranslatef (-0.025f+0.93f, 0.36f-.17f, 0.0f);
	   glutSolidSphere(0.015, 50, 50);

	glPopMatrix();
	glPushMatrix();

	   glColor3d(0.0,r,0.0);
	   glTranslatef (-0.025f+0.93f, 0.31f-.17f, 0.0f);
	   glutSolidSphere(0.015, 50, 50);

	glPopMatrix();



    ///Boat///
     ///Boat///
    glPushMatrix();
     glTranslatef(_move3, 0.0f, 0.0f);
     glBegin(GL_POLYGON);
     glColor3f(0.78,0.08,0.52);
     glVertex3f(-0.833f, -0.96f, 0.0);
     glVertex3f(-0.33f, -0.96f, 0.0);
     glVertex3f(-0.25f, -0.783f, 0.0);
     glVertex3f(-0.916f, -0.783f, 0.0);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(1.0,1.0,0.3);
     glVertex3f(-0.833f, -0.783f, 0.0);
     glVertex3f(-0.33f, -0.783f, 0.0);
     glVertex3f(-0.33f, -0.75f, 0.0);
     glVertex3f(-0.833f, -0.75f, 0.0);
     glEnd();


     glBegin(GL_POLYGON);
     glColor3f(1.0,0.0,0.3);
     glVertex3f(-0.8f, -0.75f, 0.0);
     glVertex3f(-0.36f, -0.75f, 0.0);
     glVertex3f(-0.36f, -0.72f, 0.0);
     glVertex3f(-0.8f, -0.72f, 0.0);
     glEnd();
      glBegin(GL_POLYGON);
     glColor3f(1.0,0.0,1.3);
     glVertex3f(-0.77f, -0.72f, 0.0);
     glVertex3f(-0.39f, -0.72f, 0.0);

     glVertex3f(-0.39f, -0.69f, 0.0);
     glVertex3f(-0.77f, -0.69f, 0.0);
     glEnd();

        //pipe1//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.64f,-0.6f,0.0f);
     glVertex3f(-0.62f,-0.6f,0.0f);
     glVertex3f(-0.62f,-0.7f,0.0f);
     glVertex3f(-0.64f,-0.7f,0.0f);
     glEnd();
     //pipe2//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.55f,-0.6f,0.0f);
     glVertex3f(-0.53f,-0.6f,0.0f);
     glVertex3f(-0.53f,-0.7f,0.0f);
     glVertex3f(-0.55f,-0.7f,0.0f);
     glEnd();
     //centrepipe//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.60f,-0.566f,0.0f);
     glVertex3f(-0.57f,-0.566f,0.0f);
     glVertex3f(-0.57f,-0.7f,0.0f);
     glVertex3f(-0.60f,-0.7f,0.0f);
     glEnd();
     //smoke11//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.65f,-0.58f,0.0f);
     glVertex3f(-0.64f,-0.58f,0.0f);
     glVertex3f(-0.64f,-0.59f,0.0f);
     glVertex3f(-0.65f,-0.59f,0.0f);
     glEnd();
      //smoke12//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.66f,-0.56f,0.0f);
     glVertex3f(-0.65f,-0.56f,0.0f);
     glVertex3f(-0.65f,-0.57f,0.0f);
     glVertex3f(-0.66f,-0.57f,0.0f);
     glEnd();
      //smoke13//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.67f,-0.54f,0.0f);
     glVertex3f(-0.66f,-0.54f,0.0f);
     glVertex3f(-0.66f,-0.55f,0.0f);
     glVertex3f(-0.67f,-0.55f,0.0f);
     glEnd();
      //smoke14//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.68f,-0.52f,0.0f);
     glVertex3f(-0.67f,-0.52f,0.0f);
     glVertex3f(-0.67f,-0.53f,0.0f);
     glVertex3f(-0.68f,-0.53f,0.0f);
     glEnd();
  //smoke21//

      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.61f,-0.55f,0.0f);
     glVertex3f(-0.60f,-0.55f,0.0f);
     glVertex3f(-0.60f,-0.56f,0.0f);
     glVertex3f(-0.61f,-0.56f,0.0f);
     glEnd();
       //smoke22//
          glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.62f,-0.53f,0.0f);
     glVertex3f(-0.61f,-0.53f,0.0f);
     glVertex3f(-0.61f,-0.54f,0.0f);
     glVertex3f(-0.62f,-0.54f,0.0f);
     glEnd();
        //smoke23//
          glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.63f,-0.51f,0.0f);
     glVertex3f(-0.62f,-0.51f,0.0f);
     glVertex3f(-0.62f,-0.52f,0.0f);
     glVertex3f(-0.63f,-0.52f,0.0f);
     glEnd();
      //smoke31//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.55f,-0.58f,0.0f);
     glVertex3f(-0.54f,-0.58f,0.0f);
     glVertex3f(-0.54f,-0.59f,0.0f);
     glVertex3f(-0.55f,-0.59f,0.0f);
     glEnd();
      //smoke32//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.56f,-0.56f,0.0f);
     glVertex3f(-0.55f,-0.56f,0.0f);
     glVertex3f(-0.55f,-0.57f,0.0f);
     glVertex3f(-0.56f,-0.57f,0.0f);
     glEnd();
      //smoke32//
      glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.57f,-0.54f,0.0f);
     glVertex3f(-0.56f,-0.54f,0.0f);
     glVertex3f(-0.56f,-0.55f,0.0f);
     glVertex3f(-0.57f,-0.55f,0.0f);
     glEnd();
     //smoke33//
       glBegin(GL_POLYGON);
     glColor3f(0.0,0.0 , 0.0);
     glVertex3f(-0.58f,-0.52f,0.0f);
     glVertex3f(-0.57f,-0.52f,0.0f);
     glVertex3f(-0.57f,-0.53f,0.0f);
     glVertex3f(-0.58f,-0.53f,0.0f);
     glEnd();


       glPopMatrix();


	glutSwapBuffers();
}

void update(int value) {

    _movec+= 0.00;
    if(_movec-1.1 > 1.0)
    {
        _movec = -1.5;

    }


    _movef += .003;///yellow and red fish
    if(_movef-1.3  > 1.0)
    {
        _movef = -1.0;
    }


    _movefb -= .003;  ///yellow fish
    if(_movefb+1.3 < -1.0)
    {
        _movefb = 1.0;

    }

    _move3 += .005;
    if(_move3-1.663  > 1.0)
    {
        _move3 = -1.0;
    }

     _move6 += .0005;///cloud1
    if(_move6-0.39 > 1.0)
    {
        _move6 = -1.4;
    }

     _move7 += .0006;///cloud2
    if(_move7-0.79 > 1.0)
    {
        _move7 = -1.4;
    }


	glutPostRedisplay(); ///Notify GLUT that the display has changed

	glutTimerFunc(20, update, 0); ///Notify GLUT to call update again in 20 milliseconds
}
///
void update1(int value) {

if(tr2==1&&tg2==0&&tb==0)
          {

              if(_angle1<=.8970010&&_angle1>=.8459900){
                    }
                    else{
                        if(speed>1 || speed<0)
    {

        speed = 0.0f;
    }
	_angle1 -= speed;

	if (_angle1 < -0.31) {
		_angle1 += 2.31;
	}
                    }
          }
else{
 if(speed>1 || speed<0)
    {

        speed = 0.0f;
    }
	_angle1 -= speed;

	if (_angle1 < -0.31) {
		_angle1 += 2.31;
	}
}
	if(speedt>1 || speedt<0)
    {

        speedt = 0.0f;
    }
	_moveft -= speedt;

	if (_moveft < -1.86) {
		_moveft += 3.86;
	}

	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update1, 0); //Notify GLUT to call update again in 20 milliseconds
}

void keyboard(unsigned char key, int x, int y) {

    switch(key){
        case 27:
            exit(0);   ///ESC
            break;
        case 'H':
        case 'h':
             paused = !paused;
              // Toggle state
      if (paused) {
         savedSpeed = speedt;  // Save parameters for restore later
         speedt = 0;            // Stop movement

        sndPlaySound(NULL,SND_ASYNC|SND_LOOP);
      } else {
         speedt = savedSpeed;  // Restore parameters

         sndPlaySound("airHorn.wav",SND_ASYNC|SND_LOOP);
      }
      break;

    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	traffic_regulator=0;
	p=1;
	q=0;
	r=0;
	}

	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
	traffic_regulator=0;
	p=0;
	q=1;
	r=0;
	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
	{
	traffic_regulator=1;
	p=0;
	q=0;
	r=1;
	}
	glutPostRedisplay();


}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:/// Blue car
          speed+=0.001f;
          sndPlaySound("CARBY2.wav",SND_ASYNC);
         //update1(0);
          break;
        case GLUT_KEY_DOWN:
          speed-=0.001f;
          //update1(0);
          break;
        case GLUT_KEY_LEFT:///train
          speedt+=0.001f;
          //sndPlaySound("train.wav",SND_ASYNC);

         //update1(0);
          break;
        case GLUT_KEY_RIGHT:
          speedt-=0.001f;

          //update1(0);
          break;
        case GLUT_KEY_PAGE_UP:///Day and night check
            if(dcheck==0){
                dcheck=1;
                sr=0.0;///sky
                sg=0.0;
                sb=0.05;
                str=1;///star
                stg=1;
                stb=1;
                mr=0.0;//moon
                mg=0.0;
                mb=0.05;
                mr1=0.90;//moon
                mg1=0.90;
                mb1=0.90;
                br=244;///building window
                bg= 170;
                bb=22;
                la=1.0;///car light red
                 lb=1.0;
                 lc=1.0;
                cr=.70;///cloud red
                cg=.70;
                cb=.70;
                ra=0.2;///road red
                 rb=0.2;
                 rc=0.2;

            }else{
                dcheck=0;
                sr=0.52;
                sg=0.80;
                sb=0.98;
                cr=1.0;///cloud red
                cg=1.0;
                cb=1.0;
                str=0.52;
                stg=0.80;
                stb=0.98;
                mr=1.0;
                mg=1.00;
                mb=0.0;
                mr1=0.52;
                mg1=0.80;
                mb1=0.98;
                br= 130;
                bg= 150;
                bb= 137;
                 la=0.4;///car light red
                 lb=0.4;
                 lc=0.4;
                 ra=0.4;///road red
                 rb=0.4;
                 rc=0.4;

            }

          break;


    }
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1500,1000);
	glutCreateWindow("Modern City");
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
	glutDisplayFunc(drawScene);
	glutTimerFunc(20, update, 0);
	glutTimerFunc(20, update1, 0);
	glutMainLoop();
	return 0;
}



