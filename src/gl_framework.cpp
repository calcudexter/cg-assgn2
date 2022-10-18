#include "gl_framework.hpp"
#include "hierarchy_node.hpp"

extern GLfloat c_xrot,c_yrot,c_zrot;
extern bool enable_perspective;
extern csX75::HNode* node1, *node2, *node3,*curr_node;
namespace csX75
{
  //! Initialize GL State
  void initGL(void)
  {
    //Set framebuffer clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //Set depth buffer furthest depth
    glClearDepth(1.0);
    //Set depth test to less-than
    glDepthFunc(GL_LESS);
    //Enable depth testing
    glEnable(GL_DEPTH_TEST);
  }
  
  //!GLFW Error Callback
  void error_callback(int error, const char* description)
  {
    std::cerr<<description<<std::endl;
  }
  
  //!GLFW framebuffer resize callback
  void framebuffer_size_callback(GLFWwindow* window, int width, int height)
  {
    //!Resize the viewport to fit the window size - draw to entire window
    glViewport(0, 0, width, height);
  }
  
  //!GLFW keyboard callback
  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
  {
    //!Close the window if the ESC key was pressed
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
    if (key == GLFW_KEY_P && action == GLFW_PRESS)
      enable_perspective = !enable_perspective;   
    else if (key == GLFW_KEY_A  && action == GLFW_PRESS | GLFW_REPEAT)
      c_yrot -= 1.0;
    else if (key == GLFW_KEY_D  && action == GLFW_PRESS | GLFW_REPEAT)
      c_yrot += 1.0;
    else if (key == GLFW_KEY_W  && action == GLFW_PRESS | GLFW_REPEAT)
      c_xrot -= 1.0;
    else if (key == GLFW_KEY_S  && action == GLFW_PRESS | GLFW_REPEAT)
      c_xrot += 1.0;        
    else if (key == GLFW_KEY_Q  && action == GLFW_PRESS | GLFW_REPEAT)
      c_zrot -= 1.0;
    else if (key == GLFW_KEY_E  && action == GLFW_PRESS | GLFW_REPEAT)
      c_zrot += 1.0;   
  }
};  
  


