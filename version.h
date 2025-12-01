#ifndef VERSION_H_01_12_2025_09_52_00
#define VERSION_H_01_12_2025_09_52_00

#define STABLE_MD5SUM "bf87cdb761f931b8ff806b2bd7a376af"
#define DEMO_MD5SUM "875dd65ac7983a7e34cdc22e030e5afa"

enum GameVersion {
    VERSION_NONE,
    VERSION_STABLE,
    VERSION_DEMO,
    VERSION_BETA,
};

void InitGameVersion(char *hex);
enum GameVersion GetGameVersion(void);

#endif