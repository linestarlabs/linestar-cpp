
#include <boost/program_options.hpp>
#include "Linestar.h"

namespace po = boost::program_options;

int main(int argc, char** argv) {
    std::string ip_address;

    // Parse command-line arguments
    po::options_description desc("Allowed options");
    desc.add_options()
        ("ip-address,i", po::value<std::string>(&ip_address)->required(), "PLC IP address");

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    } catch (const po::error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cout << desc << std::endl;
        return 1;
    }

    // Initialize Linestar and execute commands
    Linestar linestar;
    linestar.connect(ip_address);
    linestar.wake();
    // TODO: Execute other commands

    return 0;
}

