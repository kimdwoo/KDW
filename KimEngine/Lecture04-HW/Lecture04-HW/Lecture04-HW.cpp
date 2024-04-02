//과제물 프로젝트명: Lecture04_HW
//idle : 화면색 검정색으로 clear
//마우스 오른쪽 KeyDown하면 : 빨간색
//마우스 오른쪽 KeyUp하면 : 원상복구
//마우스 왼쪽 KeyDown하면 : 녹색
//마우스 왼쪽 KeyUp하면 : 원상복구
//마우스 오른쪽 KeyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 KeyDown하고 드래그 중이면 : 마젠타색

//https://www.glfw.org/
//학번 : 202127042
//이름 : 김동우
#pragma comment (lib, "OpenGL32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

bool RightBtnDown = false; // 마우스 오른쪽 버튼이 눌렸는지 변수
bool LeftBtnDown = false; // 마우스 왼쪽 버튼이 눌렸는지 변수
bool RightBtnDrag = false; // 마우스 오른쪽 버튼 드래그 변수
bool LeftBtnDrag = false; // 마우스 왼쪽 버튼 드래그 변수

//클릭 콜백 함수
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT) // 오른쪽 마우스 버튼 클릭 시 동작
    {
        if (action == GLFW_PRESS) // 마우스를 클릭했을 때
        {
            RightBtnDown = true;
            RightBtnDrag = false;
        }
        else if (action == GLFW_RELEASE) // 마우스 클릭을 해제했을 때
            RightBtnDown = false;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT) // 왼쪽 마우스 버튼 클릭 시 동작
    {
        if (action == GLFW_PRESS) // 마우스를 클릭했을 때
        {
            LeftBtnDown = true;
            LeftBtnDrag = false;
        }
        else if (action == GLFW_RELEASE) // 마우스 클릭을 해제했을 때
            LeftBtnDown = false;
    }
}

//이동 콜백 함수
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    if (RightBtnDown && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) // 오른쪽 마우스 버튼 지속될 때
    {
        RightBtnDrag = true;
        LeftBtnDrag = false;
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 화면을 파란색으로
    }
    else if (LeftBtnDown && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) // 왼쪽 마우스 버튼 지속될 때
    {
        RightBtnDrag = false;
        LeftBtnDrag = true;
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 화면을 마젠타색으로
    }
    else
    {
        RightBtnDrag = false;
        LeftBtnDrag = false;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}

int main() {
    // GLFW 초기화 함수 
    if (!glfwInit()) {
        std::cerr << "GLFW 초기화 실패" << std::endl;
        return -1;
    }

    // GLFW 윈도우 생성 함수
    GLFWwindow* window = glfwCreateWindow(1280, 760, "OpenGL Window", NULL, NULL);
    if (!window) {
        std::cerr << "GLFW 윈도우 생성 실패" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 윈도우 컨텍스트 설정
    glfwMakeContextCurrent(window);
    // 마우스 클릭 콜백 함수 등록
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    // 마우스 이동 콜백 함수 등록
    glfwSetCursorPosCallback(window, cursor_position_callback);

    //구동 루프
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        if (RightBtnDown) // 오른쪽 마우스를 누르면
        {
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // 화면을 빨간색으로 변경
        }
        else if (LeftBtnDown)
        {
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // 화면을 초록색으로 변경
        }
        else
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 아무것도 안 누른 상태면 화면을 검정색으로 변경
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}

