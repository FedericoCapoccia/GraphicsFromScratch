#include <GLSS/window.hpp>
#include <fmt/core.h>

int main()
{
    glss::Window window {};
    window.init(100, 100, "title");
    return 0;
}
