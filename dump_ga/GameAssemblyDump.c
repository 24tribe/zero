void DumpTNGameAssembly(char *gameName, void *GameAssembly, unsigned long long GameAssemblySize) {
    char dumpPath[MAX_PATH];
    char addressPath[MAX_PATH];

    int perr1 = snprintf(dumpPath, MAX_PATH, "%s.dump", gameName);
    int perr2 = snprintf(addressPath, MAX_PATH, "%s.addr", gameName);
    
    if (perr1 < 0 || perr2 < 0 || perr1 >= MAX_PATH || perr2 >= MAX_PATH) {
        fputs("snprintf dumpPath or addressPath failed\n", stdout);
    } else {
        if (SaveMetadata(dumpPath, (void *)GameAssembly, GameAssemblySize)) {
            printf("Saved %s\n", dumpPath);
        } else {
            printf("Failed to save %s\n", dumpPath);
        }

        if (SaveAddress(addressPath, GameAssembly)) {
            printf("Saved address to %s\n", addressPath);
        }
    }
}