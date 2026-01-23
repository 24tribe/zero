#ifndef SEMBA_H_2025_09_16_05_13
#define SEMBA_H_2025_09_16_05_13

extern void NimMain(void);
extern char *SembaCall(const char *uri, const char *request);
extern char *SembaCallDemo(const char *uri, const char *request);
extern char *SembaLoadSaveFile(const char *saves_dir, const char *path);
extern char *SembaCreateSaveFile(const char *saves_dir, const char *path);
extern char *SembaDeleteSaveFile(const char *saves_dir, const char *path);
extern void SembaInitOnlineDb(const char *path);
extern void SembaInitOfflineDb(const char *path);
extern void SembaSetRemoteUrl(const char *url);

#endif