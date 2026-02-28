#include "Logging.h"

int main() {
	MINI_INFO("Hello World");
	MINI_ASSERT(2+2==4, "test");
	MINI_ASSERT(2+2==5, "test2");
}
