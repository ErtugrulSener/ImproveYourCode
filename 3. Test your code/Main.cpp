#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

int main(int argc, char* argv[])
{
	Catch::Session session;

	int32_t height = 0;
	std::string name;

	using namespace Catch::clara;

	auto cli = session.cli()
		+ Opt(height, "height")
			["-z", "--height"]
			("how high is it?");

	session.cli(cli);

	auto exitCode = session.applyCommandLine(argc, argv);

	if (exitCode != 0)
		return exitCode;

	std::cout << "Height was: " << height << std::endl;
	return session.run();
}
