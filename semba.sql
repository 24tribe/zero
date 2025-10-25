DROP TABLE IF EXISTS debugLogsOffline;
CREATE TABLE debugLogsOffline (
    receivedAt STRING,
    uri STRING,
    req STRING,
    res STRING
);

DROP TABLE IF EXISTS areaObjects;
CREATE TABLE areaObjects (
    areaId INTEGER,
    areaObjectId INTEGER PRIMARY KEY,
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
    challengeProgressId INTEGER PRIMARY KEY,
    clearedAt STRING,
    state INTEGER
);

DROP TABLE IF EXISTS nineSequences;
CREATE TABLE nineSequences (
    nineSequenceId INTEGER PRIMARY KEY,
    content STRING
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

DROP TABLE IF EXISTS tutorialStates;
CREATE TABLE tutorialStates (
    tutorialStatusKey INTEGER,
    enabled STRING
);

DROP TABLE IF EXISTS shopProducts;
CREATE TABLE shopProducts (
    val STRING
);

DROP TABLE IF EXISTS battleParameters;
CREATE TABLE battleParameters (
    id INTEGER,
    enemies STRING
);

DROP TABLE IF EXISTS formations;
CREATE TABLE formations (
    number INTEGER,
    members STRING,
    cards STRING
);

DROP TABLE IF EXISTS readSequence;
CREATE TABLE readSequence (
    sequenceRequestId INTEGER,
    areaObjects STRING,
    changedResources STRING
);

DROP TABLE IF EXISTS adventureVariables;
CREATE TABLE adventureVariables (
    adventureVariableId INTEGER PRIMARY KEY,
    value INTEGER
);

DROP TABLE IF EXISTS challengeTasks;
CREATE TABLE challengeTasks (
    challengeTaskId INTEGER PRIMARY KEY,
    clearedAt STRING,
    count INTEGER
);

DROP TABLE IF EXISTS battleFinishAreaObjects;
CREATE TABLE battleFinishAreaObjects(
    battleEntryId INTEGER PRIMARY KEY,
    areaObjects STRING
);

DROP TABLE IF EXISTS areaActionSequenceIds;
CREATE TABLE areaActionSequenceIds (
    areaId INTEGER PRIMARY KEY,
    actionSequenceId INTEGER
);

DROP TABLE IF EXISTS readSequenceAreaAction;
CREATE TABLE readSequenceAreaAction (
    sequenceRequestId INTEGER PRIMARY KEY,
    areaId INTEGER,
    actionSequenceId INTEGER
);

DROP TABLE IF EXISTS readSequenceAreaBgm;
CREATE TABLE readSequenceAreaBgm (
    sequenceRequestId INTEGER PRIMARY KEY,
    areaId INTEGER,
    id INTEGER,
    eventName STRING
);

INSERT INTO readSequenceAreaBgm (sequenceRequestId, areaId, id, eventName) VALUES
(70012711, 300401, 1002, 'bgm_adv_00_basic_01')
, (308002021, 300401, 1002, 'bgm_adv_00_basic_01')
, (80001621, 300401, 1002, 'bgm_adv_00_basic_01')
, (80001911, 300401, 1003, 'bgm_btl_boss_24city_01')
, (80004021, 300501, 1005, '')
, (80002111, 300501, 1006, 'bgm_story_xb_01')
, (90000006, 300501, 1007, 'bgm_adv_00_basic_01')
, (80100111, 101381, 1502, '')
, (80100211, 101381, 1503, 'bgm_adv_01_hotel')
;

INSERT INTO areaActionSequenceIds (areaId, actionSequenceId) VALUES
(300501, 8000191)
, (101381, 8010021)
;

INSERT INTO readSequenceAreaAction (sequenceRequestId, areaId, actionSequenceId) VALUES
(70012711, 300401, 0)
, (308002021, 300401, 0)
, (80001621, 300401, 0)
, (80001911, 300401, 0)
, (80004021, 300501, 8000201)
, (80002111, 300501, 8000211)
, (90000006, 300501, 8010011)
, (80100111, 101381, 8010021)
, (80100211, 101381, 0)
;

INSERT INTO battleFinishAreaObjects (battleEntryId, areaObjects) VALUES
(1000004, '[{"areaObjectId": 800025, "areaPointId": 300401010, "areaObjectBehaviorId": 8000184, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700112, "areaPointId": 300401162, "areaObjectBehaviorId": 7001123, "action": {"type": 3, "id": 1, "sequenceId": 7000981, "label": "Sui Yakumo"}}, {"areaObjectId": 700111, "areaPointId": 300401161, "areaObjectBehaviorId": 7001113, "action": {"type": 3, "id": 1, "sequenceId": 7000971, "label": "Tsuki Iroha"}}, {"areaObjectId": 700037, "areaPointId": 300401140, "areaObjectBehaviorId": 7000751, "action": {"type": 3, "id": 1, "sequenceId": 7000901, "label": "Jio Takinogawa"}}, {"areaObjectId": 700036, "areaPointId": 300401144, "areaObjectBehaviorId": 7000791, "action": {"type": 3, "id": 1, "sequenceId": 7000921, "label": "Q"}}, {"areaObjectId": 700035, "areaPointId": 300401145, "areaObjectBehaviorId": 7000801, "action": {"type": 3, "id": 1, "sequenceId": 7000922, "label": "Kazuki Aoyama"}}, {"areaObjectId": 700034, "areaPointId": 300401142, "areaObjectBehaviorId": 7000771, "action": {"type": 3, "id": 1, "sequenceId": 7000911, "label": "Hyakuichitaro Senju"}}, {"areaObjectId": 700030, "areaPointId": 300401143, "areaObjectBehaviorId": 7000781, "action": {"type": 3, "id": 1, "sequenceId": 7000912, "label": "Koishi Kohinata"}}, {"areaObjectId": 700029, "areaPointId": 300401149, "areaObjectBehaviorId": 7000841, "action": {"type": 3, "id": 1, "sequenceId": 7000942, "label": "Tsuruko Semba"}}, {"areaObjectId": 700028, "areaPointId": 300401141, "areaObjectBehaviorId": 7000761, "action": {"type": 3, "id": 1, "sequenceId": 7000902, "label": "Miu Jujo"}}, {"areaObjectId": 700027, "areaPointId": 300401148, "areaObjectBehaviorId": 7000831, "action": {"type": 3, "id": 1, "sequenceId": 7000941, "label": "Eiji Todoroki"}}, {"areaObjectId": 700014, "areaPointId": 300401147, "areaObjectBehaviorId": 7000821, "action": {"type": 3, "id": 1, "sequenceId": 7000932, "label": "Enoki Yukigaya"}}, {"areaObjectId": 700013, "areaPointId": 300401146, "areaObjectBehaviorId": 7000811, "action": {"type": 3, "id": 1, "sequenceId": 7000931, "label": "Roku Saigo"}}]')
;

INSERT INTO readSequence (sequenceRequestId, areaObjects, changedResources) VALUES 
(70012711, '[{"areaObjectId": 700127, "areaPointId": 300401163, "areaObjectBehaviorId": 7001272, "action": {"type": 7, "id": 1}}]', '{"status": {"rank": 1, "staminaUpdatedAt": "2025-09-30T19:36:05Z", "formationNumber": 1, "currentAreaKeyId": 300401, "currentDirection": 7, "loggedInAt": "2025-10-01T22:51:41Z", "currentPositionCoordinates": {"x": 43.58103, "y": 21.6710052, "z": -21.4567089}, "currentAreaType": 1}, "nineSequences": [{"nineSequenceId": 95001001, "choices": "{\"Selections\":[]}", "lastReadAt": "2025-10-01T22:53:26Z"}], "adventureVariables": [{"adventureVariableId": 800027, "value": 1}]}')
,(308002021, '[{"areaObjectId": 308003, "areaPointId": 300401804, "areaObjectBehaviorId": 30800302, "action": {"type": 1, "id": 1}}, {"areaObjectId": 308002, "areaPointId": 300401802, "areaObjectBehaviorId": 30800202, "action": {"type": 3, "id": 1, "sequenceId": 30800201}}, {"areaObjectId": 308001, "areaPointId": 300401801, "areaObjectBehaviorId": 30800102, "action": {"type": 1, "id": 1}}, {"areaObjectId": 305009, "areaPointId": 300401507, "areaObjectBehaviorId": 30500902, "action": {"type": 4, "areaItemId": 30500902, "id": 1, "label": "Valuable Chest"}}]', '{"status": {"rank": 1, "staminaUpdatedAt": "2025-09-30T19:36:05Z", "formationNumber": 1, "currentAreaKeyId": 300401, "currentDirection": 2, "loggedInAt": "2025-10-01T22:51:41Z", "currentPositionCoordinates": {"x": 72.45, "y": 19.6710052, "z": -35.0720749}, "currentAreaType": 1}}')
,(80001621, '[{"areaObjectId": 800001, "areaPointId": 300401006, "areaObjectBehaviorId": 8000181, "action": {"type": 3, "id": 1, "sequenceId": 8000181}}, {"areaObjectId": 700112, "areaPointId": 300401176, "areaObjectBehaviorId": 7001127, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700037, "areaPointId": 300401164, "areaObjectBehaviorId": 7001200, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700036, "areaPointId": 300401172, "areaObjectBehaviorId": 7001216, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700035, "areaPointId": 300401173, "areaObjectBehaviorId": 7001218, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700034, "areaPointId": 300401167, "areaObjectBehaviorId": 7001206, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700030, "areaPointId": 300401166, "areaObjectBehaviorId": 7001204, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700029, "areaPointId": 300401168, "areaObjectBehaviorId": 7001208, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700028, "areaPointId": 300401165, "areaObjectBehaviorId": 7001202, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700027, "areaPointId": 300401169, "areaObjectBehaviorId": 7001210, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700014, "areaPointId": 300401171, "areaObjectBehaviorId": 7001214, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700013, "areaPointId": 300401170, "areaObjectBehaviorId": 7001212, "action": {"type": 1, "id": 1}}]', '{"status": {"rank": 1, "staminaUpdatedAt": "2025-09-30T19:36:05Z", "formationNumber": 1, "currentAreaKeyId": 300401, "currentDirection": 1, "loggedInAt": "2025-10-01T22:51:41Z", "currentPositionCoordinates": {"x": 83.65211, "y": 17.6870041, "z": -16.154192}, "currentAreaType": 1}, "challengeProgresses": [{"challengeProgressId": 1000162, "clearedAt": "2025-10-01T22:55:23Z", "state": 3}, {"challengeProgressId": 1000191, "state": 2}], "challengeTasks": [{"challengeTaskId": 10001621, "clearedAt": "2025-10-01T22:55:23Z", "count": 1}], "nineSequences": [{"nineSequenceId": 95013001, "choices": "{\"Selections\":[]}", "lastReadAt": "2025-10-01T22:55:23Z"}]}')
,(80001911, '[{"areaObjectId": 800025, "areaPointId": 300401010, "areaObjectBehaviorId": 8000183, "action": {"type": 3, "id": 1, "battleEntryId": 1000004, "sequenceId": 8000182, "label": "Lv 3"}}, {"areaObjectId": 800001, "areaPointId": 300401006, "areaObjectBehaviorId": 8000211, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700112, "areaPointId": 300401175, "areaObjectBehaviorId": 7001125, "action": {"type": 1, "id": 1, "label": "Sui Yakumo"}}, {"areaObjectId": 700111, "areaPointId": 300401174, "areaObjectBehaviorId": 7001115, "action": {"type": 1, "id": 1, "label": "Tsuki Iroha"}}, {"areaObjectId": 700037, "areaPointId": 300401151, "areaObjectBehaviorId": 7000901, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700036, "areaPointId": 300401159, "areaObjectBehaviorId": 7000981, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700035, "areaPointId": 300401160, "areaObjectBehaviorId": 7000991, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700034, "areaPointId": 300401154, "areaObjectBehaviorId": 7000931, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700030, "areaPointId": 300401153, "areaObjectBehaviorId": 7000921, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700029, "areaPointId": 300401155, "areaObjectBehaviorId": 7000941, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700028, "areaPointId": 300401152, "areaObjectBehaviorId": 7000911, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700027, "areaPointId": 300401156, "areaObjectBehaviorId": 7000951, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700014, "areaPointId": 300401158, "areaObjectBehaviorId": 7000971, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700013, "areaPointId": 300401157, "areaObjectBehaviorId": 7000961, "action": {"type": 1, "id": 1}}]', '{"status": {"rank": 1, "staminaUpdatedAt": "2025-09-30T19:36:05Z", "formationNumber": 1, "currentAreaKeyId": 300401, "currentDirection": 1, "loggedInAt": "2025-10-01T22:51:41Z", "currentPositionCoordinates": {"x": 99.3, "y": 11.0309982, "z": -5.75}, "currentAreaType": 1}, "challengeProgresses": [{"challengeProgressId": 1000191, "clearedAt": "2025-10-01T22:58:07Z", "state": 3}, {"challengeProgressId": 1000192, "state": 2}], "challengeTasks": [{"challengeTaskId": 10001911, "clearedAt": "2025-10-01T22:58:07Z", "count": 1}]}')
,(80004021, '[{"areaObjectId": 800024, "areaPointId": 300401008, "areaObjectBehaviorId": 8000177, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700112, "areaPointId": 300401162, "areaObjectBehaviorId": 7001124, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700111, "areaPointId": 300401161, "areaObjectBehaviorId": 7001114, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700037, "areaPointId": 300401140, "areaObjectBehaviorId": 7000752, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700036, "areaPointId": 300401144, "areaObjectBehaviorId": 7000792, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700035, "areaPointId": 300401145, "areaObjectBehaviorId": 7000802, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700034, "areaPointId": 300401142, "areaObjectBehaviorId": 7000772, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700030, "areaPointId": 300401143, "areaObjectBehaviorId": 7000782, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700029, "areaPointId": 300401149, "areaObjectBehaviorId": 7000842, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700028, "areaPointId": 300401141, "areaObjectBehaviorId": 7000762, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700027, "areaPointId": 300401148, "areaObjectBehaviorId": 7000832, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700014, "areaPointId": 300401147, "areaObjectBehaviorId": 7000822, "action": {"type": 7, "id": 1}}, {"areaObjectId": 700013, "areaPointId": 300401146, "areaObjectBehaviorId": 7000812, "action": {"type": 7, "id": 1}}]', '{"status": {"rank": 1, "staminaUpdatedAt": "2025-09-30T19:36:05Z", "formationNumber": 1, "currentAreaKeyId": 300501, "currentDirection": 1, "loggedInAt": "2025-10-01T22:51:41Z", "currentPositionCoordinates": {"x": -0.02, "y": 18.0416679, "z": -12.333}, "currentAreaType": 1}, "challengeProgresses": [{"challengeProgressId": 1000201, "clearedAt": "2025-10-01T23:02:14Z", "state": 3}, {"challengeProgressId": 1000211, "state": 2}], "challengeTasks": [{"challengeTaskId": 10002011, "clearedAt": "2025-10-01T23:02:14Z", "count": 1}], "adventureVariables": [{"adventureVariableId": 800011, "value": 6}]}')
,(80002111, '', '{"status": {"rank": 1, "staminaUpdatedAt": "2025-09-30T19:36:05Z", "formationNumber": 1, "currentAreaKeyId": 300501, "currentDirection": 1, "loggedInAt": "2025-10-01T22:51:41Z", "currentPositionCoordinates": {"x": -0.02, "y": 18.0416679, "z": -12.333}, "currentAreaType": 1}, "challengeProgresses": [{"challengeProgressId": 1000211, "clearedAt": "2025-10-01T23:03:10Z", "state": 3}, {"challengeProgressId": 1000221, "state": 2}], "challengeTasks": [{"challengeTaskId": 10002111, "clearedAt": "2025-10-01T23:03:10Z", "count": 1}]}')
,(90000006, '', '{"status": {"rank": 1, "staminaUpdatedAt": "2025-09-30T19:36:05Z", "formationNumber": 1, "currentAreaKeyId": 300501, "currentDirection": 1, "loggedInAt": "2025-10-01T23:08:14Z", "currentPositionCoordinates": {"x": -0.02, "y": 18.0416679, "z": -12.333}, "currentAreaType": 1}}')
,(80100111, '[{"areaObjectId": 700114, "areaPointId": 100421102, "areaObjectBehaviorId": 7010803, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700113, "areaPointId": 100421101, "areaObjectBehaviorId": 7010801, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700110, "areaPointId": 101001101, "areaObjectBehaviorId": 7010709, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700073, "areaPointId": 100101102, "areaObjectBehaviorId": 7010352, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700057, "areaPointId": 101381103, "areaObjectBehaviorId": 7010131, "action": {"type": 3, "id": 1, "sequenceId": 7000821, "label": "Bed"}}, {"areaObjectId": 700056, "areaPointId": 101381102, "areaObjectBehaviorId": 7010121, "action": {"type": 3, "id": 1, "sequenceId": 7000811, "label": "Window"}}, {"areaObjectId": 700055, "areaPointId": 101381101, "areaObjectBehaviorId": 7010111, "action": {"type": 3, "id": 1, "sequenceId": 7000801, "label": "Houseplant"}}, {"areaObjectId": 100131, "areaPointId": 101001201, "areaObjectBehaviorId": 10013101, "action": {"type": 3, "id": 1, "sequenceId": 10013101, "label": "Kujira"}}, {"areaObjectId": 100128, "areaPointId": 101511201, "areaObjectBehaviorId": 10012801, "action": {"type": 3, "id": 1, "sequenceId": 10012801, "label": "Kujira"}}, {"areaObjectId": 100122, "areaPointId": 101001208, "areaObjectBehaviorId": 10012107, "action": {"type": 1, "id": 1}}, {"areaObjectId": 100121, "areaPointId": 101001207, "areaObjectBehaviorId": 10012101, "action": {"type": 3, "id": 1, "sequenceId": 10012101, "label": "Kotora"}}, {"areaObjectId": 100094, "areaPointId": 100221205, "areaObjectBehaviorId": 10009401, "action": {"type": 3, "id": 1, "sequenceId": 10009401, "label": "CHIKARA"}}, {"areaObjectId": 100091, "areaPointId": 101317201, "areaObjectBehaviorId": 10005411, "action": {"type": 3, "id": 1, "sequenceId": 10005411, "label": "Honko"}}, {"areaObjectId": 100072, "areaPointId": 100401202, "areaObjectBehaviorId": 10007101, "action": {"type": 3, "id": 1, "sequenceId": 10007101, "label": "Sumisu"}}, {"areaObjectId": 100071, "areaPointId": 100401203, "areaObjectBehaviorId": 10007103, "action": {"type": 3, "id": 1, "sequenceId": 10007105, "label": "Sugo"}}, {"areaObjectId": 100070, "areaPointId": 100301201, "areaObjectBehaviorId": 10006901, "action": {"type": 3, "id": 1, "sequenceId": 10006901, "label": "Sumisu"}}, {"areaObjectId": 100069, "areaPointId": 100301202, "areaObjectBehaviorId": 10006903, "action": {"type": 3, "id": 1, "sequenceId": 10006905, "label": "Sugo"}}, {"areaObjectId": 100054, "areaPointId": 100411205, "areaObjectBehaviorId": 10005401, "action": {"type": 3, "id": 1, "sequenceId": 10005401, "label": "Honko"}}, {"areaObjectId": 100050, "areaPointId": 100221201, "areaObjectBehaviorId": 10005001, "action": {"type": 3, "id": 1, "sequenceId": 10005001, "label": "Ranche"}}, {"areaObjectId": 100032, "areaPointId": 101389201, "areaObjectBehaviorId": 10003201, "action": {"type": 3, "id": 1, "sequenceId": 10003201, "label": "Madam Bonnet"}}, {"areaObjectId": 100025, "areaPointId": 101388201, "areaObjectBehaviorId": 10002501, "action": {"type": 3, "id": 1, "sequenceId": 10002501, "label": "Tattered Sesami"}}, {"areaObjectId": 100023, "areaPointId": 101387201, "areaObjectBehaviorId": 10002301, "action": {"type": 3, "id": 1, "sequenceId": 10002301, "label": "Timid Hibisato"}}, {"areaObjectId": 100021, "areaPointId": 101386201, "areaObjectBehaviorId": 10002101, "action": {"type": 3, "id": 1, "sequenceId": 10002101, "label": "Clean-Freak Waka"}}, {"areaObjectId": 100019, "areaPointId": 101384201, "areaObjectBehaviorId": 10001901, "action": {"type": 3, "id": 1, "sequenceId": 10001901, "label": "Higashimachi"}}]', '{"status": {"rank": 1, "staminaUpdatedAt": "2025-09-30T19:36:05Z", "formationNumber": 1, "currentAreaKeyId": 101381, "currentDirection": 5, "loggedInAt": "2025-10-01T23:08:14Z", "currentPositionCoordinates": {"x": -3.4, "y": 0.0266666412, "z": 2.29}, "currentAreaType": 1}, "challenges": [{"challengeId": 100131, "state": 8}, {"challengeId": 100151, "state": 8}, {"challengeId": 100171, "state": 8}, {"challengeId": 100181, "state": 8}, {"challengeId": 100182, "state": 8}, {"challengeId": 100191, "state": 8}, {"challengeId": 100192, "state": 8}, {"challengeId": 100201, "state": 8}, {"challengeId": 100202, "state": 8}, {"challengeId": 100203, "state": 8}, {"challengeId": 100212, "state": 8}, {"challengeId": 100213, "state": 8}, {"challengeId": 100222, "state": 8}, {"challengeId": 100223, "state": 8}, {"challengeId": 100231, "state": 8}, {"challengeId": 100241, "state": 8}, {"challengeId": 104001, "state": 8}, {"challengeId": 104011, "state": 8}, {"challengeId": 104021, "state": 8}, {"challengeId": 104031, "state": 8}, {"challengeId": 101, "state": 5}], "challengeProgresses": [{"challengeProgressId": 10013101, "state": 2}, {"challengeProgressId": 10015101, "state": 2}, {"challengeProgressId": 10017101, "state": 2}, {"challengeProgressId": 10018101, "state": 2}, {"challengeProgressId": 10018201, "state": 2}, {"challengeProgressId": 10019101, "state": 2}, {"challengeProgressId": 10019201, "state": 2}, {"challengeProgressId": 10020101, "state": 2}, {"challengeProgressId": 10020201, "state": 2}, {"challengeProgressId": 10020301, "state": 2}, {"challengeProgressId": 10021201, "state": 2}, {"challengeProgressId": 10021301, "state": 2}, {"challengeProgressId": 10022201, "state": 2}, {"challengeProgressId": 10022301, "state": 2}, {"challengeProgressId": 10023101, "state": 2}, {"challengeProgressId": 10024101, "state": 2}, {"challengeProgressId": 10400101, "state": 2}, {"challengeProgressId": 10401101, "state": 2}, {"challengeProgressId": 10402101, "state": 2}, {"challengeProgressId": 10403101, "state": 2}, {"challengeProgressId": 1010011, "clearedAt": "2025-10-01T23:14:24Z", "state": 3}, {"challengeProgressId": 1010021, "state": 2}], "challengeTasks": [{"challengeTaskId": 10100111, "clearedAt": "2025-10-01T23:14:24Z", "count": 1}], "cities": [{"cityId": 10, "releasedAt": "2025-10-01T23:14:24Z"}], "tutorialStates": [{"tutorialStatusKey": 14, "enabled": true}]}')
,(80100211, '[{"areaObjectId": 801059, "areaPointId": 101316005, "areaObjectBehaviorId": 8010057, "action": {"type": 3, "id": 1, "sequenceId": 8010041}}, {"areaObjectId": 801058, "areaPointId": 101316004, "areaObjectBehaviorId": 8010055, "action": {"type": 3, "id": 1, "sequenceId": 8010041}}, {"areaObjectId": 801001, "areaPointId": 101316001, "areaObjectBehaviorId": 8010041, "action": {"type": 3, "id": 1, "sequenceId": 8010041}}, {"areaObjectId": 700109, "areaPointId": 101316103, "areaObjectBehaviorId": 7010103, "action": {"type": 1, "id": 1}}, {"areaObjectId": 700058, "areaPointId": 101312102, "areaObjectBehaviorId": 7010711, "action": {"type": 3, "id": 1, "sequenceId": 7010711}}, {"areaObjectId": 700057, "areaPointId": 101381103, "areaObjectBehaviorId": 7010132, "action": {"type": 3, "id": 1, "sequenceId": 7000822, "label": "Bed"}}, {"areaObjectId": 700056, "areaPointId": 101381102, "areaObjectBehaviorId": 7010122, "action": {"type": 3, "id": 1, "sequenceId": 7000812, "label": "Window"}}, {"areaObjectId": 700055, "areaPointId": 101381101, "areaObjectBehaviorId": 7010112, "action": {"type": 3, "id": 1, "sequenceId": 7000802, "label": "Houseplant"}}, {"areaObjectId": 700053, "areaPointId": 101311120, "areaObjectBehaviorId": 7010713, "action": {"type": 3, "id": 1, "sequenceId": 7010713}}]', '{"status": {"rank": 1, "staminaUpdatedAt": "2025-09-30T19:36:05Z", "formationNumber": 1, "currentAreaKeyId": 101381, "currentDirection": 5, "loggedInAt": "2025-10-01T23:08:14Z", "currentPositionCoordinates": {"x": -3.4, "y": 0.0266666412, "z": 2.29}, "currentAreaType": 1}, "challengeProgresses": [{"challengeProgressId": 1010021, "clearedAt": "2025-10-01T23:15:04Z", "state": 3}, {"challengeProgressId": 1010041, "state": 2}], "challengeTasks": [{"challengeTaskId": 10100211, "clearedAt": "2025-10-01T23:15:04Z", "count": 1}], "nineSequences": [{"nineSequenceId": 10000001, "choices": "{\"Selections\":[]}", "lastReadAt": "2025-10-01T23:15:04Z"}]}')
;

INSERT INTO formations (number, members, cards)
VALUES
(0, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
,(1, '{"character1Id": 100101, "character1OwnershipType": 1}', '{"tensionCard1Id": 5, "tensionCard2Id": 4, "tensionCard3Id": 3, "tensionCard4Id": 2, "tensionCard5Id": 1}')
,(2, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
,(3, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
,(4, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
,(5, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
,(6, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
,(7, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
,(8, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
,(9, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
,(10, '{"character1Id": 100101, "character1OwnershipType": 1}', '{}')
;

INSERT INTO battleParameters (id, enemies) VALUES 
(2000016, '[{"id": 224105, "attack": 228, "defense": 100, "hp": 6864, "isSkipEncounterAnimation": true, "hpStackCount": 0}, {"id": 224105, "attack": 228, "defense": 100, "hp": 6864, "isSkipEncounterAnimation": true, "hpStackCount": 0}]')
, (2000015, '[{"id": 250108, "attack": 228, "defense": 100, "hp": 3432, "isSkipEncounterAnimation": true, "hpStackCount": 0}, {"id": 250108, "attack": 228, "defense": 100, "hp": 3432, "isSkipEncounterAnimation": true, "hpStackCount": 0}]')
, (2000042, '[{"id": 224303, "attack": 270, "defense": 100, "hp": 17108, "hpStackCount": 1}, {"id": 224303, "attack": 270, "defense": 100, "hp": 17108, "hpStackCount": 1}]')
, (2000039, '[{"id": 224207, "attack": 245, "defense": 100, "hp": 5703, "hpStackCount": 0}, {"id": 224207, "attack": 245, "defense": 100, "hp": 5703, "hpStackCount": 0}]')
, (2000033, '[{"id": 224107, "attack": 245, "defense": 100, "hp": 6416, "hpStackCount": 0}, {"id": 224105, "attack": 245, "defense": 100, "hp": 7128, "isSkipEncounterAnimation": true, "hpStackCount": 0}, {"id": 224107, "attack": 245, "defense": 100, "hp": 6416, "hpStackCount": 0}]')
, (2000041, '[{"id": 224303, "attack": 270, "defense": 100, "hp": 17108, "isSkipEncounterAnimation": true, "hpStackCount": 1}]')
, (2000037, '[{"id": 250106, "attack": 245, "defense": 100, "hp": 4277, "hpStackCount": 0}, {"id": 250106, "attack": 245, "defense": 100, "hp": 4277, "hpStackCount": 0}]')
, (2000031, '[{"id": 250108, "attack": 245, "defense": 100, "hp": 3564, "isSkipEncounterAnimation": true, "hpStackCount": 0}, {"id": 250106, "attack": 245, "defense": 100, "hp": 4277, "isSkipEncounterAnimation": true, "hpStackCount": 0}, {"id": 250108, "attack": 245, "defense": 100, "hp": 3564, "isSkipEncounterAnimation": true, "hpStackCount": 0}]')
, (1000004, '[{"id": 257101, "attack": 210, "defense": 100, "hp": 85536, "hpStackCount": 3}]')
;

INSERT INTO shopProducts (val)
VALUES
('{"id": 101, "imagePath": "ui_shop_item_icon_eniguma_01", "priority": 87, "endAt": "2025-05-15T06:00:00Z", "purchaseSteps": [{"storeProductId": 101, "name": "Paid Enigma Entity x68"}, {"storeProductId": 1001, "name": "Paid Enigma Entity x68"}], "shopId": 1}')
,('{"id": 102, "imagePath": "ui_shop_item_icon_eniguma_02", "priority": 88, "endAt": "2025-05-15T06:00:00Z", "purchaseSteps": [{"storeProductId": 102, "name": "Paid Enigma Entity x207"}, {"storeProductId": 1002, "name": "Paid Enigma Entity x207 + Free Enigma Entity x23"}], "shopId": 1}')
,('{"id": 103, "imagePath": "ui_shop_item_icon_eniguma_03", "priority": 89, "endAt": "2025-05-15T06:00:00Z", "purchaseSteps": [{"storeProductId": 103, "name": "Paid Enigma Entity x486"}, {"storeProductId": 1003, "name": "Paid Enigma Entity x486 + Free Enigma Entity x64"}], "shopId": 1}')
,('{"id": 104, "imagePath": "ui_shop_item_icon_eniguma_04", "priority": 90, "endAt": "2025-05-15T06:00:00Z", "purchaseSteps": [{"storeProductId": 104, "name": "Paid Enigma Entity x1396"}, {"storeProductId": 1004, "name": "Paid Enigma Entity x1396 + Free Enigma Entity x214"}], "shopId": 1}')
,('{"id": 105, "imagePath": "ui_shop_item_icon_eniguma_06", "priority": 91, "endAt": "2025-05-15T06:00:00Z", "purchaseSteps": [{"storeProductId": 105, "name": "Paid Enigma Entity x2793"}, {"storeProductId": 1005, "name": "Paid Enigma Entity x2793 + Free Enigma Entity x487"}], "shopId": 1}')
,('{"id": 106, "imagePath": "ui_shop_item_icon_eniguma_07", "priority": 92, "endAt": "2025-05-15T06:00:00Z", "purchaseSteps": [{"storeProductId": 106, "name": "Paid Enigma Entity x4955"}, {"storeProductId": 1006, "name": "Paid Enigma Entity x4955 + Free Enigma Entity x995"}], "shopId": 1}')
,('{"id": 301, "dailyPassId": 301, "priority": 100, "endAt": "2025-05-15T06:00:00Z", "purchaseSteps": [{"storeProductId": 301, "name": "Daily Pass"}], "shopId": 1}')
,('{"id": 4004001, "imagePath": "ui_shop_item_icon_costume_chr008_102", "limitCount": 1, "priority": 49999, "purchaseSteps": [{"rewardSetId": 4004001, "costs": [{"type": 22, "id": 1, "quantity": 120}]}], "shopId": 4}')
,('{"id": 4004002, "imagePath": "ui_shop_item_icon_costume_chr008_103", "limitCount": 1, "priority": 49998, "purchaseSteps": [{"rewardSetId": 4004002, "costs": [{"type": 22, "id": 1, "quantity": 120}]}], "shopId": 4}')
,('{"id": 4004003, "imagePath": "ui_shop_item_icon_costume_chr008_104", "limitCount": 1, "priority": 49997, "purchaseSteps": [{"rewardSetId": 4004003, "costs": [{"type": 22, "id": 1, "quantity": 120}]}], "shopId": 4}')
,('{"id": 4004004, "imagePath": "ui_shop_item_icon_costume_chr005_102", "limitCount": 1, "priority": 19999, "purchaseSteps": [{"rewardSetId": 4004004, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004005, "imagePath": "ui_shop_item_icon_costume_chr005_103", "limitCount": 1, "priority": 19998, "purchaseSteps": [{"rewardSetId": 4004005, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004006, "imagePath": "ui_shop_item_icon_costume_chr005_104", "limitCount": 1, "priority": 19997, "purchaseSteps": [{"rewardSetId": 4004006, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004007, "imagePath": "ui_shop_item_icon_costume_chr012_102", "limitCount": 1, "priority": 19996, "purchaseSteps": [{"rewardSetId": 4004007, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004008, "imagePath": "ui_shop_item_icon_costume_chr012_103", "limitCount": 1, "priority": 19995, "purchaseSteps": [{"rewardSetId": 4004008, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004009, "imagePath": "ui_shop_item_icon_costume_chr012_104", "limitCount": 1, "priority": 19994, "purchaseSteps": [{"rewardSetId": 4004009, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004010, "imagePath": "ui_shop_item_icon_costume_chr006_201", "limitCount": 1, "priority": 19993, "purchaseSteps": [{"rewardSetId": 4004010, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004011, "imagePath": "ui_shop_item_icon_costume_chr009_201", "limitCount": 1, "priority": 19992, "purchaseSteps": [{"rewardSetId": 4004011, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004012, "imagePath": "ui_shop_item_icon_costume_chr010_201", "limitCount": 1, "priority": 19991, "purchaseSteps": [{"rewardSetId": 4004012, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004013, "imagePath": "ui_shop_item_icon_costume_chr011_201", "limitCount": 1, "priority": 19990, "purchaseSteps": [{"rewardSetId": 4004013, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004014, "imagePath": "ui_shop_item_icon_costume_chr012_201", "limitCount": 1, "priority": 19989, "purchaseSteps": [{"rewardSetId": 4004014, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004015, "imagePath": "ui_shop_item_icon_costume_chr014_201", "limitCount": 1, "priority": 19988, "purchaseSteps": [{"rewardSetId": 4004015, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004016, "imagePath": "ui_shop_item_icon_costume_chr015_201", "limitCount": 1, "priority": 19987, "purchaseSteps": [{"rewardSetId": 4004016, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004017, "imagePath": "ui_shop_item_icon_costume_chr001_011", "limitCount": 1, "priority": 9999, "purchaseSteps": [{"rewardSetId": 4004017, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004018, "imagePath": "ui_shop_item_icon_costume_chr001_012", "limitCount": 1, "priority": 9998, "purchaseSteps": [{"rewardSetId": 4004018, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004019, "imagePath": "ui_shop_item_icon_costume_chr001_013", "limitCount": 1, "priority": 9997, "purchaseSteps": [{"rewardSetId": 4004019, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004020, "imagePath": "ui_shop_item_icon_costume_chr001_014", "limitCount": 1, "priority": 9996, "purchaseSteps": [{"rewardSetId": 4004020, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004021, "imagePath": "ui_shop_item_icon_costume_chr001_015", "limitCount": 1, "priority": 9995, "purchaseSteps": [{"rewardSetId": 4004021, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004022, "imagePath": "ui_shop_item_icon_costume_chr001_016", "limitCount": 1, "priority": 9994, "purchaseSteps": [{"rewardSetId": 4004022, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004023, "imagePath": "ui_shop_item_icon_costume_chr001_017", "limitCount": 1, "priority": 9993, "purchaseSteps": [{"rewardSetId": 4004023, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004024, "imagePath": "ui_shop_item_icon_costume_chr001_018", "limitCount": 1, "priority": 9992, "purchaseSteps": [{"rewardSetId": 4004024, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004025, "imagePath": "ui_shop_item_icon_costume_chr002_011", "limitCount": 1, "priority": 9991, "purchaseSteps": [{"rewardSetId": 4004025, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004026, "imagePath": "ui_shop_item_icon_costume_chr002_012", "limitCount": 1, "priority": 9990, "purchaseSteps": [{"rewardSetId": 4004026, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004027, "imagePath": "ui_shop_item_icon_costume_chr002_013", "limitCount": 1, "priority": 9989, "purchaseSteps": [{"rewardSetId": 4004027, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004028, "imagePath": "ui_shop_item_icon_costume_chr002_014", "limitCount": 1, "priority": 9988, "purchaseSteps": [{"rewardSetId": 4004028, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004029, "imagePath": "ui_shop_item_icon_costume_chr002_015", "limitCount": 1, "priority": 9987, "purchaseSteps": [{"rewardSetId": 4004029, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004030, "imagePath": "ui_shop_item_icon_costume_chr002_016", "limitCount": 1, "priority": 9986, "purchaseSteps": [{"rewardSetId": 4004030, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004031, "imagePath": "ui_shop_item_icon_costume_chr002_017", "limitCount": 1, "priority": 9985, "purchaseSteps": [{"rewardSetId": 4004031, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004032, "imagePath": "ui_shop_item_icon_costume_chr002_018", "limitCount": 1, "priority": 9984, "purchaseSteps": [{"rewardSetId": 4004032, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004033, "imagePath": "ui_shop_item_icon_costume_chr003_011", "limitCount": 1, "priority": 9983, "purchaseSteps": [{"rewardSetId": 4004033, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004034, "imagePath": "ui_shop_item_icon_costume_chr003_012", "limitCount": 1, "priority": 9982, "purchaseSteps": [{"rewardSetId": 4004034, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004035, "imagePath": "ui_shop_item_icon_costume_chr003_013", "limitCount": 1, "priority": 9981, "purchaseSteps": [{"rewardSetId": 4004035, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004036, "imagePath": "ui_shop_item_icon_costume_chr003_014", "limitCount": 1, "priority": 9980, "purchaseSteps": [{"rewardSetId": 4004036, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004037, "imagePath": "ui_shop_item_icon_costume_chr003_015", "limitCount": 1, "priority": 9979, "purchaseSteps": [{"rewardSetId": 4004037, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004038, "imagePath": "ui_shop_item_icon_costume_chr003_016", "limitCount": 1, "priority": 9978, "purchaseSteps": [{"rewardSetId": 4004038, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004039, "imagePath": "ui_shop_item_icon_costume_chr003_017", "limitCount": 1, "priority": 9977, "purchaseSteps": [{"rewardSetId": 4004039, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004040, "imagePath": "ui_shop_item_icon_costume_chr003_019", "limitCount": 1, "priority": 9976, "purchaseSteps": [{"rewardSetId": 4004040, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004041, "imagePath": "ui_shop_item_icon_costume_chr004_012", "limitCount": 1, "priority": 9975, "purchaseSteps": [{"rewardSetId": 4004041, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004042, "imagePath": "ui_shop_item_icon_costume_chr004_013", "limitCount": 1, "priority": 9974, "purchaseSteps": [{"rewardSetId": 4004042, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004043, "imagePath": "ui_shop_item_icon_costume_chr004_014", "limitCount": 1, "priority": 9973, "purchaseSteps": [{"rewardSetId": 4004043, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004044, "imagePath": "ui_shop_item_icon_costume_chr004_015", "limitCount": 1, "priority": 9972, "purchaseSteps": [{"rewardSetId": 4004044, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004045, "imagePath": "ui_shop_item_icon_costume_chr004_016", "limitCount": 1, "priority": 9971, "purchaseSteps": [{"rewardSetId": 4004045, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004046, "imagePath": "ui_shop_item_icon_costume_chr004_017", "limitCount": 1, "priority": 9970, "purchaseSteps": [{"rewardSetId": 4004046, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004047, "imagePath": "ui_shop_item_icon_costume_chr004_018", "limitCount": 1, "priority": 9969, "purchaseSteps": [{"rewardSetId": 4004047, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004048, "imagePath": "ui_shop_item_icon_costume_chr004_019", "limitCount": 1, "priority": 9968, "purchaseSteps": [{"rewardSetId": 4004048, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004049, "imagePath": "ui_shop_item_icon_costume_chr005_011", "limitCount": 1, "priority": 9967, "purchaseSteps": [{"rewardSetId": 4004049, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004050, "imagePath": "ui_shop_item_icon_costume_chr005_012", "limitCount": 1, "priority": 9966, "purchaseSteps": [{"rewardSetId": 4004050, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004051, "imagePath": "ui_shop_item_icon_costume_chr005_013", "limitCount": 1, "priority": 9965, "purchaseSteps": [{"rewardSetId": 4004051, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004052, "imagePath": "ui_shop_item_icon_costume_chr005_014", "limitCount": 1, "priority": 9964, "purchaseSteps": [{"rewardSetId": 4004052, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004053, "imagePath": "ui_shop_item_icon_costume_chr005_015", "limitCount": 1, "priority": 9963, "purchaseSteps": [{"rewardSetId": 4004053, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004054, "imagePath": "ui_shop_item_icon_costume_chr005_016", "limitCount": 1, "priority": 9962, "purchaseSteps": [{"rewardSetId": 4004054, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004055, "imagePath": "ui_shop_item_icon_costume_chr005_017", "limitCount": 1, "priority": 9961, "purchaseSteps": [{"rewardSetId": 4004055, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004056, "imagePath": "ui_shop_item_icon_costume_chr005_018", "limitCount": 1, "priority": 9960, "purchaseSteps": [{"rewardSetId": 4004056, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004057, "imagePath": "ui_shop_item_icon_costume_chr006_012", "limitCount": 1, "priority": 9959, "purchaseSteps": [{"rewardSetId": 4004057, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004058, "imagePath": "ui_shop_item_icon_costume_chr006_013", "limitCount": 1, "priority": 9958, "purchaseSteps": [{"rewardSetId": 4004058, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004059, "imagePath": "ui_shop_item_icon_costume_chr006_014", "limitCount": 1, "priority": 9957, "purchaseSteps": [{"rewardSetId": 4004059, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004060, "imagePath": "ui_shop_item_icon_costume_chr006_015", "limitCount": 1, "priority": 9956, "purchaseSteps": [{"rewardSetId": 4004060, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004061, "imagePath": "ui_shop_item_icon_costume_chr006_016", "limitCount": 1, "priority": 9955, "purchaseSteps": [{"rewardSetId": 4004061, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004062, "imagePath": "ui_shop_item_icon_costume_chr006_017", "limitCount": 1, "priority": 9954, "purchaseSteps": [{"rewardSetId": 4004062, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004063, "imagePath": "ui_shop_item_icon_costume_chr006_018", "limitCount": 1, "priority": 9953, "purchaseSteps": [{"rewardSetId": 4004063, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004064, "imagePath": "ui_shop_item_icon_costume_chr006_019", "limitCount": 1, "priority": 9952, "purchaseSteps": [{"rewardSetId": 4004064, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004065, "imagePath": "ui_shop_item_icon_costume_chr007_011", "limitCount": 1, "priority": 9951, "purchaseSteps": [{"rewardSetId": 4004065, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004066, "imagePath": "ui_shop_item_icon_costume_chr007_012", "limitCount": 1, "priority": 9950, "purchaseSteps": [{"rewardSetId": 4004066, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004067, "imagePath": "ui_shop_item_icon_costume_chr007_013", "limitCount": 1, "priority": 9949, "purchaseSteps": [{"rewardSetId": 4004067, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004068, "imagePath": "ui_shop_item_icon_costume_chr007_014", "limitCount": 1, "priority": 9948, "purchaseSteps": [{"rewardSetId": 4004068, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004069, "imagePath": "ui_shop_item_icon_costume_chr007_015", "limitCount": 1, "priority": 9947, "purchaseSteps": [{"rewardSetId": 4004069, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004070, "imagePath": "ui_shop_item_icon_costume_chr007_016", "limitCount": 1, "priority": 9946, "purchaseSteps": [{"rewardSetId": 4004070, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004071, "imagePath": "ui_shop_item_icon_costume_chr007_017", "limitCount": 1, "priority": 9945, "purchaseSteps": [{"rewardSetId": 4004071, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004072, "imagePath": "ui_shop_item_icon_costume_chr007_018", "limitCount": 1, "priority": 9944, "purchaseSteps": [{"rewardSetId": 4004072, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004073, "imagePath": "ui_shop_item_icon_costume_chr008_011", "limitCount": 1, "priority": 9943, "purchaseSteps": [{"rewardSetId": 4004073, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004074, "imagePath": "ui_shop_item_icon_costume_chr008_012", "limitCount": 1, "priority": 9942, "purchaseSteps": [{"rewardSetId": 4004074, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004075, "imagePath": "ui_shop_item_icon_costume_chr008_013", "limitCount": 1, "priority": 9941, "purchaseSteps": [{"rewardSetId": 4004075, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004076, "imagePath": "ui_shop_item_icon_costume_chr008_014", "limitCount": 1, "priority": 9940, "purchaseSteps": [{"rewardSetId": 4004076, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004077, "imagePath": "ui_shop_item_icon_costume_chr008_015", "limitCount": 1, "priority": 9939, "purchaseSteps": [{"rewardSetId": 4004077, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004078, "imagePath": "ui_shop_item_icon_costume_chr008_016", "limitCount": 1, "priority": 9938, "purchaseSteps": [{"rewardSetId": 4004078, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004079, "imagePath": "ui_shop_item_icon_costume_chr008_017", "limitCount": 1, "priority": 9937, "purchaseSteps": [{"rewardSetId": 4004079, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004080, "imagePath": "ui_shop_item_icon_costume_chr008_018", "limitCount": 1, "priority": 9936, "purchaseSteps": [{"rewardSetId": 4004080, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004081, "imagePath": "ui_shop_item_icon_costume_chr009_011", "limitCount": 1, "priority": 9935, "purchaseSteps": [{"rewardSetId": 4004081, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004082, "imagePath": "ui_shop_item_icon_costume_chr009_013", "limitCount": 1, "priority": 9934, "purchaseSteps": [{"rewardSetId": 4004082, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004083, "imagePath": "ui_shop_item_icon_costume_chr009_014", "limitCount": 1, "priority": 9933, "purchaseSteps": [{"rewardSetId": 4004083, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004084, "imagePath": "ui_shop_item_icon_costume_chr009_015", "limitCount": 1, "priority": 9932, "purchaseSteps": [{"rewardSetId": 4004084, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004085, "imagePath": "ui_shop_item_icon_costume_chr009_016", "limitCount": 1, "priority": 9931, "purchaseSteps": [{"rewardSetId": 4004085, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004086, "imagePath": "ui_shop_item_icon_costume_chr009_017", "limitCount": 1, "priority": 9930, "purchaseSteps": [{"rewardSetId": 4004086, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004087, "imagePath": "ui_shop_item_icon_costume_chr009_018", "limitCount": 1, "priority": 9929, "purchaseSteps": [{"rewardSetId": 4004087, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004088, "imagePath": "ui_shop_item_icon_costume_chr009_019", "limitCount": 1, "priority": 9928, "purchaseSteps": [{"rewardSetId": 4004088, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004089, "imagePath": "ui_shop_item_icon_costume_chr010_011", "limitCount": 1, "priority": 9927, "purchaseSteps": [{"rewardSetId": 4004089, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004090, "imagePath": "ui_shop_item_icon_costume_chr010_012", "limitCount": 1, "priority": 9926, "purchaseSteps": [{"rewardSetId": 4004090, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004091, "imagePath": "ui_shop_item_icon_costume_chr010_013", "limitCount": 1, "priority": 9925, "purchaseSteps": [{"rewardSetId": 4004091, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004092, "imagePath": "ui_shop_item_icon_costume_chr010_014", "limitCount": 1, "priority": 9924, "purchaseSteps": [{"rewardSetId": 4004092, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004093, "imagePath": "ui_shop_item_icon_costume_chr010_015", "limitCount": 1, "priority": 9923, "purchaseSteps": [{"rewardSetId": 4004093, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004094, "imagePath": "ui_shop_item_icon_costume_chr010_016", "limitCount": 1, "priority": 9922, "purchaseSteps": [{"rewardSetId": 4004094, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004095, "imagePath": "ui_shop_item_icon_costume_chr010_017", "limitCount": 1, "priority": 9921, "purchaseSteps": [{"rewardSetId": 4004095, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004096, "imagePath": "ui_shop_item_icon_costume_chr010_018", "limitCount": 1, "priority": 9920, "purchaseSteps": [{"rewardSetId": 4004096, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004097, "imagePath": "ui_shop_item_icon_costume_chr011_012", "limitCount": 1, "priority": 9919, "purchaseSteps": [{"rewardSetId": 4004097, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004098, "imagePath": "ui_shop_item_icon_costume_chr011_013", "limitCount": 1, "priority": 9918, "purchaseSteps": [{"rewardSetId": 4004098, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004099, "imagePath": "ui_shop_item_icon_costume_chr011_014", "limitCount": 1, "priority": 9917, "purchaseSteps": [{"rewardSetId": 4004099, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004100, "imagePath": "ui_shop_item_icon_costume_chr011_015", "limitCount": 1, "priority": 9916, "purchaseSteps": [{"rewardSetId": 4004100, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004101, "imagePath": "ui_shop_item_icon_costume_chr011_016", "limitCount": 1, "priority": 9915, "purchaseSteps": [{"rewardSetId": 4004101, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004102, "imagePath": "ui_shop_item_icon_costume_chr011_017", "limitCount": 1, "priority": 9914, "purchaseSteps": [{"rewardSetId": 4004102, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004103, "imagePath": "ui_shop_item_icon_costume_chr011_018", "limitCount": 1, "priority": 9913, "purchaseSteps": [{"rewardSetId": 4004103, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004104, "imagePath": "ui_shop_item_icon_costume_chr011_019", "limitCount": 1, "priority": 9912, "purchaseSteps": [{"rewardSetId": 4004104, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004105, "imagePath": "ui_shop_item_icon_costume_chr012_011", "limitCount": 1, "priority": 9911, "purchaseSteps": [{"rewardSetId": 4004105, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004106, "imagePath": "ui_shop_item_icon_costume_chr012_012", "limitCount": 1, "priority": 9910, "purchaseSteps": [{"rewardSetId": 4004106, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004107, "imagePath": "ui_shop_item_icon_costume_chr012_013", "limitCount": 1, "priority": 9909, "purchaseSteps": [{"rewardSetId": 4004107, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004108, "imagePath": "ui_shop_item_icon_costume_chr012_014", "limitCount": 1, "priority": 9908, "purchaseSteps": [{"rewardSetId": 4004108, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004109, "imagePath": "ui_shop_item_icon_costume_chr012_015", "limitCount": 1, "priority": 9907, "purchaseSteps": [{"rewardSetId": 4004109, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004110, "imagePath": "ui_shop_item_icon_costume_chr012_016", "limitCount": 1, "priority": 9906, "purchaseSteps": [{"rewardSetId": 4004110, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004111, "imagePath": "ui_shop_item_icon_costume_chr012_017", "limitCount": 1, "priority": 9905, "purchaseSteps": [{"rewardSetId": 4004111, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004112, "imagePath": "ui_shop_item_icon_costume_chr012_018", "limitCount": 1, "priority": 9904, "purchaseSteps": [{"rewardSetId": 4004112, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004113, "imagePath": "ui_shop_item_icon_costume_chr013_011", "limitCount": 1, "priority": 9903, "purchaseSteps": [{"rewardSetId": 4004113, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004114, "imagePath": "ui_shop_item_icon_costume_chr013_012", "limitCount": 1, "priority": 9902, "purchaseSteps": [{"rewardSetId": 4004114, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004115, "imagePath": "ui_shop_item_icon_costume_chr013_013", "limitCount": 1, "priority": 9901, "purchaseSteps": [{"rewardSetId": 4004115, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004116, "imagePath": "ui_shop_item_icon_costume_chr013_014", "limitCount": 1, "priority": 9900, "purchaseSteps": [{"rewardSetId": 4004116, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004117, "imagePath": "ui_shop_item_icon_costume_chr013_015", "limitCount": 1, "priority": 9899, "purchaseSteps": [{"rewardSetId": 4004117, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004118, "imagePath": "ui_shop_item_icon_costume_chr013_016", "limitCount": 1, "priority": 9898, "purchaseSteps": [{"rewardSetId": 4004118, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004119, "imagePath": "ui_shop_item_icon_costume_chr013_017", "limitCount": 1, "priority": 9897, "purchaseSteps": [{"rewardSetId": 4004119, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004120, "imagePath": "ui_shop_item_icon_costume_chr013_018", "limitCount": 1, "priority": 9896, "purchaseSteps": [{"rewardSetId": 4004120, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004121, "imagePath": "ui_shop_item_icon_costume_chr014_011", "limitCount": 1, "priority": 9895, "purchaseSteps": [{"rewardSetId": 4004121, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004122, "imagePath": "ui_shop_item_icon_costume_chr014_012", "limitCount": 1, "priority": 9894, "purchaseSteps": [{"rewardSetId": 4004122, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004123, "imagePath": "ui_shop_item_icon_costume_chr014_013", "limitCount": 1, "priority": 9893, "purchaseSteps": [{"rewardSetId": 4004123, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004124, "imagePath": "ui_shop_item_icon_costume_chr014_014", "limitCount": 1, "priority": 9892, "purchaseSteps": [{"rewardSetId": 4004124, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004125, "imagePath": "ui_shop_item_icon_costume_chr014_015", "limitCount": 1, "priority": 9891, "purchaseSteps": [{"rewardSetId": 4004125, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004126, "imagePath": "ui_shop_item_icon_costume_chr014_016", "limitCount": 1, "priority": 9890, "purchaseSteps": [{"rewardSetId": 4004126, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004127, "imagePath": "ui_shop_item_icon_costume_chr014_017", "limitCount": 1, "priority": 9889, "purchaseSteps": [{"rewardSetId": 4004127, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004128, "imagePath": "ui_shop_item_icon_costume_chr014_018", "limitCount": 1, "priority": 9888, "purchaseSteps": [{"rewardSetId": 4004128, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004129, "imagePath": "ui_shop_item_icon_costume_chr015_011", "limitCount": 1, "priority": 9887, "purchaseSteps": [{"rewardSetId": 4004129, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004130, "imagePath": "ui_shop_item_icon_costume_chr015_012", "limitCount": 1, "priority": 9886, "purchaseSteps": [{"rewardSetId": 4004130, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004131, "imagePath": "ui_shop_item_icon_costume_chr015_013", "limitCount": 1, "priority": 9885, "purchaseSteps": [{"rewardSetId": 4004131, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004132, "imagePath": "ui_shop_item_icon_costume_chr015_014", "limitCount": 1, "priority": 9884, "purchaseSteps": [{"rewardSetId": 4004132, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004133, "imagePath": "ui_shop_item_icon_costume_chr015_015", "limitCount": 1, "priority": 9883, "purchaseSteps": [{"rewardSetId": 4004133, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004134, "imagePath": "ui_shop_item_icon_costume_chr015_016", "limitCount": 1, "priority": 9882, "purchaseSteps": [{"rewardSetId": 4004134, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004135, "imagePath": "ui_shop_item_icon_costume_chr015_017", "limitCount": 1, "priority": 9881, "purchaseSteps": [{"rewardSetId": 4004135, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004136, "imagePath": "ui_shop_item_icon_costume_chr015_018", "limitCount": 1, "priority": 9880, "purchaseSteps": [{"rewardSetId": 4004136, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004137, "imagePath": "ui_shop_item_icon_costume_chr013_112", "limitCount": 1, "priority": 49996, "purchaseSteps": [{"rewardSetId": 4004137, "costs": [{"type": 22, "id": 1, "quantity": 120}]}], "shopId": 4}')
,('{"id": 4004138, "imagePath": "ui_shop_item_icon_costume_chr013_113", "limitCount": 1, "priority": 49995, "purchaseSteps": [{"rewardSetId": 4004138, "costs": [{"type": 22, "id": 1, "quantity": 120}]}], "shopId": 4}')
,('{"id": 4004139, "imagePath": "ui_shop_item_icon_costume_chr013_114", "limitCount": 1, "priority": 49994, "purchaseSteps": [{"rewardSetId": 4004139, "costs": [{"type": 22, "id": 1, "quantity": 120}]}], "shopId": 4}')
,('{"id": 4004140, "imagePath": "ui_shop_item_icon_costume_chr030_112", "limitCount": 1, "priority": 19986, "purchaseSteps": [{"rewardSetId": 4004140, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004141, "imagePath": "ui_shop_item_icon_costume_chr030_113", "limitCount": 1, "priority": 19985, "purchaseSteps": [{"rewardSetId": 4004141, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004142, "imagePath": "ui_shop_item_icon_costume_chr030_114", "limitCount": 1, "priority": 19984, "purchaseSteps": [{"rewardSetId": 4004142, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004143, "imagePath": "ui_shop_item_icon_costume_chr013_201", "limitCount": 1, "priority": 19983, "purchaseSteps": [{"rewardSetId": 4004143, "costs": [{"type": 22, "id": 1, "quantity": 50}]}], "shopId": 4}')
,('{"id": 4004144, "imagePath": "ui_shop_item_icon_costume_chr030_011", "limitCount": 1, "priority": 9879, "purchaseSteps": [{"rewardSetId": 4004144, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004145, "imagePath": "ui_shop_item_icon_costume_chr030_012", "limitCount": 1, "priority": 9878, "purchaseSteps": [{"rewardSetId": 4004145, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004146, "imagePath": "ui_shop_item_icon_costume_chr030_013", "limitCount": 1, "priority": 9877, "purchaseSteps": [{"rewardSetId": 4004146, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004147, "imagePath": "ui_shop_item_icon_costume_chr030_014", "limitCount": 1, "priority": 9876, "purchaseSteps": [{"rewardSetId": 4004147, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004148, "imagePath": "ui_shop_item_icon_costume_chr030_015", "limitCount": 1, "priority": 9875, "purchaseSteps": [{"rewardSetId": 4004148, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004149, "imagePath": "ui_shop_item_icon_costume_chr030_016", "limitCount": 1, "priority": 9874, "purchaseSteps": [{"rewardSetId": 4004149, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004150, "imagePath": "ui_shop_item_icon_costume_chr030_017", "limitCount": 1, "priority": 9873, "purchaseSteps": [{"rewardSetId": 4004150, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4004151, "imagePath": "ui_shop_item_icon_costume_chr030_018", "limitCount": 1, "priority": 9872, "purchaseSteps": [{"rewardSetId": 4004151, "costs": [{"type": 22, "id": 1, "quantity": 15}]}], "shopId": 4}')
,('{"id": 4005001, "imagePath": "ui_shop_item_icon_pack_7133", "limitCount": 10, "resetCycle": 2, "priority": 9999, "purchaseSteps": [{"rewardSetId": 4005001, "costs": [{"type": 2, "id": 1, "quantity": 380}], "name": "PAR Set"}], "shopId": 5, "resetPeriod": 1}')
,('{"id": 4005002, "imagePath": "ui_shop_item_icon_pack_15", "limitCount": 10, "resetCycle": 2, "priority": 9998, "purchaseSteps": [{"rewardSetId": 4005002, "costs": [{"type": 2, "id": 1, "quantity": 380}], "name": "Booster Set"}], "shopId": 5, "resetPeriod": 1}')
,('{"id": 4005003, "imagePath": "ui_shop_item_icon_pack_80003", "limitCount": 20, "resetCycle": 2, "priority": 9997, "purchaseSteps": [{"rewardSetId": 4005003, "costs": [{"type": 2, "id": 1, "quantity": 50}], "name": "Kane Set"}], "shopId": 5, "resetPeriod": 1}')
,('{"id": 4005004, "imagePath": "ui_shop_item_icon_pack_2", "limitCount": 20, "resetCycle": 2, "priority": 9996, "purchaseSteps": [{"rewardSetId": 4005004, "costs": [{"type": 2, "id": 1, "quantity": 50}], "name": "T Point Set"}], "shopId": 5, "resetPeriod": 1}')
,('{"id": 4010001, "limitCount": 5, "resetCycle": 3, "priority": 10000, "purchaseSteps": [{"rewardSetId": 4010001, "costs": [{"type": 7, "id": 104, "quantity": 30}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010002, "limitCount": 5, "resetCycle": 3, "priority": 8999, "purchaseSteps": [{"rewardSetId": 4010002, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010003, "limitCount": 5, "resetCycle": 3, "priority": 8998, "purchaseSteps": [{"rewardSetId": 4010003, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010004, "limitCount": 5, "resetCycle": 3, "priority": 8997, "purchaseSteps": [{"rewardSetId": 4010004, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010005, "limitCount": 15, "resetCycle": 3, "priority": 7999, "purchaseSteps": [{"rewardSetId": 4010005, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010006, "limitCount": 15, "resetCycle": 3, "priority": 7998, "purchaseSteps": [{"rewardSetId": 4010006, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010007, "limitCount": 15, "resetCycle": 3, "priority": 7997, "purchaseSteps": [{"rewardSetId": 4010007, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010008, "limitCount": 45, "resetCycle": 3, "priority": 6999, "purchaseSteps": [{"rewardSetId": 4010008, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010009, "limitCount": 45, "resetCycle": 3, "priority": 6998, "purchaseSteps": [{"rewardSetId": 4010009, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010010, "limitCount": 45, "resetCycle": 3, "priority": 6997, "purchaseSteps": [{"rewardSetId": 4010010, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010011, "limitCount": 10, "resetCycle": 3, "priority": 1, "purchaseSteps": [{"rewardSetId": 4010011, "costs": [{"type": 7, "id": 104, "quantity": 1}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010012, "limitCount": 5, "resetCycle": 3, "priority": 8996, "purchaseSteps": [{"rewardSetId": 4010012, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010013, "limitCount": 5, "resetCycle": 3, "priority": 8995, "purchaseSteps": [{"rewardSetId": 4010013, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010014, "limitCount": 15, "resetCycle": 3, "priority": 7996, "purchaseSteps": [{"rewardSetId": 4010014, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010015, "limitCount": 15, "resetCycle": 3, "priority": 7995, "purchaseSteps": [{"rewardSetId": 4010015, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010016, "limitCount": 45, "resetCycle": 3, "priority": 6996, "purchaseSteps": [{"rewardSetId": 4010016, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4010017, "limitCount": 45, "resetCycle": 3, "priority": 6995, "purchaseSteps": [{"rewardSetId": 4010017, "costs": [{"type": 7, "id": 104, "quantity": 10}]}], "shopId": 10, "resetPeriod": 1}')
,('{"id": 4011001, "limitCount": 5, "resetCycle": 3, "priority": 10000, "purchaseSteps": [{"rewardSetId": 4011001, "costs": [{"type": 7, "id": 105, "quantity": 60}]}], "shopId": 11, "resetPeriod": 1}')
,('{"id": 4011002, "limitCount": 10, "resetCycle": 3, "priority": 9999, "purchaseSteps": [{"rewardSetId": 4011002, "costs": [{"type": 7, "id": 105, "quantity": 100}]}], "shopId": 11, "resetPeriod": 1}')
,('{"id": 4011003, "limitCount": 10, "resetCycle": 3, "priority": 8999, "purchaseSteps": [{"rewardSetId": 4011003, "costs": [{"type": 7, "id": 105, "quantity": 10}]}], "shopId": 11, "resetPeriod": 1}')
,('{"id": 4011004, "limitCount": 10, "resetCycle": 3, "priority": 8998, "purchaseSteps": [{"rewardSetId": 4011004, "costs": [{"type": 7, "id": 105, "quantity": 10}]}], "shopId": 11, "resetPeriod": 1}')
,('{"id": 4011005, "limitCount": 10, "resetCycle": 3, "priority": 8997, "purchaseSteps": [{"rewardSetId": 4011005, "costs": [{"type": 7, "id": 105, "quantity": 10}]}], "shopId": 11, "resetPeriod": 1}')
,('{"id": 4011006, "limitCount": 10, "resetCycle": 3, "priority": 8996, "purchaseSteps": [{"rewardSetId": 4011006, "costs": [{"type": 7, "id": 105, "quantity": 10}]}], "shopId": 11, "resetPeriod": 1}')
,('{"id": 4011007, "limitCount": 10, "resetCycle": 3, "priority": 8995, "purchaseSteps": [{"rewardSetId": 4011007, "costs": [{"type": 7, "id": 105, "quantity": 10}]}], "shopId": 11, "resetPeriod": 1}')
,('{"id": 4011008, "limitCount": 10, "resetCycle": 3, "priority": 1, "purchaseSteps": [{"rewardSetId": 4011008, "costs": [{"type": 7, "id": 105, "quantity": 5}]}], "shopId": 11, "resetPeriod": 1}')
,('{"id": 4011009, "limitCount": 10, "resetCycle": 3, "priority": 8994, "purchaseSteps": [{"rewardSetId": 4011009, "costs": [{"type": 7, "id": 105, "quantity": 10}]}], "shopId": 11, "resetPeriod": 1}')
,('{"id": 4012001, "limitCount": 5, "resetCycle": 3, "priority": 10000, "purchaseSteps": [{"rewardSetId": 4012001, "costs": [{"type": 7, "id": 106, "quantity": 50}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012002, "limitCount": 5, "resetCycle": 3, "priority": 9999, "purchaseSteps": [{"rewardSetId": 4012002, "costs": [{"type": 7, "id": 106, "quantity": 50}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012003, "limitCount": 30, "resetCycle": 3, "priority": 8999, "purchaseSteps": [{"rewardSetId": 4012003, "costs": [{"type": 7, "id": 106, "quantity": 20}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012004, "limitCount": 30, "resetCycle": 3, "priority": 8998, "purchaseSteps": [{"rewardSetId": 4012004, "costs": [{"type": 7, "id": 106, "quantity": 20}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012005, "limitCount": 30, "resetCycle": 3, "priority": 8997, "purchaseSteps": [{"rewardSetId": 4012005, "costs": [{"type": 7, "id": 106, "quantity": 20}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012006, "limitCount": 30, "resetCycle": 3, "priority": 8996, "purchaseSteps": [{"rewardSetId": 4012006, "costs": [{"type": 7, "id": 106, "quantity": 20}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012007, "limitCount": 30, "resetCycle": 3, "priority": 8995, "purchaseSteps": [{"rewardSetId": 4012007, "costs": [{"type": 7, "id": 106, "quantity": 20}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012008, "limitCount": 10, "resetCycle": 3, "priority": 7999, "purchaseSteps": [{"rewardSetId": 4012008, "costs": [{"type": 7, "id": 106, "quantity": 10}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012009, "limitCount": 90, "resetCycle": 3, "priority": 6999, "purchaseSteps": [{"rewardSetId": 4012009, "costs": [{"type": 7, "id": 106, "quantity": 5}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012010, "limitCount": 90, "resetCycle": 3, "priority": 6998, "purchaseSteps": [{"rewardSetId": 4012010, "costs": [{"type": 7, "id": 106, "quantity": 5}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012011, "limitCount": 90, "resetCycle": 3, "priority": 6997, "purchaseSteps": [{"rewardSetId": 4012011, "costs": [{"type": 7, "id": 106, "quantity": 5}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012012, "limitCount": 90, "resetCycle": 3, "priority": 6996, "purchaseSteps": [{"rewardSetId": 4012012, "costs": [{"type": 7, "id": 106, "quantity": 5}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012013, "limitCount": 90, "resetCycle": 3, "priority": 6995, "purchaseSteps": [{"rewardSetId": 4012013, "costs": [{"type": 7, "id": 106, "quantity": 5}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012014, "priority": 1, "purchaseSteps": [{"rewardSetId": 4012014, "costs": [{"type": 7, "id": 106, "quantity": 1}]}], "shopId": 12}')
,('{"id": 4012015, "limitCount": 30, "resetCycle": 3, "priority": 8994, "purchaseSteps": [{"rewardSetId": 4012015, "costs": [{"type": 7, "id": 106, "quantity": 20}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4012016, "limitCount": 90, "resetCycle": 3, "priority": 6994, "purchaseSteps": [{"rewardSetId": 4012016, "costs": [{"type": 7, "id": 106, "quantity": 5}]}], "shopId": 12, "resetPeriod": 1}')
,('{"id": 4100000, "priority": 10000, "purchaseSteps": [{"rewardSetId": 4100000, "costs": [{"type": 7, "id": 15, "quantity": 1}]}], "shopId": 100}')
,('{"id": 4100001, "limitCount": 20, "resetCycle": 3, "priority": 9000, "purchaseSteps": [{"rewardSetId": 4100001, "costs": [{"type": 7, "id": 14, "quantity": 20}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100002, "limitCount": 20, "resetCycle": 3, "priority": 9001, "purchaseSteps": [{"rewardSetId": 4100002, "costs": [{"type": 7, "id": 14, "quantity": 20}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100003, "limitCount": 30, "resetCycle": 3, "priority": 8000, "purchaseSteps": [{"rewardSetId": 4100003, "costs": [{"type": 7, "id": 14, "quantity": 15}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100004, "limitCount": 55, "resetCycle": 3, "priority": 7000, "purchaseSteps": [{"rewardSetId": 4100004, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100005, "limitCount": 55, "resetCycle": 3, "priority": 7001, "purchaseSteps": [{"rewardSetId": 4100005, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100006, "limitCount": 55, "resetCycle": 3, "priority": 7002, "purchaseSteps": [{"rewardSetId": 4100006, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100007, "limitCount": 55, "resetCycle": 3, "priority": 7003, "purchaseSteps": [{"rewardSetId": 4100007, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100008, "limitCount": 55, "resetCycle": 3, "priority": 7004, "purchaseSteps": [{"rewardSetId": 4100008, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100009, "limitCount": 60, "resetCycle": 3, "priority": 6000, "purchaseSteps": [{"rewardSetId": 4100009, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100010, "limitCount": 60, "resetCycle": 3, "priority": 6001, "purchaseSteps": [{"rewardSetId": 4100010, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100011, "limitCount": 60, "resetCycle": 3, "priority": 6002, "purchaseSteps": [{"rewardSetId": 4100011, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100012, "limitCount": 60, "resetCycle": 3, "priority": 6003, "purchaseSteps": [{"rewardSetId": 4100012, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100013, "limitCount": 60, "resetCycle": 3, "priority": 6004, "purchaseSteps": [{"rewardSetId": 4100013, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100014, "limitCount": 60, "resetCycle": 3, "priority": 6005, "purchaseSteps": [{"rewardSetId": 4100014, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100015, "limitCount": 60, "resetCycle": 3, "priority": 6006, "purchaseSteps": [{"rewardSetId": 4100015, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100016, "limitCount": 60, "resetCycle": 3, "priority": 6007, "purchaseSteps": [{"rewardSetId": 4100016, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100017, "limitCount": 20, "resetCycle": 3, "priority": 9002, "purchaseSteps": [{"rewardSetId": 4100017, "costs": [{"type": 7, "id": 14, "quantity": 20}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100018, "limitCount": 55, "resetCycle": 3, "priority": 7005, "purchaseSteps": [{"rewardSetId": 4100018, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100019, "limitCount": 60, "resetCycle": 3, "priority": 6008, "purchaseSteps": [{"rewardSetId": 4100019, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100020, "limitCount": 60, "resetCycle": 3, "priority": 6009, "purchaseSteps": [{"rewardSetId": 4100020, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4100021, "limitCount": 60, "resetCycle": 3, "priority": 6010, "purchaseSteps": [{"rewardSetId": 4100021, "costs": [{"type": 7, "id": 14, "quantity": 5}]}], "shopId": 100, "resetPeriod": 1}')
,('{"id": 4101001, "limitCount": 5, "resetCycle": 3, "priority": 10000, "purchaseSteps": [{"rewardSetId": 4101001, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101002, "limitCount": 5, "resetCycle": 3, "priority": 9999, "purchaseSteps": [{"rewardSetId": 4101002, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101003, "limitCount": 5, "resetCycle": 3, "priority": 9998, "purchaseSteps": [{"rewardSetId": 4101003, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101004, "limitCount": 5, "resetCycle": 3, "priority": 9997, "purchaseSteps": [{"rewardSetId": 4101004, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101005, "limitCount": 5, "resetCycle": 3, "priority": 9996, "purchaseSteps": [{"rewardSetId": 4101005, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101007, "limitCount": 5, "resetCycle": 3, "priority": 9995, "purchaseSteps": [{"rewardSetId": 4101007, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101008, "limitCount": 5, "resetCycle": 3, "priority": 9994, "purchaseSteps": [{"rewardSetId": 4101008, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101009, "limitCount": 5, "resetCycle": 3, "priority": 9993, "purchaseSteps": [{"rewardSetId": 4101009, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101010, "limitCount": 5, "resetCycle": 3, "priority": 9992, "purchaseSteps": [{"rewardSetId": 4101010, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101011, "limitCount": 5, "resetCycle": 3, "priority": 9991, "purchaseSteps": [{"rewardSetId": 4101011, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101013, "limitCount": 5, "resetCycle": 3, "priority": 9990, "purchaseSteps": [{"rewardSetId": 4101013, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101014, "limitCount": 5, "resetCycle": 3, "priority": 9989, "purchaseSteps": [{"rewardSetId": 4101014, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101015, "limitCount": 5, "resetCycle": 3, "priority": 9988, "purchaseSteps": [{"rewardSetId": 4101015, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101016, "limitCount": 5, "resetCycle": 3, "priority": 9987, "purchaseSteps": [{"rewardSetId": 4101016, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101017, "limitCount": 5, "resetCycle": 3, "priority": 9986, "purchaseSteps": [{"rewardSetId": 4101017, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101018, "limitCount": 5, "resetCycle": 3, "priority": 9985, "purchaseSteps": [{"rewardSetId": 4101018, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101019, "limitCount": 5, "resetCycle": 3, "priority": 9984, "purchaseSteps": [{"rewardSetId": 4101019, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101020, "limitCount": 5, "resetCycle": 3, "priority": 9983, "purchaseSteps": [{"rewardSetId": 4101020, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101021, "limitCount": 5, "resetCycle": 3, "priority": 9982, "purchaseSteps": [{"rewardSetId": 4101021, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101022, "limitCount": 5, "resetCycle": 3, "priority": 9981, "purchaseSteps": [{"rewardSetId": 4101022, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101023, "limitCount": 5, "resetCycle": 3, "priority": 9980, "purchaseSteps": [{"rewardSetId": 4101023, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101024, "limitCount": 5, "resetCycle": 3, "priority": 9979, "purchaseSteps": [{"rewardSetId": 4101024, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101025, "limitCount": 5, "resetCycle": 3, "priority": 9977, "purchaseSteps": [{"rewardSetId": 4101025, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101026, "limitCount": 5, "resetCycle": 3, "priority": 9976, "purchaseSteps": [{"rewardSetId": 4101026, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4101027, "limitCount": 5, "resetCycle": 3, "priority": 9978, "purchaseSteps": [{"rewardSetId": 4101027, "costs": [{"type": 7, "id": 104, "quantity": 500}]}], "shopId": 101, "resetPeriod": 1}')
,('{"id": 4102001, "keyTasks": [{"conditionId": 1031, "count": "1", "name": "Confirmation (Ch. 2 cleared)"}], "limitCount": 5, "resetCycle": 3, "priority": 9001, "purchaseSteps": [{"rewardSetId": 4102001, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102002, "keyTasks": [{"conditionId": 1030, "count": "1", "name": "Confirmation (Ch. 1 cleared)"}], "limitCount": 5, "resetCycle": 3, "priority": 9000, "purchaseSteps": [{"rewardSetId": 4102002, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102003, "keyTasks": [{"conditionId": 1032, "count": "1", "name": "Confirmation (defeated Endrone)"}], "limitCount": 5, "resetCycle": 3, "priority": 8002, "purchaseSteps": [{"rewardSetId": 4102003, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102004, "keyTasks": [{"conditionId": 1033, "count": "1", "name": "Confirmation (defeated Destroyer)"}], "limitCount": 5, "resetCycle": 3, "priority": 8001, "purchaseSteps": [{"rewardSetId": 4102004, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102005, "keyTasks": [{"conditionId": 1034, "count": "1", "name": "Confirmation (defeated Death Penalty)"}], "limitCount": 5, "resetCycle": 3, "priority": 8000, "purchaseSteps": [{"rewardSetId": 4102005, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102006, "limitCount": 5, "resetCycle": 3, "priority": 6999, "purchaseSteps": [{"rewardSetId": 4102006, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102007, "limitCount": 5, "resetCycle": 3, "priority": 6998, "purchaseSteps": [{"rewardSetId": 4102007, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102008, "limitCount": 5, "resetCycle": 3, "priority": 6997, "purchaseSteps": [{"rewardSetId": 4102008, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102009, "limitCount": 5, "resetCycle": 3, "priority": 6996, "purchaseSteps": [{"rewardSetId": 4102009, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102010, "limitCount": 5, "resetCycle": 3, "priority": 6995, "purchaseSteps": [{"rewardSetId": 4102010, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102011, "limitCount": 5, "resetCycle": 3, "priority": 6994, "purchaseSteps": [{"rewardSetId": 4102011, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102012, "limitCount": 5, "resetCycle": 3, "priority": 6993, "purchaseSteps": [{"rewardSetId": 4102012, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102013, "limitCount": 5, "resetCycle": 3, "priority": 6992, "purchaseSteps": [{"rewardSetId": 4102013, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102014, "limitCount": 5, "resetCycle": 3, "priority": 6991, "purchaseSteps": [{"rewardSetId": 4102014, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102015, "limitCount": 5, "resetCycle": 3, "priority": 6990, "purchaseSteps": [{"rewardSetId": 4102015, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102016, "limitCount": 5, "resetCycle": 3, "priority": 6989, "purchaseSteps": [{"rewardSetId": 4102016, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102017, "limitCount": 5, "resetCycle": 3, "priority": 6988, "purchaseSteps": [{"rewardSetId": 4102017, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102018, "limitCount": 5, "resetCycle": 3, "priority": 6987, "purchaseSteps": [{"rewardSetId": 4102018, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102019, "limitCount": 5, "resetCycle": 3, "priority": 6986, "purchaseSteps": [{"rewardSetId": 4102019, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102020, "limitCount": 5, "resetCycle": 3, "priority": 6985, "purchaseSteps": [{"rewardSetId": 4102020, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102022, "keyTasks": [{"conditionId": 1037, "count": "1", "name": "Confirmation (Ch. 3 cleared)"}], "limitCount": 5, "resetCycle": 3, "priority": 9003, "purchaseSteps": [{"rewardSetId": 4102022, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102023, "keyTasks": [{"conditionId": 1039, "count": "1", "name": "Confirmation (defeated Deadly Red Alert)"}], "limitCount": 5, "resetCycle": 3, "priority": 8003, "purchaseSteps": [{"rewardSetId": 4102023, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102024, "keyTasks": [{"conditionId": 1038, "count": "1", "name": "Confirmation (defeated Tentacles)"}], "limitCount": 5, "resetCycle": 3, "priority": 8004, "purchaseSteps": [{"rewardSetId": 4102024, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102025, "limitCount": 5, "resetCycle": 3, "priority": 6984, "purchaseSteps": [{"rewardSetId": 4102025, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102026, "limitCount": 5, "resetCycle": 3, "priority": 6983, "purchaseSteps": [{"rewardSetId": 4102026, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4102027, "limitCount": 5, "resetCycle": 3, "priority": 6982, "purchaseSteps": [{"rewardSetId": 4102027, "costs": [{"type": 7, "id": 105, "quantity": 400}]}], "shopId": 102, "resetPeriod": 1}')
,('{"id": 4103001, "limitCount": 5, "resetCycle": 3, "priority": 8999, "purchaseSteps": [{"rewardSetId": 4103001, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103002, "limitCount": 5, "resetCycle": 3, "priority": 8998, "purchaseSteps": [{"rewardSetId": 4103002, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103003, "limitCount": 5, "resetCycle": 3, "priority": 8997, "purchaseSteps": [{"rewardSetId": 4103003, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103004, "limitCount": 5, "resetCycle": 3, "priority": 8996, "purchaseSteps": [{"rewardSetId": 4103004, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103005, "limitCount": 5, "resetCycle": 3, "priority": 8995, "purchaseSteps": [{"rewardSetId": 4103005, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103006, "limitCount": 5, "resetCycle": 3, "priority": 8994, "purchaseSteps": [{"rewardSetId": 4103006, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103007, "limitCount": 5, "resetCycle": 3, "priority": 8993, "purchaseSteps": [{"rewardSetId": 4103007, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103008, "limitCount": 5, "resetCycle": 3, "priority": 8992, "purchaseSteps": [{"rewardSetId": 4103008, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103009, "limitCount": 5, "resetCycle": 3, "priority": 8991, "purchaseSteps": [{"rewardSetId": 4103009, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103010, "limitCount": 5, "resetCycle": 3, "priority": 8990, "purchaseSteps": [{"rewardSetId": 4103010, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103011, "limitCount": 5, "resetCycle": 3, "priority": 8989, "purchaseSteps": [{"rewardSetId": 4103011, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103012, "limitCount": 5, "resetCycle": 3, "priority": 8988, "purchaseSteps": [{"rewardSetId": 4103012, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103013, "limitCount": 5, "resetCycle": 3, "priority": 8987, "purchaseSteps": [{"rewardSetId": 4103013, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103014, "limitCount": 5, "resetCycle": 3, "priority": 8986, "purchaseSteps": [{"rewardSetId": 4103014, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103015, "limitCount": 5, "resetCycle": 3, "priority": 8985, "purchaseSteps": [{"rewardSetId": 4103015, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103016, "limitCount": 5, "resetCycle": 3, "priority": 8984, "purchaseSteps": [{"rewardSetId": 4103016, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103017, "limitCount": 5, "resetCycle": 3, "priority": 8983, "purchaseSteps": [{"rewardSetId": 4103017, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103018, "limitCount": 5, "resetCycle": 3, "priority": 8982, "purchaseSteps": [{"rewardSetId": 4103018, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103019, "limitCount": 5, "resetCycle": 3, "priority": 8981, "purchaseSteps": [{"rewardSetId": 4103019, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103020, "limitCount": 5, "resetCycle": 3, "priority": 8980, "purchaseSteps": [{"rewardSetId": 4103020, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103021, "limitCount": 5, "resetCycle": 3, "priority": 8979, "purchaseSteps": [{"rewardSetId": 4103021, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103022, "limitCount": 5, "resetCycle": 3, "priority": 8978, "purchaseSteps": [{"rewardSetId": 4103022, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103023, "limitCount": 5, "resetCycle": 3, "priority": 8977, "purchaseSteps": [{"rewardSetId": 4103023, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103024, "limitCount": 5, "resetCycle": 3, "priority": 8976, "purchaseSteps": [{"rewardSetId": 4103024, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103025, "limitCount": 5, "resetCycle": 3, "priority": 8975, "purchaseSteps": [{"rewardSetId": 4103025, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103026, "limitCount": 5, "resetCycle": 3, "priority": 8974, "purchaseSteps": [{"rewardSetId": 4103026, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103027, "limitCount": 5, "resetCycle": 3, "priority": 8973, "purchaseSteps": [{"rewardSetId": 4103027, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103028, "limitCount": 5, "resetCycle": 3, "priority": 8972, "purchaseSteps": [{"rewardSetId": 4103028, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103029, "limitCount": 5, "resetCycle": 3, "priority": 8971, "purchaseSteps": [{"rewardSetId": 4103029, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103030, "limitCount": 5, "resetCycle": 3, "priority": 8970, "purchaseSteps": [{"rewardSetId": 4103030, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103031, "limitCount": 5, "resetCycle": 3, "priority": 8969, "purchaseSteps": [{"rewardSetId": 4103031, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103032, "limitCount": 5, "resetCycle": 3, "priority": 8968, "purchaseSteps": [{"rewardSetId": 4103032, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103033, "limitCount": 5, "resetCycle": 3, "priority": 8967, "purchaseSteps": [{"rewardSetId": 4103033, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103034, "limitCount": 5, "resetCycle": 3, "priority": 8966, "purchaseSteps": [{"rewardSetId": 4103034, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103035, "limitCount": 5, "resetCycle": 3, "priority": 8965, "purchaseSteps": [{"rewardSetId": 4103035, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103036, "limitCount": 5, "resetCycle": 3, "priority": 8964, "purchaseSteps": [{"rewardSetId": 4103036, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103037, "limitCount": 5, "resetCycle": 3, "priority": 8963, "purchaseSteps": [{"rewardSetId": 4103037, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103038, "limitCount": 5, "resetCycle": 3, "priority": 8962, "purchaseSteps": [{"rewardSetId": 4103038, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103039, "limitCount": 5, "resetCycle": 3, "priority": 8961, "purchaseSteps": [{"rewardSetId": 4103039, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103040, "limitCount": 5, "resetCycle": 3, "priority": 8960, "purchaseSteps": [{"rewardSetId": 4103040, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103041, "limitCount": 5, "resetCycle": 3, "priority": 8959, "purchaseSteps": [{"rewardSetId": 4103041, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103042, "limitCount": 5, "resetCycle": 3, "priority": 8958, "purchaseSteps": [{"rewardSetId": 4103042, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103043, "limitCount": 5, "resetCycle": 3, "priority": 8957, "purchaseSteps": [{"rewardSetId": 4103043, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103044, "limitCount": 5, "resetCycle": 3, "priority": 8956, "purchaseSteps": [{"rewardSetId": 4103044, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103045, "limitCount": 5, "resetCycle": 3, "priority": 8955, "purchaseSteps": [{"rewardSetId": 4103045, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103046, "limitCount": 5, "resetCycle": 3, "priority": 8954, "purchaseSteps": [{"rewardSetId": 4103046, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103047, "limitCount": 5, "resetCycle": 3, "priority": 8953, "purchaseSteps": [{"rewardSetId": 4103047, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103048, "limitCount": 5, "resetCycle": 3, "priority": 8952, "purchaseSteps": [{"rewardSetId": 4103048, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103049, "limitCount": 5, "resetCycle": 3, "priority": 8951, "purchaseSteps": [{"rewardSetId": 4103049, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103051, "limitCount": 5, "resetCycle": 3, "priority": 8950, "purchaseSteps": [{"rewardSetId": 4103051, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103052, "limitCount": 5, "resetCycle": 3, "priority": 8949, "purchaseSteps": [{"rewardSetId": 4103052, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103053, "limitCount": 5, "resetCycle": 3, "priority": 8948, "purchaseSteps": [{"rewardSetId": 4103053, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103054, "limitCount": 5, "resetCycle": 3, "priority": 8947, "purchaseSteps": [{"rewardSetId": 4103054, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103055, "limitCount": 5, "resetCycle": 3, "priority": 8946, "purchaseSteps": [{"rewardSetId": 4103055, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103056, "limitCount": 5, "resetCycle": 3, "priority": 8945, "purchaseSteps": [{"rewardSetId": 4103056, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103057, "limitCount": 5, "resetCycle": 3, "priority": 8944, "purchaseSteps": [{"rewardSetId": 4103057, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103058, "limitCount": 5, "resetCycle": 3, "priority": 8943, "purchaseSteps": [{"rewardSetId": 4103058, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103059, "limitCount": 5, "resetCycle": 3, "priority": 8942, "purchaseSteps": [{"rewardSetId": 4103059, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103060, "limitCount": 5, "resetCycle": 3, "priority": 8941, "purchaseSteps": [{"rewardSetId": 4103060, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103061, "limitCount": 5, "resetCycle": 3, "priority": 8940, "purchaseSteps": [{"rewardSetId": 4103061, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103062, "limitCount": 5, "resetCycle": 3, "priority": 8939, "purchaseSteps": [{"rewardSetId": 4103062, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103063, "limitCount": 5, "resetCycle": 3, "priority": 8938, "purchaseSteps": [{"rewardSetId": 4103063, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103064, "limitCount": 5, "resetCycle": 3, "priority": 8937, "purchaseSteps": [{"rewardSetId": 4103064, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103065, "limitCount": 5, "resetCycle": 3, "priority": 8936, "purchaseSteps": [{"rewardSetId": 4103065, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103066, "limitCount": 5, "resetCycle": 3, "priority": 8935, "purchaseSteps": [{"rewardSetId": 4103066, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103067, "limitCount": 5, "resetCycle": 3, "priority": 8934, "purchaseSteps": [{"rewardSetId": 4103067, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103068, "limitCount": 5, "resetCycle": 3, "priority": 8933, "purchaseSteps": [{"rewardSetId": 4103068, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103069, "limitCount": 5, "resetCycle": 3, "priority": 8932, "purchaseSteps": [{"rewardSetId": 4103069, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103070, "limitCount": 5, "resetCycle": 3, "priority": 8931, "purchaseSteps": [{"rewardSetId": 4103070, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103071, "limitCount": 5, "resetCycle": 3, "priority": 8930, "purchaseSteps": [{"rewardSetId": 4103071, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
,('{"id": 4103072, "limitCount": 5, "resetCycle": 3, "priority": 8929, "purchaseSteps": [{"rewardSetId": 4103072, "costs": [{"type": 7, "id": 106, "quantity": 600}]}], "shopId": 103, "resetPeriod": 1}')
;

INSERT INTO tutorialStates (tutorialStatusKey, enabled)
VALUES
(1, 'true')
,(2, 'true')
,(4, 'true')
,(5, 'true')
,(6, 'true')
,(7, 'true')
,(8, 'true')
,(20, 'true')
,(22, 'true')
,(28, 'true')
,(35, 'true')
,(36, 'true')
,(40, '')
;

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

INSERT INTO characterCostumes (characterCostumeId, receivedAt) VALUES
(1001001, '2025-04-24T03:49:59Z')
, (1001011, '2025-04-24T03:49:59Z')
, (1001012, '2025-04-24T03:49:59Z')
, (1001013, '2025-04-24T03:49:59Z')
, (1001014, '2025-04-24T03:49:59Z')
, (1001015, '2025-04-24T03:49:59Z')
, (1001016, '2025-04-24T03:49:59Z')
, (1001017, '2025-04-24T03:49:59Z')
, (1001018, '2025-04-24T03:49:59Z')
, (1001901, '2025-04-24T03:49:59Z')
, (1002018, '2025-04-24T03:49:59Z')
, (1002017, '2025-04-24T03:49:59Z')
, (1002016, '2025-04-24T03:49:59Z')
, (1002015, '2025-04-24T03:49:59Z')
, (1002011, '2025-04-24T03:49:59Z')
, (1002013, '2025-04-24T03:49:59Z')
, (1002012, '2025-04-24T03:49:59Z')
, (1002001, '2025-04-24T03:49:59Z')
, (1002014, '2025-04-24T03:49:59Z')
, (1003016, '2025-04-24T03:49:59Z')
, (1003019, '2025-04-24T03:49:59Z')
, (1003017, '2025-04-24T03:49:59Z')
, (1003015, '2025-04-24T03:49:59Z')
, (1003012, '2025-04-24T03:49:59Z')
, (1003013, '2025-04-24T03:49:59Z')
, (1003011, '2025-04-24T03:49:59Z')
, (1003001, '2025-04-24T03:49:59Z')
, (1003014, '2025-04-24T03:49:59Z')
, (1004019, '2025-04-24T03:49:59Z')
, (1004018, '2025-04-24T03:49:59Z')
, (1004017, '2025-04-24T03:49:59Z')
, (1004015, '2025-04-24T03:49:59Z')
, (1004016, '2025-04-24T03:49:59Z')
, (1004013, '2025-04-24T03:49:59Z')
, (1004012, '2025-04-24T03:49:59Z')
, (1004001, '2025-04-24T03:49:59Z')
, (1004014, '2025-04-24T03:49:59Z')
, (1005018, '2025-04-24T03:49:59Z')
, (1005105, '2025-04-24T03:49:59Z')
, (1005104, '2025-04-24T03:49:59Z')
, (1005102, '2025-04-24T03:49:59Z')
, (1005101, '2025-04-24T03:49:59Z')
, (1005017, '2025-04-24T03:49:59Z')
, (1005103, '2025-04-24T03:49:59Z')
, (1005015, '2025-04-24T03:49:59Z')
, (1005014, '2025-04-24T03:49:59Z')
, (1005013, '2025-04-24T03:49:59Z')
, (1005012, '2025-04-24T03:49:59Z')
, (1005016, '2025-04-24T03:49:59Z')
, (1005011, '2025-04-24T03:49:59Z')
, (1005001, '2025-04-24T03:49:59Z')
, (1006201, '2025-04-24T03:49:59Z')
, (1006018, '2025-04-24T03:49:59Z')
, (1006017, '2025-04-24T03:49:59Z')
, (1006016, '2025-04-24T03:49:59Z')
, (1006019, '2025-04-24T03:49:59Z')
, (1006014, '2025-04-24T03:49:59Z')
, (1006013, '2025-04-24T03:49:59Z')
, (1006012, '2025-04-24T03:49:59Z')
, (1006001, '2025-04-24T03:49:59Z')
, (1006015, '2025-04-24T03:49:59Z')
, (1007018, '2025-04-24T03:49:59Z')
, (1007017, '2025-04-24T03:49:59Z')
, (1007016, '2025-04-24T03:49:59Z')
, (1007015, '2025-04-24T03:49:59Z')
, (1007014, '2025-04-24T03:49:59Z')
, (1007012, '2025-04-24T03:49:59Z')
, (1007011, '2025-04-24T03:49:59Z')
, (1007001, '2025-04-24T03:49:59Z')
, (1007013, '2025-04-24T03:49:59Z')
, (1008018, '2025-04-24T03:49:59Z')
, (1008104, '2025-04-24T03:49:59Z')
, (1008103, '2025-04-24T03:49:59Z')
, (1008102, '2025-04-24T03:49:59Z')
, (1008101, '2025-04-24T03:49:59Z')
, (1008017, '2025-04-24T03:49:59Z')
, (1008001, '2025-04-24T03:49:59Z')
, (1008015, '2025-04-24T03:49:59Z')
, (1008014, '2025-04-24T03:49:59Z')
, (1008013, '2025-04-24T03:49:59Z')
, (1008012, '2025-04-24T03:49:59Z')
, (1008011, '2025-04-24T03:49:59Z')
, (1008016, '2025-04-24T03:49:59Z')
, (1009201, '2025-04-24T03:49:59Z')
, (1009019, '2025-04-24T03:49:59Z')
, (1009018, '2025-04-24T03:49:59Z')
, (1009017, '2025-04-24T03:49:59Z')
, (1009016, '2025-04-24T03:49:59Z')
, (1009015, '2025-04-24T03:49:59Z')
, (1009013, '2025-04-24T03:49:59Z')
, (1009011, '2025-04-24T03:49:59Z')
, (1009001, '2025-04-24T03:49:59Z')
, (1009014, '2025-04-24T03:49:59Z')
, (1010016, '2025-04-24T03:49:59Z')
, (1010201, '2025-04-24T03:49:59Z')
, (1010018, '2025-04-24T03:49:59Z')
, (1010017, '2025-04-24T03:49:59Z')
, (1010015, '2025-04-24T03:49:59Z')
, (1010011, '2025-04-24T03:49:59Z')
, (1010013, '2025-04-24T03:49:59Z')
, (1010012, '2025-04-24T03:49:59Z')
, (1010014, '2025-04-24T03:49:59Z')
, (1010001, '2025-04-24T03:49:59Z')
, (1011201, '2025-04-24T03:49:59Z')
, (1011019, '2025-04-24T03:49:59Z')
, (1011018, '2025-04-24T03:49:59Z')
, (1011017, '2025-04-24T03:49:59Z')
, (1011016, '2025-04-24T03:49:59Z')
, (1011014, '2025-04-24T03:49:59Z')
, (1011013, '2025-04-24T03:49:59Z')
, (1011012, '2025-04-24T03:49:59Z')
, (1011001, '2025-04-24T03:49:59Z')
, (1011015, '2025-04-24T03:49:59Z')
, (1012018, '2025-04-24T03:49:59Z')
, (1012201, '2025-04-24T03:49:59Z')
, (1012104, '2025-04-24T03:49:59Z')
, (1012103, '2025-04-24T03:49:59Z')
, (1012102, '2025-04-24T03:49:59Z')
, (1012017, '2025-04-24T03:49:59Z')
, (1012101, '2025-04-24T03:49:59Z')
, (1012015, '2025-04-24T03:49:59Z')
, (1012014, '2025-04-24T03:49:59Z')
, (1012013, '2025-04-24T03:49:59Z')
, (1012012, '2025-04-24T03:49:59Z')
, (1012011, '2025-04-24T03:49:59Z')
, (1012001, '2025-04-24T03:49:59Z')
, (1012016, '2025-04-24T03:49:59Z')
, (1013201, '2025-04-24T03:49:59Z')
, (1013114, '2025-04-24T03:49:59Z')
, (1013113, '2025-04-24T03:49:59Z')
, (1013112, '2025-04-24T03:49:59Z')
, (1013111, '2025-04-24T03:49:59Z')
, (1013018, '2025-04-24T03:49:59Z')
, (1013017, '2025-04-24T03:49:59Z')
, (1013015, '2025-04-24T03:49:59Z')
, (1013014, '2025-04-24T03:49:59Z')
, (1013013, '2025-04-24T03:49:59Z')
, (1013012, '2025-04-24T03:49:59Z')
, (1013011, '2025-04-24T03:49:59Z')
, (1013001, '2025-04-24T03:49:59Z')
, (1013016, '2025-04-24T03:49:59Z')
, (1014016, '2025-04-24T03:49:59Z')
, (1014018, '2025-04-24T03:49:59Z')
, (1014017, '2025-04-24T03:49:59Z')
, (1014201, '2025-04-24T03:49:59Z')
, (1014015, '2025-04-24T03:49:59Z')
, (1014012, '2025-04-24T03:49:59Z')
, (1014013, '2025-04-24T03:49:59Z')
, (1014011, '2025-04-24T03:49:59Z')
, (1014001, '2025-04-24T03:49:59Z')
, (1014014, '2025-04-24T03:49:59Z')
, (1015201, '2025-04-24T03:49:59Z')
, (1015018, '2025-04-24T03:49:59Z')
, (1015017, '2025-04-24T03:49:59Z')
, (1015015, '2025-04-24T03:49:59Z')
, (1015016, '2025-04-24T03:49:59Z')
, (1015013, '2025-04-24T03:49:59Z')
, (1015012, '2025-04-24T03:49:59Z')
, (1015011, '2025-04-24T03:49:59Z')
, (1015001, '2025-04-24T03:49:59Z')
, (1015014, '2025-04-24T03:49:59Z')
, (1016902, '2025-04-24T03:49:59Z')
, (1029001, '2025-04-24T03:49:59Z')
, (1030114, '2025-04-24T03:49:59Z')
, (1030113, '2025-04-24T03:49:59Z')
, (1030112, '2025-04-24T03:49:59Z')
, (1030111, '2025-04-24T03:49:59Z')
, (1030018, '2025-04-24T03:49:59Z')
, (1030017, '2025-04-24T03:49:59Z')
, (1030014, '2025-04-24T03:49:59Z')
, (1030015, '2025-04-24T03:49:59Z')
, (1030013, '2025-04-24T03:49:59Z')
, (1030012, '2025-04-24T03:49:59Z')
, (1030011, '2025-04-24T03:49:59Z')
, (1030001, '2025-04-24T03:49:59Z')
, (1030016, '2025-04-24T03:49:59Z')
, (1031112, '2025-04-24T03:49:59Z')
, (1031111, '2025-04-24T03:49:59Z')
, (1031019, '2025-04-24T03:49:59Z')
, (1031018, '2025-04-24T03:49:59Z')
, (1031016, '2025-04-24T03:49:59Z')
, (1031013, '2025-04-24T03:49:59Z')
, (1031014, '2025-04-24T03:49:59Z')
, (1031012, '2025-04-24T03:49:59Z')
, (1031011, '2025-04-24T03:49:59Z')
, (1031001, '2025-04-24T03:49:59Z')
, (1031113, '2025-04-24T03:49:59Z')
, (1031015, '2025-04-24T03:49:59Z')
, (1031114, '2025-04-24T03:49:59Z')
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
;

INSERT INTO nineSequences (nineSequenceId, content)
VALUES
(10000000, '{"expiresAt": "2025-09-10T02:22:53Z", "lastReceiveAt": "2025-09-10T02:22:53Z", "lastReadAt": "2025-09-10T02:22:53Z"}')
,(10001002, '{"expiresAt": "2025-09-10T02:22:53Z", "lastReceiveAt": "2025-09-10T02:22:53Z", "lastReadAt": "2025-09-10T02:22:53Z"}')
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
,(100201, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1002015, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(100301, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1003012, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
-- miu?
,(100401, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1004001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(100501, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1005105, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(100601, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1006001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(100701, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1007001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(100801, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1008103, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(100901, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1009001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(101001, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1010001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(101101, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1011001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(101201, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1012001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(101301, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1013001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
-- kazuki?
,(101401, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1014001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(101501, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1015001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(102901, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1029001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(103001, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1030112, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
,(103101, 240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1031001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)
;

INSERT INTO gates (fromAreaId, fromPosX, fromPosY, fromPosZ, toAreaId, toPosX, toPosY, toPosZ, toDirection)
VALUES
(300402, -11.2500019, 53.5918961, -15.75, 300401, -4.15, 53.61689, -17.95, 3)
;

INSERT INTO userData (keyName, val)
VALUES
("status", '{"rank": 1, "staminaUpdatedAt": "2025-09-10T02:22:51Z", "formationNumber": 1, "currentAreaKeyId": 300402, "currentDirection": 5, "loggedInAt": "2025-09-17T00:18:05Z", "currentPositionCoordinates": {"x": -6, "y": 53.61689, "z": -15.75}, "currentAreaType": 1}')
;

INSERT INTO areaBgm (areaId, id, eventName) VALUES
(300402, 3101, 'bgm_story_serious_02')
, (300401, 1002, 'bgm_adv_00_basic_01')
, (300501, 1005, '')
, (101381, 1502, '')
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
-- Area 101381
INSERT INTO areaObjects (areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)
VALUES
(101381, 700055, 101381101, 7010111, '{"type": 3, "id": 1, "sequenceId": 7000801, "label": "Houseplant"}')
,(101381, 700056, 101381102, 7010121, '{"type": 3, "id": 1, "sequenceId": 7000811, "label": "Window"}')
,(101381, 700057, 101381103, 7010131, '{"type": 3, "id": 1, "sequenceId": 7000821, "label": "Bed"}')
;
