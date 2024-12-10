///* Rotating cube with color interpolation */
//
///* Demonstration of use of homogeneous coordinate
//transformations and simple data structure for representing
//cube from Chapter 4 */
//
///*Both normals and colors are assigned to the vertices */
///*Cube is centered at origin so (unnormalized) normals
//are the same as the vertex values */
//
//#include <stdlib.h>
//
//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include <GL/glut.h>
//#endif
//
//GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
//{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
//{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0} };
//
//GLfloat normals[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
//{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
//{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0} };
//
//GLfloat colors[][3] = { {0.0,0.0,0.0},{1.0,0.0,0.0},
//{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
//{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0} };
//
////variaveis globais
//static GLfloat theta[] = { 0.0,0.0,0.0 };
//static GLint axis = 2;
//
//float escala = 0.5;
//float xCubo = 0;
//float yCubo = 0;
//
//
//void tempo()
//{
//	int i;
//	double max = 25000000.0;
//	for (i = 0; i < max; i++)
//		(1 / max)* max* max* max / 3.14 + (1 / max) * max * max * max / 3.14 + (1 / max) * max * max * max / 3.14 + (1 / max) * max * max * max / 3.14;
//
//}
//
//void polygon(int a, int b, int c, int d, int faceColor)
//{
//	/* Draw a polygon with a single solid color for the entire face */
//
//	glBegin(GL_POLYGON);
//	glColor3fv(colors[faceColor]); // Set the face color
//
//	glNormal3fv(normals[a]);
//	glVertex3fv(vertices[a]);
//
//	glNormal3fv(normals[b]);
//	glVertex3fv(vertices[b]);
//
//	glNormal3fv(normals[c]);
//	glVertex3fv(vertices[c]);
//
//	glNormal3fv(normals[d]);
//	glVertex3fv(vertices[d]);
//
//	glEnd();
//}
//
//
//
//void colorcube(void)
//{
//    /* Map vertices to faces with unique colors */
//    polygon(0, 3, 2, 1, 0); // Face 1: Cor 0
//    polygon(2, 3, 7, 6, 1); // Face 2: Cor 1
//    polygon(0, 4, 7, 3, 2); // Face 3: Cor 2
//    polygon(1, 2, 6, 5, 3); // Face 4: Cor 3
//    polygon(4, 5, 6, 7, 4); // Face 5: Cor 4
//    polygon(0, 1, 5, 4, 5); // Face 6: Cor 5
//}
//
//
//void teclado(char key, int x, int y) {
//	switch (key)
//	{
//	case '+':
//		escala += 0.1;
//
//		glutPostRedisplay();
//		break;
//	case '-':
//		escala -= 0.1;
//
//		glutPostRedisplay();
//		break;
//	case 'w':
//	case 'W':	
//		yCubo += 0.1;
//
//		glutPostRedisplay();
//		break;
//	case 's':
//	case 'S':
//		yCubo -= 0.1;
//
//		glutPostRedisplay();
//		break;
//	case 'a':
//	case 'A':
//		xCubo -= 0.1;
//
//		glutPostRedisplay();
//		break;
//	case 'd':
//	case 'D':
//		xCubo += 0.1;
//		glutPostRedisplay();
//		break;
//	default:
//		break;
//	}
//}
//
//void especialTeclado(char key, int x, int y) {
//	switch (key)
//	{
//	case GLUT_KEY_UP:
//		axis = 0;
//		theta[axis] += 2.0;
//		glutPostRedisplay();
//		break;
//	case GLUT_KEY_DOWN:
//		axis = 0;
//		theta[axis] -= 2.0;
//
//		glutPostRedisplay();
//		break;
//	case GLUT_KEY_LEFT:
//		axis = 1;
//		theta[axis] -= 2.0;
//
//		glutPostRedisplay();
//		break;
//	case GLUT_KEY_RIGHT:
//		axis = 1;
//		theta[axis] += 2.0;
//		glutPostRedisplay();
//		break;
//	default:
//		break;
//	}
//
//}
//
//void drawMainAxis() {
//	glLineWidth(2.0); // Adiciona espessura às linhas
//
//	glBegin(GL_LINES);
//	glColor3f(1.0, 0.0, 0.0); // Eixo X
//	glVertex3f(-1.5, 0.0, 0.0);
//	glVertex3f(1.5, 0.0, 0.0);
//
//	glColor3f(0.0, 1.0, 0.0); // Eixo Y
//	glVertex3f(0.0, -1.5, 0.0);
//	glVertex3f(0.0, 1.5, 0.0);
//
//	glColor3f(0.0, 0.0, 1.0); // Eixo Z
//	glVertex3f(0.0, 0.0, -1.5);
//	glVertex3f(0.0, 0.0, 1.5);
//
//	glEnd();
//	glLineWidth(1.0); // Volta à espessura padrão
//}
//
//
//
//void display(void) {
//	/* Limpa o buffer de cor e profundidade */
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	/* Reseta as transformações */
//	glLoadIdentity();
//
//	// Cubo 1
//	glPushMatrix();
//	glTranslatef(-2.0 + xCubo, yCubo, 0.0); // Move o cubo para a esquerda
//	glRotatef(theta[0], 1.0, 0.0, 0.0);    // Rotação em X
//	glRotatef(theta[1], 0.0, 1.0, 0.0);    // Rotação em Y
//	glRotatef(theta[2], 0.0, 0.0, 1.0);    // Rotação em Z
//	glScalef(escala, escala, escala);      // Escala
//
//	colorcube();  // Desenha o cubo
//	drawMainAxis(); // Desenha os eixos para este cubo
//	glPopMatrix();
//
//	// Cubo 2
//	glPushMatrix();
//	glTranslatef(0.0 + xCubo, yCubo, 0.0); // Não move horizontalmente
//	glRotatef(theta[0], 1.0, 0.0, 0.0);    // Rotação em X
//	glRotatef(theta[1], 0.0, 1.0, 0.0);    // Rotação em Y
//	glRotatef(theta[2], 0.0, 0.0, 1.0);    // Rotação em Z
//	glScalef(escala, escala, escala);      // Escala
//
//	colorcube();  // Desenha o cubo
//	drawMainAxis(); // Desenha os eixos para este cubo
//	glPopMatrix();
//
//	// Cubo 3
//	glPushMatrix();
//	glTranslatef(2.0 + xCubo, yCubo, 0.0); // Move o cubo para a direita
//	glRotatef(theta[0], 1.0, 0.0, 0.0);    // Rotação em X
//	glRotatef(theta[1], 0.0, 1.0, 0.0);    // Rotação em Y
//	glRotatef(theta[2], 0.0, 0.0, 1.0);    // Rotação em Z
//	glScalef(escala, escala, escala);      // Escala
//
//	colorcube();  // Desenha o cubo
//	drawMainAxis(); // Desenha os eixos para este cubo
//	glPopMatrix();
//
//	/* Força a execução imediata */
//	glFlush();
//}
//
//
//
//
//void spinCube()
//{
//
//	/* Idle callback, spin cube 2 degrees about selected axis */
//
//	theta[axis] += 2.0;
//	if (theta[axis] > 360.0) theta[axis] -= 360.0;
//	/* display(); */
//	glutPostRedisplay();
//}
//
//void mouse(int btn, int state, int x, int y)
//{
//
//	/* mouse callback, selects an axis about which to rotate */
//
//	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
//	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
//	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
//}
//
//void myReshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
//			2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
//	else
//		glOrtho(-2.0 * (GLfloat)w / (GLfloat)h,
//			2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void
//main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//
//	/* need both double buffering and z buffer */
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("colorcube");
//	//teclado
//	glutKeyboardFunc(teclado);
//	//especial teclado
//	glutSpecialFunc(especialTeclado);
//	glutReshapeFunc(myReshape);
//	glutDisplayFunc(display);
//	//glutIdleFunc(spinCube);
//	glutMouseFunc(mouse);
//	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
//	glutMainLoop();
//}


