#include <glfw_initialization.h>
#include <GLFW/glfw3.h>
#include <precomp.h>

namespace veng {
    GlfwInitialization::GlfwInitialization() {
        if (glfwInit() != GLFW_TRUE) {
            std::exit(EXIT_FAILURE);
        }
    }

    GlfwInitialization::~GlfwInitialization() { glfwTerminate(); }
}
