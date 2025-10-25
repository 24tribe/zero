CREATE TABLE areaObjects (
    areaId INTEGER,
    areaObjectId INTEGER,
    areaPointId INTEGER,
    areaObjectBehaviorId INTEGER,
    action STRING
);

INSERT INTO areaObjects (areaObjectId, areaPointId, areaObjectBehaviorId, action)
VALUES (309001, 300402901, 30900101, '{"type": 3, "id": 1, "sequenceId": 30900101, "label": "Hoimi"}'); 

INSERT INTO areaObjects (areaObjectId, areaPointId, areaObjectBehaviorId, action)
VALUES (309901, 300402991, 30990101, '{"type": 3, "id": 1, "sequenceId": 30990101, "label": "Zero"}')