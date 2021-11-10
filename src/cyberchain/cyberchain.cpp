// cyberchain.cpp : Defines the entry point for the application.
//

//#define WIN32_MEAN_AND_LEAN
//#define CYBER_INC_STD

#include "cyberchain.h"

using namespace std;

int main()
{
	Cyber::Data data("KuberKode CyberChain - Work In Progress");

	cout << data << endl;

#if defined(WIN32_MEAN_AND_LEAN)
	system("pause");
#else
	std::cout << std::endl << "Press any key to continue . . .";
	int gc = getchar();
#endif
	return 0;
}
