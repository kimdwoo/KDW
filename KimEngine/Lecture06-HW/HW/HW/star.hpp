#include "MObject.h"
#include <GLFW/glfw3.h>
#include <random> 

class Star : public MObject
{
public:
    Star() {}

    void update()
    {
        
    }

    void render()
    {
       
        std::random_device rd;
        std::mt19937 gen(rd()); // 난수 생성기 메르센 트위스터?? random에서 사용하는 
        std::uniform_real_distribution<float> dis(-1.0f, 1.0f); // -1에서 1 사이의 균일한 분포 생성

        float xPos = dis(gen); // x 
        float yPos = dis(gen); // y 
        float red = dis(gen); // 빨간색 
        float green = dis(gen); // 녹색 
        float blue = dis(gen); // 파란색 

        glBegin(GL_TRIANGLES);

        glColor3f(red, green, blue);// 랜덤 색

        // 크기 줄이고 랜덤 위치
        glVertex2f(xPos, yPos + 0.05f);
        glVertex2f(xPos - 0.02f, yPos);
        glVertex2f(xPos, yPos - 0.05f);

        glVertex2f(xPos, yPos - 0.05f);
        glVertex2f(xPos + 0.02f, yPos);
        glVertex2f(xPos, yPos + 0.05f);

        glEnd();
    }
};
