#include "Flags.hpp"

void Flags::printFlags() const {
    cout << boolalpha <<
    "l_flag : " << l << endl << // link
    "d_flag : " << d << endl << // dir
    "f_flag : " << f << endl << // file
    "s_flag : " << s << endl;   // sort
}
