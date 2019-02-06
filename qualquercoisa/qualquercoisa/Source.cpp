#include<glut.h>
GLint op = 0, ap = 0;

void tri(){
	glBegin(GL_TRIANGLES);
	if (ap > 0 && ap < 3)
		ap == 1 ? glColor3f(1, 0, 0) : glColor3f(0, 1, 0);
	else
		glColor3f(0, 0, 1);
	glVertex2f(-3,-3);
	glVertex2f(3,-3);
	glVertex2f(0,3);
	glEnd();
}

void quad(){
	glBegin(GL_QUADS);
	if (ap > 0 && ap < 3)
		ap == 1 ? glColor3f(1, 0, 0) : glColor3f(0, 1, 0);
	else
		glColor3f(0, 0, 1);
	glVertex2f(-3, -3);
	glVertex2f(3, -3);
	glVertex2f(-3, 3);
	glVertex2f(3, 3);
	glEnd();
}

void show(){
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	if (op>0&&op<3)
		op == 1 ? tri() : quad();
	glFlush();
}

void Mouse(int button, int state, int x, int y){

}

void Teclado(unsigned char key, int x, int y){
	switch (key)
	{
	case '1':
		op = 1;
		break;
	case '2':
		op = 2;
		break;
	case 'R':
		op = 0;
		ap = 0;
		break;
	}
	show();
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("aula de mouse");
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(300, 300);
	gluOrtho2D(-16,16,-12,12);
	glutDisplayFunc(show);
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Teclado);
	glutMainLoop();
	return 0;
}