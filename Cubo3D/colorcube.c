#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>

GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0} };

GLfloat normals[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0} };

GLfloat colors[][3] = { {0.0,0.0,0.0},{1.0,0.0,0.0},
{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0} };


// Variáveis Globais



#define TIME 40
#define NCubos 2


//pode ter a velocidade e o angulo para saber para onde quer ir ( seno e cosseno)
struct cubo {
	float theta[3];
	float escala;
	float xCubo;
	float yCubo;
	float velocityX;
	float velocityY;

};


//variaveis globais
struct cubo cubos[NCubos];
int selectedCubo = 0;
float velocity = 0.5; //velocidade em unidades do mundo por segundo

float internalPosition = 0.0;
float internalVelocity = 2.5;


void init() {
	cubos[0].theta[0] = 0.0;
	cubos[0].theta[1] = 0.0;
	cubos[0].theta[2] = 0.0;
	cubos[0].escala = 1.0;
	cubos[0].xCubo = -1.5;
	cubos[0].yCubo = 0.0;
	cubos[0].velocityX = 0.5;
	cubos[0].velocityY = 0.5;

	cubos[1].theta[0] = 0.0;
	cubos[1].theta[1] = 0.0;
	cubos[1].theta[2] = 0.0;
	cubos[1].escala = 1.0;
	cubos[1].xCubo = 1.5;
	cubos[1].yCubo = 0.0;
	cubos[1].velocityX = 0.5;
	cubos[1].velocityY = 0.5;
}


void polygon(int a, int b, int c, int d)
{

	/* draw a polygon via list of vertices */

	glBegin(GL_POLYGON);
	//glColor3fv(colors[a]);
	glNormal3fv(normals[a]);
	glVertex3fv(vertices[a]);
	//glColor3fv(colors[b]);
	glNormal3fv(normals[b]);
	glVertex3fv(vertices[b]);
	//glColor3fv(colors[c]);
	glNormal3fv(normals[c]);
	glVertex3fv(vertices[c]);
	//glColor3fv(colors[d]);
	glNormal3fv(normals[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}




void colorcube(void)
{

	/* map vertices to faces */

	glColor3fv(colors[1]);
	polygon(0, 3, 2, 1);
	glColor3fv(colors[2]);
	polygon(2, 3, 7, 6);
	glColor3fv(colors[3]);
	polygon(0, 4, 7, 3);
	glColor3fv(colors[4]);
	polygon(1, 2, 6, 5);
	glColor3fv(colors[5]);
	polygon(4, 5, 6, 7);
	glColor3fv(colors[7]);
	polygon(0, 1, 5, 4);
}

void desenha3Cubos() {
	glScalef(0.2, 0.2, 0.2);
	colorcube();
	glTranslatef(2.2, 0, 0);
	colorcube();
	glTranslatef(-2.2 * 2, 0, 0);
	colorcube();
}

void cuboMagicoSemPushPop()
{
	int i, j, k;

	glScalef(0.2, 0.2, 0.2);

	glTranslatef(-2.2 * 2, -2.2 * 2, -2.2 * 2);

	for (i = 0; i < 3; i++) {
		glTranslatef(0.0, 0.0, 2.2);
		for (j = 0; j < 3; j++) {
			glTranslatef(0.0, 2.2, 0.0);
			for (k = 0; k < 3; k++) {
				glTranslatef(2.2, 0.0, 0.0);
				colorcube();
			}
			glTranslatef(-2.2 * 3, 0.0, 0.0);
		}
		glTranslatef(0.0, -2.2 * 3, 0.0);
	}
	glTranslatef(0.0, 0.0, -2.2 * 3);
}

void cuboMagico(int n)
{
	int i, j, k;

	glPushMatrix();

	glScalef(0.2, 0.2, 0.2);

	glTranslatef(-2.2, -2.2, -2.2);  // need to be centered...

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++) {
				glPushMatrix();
				glTranslatef(2.2 * i, 2.2 * j, 2.2 * k);
				colorcube();
				glPopMatrix();
			}

	glPopMatrix();
}


void eixos() {
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-2, 0, 0);
	glVertex3f(2, 0, 0);

	glVertex3f(2, 0, 0);
	glVertex3f(1.7, 0.3, 0);
	glVertex3f(2, 0, 0);
	glVertex3f(1.7, -0.3, 0);


	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, -2, 0);
	glVertex3f(0, 2, 0);

	glVertex3f(0, 2, 0);
	glVertex3f(0.3, 1.7, 0);
	glVertex3f(0, 2, 0);
	glVertex3f(-0.3, 1.7, 0);


	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, -2);
	glVertex3f(0, 0, 2);

	glVertex3f(0, 0, 2);
	glVertex3f(0.3, 0, 1.7);
	glVertex3f(0, 0, 2);
	glVertex3f(-0.3, 0, 1.7);

	glEnd();
}

