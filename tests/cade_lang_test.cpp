#include <gtest/gtest.h>
#include "../src/cade_lang.h"
#include <vector>
#include "../src/token.h"

class CadeLangTestFixture : public ::testing::Test {
protected:
    Cade_Lang* cade_lang = nullptr; 
    std::vector<char*> argv; 
    int argc;

    void SetUp() override {
        argc = 2; 
	// Without these strdup the compiler complains
        argv = {strdup("Cade_Lang"), strdup("../tests/test_file.txt")}; 
        cade_lang = new Cade_Lang(argc, argv.data());
    }

    void TearDown() override {
        delete cade_lang;
        cade_lang = nullptr;
        for (char* arg : argv) {
            free(arg);
        }
    }
};

TEST_F(CadeLangTestFixture, num_token_test) {
	std::string test_string = "hello world";
	std::vector<Token> tokens = cade_lang->tokenize(test_string);
	int num_tokens = tokens.size();
	int num_tokens_expected = 2;
	EXPECT_EQ(num_tokens, num_tokens_expected);
}

TEST_F(CadeLangTestFixture, num_token_test_2) {
	std::string test_string = "hello world this should be longer";
	std::vector<Token> tokens = cade_lang->tokenize(test_string);
	int num_tokens = tokens.size();
	int num_tokens_expected = 6;
	EXPECT_EQ(num_tokens, num_tokens_expected);
}

TEST_F(CadeLangTestFixture, num_token_test_3) {
	std::string test_string = "1 2 3 4 5 6 7 8 9";
	std::vector<Token> tokens = cade_lang->tokenize(test_string);
	int num_tokens = tokens.size();
	int num_tokens_expected = 9;
	EXPECT_EQ(num_tokens, num_tokens_expected);
}

TEST_F(CadeLangTestFixture, num_token_test_spaces) {
	std::string test_string = "1  2 3 cd   4 5 6 7  8 9";
	std::vector<Token> tokens = cade_lang->tokenize(test_string);
	int num_tokens = tokens.size();
	int num_tokens_expected = 10;
	EXPECT_EQ(num_tokens, num_tokens_expected);
}



