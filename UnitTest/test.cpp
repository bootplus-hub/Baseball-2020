#include "pch.h"
#include "../Baseball/baseball.cpp"
#include <stdexcept>

using namespace std;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnMatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}