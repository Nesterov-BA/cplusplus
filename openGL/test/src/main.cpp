#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader_s.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window, float *br, float *xOff, float *yOff) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (glfwGetKey(window, GLFW_KEY_1)) {
    *br += 0.01;
  }
  if (glfwGetKey(window, GLFW_KEY_2)) {
    *br -= 0.01;
  }
  if (glfwGetKey(window, GLFW_KEY_W)) {
    *yOff += 0.01;
  }
  if (glfwGetKey(window, GLFW_KEY_S)) {
    *yOff -= 0.01;
  }
  if (glfwGetKey(window, GLFW_KEY_D)) {
    *xOff += 0.01;
  }
  if (glfwGetKey(window, GLFW_KEY_A)) {
    *xOff -= 0.01;
  }
}

int main() {
  int success;
  char infoLog[512];
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  std::cout << "a\n";

  GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  Shader ourShader("shaders/3.3.shader.vs", "shaders/3.3.shader.fs");

  float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
  unsigned int VBO;
  glGenBuffers(1, &VBO);

  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  float br = 0;
  float xOff = 0;
  float yOff = 0;
  while (!glfwWindowShouldClose(window)) {
    // input processing
    processInput(window, &br, &xOff, &yOff);
    // render commands
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ourShader.setFloat("brightness", br);
    ourShader.setFloat("xOffset", xOff);
    ourShader.setFloat("yOffset", yOff);
    ourShader.use();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // boilerplate
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  std::cout << "Terminated\n";
  glfwTerminate();
  return 0;
}
