#include "display_operations.h"
#include "display.h"
namespace gle {
    void disableKey(Display & display, const int key) {
        display.registerKey(key,nullptr);
    }
}
