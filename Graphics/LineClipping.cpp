#include <stdio.h>
#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>

int X1, Y1, X2, Y2, l1x1, l1y1, l1x2, l1y2, l2x1, l2y1, l2x2, l2y2;
const int in = 0, lf = 1, rt = 2, bt = 4, tp = 8;
int x_max, y_max, x_min, y_min;

struct Color {
	float r;
	float g;
	float b;
};

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500, 500, -500, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
	if (y1 == y2) {
		for (int i = x1; i <= x2; i++)
			draw_pixel(i, y1);
	} else {
		for (int i = y1; i <= y2; i++)
			draw_pixel(x1, i);
	}
}

void DDA(int x1, int y1, int x2, int y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;
	float step = abs(dx);
	if (abs(dy) > abs(dx))
		step = abs(dy);
	float xInc = dx / step;
	float yInc = dy / step;
	float temX = x1, temY = y1;
	for (int i = 1; i <= step; i++) {
		draw_pixel(round(temX), round(temY));
		temX += xInc;
		temY += yInc;
	}
}

int computeCode(int x, int y) {
	int code = in;

	if (x < x_min)
		code |= lf;
	else if (x > x_max)
		code |= rt;
	if (y < y_min)
		code |= bt;
	else if (y > y_max)
		code |= tp;

	return code;
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
	int code1 = computeCode(x1, y1);
	int code2 = computeCode(x2, y2);

	bool accept = false;

	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
			accept = true;
			break;
		} else if (code1 & code2) {
			glColor3f(1.0, 0.0, 0.0);
			DDA(x1, y1, x2, y2);
			break;
		} else {
			int code_out;
			double x, y;

			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			if (code_out & tp) {
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			} else if (code_out & bt) {
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			} else if (code_out & rt) {
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			} else if (code_out & lf) {
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			if (code_out == code1) {
				glColor3f(1.0, 0.0, 0.0);
				DDA(x1, y1, x, y);
				x1 = x;
				y1 = y;
				code1 = computeCode(x1, y1);
			} else {
				glColor3f(1.0, 0.0, 0.0);
				DDA(x2, y2, x, y);
				x2 = x;
				y2 = y;
				code2 = computeCode(x2, y2);
			}
		}
	}
	if (accept) {
		glColor3f(0.0, 1.0, 0.0);
		DDA(x1, y1, x2, y2);
	}
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	draw_line(-500, 500, 0, 0);
	draw_line(0, 0, -500, 500);
	draw_line(X1, X2, Y1, Y1);
	draw_line(X1, X2, Y2, Y2);
	draw_line(X1, X1, Y1, Y2);
	draw_line(X2, X2, Y1, Y2);
	cohenSutherlandClip(l1x1, l1y1, l1x2, l1y2);
	cohenSutherlandClip(l2x1, l2y1, l2x2, l2y2);
	glFlush();

}

int main(int argc, char **argv) {
	printf("Enter lower left coordinate of Rectangle : ");
	scanf("%d %d", &X1, &Y1);
	printf("Enter upper right coordinate of Rectangle : ");
	scanf("%d %d", &X2, &Y2);
	x_max = X2;
	x_min = X1;
	y_max = Y2;
	y_min = Y1;

	printf("Enter end points of line1 : ");
	scanf("%d %d %d %d", &l1x1, &l1y1, &l1x2, &l1y2);
	printf("Enter end points of line2 : ");
	scanf("%d %d %d %d", &l2x1, &l2y1, &l2x2, &l2y2);


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(800, 400);
	glutCreateWindow("Line Clipping");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
