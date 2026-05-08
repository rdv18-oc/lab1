#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string processSentence(const string& sentence) {
    stringstream ss(sentence);
    string word;
    vector<string> words;
    
    // Разбиение на слова
    while (ss >> word) {
        words.push_back(word);
    }

    if (words.empty()) return "";

    // средняя долина стр
    double totalLen = 0;
    for (const string& w : words) {
        totalLen += w.length();
    }
    double average = totalLen / words.size();

    // Фильтр
    string result;
    for (const string& w : words) {
        if (w.length() >= average) {
            if (!result.empty()) result += " ";
            result += w;
        }
    }
    return result;
}

int main() {
    cout << "Input text:" << endl;
    string input;
    getline(cin, input);

    if (input.length() > 500) {
        cerr << "Error (MAX symbol = 500)" << endl;
        return 1;
    }

    stringstream ss(input);
    string segment;
    string finalResult;

    // разделения на предложения
    while (getline(ss, segment, '.')) {
        string processed = processSentence(segment);
        if (!processed.empty()) {
            if (!finalResult.empty()) finalResult += ". ";
            finalResult += processed;
        }
    }

    if (!finalResult.empty()) cout << "Resukt: " << finalResult << "." << endl;

    return 0;
}