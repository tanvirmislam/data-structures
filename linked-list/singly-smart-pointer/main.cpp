#include "List.h"

void test1() {
    using namespace std;
    cout << "\n\tTest 1\n" << endl;

    List<int> aList;

    for(int i = 0; i < 5; i++) {
      std::cout << "Addind at front: " << i << std::endl;
      aList.add_front(i);
    }

    cout << "\n" << endl;
    aList.forEach(std::function <void (const int&)> ([](const int& v)
                                                    {
                                                        cout << v << " ";
                                                    }));
    cout << "\n" << endl;

    for(int i = 10; i < 20; i++) {
      std::cout << "Addind at back: " << i << std::endl;
      aList.add_back(i);
    }

    cout << "\n" << endl;
    aList.forEach(std::function <void (const int&)> ([](const int& v)
                                                    {
                                                        cout << v << " ";
                                                    }));
    cout << "\n" << endl;
}


void test2() {
    using namespace std;
    cout << "\n\tTest 2\n" << endl;

    List<unique_ptr<int>> aList;

    std::cout << "Addind at front: " << 7 << std::endl;
    aList.add_front(make_unique<int>(7));

    for(int i = 0; i < 10; i++) {
        std::cout << "Addind at front: " << i << std::endl;
        aList.add_front(make_unique<int>(i));
    }

    cout << "\n" << endl;
    aList.forEach(std::function <void (const unique_ptr<int>&)> ([](const unique_ptr<int>& v)
                                                                {
                                                                    cout << *v << " ";
                                                                }));
    cout << "\n" << endl;


    for(int i = 100; i < 110; i++) {
        std::cout << "Addind at back: " << i << std::endl;
        aList.add_back(make_unique<int>(i));
    }

    cout << "\n" << endl;
    aList.forEach(std::function <void (const unique_ptr<int>&)> ([](const unique_ptr<int>& v)
                                                                {
                                                                    cout << *v << " ";
                                                                }));
    cout << "\n" << endl;
}


int main() {
    test1(); std::cout << "\n\n" << std::endl;
    test2(); std::cout << "\n\n" << std::endl;
    getchar();
    return 0;
}
