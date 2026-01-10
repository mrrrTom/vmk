#include <iostream>

namespace vmk {
	class Body {
	public:
		virtual int area() = 0;
	};

	class Box : public Body {
	private:
		int _length;
		int _width;
		int _height;
	public:
		Box(int length, int width, int height) {
			_length = length;
			_width = width;
			_height = height;
		}

		Box(const Box &src) : Box(src._length, src._width, src._height) { 
			std::cout << "called copy constructor" << std::endl;
		}

		Box(int length, int height) : Box(length, length, height) {	}

		Box(int length) : Box(length, length) {	}

		~Box() { std::cout << "Called for box destructor" << std::endl;	}
		
		Box &operator = (const Box &src) {
			std::cout << "called assign operator" << std::endl;
			if (this != &src) {
				this -> _length = src._length;
				this -> _width = src._width;
				this -> _height = src._height;
			}

			return *this;
		}

		Box operator++() {
			this -> _length++;
			this -> _width++;
			this -> _height++;
			Box result(*this);
			return result;
		}

		Box operator++(int) {
			Box result(*this);
			this -> _length++;
			this -> _width++;
			this -> _height++;
			return result;
		}
		
		friend Box operator+(const Box& b1, const Box& b2);

		int get_length() { return this -> _length; }

		int get_width() { return this -> _width; }

		int get_height() { return this -> _height; }

		void set_length(int length) { this -> _length = length;	}

		void set_width(int width) {	this -> _width = width; }

		void set_height(int height) { this -> _height = height;	}

		virtual int area() override {
			int bottom = _length * _width;
			int side_1 = _length * _height;
			int side_2 = _width * _height;
			int result = 2 * bottom + 2 * side_1 + 2 * side_2;
			return result;
		}
		   
	};

	Box operator+(const Box& b1, const Box& b2) {
		Box result(b1._length + b2._length, 
				b1._width + b2._width,
				b1._height + b2._height);
		return result;
	}

	class WBox : public Box {
	private:
		int _w_length;
		int _w_width;
	public:
		WBox(int length, int width, int height, int w_length, int w_width) 
		: Box (length, width, height) {
			_w_length = w_length;
			_w_width = w_width;
		}

		WBox(int length, int width, int height, int w_length)
			: Box(length, width, height) {
				_w_length = w_length;
				_w_width = w_length;
		}

		int area() override {
			int w_area = _w_length * _w_width;
			int result = Box::area() - w_area;
			return result;
		}
	};

	class HBox : public Box {
		
	};
}
