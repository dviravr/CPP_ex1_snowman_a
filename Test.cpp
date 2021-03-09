/**
 * AUTHORS: dvir avrahami
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	erase(input, ' ');
	erase(input, '\t');
	erase(input, '\n');
	erase(input, '\r');
	return input;
}

// HNLRXYTB
TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11111111)) == nospaces("\n _---_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11114411)) == nospaces("\n_---_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(22222222)) == nospaces("\n  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(nospaces(snowman(23121122)) == nospaces("\n  ___  \n ..... \n (._o) \n<(] [)>\n (\" \") "));
    CHECK(nospaces(snowman(32342333)) == nospaces("\n   _   \n  /_\\  \n\\(O.-) \n (> <)\\ \n (___) "));
    CHECK(nospaces(snowman(33333333)) == nospaces("\n   _   \n  /_\\  \n (O_O) \n/(> <)\\ \n (___) "));
    CHECK(nospaces(snowman(44423244)) == nospaces("\n  ___  \n (_*_) \n (- o)/\n/(   ) \n (   ) "));
    CHECK(nospaces(snowman(44444444)) == nospaces("\n  ___  \n (_*_) \n (- -) \n (   ) \n (   ) "));
    CHECK(nospaces(snowman(41231131)) == nospaces("\n ___ \n(_*_)\n(o,O)\n<(> <)>\n( : )"));
    CHECK(nospaces(snowman(12141232)) == nospaces("\n _---_ \n (..-)/\n<(> <) \n (\" \") "));

}

TEST_CASE("Bad snowman code") {
    CHECK(nospaces(snowman(11111111)) != nospaces(" _---_ \n (...) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(12341234)) != nospaces(" _---_ \n (O,-)/\n<(] [) \n (   ) "));
    CHECK(nospaces(snowman(43212323)) != nospaces("  ___  \n (_*_) \n (o_.)/\n/(] [) \n (___) "));
}

TEST_CASE("Invalid input") {
    CHECK_THROWS(snowman(-1));
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(22222022));
    CHECK_THROWS(snowman(02312421));
    CHECK_THROWS(snowman(22812424));
}
