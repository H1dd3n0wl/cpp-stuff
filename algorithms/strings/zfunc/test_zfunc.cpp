#include <gtest/gtest.h>
#include "zfunc.hpp"

TEST(zfunc, strings) {
	ASSERT_EQ(1, 1);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}