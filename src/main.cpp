#include <iostream>
#include "clang_installer.h"
#include "c_make_installer.h"
#include "ctags_installer.h"
#include "cscope_installer.h"

using std::cout;
using std::endl;

int main()
{
    ClangInstaller::install_clang();
    CMakeInstaller::install_c_make();
    CtagsInstaller::install_ctags();
    CscopeInstaller::install_cscope();

    return(0);
}
