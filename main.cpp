#include "ncmcrypt.h"

#include <stdexcept>

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		std::cout << "please input file path!" << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		try
		{
			NeteaseCrypt crypt(argv[i]);
			crypt.Dump();
			crypt.FixMetadata();

			std::cout << crypt.dumpFilepath() << std::endl;
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "invalid file, " << argv[i] << std::endl;
		}
		catch (const std::bad_alloc&)
		{
			try
			{
				std::cout << "Out of memory, exiting.";
			}
			catch (...) {}
			return EXIT_FAILURE;
		}
		catch (...)
		{
			std::cout << "unexcept exception!" << std::endl;
			return EXIT_FAILURE;
		}
	}
	return 0;
}