#include <GLFW/glfw3.h>
#include <GL/gl.h> // OpenGL 헤더 포함
#include <iostream>
#include <list> // 링크드 리스트 헤더 포함

float moveFactor = 0.0f;
float scaleFactor = 1.0f;

void errorCallback(int error, const char* description)
{
    std::cerr << "\033[1;31mGLFW Error: " << description << "\033[0m" << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        moveFactor += 0.01f;
    }
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {
        scaleFactor += 0.1f;
    }
}

// MObject 클래스 선언
class MObject {
public:
    virtual void render() = 0;
    // 가상 소멸자 추가
    virtual ~MObject() {}
};

// Star 클래스 선언
class Star : public MObject {
public:
    virtual void render() override {
        // Star를 렌더링하는 코드
    }
};

std::list<MObject*> list; // 링크드 리스트로 변경

int initialize()
{
    MObject* temp[4];
    temp[0] = new Star();
    temp[1] = new Star();
    temp[2] = new Star();
    temp[3] = new Star();

    list.push_back(temp[0]);
    list.push_back(temp[1]);
    list.push_back(temp[2]);
    list.push_back(temp[3]);

    return 0;
}

int release()
{
    // 링크드 리스트의 객체들을 삭제
    for (auto obj : list) {
        delete obj;
    }
    list.clear(); // 리스트 비우기

    return 0;
}

int update()
{
    return 0;
}

int render()
{
    glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto obj : list) {
        obj->render();
    }

    return 0;
}

int main(void)
{
    //glfw라이브러리 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    initialize();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        update();
        render();
        glfwSwapBuffers(window);
    }

    release();

    glfwTerminate();
    return 0;
}
