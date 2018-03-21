# cp3 - C++ script interpreter

Use this program within your C++ scripts via the *shebang line*, so
you can on-the-fly compile your C++ programs without the need to
explicitely (re-)compile.

```!cpp
#! /usr/bin/cp3 -std=c++14
#include <stdio.h>
int main() {
  printf("Hello, World\n");
}
```

`chmod` this script to mark it as executible and run it.

## License

cp3 - C++ interpreter
Copyright (C) 2018 Christian Parpart <christian@parpart.family>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

