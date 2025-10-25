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
    char *r = "{\"areaId\": 300401, \"currentLocation\": {\"areaType\": 1, \"direction\": 7, \"positionCoordinates\": {\"x\": -11.2500019, \"y\": 53.5918961, \"z\": -15.75}, \"areaKeyId\": 300401}}";
    res = SembaCall("/adventure/move_to_area", r);
    printf("%s\n\n", res);

    printf("calling /user/cross_date ...\n");
    res = SembaCall("/user/cross_date", "");
    printf("%s\n\n", res);

    printf("calling /user/log_in ...\n");
    res = SembaCall("/user/log_in", "");
    if (!res) {
        printf("res is null!!!\n\n");
    } else {
        printf("res is probably too big to show\n\n");
    }

    printf("calling /adventure/update_character_status with {\"characterUpdates\": [{\"characterId\": 100101, \"hp\": 511 }]}...\n");
    res = SembaCall("/adventure/update_character_status", "{\"characterUpdates\": [{\"characterId\": 100101, \"hp\": 511 }]}");
    printf("%s\n\n", res);

    r = "{\"battleEntryIds\": [2000016, 2000015], \"lineCharacterIds\": [100101], \"battleTriggers\": [{\"triggerIds\": [300401701, 300401702]}], \"advantageType\": \"advantage\", \"isAttackHit\": true, \"currentLocation\": {\"areaType\": 1, \"direction\": 7, \"positionCoordinates\": {\"x\": -4.79455566, \"y\": 53.6070023, \"z\": -8.03439}, \"areaKeyId\": 300401}, \"bloodStainLocation\": {\"areaKeyId\": 300401, \"areaType\": 1, \"positionCoordinates\": {\"x\": -1.59099984, \"y\": 53.6070023, \"z\": -7.590285}}}";
    printf("calling /battle/start with '%s'...\n\n", r);
    res = SembaCall("/battle/start", r);
    printf("%s\n\n", res);
}