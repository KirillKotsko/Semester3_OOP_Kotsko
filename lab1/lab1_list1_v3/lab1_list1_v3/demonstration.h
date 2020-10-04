#pragma once
#include "containers.h"
#include "windows.h"
#include <cstdlib>
#include <vector>

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a);

void demonstration_stack();

void demonstraation_queue();

void demonstration_deque();