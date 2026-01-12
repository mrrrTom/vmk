#include <iostream>
#include <stdexcept>
#include <climits>

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
		Box() {}
		Box(int length, int width, int height) {
			if (length <= 0 || width <= 0 || height <= 0) {
				throw std::runtime_error("box cannot have zero or less side!");
			}

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
			if (_length == INT_MAX ||
					_width == INT_MAX ||
					_height == INT_MAX) {
				throw std::runtime_error("wrong value to increase!");
			}

			this -> _length++;
			this -> _width++;
			this -> _height++;
			Box result(*this);
			return result;
		}

		Box operator++(int) {
			if (_length == INT_MAX ||
					_width == INT_MAX ||
					_height == INT_MAX) {
				throw std::runtime_error("wrong value to increase!");
			}

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

	class WBox : virtual public Box {
	private:
		int _w_length;
		int _w_width;
	public:
		WBox(int length, int width, int height, int w_length, int w_width) 
		: Box (length, width, height) {
			if (w_length <= 0 || w_width <= 0) {
				throw std::runtime_error("size cannot be zero or less!");
			}

			int w_area = w_length * w_width;
			if ((w_length > length && w_length > width) ||
					(w_width > length && w_width > width) ||
					(w_area > (length * height) && w_area > (width * height))) {
				throw std::runtime_error("very big window!");
			}
			
			_w_length = w_length;
			_w_width = w_width;
		}

		WBox(int length, int width, int height, int w_length)
			: WBox(length, width, height, w_length, w_length) {
		}

		virtual int area() override {
			int w_area = _w_length * _w_width;
			int result = Box::area() - w_area;
			return result;
		}
	};

	class HBox : virtual public Box {
	private:
		Box* _top;
	public:
		HBox(int length, int width, int height, int h_height)
			: Box (length, width, height) {
				if (h_height <= 0) {
					throw std::runtime_error("size cannot be zero or less!");
				}

				_top = new Box(length, width, h_height);
			}

		HBox(int length, int height, int h_height)
			: HBox(length, length, height, h_height) {
		}

		HBox(int length, int h_height) 
			: HBox(length, length, length, h_height) { }

		~HBox() {
			delete(_top);
		}

		virtual int area() override {
			int h_area = _top -> area();
			int result = Box::area() + h_area;
			return result;
		}
	};

	class WHBox : public WBox, public HBox {
	public:
		WHBox(int length, int width, int height, 
				int w_length, int w_width, 
				int h_height)
			: Box(length, width, height),
			WBox(length, width, height, w_length, w_width),
			HBox(length, width, height, h_height) {
		}

		WHBox(int length, int width, int height,
				int w_length,
				int h_height)
			: Box(length, width, height),
			WBox(length, width, height, w_length),
			HBox(length, width, height, h_height) {
			}

		int area() override {
			int box_area = Box::area();
			int window_area = box_area - WBox::area();
			int top_area = HBox::area() - box_area;
			int result = box_area + top_area - window_area;
			return result;
		}
	};
}
