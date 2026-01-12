#include "vmk_box.hpp"
#include "vmk_stack.hpp"

using namespace vmk;

int main() {
	// 1)
	std::cout << "started (1)" << std::endl;
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
	std::cout << std::endl << "started (2)" << std::endl;
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
	std::cout << std::endl << "started (3)" << std::endl;
	Body* box_3 = new Box(1, 2, 3);
	std::cout << (box_3 -> area()) << std::endl;
	delete(box_3);

	// 4)
	std::cout << std::endl << "started (4)" << std::endl;
	WBox* box_4 = new WBox(1, 2, 3, 1, 2);
	std::cout << (box_4 -> area()) << std::endl;
	delete (box_4);
	
	WBox* box_4_2 = new WBox(1, 2, 3, 1);
	std::cout << (box_4_2 -> area()) << std::endl;
	delete (box_4_2);

	// 5)
	std::cout << std::endl << "started (5)" << std::endl;
	HBox* box_5 = new HBox(1, 2, 3, 1);
	std::cout << (box_5 -> area()) << std::endl;
	delete(box_5);

	//6
	std::cout << std::endl << "started (6)" << std::endl;
	WHBox* box_6 = new WHBox(1, 2, 3, 1, 2, 1);
	std::cout << (box_6 -> area()) << std::endl;
	delete(box_6);

	//7
	std::cout << std::endl << "started (7)" << std::endl;
	try {
		WHBox* box_7 = new WHBox(0, 2, 3, 1, 2, 1);
	} catch(...) {
		std::cout << "got exception" << std::endl;
	}
	
	//8
	std::cout << std::endl << "started (8)" << std::endl;
	Stack<int> stack_8;
	stack_8.push(2);
	stack_8.push(3);
	std::cout << stack_8.top_element() << std::endl;
	std::cout << stack_8.pop() << std::endl;
	std::cout << stack_8.top_element() << std::endl;

	Stack<double> stack_8_2;
	stack_8_2.push(1.2);
	stack_8_2.push(4.5);
	std::cout << stack_8_2.top_element() << std::endl;
	std::cout << stack_8_2.pop() << std::endl;
	std::cout << stack_8_2.top_element() << std::endl;

	Stack<Box> stack_8_3;
	Box box_8(1, 2, 3);
	Box box_8_2(2, 3, 4);
	stack_8_3.push(box_8);
	stack_8_3.push(box_8_2);
	std::cout << (stack_8_3.top_element().area()) << std::endl;
	
	return 0;
}
