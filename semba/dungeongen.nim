import std/random
import std/options

randomize()

const nonVisitedNode = "N";
const visitedNode = "V";
const objectiveNode = "O"

type Grid = seq[seq[string]]
type Position = array[2, int]
type Path = seq[Position]

type DungeonPartId* = enum
    startDungeonPartId = 101,
    endDungeonPartId = 201

type DungeonPiece* = object
    x*: int
    y*: int
    rotate*: int
    dungeonPieceId*: int

type Block* = object
    x*: int
    y*: int
    top*: int
    right*: int
    bottom*: int
    left*: int

type Entrances = object
    top: int
    right: int
    bottom: int
    left: int

type DungeonPart* = ref object
    id*: int
    name*: string
    blocks*: seq[Block]
    angle*: int
    canHaveMobs*: bool

type DungeonData* = seq[DungeonPart]


proc getRandomInt(max: int): int = rand(0 ..< max)


proc createGrid(gridWidth: int, gridHeight: int): Grid =
    for y in 0 ..< gridHeight:
        var row = newSeq[string]()

        for x in 0 ..< gridWidth:
            row.add(nonVisitedNode)

        result.add(row)


proc getNeighbourPositions(x: int, y: int): seq[Position] =
    result = @[
        [x - 1, y],
        [x + 1, y],
        [x, y + 1],
        [x, y - 1],
    ]


proc validPosition(grid: Grid, x: int, y: int): bool =
    let gridHeight = grid.len
    let gridWidth = grid[0].len
    result = (x in 0 ..< gridWidth) and (y in 0 ..< gridHeight)


proc getPossibleNextPositions(x: int, y: int, grid: Grid): seq[Position] =
    for pos in getNeighbourPositions(x, y):
        let neightbourX = pos[0]
        let neightbourY = pos[1]

        if validPosition(grid, neightbourX, neightbourY):
            let node = grid[neightbourY][neightbourX]
            if node == nonVisitedNode or node == objectiveNode:
                result.add(pos)


proc setIfValidPos(grid: var Grid, x: int, y: int, val: string) =
    if validPosition(grid, x, y):
        grid[y][x] = val


proc getPath(gridWidth: int, gridHeight: int): Path =
    var grid = createGrid(gridWidth, gridHeight)

    let objX = getRandomInt(gridWidth)
    let objY = 0
    let startX = getRandomInt(gridWidth)
    let startY = gridHeight - 1;

    setIfValidPos(grid, objX - 1, objY, visitedNode)
    setIfValidPos(grid, objX + 1, objY, visitedNode)
    grid[objY][objX] = objectiveNode

    grid[startY][startX] = visitedNode
    setIfValidPos(grid, startX - 1, startY, visitedNode)
    setIfValidPos(grid, startX + 1, startY, visitedNode)

    result.add([startX, startY])

    var x = startX
    var y = startY

    while grid[y][x] != objectiveNode:
        let nextPositions = getPossibleNextPositions(x, y, grid)

        if nextPositions.len == 0:
            discard result.pop()
            let lastPos = result[result.len - 1]
            x = lastPos[0]
            y = lastPos[1]
            continue

        let nextPos = nextPositions[getRandomInt(nextPositions.len)]
        let nextPosX = nextPos[0]
        let nextPosY = nextPos[1]

        if grid[nextPosY][nextPosX] != objectiveNode:
            grid[nextPosY][nextPosX] = visitedNode

        x = nextPosX
        y = nextPosY

        result.add([x, y])


proc splitDungeonParts(dungeonData: DungeonData): (DungeonPart, seq[DungeonPart], DungeonPart) =
    var startPart: DungeonPart = nil
    var middleParts = newSeq[DungeonPart]()
    var endPart: DungeonPart = nil

    for dungeonpart in dungeonData:
        if dungeonPart.id == startDungeonPartId.int:
            startPart = dungeonPart
        elif dungeonPart.id == endDungeonPartId.int:
            endPart = dungeonPart
        else:
            middleParts.add(dungeonPart)

    result = (startPart, middleParts, endPart)


proc updateEntrances(entrances: var Entrances, nodePos: Position, otherNodePos: Position) =
    let diffX = nodePos[0] - otherNodePos[0]
    let diffY = nodePos[1] - otherNodePos[1]

    if diffX == 1:
        entrances.right = 1
    elif diffX == -1:
        entrances.left = 1

    if diffY == 1:
        entrances.bottom = 1
    elif diffY == -1:
        entrances.top = 1;


