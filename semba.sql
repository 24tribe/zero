DROP TABLE IF EXISTS areaObjects;
CREATE TABLE areaObjects (
    areaId INTEGER,
    areaObjectId INTEGER,
    areaPointId INTEGER,
    areaObjectBehaviorId INTEGER,
    action STRING
);

DROP TABLE IF EXISTS tipRelease;
CREATE TABLE tipRelease (
    tipId INTEGER,
    areaId INTEGER,
    areaObjectId INTEGER,
    newAreaPointId INTEGER,
    newAreaObjectBehaviorId INTEGER,
    newAction STRING
);

DROP TABLE IF EXISTS areaEnemies;
CREATE TABLE areaEnemies (
    areaId INTEGER,
    areaPointId INTEGER,
    areaEnemyRateSetId INTEGER,
    action STRING
);

DROP TABLE IF EXISTS areaItems;
CREATE TABLE areaItems (
    areaId INTEGER,
    areaItemId INTEGER
);

DROP TABLE IF EXISTS areaBgm;
CREATE TABLE areaBgm (
    areaId INTEGER,
    id INTEGER,
    eventName STRING
);

DROP TABLE IF EXISTS userData;
CREATE TABLE userData (
    keyName STRING,
    val STRING
);

DROP TABLE IF EXISTS gates;
CREATE TABLE gates (
    fromAreaId INTEGER,
    fromPosX REAL,
    fromPosY REAL,
    fromPosZ REAL,
    toAreaId INTEGER,
    toPosX REAL,
    toPosY REAL,
    toPosZ REAL,
    toDirection INTEGER
);

DROP TABLE IF EXISTS characters;
CREATE TABLE characters (
    characterId INTEGER,
    exp INTEGER,
    hp INTEGER,
    attack INTEGER,
    defense INTEGER,
    maxHp INTEGER,
    receivedAt STRING,
    characterOwnershipType INTEGER,
    criticalRate INTEGER,
    criticalDamageRate INTEGER,
    movementSpeed INTEGER,
    damageInflictedRate INTEGER,
    tensionIncreaseRate INTEGER,
    cpRecastRate INTEGER,
    spGaugeIncreaseRate INTEGER,
    attackSpeed INTEGER,
    characterCostumeId INTEGER,
    abnormalityParamSet STRING,
    trainingScoreLevelScore INTEGER,
    trainingScoreRankScore INTEGER,
    actionPointMax INTEGER,
    actionPointRate INTEGER,
    actionPointConsumption INTEGER,
    damageTakenRate INTEGER
);

DROP TABLE IF EXISTS tensionCards;
CREATE TABLE tensionCards (
    tensionCardId INTEGER,
    receivedAt STRING,
    maxLevel INTEGER,
    abilityEfficacies STRING,
    trainingScoreLevelScore INTEGER,
    entityId INTEGER,
    isLocked BOOLEAN
);

DROP TABLE IF EXISTS challengeProgresses;
CREATE TABLE challengeProgresses (
    challengeProgressId INTEGER,
    clearedAt STRING,
    state INTEGER
);

DROP TABLE IF EXISTS nineSequences;
CREATE TABLE nineSequences (
    nineSequenceId INTEGER,
    expiresAt STRING,
    lastReceiveAt STRING,
    lastReadAt STRING
);

DROP TABLE IF EXISTS tips;
CREATE TABLE tips (
    tipId INTEGER,
    releasedAt STRING
);

DROP TABLE IF EXISTS characterCostumes;
CREATE TABLE characterCostumes (
    characterCostumeId INTEGER,
    receivedAt STRING
);

DROP TABLE IF EXISTS totalTasks;
CREATE TABLE totalTasks (
    conditionId INTEGER
);

