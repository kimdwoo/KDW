#include <iostream>
#include <string>
#include <bitset>

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Cyan = 36,
    Magenta = 35,
    White = 37
};

// 숫자를 2진수로 변환하는 함수
std::string toBinaryString(int num) {
    return std::bitset<6>(num).to_string();
}

// 색상 코드에 따라 색상을 출력하는 함수
void printColoredText(const std::string& text, int colorCode) {
    std::cout << "\x1b[" << colorCode << "m" << text << "\x1b[0m";
}

int main() {
    std::cout << "\x1b[036m" << "아름다운 색!! 우왕" << std::endl;
    
    std::cout << "화면에 그림을 그리는 프로그램입니다." << std::endl;
    std::cout << "학번: 202127042" << std::endl;
    std::cout << "이름: 김동우" << std::endl;

    int end;
    while (true) {
        std::cout << "\n화면에 그릴 물체코드를 입력하세요 (프로그램 종료를 위해 64 입력): ";
        std::cin >> end;

        if (end == 64)
            break;

        // 입력된 숫자를 2진수로 변환
        std::string bString = toBinaryString(end);

        // 색상 코드에 맞게 출력
        for (int i = bString.size() - 1; i >= 0; --i) {
            int colorCode = 1 << (bString.size() - i - 1);
            std::string text = "*"; 

            // 각 자릿수가 1이면 색상 블록으로 변경
            if (bString[i] == '1') {
                switch (colorCode) {
                case 1:
                    printColoredText(text, White); break;
                case 2:
                    printColoredText(text, Red); break;
                case 4:
                    printColoredText(text, Green); break;
                case 8:
                    printColoredText(text, Yellow); break;
                case 16:
                    printColoredText(text, Cyan); break;
                case 32:
                    printColoredText(text, Magenta); break;
                }
            }
            else {
                std::cout << text;
            }
        }
    }
    /*
    * 흰색 블록을 그리는 키코드 : 1 (1)
    * 빨강색 블록을 그리는 키코드 : 2 (10)
    * 녹색 블록을 그리는 키코드 : 4 (100)
    * 노란색 블록을 그리는 키코드 : 8 (1000)
    * 청록색 블록을 그리는 키코드 : 16 (10000)
    * 마젠타색 블록을 그리는 키코드 : 32 (100000)
    * 프로그램 종료 : 64 (1000000)*/

    return 0;
}
