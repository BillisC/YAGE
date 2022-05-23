#include "system.h"
#include "table.h"

class GBHANDLER{
    gameboy_system gb_sys;

public:
    GBHANDLER();
    ~GBHANDLER();

    void fetch();
};
