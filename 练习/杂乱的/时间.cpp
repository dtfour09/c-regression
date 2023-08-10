#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* timeInfo = std::localtime(&currentTime_t);

    std::chrono::time_point<std::chrono::system_clock> baseTime = std::chrono::system_clock::from_time_t(946684800); // 2000��1��1�յ�ʱ���
    std::chrono::duration<double> elapsedTime = currentTime - baseTime;

    int days = static_cast<int>(elapsedTime.count() / (24 * 60 * 60));
    int hours = static_cast<int>((static_cast<int>(elapsedTime.count())) / 3600);
    int minutes = static_cast<int>((static_cast<int>(elapsedTime.count())) / 60);
    int seconds = static_cast<int>(elapsedTime.count());

    std::cout << "����: " << days << std::endl;
    std::cout << "Сʱ: " << hours << std::endl;
    std::cout << "����: " << minutes << std::endl;
    std::cout << "��: " << seconds << std::endl;

    std::cout << "ϵͳʱ��: "
        << timeInfo->tm_hour << ":" << timeInfo->tm_min << ":" << timeInfo->tm_sec << std::endl;

    return 0;
}
