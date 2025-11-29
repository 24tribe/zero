#ifndef CONFIG_H_2025_09_11_08_45
#define CONFIG_H_2025_09_11_08_45

#include <stdbool.h>
#include <stdint.h>

struct Config {
    char *saveFile;
    uint16_t *goldbergPath;
    char *sembaDbPath;
    char *remoteUrl;
    bool dumpGameAssembly;
};

extern struct Config ZERO_CONFIG;

void InitConfig(void);

#endif