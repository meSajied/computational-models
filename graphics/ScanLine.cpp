#include <stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<algorithm>
#include <GL/glut.h>

using namespace std;

int n, minY = 10000, maxY = -1;
vector<double> xInt;

struct Vertices {
	int X;
	int Y;
};

struct Edges {
	double xx;
	int ymin;
	int ymax;
	double revslp;
};

Vertices vrt[50];
Edges edg[50];

void func(double x1, double y1, double x2, double y2) {

	double dx, dy, inc_x, inc_y, x, y, cnt;

	dx = x2 - x1;
	dy = y2 - y1;

	if (fabs(dy) > fabs(dx))
		cnt = fabs(dy) * 100;
	else
		cnt = fabs(dx) * 100;

	inc_x = dx / cnt;
	inc_y = dy / cnt;

	x = x1;
	y = y1;

	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();

	for (double i = 1; i <= cnt; i++) {
		x = x + inc_x;
		y = y + inc_y;

		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();

	}
	glFlush();
	glutSwapBuffers();
}

void polygonDrawer() {
	int x1, y1, x2, y2;

	for (int i = 0; i < n; i++) {
		x1 = vrt[i].X;
		y1 = vrt[i].Y;

		if (i == n - 1) {
			x2 = vrt[0].X;
			y2 = vrt[0].Y;
		} else {
			x2 = vrt[i + 1].X;
			y2 = vrt[i + 1].Y;
		}

		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}

		func(x1, y1, x2, y2);
	}
}

void edgeMaker() {
	int x1, y1, x2, y2, x3, y3;

	for (int i = 0; i < n; i++) {
		x1 = vrt[i].X;
		y1 = vrt[i].Y;

		if (i + 2 == n) {
			x2 = vrt[i + 1].X;
			y2 = vrt[i + 1].Y;

			x3 = vrt[0].X;
			y3 = vrt[0].Y;
		} else if (i + 1 == n) {
			x2 = vrt[0].X;
			y2 = vrt[0].Y;

			x3 = vrt[1].X;
			y3 = vrt[1].Y;
		} else {
			x2 = vrt[i + 1].X;
			y2 = vrt[i + 1].Y;

			x3 = vrt[i + 2].X;
			y3 = vrt[i + 2].Y;
		}

		if (y1 == y2)
			continue;

		edg[i].xx = x1;

		if (y1 < y2 && y2 < y3) {
			edg[i].ymax = y2 - 1;
			edg[i].ymin = y1;
			edg[i].xx = x1;
			edg[i].revslp = (double) (x1 - x2) / (double) (y1 - y2 + 1);
		} else if (y1 > y2 && y2 > y3) {
			edg[i].ymax = y1;
			edg[i].ymin = y2 + 1;
			edg[i].xx = x2;
			edg[i].revslp = (double) (x1 - x2) / (double) (y1 - y2 - 1);
		} else {
			if (y1 >= y2) {
				edg[i].ymax = y1;
				edg[i].ymin = y2;
				edg[i].xx = x2;
			} else {
				edg[i].ymax = y2;
				edg[i].ymin = y1;
				edg[i].xx = x1;
			}
			edg[i].revslp = (double) (x1 - x2) / (double) (y1 - y2);
		}
	}
}

void coloring() {

	for (int i = minY; i <= maxY; i++) {
		xInt.clear();

		for (int j = 0; j < n; j++) {
			if (i <= edg[j].ymax && i >= edg[j].ymin) {
				xInt.push_back(edg[j].xx);
				edg[j].xx = edg[j].xx + edg[j].revslp;
			}
		}

		sort(xInt.begin(), xInt.end());
		for (int j = 0; j < xInt.size(); j += 2) {
			func(xInt[j], i, xInt[j + 1], i);
		}
	}
}

void myDisplay() {
	glPointSize(1.0);

	glColor3f(0.0, 0.0, 0.0);
	func(-500, 0, 500, 0);
	func(0, -500, 0, 500);

	glColor3f(0.0, 0.0, 0.0);
	polygonDrawer();
	glEnd();
	glFlush();

	edgeMaker();

	glPointSize(1.0);
	glColor3f(0.0, 1.0, 1.0);
	coloring();
	glEnd();
	glFlush();

	glPointSize(1.0);
	glColor3f(0.0, 1.0, 1.0);
	polygonDrawer();
	glEnd();
	glFlush();
}

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv) {
	printf("What's the number of edges?\n");
	scanf("%d", &n);

	int x, y;
	printf("Input vertices clockwise:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);

		minY = min(y, minY);
		maxY = max(y, maxY);

		vrt[i].X = x;
		vrt[i].Y = y;
	}

	//Initializing
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Polygon filling using Scanline Algorithm");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();

	return 0;
}
/*
6
20 10
70 140
50 250
150 240
220 300
170 65
*/
