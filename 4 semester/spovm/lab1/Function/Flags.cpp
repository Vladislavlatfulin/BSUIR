#include "Flags.hpp"

void Flags::print_flags() const {
    cout << boolalpha <<
    "l_flag : " << l << endl <<             // link
    "d_flag : " << d << endl <<             // dir
    "f_flag : " << f << endl <<             // file
    "s_flag : " << s << endl;  // sort
}
