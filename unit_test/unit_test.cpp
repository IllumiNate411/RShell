#include "gtest/gtest.h"
#include <iostream>
#include <string>

#include "../header/parser.hpp"
#include "../header/executable.hpp"
#include "../header/expression.hpp"
#include "../header/And.hpp"
#include "../header/Or.hpp"
#include "../header/Semicolon.hpp"

TEST(parserTest, ParserBrackets) {
	string str = "[ -f test/file/path ] && echo \"path exists\"";
	parser* testParse = new parser();
	testParse->parseStrings(str);
	EXPECT_EQ("test", testParse->stringsAt(0));
	EXPECT_EQ("-f", testParse->stringsAt(1));
	EXPECT_EQ("test/file/path", testParse->stringsAt(2));
	EXPECT_EQ("&&", testParse->stringsAt(3));
	EXPECT_EQ("echo", testParse->stringsAt(4));
	EXPECT_EQ("path exists", testParse->stringsAt(5));
}

TEST(parserTest, ParserBracketsWithoutFlag) {
        string str = "[ test/file/path ] && echo \"path exists\"";
        parser* testParse = new parser();
        testParse->parseStrings(str);
        EXPECT_EQ("test", testParse->stringsAt(0));
        EXPECT_EQ("-e", testParse->stringsAt(1));
        EXPECT_EQ("test/file/path", testParse->stringsAt(2));
        EXPECT_EQ("&&", testParse->stringsAt(3));
        EXPECT_EQ("echo", testParse->stringsAt(4));
        EXPECT_EQ("path exists", testParse->stringsAt(5));
}

TEST(parserTest, ParserComments) {
        string str = "echo A; ls -a #  && echo B";
        parser* testParse = new parser();
        testParse->parseStrings(str);
        EXPECT_EQ("echo", testParse->stringsAt(0));
        EXPECT_EQ("A", testParse->stringsAt(1));
        EXPECT_EQ(";", testParse->stringsAt(2));
        EXPECT_EQ("ls", testParse->stringsAt(3));
        EXPECT_EQ("-a", testParse->stringsAt(4));
}

TEST(parserTest, ParserQuotes) {
        string str = "echo \"A || echo B\"";
        parser* testParse = new parser();
        testParse->parseStrings(str);
        EXPECT_EQ("echo", testParse->stringsAt(0));
        EXPECT_EQ("A || echo B", testParse->stringsAt(1));
}

TEST(parserTest, ParserTrailingSemicolon) {
        string str = "git status; ls -a;";
        parser* testParse = new parser();
        testParse->parseStrings(str);
        EXPECT_EQ("git", testParse->stringsAt(0));
        EXPECT_EQ("status", testParse->stringsAt(1));
	EXPECT_EQ(";", testParse->stringsAt(2));
	EXPECT_EQ("ls", testParse->stringsAt(3));
	EXPECT_EQ("-a", testParse->stringsAt(4));
}

TEST(expressionTestTrue, BasicEvaluate) {
	const char* exArr[3];
	string str1 = "echo";
	string str2 = "hello";
	exArr[0] = str1.c_str();
	exArr[1] = str2.c_str();
	exArr[2] = '\0';
	executable* ex = new expression(exArr);
	EXPECT_EQ(true, ex->execute());
}

TEST(expressionTestTruels, BasicEvaluate) {
	const char* exArr[2];
	string str1 = "ls";
	exArr[0] = str1.c_str();
	exArr[1] = '\0';
	executable* ex = new expression(exArr);
	EXPECT_EQ(true, ex->execute());
}

TEST(expressionTestFalse, BasicEvaluate) {
        const char* exArr[3];
        string str1 = "ls";
        string str2 = "-j";
        exArr[0] = str1.c_str();
        exArr[1] = str2.c_str();
        exArr[2] = '\0';
        executable* ex = new expression(exArr);
        EXPECT_EQ(false, ex->execute());
}

TEST(orTestTrue, BasicEvaluate) {
        const char* exArr1[3];
        const char* exArr2[3];
        string str1 = "echo";
        string str2 = "howdy";
        string str3 = "ls";
        string str4 = "-a";
        exArr1[0] = str1.c_str();
        exArr1[1] = str2.c_str();
        exArr1[2] = '\0';
        exArr2[0] = str3.c_str();
        exArr2[1] = str4.c_str();
        exArr2[2] = '\0';
        executable* ex1 = new expression(exArr1);
        executable* ex2 = new expression(exArr2);
        executable* TestOr = new Or(ex1, ex2);
        EXPECT_EQ(true, TestOr->execute());
}

TEST(orTestFalse, BasicEvaluate) {
        const char* exArr1[3];
        const char* exArr2[3];
        string str1 = "ls";
        string str2 = "-j";
        string str3 = "ls";
        string str4 = "-j";
        exArr1[0] = str1.c_str();
        exArr1[1] = str2.c_str();
        exArr1[2] = '\0';
        exArr2[0] = str3.c_str();
        exArr2[1] = str4.c_str();
        exArr2[2] = '\0';
        executable* ex1 = new expression(exArr1);
        executable* ex2 = new expression(exArr2);
        executable* TestOr = new Or(ex1, ex2);
        EXPECT_EQ(false, TestOr->execute());
}

TEST(andTestTrue, BasicEvaluate) {
        const char* exArr1[3];
        const char* exArr2[2];
        string str1 = "echo";
        string str2 = "Yeehaw";
        string str3 = "ls";
        exArr1[0] = str1.c_str();
        exArr1[1] = str2.c_str();
        exArr1[2] = '\0';
        exArr2[0] = str3.c_str();
        exArr2[1] = '\0';
        executable* ex1 = new expression(exArr1);
        executable* ex2 = new expression(exArr2);
        executable* TestAnd = new And(ex1, ex2);
        EXPECT_EQ(true, TestAnd->execute());
}

TEST(andTestFalse, BasicEvaluate) {
        const char* exArr1[3];
        const char* exArr2[3];
        string str1 = "echo";
        string str2 = "This should return false!";
        string str3 = "ls";
        string str4 = "-j";
        exArr1[0] = str1.c_str();
        exArr1[1] = str2.c_str();
        exArr1[2] = '\0';
        exArr2[0] = str3.c_str();
        exArr2[1] = str4.c_str();
        exArr2[2] = '\0';
        executable* ex1 = new expression(exArr1);
        executable* ex2 = new expression(exArr2);
        executable* TestAnd = new And(ex1, ex2);
        EXPECT_EQ(false, TestAnd->execute());
}

TEST(semicolonTest, BasicEvaluate) {
        const char* exArr1[3];
        const char* exArr2[3];
        string str1 = "echo";
        string str2 = "Hi Ryan";
        string str3 = "git";
        string str4 = "status";
        exArr1[0] = str1.c_str();
        exArr1[1] = str2.c_str();
        exArr1[2] = '\0';
        exArr2[0] = str3.c_str();
        exArr2[1] = str4.c_str();
        exArr2[2] = '\0';
        executable* ex1 = new expression(exArr1);
        executable* ex2 = new expression(exArr2);
        executable* TestSemicolon = new Semicolon(ex1, ex2);
        EXPECT_EQ(true, TestSemicolon->execute());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//exit test is evalutated in integration.
