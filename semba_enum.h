#ifndef SEMBA_ENUM_16_03_2026_02_25
#define SEMBA_ENUM_16_03_2026_02_25

#ifdef __cplusplus
extern "C" {
#endif

enum SembaStatus {
    SEMBA_STATUS_OK = 0,
    SEMBA_STATUS_EXCEPTION = 1,
    SEMBA_STATUS_VERSION_UNKNOWN = 2,
    SEMBA_STATUS_DB_ERROR = 3,
    SEMBA_STATUS_ALLOC_ERROR = 4,
    SEMBA_STATUS_INVALID_CONTEXT = 5,
};

enum SembaGameVersion {
    GAME_VERSION_UNKNOWN = -1,
    GAME_VERSION_1_1_3_35 = 0,
    GAME_VERSION_0_2_1_20 = 1,
};

#ifdef __cplusplus
}
#endif

#endif