// C# Native AOT Compiler doesn't support cross-compiling

#include "BundleMod.h"

void BundleMod_ChangeTextures(
    HANDLE fromFile, HANDLE toFile, const char *textureChanges
) {
    (void)fromFile;
    (void)toFile;
    (void)textureChanges;
}