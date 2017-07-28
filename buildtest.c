#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* libc */
#include "source/libraries/libc/sfd_ctype.c"
#include "source/libraries/libc/sfd_string.c"

/* config libs */
#include "source/libraries/config/sfd_config_sys.c"

/* io libs */
#include "source/libraries/io/sfd_libcli.c"

/* net libs */
/* #include "source/libraries/sfd_libhttp.c" */

/* file libs */
#include "source/libraries/files/sfd_libfile.c"
#include "source/libraries/files/filetypes/sfd_libbmp.c"
#include "source/libraries/files/filetypes/sfd_libid3.c"
#include "source/libraries/files/filetypes/sfd_libiso.c"
/* #include "source/libraries/files/filetypes/sfd_libobj.c" */
#include "source/libraries/files/filetypes/sfd_libwav.c"

/* dev libs */
/* #include "source/libraries/development/sfd_libcode.c" */

int main() {
    puts("This is a test progam that pulls in all of the Sandford libraries to ensure they all compile successfully, it does not do anything.");
    return 0;
}
