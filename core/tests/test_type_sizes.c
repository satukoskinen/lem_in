#include "inc/core.h"

int main(void)
{
	print("i64 = %d bytes\n", sizeof(t_int64));
	print("i32 = %d bytes\n", sizeof(t_int32));
	print("i16 = %d bytes\n", sizeof(t_int16));
	print("i8 = %d bytes\n", sizeof(t_int8));
	print("u64 = %d bytes\n", sizeof(t_uint64));
	print("u32 = %d bytes\n", sizeof(t_uint32));
	print("u16 = %d bytes\n", sizeof(t_uint16));
	print("u8 = %d bytes\n", sizeof(t_uint8));
	print("size = %d bytes\n", sizeof(t_size));
	print("ssize = %d bytes\n", sizeof(t_ssize));
	print("byte = %d bytes\n", sizeof(t_byte));	
}
