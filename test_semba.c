#include <semba.h>

#include <stdio.h>

int main(void) {
    NimMain();

    const char *res;

    printf("calling hello world endpoint...\n");
    res = SembaCall("echo", "{\"data\":\"Hello World!!!\"}");
    printf("%s\n\n", res);

    printf("calling missing endpoint...\n");
    res = SembaCall("asdsdjaksjd", "");
    printf("%s\n\n", res);

    printf("calling /auth/steam_user ...\n");
    res = SembaCall("/auth/steam_user", "");
    printf("%s\n\n", res);

    printf("calling /adventure/area_object ...\n");
    res = SembaCall("/adventure/area_object", "{\"areaId\": 300402}");
    printf("%s\n\n", res);

    printf("calling /tip/release ...\n");
    res = SembaCall("/tip/release", "{ \"tipIds\": [ 3012 ] }");
    printf("%s\n\n", res);

    printf("calling /adventure/area_object areaId=300401 ...\n");
    res = SembaCall("/adventure/area_object", "{\"areaId\": 300401}");
    printf("%s\n\n", res);

    printf("calling /adventure/move_to_area areaId=300401 ...\n");
    res = SembaCall("/adventure/move_to_area", "{\"areaId\": 300402, \"currentLocation\": {\"areaType\": 1, \"direction\": 5, \"positionCoordinates\": {\"x\": -9.795328, \"y\": 53.59764, \"z\": -15.6977167}, \"areaKeyId\": 300402}}");
    printf("%s\n\n", res);
}