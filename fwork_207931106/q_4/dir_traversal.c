#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


// program that performs a recursive transition on a given directory


/** nftw() calls that function for each entry found in the tree,
 *          with the following parameters:
 * fpath = pathname of the entry (relative to the calling process's current working directory)
 * sb = pointer to the stat structure returned by a call to stat(2) for fpath
 * tflag = can has one of the following values:
 *          FTW_F --- fpath is a regular file
 *          FTW_D --- fpath is a directory
 *          FTW_DNR - fpath is a directory which can't be read
 *          FTW_NS -- stat(2) call failed on fpath, which is not a symbolic link
 * ftwbuf = flag that have some options (you can see it in man page)
 */
static int fn(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf) {

    lstat(fpath, (struct stat* restrict)sb);  // returns information about the file or the link itself

    switch (sb -> st_mode & S_IFMT) {
        case S_IFLNK : break;
        default:
            if(tflag == FTW_F) printf("F ");
            else if(tflag == FTW_D || tflag == FTW_DNR) printf("D ");  // print type
    
            printf("%ld ", sb -> st_ino);  // inode number
    
            printf("%s \n", fpath + ftwbuf -> base);  // print name
    }
    return 0;
}

int main(int argc, char **argv) {
    if(nftw(argv[1], fn, 20, 0) == -1) {
        printf("nftw() function failed");
        exit(1);
    }
    return 0;
}