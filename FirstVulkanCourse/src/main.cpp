#include <GLFW/glfw3.h>
#include <glfw_initialization.h>
#include <glfw_window.h>
#include <precomp.h>

std::int32_t main(std::int32_t argc, gsl::zstring *argv) {
    const veng::GlfwInitialization _glfw;

    veng::Window window("Vulkan Engine", {800, 600});

    window.TryMoveToMonitor(1);

    while (!window.ShouldClose()) {
        glfwPollEvents();
    }

    return EXIT_SUCCESS;
}
