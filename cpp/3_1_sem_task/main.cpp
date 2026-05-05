#include <iostream>
#include <string>
#include <sstream>
#define _VMK_TERM_SEQ '\0'
using namespace std;

char _cur_symb;
istream* _is;
void read_next_symb () { (*_is) >> _cur_symb; }

bool check_g ()
{
	enum state { H, HA, HAB, HABC, HB, HAC, HC, HBC, S, ER };
	state cur_state;
	cur_state = H;

	do {
		read_next_symb();
		switch (cur_state) {
			case H:
				if (_cur_symb == 'b') break;
				if (_cur_symb == 'a') { cur_state = HA; break; }
				cur_state = ER;
				break;
			case HA:
				if (_cur_symb == 'a') { cur_state = HAB; break; }
				if (_cur_symb == 'b') { cur_state = HB; break; }
				cur_state = ER;
				break;
			case HAB:
				if (_cur_symb == 'a') { cur_state = HABC; break; }
				if (_cur_symb == 'b') { cur_state = HBC; break; }
				cur_state = ER;
				break;
			case HABC:
				if (_cur_symb == 'a') { break; }
				if (_cur_symb == 'b') { cur_state = HB; break; }
				if (_cur_symb == _VMK_TERM_SEQ) { cur_state = S; break; }
				cur_state = ER;
				break;
			case HB:
				if (_cur_symb == 'a') { cur_state = HAC; break; }
				if (_cur_symb == 'b') { cur_state = HC; break; }
				cur_state = ER;
				break;
			case HAC:
				if (_cur_symb == 'a') { cur_state = HAB; break; }
				if (_cur_symb == 'b') { cur_state = HB; break; }
				if (_cur_symb == _VMK_TERM_SEQ) { cur_state = S; break; }
				cur_state = ER;
				break;
			case HC:
				if (_cur_symb == 'a') { cur_state = HA; break; }
				if (_cur_symb == 'b') { cur_state = H; break; }
				if (_cur_symb == _VMK_TERM_SEQ) { cur_state = S; break; }
				cur_state = ER;
				break;
			case HBC:
				if (_cur_symb == 'a') { cur_state = HAC; break; }
				if (_cur_symb == 'b') { cur_state = HC; break; }
				if (_cur_symb == _VMK_TERM_SEQ) { cur_state = S; break; }
				cur_state = ER;
				break;
		}
	}
	while (cur_state != S && cur_state != ER);
	return cur_state == S;
}

int main(void) {
	cout << "Hello, please insert consequence of symbols for check: ";
	string input;
	cin >> input;
	input += '\0';
	stringstream ss{input};
	_is = &ss;
	bool result = check_g();
	string result_word = result ? "passed" : "not passed";
	cout << "your sequence " << result_word << endl;
	return 0;
}
