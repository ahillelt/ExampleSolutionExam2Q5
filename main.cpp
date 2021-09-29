#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> get_sentence();

void word_info(vector<string>& list);

void display_list(const vector<string>& list);

const int FIRST_LETTER = 0;
const int LENGTH_OF_ALPHABET = 26;

int main() {

	vector<string> words = get_sentence();

	word_info(words);

	return 0;
}


vector<string> get_sentence() {
	vector<string> words;
	string word;

	cout << "Please enter a non-empty sequence of words, all in lower case" << endl;
	cout << "letters. Each word should be in a separate line." << endl;
	cout << "To indicate the end of the input, enter an empty line." << endl;

	word = "";
	do {
			
		if (!word.empty()) {
		words.push_back(word);
		}

	} while (getline(cin, word) && !word.empty());
		
	return words;
}

void word_info(vector<string>& list) {
	vector<vector<string>> word_frequency;
	int frequent_letter_num;
	int frequent_letter_index;
	char frequent_letter_char;

	word_frequency.resize(LENGTH_OF_ALPHABET);

	
	/* //NO NEED to convert to lower case as the range is a-z not a-Z
	for (int i =0; i < list.size(); i++){
		for (int j = 0; j < list.at(i).size(); j++) {
			list.at(i).at(j) = tolower(list.at(i).at(j));
		}
	}
	*/

	for (int i = 0; i < list.size(); i++) {

		int alphabet_value = list.at(i).at(FIRST_LETTER ) - static_cast<int>('a');
		word_frequency.at(alphabet_value).push_back(list.at(i));
	
	}

	frequent_letter_num = word_frequency.at(FIRST_LETTER).size();
	frequent_letter_index = FIRST_LETTER;

	for (int i = 0; i < word_frequency.size(); i++) {

		if (word_frequency.at(i).size() > frequent_letter_num) {
			frequent_letter_num = word_frequency.at(i).size();
			frequent_letter_index = i;
		}

	}

	frequent_letter_char = static_cast<char>(frequent_letter_index + static_cast<int>('a'));
	cout << "The most frequent first letter is: "<< frequent_letter_char << endl;

	cout << "The words starting with " << frequent_letter_char << " are: ";
	display_list(word_frequency.at(frequent_letter_index));

}

void display_list(const vector<string>& list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list.at(i) << " ";
	}
}
