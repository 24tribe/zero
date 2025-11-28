from argparse import ArgumentParser
import struct

def get_higher_limit(base_address):
    base_address &= 0xffff00000000
    base_address += 0x0000f0000000
    return base_address

def main():
    assert get_higher_limit(0x7ffcc2850000) == 0x7ffcf0000000

    parser = ArgumentParser()
    parser.add_argument("in_bin")
    parser.add_argument("out_bin")
    parser.add_argument("base_address", type=int)
    args = parser.parse_args()
    
    with open(args.in_bin, "rb") as f:
        data = bytearray(f.read())

    new_base_address = 0x180000000

    with open(args.in_bin, "rb") as infile:
        with open(args.out_bin, "wb") as out:
            while data := infile.read(8):
                addr = struct.unpack("<Q", data)[0]

                if args.base_address <= addr <= get_higher_limit(args.base_address):
                    new_addr = new_base_address + (addr - args.base_address)
                else:
                    new_addr = addr

                enc_addr = struct.pack("<Q", new_addr)

                out.write(enc_addr)

    print("OK")

        
    

if __name__ == "__main__":
    main()