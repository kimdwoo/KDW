#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <cmath>

// 창 크기 설정
const int window_width = 1000;
const int window_height = 800;

// 시간 설정
const double sun_rotation_period = 30.0; // 태양 자전 
const double earth_rotation_period = 10.0; // 지구 자전
const double earth_orbit_period = 60.0; // 지구 공전 
const double moon_rotation_period = 3.0; //달 자전
const double moon_orbit_period = 3.0; //달 공전
const double M_PI = 3.14; //원

// 도형 그리기 함수
void drawsun(float x, float y, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawearth(float x, float y, float size) {
    glBegin(GL_QUADS);
    glVertex2f(x - size / 2, y - size / 2);
    glVertex2f(x + size / 2, y - size / 2);
    glVertex2f(x + size / 2, y + size / 2);
    glVertex2f(x - size / 2, y + size / 2);
    glEnd();
    
}

void drawStar(float x, float y, float radius, int points) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= points * 2; i++) {
        float angle = M_PI * i / points;
        float len = (i % 2 == 0) ? radius : radius / 2;
        glVertex2f(x + cos(angle) * len, y + sin(angle) * len);
    }
    glEnd();
    
}

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
        return -1;
    }

    // 창 생성
    GLFWwindow* window = glfwCreateWindow(window_width, window_height, "sun!", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwInit();

    // OpenGL 초기 설정
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, window_width, window_height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    while (!glfwWindowShouldClose(window)) {
        // 화면 초기화
        glClear(GL_COLOR_BUFFER_BIT);

        double currentTime = glfwGetTime();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 흰색 배경
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // 태양 그리기
        double sun_angle = (currentTime / sun_rotation_period) * 360;
        float sun_radius = window_width / 6;
        glPushMatrix();
        glTranslatef(window_width / 2, window_height / 2, 0);
        glRotatef(sun_angle, 0, 0, 1);
        glColor3f(1.0f, 0.851f, 0.4f); // #FFD966 색상
        drawsun(0, 0, sun_radius, 50); // 태양 크기
        glPopMatrix();

        
        glPushMatrix();
        glTranslatef(window_width / 2, window_height / 2, 0);
        glRotatef(sun_angle, 0, 0, 1);
        float inner_circle_radius1 = sun_radius / 3;
        glTranslatef(-1.5 * inner_circle_radius1, 0, 0);
        glColor3f(1.0f, 0.902f, 0.6f);
        drawsun(0, 0, inner_circle_radius1, 50);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(window_width / 2, window_height / 2, 0);
        glRotatef(sun_angle, 0, 0, 1);
        float inner_circle_radius2 = sun_radius / 5;
        glTranslatef(3.2 * inner_circle_radius2, 3.1* inner_circle_radius2, 0);
        
        glRotatef(-45.0f, 0, 0, 1); // 45도 회전
        glScalef(1.0f, 0.3f, 1.0f); // 세로로 1/4 축소
        glColor3f(1.0f, 0.7529f, 0.0f);
        drawsun(0, 0, inner_circle_radius2, 50);
        glPopMatrix();

        // 지구 그리기
        double earth_orbit_radius = window_width / 3;
        double earth_orbit_angle = (currentTime / earth_orbit_period) * 360;
        double earth_angle = (currentTime / earth_rotation_period) * 360;
        glPushMatrix();
        glTranslatef(window_width / 2, window_height / 2, 0);
        glRotatef(earth_orbit_angle, 0, 0, 1);
        glTranslatef(earth_orbit_radius, 0, 0);
        glRotatef(earth_angle, 0, 0, 1);
        glColor3f(0.0f, 0.0f, 1.0f); 
        drawearth(0, 0, window_width / 20); // 지구 크기
        glPopMatrix();

        // 달 그리기
        double moon_orbit_radius = window_width / 15;
        double moon_orbit_angle = (currentTime / moon_orbit_period) * 360;
        double moon_angle = (currentTime / moon_rotation_period) * 360;
        glPushMatrix();
        glTranslatef(window_width / 2, window_height / 2, 0);
        glRotatef(earth_orbit_angle, 0, 0, 1);
        glTranslatef(earth_orbit_radius, 0, 0);
        glRotatef(moon_orbit_angle, 0, 0, 1);
        glTranslatef(moon_orbit_radius, 0, 0);
        glRotatef(moon_angle, 0, 0, 1);
        glColor3f(1.0f, 1.0f, 0.0f); 
        drawStar(0, 0, window_width / 60, 5); // 달 크기
        glPopMatrix();

        // 화면 업데이트
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 종료
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
