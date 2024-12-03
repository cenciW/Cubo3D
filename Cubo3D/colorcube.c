/* Rotating cube with color interpolation */

/* Demonstration of use of homogeneous coordinate
transformations and simple data structure for representing
cube from Chapter 4 */

/*Both normals and colors are assigned to the vertices */
/*Cube is centered at origin so (unnormalized) normals
are the same as the vertex values */

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

//variaveis globais
static GLfloat theta[] = { 0.0,0.0,0.0 };
static GLint axis = 2;

float escala = 0.5;
float xCubo = 0;
float yCubo = 0;


void tempo()
{
	int i;
	double max = 25000000.0;
	for (i = 0; i < max; i++)
		(1 / max)* max* max* max / 3.14 + (1 / max) * max * max * max / 3.14 + (1 / max) * max * max * max / 3.14 + (1 / max) * max * max * max / 3.14;

}

void polygon(int a, int b, int c, int d, int faceColor)
{
	/* Draw a polygon with a single solid color for the entire face */

	glBegin(GL_POLYGON);
	glColor3fv(colors[faceColor]); // Set the face color

	glNormal3fv(normals[a]);
	glVertex3fv(vertices[a]);

	glNormal3fv(normals[b]);
	glVertex3fv(vertices[b]);

	glNormal3fv(normals[c]);
	glVertex3fv(vertices[c]);

	glNormal3fv(normals[d]);
	glVertex3fv(vertices[d]);

	glEnd();
}



void colorcube(void)
{
    /* Map vertices to faces with unique colors */
    polygon(0, 3, 2, 1, 0); // Face 1: Cor 0
    polygon(2, 3, 7, 6, 1); // Face 2: Cor 1
    polygon(0, 4, 7, 3, 2); // Face 3: Cor 2
    polygon(1, 2, 6, 5, 3); // Face 4: Cor 3
    polygon(4, 5, 6, 7, 4); // Face 5: Cor 4
    polygon(0, 1, 5, 4, 5); // Face 6: Cor 5
}


void teclado(char key, int x, int y) {
	switch (key)
	{
	case '+':
		escala += 0.1;

		glutPostRedisplay();
		break;
	case '-':
		escala -= 0.1;

		glutPostRedisplay();
		break;
	case 'w':
	case 'W':	
		yCubo += 0.1;

		glutPostRedisplay();
		break;
	case 's':
	case 'S':
		yCubo -= 0.1;

		glutPostRedisplay();
		break;
	case 'a':
	case 'A':
		xCubo -= 0.1;

		glutPostRedisplay();
		break;
	case 'd':
	case 'D':
		xCubo += 0.1;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void especialTeclado(char key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		axis = 0;
		theta[axis] += 2.0;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		axis = 0;
		theta[axis] -= 2.0;

		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		axis = 1;
		theta[axis] -= 2.0;

		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		axis = 1;
		theta[axis] += 2.0;
		glutPostRedisplay();
		break;
	default:
		break;
	}

}

void drawMainAxis() {
	glLineWidth(2.0); // Adiciona espessura às linhas

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0); // Eixo X
	glVertex3f(-1.5, 0.0, 0.0);
	glVertex3f(1.5, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0); // Eixo Y
	glVertex3f(0.0, -1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glColor3f(0.0, 0.0, 1.0); // Eixo Z
	glVertex3f(0.0, 0.0, -1.5);
	glVertex3f(0.0, 0.0, 1.5);

	glEnd();
	glLineWidth(1.0); // Volta à espessura padrão
}



void display(void) {
	/* Limpa o buffer de cor e profundidade */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Reseta as transformações */
	glLoadIdentity();

	// Cubo 1
	glPushMatrix();
	glTranslatef(-2.0 + xCubo, yCubo, 0.0); // Move o cubo para a esquerda
	glRotatef(theta[0], 1.0, 0.0, 0.0);    // Rotação em X
	glRotatef(theta[1], 0.0, 1.0, 0.0);    // Rotação em Y
	glRotatef(theta[2], 0.0, 0.0, 1.0);    // Rotação em Z
	glScalef(escala, escala, escala);      // Escala

	colorcube();  // Desenha o cubo
	drawMainAxis(); // Desenha os eixos para este cubo
	glPopMatrix();

	// Cubo 2
	glPushMatrix();
	glTranslatef(0.0 + xCubo, yCubo, 0.0); // Não move horizontalmente
	glRotatef(theta[0], 1.0, 0.0, 0.0);    // Rotação em X
	glRotatef(theta[1], 0.0, 1.0, 0.0);    // Rotação em Y
	glRotatef(theta[2], 0.0, 0.0, 1.0);    // Rotação em Z
	glScalef(escala, escala, escala);      // Escala

	colorcube();  // Desenha o cubo
	drawMainAxis(); // Desenha os eixos para este cubo
	glPopMatrix();

	// Cubo 3
	glPushMatrix();
	glTranslatef(2.0 + xCubo, yCubo, 0.0); // Move o cubo para a direita
	glRotatef(theta[0], 1.0, 0.0, 0.0);    // Rotação em X
	glRotatef(theta[1], 0.0, 1.0, 0.0);    // Rotação em Y
	glRotatef(theta[2], 0.0, 0.0, 1.0);    // Rotação em Z
	glScalef(escala, escala, escala);      // Escala

	colorcube();  // Desenha o cubo
	drawMainAxis(); // Desenha os eixos para este cubo
	glPopMatrix();

	/* Força a execução imediata */
	glFlush();
}




void spinCube()
{

	/* Idle callback, spin cube 2 degrees about selected axis */

	theta[axis] += 2.0;
	if (theta[axis] > 360.0) theta[axis] -= 360.0;
	/* display(); */
	glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{

	/* mouse callback, selects an axis about which to rotate */

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
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
	//teclado
	glutKeyboardFunc(teclado);
	//especial teclado
	glutSpecialFunc(especialTeclado);
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	//glutIdleFunc(spinCube);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	glutMainLoop();
}