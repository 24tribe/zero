#ifdef __cplusplus
extern "C" {
#endif

#include "semba_enum.h"

struct SembaRemote;

struct SembaRemote *SembaRemote_Init(const char *url, enum SembaStatus *status);
char *SembaRemote_Call(struct SembaRemote *ctx, const char *path, const char *req, enum SembaStatus *status);
void SembaRemote_FreeResponse(char *response);
void SembaRemote_Deinit(struct SembaRemote *ctx);

#ifdef __cplusplus
}
#endif