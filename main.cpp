#include "oglm.hpp"
#include "transform.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main() {
	glm::mat4 test1 =
	    glm::lookAt(glm::vec3(10.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f),
	                glm::vec3(0.0f, 1.0f, 0.0f));
	oglm::mat4<float> test2 = oglm::lookAt(oglm::vec3<float>(10.0f, 0.0f, 1.0f),
	                                       oglm::vec3<float>(0.0f, 0.0f, 0.0f),
	                                       oglm::vec3<float>(0.0f, 1.0f, 0.0f));
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
