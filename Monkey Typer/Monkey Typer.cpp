// Monkey Typer.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

int failedWords;
int successfulWords;

vector<string> dictionary;

void buildDictionary() {

    ifstream stream;
    stream.open("engmix.txt");

    string word;

    int i = 0;
    while (!stream.eof())
    {
        getline(stream, word);
        dictionary.push_back(word);
        i++;

    }

    stream.close();

}

string generateWord() {

    string word;
    char letter;
    int length = rand() % 10 + 1;


    for (int i = 0; i < length; i++)
    {
        letter = 'a' + rand() % 26;
        word += letter;
    }

    return word;
}

vector<string> buildSentence() {

    string word;
    vector<string> words;

    int sentenceLength = rand() % 10 + 5;

    for (int i = 0; i < sentenceLength; i++) {

        bool realWord = false;

        while (!realWord) {
            word = generateWord();
            if ((find(dictionary.begin(), dictionary.end(), word) != dictionary.end()) && !(find(words.begin(), words.end(), word) != words.end())) {
                realWord = true;
                words.push_back(word);
            }
            else {
                failedWords++;
            }
        }

    }

    successfulWords += sentenceLength;


    return words;

}

void displaySentence(vector<string> sentence) {

    sentence.at(0)[0] = toupper(sentence.at(0)[0]);

    for (int i = 0; i < sentence.size(); i++) {

        if (i == sentence.size() - 1) {
            cout << sentence.at(i) << ". ";
        }
        else {
            cout << sentence.at(i) << " ";
        }
    }

}

int main()
{

    failedWords = 0;
    successfulWords = 0;
    int numSentences;

    srand(time(NULL));

    buildDictionary();

    cout << "Input desired number of sentences: ";

    cin >> numSentences;

    for (int i = 0; i < numSentences; i++) {
        vector<string> sentence = buildSentence();
        displaySentence(sentence);
    }

    cout << endl << "Failed words: " << failedWords << endl;
    cout << "Successful words: " << successfulWords << endl;
    cout << "Word generation success rate: " << (successfulWords / ((double)failedWords + successfulWords)) * 100 << "%" << endl;

    return 0;

}
