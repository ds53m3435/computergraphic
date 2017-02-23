#include<stdlib.h>
#include<stdio.h>
#include<gl/glut.h>
#include<cmath>
#include<math.h>
#define PI 3.14159265359
#define MAXPOINT 1300
double tx2 = 0, ty2 = 0, tx3 = 0, ty3 = 0, tx4 = 0, ty4 = 0;
float walk = 0, flyx = 0, flyy = 0, ffly = 0, anglex = 0.1, angley = 0.1, shake = 0,angles=0;
int countx = 0, county = 0, sh = 0, count = 0, all = 0, character = 0, charactera=0;
struct point{
	double x, y;
};
void drawBizier(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, GLdouble x3, GLdouble y3, GLdouble x4, GLdouble y4, bool close, point p[], bool fill){
	point a[MAXPOINT];
	int r = 0;
	for (double i = 0; i < 1; i += 0.001, r++)
	{
		a[r].x = (pow(i, 0) * pow(1 - i, 3) * x1) + (3 * pow(i, 1) * pow(1 - i, 2) * x2) + (3 * pow(i, 2) * pow(1 - i, 1) * x3) + (pow(i, 3) * x4);
		a[r].y = (pow(i, 0) * pow(1 - i, 3) * y1) + (3 * pow(i, 1) * pow(1 - i, 2) * y2) + (3 * pow(i, 2) * pow(1 - i, 1) * y3) + (pow(i, 3) * y4);
	}
	for (int i = 0; i < MAXPOINT; i++)
		glVertex2f(a[i].x, a[i].y);

	if (close)
	{
		drawBizier(x4, y4, x3 + tx2, y3 + ty2, x2 + tx3, y3 + ty3, x1 + tx4, y1 + ty4, false, a, fill);

	}
	if (p != nullptr&&fill)
	{
		glPointSize(1);
		glBegin(GL_LINES);
		for (int i = 0, j = MAXPOINT - 1; i <= MAXPOINT - 1; i++, j--)
		{
			glVertex2f(p[i].x, p[i].y);
			glVertex2f(a[j].x, a[j].y);
		}
		glEnd();
	}
}
void hcirce(double cenx, double ceny, double radiusx, double radiusy){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 500; i++){
		double theta =   PI*i / 500;
		glVertex2f(cenx + (radiusx*cos(theta)), ceny + (radiusy*sin(theta)));
	}
	glEnd();
}
void dhcirce(double cenx, double ceny, double radiusx, double radiusy){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 500; i++){
		double theta = -PI*i / 500;
		glVertex2f(cenx + (radiusx*cos(theta)), ceny + (radiusy*sin(theta)));
	}
	glEnd();
}
void circe(double cenx, double ceny, double radiusx, double radiusy,int h){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 500; i++){
		double theta = h*PI*i / 500;
		glVertex2f(cenx + (radiusx*cos(theta)), ceny + (radiusy*sin(theta)));
	}
	glEnd();
}
void hair(){
	glColor3f(0.5, 0.9, 0);
	circe(20, 67, 7, 6,2);
	circe(20, 60, 4, 4,2);
}
void face(){
	glLineWidth(2);
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(76.8, 49);
	glVertex2f(69, 69);
	glVertex2f(50, 80);
	glVertex2f(30, 79);
	glVertex2f(20, 70);
	glVertex2f(20, 56);
	glVertex2f(21.5, 46.5);
	glVertex2f(20, 45);
	glVertex2f(20, 40);
	glVertex2f(23, 35);
	glVertex2f(30, 30);
	glVertex2f(37, 27);
	glVertex2f(45, 28.5);
	glVertex2f(52, 30);
	glVertex2f(60, 34);
	glVertex2f(76, 41);
	glVertex2f(70, 38);
	glVertex2f(64, 38);
	glEnd();
	glLineWidth(0);
	glColor3f(1, 0.95, 0.8);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glVertex2f(76.8, 49);
	glVertex2f(69, 69);
	glVertex2f(50, 80);
	glVertex2f(30, 79);
	glVertex2f(20, 70);
	glVertex2f(20, 56);
	glVertex2f(21.5, 46.5);
	glVertex2f(20, 45);
	glVertex2f(20, 40);
	glVertex2f(23, 35);
	glVertex2f(30, 30);
	glVertex2f(37, 27);
	glVertex2f(45, 28.5);
	glVertex2f(52, 30);
	glVertex2f(60, 34);
	glVertex2f(76, 41);
	glVertex2f(70, 38);
	glVertex2f(64, 38);
	glEnd();
	glLineWidth(1);
	glPointSize(2);
	glColor3f(0.0, 0.0, 0.0);
}
void brow(){
	glBegin(GL_LINES);
	glVertex2f(37.5, 67);
	glVertex2f(44, 73);
	glVertex2f(33, 67);
	glVertex2f(28, 72);
	glEnd();
}
void ear(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(72, 40);
	glVertex2f(68.5, 40);
	glVertex2f(67.8, 41);
	glVertex2f(70, 43.5);
	glVertex2f(69.5, 45.8);
	glVertex2f(74, 48);
	glVertex2f(75.1, 45);
	glEnd();	
	glBegin(GL_LINE_LOOP);
	glVertex2f(66, 46);
	glVertex2f(72.5, 51);
	glVertex2f(76, 51);
	glVertex2f(77, 45);
	glVertex2f(76, 41);
	glVertex2f(70, 38);
	glVertex2f(64, 38);
	glEnd();
}
void nose(){
	glBegin(GL_TRIANGLES);
	glVertex2f(30.8, 47.4);
	glVertex2f(31.4, 49);
	glVertex2f(30.6, 48);
	glEnd();
}
void ka(){
	glBegin(GL_POINTS);
	glVertex2f(57, 44);
	glVertex2f(59.5, 42.5);
	glVertex2f(56.5, 40);
	glVertex2f(54.8, 42.5);
	glVertex2f(20.5, 41.2);
	glVertex2f(21.5, 42.7);
	glVertex2f(21, 44.7);
	glEnd();
}
void eyeout(){
	glLineWidth(6);
	hcirce(49, 53.5, 8, 13);
	glColor3f(1, 0.95, 0.8);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(57, 53.5);
	glVertex2f(41, 53.5);
	glEnd();
	glLineWidth(6);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(57, 53.5);
	glVertex2f(55, 45.5);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(59, 45.8);
	glVertex2f(42, 46);
	glVertex2f(58, 45);
	glVertex2f(52, 45.5);
	glEnd();
	glLineWidth(6);
	hcirce(26, 55, 5, 11);
	glColor3f(1, 0.95, 0.8);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(31, 55);
	glVertex2f(21, 55);
	glEnd();
	glLineWidth(6);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(21, 55);
	glVertex2f(23.3, 47.2);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(27, 47);
	glVertex2f(23, 47.2);
	glVertex2f(26, 46.5);
	glVertex2f(23, 46);
	glEnd();
}
void eyein(){
	glColor3f(0, 1, 0);
	circe(28, 56, 1.8, 4,2);
	circe(44.8, 57.5, 2.2, 4,2);
	glColor3f(1, 1, 1);
	circe(46.2, 57.2, 1.2, 2,2);
	circe(29, 56, 1, 1,2);
}
void mouse(){
	glLineWidth(3);
	glColor3f(0, 0, 0);
	dhcirce(37, 42, 11, 7);
	glColor3f(1, 0.95, 0.8);
	glLineWidth(8);
	glBegin(GL_LINES);
	glVertex2f(26, 42);
	glVertex2f(48, 42);
	glEnd();
}
void hair1(){
	glColor3f(0, 1, 0);
	circe(25, 90, 6, 6,2);
	circe(40, 92, 8, 10,2);
	circe(50, 90, 8, 10,2);
	circe(62, 85, 8, 10,2);
	circe(70, 77, 8, 8,2);
	circe(75, 70, 6, 6,2);
	circe(77, 60, 5, 5,2);
	circe(76, 55, 5, 6,2);
	glColor3f(0.5, 0.9, 0);
	circe(20, 80, 8, 10,2);
	circe(30, 85, 8, 10,2);
	circe(42, 87, 8, 12,2);
	circe(51, 80, 5, 8,2);
	circe(60, 80, 8, 9,2);
	circe(65, 73, 5, 4,2);
	circe(70, 67, 7, 7,2);
	circe(71, 57.2, 6, 6.2,2);
	circe(68.5, 52, 4, 4,2);
	circe(67, 48, 3, 3,2);
	circe(65, 42, 3, 6,2);
}
void shirt(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(67, 36);
	glVertex2f(80, 29);
	glVertex2f(85, 21);
	glVertex2f(95, 6);
	glVertex2f(94.6, 0);
	glVertex2f(33, 0);
	glVertex2f(33, 8);
	glVertex2f(35, 12);
	glVertex2f(40, 20);
	glVertex2f(43, 25);
	glVertex2f(45, 27.5);
	glVertex2f(50, 29);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 0.95, 0.8);
	glBegin(GL_TRIANGLES);
	glVertex2f(80, 0);
	glVertex2f(88, 5.7);
	glVertex2f(90, 0);
	glVertex2f(40, 0);
	glVertex2f(34, 0);
	glVertex2f(36.5, 3);
	glEnd();
	glColor3f(0, 0, 0);
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(67, 36);
	glVertex2f(80, 29);
	glVertex2f(85, 21);
	glVertex2f(95, 6);
	glVertex2f(94.6, 0);
	glVertex2f(33, 0);
	glVertex2f(33, 8);
	glVertex2f(35, 12);
	glVertex2f(40, 20);
	glVertex2f(43, 25);
	glVertex2f(45, 27.5);
	glVertex2f(50, 29);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(95, 6);
	glVertex2f(92, 7);
	glVertex2f(89, 6.2);
	glVertex2f(80, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(40, 0);
	glVertex2f(34, 0);
	glVertex2f(36.5, 3);
	glVertex2f(80, 0);
	glVertex2f(88, 5.7);
	glVertex2f(90, 0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(45, 13.5);
	glVertex2f(48, 3.5);
	glVertex2f(48, 0);
	glEnd();
}
void neck(){
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 0.95, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(50.5, 29);
	glVertex2f(63, 35.2);
	glVertex2f(66, 33);
	glVertex2f(57, 16);
	glVertex2f(55, 23);
	glVertex2f(54.5, 27);
	glEnd();
	glColor3f(0.8, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(54.5, 27);
	glVertex2f(50.5, 29);
	glVertex2f(50, 23);
	glVertex2f(57, 16);
	glEnd();
	glColor3f(0, 0, 0);
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(50.5, 29);
	glVertex2f(63, 35.2);
	glVertex2f(66, 33);
	glVertex2f(57, 16);
	glVertex2f(55, 23);
	glVertex2f(54.5, 27);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(54.5, 27);
	glVertex2f(56, 24);
	glVertex2f(66, 34.5);
	glVertex2f(66.5, 33);
	glVertex2f(66.5, 33);
	glVertex2f(66, 33);
	glEnd();
}
void hand(){
	glLineWidth(2);
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0, shake, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(53.2, 0);
	glVertex2f(52.8, 2);
	glVertex2f(55.5, 6.8);
	glVertex2f(54.2, 10);
	glVertex2f(57, 13);
	glVertex2f(60, 14.8);
	glVertex2f(65, 16);
	glVertex2f(70, 15.5);
	glVertex2f(75, 14);
	glVertex2f(79, 9);
	glVertex2f(78, 0);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 0.95, 0.8);
	glBegin(GL_POLYGON);
		glVertex2f(53.2, 0);
		glVertex2f(52.8, 2);
		glVertex2f(55.5, 6.8);
		glVertex2f(54.2, 10);
		glVertex2f(57, 13);
		glVertex2f(60, 14.8);
		glVertex2f(65, 16);
		glVertex2f(70, 15.5);
		glVertex2f(75, 14);
		glVertex2f(79, 9);
		glVertex2f(78, 0);
	glEnd();
	glColor3f(0, 0, 0);
	glLineWidth(1);
	glBegin(GL_LINES);
		glVertex2f(54,7);
		glVertex2f(64, 9);
		glVertex2f(54, 2);
		glVertex2f(64, 3.2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 0.95, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(14.5, 0);
	glVertex2f(15, 13.5);
	glVertex2f(25, 15);
	glVertex2f(28, 15);
	glVertex2f(32.5, 10.5);
	glVertex2f(32, 0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(32.5, 10.5);
	glVertex2f(37, 8);
	glVertex2f(36.8, 3.8);
	glVertex2f(32, 1.2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(14.5, 0);
	glVertex2f(15, 13.5);
	glVertex2f(25, 15);
	glVertex2f(28, 15);
	glVertex2f(32.5, 10.5);
	glVertex2f(32, 0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(32.5, 10.5);
	glVertex2f(37, 8);
	glVertex2f(36.8, 3.8);
	glVertex2f(32, 1.2);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(19, 6.5);
	glVertex2f(24, 8);
	glVertex2f(24, 8);
	glVertex2f(29.5, 7);
	glVertex2f(20.5, 1.5);
	glVertex2f(24, 2);
	glVertex2f(24, 2);
	glVertex2f(30, 1.1);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(25,8);
	glVertex2f(25.5,10);
	glVertex2f(25.3,12);
	glVertex2f(25.5, 15);
	glEnd();
	glPopMatrix();
}
void knight(){
	glPushMatrix();
	glTranslatef(0, shake, 0);
	glColor3f(0.5,0.5,0.5);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUAD_STRIP);
		glVertex2f(62,14);
		glVertex2f(72, 14);
		glVertex2f(61,50);
		glVertex2f(72, 18);
		glVertex2f(73,50);
		glVertex2f(67, 60);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2f(73,50);
		glVertex2f(67,60);
		glVertex2f(72,18);
	glEnd();
	glColor3f(0, 0, 0);
	glLineWidth(0.5);
	glBegin(GL_LINES);
		glVertex2f(67,59);
		glVertex2f(67, 16);
		glVertex2f(61.5,50);
		glVertex2f(67,47);
		glVertex2f(67, 47);
		glVertex2f(72.5,50);
		glVertex2f(62, 14);
		glVertex2f(61, 50);
		glVertex2f(61, 50);
		glVertex2f(67, 60);
		glVertex2f(67, 60);
		glVertex2f(73, 50);
		glVertex2f(73, 50);
		glVertex2f(72, 14);
	glEnd();
	glPopMatrix();
}
void man(){
	hair();
	face();
	brow();
	ear();
	nose();
	ka();
	eyeout();
	eyein();
	mouse();
	hair1();
	shirt();
	neck();
	knight();
	hand();

}
void sky(){
	glColor3f(0, 0.8, 1);
	glBegin(GL_QUADS);
	glVertex2f(0,35);
	glVertex2f(0,120);
	glVertex2f(120,120);
	glVertex2f(120, 35);
	glEnd();
	glColor3f(0.741, 0.718, 0.420);
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(0, 35);
	glVertex2f(120, 35);
	glVertex2f(120, 0);
	glEnd();
	glColor3f(0.196, 0.804, 0.196);
	circe(35, 30, 45, 30, 1);
	circe(95, 30,30,15, 1);
}
void sun(){
	glColor3f(1.000, 1.000, 0.000);
	circe(60, 100, 5, 5,2);
}
void bird(){
	glPushMatrix();
	glTranslatef(flyx, flyy, 0);
	glColor3f(1, 1, 1);
	drawBizier(-120, 100, -117, 110, -113, 110, -110, 100, true, nullptr, true);
	drawBizier(-50, 90, -46, 100, -42, 100, -39, 90, true, nullptr, true);
	drawBizier(20, 100, 24, 110, 27, 110, 30, 100, true, nullptr, true);
	drawBizier(0, 90, 4, 100, 7, 100, 10, 90, true, nullptr, true);
	drawBizier(70, 90, 74, 100, 77, 100, 80, 90, true, nullptr, true);
	drawBizier(100,70, 104, 80, 108, 80, 110, 75, true, nullptr, true);
	drawBizier(150, 80, 154, 83, 158, 83, 160, 80, true, nullptr, true);
	drawBizier(130, 70, 134, 80, 138, 80, 142, 70, true, nullptr, true);
	drawBizier(190, 90, 194, 100, 197, 100, 200, 90, true, nullptr, true);
	glPopMatrix();
}
void wall(){
	//sky();
	sun();
	bird();
	glColor3f(0.196, 0.804, 0.196);
	circe(35, 30, 45, 30, 1);
	circe(95, 30, 30, 15, 1);
	circe(-24, 30, 45,20, 1);
	circe(130, 30, 30, 30, 1);
	circe(-70, 30, 40, 40, 1);
	circe(175, 30, 40, 40, 1);
	glColor3f(0.741, 0.718, 0.420);
	glBegin(GL_QUADS);
	glVertex2f(-200, 0);
	glVertex2f(-200, 35);
	glVertex2f(300, 35);
	glVertex2f(300, 0);
	glEnd();
}
void display(){
	glClearColor(0, 0.8, 10, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(walk, 0, 0);
	wall();
	glPopMatrix();
	glPushMatrix();
	if (!character)
	glRotatef(0, 0,character, 0);
	else{
		glTranslatef(105, 0, 0);
		glRotatef(180, 0, character, 0);
	}
	man();
	glPopMatrix();
	glutSwapBuffers();
}
void mykey(unsigned char key,int x,int y){

}
void myspe(int key,int x ,int y){
	switch (key){
	case GLUT_KEY_RIGHT:
		if (walk < -100) walk = 100;
		walk =walk - 2;
		charactera = 0;
		character = 1;
		glutPostRedisplay();
		printf("x = %d , y = %d ,walk = %d\n",x,y,walk);
		break;
	case GLUT_KEY_LEFT:
		if (walk > 100) walk = -100;
		walk = walk+ 2;
		charactera = 180 ;
		character = 0;
		glutPostRedisplay();
		printf("x = %d , y = %d ,walk = %d\n", x, y, walk);
		break;
	}
		
}
void spin() {
	if (countx%3000 == 0){
		anglex = 0.05;
	}
	else if (countx%3000 == 1500){
		anglex = -0.05;
	}
	if (countx % 100 == 0){
		angley = 0.05;
	}
	else if (countx % 100 == 50){
		angley = -0.05;
	}
	flyx += anglex;
	flyy += angley;
	countx++;
	county++;
	glutPostRedisplay();
}void shakker(){
	if (count % 100 == 0){
		angles = -0.1;
	}
	else if (count % 100 == 50){
		angles = 0.1;
	}
	count++;
	shake += angles;
	glutPostRedisplay();
}
void shakkerandspin(){
	if (countx % 3000 == 0){
		anglex = 0.05;
	}
	else if (countx % 3000 == 1500){
		anglex = -0.05;
	}
	if (countx % 100 == 0){
		angley = 0.05;
	}
	else if (countx % 100 == 50){
		angley = -0.05;
	}
	if (count % 100 == 0){
		angles = -0.1;
	}
	else if (count % 100 == 50){
		angles = 0.1;
	}
	count++;
	shake += angles;
	flyx += anglex;
	flyy += angley;
	countx++;
	county++;
	glutPostRedisplay();
}
void mainmenu(int value) {
	switch (value) {
	case 1: if (ffly == 0){
		glutIdleFunc(spin);
		ffly = 1;
	}
			else{
		glutIdleFunc(NULL);
		ffly = 0;
			}
			break;
	case 2: if(sh == 0){
		glutIdleFunc(shakker);
		sh = 1;
	}
			else{
				glutIdleFunc(NULL);
				sh = 0;
			}
			break;
	case 3:if (all == 0){
		glutIdleFunc(shakkerandspin);
		all = 1;
	}
		   else{
			   glutIdleFunc(NULL);
			   all = 0;
		   }
		   break;
	case 999: exit(0);

	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(800, 600);
	glutCreateWindow("My hero          press left and right for walk");
	glutCreateMenu(mainmenu);
	glutAddMenuEntry("Bird Fly", 1);
	glutAddMenuEntry("Chucky", 2);
	glutAddMenuEntry("Chuck & Bird", 3);
	glutAddMenuEntry("Quit", 999);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 110,0,110);
	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	glutSpecialFunc(myspe);
	glutMainLoop();
	return 0;

}