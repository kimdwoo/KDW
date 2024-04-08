#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>


enum MouseState {
    NONE,
    DRAGGING_MOVE,
    DRAGGING_RESIZE
};

MouseState mouse = NONE;
double MouseX, MouseY;
float starX = 0.0f, starY = 0.0f; // 별의 중심
float scaleX = 1.0f, scaleY = 1.0f; // 별의 크기 조절

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        mouse = DRAGGING_MOVE; 
        MouseX = xpos;
        MouseY = ypos;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        mouse = DRAGGING_RESIZE; 
        MouseX = xpos;
        MouseY = ypos;
    }
    else if (action == GLFW_RELEASE) {
        mouse = NONE; 
    }
}

void mouseDragCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (mouse == DRAGGING_MOVE) {
        // 별의 위치 조절 
        float moveX = (xpos - MouseX) / 500.0f;
        float moveY = (ypos - MouseY) / 500.0f;
        starX += moveX;
        starY -= moveY; // y축은 반대여서 빼줌
        MouseX = xpos;
        MouseY = ypos;
    }
    else if (mouse == DRAGGING_RESIZE) {
        // 별의 크기 조절
        float scalX = (xpos - MouseX) / 500.0f;
        scaleX += scalX;
        scaleY += scalX; // x와 y 축의 스케일을 동일하게 변경하여 확대/축소
        MouseX = xpos;
        MouseY = ypos;
    }
}

int render()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON); //다각형
    //못생긴 별
    glVertex3f((0.15f * scaleX) + starX, (0.2f * scaleY) + starY, 0.0f);
    glVertex3f((0.5f * scaleX) + starX, (0.2f * scaleY) + starY, 0.0f);
    glVertex3f((0.25f * scaleX) + starX, (-0.05f * scaleY) + starY, 0.0f);
    glVertex3f((0.4f * scaleX) + starX, (-0.5f * scaleY) + starY, 0.0f);
    glVertex3f((0.0f * scaleX) + starX, (-0.2f * scaleY) + starY, 0.0f);
    glVertex3f((-0.4f * scaleX) + starX, (-0.5f * scaleY) + starY, 0.0f);
    glVertex3f((-0.25f * scaleX) + starX, (-0.05f * scaleY) + starY, 0.0f);
    glVertex3f((-0.5f * scaleX) + starX, (0.2f * scaleY) + starY, 0.0f);
    glVertex3f((-0.15f * scaleX) + starX, (0.2f * scaleY) + starY, 0.0f);
    glVertex3f((0.0f * scaleX) + starX, (0.5f * scaleY) + starY, 0.0f);

    glEnd();

    return 0;
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1000, 700, "drow star", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);


    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    glfwSetCursorPosCallback(window, mouseDragCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