INSERT INTO totalTasks (conditionId)
VALUES
(104010)
,(112106)
,(107009)
,(105003)
,(1015)
,(10814602)
,(1402911)
,(107005)
,(1023)
,(104012)
,(111001)
,(13301011)
,(112110)
,(104014)
,(1016)
,(105014)
,(103002)
,(1302011)
,(111005)
,(200003)
,(1402111)
,(1032)
,(1029)
,(120001)
,(103006)
,(104031)
,(111006)
,(119002)
,(1037)
,(110010)
,(105008)
,(13301013)
,(1300711)
,(13807502)
,(101013)
,(1039)
,(104002)
,(107011)
,(10302)
,(100)
,(104009)
,(107021)
,(105006)
,(2)
,(105005)
,(13807402)
,(113005)
,(103011)
,(300003)
,(1028)
,(300002)
,(104030)
,(103012)
,(110003)
,(107002)
,(110002)
,(300004)
,(104011)
,(1031)
,(1019)
,(111002)
,(1027)
,(200006)
,(110007)
,(10353)
,(1001631)
,(113003)
,(1025)
,(112103)
,(117001)
,(14040112)
,(104005)
,(105030)
,(10301011)
,(119005)
,(107004)
,(103014)
,(105010)
,(107003)
,(10301012)
,(200009)
,(1014)
,(1301011)
,(103008)
,(14930902)
,(14930502)
,(105015)
,(113002)
,(1022)
,(112105)
,(105012)
,(1402811)
,(105031)
,(104015)
,(107006)
,(105001)
,(111004)
,(112108)
,(107015)
,(103013)
,(107020)
,(1038)
,(107012)
,(14930702)
,(13301012)
,(107007)
,(10832902)
,(1012)
,(10351)
,(102014)
,(107022)
,(104004)
,(1030)
,(104013)
,(112102)
,(1034)
,(1300811)
,(110006)
,(103029)
,(105011)
,(113004)
,(108003)
,(300005)
,(110001)
,(103031)
,(107010)
,(103030)
,(118001)
,(108002)
,(10305)
,(10836602)
,(200004)
,(300001)
,(10352)
,(105007)
,(10301010)
,(101014)
,(107017)
,(200011)
,(1011)
,(120003)
,(200005)
,(1301211)
,(116001)
,(103010)
,(105013)
,(104008)
,(105002)
,(200008)
,(10355)
,(112104)
,(103009)
,(14930302)
,(107019)
,(103005)
,(1018)
,(112101)
,(104006)
,(10835602)
,(107018)
,(104007)
,(1021)
,(10303)
,(1300511)
,(200012)
,(103003)
,(1013)
,(10301013)
,(112107)
,(103001)
,(14040113)
,(200010)
,(103007)
,(10990701)
,(14040111)
,(1020)
,(13807302)
,(105029)
,(104003)
,(107008)
,(119003)
,(200007)
,(107014)
,(10814802)
,(14930102)
,(112111)
,(10301)
,(102013)
,(200013)
,(113001)
,(1017)
,(107016)
,(107013)
,(113006)
,(13301010)
,(113007)
,(105004)
,(107001)
,(108001)
,(104029)
,(14040110)
,(110008)
,(110004)
,(103015)
,(102010)
,(119001)
,(1026)
,(101010)
,(112109)
,(200001)
,(1035)
,(1302211)
,(200002)
,(104001)
,(120002)
,(101000)
,(111003)
,(119004)
,(103004)
,(10814702)
,(1033)
,(105009)
,(1024)
,(1036)
;

INSERT INTO characterCostumes
VALUES
(1001001, '2025-09-10T02:22:51Z')
,(1002001, '2025-09-10T02:22:53Z')
,(1005001, '2025-09-10T02:22:53Z')
;

INSERT INTO tips (tipId, releasedAt)
VALUES
(1002, '2025-09-10T02:22:53Z')
,(1004, '2025-09-10T02:22:53Z')
,(1005, '2025-09-10T02:22:53Z')
,(1006, '2025-09-10T02:22:53Z')
,(1030, '2025-09-10T02:22:53Z')
,(1031, '2025-09-10T02:22:53Z')
,(1032, '2025-09-10T02:22:53Z')
,(1033, '2025-09-10T02:22:53Z')
,(1034, '2025-09-10T02:22:53Z')
,(1035, '2025-09-10T02:22:53Z')
,(1036, '2025-09-10T02:22:53Z')
,(1037, '2025-09-10T02:22:53Z')
,(1039, '2025-09-10T02:22:53Z')
,(1041, '2025-09-10T02:22:53Z')
,(1042, '2025-09-10T02:22:53Z')
,(1043, '2025-09-10T02:22:53Z')
,(1045, '2025-09-10T02:22:53Z')
,(1046, '2025-09-10T02:22:53Z')
,(1052, '2025-09-10T02:22:53Z')
,(1053, '2025-09-10T02:22:53Z')
,(2001, '2025-09-10T02:22:53Z')
,(2002, '2025-09-10T02:22:53Z')
,(2003, '2025-09-10T02:22:53Z')
,(2006, '2025-09-10T02:22:53Z')
,(2011, '2025-09-17T00:18:48Z')
,(2013, '2025-09-10T02:22:53Z')
,(2034, '2025-09-10T02:22:53Z')
,(3006, '2025-09-10T02:22:53Z')
,(3012, '2025-09-16T21:43:57Z')
;

