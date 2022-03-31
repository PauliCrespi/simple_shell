#include <sys/types.h>
#include <iostream>
#include <boost/integer_traits.hpp>

using namespace std;

int main ()
{
    cout << "pid_t max = " << boost::integer_traits<pid_t>::const_max << endl;
}
