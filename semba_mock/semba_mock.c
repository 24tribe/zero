#include "semba.h"

struct SembaExContext {};
struct SembaExContext dummy;

void NimMain(void) {
  // do nothing
}

struct SembaExContext *SembaExInit(const char *dbPath, int32_t gameVersion, int32_t *status) {
  *status = 0;
  return &dummy; 
}

char *SembaExCall(struct SembaExContext *ctx, const char *path, const char *req, int32_t *status) {
  *status = 1; // statusException    
  return "Compiled without offline mode support!!";
}

void SembaExFreeResponse(char *response) {
  // do nothing  
}

void SembaExDeinit(struct SembaExContext *ctx) {
  // do nothing
}
