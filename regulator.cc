/*
 * main.cc
 *
 *  Created on: Apr 19, 2015
 *      Author: palchak
 */


#include <iostream>
#include <cstdint>
#include <cstdio>

using namespace std;

namespace Regulator {

template<class T> class Value;
template<class T> class Modification;

template<class T>
class Register {
public:
	typedef T AccessType;
	typedef Register<T> ThisType;
	typedef Value<T> ValueType;
	typedef Modification<T> ModificationType;

	constexpr Register() : _bits(ValueType::_default_bits) {}
	constexpr Register(AccessType bits) : _bits(bits) {}
	constexpr Register(ValueType value) : _bits(value._bits) {}
	// TODO(palchak): Delete copy and move constructors

	constexpr ValueType value() const { return ValueType(_bits); }
	constexpr ValueType default_value() const { return ValueType(); }

	inline ThisType& operator= (AccessType bits) { _bits = bits; return *this; }
	inline ThisType& operator= (ValueType value) { _bits = value._bits; return *this; }
	// TODO(palchak): Delete copy assignment operator

	constexpr ModificationType modification() const { return ModificationType {*const_cast<ThisType*>(this)}; }

	template<typename F>
	inline void modify(F&& transform_fn) {
		bool succeeded = false;
		do {
			ValueType before = this->value();
			succeeded = this->swap(before, transform_fn(before));
		} while (!succeeded);
	}

protected:
	inline bool swap(ValueType old_value, ValueType new_value) {
		AccessType old_bits = AccessType(old_value);
		AccessType new_bits = AccessType(new_value);
		//printf("swap (0x%08X) = 0x%08X\n", old_bits, new_bits);
		return __sync_bool_compare_and_swap(&_bits, old_bits, new_bits);
	}
	AccessType _bits;
};

template<class T>
class Value {
public:
	typedef T AccessType;
	typedef Value<T> ThisType;
	friend class Register<T>;

	constexpr Value() : _bits(_default_bits) {}
	constexpr Value(AccessType v) : _bits(v) {}
	constexpr ThisType with_nibble(size_t N, AccessType foo) const { return (_bits & ~(0x0F << (4*N))) | ((foo & 0x0F) << (4*N)); }
	constexpr AccessType nibble(size_t N) const { return ((_bits >> (N*4)) & 0x0F); }
	constexpr explicit operator AccessType() const { return _bits; };

protected:
	static constexpr AccessType _default_bits = 0;
	AccessType _bits;
};

template<class T>
class Modification {
public:
	typedef T AccessType;
	typedef Modification<T> ThisType;
	typedef Register<T> RegisterType;
	typedef typename RegisterType::ValueType ValueType;
	friend class Register<T>;

	constexpr Modification(RegisterType& reg) : _reg(reg), _value(0), _mask(0) {}
	inline void apply() const { _reg.modify([=] (ValueType before) { return ValueType { (AccessType(before) & ~_mask) | AccessType(_value) }; }); }
	constexpr Modification with_nibble(size_t N, AccessType foo) const {
		return {_reg, _value.with_nibble(N, foo), _mask | (0x0F << (4*N)) };
	}

protected:
	constexpr Modification(RegisterType& reg, ValueType val, AccessType mask) : _reg(reg), _value(val), _mask(mask) {}
	RegisterType& _reg;
	ValueType _value;
	uint32_t _mask;
};


} // Namespace


uint32_t mem32;

void print_status() {
	printf("REG = 0x%08X\n", mem32);
}

struct Value32 {
	constexpr Value32(uint32_t v) : value(v) {};
	constexpr Value32&& with_rvalue(uint32_t v) && {
		return Value32{value + v};
	}
	constexpr Value32 with_lvalue(uint32_t v) & {
		return Value32{value + v}
	}
	uint32_t value;
};

struct Reg32 {
	constexpr Reg32() : _value(0) {}
	constexpr Value32 value() { return _value; }
	constexpr Value32& lvalue() { return _value; }
	Value32 _value;
};

using namespace Regulator;

int main(void) {
#if 0
	Register<uint32_t> *r0 = new(&mem32) Register<uint32_t>(0xFACADE);
	print_status();
	for(int i=0; i<8; i++) {
		printf("Nibble %i: 0x%02X\n", i, r0->value().nibble(i));
	}
	for(int i=0; i<8; i++) {
		r0->modification()
				.with_nibble(i,i)
				.apply();
		print_status();
	}
	for(int i=0; i<4; i++) {
		r0->modification()
				.with_nibble(2*i,0xA)
				.with_nibble(2*i+1, 0x5)
				.apply();
		print_status();
	}
#endif
	Reg32 r0;
	Value32 v0 = r0.value();

	uint32_t t1 = r0.value().with_lvalue(1).value;
	uint32_t t2 = r0.value().with_rvalue(2).value;
	uint32_t t3 = v0.with_lvalue(3).value;
	utin32_t t4 = v0.with_rvalue(3).value;

	Value32& v1 = v0.with_rvalue(5);

	uint32_t t5 = r0.lvalue().with_lvalue(1).value;
	uint32_t t6 = r0.lvalue().with_rvalue(2).value;
	uint32_t t7 = v0.with_lvalue(3).value;
	utin32_t t8 = v0.with_rvalue(3).value;

	printf("Test", t1, t2, t3, t4, t5, t6, t7, t8, v0, v1);
}



