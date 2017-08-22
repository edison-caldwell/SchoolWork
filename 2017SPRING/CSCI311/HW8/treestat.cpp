#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <iomanip>

using namespace std;

struct r_buff{
    int blk, chr, dir, pipe, reg, sckt, syml, total;
} file_stat;

static int CreateStats(const char * path, const struct stat *sb, int tflag, struct FTW *ftwbuf);
void PrintReport();

int main(int argc, char *argv[])
{
    int flags = 0;
    char * cwd = ".";    
    file_stat.blk = 0;
    file_stat.chr = 0;
    file_stat.dir = 0;
    file_stat.pipe = 0;
    file_stat.reg = 0;
    file_stat.sckt = 0;
    file_stat.syml = 0;
    file_stat.total = 0;
    flags |= FTW_PHYS;

    if((argc == 2 && strchr(argv[1], '/') == NULL) || argc > 2)
    {
        cerr << "\n\nInvalid arguments. Process terminiating..\n\n";
        return 1;
    }

    if(argc < 2){
         cout << "\n\n" << cwd << endl;
         nftw(cwd, CreateStats, 20, flags);
    }
    else{
        cout << "\n\n" << argv[1] << endl;
        nftw(argv[1], CreateStats, 20, flags);
    }

    PrintReport();

    return 0;
}


static int CreateStats(const char * path, const struct stat *sb, int tflag, struct FTW *ftwbuf)
{ 
    if(S_ISBLK(sb->st_mode)){
        file_stat.blk++;    
    }
    else if(S_ISCHR(sb->st_mode)){
        file_stat.chr++;
    }
    else if(S_ISDIR(sb->st_mode)){
        file_stat.dir++;
    }
    else if(S_ISFIFO(sb->st_mode)){
        file_stat.pipe++;
    }
    else if(S_ISREG(sb->st_mode)){
        file_stat.reg++;
    }
    else if(S_ISSOCK(sb->st_mode)){
        file_stat.sckt++;
    }
    else if(S_ISLNK(sb->st_mode)){
        file_stat.syml++;
    }
    file_stat.total++;

    return 0;
}

void PrintReport()
{
    file_stat.dir--;
    file_stat.total--;
    cout << fixed << setprecision(0);
    cout << "\tBlock\t" << right << setw(4) << file_stat.blk << right << setw(8) << static_cast<float>(file_stat.blk) / static_cast<float>(file_stat.total) * 100 << "%\n";
    cout << "\tChar\t" << right << setw(4) << file_stat.chr << right << setw(8) << static_cast<float>(file_stat.chr) / static_cast<float>(file_stat.total) * 100 << "%\n";
    cout << "\tDir\t" << right << setw(4) << file_stat.dir << right << setw(8) << static_cast<float>(file_stat.dir) / static_cast<float>(file_stat.total) * 100 << "%\n";
    cout << "\tPipe\t" << right << setw(4) << file_stat.pipe << right << setw(8) << static_cast<float>(file_stat.pipe) / static_cast<float>(file_stat.total) * 100 << "%\n";
    cout << "\tReg\t" << right << setw(4) << file_stat.reg << right << setw(8) << static_cast<float>(file_stat.reg) / static_cast<float>(file_stat.total) * 100 << "%\n";
    cout << "\tSocket\t" << right << setw(4) << file_stat.sckt << right << setw(8) << static_cast<float>(file_stat.sckt) / static_cast<float>(file_stat.total) * 100 << "%\n";
    cout << "\tSymlnk\t" << right << setw(4) << file_stat.syml << right << setw(8) << static_cast<float>(file_stat.syml) / static_cast<float>(file_stat.total) * 100 << "%\n\n\n";

    return;
}
