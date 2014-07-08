CodeBlocks support
------------------

This fork is added with codeblock support.

All other dependency suchas regex is done via normal MSYS/MinGW make.

Within CodeBlocks please configure the General Compiler GCC to which is
regex compile and installed, otherwise tell to search-dirs  where is 
*libgnurx* (libregex renamed).

The *config.h* is generated using MSYS/MinGW make.

This project don't use custom MakeFile.