/* Implementation until ToDo2, exercice 1*/


#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

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
static GLfloat theta[] = { 0.0,0.0,0.0 };
static GLint axis = 2;

// escala -> scale
float escala = 1.0;
float xCubo = 0.0;
float yCubo = 0.0;


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


// Rubik cube function
void cuboMagico()
{
	int i, j, k;

	glPushMatrix();

	glScalef(0.2, 0.2, 0.2);

	glTranslatef(-2.2, -2.2, -2.2);  // For center the cube...

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++) {
				glPushMatrix();
				glTranslatef(2.2 * i, 2.2 * j, 2.2 * k);
				colorcube();
				glPopMatrix();
			}

	glPopMatrix();
}

// Rubik cube function without push and pop functions
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

// draw 3 cubes
void desenha3Cubos() {

	glPushMatrix();

	glScalef(0.5, 0.5, 0.5);

	colorcube();
	//cuboMagico();

	glPushMatrix();
	glTranslatef(+2.5, 0.0, 0.0);
	colorcube();
	//cuboMagico();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 0.0, 0.0);
	colorcube();
	//cuboMagico();
	glPopMatrix();

	glPopMatrix();

}


// drawing the exis
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



void display(void)
{
	/* display callback, clear frame buffer and z buffer */

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(xCubo, yCubo, 0.0);

	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	glScalef(escala, escala, escala);


	//colorcube();
	//desenha3Cubos();
	cuboMagico();

	//glPushMatrix();
	//cuboMagicoSemPushPop();
	//glPopMatrix();

	eixos();


	glFlush();



	//glutSwapBuffers();
}


void mouse(int btn, int state, int x, int y)
{

	/* mouse callback, selects an axis about which to rotate */

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}


void teclasEspeciais(int key, int x, int y) {
	int i;

	if (key == GLUT_KEY_UP) {
		theta[0] -= 2.0;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_DOWN) {
		theta[0] += 2.0;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_LEFT) {
		theta[1] -= 2.0;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_RIGHT) {
		theta[1] += 2.0;
		glutPostRedisplay();
	}

	for (i = 0; i < 3; i++) {
		if (theta[i] > 360.0) theta[i] -= 360.0;
		if (theta[i] < -360.0) theta[i] += 360.0;
	}
}

void teclado(char key, int x, int y) {
	switch (key) {
	case '+': escala += 0.1; glutPostRedisplay(); break;
	case '-': escala -= 0.1; glutPostRedisplay(); break;
	case 'W':
	case 'w': yCubo += 0.1; glutPostRedisplay(); break;
	case 'S':
	case 's': yCubo -= 0.1; glutPostRedisplay(); break;
	case 'A':
	case 'a': xCubo -= 0.1; glutPostRedisplay(); break;
	case 'D':
	case 'd': xCubo += 0.1; glutPostRedisplay(); break;
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

	/* need both double buffering and z buffer */

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(500, 500);
	glutCreateWindow("colorcube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutSpecialFunc(teclasEspeciais);
	glutKeyboardFunc(teclado);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	glutMainLoop();
}