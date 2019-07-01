// The whole point of this application to add and remove the SMC header from a .smc SNES rom file.

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>




int main(int argc, char* argv[])
{
	// Opening both file streams, will check for success at a later date
	std::ifstream romfile{"snes.smc", std::ios::binary};
	std::ofstream outfile{"snes.sfc", std::ios::binary};

	// Getting file size with the 512 byte header
	romfile.seekg(0, std::ios::end);
	unsigned long fileSize = romfile.tellg();

	unsigned long headerSize = fileSize % 1024; // Determining header size in bytes using a modulo

	unsigned long outSize = fileSize - headerSize;

	char buffer[outSize]; // Creating a buffer using the size variable

	romfile.seekg(headerSize, std::ios::beg); // Set cursor position to end of SMC header

	romfile.read(buffer, outSize); // Read the files contents into buffer, starting at offset

	outfile.write(buffer, outSize); // Write the contents of the buffer into the output file

	return 0;
}
