#ifndef I_BLOCK_HH
#define I_BLOCK_HH
#include<cstddef>
// Abstract interface class for a Block of storage 
class Block {
public:
// 	Block(); // no default constructor. There are no pure Block s. Only subclass members may be constructed. 
	virtual ~Block() {}; // default destructor
	// ask is this Block constructed/allocated
	virtual bool valid()=0; 
	// get the length of the Block
	virtual std::size_t length()=0;
	// get the byte at offset, store into val
	virtual void get_byte(std::size_t offset, char & val)=0; 
	// set the byte at offset to val
	virtual void set_byte(std::size_t offset, char & val)=0; 
	
	// Ignore the rest for now
	// TBD additional methods
	// get the byte at offset
	virtual char the_byte_at(std::size_t offset) 
	{
		char buffer;
		get_byte( offset, buffer );
		return buffer;
	}; 
	// get count bytes at offset, store into val
	virtual void get_bytes(std::size_t offset, char * vals, std::size_t count ) 
	{
		char * j = vals;
		std::size_t i = offset;
		for ( std::size_t c = 0; c < count; ++c, ++i, ++j ) 
		{
			get_byte( i, *j );
		};
	}; 
	// set count bytes at offset to val
	virtual void set_bytes(std::size_t offset, char * vals, std::size_t count ) 
	{
		char * j = vals;
		std::size_t i = offset;
		for ( std::size_t c = 0; c < count; ++c, ++i, ++j ) 
		{
			set_byte( i, *j );
		};
	}; 
	
	// copy count bytes from offset to the target at target_offset:
	virtual void copy_bytes( Block & target, std::size_t target_offset, 
					std::size_t offset, std::size_t count ) 
	{
		char buffer;
		std::size_t j = target_offset;
		std::size_t i = offset;
		for ( std::size_t c = 0; c < count; ++c, ++i, ++j ) 
		{
			get_byte( i, buffer );
			target.set_byte( j, buffer );
		};
	}; 
};
#endif //I_BLOCK_HH
