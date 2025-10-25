#ifndef CONFIG_H_2025_09_11_08_45
#define CONFIG_H_2025_09_11_08_45

#include <stdbool.h>

struct Config {
    bool enableGoldbergSteam;
};

extern struct Config ZERO_CONFIG;

void InitConfig(void);

#endif