#include <GLFW/glfw3.h>

#include <precomp.h>
#include <graphics.h>

namespace veng {

Graphics::Graphics(gsl::not_null<Window*> window) : window_(window) {
  InitializeVulkan();
}

Graphics::~Graphics() {
  if (instance_ != nullptr) { vkDestroyInstance(instance_, nullptr); }
}

void Graphics::InitializeVulkan() {
  CreateInstance();
}

void Graphics::CreateInstance() {
  gsl::span<gsl::czstring> suggested_extensions = GetSuggestExtensions();

  VkApplicationInfo app_info = {};
  app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  app_info.pNext = nullptr;
  app_info.pApplicationName = "VulkanEngine";
  app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.pEngineName = "VulkanEngine";
  app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo instance_create_info = {};
  instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instance_create_info.pNext = nullptr;
  instance_create_info.pApplicationInfo = &app_info;
  instance_create_info.enabledExtensionCount = suggested_extensions.size();
  instance_create_info.ppEnabledExtensionNames = suggested_extensions.data();
  instance_create_info.enabledLayerCount = 0;

  VkResult result = vkCreateInstance(&instance_create_info, nullptr, &instance_);

  if (result != VK_SUCCESS) { std::exit(EXIT_FAILURE); }
}

gsl::span<gsl::czstring> Graphics::GetSuggestExtensions() {
  std::uint32_t glfw_extension_count = 0;
  gsl::czstring* glfw_extensions;

  glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
  return {glfw_extensions, glfw_extension_count};
}

}  // namespace veng