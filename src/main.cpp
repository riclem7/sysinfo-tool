#include <iostream>
#include <string>

static const char* VERSION = "0.1";

static void print_help(const std::string& prog) {
    std::cout
        << "Usage: " << prog << " [--help] [--version]\n"
        << "  --help     Print this help message\n"
        << "  --version  Print version\n";
}

int main(int argc, char* argv[]) {
    std::string prog = (argc > 0 && argv[0]) ? argv[0] : "sysinfo_tool";

    //No args: default behavior
    if (argc == 1) {
        std::cout << "sysinfo-tool v" << VERSION << "\n";
        return 0;
    }

    std::string arg = argv[1];

    if (arg == "--help") {
        print_help(prog);
        return 0;
    }

    if (arg == "--version") {
        std::cout << "sysinfo-tool v" << VERSION << "\n";
        return 0;
    }

    std::cerr << "Unknown argument: " << arg << "\n";
    print_help(prog);
    return 1;
}
