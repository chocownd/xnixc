#include <iostream>
#include "clang_installer.h"
#include "c_make_installer.h"
#include "ctags_installer.h"
#include "cscope_installer.h"
#include "vim_manager.h"
#include "ycm_installer.h"

int main()
{
    ClangInstaller::install_clang();
    CMakeInstaller::install_c_make();
    CtagsInstaller::install_ctags();
    CscopeInstaller::install_cscope();
    VimManager::vim_configure();
    YcmInstaller::install_ycm();

    return(0);
}
