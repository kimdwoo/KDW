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
        std::mt19937 gen(rd()); // ���� ������ �޸��� Ʈ������?? random���� ����ϴ� 
        std::uniform_real_distribution<float> dis(-1.0f, 1.0f); // -1���� 1 ������ ������ ���� ����

        float xPos = dis(gen); // x 
        float yPos = dis(gen); // y 
        float red = dis(gen); // ������ 
        float green = dis(gen); // ��� 
        float blue = dis(gen); // �Ķ��� 

        glBegin(GL_TRIANGLES);

        glColor3f(red, green, blue);// ���� ��

        // ũ�� ���̰� ���� ��ġ
        glVertex2f(xPos, yPos + 0.05f);
        glVertex2f(xPos - 0.02f, yPos);
        glVertex2f(xPos, yPos - 0.05f);

        glVertex2f(xPos, yPos - 0.05f);
        glVertex2f(xPos + 0.02f, yPos);
        glVertex2f(xPos, yPos + 0.05f);

        glEnd();
    }
};
