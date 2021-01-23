#include <catch.hpp>

TEST_CASE("The answer to the universe and everything", "[theanswer]") {
	REQUIRE(42 == 42);
};

TEST_CASE("Check a vector", "[benchmark]") {
	static const int size = 2;

	std::vector<int> vec;

	BENCHMARK("Vector load really long.")
	{
		vec = std::vector<int>();

		for (int i = 0; i < vec.size(); ++i)
			vec.push_back(i);
	};
	REQUIRE(vec.size() == size);

	BENCHMARK("Vector load really long with resize.")
	{
		vec = std::vector<int>();
		vec.resize(size);

		for (int i = 0; i < vec.size(); ++i)
			vec.push_back(i);
	};
	REQUIRE(vec.size() == size);
};
