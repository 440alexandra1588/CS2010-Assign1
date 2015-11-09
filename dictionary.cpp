#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;
const int MAXWORD = 20;
const int MAXLEN = 15;

char dictionary[MAXWORD][MAXLEN];
char buffer[256];
int freq[MAXWORD] = {0};
int currentLetter = 0;
int numWords = 0;





int main() {

	char ch;
	bool newWord = false;
        int i;
	bool bigWord = false;

	while( cin.good() )
	{

		ch = cin.get();

		if( isalpha(ch) )  
		{
			ch = tolower(ch);
			dictionary[numWords][currentLetter++] = ch;
			if(currentLetter >= MAXLEN)
				bigWord = true;
			newWord = true;
		}
		else

			if (newWord)
			{
				dictionary[numWords][currentLetter] =  '\0';
				for( i = 0; i <numWords; i++) {
					if(!strcmp(dictionary[i], dictionary[numWords]))
                                                break;
				}
                                if(numWords >= MAXWORD){
					cout<< "WARNING!  No more Words permitted inside dictionary.Words collected before overflow 	: " << endl;
						break;
				}
				if(i == numWords) {
                                        freq[numWords]++;
                                        numWords++;      
                                } else {
                                        freq[i]++;
                                }            
				
				currentLetter = 0;
				newWord = false;
			}
}
	if (bigWord) cout << "WARNING! You've input words that has exceeded the  number of characters permitted, printing what could fit inside the dictionary. \n" << endl;	
	cout<< "Word			Frequency" << endl << "--------------------------------" << endl;
	for(int i = 0; i < numWords; i++)
	{
		cout << dictionary[i] << "                              " << freq[i] <<  endl;
	} 
	return 0;
}
