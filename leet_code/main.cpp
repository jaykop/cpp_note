#include "maxScoreWords.h"

int main() {

	vector<string> words = { "dog", "cat", "dad", "good" };
	vector<char> letters = { 'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o' };
	vector<int>	score = { 1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	Solution a;
	auto result = a.maxScoreWords(words, letters, score);

	return 0;
}