#[
the functions in this file mimic the behaviour of the protobuf json dumper
(they omit the field if the value is set to the default)
]#

import std/json

proc protoJsonDeleteKey*(node: JsonNode, key: string) =
  if node.hasKey(key):
    node.delete(key)

proc protoJsonGetBool*(node: JsonNode, key: string): bool = node.getOrDefault(key).getBool()

proc protoJsonSetBool*(node: JsonNode, key: string, val: bool) =
  if val:
    node[key] = %*true
  else:
    if node.hasKey(key):
      node.delete(key)

proc protoJsonGetInt*(node: JsonNode, key: string): int = node.getOrDefault(key).getInt()

proc protoJsonSetInt*(node: JsonNode, key: string, val: int) =
  if val != 0:
    node[key] = %*val
  else:
    if node.hasKey(key):
      node.delete(key)

proc protoJsonGetFloat*(node: JsonNode, key: string): float = node.getOrDefault(key).getFloat()

proc protoJsonSetFloat*(node: JsonNode, key: string, val: float) =
  if val != 0.0:
    node[key] = %*val
  else:
    if node.hasKey(key):
      node.delete(key)