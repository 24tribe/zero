import std/bitops

var s: array[4, uint64] = [0, 0, 0, 0]

proc setState(s0, s1, s2, s3: uint64) =
  s[0] = s0
  s[1] = s1
  s[2] = s2
  s[3] = s3

proc next(): uint64 =
  result = rotateLeftBits(s[0] + s[3], 23) + s[0]

  let t: uint64 = s[1] shl 17

  s[2] = s[2] xor s[0]
  s[3] = s[3] xor s[1]
  s[1] = s[1] xor s[2]
  s[0] = s[0] xor s[3]
  s[2] = s[2] xor t
  s[3] = rotateLeftBits(s[3], 45)

proc test_xoshiro256pp() =
  setState(
    0x5490141ec56727c2.uint64,
    0xf4e7615431a42bdb.uint64,
    0xb6a380264f8df51f.uint64,
    0x4d93987efefaa433.uint64 
  )

  var results = newSeq[uint64]()

  for i in 0 ..< 10:
      results.add(next())

  let expected = @[
      0xa3724504c0383998.uint64,
      0x1f399cb51519992c.uint64,
      0x58825c9cd8a17e2b.uint64,
      0xde9fee7862310532.uint64,
      0xf3afc52fed83fb71.uint64,
      0x25ddc36152b6e3c9.uint64,
      0x517d516a7ffff275.uint64,
      0x360892443cd11fda.uint64,
      0x707f9c6fe1a8a9e1.uint64,
      0x668307cf48d3463c.uint64
  ]

  doAssert results == expected
  echo "OK"

when isMainModule:
  test_xoshiro256pp()