// cp3 - C++ script interpreter
// Copyright (C) 2018 Christian Parpart <christian@parpart.family>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <libgen.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

time_t file_mtime(const std::string& f) {
  struct stat st;
  if (stat(f.c_str(), &st) < 0)
    return 0;
  else
    return st.st_mtime;
}

string getCompiled(const string& sourcefile, const vector<string>& args) {
  const string outputfile = "/tmp/cp3." + to_string(hash<string>{}(sourcefile));

  if (file_mtime(sourcefile) > file_mtime(outputfile)) {
    setenv("CXX", "g++", 0);

    // XXX: chdir to basedir of sourcefile (so relative includes work)
    char oldwd[PATH_MAX];
    getcwd(oldwd, sizeof(oldwd));

    char absSourcePath[PATH_MAX];
    realpath(sourcefile.c_str(), absSourcePath);
    const char* const srcfile = basename(absSourcePath);
    const char* const srcdir = dirname(absSourcePath);

    // printf("| abspath: '%s'\n", absSourcePath);
    // printf("| srcdir:  '%s'\n", srcdir);
    // printf("| srcfile: '%s'\n", srcfile);

    if (chdir(srcdir) < 0)
      perror(srcdir);

    // TODO: read sourcefile ourself, to not depend on tail"
    stringstream cmd;
    cmd << "tail -n+2 " << std::quoted(srcfile) << " | "
        << "$CXX -x c++ - -o " << std::quoted(outputfile);

    // append script's compiler args
    for (const string& arg: args)
      cmd << " " << arg;

    // compile script
    if (system(cmd.str().c_str()) != 0) {
      perror(cmd.str().c_str());
      exit(EXIT_FAILURE);
    }

    // chdir back to original working dir
    chdir(oldwd);
  }

  return outputfile;
}

int main(int argc, char* const argv[]) {
  int i = 1;
  vector<string> cp3args;
  for (; i < argc && argv[i][0] == '-'; ++i)
    cp3args.push_back(argv[i]);

  if (i == argc) {
    printf("please use this program with a c++ script\n");
    return EXIT_FAILURE;
  }

  string sourcefile = argv[i];
  i++;

  string binaryfile = getCompiled(sourcefile, cp3args);
  execvp(binaryfile.c_str(), argv + i);
  perror(binaryfile.c_str());
  return EXIT_FAILURE;
}
