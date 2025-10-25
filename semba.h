#ifndef SEMBA_H_2025_09_16_05_13
#define SEMBA_H_2025_09_16_05_13

extern void NimMain(void);
extern const char *SembaCall(const char *uri, const char *request);
extern void SembaLogFlow(const char *uri, const char *req, const char *res);

#endif