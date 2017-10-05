#include <gtest/gtest.h>
#include "../Sets.h"

TEST(Unite, Equals) {
    // Arrange
    BitSet setA{"012D"};
    BitSet setB{"012D"};

    // Act
    BitSet uAB {setA|setB};

    // Assert
    EXPECT_TRUE(uAB == "012D");
}

TEST(Unite, Different) {
    BitSet setA{"0342"};
    BitSet setB{"9CEF"};

    BitSet uAB {setA|setB};

    EXPECT_TRUE(uAB == "02349CEF");
}

TEST(Unite, WithEmpty) {
    BitSet setA{""};
    BitSet setB{"CA"};

    BitSet uAB{setA|setB};

    EXPECT_TRUE(uAB == "AC");
}

TEST(Unite, TwoCommon) {
    BitSet setA{"125"};
    BitSet setB{"135"};

    BitSet uAB{setA|setB};

    EXPECT_TRUE(uAB == "1235");
}

TEST(Unite, OneCommon) {
    BitSet setA{"975"};
    BitSet setB{"E69"};

    BitSet uAB{setA|setB};

    EXPECT_TRUE(uAB == "5679E");
}

TEST(Unite, BothEmpty) {
    BitSet setA{""};
    BitSet setB{""};

    BitSet uAB{setA|setB};

    EXPECT_TRUE(uAB == "");
}

TEST(Cross, Equals) {
    BitSet setA{"2AB"};
    BitSet setB{"2AB"};

    BitSet cAB{setA & setB};

    EXPECT_TRUE(cAB == "2AB");
}

TEST(Cross, Different) {
    BitSet setA{"2AB"};
    BitSet setB{"7CF"};

    BitSet cAB{setA & setB};

    EXPECT_TRUE(cAB == "");
}

TEST(Cross, WithEmpty) {
    BitSet setA{"AB2"};
    BitSet setB{""};

    BitSet cAB{setA & setB};

    EXPECT_TRUE(cAB == "");
}

TEST(Cross, TwoCommon) {
    BitSet setA{"12C"};
    BitSet setB{"14C"};

    BitSet cAB{setA & setB};

    EXPECT_TRUE(cAB == "1C");
}

TEST(Cross, OneCommon) {
    BitSet setA{"AB2"};
    BitSet setB{"F02"};

    BitSet cAB{setA & setB};

    EXPECT_TRUE(cAB == "2");
}

TEST(Cross, BothEmpty) {
    BitSet setA{""};
    BitSet setB{""};

    BitSet cAB{setA & setB};

    EXPECT_TRUE(cAB == "");
}

