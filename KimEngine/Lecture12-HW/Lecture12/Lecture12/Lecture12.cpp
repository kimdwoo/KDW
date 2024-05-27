#include <iostream>
#include <thread>  
#include <chrono> 

int main() {
    int count = 1;

    // while 문을 돌면서 1초 동안 대기
    while (count <= 10) {
        auto start = std::chrono::high_resolution_clock::now();

        std::cout << count << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "지연 시간: " << elapsed.count() << "s\n";

        ++count;
    }

    return 0;
}