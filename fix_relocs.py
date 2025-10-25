from argparse import ArgumentParser
import struct
 
def main():
    parser = ArgumentParser()
    parser.add_argument("in_bin")
    parser.add_argument("out_bin")
    args = parser.parse_args()
    
    with open(args.in_bin, "rb") as f:
        data = bytearray(f.read())

    base_address = 0x7ffcc2850000
    new_base_address = 0x180000000

    with open(args.in_bin, "rb") as infile:
        with open(args.out_bin, "wb") as out:
            while data := infile.read(8):
                addr = struct.unpack("<Q", data)[0]
                
                if 0x7ffcf0000000 >= addr >= 0x7ffcc2850000:
                    new_addr = new_base_address + (addr - base_address)
                else:
                    new_addr = addr
                
                enc_addr = struct.pack("<Q", new_addr)

                out.write(enc_addr)
    
    print("OK")

        
    

if __name__ == "__main__":
    main()