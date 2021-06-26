#include <iostream>
#include <unistd.h>
#include <term.h>
#include "field.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    field Game;
    cout << Game.Field;
    return 0;
}