INSERT INTO nineSequences (nineSequenceId, expiresAt, lastReceiveAt, lastReadAt)
VALUES
(10000000, "2025-09-10T02:22:53Z", "2025-09-10T02:22:53Z", "2025-09-10T02:22:53Z")
,(10001002, '2025-09-10T02:22:53Z', '2025-09-10T02:22:53Z', '2025-09-10T02:22:53Z')
;

INSERT INTO challengeProgresses (challengeProgressId, clearedAt, state)
VALUES
(1000011, '2025-09-10T02:22:53Z', 3)
,(1000021, '2025-09-10T02:22:53Z', 3)
,(1000031, '2025-09-10T02:22:53Z', 3)
,(1000041, '2025-09-10T02:22:53Z', 3)
,(1000051, '2025-09-10T02:22:53Z', 3)
,(1000061, '2025-09-10T02:22:53Z', 3)
,(1000071, '2025-09-10T02:22:53Z', 3)
,(1000081, '2025-09-10T02:22:53Z', 3)
,(1000091, '2025-09-10T02:22:53Z', 3)
,(1000101, '2025-09-10T02:22:53Z', 3)
,(1000111, '2025-09-10T02:22:53Z', 3)
,(1000112, '2025-09-10T02:22:53Z', 3)
,(1000121, '2025-09-10T02:22:53Z', 3)
,(1000122, '2025-09-10T02:22:53Z', 3)
,(1000141, '2025-09-10T02:22:53Z', 3)
,(1000151, '2025-09-10T02:22:53Z', 3)
,(1000152, '2025-09-10T02:22:53Z', 3)
,(1000153, '2025-09-10T02:22:53Z', 3)
,(1000161, '2025-09-10T02:22:53Z', 3)
,(1000162, '', 2)
;

INSERT INTO tensionCards (tensionCardId, receivedAt, maxLevel, abilityEfficacies, trainingScoreLevelScore, entityId, isLocked)
VALUES
(40006, '2025-09-10T02:22:53Z', 10, '[{"id": 100400060, "coolTimeMillisecond": 25000, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 53, "probability": 100, "activateConditions": "100400061&!100400060&!100400062", "fValues": [0, 0.9], "values": [1, 0], "targetType": 1}, {"id": 100400061, "coolTimeMillisecond": 25000, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": 25000, "efficacyType": 24, "probability": 100, "activateConditions": "100400061&!100400062", "fValues": [30], "targetType": 2}]', 2, 1, true)
,(40024, '2025-09-10T02:22:53Z', 10, '[{"id": 100300290, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 1, "probability": 100, "activateConditions": "100300290", "sustainConditions": "100300290", "fValues": [6.48], "values": [2], "targetType": 1}, {"id": 100300291, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 1, "probability": 100, "activateConditions": "100300290", "sustainConditions": "100300290", "fValues": [6.48], "values": [1], "targetType": 1}, {"id": 100300292, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 1, "probability": 100, "activateConditions": "!100300290", "sustainConditions": "!100300290", "fValues": [3.24], "values": [2], "targetType": 1}, {"id": 100300293, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 1, "probability": 100, "activateConditions": "!100300290", "sustainConditions": "!100300290", "fValues": [3.24], "values": [1], "targetType": 1}, {"id": 100300294, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": 100, "efficacyType": 24, "probability": 100, "fValues": [15], "targetType": 1}]', 2, 2, true)
,(20014, '2025-09-10T02:22:53Z', 10, '[{"id": 100900020, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 31, "probability": 100, "fValues": [0], "values": [0, 5], "targetType": 1}, {"id": 100200141, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 43, "probability": 100, "activateConditions": "!100200142&!100900026&100200141&100200140", "fValues": [100, 0.9, 0.2], "values": [100, 100], "targetType": 1}, {"id": 100200140, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 1, "probability": 100, "fValues": [0.45], "values": [3], "targetType": 1}, {"id": 100200142, "abilityEfficacyGroupId": 10000001, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 24, "probability": 100, "activateConditions": "!100200142&100200141&100200140", "targetConditions": "100900025&!100900022", "targetType": 1}, {"id": 100200144, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": 100, "efficacyType": 24, "probability": 100, "activateConditions": "!100200142", "targetConditions": "100900023", "fValues": [999], "values": [1], "targetType": 1}, {"id": 100200145, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 65, "probability": 100, "activateConditions": "!100200142&100200141&100200140", "fValues": [0], "values": [100900020, 1], "targetType": 1}, {"id": 100200143, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 145, "probability": 100, "activateConditions": "100200142", "values": [100900020], "targetType": 1}, {"id": 100200146, "abilityEfficacyGroupId": 100200146, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 24, "probability": 100, "activateConditions": "100200141&100200140", "targetType": 2}, {"id": 100900021, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 126, "probability": 100, "fValues": [1], "values": [5, 100900020], "targetType": 1}, {"id": 100200147, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 24, "probability": 100, "targetType": 2}]', 2, 3, true)
,(20005, '2025-09-10T02:22:53Z', 10, '[{"id": 100200051, "abilityEfficacyGroupId": 100200051, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": 5000, "efficacyType": 29, "probability": 100, "activateConditions": "100200053&100200055", "deactivateConditions": "100200055", "fValues": [3.33], "values": [8], "targetType": 1}, {"id": 100200050, "abilityEfficacyGroupId": 100200050, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": 1, "efficacyType": 29, "probability": 100, "activateConditions": "!100200056&100200053", "sustainConditions": "!100200056", "fValues": [3.33], "values": [8], "targetType": 1}, {"id": 100200055, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": 100, "efficacyType": 24, "probability": 100, "fValues": [30], "targetType": 1}]', 2, 4, true)
,(20003, '2025-09-10T02:22:53Z', 10, '[{"id": 100200030, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": -1, "efficacyType": 73, "probability": 100, "fValues": [0, 3, 1.08], "values": [1, 1, 7, 0, 0], "targetType": 1}, {"id": 100200031, "coolTimeMillisecond": -1, "effectCoolTimeMillisecond": -1, "activeTimeMillisecond": 100, "efficacyType": 24, "probability": 100, "activateConditions": "100200031&100200032", "fValues": [7.5], "targetType": 1}]', 2, 5, true)
;

