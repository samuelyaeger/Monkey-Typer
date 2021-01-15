// Monkey Typer.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

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


int main()
{

    return 0;

}
