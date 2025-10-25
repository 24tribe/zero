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

INSERT INTO areaObjects (areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)
VALUES
(300402, 309001, 300402901, 30900101, '{"type": 3, "id": 1, "sequenceId": 30900101, "label": "Hoimi"}'),
(300402, 309901, 300402991, 30990101, '{"type": 3, "id": 1, "sequenceId": 30990101}');

INSERT INTO tipRelease (tipId, areaId, areaObjectId, newAreaPointId, newAreaObjectBehaviorId, newAction)
VALUES (3012, 300402, 309901, 300402991, 30990102, '{"type": 7, "id": 1}');