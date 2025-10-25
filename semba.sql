CREATE TABLE areaObjects (
    areaId INTEGER,
    areaObjectId INTEGER,
    areaPointId INTEGER,
    areaObjectBehaviorId INTEGER,
    action STRING
);

CREATE TABLE tipRelease (
    tipId INTEGER,
    areaId INTEGER,
    areaObjectId INTEGER,
    newAreaPointId INTEGER,
    newAreaObjectBehaviorId INTEGER,
    newAction STRING
);

CREATE TABLE areaEnemies (
    areaId INTEGER,
    areaPointId INTEGER,
    areaEnemyRateSetId INTEGER,
    action STRING
);

CREATE TABLE areaItems (
    areaId INTEGER,
    areaItemId INTEGER
);

CREATE TABLE areaBgm (
    areaId INTEGER,
    id INTEGER,
    eventName STRING
);

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