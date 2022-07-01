#include "oglm.hpp"
#include "transform.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main() {
  glm::mat4 test1 = glm::perspective(45.0f, 1920.0f/1080.0f,0.0f, 100.0f );
  oglm::mat4<float> test2 = oglm::perspective(45.0f, 1920.0f/1080.0f,0.0f, 100.0f );
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << test1[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << test2.arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
