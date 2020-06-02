#include <iostream>

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {

	glViewport(0, 0, width, height);

}

// ���������� ������� ������
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action != GLFW_RELEASE) { // ���� ������� ������
		switch (key) { // ����������� �������������� �������
		case GLFW_KEY_ESCAPE: // ���� ������� - Escape
		// �������������, ��� ���� window ������ ���� �������
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		default:
			break;
		}
	}
}
int main() {
	glfwInit();

	// �������� ����������� ��������� ������ OpenGL.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // ����� �� ���������� �����
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // ����� ����� ���������� �����
	// ������� ����
	GLFWwindow* window = glfwCreateWindow(800, 600, "Task 7. Martyshin Ivan", NULL, NULL);

	if (window == NULL) { // ���� ������ �� ���� �� �������
		std::cout << "����� glfwCreateWindow ���������� ��������." << std::endl;
		glfwTerminate(); // ��������� ������ GLFW
		return -1; // ��������� ���������
	}
	glfwMakeContextCurrent(window); // ������ ���� window �������� (�������)
	// ���������� ����������� ������� Resize
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// ���������� ����������� ������� ������
	glfwSetKeyCallback(window, key_callback);


	// ������������� GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "�� ������� ��������� GLAD" << std::endl;
		glfwTerminate(); // ��������� ������ GLFW
		return -1; // ��������� ���������
	}

	// �������� �������� ��������� � ����
// (0, 0) - ���������� ������ ������� ����, 800x600 - ������� ���� � ��������
	glViewport(0, 0, 800, 600);

//=====================================================================
						// ��������� ������
//=====================================================================

	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main() {\n"
		" gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\0";
	//=====================================================================

	GLuint vertexShader; // ��������� ������ - ��������� ������
	vertexShader = glCreateShader(GL_VERTEX_SHADER); // ������� ������

	// ����������� �������� ��� � ���������� �������
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader); // ����������� ������
	GLint success; // ��������� ����������
	// ����������� ������ ���������� ������� � ���������� success
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) { // ���� ���������� ������ � �������
		GLchar infoLog[512]; // ������� ��������� ��� ��������� �� ������
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog); // ����������� ���������
		// ������� ��������� �� ������ �� �����
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

//======================================================
			// ����������� ������
//======================================================
	const char* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 color;\n"
		"void main() {\n"
		" color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
	//=======================================================
	GLuint fragmentShader; // ��������� ������ - ����������� ������
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // ������� ������
	// ����������� �������� ��� � ���������� �������
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader); // ����������� ������
	// ����������� ������ ���������� ������� � ��������� ����� ���������� success
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) { // ���� ���������� ������ � �������
		GLchar infoLog[512]; // ������� ��������� ��� ��������� �� ������
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog); // ����������� ���������
		// ������� ��������� �� ������ �� �����
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// ��������� ���������
	GLuint shaderProgram; // ������������� ��������� ���������
	shaderProgram = glCreateProgram(); // ������� ����������� ������

	glAttachShader(shaderProgram, vertexShader); // ������������ ��������� ������
	glAttachShader(shaderProgram, fragmentShader); // ����������� ������
	glLinkProgram(shaderProgram); // ���������� ���������

	// ����������� ������ ���������� ��������� ��������� � ���������� success
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) { // ���� ���������� ������ � �������
		GLchar infoLog[512]; // ������� ��������� ��� ��������� �� ������
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog); // ����������� ���������
		// ������� ��������� �� ������ �� �����
		std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	}

	// �������� ��������� ��������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//==============================================
// ����� �������� ������ ��� ���������
//==============================================
	GLfloat vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f
	};

	GLuint vertexArray; // ������ ���������� �������
	// ������� ��������� ������, ������������� �������� ����������� vertexArray
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray); // ������ �������� ��������� ������

	GLuint vertexBuffer; // ������������� ��������� �������
	// ������� �������� ������, ������������� �������� ����������� vertexBuffer
	glGenBuffers(1, &vertexBuffer);
	// �������� vertexBuffer � GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0); // ��������� ��������� 0 ��� �������
	glBindBuffer(GL_ARRAY_BUFFER, 0); // ������� ��������� �������

	while (!glfwWindowShouldClose(window)) { // ���� ���� window �� ������ ���������

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // ��������� ���� �������
		glClear(GL_COLOR_BUFFER_BIT); // ������� ����� �������� ������

		glUseProgram(shaderProgram); // ��������� ��������� shaderProgram ������ ��������
		glBindVertexArray(vertexArray); // ������ �������� ��������� ������
		glBindVertexArray(0); // ��������� ��������� ������


		glfwSwapBuffers(window); // �������� ������� ������ �����������
		glfwPollEvents(); // ���������, ��������� �� �����-�� �������
	}

	glfwTerminate(); // ��������� ������ GLFW


	return 0;
}
