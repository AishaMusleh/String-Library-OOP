#pragma once

#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString() {
		_Value = "";
	}
	clsString(string Value) {
		_Value = Value;
	}

	void SetValue(string Value) {
		_Value = Value;
	}
	string GetValue() {
		return _Value;
	}

	static void PrintFirstLetter(string Phase) {
		bool IsFirstLetter = true;
		for (short i = 0; i < Phase.length(); i++) {
			if (Phase[i] != ' ' && IsFirstLetter) {
				cout << Phase[i] << "\n";
			}
			IsFirstLetter = (Phase[i] == ' ' ? true : false);
		}
	}
	void PrintFirstLetter() {
		PrintFirstLetter(_Value);
	}

	static string CabitalFirstLetter(string Phase) {
		bool IsFirstLetter = true;
		for (short i = 0; i < Phase.length(); i++) {
			if (Phase[i] != ' ' && IsFirstLetter && islower(Phase[i])) {
				Phase[i] = toupper(Phase[i]);
			}
			IsFirstLetter = (Phase[i] == ' ' ? true : false);
		}
		return Phase;
	}
	string CabitalFirstLetter() {
		return CabitalFirstLetter(_Value);
	}

	static string LowerFirstLetter(string Phase) {
		bool IsFirstLetter = true;
		for (short i = 0; i < Phase.length(); i++) {
			if (Phase[i] != ' ' && IsFirstLetter && isupper(Phase[i])) {
				Phase[i] = tolower(Phase[i]);
			}
			IsFirstLetter = (Phase[i] == ' ' ? true : false);
		}
		return Phase;
	}
	string LowerFirstLetter() {
		return LowerFirstLetter(_Value);
	}

	static string CabitalAllLetter(string Phase) {
		for (short i = 0; i < Phase.length(); i++) {
			Phase[i] = toupper(Phase[i]);
		}
		return Phase;
	}
	string CabitalAllLetter() {
		return CabitalAllLetter(_Value);
	}

	static string LowerAllLetter(string Phase) {
		for (short i = 0; i < Phase.length(); i++) {
			Phase[i] = tolower(Phase[i]);
		}
		return Phase;
	}
	string LowerAllLetter() {
		return LowerAllLetter(_Value);
	}

	string InvertAllString() {

		for (int i = 0; i < _Value.length(); i++) {
			_Value[i] = InvertChar(_Value[i]);
		}
		return  _Value;
	}

	static short CountCapitalLetter(string Phase) {
		short countCapital = 0;
		for (int i = 0; i < Phase.length(); i++) {
			if (isupper(Phase[i]))
				countCapital++;
		}
		return  countCapital;
	}
	short CountCapitalLetter() {
		return  CountCapitalLetter(_Value);
	}

	static short CountSmallLetter(string Phase) {
		short countSmall = 0;
		for (int i = 0; i < Phase.length(); i++) {
			if (islower(Phase[i]))
				countSmall++;
		}
		return  countSmall;
	}
	short CountSmallLetter() {
		return CountSmallLetter(_Value);
	}

	static short CountLetter(string Phase, char Letter, bool CaseSensitive = true) {
		short countLetter = 0;
		if (CaseSensitive) {
			for (int i = 0; i < Phase.length(); i++) {
				if (tolower(Phase[i]) == tolower(Letter))
					countLetter++;
			}
		}
		else {
			for (int i = 0; i < Phase.length(); i++) {
				if (Phase[i] == Letter)
					countLetter++;
			}
		}

		return  countLetter;
	}
	short CountLetter(char Letter, bool CaseSensitive = true) {
		return CountLetter(_Value, Letter, CaseSensitive);
	}

	static char InvertChar(char letter) {
		return isupper(letter) ? tolower(letter) : toupper(letter);
	}
	static bool IsVowel(char Letter) {

		Letter = tolower(Letter);
		char Array[5] = { 'a','e','i','o','u' };

		for (char& letter : Array) {
			if (Letter == letter)
				return true;
		}
		return false;
	}

	static short CountVowel(string Phase) {
		short Count = 0;
		for (char i = 0; i < Phase.length(); i++) {
			if (IsVowel(Phase[i]))
				Count++;
		}
		return Count;
	}
	short CountVowel() {
		return CountVowel(_Value);
	}

	static void PrintVowel(string Phase) {
		cout << "Letter Vowel is : \n";

		for (char i = 0; i < Phase.length(); i++) {
			if (IsVowel(Phase[i]))
				cout << Phase[i] << "\t";
		}
	}
	void PrintVowel() {
		PrintVowel(_Value);
	}

	static void PrintWordInPhase(string Phase) {
		short Pos = 0;
		string Delim = " ";
		string Word;
		cout << "\nThe Word in Phase : \n";
		while ((Pos = Phase.find(Delim)) != std::string::npos) {
			Word = Phase.substr(0, Pos);
			if (Word != "")
				cout << Word << "\n";
			Phase.erase(0, Pos + Delim.length());
		}
		if (Phase != "")
			cout << Phase << "\n";
	}
	void PrintWordInPhase() {
		PrintWordInPhase(_Value);
	}

	static short CountWordInPhase(string Phase) {
		short Pos = 0;
		short Count = 0;
		string Delim = " ";
		string Word;
		while ((Pos = Phase.find(Delim)) != std::string::npos) {
			Word = Phase.substr(0, Pos);
			if (Word != "")
				Count++;
			Phase.erase(0, Pos + Delim.length());
		}
		if (Phase != "")
			Count++;
		return Count;
	}
	short CountWordInPhase() {
		return CountWordInPhase(_Value);
	}

	static vector<string> SplitString(string Phase, string Delim) {
		short Pos = 0;
		string Word;
		vector<string> splitWord;
		while ((Pos = Phase.find(Delim)) != std::string::npos) {
			Word = Phase.substr(0, Pos);
			if (Word != "")
				splitWord.push_back(Word);
			Phase.erase(0, Pos + Delim.length());
		}
		if (Phase != "")
			splitWord.push_back(Phase);
		return splitWord;
	}
	vector<string> SplitString(string Delim) {
		return SplitString(_Value, Delim);
	}

	void PrintSplitString(vector<string>& splitWord) {
		cout << "Tokens Number = " << splitWord.size() << "\n";
		for (string& word : splitWord)
			cout << word << "\n";
	}

	static string TirmLeft(string Phase) {
		for (short i = 0; i < Phase.length(); i++) {
			if (Phase[i] != ' ') {
				return Phase.substr(i, Phase.length() - i);
			}
		}
		return "";
	}
	string TirmLeft() {
		return TirmLeft(_Value);
	}

	static string TirmRight(string Phase) {
		for (short i = Phase.length() - 1; i > 0; i--) {
			if (Phase[i] != ' ') {
				return Phase.substr(0, i + 1);
			}
		}
		return "";
	}
	string TirmRight() {
		return TirmRight(_Value);
	}

	static string TirmString(string Phase) {
		return TirmRight(TirmLeft(Phase));
	}
	string TirmString() {
		return TirmString(_Value);
	}

	static string JoinString(vector<string>& splitWord, string Delimiter) {
		string Phase;
		for (string& Word : splitWord) {
			Phase += Word + Delimiter;
		}
		return Phase.substr(0, Phase.length() - Delimiter.length());
	}

	string JoinString(string splitWord[3], short length, string Delimiter) {
		string Phase;
		for (short i = 0; i < length; i++) {
			Phase += splitWord[i] + Delimiter;
		}
		return Phase.substr(0, Phase.length() - Delimiter.length());
	}

	static string ReverseWordInString(string phase) {

		string sRevers = "";
		vector<string> vReverse;
		vReverse = SplitString(phase, " ");

		vector<string>::iterator iter = vReverse.end();

		while (iter != vReverse.begin()) {
			--iter;
			sRevers += *iter + " ";
		}
		sRevers = sRevers.substr(0, sRevers.length() - 1);
		return sRevers;
	}
	string ReverseWordInString() {
		return  ReverseWordInString(_Value);
	}

	static string ReplaceStringCustomFunc(string StringOriginal, string WordOriginal, string WordToReplace, bool MatchCase = true) {
		vector<string> s1;
		s1 = SplitString(StringOriginal, " ");
		if (MatchCase) {
			for (string& Word : s1) {
				if (Word == WordOriginal) {
					Word = WordToReplace;
				}
			}
		}
		else {
			for (string& Word : s1) {
				if (LowerAllLetter(Word) == LowerAllLetter(WordOriginal)) {
					Word = WordToReplace;
				}
			}
		}
		return JoinString(s1, " ");
	}
	string ReplaceStringCustomFunc(string WordOriginal, string WordToReplace, bool MatchCase = true) {
		return  ReplaceStringCustomFunc(_Value, WordOriginal, WordToReplace, MatchCase);
	}

	static string DeleteBunct(string StringOriginal) {
		string StringDelete = "";
		for (short i = 0; i < StringOriginal.length(); i++) {
			if (!ispunct(StringOriginal[i])) {
				StringDelete += StringOriginal[i];
			}
		}
		return StringDelete;
	}
	string DeleteBunct() {
		return  DeleteBunct(_Value);
	}


	__declspec(property(get = GetValue, put = SetValue)) string Value;
};

