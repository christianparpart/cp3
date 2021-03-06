#! /usr/bin/cp3 -std=c++17 -I$HOME/projects/cp3
// example C++ shell script
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

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char* argv[]) {
  vector<string> args;
  for (int i = 0; i < argc; ++i)
    args.push_back(argv[i]);

  printf("Hello, World\n");

  for (auto& arg: args)
    printf("- %s\n", arg.c_str());

  return 0;
}