void desenharCubo(int i) {

	glPushMatrix();

	glTranslatef(cubos[i].xCubo, cubos[i].yCubo, 0.0);

	glRotatef(cubos[i].theta[0], 1.0, 0.0, 0.0);
	glRotatef(cubos[i].theta[1], 0.0, 1.0, 0.0);
	glRotatef(cubos[i].theta[2], 0.0, 0.0, 1.0);

	glRotatef(internalPosition*60, 0.0, 1.0, 0.0);

	glScalef(cubos[i].escala, cubos[i].escala, cubos[i].escala);

	cuboMagico(3);

	glPopMatrix();
}

void updateCubo(int iCubo) {
	// Calcula a nova posição com base na velocidade e no tempo (em segundos)
	cubos[iCubo].xCubo += cubos[iCubo].velocityX * (TIME / 1000.0);
	cubos[iCubo].yCubo -= cubos[iCubo].velocityY * (TIME / 1000.0);

	// Verifica se o cubo bateu na parede e inverte a direção
	if (cubos[iCubo].xCubo < -2.0 || cubos[iCubo].xCubo > 2.0) {
		cubos[iCubo].velocityX = -cubos[iCubo].velocityX;
	}

	if (cubos[iCubo].yCubo < -2.0 || cubos[iCubo].yCubo > 2.0) {
		cubos[iCubo].velocityY = -cubos[iCubo].velocityY;
	}
}

//velocidade aqui em (pix/segundo) ou (unidade do mundo / segundo)
void update(int value) {
	printf("Some time...\n");

	
	internalPosition += internalVelocity * (TIME / 1000.0);

	if (internalPosition >= 1.0) {
		internalVelocity *= -1;
		internalPosition = 1.0;
	}

	if (internalPosition <= -1.0) {
		internalVelocity *= -1;
		internalPosition = -1.0;
	}
	
	updateCubo(0);
	updateCubo(1);


	glutPostRedisplay();

	glutTimerFunc(TIME, update, TIME);
}

void display(void)
{
	/* display callback, clear frame buffer and z buffer,
	   rotate cube and draw, swap buffers */

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	desenharCubo(0);
	desenharCubo(1);
	

	eixos();


	glFlush();


	//glutSwapBuffers();
}


void mouse(int btn, int state, int x, int y)
{

	/* mouse callback, selects an axis about which to rotate */

}


void teclasEspeciais(int key, int x, int y) {
	int i;

	if (key == GLUT_KEY_UP) {
		cubos[selectedCubo].theta[0] -= 2.0;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_DOWN) {
		cubos[selectedCubo].theta[0] += 2.0;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_LEFT) {
		cubos[selectedCubo].theta[1] -= 2.0;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_RIGHT) {
		cubos[selectedCubo].theta[1] += 2.0;
		glutPostRedisplay();
	}

	for (i = 0; i < 3; i++) {
		if (cubos[selectedCubo].theta[i] > 360.0) cubos[selectedCubo].theta[i] -= 360.0;
		if (cubos[selectedCubo].theta[i] < -360.0) cubos[selectedCubo].theta[i] += 360.0;
	}
}

void teclado(char key, int x, int y) {
	switch (key) {
	case '+': cubos[selectedCubo].escala += 0.1; glutPostRedisplay(); break;
	case '-': cubos[selectedCubo].escala -= 0.1; glutPostRedisplay(); break;
	case 'W':
	case 'w': cubos[selectedCubo].yCubo += 0.1; glutPostRedisplay(); break;
	case 'S':
	case 's': cubos[selectedCubo].yCubo -= 0.1; glutPostRedisplay(); break;
	case 'A':
	case 'a': cubos[selectedCubo].xCubo -= 0.1; glutPostRedisplay(); break;
	case 'D':
	case 'd': cubos[selectedCubo].xCubo += 0.1; glutPostRedisplay(); break;
	case '1': selectedCubo = 0; break;
	case '2': selectedCubo = 1; break;
	}

}



void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
			2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.0 * (GLfloat)w / (GLfloat)h,
			2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void
main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(500, 500);
	glutCreateWindow("colorcube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutTimerFunc(TIME, update, TIME);
	glutSpecialFunc(teclasEspeciais);
	glutKeyboardFunc(teclado);
	glutMouseFunc(mouse);

	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	init();
	glutMainLoop();
}
