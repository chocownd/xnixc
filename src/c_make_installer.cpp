#include <iostream>
#include "install_helper.h"
#include "c_make_installer.h"

using std::cout;
using std::endl;

bool CMakeInstaller::check_c_make()
{
    InstallHelper::examine_os( "To check CMake installed, this OS is invalid" );

    string cmd = "which cmake";
    string result = InstallHelper::xnix_cmd_exec( cmd.c_str() );

    if ( result != InstallHelper::FAILED )
        return true;
    else
        return false;
}

bool CMakeInstaller::install_c_make()
{
    InstallHelper::examine_os( "To install CMake, this OS is invalid" );

    if ( check_c_make() )
    {
        cout << "CMake is already installed ..." << endl;
        cout << "CMake install complete" << endl;

        return true;
    }

    string cmd;

    if ( InstallHelper::get_os() == InstallHelper::UBUNTU )
    {

        cmd = "export CC=/usr/bin/clang";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "export CXX=/usr/bin/clang++";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "sudo apt-get install -y make";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "wget -O ~/cmake-3.5.2.tar.gz " \
               "https://cmake.org/files/v3.5/cmake-3.5.2.tar.gz";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "rm -rf ~/cmake-3.5.2";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "tar -xvzf ~/cmake-3.5.2.tar.gz -C ~/";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "rm ~/cmake-3.5.2.tar.gz";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "cd ~/cmake-3.5.2 && ./configure";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "cd ~/cmake-3.5.2 && make";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "sudo apt-get install -y checkinstall";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "cd ~/cmake-3.5.2 && sudo checkinstall -y";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        cmd = "sudo rm -rf ~/cmake-3.5.2";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        return true;
    }
    else if ( InstallHelper::get_os() == InstallHelper::MAC )
    {
        cmd = "brew install CMake";
        InstallHelper::xnix_cmd_exec( cmd.c_str() );

        return true;
    }

    return false;
}
