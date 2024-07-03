#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {

	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		GuessResult rst{ false, 0, 0 };

		for (int index = 0; index < (int)question.size(); index++) {
			if (isStrike(guessNumber[index], index)) rst.strikes++;
			if (isBall(guessNumber[index], index)) rst.balls++;
		}

		return rst;
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Mus be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	bool isStrike(char number, int index) {
		return question[index] == number;
	}
	
	bool isBall(char number, int index) {
		if (question[index] == number) return false;
		if (question.find(number) == -1) return false;
		return true;
	}
private:
	string question;
};