INSERT INTO characters
(characterId, exp, hp, attack, defense, maxHp, receivedAt, characterOwnershipType,
criticalRate, criticalDamageRate, movementSpeed, damageInflictedRate, tensionIncreaseRate,
cpRecastRate, spGaugeIncreaseRate, attackSpeed, characterCostumeId, abnormalityParamSet,
trainingScoreLevelScore, trainingScoreRankScore, actionPointMax,
actionPointRate, actionPointConsumption, damageTakenRate)
VALUES
(100101, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1001001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
;

INSERT INTO gates (fromAreaId, fromPosX, fromPosY, fromPosZ, toAreaId, toPosX, toPosY, toPosZ, toDirection)
VALUES
(300402, -11.2500019, 53.5918961, -15.75, 300401, -4.15, 53.61689, -17.95, 3)
;

INSERT INTO userData (keyName, val)
VALUES
("status", '{"rank": 1, "staminaUpdatedAt": "2025-09-10T02:22:51Z", "formationNumber": 1, "currentAreaKeyId": 300402, "currentDirection": 3, "loggedInAt": "2025-09-17T00:18:05Z", "currentPositionCoordinates": {"x": -4.15, "y": 53.61689, "z": -17.95}, "currentAreaType": 1}')
;

INSERT INTO areaBgm (areaId, id, eventName)
VALUES
(300402, 3101, 'bgm_story_serious_02')
,(300401, 1002, 'bgm_adv_00_basic_01')
;

-- Area 300402

INSERT INTO areaObjects (areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)
VALUES
(300402, 309001, 300402901, 30900101, '{"type": 3, "id": 1, "sequenceId": 30900101, "label": "Hoimi"}')
,(300402, 309901, 300402991, 30990101, '{"type": 3, "id": 1, "sequenceId": 30990101}')
;

INSERT INTO tipRelease (tipId, areaId, areaObjectId, newAreaPointId, newAreaObjectBehaviorId, newAction)
VALUES (3012, 300402, 309901, 300402991, 30990102, '{"type": 7, "id": 1}')
;

-- Area 300401
INSERT INTO areaEnemies (areaId, areaPointId, areaEnemyRateSetId, action)
VALUES
(300401, 300401701, 300401701, '{"type": 5, "areaEnemyId": 300401701, "battleEntryId": 2000016}')
,(300401, 300401702, 300401702, '{"type": 5, "areaEnemyId": 300401702, "battleEntryId": 2000015}')
,(300401, 300401703, 300401703, '{"type": 5, "areaEnemyId": 300401703, "battleEntryId": 2000041}')
,(300401, 300401704, 300401704, '{"type": 5, "areaEnemyId": 300401704, "battleEntryId": 2000037}')
,(300401, 300401705, 300401705, '{"type": 5, "areaEnemyId": 300401705, "battleEntryId": 2000033}')
,(300401, 300401706, 300401706, '{"type": 5, "areaEnemyId": 300401706, "battleEntryId": 2000039}')
,(300401, 300401709, 300401709, '{"type": 5, "areaEnemyId": 300401709, "battleEntryId": 2000031}')
;
INSERT INTO areaObjects (areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)
VALUES
(300401, 305009, 300401507, 30500901, '{"type": 7, "id": 1}')
,(300401, 700034, 300401139, 7000294, '{"type": 7, "id": 1}')
,(300401, 308001, 300401801, 30800101, '{"type": 1, "id": 1}')
,(300401, 308003, 300401804, 30800301, '{"type": 1, "id": 1}')
,(300401, 800024, 300401008, 8000176, '{"type": 1, "id": 1}')
,(300401, 308002, 300401802, 30800201, '{"type": 3, "id": 1, "sequenceId": 30800201, "label": "Control Panel"}')
,(300401, 309101, 300401910, 30910101, '{"type": 3, "id": 1, "sequenceId": 30910101, "label": "Respite Unit"}')
,(300401, 309102, 300401911, 30910201, '{"type": 3, "id": 1, "sequenceId": 30910201, "label": "Respite Unit"}')
,(300401, 700013, 300401107, 7000391, '{"type": 3, "id": 1, "sequenceId": 7000391, "label": "Roku Saigo"}')
,(300401, 700014, 300401102, 7000341, '{"type": 3, "id": 1, "sequenceId": 7000341, "label": "Enoki Yukigaya"}')
,(300401, 700027, 300401101, 7000331, '{"type": 3, "id": 1, "sequenceId": 7000331, "label": "Eiji Todoroki"}')
,(300401, 700028, 300401135, 7000711, '{"type": 3, "id": 1, "sequenceId": 7000471, "label": "Miu Jujo"}')
,(300401, 700029, 300401125, 7000571, '{"type": 3, "id": 1, "sequenceId": 7000361, "label": "Tsuruko Semba"}')
,(300401, 700030, 300401124, 7000561, '{"type": 3, "id": 1, "sequenceId": 7000431, "label": "Koishi Kohinata"}')
,(300401, 700035, 300401108, 7000401, '{"type": 3, "id": 1, "sequenceId": 7000401, "label": "Kazuki Aoyama"}')
,(300401, 700036, 300401109, 7000411, '{"type": 3, "id": 1, "sequenceId": 7000401, "label": "Q"}')
,(300401, 700037, 300401136, 7000721, '{"type": 3, "id": 1, "sequenceId": 7000421, "label": "Jio Takinogawa"}')
,(300401, 700127, 300401163, 7001271, '{"type": 3, "id": 1, "sequenceId": 7001271}')
,(300401, 800001, 300401011, 8000151, '{"type": 3, "id": 1, "sequenceId": 8000162}')
,(300401, 305003, 300401501, 30500301, '{"type": 4, "areaItemId": 30500301, "id": 1, "label": "Regular Chest"}')
,(300401, 305006, 300401504, 30500601, '{"type": 4, "areaItemId": 30500601, "id": 1, "label": "Regular Chest"}')
,(300401, 305007, 300401505, 30500702, '{"type": 4, "areaItemId": 30500702, "id": 1, "label": "Valuable Chest"}')
,(300401, 305008, 300401506, 30500801, '{"type": 4, "areaItemId": 30500801, "id": 1, "label": "Regular Chest"}')
,(300401, 307013, 300401707, 30701301, '{"type": 5, "id": 1, "areaEnemyId": 300401708, "battleEntryId": 2000042}')
;
INSERT INTO areaItems (areaId, areaItemId)
VALUES
(300401, 30500301)
,(300401, 30500601)
,(300401, 30500702)
,(300401, 30500801)
,(300401, 30600501)
,(300401, 30600601)
,(300401, 30600701)
,(300401, 30600801)
,(300401, 30600901)
,(300401, 30601001)
,(300401, 30601101)
,(300401, 30601201)
,(300401, 30601301)
,(300401, 30601401)
,(300401, 300401611)
,(300401, 300401612)
,(300401, 300401613)
,(300401, 300401614)
,(300401, 300401615)
;