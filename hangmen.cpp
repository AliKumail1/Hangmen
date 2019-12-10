
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
bool open_letter(char, string, string&); // Function declaration of bool tpye which takes three para 
string InputGuessWord(); // Function declaration which inputs a guess word

int main()
{
	system("color 0a"); // changes text color in cmd
	const int attempt = 8; // Intially attempt is assigned with value of 8
	char letter; // variable letter of char type which stores guess letter
	int guesses = 0; // initially no. of guesses is zero
	string word; // variable string which stores guess word
	string my_wrd = ""; // variable my_wrd which displayes hyphen and guessed words
	cout << "--------------------------------------" << endl;
	cout << "\n\t\tHangman\n" << endl;
	cout << "--------------------------------------" << endl << endl;
	cout << "Note : Enter word in small letters." << endl;
	word = InputGuessWord(); // taking input of guess word
	for (int i = 0; i < word.length(); i++) // for loop which assign var my_wrd with hyphens equal to word length
		my_wrd += "-";
	cout << endl;
	cout << "\nEnter one letter in one time:" << endl;
	
	while (guesses < attempt) // loops continue as long is guess is less than attempt
	{
		cout << my_wrd<<endl;
		cout << "\nWhat is the letter:";
		cin >> letter;
		bool same_letter = open_letter(letter, word, my_wrd); // variable same_letter bool type 
		if (same_letter) // if same_letter is 1 i.e true execute this
		{
			cout << "Guessed Correctly! Now carry on guess more:" << endl;
		}
		else
		{
			cout << "Next try! You entered a false letter:" << endl;
			guesses++;
		}
		cout << "You have " << attempt - guesses << " Guesses left" << endl;
		if (word == my_wrd)
		{
			cout << "\n--------------------------------------" << endl;
			cout << word << endl <<  "Congratulations you Won!..." << endl;
			break;
		}
	}
	if (guesses == attempt)
	{
		cout << "You lose!Try again:" << endl;
		cout << "The word was given" << word << endl;
	}
	system("pause");
	return 0;
}
bool open_letter(char letter, string word, string& guessword)
{
	int i ;
	int same = 0;
	int lenght= word.length();
	for (i = 0; i < lenght; i++)
	{
		if (letter == guessword[i])
			return false;
		if (letter == word[i])
		{
			guessword[i] = letter ;
			same++;
		}
	}
	return same > 0;

	}

string InputGuessWord(){
	char word[100];
	int i;
	char a;
	int no = 0;
	cout << " Enter Guess Word : ";
	for(i=0;;){
		a = getch();
		if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
			word[i] = a;
			++i;
			cout << "*";
			no++;
		}
		if(a == '\b' && a >=1){
			cout << "\b \b";
			
			--i;
			word[i] = a;
			
		}
		if(a == '\r'){
			word[i] = '\0';
			break;
		}
	}
	string text = "";
	for(i = 0; i < no;i++)
		text = text + word[i];
		
	return text;
	
}


