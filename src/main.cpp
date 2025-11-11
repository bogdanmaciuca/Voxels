#include <print>
#include "glw/glw.hpp"

constexpr int WND_W = 1024;
constexpr int WND_H = 768;

int main() {
    if (glw::Initialize("Hello Voxels!", WND_W, WND_H, true) == false) {
        std::println("Could not initialize glw. Exitting.");
        return 1;
    }

    while (!glw::ShouldQuit()) {
        glw::PollEvents();

        glw::Clear();
        glw::SwapBuffers();
    }
}

