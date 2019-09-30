#include <iostream>
#include <string>
#include "image.h"

using namespace std;

int menu()
{
	int option;
	cout << "Menu:\n";
	cout << "-----\n";
	cout << "1. Store data into image.\n";
	cout << "2. Retrieve data from image.\n";
	cout << "3. Inspect image.\n";
	cout << "4. Scrub image.\n";
	cout << "0. Quit.\n";

	cin >> option;
	if (option >= 0 && option <= 4)
	{
		return option;
	}
	else
		return -1;
}

void inspectImage(string fileName)
{
	struct Image img = { 0, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	if (ReadImage(fileName.c_str(), &img))
	{
		cout << "Width: " << img.NofC << "\tHeight: " << img.NofR << endl;
		cout << "Capacity: "<< img.capacity << endl;

		if (img.bytesEmbedded > 0 && img.bytesEmbedded <= img.capacity)
			cout << "Stored: " << img.bytesEmbedded <<  endl;
		else
			cout << "Stored: none\n";
		cout << endl;
	}
	delete[] img.red;
	delete[] img.green;
	delete[] img.blue;
	delete[] img.gray;
}

void extractImage(string fileName)
{
	struct Image img = { 0, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	string outputImageFile;

	Buffer b;
	byte *buffer;
	if (ReadImage(fileName.c_str(), &img))
	{
		if (img.bytesEmbedded > 0 && img.bytesEmbedded <= img.capacity)
		{
			cout << "Output text filename: ";
			cin >> outputImageFile;

			buffer = new byte[img.bytesEmbedded];
			for (int i = 0; i < img.bytesEmbedded; i++)
			{
				buffer[i] = extractByte(&img);
			}
			b.size = img.bytesEmbedded;
			b.data = buffer;
			WriteBinaryFile(outputImageFile.c_str(), b);
			delete[] buffer;
		}
		else
			cout << "stored: none\n";
	}
}

int main(int argc, char *argv[])
{
	struct Buffer b = { NULL, 0, 0 };
	struct Image img = { 0, NULL, NULL, NULL, NULL, 0, 0 };
	
	string inputImageFile, inputTextFile, outputImageFile;
	int isValid = 1;
	int option = 0;

	if (argc == 2)
	{
		// read image file into the image buffer img
		inspectImage(argv[1]);
		
	}
	else
	{
		while (isValid)
		{
			option = menu();
			switch (option)
			{
			case 1:
				cout << "Input image filename: ";
				cin >> inputImageFile;
				if (ReadImage(inputImageFile.c_str(), &img))
				{
					cout << "capacity: " << img.capacity << endl;
					cout << "Input text filename: ";
					cin >> inputTextFile;
					
					if (ReadBinaryFile(inputTextFile.c_str(), &b))
					{
						cout << b.size << " bytes to store." << endl;
						if (b.size <= img.capacity)
						{
							cout << "Output image filename: ";
							cin >> outputImageFile;
							for (int i = 0; i < b.size; i++)
							{
								embedByte(&img, b.data[i]);
							}
							WriteImage(outputImageFile.c_str(), img, b.size);
						}
						else
						{
							cout << "Image file does not have enough capacity\n" << endl;
						}
					}
				}
				break;
			case 2:
				cout << "Image filename: ";
				cin >> inputImageFile;
				extractImage(inputImageFile);
				break;
			case 3:
				cout << "Image filename: ";
				cin >> inputImageFile;
				inspectImage(inputImageFile);
				break;
			case 4:
				cout << "Image filename: ";
				cin >> inputImageFile;
				if (ReadImage(inputImageFile.c_str(), &img))
				{
					for (int i = 0; i < img.capacity; i++)
					{
						embedByte(&img, 0);
					}
					WriteImage(inputImageFile.c_str(), img, 0);
					cout << "Scrubbed.\n";
				}
				break;
			case 0:
				isValid = false;
				break;
			}
		}
	}
	
	return 0;
}
