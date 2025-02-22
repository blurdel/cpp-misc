#include <iostream>
#include <boost/array.hpp>

using namespace std;
int main()
{
    boost::array<int, 4> arr = {{1,2,3,4}};
    cout << "hi" << arr[0];
    
    printDirs("~/Temp");
    
    return 0;
}

void printDirs(std::string pDir)
{
    path p(pDir);

    if (is_directory(p)) {
        std::cout << p << " is a directory containing:\n";

        for(auto& entry : boost::make_iterator_range(directory_iterator(p), {}))
            std::cout << entry << "\n";
    }
}
