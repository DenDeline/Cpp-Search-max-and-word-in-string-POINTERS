#define _CRT_USE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void Solution(char UserInput[]);
int IgnorePunctuation(char CurrentChar);

int main()
{
	char String[100] = {};
	cout << "Enter a string of up to 100 characters: ";
	Solution(gets_s(String));
	return 0;
}

int IgnorePunctuation(char CurrentChar)
{
	char PunctuationChars[] = { ' ','-','!','?','\"','\'', '.', ',','\\','/','\0' };
	for (int i = 0; i < strlen(PunctuationChars); i++)
		if (CurrentChar == PunctuationChars[i])
			return 0;
	return 1;
}

void Solution(char UserInput[])
{
	char* StringHead = UserInput, * StringEnd = &UserInput[strlen(UserInput)];

	if (StringHead != StringEnd)
	{

		char** MaxWord, ** MinWord, ** TempWord;
		MaxWord = MinWord = TempWord = nullptr;

		for (auto iterator = StringHead; iterator != StringEnd; ++iterator)
		{
			if (IgnorePunctuation(*iterator))
			{
				if (MaxWord == nullptr && MinWord == nullptr)
				{
					TempWord = new char* [2];
					TempWord[0] = iterator;

					while (IgnorePunctuation(*iterator) && iterator != StringEnd) { iterator++; }
					TempWord[1] = iterator--;
					MaxWord = MinWord = TempWord;

					TempWord = nullptr;
				}

				else
				{
					TempWord = new char* [2];
					TempWord[0] = iterator;

					while (IgnorePunctuation(*iterator) && iterator != StringEnd) { iterator++; }
					TempWord[1] = iterator--;

					if ((TempWord[1] - TempWord[0]) > (MaxWord[1] - MaxWord[0])) { MaxWord = TempWord; }
					if ((TempWord[1] - TempWord[0]) < (MinWord[1] - MinWord[0])) { MinWord = TempWord; }

					TempWord = nullptr;
				}
			}
		}
		if (MaxWord != nullptr && MinWord != nullptr)
		{
			cout << "Max word: ";
			for (auto iterator = MaxWord[0]; iterator != MaxWord[1]; ++iterator) { cout << *iterator; };
			cout << ". Characters: " << MaxWord[1] - MaxWord[0] << "\n";

			cout << "Min word: ";
			for (auto iterator = MinWord[0]; iterator != MinWord[1]; ++iterator) { cout << *iterator; };
			cout << ". Characters: " << MinWord[1] - MinWord[0] << "\n";
			delete[]MaxWord, MinWord, TempWord, StringHead, StringEnd;
		}
	}
}