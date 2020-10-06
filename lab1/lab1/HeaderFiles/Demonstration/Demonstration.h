#pragma once
#include "../Containers/Containers.h"
#include "../Date/Date.h"
#include "windows.h"
#include <cstdlib>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a);
int menu();
void demonstration_mode_stack();
void demonstration_mode_queue();
void demonstration_mode_deque();
void demonstration_stack();
void demonstraation_queue();
void demonstration_deque();