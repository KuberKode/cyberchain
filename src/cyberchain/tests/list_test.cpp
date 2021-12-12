
//#define WIN32_MEAN_AND_LEAN
//#define CYBER_INC_STD

#include "../core/list.h"
using namespace std;

int main(void) {
	
	Cyber::Data data = "HELLO WORLD";


	std::cout << "*********LIST**********" << std::endl;
	Cyber::List<Cyber::Data> list;
	std::cout << "*********LIST ADD**********" << std::endl;
	list.Add("Hello");
	list.Add(Cyber::Data("There"));
	list.Add(data);
	std::cout << "*********LIST ITERATION**********" << std::endl;
	for (int i = 0; i < list.Count(); i++) {
		std::cout << list[i] << std::endl;
	}
	std::cout << "*********LIST Get()**********" << std::endl;
	for (int i = 0; i < list.Count(); i++) {
		std::cout << list.Get(i) << std::endl;
	}

#if defined(WIN32_MEAN_AND_LEAN)
	system("pause");
#else
	std::cout << std::endl << "Press any key to continue . . .";
	int gc = getchar();
#endif

	return 0;
}