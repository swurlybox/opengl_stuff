#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/* Helper functions. */
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);


int main() {

    /* Setup Code. */

    /* Initialize a Window. */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for macOS
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL",
        NULL, NULL);
    if (window == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    /* Initialize GLAD to connect defined function pointers to the addresses
     * of the GPU-driver specific implementations of those OpenGL functions. */
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }

    /* Define a viewport for the rendering window. */
    glViewport(0, 0, 800, 600);

    /* Attach callbacks (event-handlers) */

    /* Resize the viewport when window is resized. */
    /* Whenever GLFW detects a window-resize event from the user, it will
     * call the registered callback function (framebuffer_size_callback),
     * which resizes our viewport according to the window's height & width.*/
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Render loop */
    while(!glfwWindowShouldClose(window)) {
        /* processes input: glfwPollEvents also processes inputs, but only
         * responds to them if we hookup a callback to the window context
         * via specific functions (i.e. glfwSetFramebufferSizeCallback) */
        processInput(window);

        /* double-buffer: rendering commands draw to the back buffer, while
         * the front buffer is displayed on the screen. By swapping these
         * buffers, we display the updated display after rendering on an
         * iteration. */
        glfwSwapBuffers(window);
        
        /* checks if any events triggered, updates the window state, and
         * calls the corresponding functions (which we can register via
         * callback methods). */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
    printf("window resizing: %d, %d\n");
}

void processInput(GLFWwindow *window) {
    /* polling for esc-key press: close the window. */
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
        printf("esc detected! closing\n");    
    }
}
