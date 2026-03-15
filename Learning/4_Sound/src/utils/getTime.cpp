#include <chrono>
#include <cstdint>

std::uint64_t getTimeInMilliseconds() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::chrono::milliseconds ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch();
    return ms.count();
}