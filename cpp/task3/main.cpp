#include "vmk_box.hpp"
using namespace vmk;

int main() {
	// 1)
	Box* box_1 = new Box(1, 2, 3);
	std::cout << (box_1 -> get_width()) << std::endl;
	box_1 -> set_width(4);
	std::cout << (box_1 -> get_width()) << std::endl;
	std::cout << (box_1 -> area()) << std::endl;
	delete(box_1);
	
	Box* cube_1 = new Box(1);
	std::cout << (cube_1 -> get_height()) << std::endl;
	Box* cube_2 = new Box(*cube_1);
	delete(cube_1);
	std::cout << (cube_2 -> get_width()) << std::endl;
	delete(cube_2);

	// 2)
	Box* box_2 = new Box(1, 2, 3);
	Box box_2_2(1);
	std::cout << (box_2_2.area()) << std::endl;
	box_2_2 = *box_2;
	std::cout << (box_2_2.area()) << std::endl;
	delete(box_2);

	Box* box_2_3 = new Box(1, 2, 3);
	std::cout << (box_2_3 -> area()) << std::endl;
	(*box_2_3)++;
	std::cout << (box_2_3 -> area()) << std::endl;
	
	Box* box_2_4 = new Box(1, 2, 3);
	Box box_2_5 = *box_2_3 + *box_2_4;
	std::cout << (box_2_5.get_length()) << std::endl;
	delete(box_2_4);
	delete(box_2_3);

	// 3)
	Body* box_3 = new Box(1, 2, 3);
	std::cout << (box_3 -> area()) << std::endl;
	delete(box_3);

	// 4)
	WBox* box_4 = new WBox(1, 2, 3, 1, 1);
	std::cout << (box_4 -> area()) << std::endl;
	delete (box_4);

	return 0;
}
