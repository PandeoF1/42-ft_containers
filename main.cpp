#include "includes/ft_containers.hpp"
#include <vector>
int main() {
	// method 3
	ft::vector<int> vector3(5, 12);
	std::cout<< vector3[0] << std::endl;
	std::cout<< vector3[1] << std::endl;
	std::cout<< vector3[2] << std::endl;
	std::cout<< vector3[3] << std::endl;
	vector3.resize(8);
	//std::cout<< vector3.begin() << std::endl;
	std::cout << "a" << std::endl;
	ft::vector<std::string> vector4(5, "hello");
	std::cout << "b" << std::endl;
	vector4.push_back("world");
	std::cout << "c" << std::endl;
	std::cout<< vector4[0] << std::endl;
	std::cout<< vector4[1] << std::endl;
	std::cout<< vector4[2] << std::endl;
	std::cout<< vector4[4] << std::endl;
	std::cout<< vector4[5] << std::endl;
	std::cout << "\nvector3 = ";

	// ranged loop
	//for (int i : vector3) {
	//  std::cout << i << "  ";
	//}
	std::cout << std::endl;
	std::cout << "hey" << std::endl;
	return 0;
}