proc getMiddleNodesEntrances(path: Path): seq[Entrances] =
    for i in 1 ..< path.len - 1:
        var entrances = Entrances(top: 0, right: 0, bottom: 0, left: 0)
        let nodePos = path[i]
        let lastNodePos = path[i - 1]
        let nextNodePos = path[i + 1]

        updateEntrances(entrances, lastNodePos, nodePos)
        updateEntrances(entrances, nextNodePos, nodePos)

        result.add(entrances)


proc copyAndApplyPos(part: DungeonPart, pos: Position): DungeonPart =
    new(result)
    result.id = part.id
    result.name = part.name
    result.angle = part.angle

    for oldBlock in part.blocks:
        let newBlock = Block(x: oldBlock.x + pos[0], y: oldBlock.y + pos[1])
        result.blocks.add(newBlock)


proc dungeonPartToDungeonPiece(
    dungeonPart: DungeonPart, cityId: int, nodePos: Position
): DungeonPiece =
    let absoluteDungeonPart = copyAndApplyPos(dungeonPart, nodePos)
    result = DungeonPiece(
        x: absoluteDungeonPart.blocks[0].x,
        y: absoluteDungeonPart.blocks[0].y,
        rotate: absoluteDungeonPart.angle,
        dungeonPieceId: cityId*10000 + absoluteDungeonPart.id
    )


proc equalEntrances(entrances1: Entrances, entrances2: Entrances): bool =
    result = entrances1.top == entrances2.top and
             entrances1.right == entrances2.right and
             entrances1.bottom == entrances2.bottom and
             entrances1.left == entrances2.left


proc partCanFit(
    i: int, part: DungeonPart, path: Path, middleNodesEntrances: seq[Entrances]
): bool =
    if i + part.blocks.len >= path.len:
        return false

    var j = 0
    var lastBlock: Option[Block] = none(Block)

    for bloc in part.blocks:
        let entrances = middleNodesEntrances[i - 1 + j]
        let blockEntrances = Entrances(
            top: bloc.top, right: bloc.right,
            bottom: bloc.bottom, left: bloc.left
        )

        if not equalEntrances(entrances, blockEntrances):
            return false

        if lastBlock.isSome():
            let lastNodePos = path[i + j - 1]
            let nodePos = path[i + j]
            let diffX = nodePos[0] - lastNodePos[0]
            let diffY = nodePos[1] - lastNodePos[1]

            if (bloc.x - lastBlock.get().x != diffX) or (bloc.y - lastBlock.get().y != diffY):
                return false

        lastBlock = some(bloc)
        j += 1

    return true


proc getPossibleParts(
    middleParts: seq[DungeonPart], i: int, path: Path, middleNodesEntrances: seq[Entrances]
): seq[DungeonPart] =

    for part in middleParts:
        if partCanFit(i, part, path, middleNodesEntrances):
            result.add(part)


proc filterPartsThatCanHaveMobs(possibleParts: seq[DungeonPart]): seq[DungeonPart] =
    for part in possibleParts:
        if part.canHaveMobs:
            result.add(part)


proc pickPart(possibleParts: seq[DungeonPart]): DungeonPart =
    let partsThatCanHaveMobs = filterPartsThatCanHaveMobs(possibleParts)

    if partsThatCanHaveMobs.len > 0:
        return partsThatCanHaveMobs[getRandomInt(partsThatCanHaveMobs.len)]

    if possibleParts.len == 0:
        raise newException(ValueError, "error: couldn't get a part that fit")

    return possibleParts[getRandomInt(possibleParts.len)]


proc genDungeon*(dungeonData: DungeonData, cityId: int): seq[DungeonPiece] =
    let (startPart, middleParts, endPart) = splitDungeonParts(dungeonData)

    const gridWidth = 3
    const gridHeight = 6

    let path = getPath(gridWidth, gridHeight)
    let middleNodesEntrances = getMiddleNodesEntrances(path)

    let startNodePos = path[0]
    let endNodePos = path[path.len - 1]

    result.add(dungeonPartToDungeonPiece(startPart, cityId, startNodePos))

    var i = 1

    while i < path.len - 1:
        let possibleParts = getPossibleParts(middleParts, i, path, middleNodesEntrances)

        let foundPart = pickPart(possibleParts)

        result.add(dungeonPartToDungeonPiece(foundPart, cityId, path[i]))

        i += foundPart.blocks.len

    result.add(dungeonPartToDungeonPiece(endPart, cityId, endNodePos))