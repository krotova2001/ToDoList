#include "Model.h"

// здесь мы создаем встроенную структуру С которая содержит текущее время
time_t now = time(0);
tm* time_now = localtime(&now);