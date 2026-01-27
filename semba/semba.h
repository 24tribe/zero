#ifndef SEMBA_H_2025_09_16_05_13
#define SEMBA_H_2025_09_16_05_13

extern void NimMain(void);
extern char *SembaCall(const char *uri, const char *request);
extern char *SembaCallDemo(const char *uri, const char *request);
extern void SembaInitOfflineDb(const char *path);
extern void SembaSetRemoteUrl(const char *url);

#endif